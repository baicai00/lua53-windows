// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 新建虚拟机
	lua_State *L = luaL_newstate();

	// 载入库
	luaL_openlibs(L);

	// 这里执行test.lua
	int nRet = luaL_dofile(L, "test.lua");
	// 重新设置栈底
	//lua_settop(L, 0);

	// 获取返回结果
	
	//int a = lua_getglobal(L, "LuaFunc");
	nRet = lua_gettable(L, -1);

	// 操作栈调回结果
	lua_pcall(L, 0, 4, 0);
	printf("%s\n", lua_tostring(L, 1));
	printf("%s\n", lua_tostring(L, 2));
	printf("%s\n", lua_tostring(L, 3));
	printf("%s\n", lua_tostring(L, 4));

	lua_settop(L, 0);

	lua_getglobal(L, "LuaAdd");
	lua_pushnumber(L, 2);
	lua_pushnumber(L, 3);
	lua_pcall(L, 2, 1, 0);
	printf("ret=%d\n", lua_tointeger(L, 1));

	// 关闭虚拟机
	lua_close(L);

	return 0;
}

