#pragma once
#include "vector"
#include "iostream"
#include "string"


using namespace std;


class SocialMedia
{
public:
	SocialMedia() {
		Start();
	}

	 void Start() {

		int Ask = 0;

		cout << "1- login." << endl;
		cout << "2- create new Account." << endl;
		cout << "3- Quit." << endl;
		cout << "Choose number: "; cin >> Ask;
		switch (Ask)
		{
		case 1:
			Login();
			break;
		case 2:
			CreateNewAccount();
			break;
		case 3:
			cout << "press any key to Exit..." << endl;
			return;
		default:
			cout << "Please enter correct number!" << endl;
			Start();
			break;
		}

	}

	void Login() {
		
		string name, pwd;
		int LoginStatus = 0;
		cout << "your name: "; cin >> name; cout << " , your password: "; cin >> pwd;
		for (unsigned int x = 0; x < this->UsersCapacity(); x++)
		{
			if (this->AccName.at(x) == name && this->AccPwd.at(x) == pwd) {
				cout << "welcome , " << AccName.at(x) << endl;
				this->CurrentUserID = x;
				return;
			}
			
		}
		if (LoginStatus == 0) { cout << "invalid user name or password" << endl; Login(); }
	}

	int RetrieveMaxUsers() {

		return MaxUsers;
	}

	void CreateNewAccount() {
		string name, pwd;
		cout << "Enter User name: "; cin >> name; cout << " , Enter Password: "; cin >> pwd;
		AccName.push_back(name);
		AccPwd.push_back(pwd);
		cout << "Account Created successfully !" << endl;
		Start();
	}


	int UsersCapacity() {

		return this->AccName.size();
	}

	bool CheckUserLogin() {
		if (CurrentUserID != -1) { return true; }
		else
		{
			return false;
		}
	}

private:
	int MaxUsers = 20;
	
protected:
	int CurrentUserID = -1;
	vector <string> AccName;
	vector <string> AccPwd;
	
};
