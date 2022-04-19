#pragma once
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

#include <json/value.h>
#include <json/json.h>
#include <fstream>


void ClearConsole() {
	system("cls");
}

enum printingModes
{
	SAME_LINE,
	NEW_LINE
};

void print(const char* Text, printingModes mode) {
	switch (mode)
	{
	case SAME_LINE:
		std::cout << Text;
		break;
	case NEW_LINE:
		std::cout << Text << std::endl;
		break;
	default:
		std::cout << Text << std::endl;
		break;
	}
}

void CreateAccount(Json::Value root,std::string username, std::string password) {
	Json::StreamWriterBuilder builder;
	std::ofstream file;
	const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	root["Username"] = username;
	root["Password"] = password;
	file.open("Test.json");
	file << root;
	file.close();
}

void LoginToAccount(Json::Value root, std::string fileName, std::string newName, std::string newPass) {
	Json::Reader reader;
	std::ifstream jsonfile("Test.json");

	reader.parse(jsonfile, root);
	if (root["Username"] == newName && root["Password"] == newPass) {
		std::cout << "You logged in Successfully:)" << std::endl;
	}
	else {
		std::cout << "You failed to login:(" << std::endl;
	}
}