#include "Utils.h"

enum Menus 
{
	MainMenu,
	CreateAccountMenu,
	LoginMenu
};

Json::Value root;
std::string username;
std::string password;

std::string newName;
std::string newPass;

void GoToMenu(Menus menu);

int main() {
	int menuSelection = 0;
	
	while (true) {
		GoToMenu(MainMenu);
		print("Mode:", SAME_LINE);
		std::cin >> menuSelection;
		switch (menuSelection)
		{
		case 1:
			GoToMenu(CreateAccountMenu);
			break;
		case 2:
			GoToMenu(LoginMenu);
			Sleep(1000);
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
}

void GoToMenu(Menus menu) {
	switch (menu)
	{
	case MainMenu:
		ClearConsole();
		print("Welcome To Account Creator", NEW_LINE);
		print("--------------------------", NEW_LINE);
		print("1:Create Account", NEW_LINE);
		print("2:Login", NEW_LINE);
		print("3:Quit", NEW_LINE);
		break;
	case CreateAccountMenu:
		ClearConsole();
		print("Create Account", NEW_LINE);
		print("--------------", NEW_LINE);
		print("Username: ", SAME_LINE);
		std::cin >> username;
		print("Password: ", SAME_LINE);
		std::cin >> password;
		CreateAccount(root, username, password);
		break;
	case LoginMenu:
		ClearConsole();
		print("Login to your account", NEW_LINE);
		print("---------------------", NEW_LINE);
		print("Username: ", SAME_LINE);	std::cin >> newName;
		print("Password: ", SAME_LINE); std::cin >> newPass;
		LoginToAccount(root, "Test.json", newName, newPass);
		break;
	default:
		break;
	}
}