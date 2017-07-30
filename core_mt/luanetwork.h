#pragma once

#include <stdint.h>

class Pluto;
class LuaWorld;

class LuaNetwork
{
public:
	static LuaNetwork *Instance();

	void SetWorld(LuaWorld *world)
	{
		m_world = world;
	}

	int64_t ConnectTo(const char* ip, unsigned int port); // return mailboxId or negative
	void WriteMsgId(int msg_id);
	void WriteExt(int ext);
	bool WriteByte(char val);
	bool WriteInt(int val);
	bool WriteFloat(float val);
	bool WriteBool(bool val);
	bool WriteShort(short val);
	bool WriteInt64(int64_t val);
	bool WriteString(int len, const char* str);

	bool Send(int64_t mailboxId);
	bool Transfer();

	//��ǰ��д�ַ�����󳤶�
	// int can_write_string_maxlen();

	void SetRecvPluto(Pluto *pu);
	int  ReadMsgId();
	int  ReadExt();
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

	LuaWorld *m_world;
};