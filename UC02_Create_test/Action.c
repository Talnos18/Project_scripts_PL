Action()
{

	web_set_user("{user}", 
    "{pass}",
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
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	web_websocket_send("ID=1", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1712375831259\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 1 received buffer WebSocketReceive0*/

	lr_start_transaction("UC02_TR_01_Login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2024-04-06T07:11:24.316Z");
	
	web_reg_save_param_ex(
	      "ParamName=token", 
	      "LB=authorization: ",
	      "RB=\r",            
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
		"Name=username", "Value={user}", ENDITEM, 
		"Name=password", "Value={pass}", ENDITEM, 
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
	
	web_reg_save_param_regexp(
	    "ParamName=name",
	    "RegExp=\"email\":\"([^@]+)",
	    "Ordinal=All",
	    "Group=1",
	    "NotFound=warning",
	    SEARCH_FILTERS,
	    "Scope=Body",
	    LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	// Сохраняем текущее время в переменную "time"
    lr_save_timestamp("time", LAST);

    // Получаем значение переменной "time" и сохраняем его в отдельную переменную
    lr_save_string(lr_eval_string("{time}"), "current_time");

    // Объединяем текущее время с переменной {name_1}
    lr_save_string(lr_eval_string("{name_1}"), "old_name");
    lr_param_sprintf("name_1_with_time", "%s_%s", lr_eval_string("{old_name}"), lr_eval_string("{current_time}"));

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
		"ParamName=userId",
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

	web_add_auto_header("Origin", 
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
		"Body={\"email\":\"{user}\",\"id\":{userId},\"language\":\"RU\",\"notificationEnabled\":false}", 
		EXTRARES, 
		"Url=../static/media/ru.4cd05270ae7e3662e152f7c201b429f1.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	lr_end_transaction("UC02_TR_01_Login",LR_AUTO);
	
	lr_think_time(2);

	lr_start_transaction("UC02_TR_02_Settings_thread");

	lr_end_transaction("UC02_TR_02_Settings_thread",LR_AUTO);

	lr_start_transaction("UC02_TR_03_Load_SLA");

	web_custom_request("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"{name_1_with_time}\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"3b37ddbe-43c8-443d-9abb-b169553ab2b5\",\"label\":\"{name_1_with_time}\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\"threadGroupElements"
		"\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"GET\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"{path_mock}\",\"port\":\"{port_mock}\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"{host_mock}\",\"headers\":{},\"queryParameters\":[],\"body\":\"\",\"bodyParameters\":[]},\"timerList\":[{\""
		"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_d06b72f2-ca70-4d8c-9d37-fc6dedf62a40\",\"id\":\"d06b72f2-ca70-4d8c-9d37-fc6dedf62a40\",\"durationMs\":{durationMs},\"enabled\":true}],\"label\":\"{mock_ip}\",\"id\":\"ffc18113-4b5b-4481-9fb1-a4c41f3cbc98\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler"
		"\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"a4286aa8-2c02-402e-8b8c-b8b49c8bfd8a\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\""
		"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"fe00c662-85c2-40d3-9f2c-5600fee1a354\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"ba538c93-08ea-4a3f-af4a-2f432e5f4ecd\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"949c24fa-3f28-4aa2-96a0-3c9ce5fbf28c\",\"connectTimeout\":60000,\""
		"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":{usersPerStep},\"rampDownMs\":{rampDownMs},\"durationAddedOnLastStepMs\":{durationAddedOnLastStepMs},\"boomqProfileType\":\"STABLE\",\"rampUpMs\":{rampUpMs},\"stepLengthMs\":300000,\"stepCount\":{stepCount}},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_e6c295d9-bb7b-448f-addf-87e0bd6ee4ab\",\"id\":\"e6c295d9-bb7b-448f-addf-87e0bd6ee4ab\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":0,\""
		"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_response}\"},{\"fromDate\":0,\"restrictionType\":\"ERROR_RATE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_error}\"},{\"fromDate\":0,\"restrictionType\":\"THROUGHPUT\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_request}\"}]}],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":{totalDuration}}", 
		EXTRARES, 
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);
/*
	web_custom_request("124", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/124", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"{name_1}9\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"3b37ddbe-43c8-443d-9abb-b169553ab2b5\",\"label\":\"{name_1}9\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\"threadGroupElements"
		"\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"GET\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"{path_mock}\",\"port\":\"{port_mock}\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"{host_mock}\",\"headers\":{},\"queryParameters\":[],\"body\":\"\",\"bodyParameters\":[]},\"timerList\":[{\""
		"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_d06b72f2-ca70-4d8c-9d37-fc6dedf62a40\",\"id\":\"d06b72f2-ca70-4d8c-9d37-fc6dedf62a40\",\"durationMs\":{durationMs},\"enabled\":true}],\"label\":\"{mock_ip}\",\"id\":\"ffc18113-4b5b-4481-9fb1-a4c41f3cbc98\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler"
		"\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"a4286aa8-2c02-402e-8b8c-b8b49c8bfd8a\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\""
		"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"10c9f8a9-dbf2-4ec5-8e14-1bfe1fd96412\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"684e2840-673c-470b-8884-dba347334119\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"87f90112-4ead-42cc-82ea-b2c089d182df\",\"connectTimeout\":60000,\""
		"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":{usersPerStep},\"rampDownMs\":{rampDownMs},\"durationAddedOnLastStepMs\":{durationAddedOnLastStepMs},\"boomqProfileType\":\"STABLE\",\"rampUpMs\":{rampUpMs},\"stepLengthMs\":300000,\"stepCount\":{stepCount}},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_6fc7147e-35c4-46fa-841a-ef2f6522f249\",\"id\":\"6fc7147e-35c4-46fa-841a-ef2f6522f249\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":0,\""
		"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_response}\"},{\"fromDate\":0,\"restrictionType\":\"ERROR_RATE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_error}\"},{\"fromDate\":0,\"restrictionType\":\"THROUGHPUT\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":720,\"value\":\"{SLA_request}\"}]}],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":300}", 
		LAST);
*/
	lr_end_transaction("UC02_TR_03_Load_SLA",LR_AUTO);
	
	lr_think_time(2);

	lr_start_transaction("UC02_TR_04_Logout");
/*	
	web_cleanup_cookies();
	
	web_cache_cleanup();
*/
	lr_end_transaction("UC02_TR_04_Logout",LR_AUTO);

	return 0;
}