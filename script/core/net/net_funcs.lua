
Net = {}
Net._all_mailbox = {} -- {{mailbox_id=x, conn_type=x, ip=x, port=x}, }

function Net.send_msg_ext(mailbox_id, msg_id, ext, data)
	-- Log.debug("Net.send_msg_ext msgdef mailbox_id=%d msg_id=%d ext=%d", mailbox_id, msg_id, ext)
	local msgdef = MSG_DEF_MAP[msg_id]
	if not msgdef then
		Log.err("Net.send_msg_ext msgdef not exists msg_id=%d", msg_id)
		return false
	end

	local flag = write_data_by_msgdef(data, msgdef, 0)
	if not flag then
		Log.err("Net.send_msg_ext write data error msg_id=%d", msg_id)
		g_network:clear_write()
		return false
	end

	g_network:write_msg_id(msg_id)
	g_network:write_ext(ext)
	return g_network:send(mailbox_id)
end

function Net.send_msg(mailbox_id, msg_id, data)
	return Net.send_msg_ext(mailbox_id, msg_id, 0, data)
end

-- transfer msg, copy data from recv pluto to send pluto, update ext if necessary
function Net.transfer_msg(mailbox_id, ext)
	-- Log.debug("Net.transfer_msg msgdef mailbox_id=%d ext=%d", mailbox_id, ext or 0)

	if ext then
		g_network:write_ext(ext)
	end
	return g_network:transfer(mailbox_id)
end

function Net.add_mailbox(mailbox_id, ip, port)
	local conn_type = ConnType.UNTRUST
	if TrustIPList[ip] then
		conn_type = ConnType.TRUST
	end
	Net._all_mailbox[mailbox_id] = 
	{
		mailbox_id = mailbox_id, 
		conn_type = conn_type,
		ip = ip,
		port = port,
	}
end

function Net.get_mailbox(mailbox_id)
	return Net._all_mailbox[mailbox_id]	
end

function Net.del_mailbox(mailbox_id)
	Net._all_mailbox[mailbox_id] = nil
end

function Net.http_request_get(url, session_id)
	local post_data = ""
	local post_data_len = 0;
	g_network:http_request(url, session_id, HttpRequestType.GET, post_data, post_data_len)
end

function Net.http_request_post(url, session_id, post_data, post_data_len)
	g_network:http_request(url, session_id, HttpRequestType.POST, post_data, post_data_len)
end

function Net.connect_to(ip, port)
	return g_network:connect_to(ip, port)
end

function Net.close_mailbox(mailbox_id)
	return g_network:close_mailbox(mailbox_id)
end
