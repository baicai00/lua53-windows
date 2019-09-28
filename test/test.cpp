// test.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// �½������
	lua_State *L = luaL_newstate();

	// �����
	luaL_openlibs(L);

	// ����ִ��test.lua
	int nRet = luaL_dofile(L, "test.lua");
	// ��������ջ��
	//lua_settop(L, 0);

	// ��ȡ���ؽ��
	
	//int a = lua_getglobal(L, "LuaFunc");
	nRet = lua_gettable(L, -1);

	// ����ջ���ؽ��
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

	// �ر������
	lua_close(L);

	return 0;
}

