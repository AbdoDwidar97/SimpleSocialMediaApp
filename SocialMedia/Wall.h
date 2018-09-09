#pragma once
#include "vector"
#include "iostream"
#include "string"
#include "Posts.h"

using namespace std;

class Wall : public Posts
{
public:
	Wall() {

	}
	
	void ShowMyPosts() {
		system("cls");
		int PostID;
		for (int i = 0; i < this->UserIDForTextPost.size(); i++)
		{
			if (this->UserIDForTextPost.at(i) == this->MyAccountID()) {
				PostID = i;
				cout << this->AccName.at(MyAccountID()) << " posted:" << endl;
				cout << this->TextPost.at(PostID) << endl;
				cout << ".............................................................." << endl; cout << endl;
			}
		}

		for (int i = 0; i < this->UserIDForAudioPost.size(); i++)
		{
			if (this->UserIDForAudioPost.at(i) == this->MyAccountID()) {
				PostID = i;
				cout << this->AccName.at(MyAccountID()) << " posted:" << endl;
				cout << this->AudioPost.at(PostID) << endl;
				cout << ".............................................................." << endl; cout << endl;
			}
		}

		this->UserList();
	}




private:

};
