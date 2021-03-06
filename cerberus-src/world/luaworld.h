
#pragma once

#include <lua.hpp>
#include <map>

class EventPipe;
struct EventNode;
class TimerMgr;
class Pluto;
class LuaSubThread;

class LuaWorld
{
public:
	LuaWorld();
	virtual ~LuaWorld();

	bool Init(const char *conf_file, EventPipe *inputPipe, EventPipe *outputPipe);
	void Dispatch();

	void RecvEvent();
	void SendEvent(EventNode *node);
	void HandleEvent(const EventNode &node);

	virtual void HandleNewConnection(int64_t mailboxId, const char *ip, int port);
	virtual void HandleDisconnect(int64_t mailboxId);
	virtual void HandleMsg(Pluto &u);
	virtual void HandleStdin(const char *buffer);
	virtual void HandleConnectRet(int64_t session_id, int64_t mailboxId);
	virtual void HandleHttpResponse(int64_t session_id, int response_code, const char *content, int content_len);
	virtual void HandleListenRet(int64_t listenId, int64_t session_id);

	TimerMgr *GetTimerMgr()
	{
		return m_timerMgr;
	}
	// call from world - timermgr
	void HandleTimer(void *arg, bool is_loop);


	Pluto *GetRecvPluto();
	Pluto *GetSendPluto();
	// call from lua
	bool Connect(int64_t session_id, const char* ip, unsigned int port);
	bool SendPluto(int64_t mailboxId);
	bool Transfer(int64_t mailboxId);
	void CloseMailbox(int64_t mailboxId);
	bool HttpRequest(const char *url, int64_t session_id, int request_type, const char *post_data, int post_data_len);
	bool Listen(const char* ip, unsigned int port, int64_t session_id);

	// sub thread function
	int CreateSubThread(const char *file_name, const char *params, int len);
	void CallSubThread(int thread_id, int64_t session_id, const char *func_name, const char *params, int len);
	void DestroySubThread(int thread_id);

protected:
	bool m_isRunning;
	EventPipe *m_inputPipe;
	EventPipe *m_outputPipe;
	TimerMgr *m_timerMgr;
	std::thread m_thread;

	Pluto *m_recvPluto;
	Pluto *m_sendPluto;

	lua_State *m_L;
	int64_t m_connIndex;
	std::map<int, LuaSubThread*> m_subthread_map;

};

