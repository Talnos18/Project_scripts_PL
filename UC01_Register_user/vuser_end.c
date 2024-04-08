#include "lrun.h"
#include "stdio.h"

vuser_end()
{
    char *user = lr_eval_string("{user}");
    char *pass = lr_eval_string("{pass}");

    // Объявляем переменные здесь
    FILE *file_csv;
    FILE *file_dat;

    file_csv = fopen("../Reg_users.csv", "a");
    if (file_csv != NULL) {
        long size;
        fseek(file_csv, 0, SEEK_END);
        size = ftell(file_csv);
        if (size == 0) {
            fprintf(file_csv, "Login,Password\n");
        }
        fprintf(file_csv, "%s,%s\n", user, pass);
        fclose(file_csv);
    } else {
        lr_error_message("Не удалось открыть или создать файл для записи (Reg_users.csv).");
        lr_abort();
    }
    
    file_dat = fopen("../user_reg.dat", "a");
    if (file_dat != NULL) {
        fprintf(file_dat, "%s\n", user);
        fclose(file_dat);
    } else {
        lr_error_message("Не удалось открыть или создать файл для записи (user_reg.dat).");
        lr_abort();
    }
    
    return 0;
}