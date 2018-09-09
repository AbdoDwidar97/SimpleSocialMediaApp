#pragma once
#include "vector"
#include "iostream"
#include "string"
#include "User.h"

using namespace std;

class Posts : public User
{
public:
	Posts(){
		
	}
	 void PostList() {
		 int Ask;
		 cout << "1- Add text post." << endl;
		 cout << "2- Add Audio post (vedio or image)." << endl;
		 cout << "Choose number: "; cin >> Ask; cout << endl;
		 switch (Ask)
		 {
		 case 1:
			 AddNewTextPost();
			 break;
		 case 2:
			 AddNewAudioPost();
			 break;
		 default:
			 cout << "Enter correct number!" << endl;
			 PostList();
			 break;
		 }
	}
	void AddNewTextPost() {
		system("cls");
	    string Pst;
		cout << "what is your feelings !: " << endl; cin >> Pst; cout << endl;
		this->TextPost.push_back(Pst);
		this->UserIDForTextPost.push_back(this->MyAccountID());
		cout << "Your post saved on your timeline!" << endl;
		system("pause");
		system("cls");
		this->UserList();
	}

	void AddNewAudioPost() {
		system("cls");
		string Pst;
		cout << "Copy and paste path of video or image: " << endl; cin >> Pst; cout << endl;
		this->AudioPost.push_back(Pst);
		this->UserIDForAudioPost.push_back(this->MyAccountID());
		cout << "Your post saved on your timeline!" << endl;
		system("pause");
		system("cls");
		this->UserList();
	}

protected:
	vector <string> TextPost;
	vector <string> AudioPost;
	vector <int> UserIDForTextPost;
	vector <int> UserIDForAudioPost;
};

