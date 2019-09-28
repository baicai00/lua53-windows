local mt = {}

function mt:LuaFunc()
	return 1,2,3,4
end

function mt:LuaAdd(a, b)
	return (a+b)
end

return mt