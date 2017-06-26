

function register_rpc_handler()

	local call_func_map = RpcMgr._all_call_func

	call_func_map.bridge_create_role = function(data)
		
		Log.debug("bridge_create_role: data=%s", Util.TableToString(data))

		local server = ServiceClient.get_server_by_type(ServerType.ROUTER)
		if not server then
			Log.err("bridge_create_role no router server")
			return {result = ServerErrorCode.RPC_FAIL}
		end

		local status, result = RpcMgr.call(server, "router_create_role", data)
		if not status then
			Log.err("bridge_create_role rpc call fail")
			return {result = ServerErrorCode.RPC_FAIL}
		end

		Log.debug("bridge_create_role: callback result=%s", Util.TableToString(result))

		return result
	end

end
