
local Log = require "log.logger"
local Util = require "util.util"
local class = require "util.class"
local g_funcs = require "global.global_funcs"
local SheetObj = require "obj.sheet_obj"
local sheet_name = "test_bag"

local TestBag = class(SheetObj)

function TestBag:ctor(role_id)
	self._role_id = role_id
end

function TestBag:init()
	self:init_sheet(sheet_name, {self._role_id})
end

function TestBag:do_save(insert_rows, delete_rows, modify_rows)
	Log.debug("#### TestBag:do_save ####")
	Log.debug("insert_rows=%s", Util.table_to_string(insert_rows))
	Log.debug("delete_rows=%s", Util.table_to_string(delete_rows))
	Log.debug("modify_rows=%s", Util.table_to_string(modify_rows))
	Log.debug("##########################")
end

g_funcs.register_getter_setter(TestBag, sheet_name)

return TestBag
