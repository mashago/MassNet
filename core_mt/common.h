
#pragma once

enum E_CONN_TYPE
{
	CONN_TYPE_ERROR 		= 0,
	CONN_TYPE_UNTRUST 		= 1,
	CONN_TYPE_TRUST 		= 2,
};

enum E_SERVER_TYPE
{
	SERVER_TYPE_NULL 		= 0,
	SERVER_TYPE_ROUTER 		= 1,
	SERVER_TYPE_SCENE 		= 2,
	SERVER_TYPE_DB 			= 3,
	SERVER_TYPE_BRIDGE 		= 4,
	SERVER_TYPE_LOGIN 		= 5,
	SERVER_TYPE_PUBLIC 		= 6,
	SERVER_TYPE_CROSS 		= 7,
	SERVER_TYPE_PAY 		= 8,
	SERVER_TYPE_CHAT 		= 9,
};

static const char *SERVER_NAME_ARRAY[] =
{
	"null"
,	"router_svr"
,	"scene_svr"
,	"db_svr"
,	"bridge_svr"
,	"login_svr"
,	"public_svr"
,	"cross_svr"
,	"pay_svr"
,	"chat_svr"
};

enum MSGID_TYPE
{
	CLIENT_TEST = 1,
	CLIENT_TEST_RET = 2,
};
