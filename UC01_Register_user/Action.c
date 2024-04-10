Action()
{	
	web_set_user("{main_user}", 
    "{main_pass}",
    "dev-boomq.pflb.ru:443");

	web_set_max_html_param_len("16384");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("dev-boomq.pflb.ru", 
		"URL=https://dev-boomq.pflb.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		LAST);

	web_websocket_send("ID=1", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1711095923403\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 1 received buffer WebSocketReceive0*/
	
	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_01_Login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2024-04-04T06:21:05.816Z");

	web_reg_save_param_ex(
	    "ParamName=token",
	    "LB=authorization: ",
	    "RB=\r\n",
	    SEARCH_FILTERS,
	    "Scope=Headers",
	    LAST);

	web_submit_data("login",
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={main_user}", ENDITEM, 
		"Name=password", "Value={main_pass}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Authorization", "Bearer {token}");
	
	web_url("user",
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_ex(
	    "ParamName=token2",
	    "LB=authorization: ",
	    "RB=\r\n",
	    SEARCH_FILTERS,
	    "Scope=Headers",
	    LAST);
	
	web_reg_save_param_json(
		"ParamName=main_id",
		"QueryString=$..userId",
		SEARCH_FILTERS,
		LAST);

	web_url("teamContext",
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	web_remove_auto_header("Authorization", LAST);
	
	web_add_auto_header("Authorization", "Bearer {token2}");

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Content-Type", "application/json");
	
	web_custom_request("user_2",
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"Body={\"email\":\"{main_user}\",\"id\":{main_id},\"language\":\"EN\",\"notificationEnabled\":false}", 
		LAST);

	web_url("5", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/{teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_01_Login",LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_02_Team_choose");
	
	web_url("team_2",
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_02_Team_choose",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("UC_01_TR_03_Team_edit");

	web_url("5_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/{teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("teamMember",
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_03_Team_edit",LR_AUTO);
	
	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_04_Add_user");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");
	
	web_reg_save_param_json(
	    "ParamName=invite",
	    "QueryString=$..inviteUrl",
	    "Notfound=warning",
	    SEARCH_FILTERS,
	    LAST);
	
	web_reg_save_param_json(
		"ParamName=new_id",
		"QueryString=$..id",
		SEARCH_FILTERS,
		LAST);

	web_reg_save_param_json(
		"ParamName=new_userId",
		"QueryString=$..userId",
		SEARCH_FILTERS,
		LAST);
	
	web_custom_request("teamMember_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"email\":\"{user}\",\"permissionList\":[\"ADMIN\",\"VIEW\",\"EDIT\",\"RUN\",\"MANAGE_USERS_IN_ORG\"],\"userDisplayName\":\"\"}]", 
		LAST);

	web_url("teamMember_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_04_Add_user",LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_05_Search_user_link_pass");
	
	web_url("teamMember_4",
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}&page=1&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("teamMember_5", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/5", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=[{\"email\":\"{user}\",\"id\":{new_id},\"permissionList\":[\"VIEW\",\"EDIT\",\"MANAGE_USERS_IN_ORG\",\"ADMIN\",\"RUN\"],\"teamId\":\"{teamId}\",\"userDisplayName\":\"\",\"userId\":{new_userId},\"updateInviteExpiration\":true}]", 
		LAST);

	lr_end_transaction("UC_01_TR_05_Search_user_link_pass",LR_AUTO);
	
	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_06_Logout");
	
	web_cleanup_cookies();
	web_cache_cleanup();
	web_remove_auto_header("Authorization", LAST);

	lr_end_transaction("UC_01_TR_06_Logout",LR_AUTO);
	
	lr_think_time(2);

	lr_start_transaction("UC_01_TR_07_Follow_link_pass");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_save_param_ex(
	    "ParamName=token3",
	    "LB=boomq_auth=",
	    "RB=;",
	    SEARCH_FILTERS,
	    "Scope=Headers",
	    LAST);
	
	web_url("B141BeGI4u03_E60pwNGLiiRIC0S3z--ddKscxGnUCbcZq43djn3yJDoWpxWCwYlhFFXpdxY-VlgGsPc9gV7uLtZDJO32wK23_AVPM6H3xo=",
		"URL=https://dev-boomq.pflb.ru{invite}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_07_Follow_link_pass",LR_AUTO);
	
	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_08_Set_pass");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
	web_add_auto_header("Authorization", "Bearer {token3}");

	web_url("modelSchema_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("user_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"Body={\"password\":\"{pass}\"}", 
		LAST);

	web_url("team_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner_2", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_08_Set_pass",LR_AUTO);
	
	lr_think_time(atoi(lr_eval_string("{thinkTimeSeconds}")));

	lr_start_transaction("UC_01_TR_09_Logout_new_user");
	
	web_cleanup_cookies();
	
	web_cache_cleanup();

	lr_end_transaction("UC_01_TR_09_Logout_new_user",LR_AUTO);

        return 0;
}