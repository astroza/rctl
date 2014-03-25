PASS="YOURPASS"
function handle_request(env)
	params = {}
	for p in string.gmatch(env.REQUEST_URI, "%w+") do
		table.insert(params, p)
	end

	if(table.getn(params) == 3 and params[2] == PASS) then
		uhttpd.send("HTTP/1.0 200 OK\r\n")
		uhttpd.send("Content-Type: text/plain\r\n\r\n")
		if(params[3] == "open") then
			os.execute("/usr/bin/homectl open")
			uhttpd.send("Ok")
		else
			uhttpd.send("Unknown command")
		end
	else
		uhttpd.send("HTTP/1.0 404 Not Found\r\n")
		uhttpd.send("Content-Type: text/plain\r\n\r\n")
		uhttpd.send("Ah?")
	end
end
