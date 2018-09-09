#pragma once
#include "vector"
#include "iostream"
#include "string"
#include "SocialMedia.h"

class User : public SocialMedia
{
private:
	bool PostStatus = false;
	bool WallStatus = false;
public:
	User() {
		
	}
	
	 void UserList() {
		bool PostStatus = false;
		bool WallStatus = false;
		int Ask;
		cout << "welcome, " << this->AccName.at(MyAccountID()) << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "1- View My profile Information." << endl;
		cout << "2- Edit My informaion." << endl;
		cout << "3- change password." << endl;
		cout << "4- Logout." << endl;
		cout << "5- Add posts." << endl;
		cout << "6- My Wall" << endl;
		cout << "Choose Number of choice: "; cin >> Ask; cout << endl;
		switch (Ask)
		{
		case 1:
			ViewProfile();
			break;
		case 2:
			EditMyInfo();
			break;
		case 3:
			ChangePwd();
			break;
		case 4:
			Logout();
			break;
		case 5:
			this->PostStatus = true;
			return;
		case 6:
			this->WallStatus = true;
			return;
		default:
			cout << "Enter correct number!" << endl;
			UserList();
			break;
		}
	}

	void ViewProfile() {
			try
			{
				cout << "your name: " << this->AccName.at(MyAccountID()) << " - your ID: " << MyAccountID() << endl;
				system("pause");
				system("cls");
				UserList();
			}
			catch (const std::exception&)
			{
				system("cls");
				UserList();
				return;
			}
		
	}

	void EditMyInfo() {
		string nm;
		cout << "Enter name: "; cin >> nm;
		this->AccName.at(MyAccountID()) = nm;
		cout << "your data updated successfully!" << endl;
		system("pause");
		system("cls");
		UserList();
	}

	bool CheckPostStatus() {
		if (PostStatus == true) { return true; }
		else {
			return false;
		}
	}

	bool CheckWallStatus() {
		if (WallStatus == true) { return true; }
		else { return false; }
	}


	bool CheckPwd(string pwd) {
		
		if (pwd == this->AccPwd.at(MyAccountID())) {
			return true;
		}
		else
		{
			return false;
		}
	}


	void ChangePwd() {
		string Oldpwd , Newpwd; 
		cout << "Enter Current password: "; cin >> Oldpwd;

		if (CheckPwd(Oldpwd)== true) {
			cout << "Enter new password: "; cin >> Newpwd;
			this->AccPwd.at(MyAccountID()) = Newpwd;
			cout << "password Changed successfully!" << endl;
		}
		else
		{
			cout << "Please enter current password correctly!" << endl;
			ChangePwd();
		}
		system("pause");
		system("cls");
		UserList();
	}

	int MyAccountID() {
		return this->CurrentUserID;
	}

	void Logout() {

		this->CurrentUserID = -1;
		this->Start();
	}

};
