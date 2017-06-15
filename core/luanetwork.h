#pragma once

#include <stdint.h>

class Pluto;
class NetService;

class LuaNetwork
{
public:
	static LuaNetwork *Instance();

	void SetNetService(NetService *net)
	{
		m_net = net;
	}

	int ConnectTo(const char* ip, int port); // return mailboxId or negative
	void WriteMsgId(int msg_id);
	bool WriteByte(char val);
	bool WriteInt(int val);
	bool WriteFloat(float val);
	bool WriteBool(bool val);
	bool WriteShort(short val);
	bool WriteInt64(int64_t val);
	bool WriteString(int len, const char* str);

	bool Send(int64_t mailboxId);

	//��ǰ��д�ַ�����󳤶�
	// int can_write_string_maxlen();

	void SetRecvPluto(Pluto *pu);
	int  ReadMsgId();
	bool ReadByte(char &out_val);
	bool ReadInt(int &out_val);
	bool ReadFloat(float &out_val);
	bool ReadBool(bool &out_val);
	bool ReadShort(short &out_val);
	bool ReadInt64(int64_t &out_val);
	bool ReadString(int &out_len, char *out_val);

	void CloseMailbox(int64_t mailboxId);

private:
	LuaNetwork();
	~LuaNetwork();

	void initSendPluto();

	Pluto *m_recvPluto;
	Pluto *m_sendPluto;

	NetService *m_net;
};
