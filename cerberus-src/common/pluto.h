
#pragma once

extern "C"
{
#include <stdint.h>
}

/*
 * msg:
 * [msgLen:4] [msgId:4] [ext:8] [content] 
 * msgLen is total msg len, msgLen size + msgId size + ext size + content size
 *
 */

class Pluto
{
public:

	Pluto(int bufferSize);
	~Pluto();

	int GetMsgLen() const;
	void SetMsgLen(int len = 0);

	char * GetBuffer();
	char * GetPayload();
	int GetPayloadLen();

	int GetRecvLen();
	void SetRecvLen(int len);
	void SetMailboxId(int64_t mailboxId);
	int64_t GetMailboxId();

	void ResetCursor();
	void Cleanup();

	Pluto *Dup();
	void Copy(const Pluto *pu);

	void WriteMsgId(int msgId);
	void WriteExt(int64_t ext);
	bool WriteByte(char val);
	bool WriteInt(int val);
	bool WriteFloat(float val);
	bool WriteBool(bool val);
	bool WriteShort(short val);
	bool WriteInt64(int64_t val);
	bool WriteString(int len, const char* str);

	int  ReadMsgId();
	int64_t  ReadExt();
	bool ReadByte(char &out_val);
	bool ReadInt(int &out_val);
	bool ReadFloat(float &out_val);
	bool ReadBool(bool &out_val);
	bool ReadShort(short &out_val);
	bool ReadInt64(int64_t &out_val);
	bool ReadString(int &out_len, char *out_val);

	void Print();

private:
	char *m_buffer;
	char *m_cursor;

	int m_bufferSize;
	int m_recvLen;

	int64_t m_mailboxId;
};

