#include "codingame-sync.h"
#include "httplib.h"
#include <format>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "You must provide the entry file as first argument" << std::endl;
		return 1;
	}

	std::cout << "Merger starter successfully" << std::endl;

	httplib::Server server;

	server.Get("/code", [&](const httplib::Request &, httplib::Response &res) {
		try {
			auto mergeResult = merge(argv[1]);
			std::cout << "Code merged successfully" << std::endl;
			res.set_content(mergeResult, "text/plain");
		} catch (std::exception* e) {
			std::cout << "Exception : " << e->what() << std::endl;
			res.status = 500;
		}
	});

	server.listen("0.0.0.0", 8080);
	return 0;
}
