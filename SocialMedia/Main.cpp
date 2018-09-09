#include "iostream"
#include "string"
#include "SocialMedia.h"
#include "User.h"
#include "Posts.h"
#include "Wall.h"
using namespace std;

int main()
{

	cout << "Welcome to SocialMedia!" << endl;
	cout << "=====================================================" << endl;
	
	Wall wl;
	Posts *p = &wl;
	User *u = p;
	SocialMedia *S = u;
	
	while (S->CheckUserLogin() == true) {
		system("cls");
		u->UserList();
		if (u->CheckPostStatus() == true) { p->PostList(); }
		if (u->CheckWallStatus() == true) { wl.ShowMyPosts(); }
		
	}
	
	system("pause");
	return 0;
}