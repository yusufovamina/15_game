#include"game_logics.h"
#include"UI.h"
#include"users_operations.h"

void game(ushort game_field[][4]) {
	unsigned char arrow{};
	while (!isWin(game_field)) {
		arrow = _getch();
		arrow = _getch();
		system("cls");
		movement(game_field, arrow);
		showFields(game_field);
	}
}

int main() {
	srand(time(NULL));
	User admin;
	strcpy_s(admin.username,50, "Admin");
	strcpy_s(admin.password, 50, encrypt("salam",3));



	users[0] = admin;
	fopen_s(&file, "users.dat", "wb");
	fwrite((char*)users, sizeof(User), 1, file);

	fclose(file);



	ushort game_field[4][4]{};
	ushort menuItem = 0;
	//startIntro();
	const char* startMenu[] = { "  Start game","  Load Game","  Exit game" };
	const char* levels[] = { "  Easy","  Medium","  Hard" };
	const char* intromenu[] = { "  Sign In","  Sign Up","  Exit" };
	User currentUser;
	menuItem = menu(intromenu, 3);
	char login[50];
	char password[50];
	char confPassword[50];
	int index;
	switch (menuItem)
	{
	case 1:
		while (true) {
			system("cls");
			cout << "Enter the login:";
			cin >> login;
			cout << "Enter the password:";
			cin >> password;
			index = isUser(users, length, login);
			if (isUser(users, length, login) != -1 && strcmp(decrypt(password, 3), users[index].password)) {
				system("cls");
				currentUser=users[index];
				break;
			}
			else {
				cout << "Login or password is incorrect" << endl;
				system("pause");
				system("cls");
			}
		}
		break; 
	case 2:
		while (true) {
			system("cls");
			cout << "Enter the login:";
			cin >> login;
			cout << "Enter the password:";
			cin >> password;
			cout << "Confirm the password:";
			cin >> confPassword;
			index = isUser(users, length, login);
			system("cls");
			if (index != -1) {
				if (strcmp(password, confPassword) == 0) {
					strcpy_s(currentUser.username, 50, login);
					strcpy_s(currentUser.password, 50, encrypt(password, 3));
					users = addUser(users, length, currentUser);
					system("cls");
					break;
				}
				else {
					cout << "Password is not confirmed" << endl;
				}
			}
			else {
				cout << "Username already exists" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
	case 3:
		return 0;
	}

	menuItem = menu(startMenu, 3);
	switch (menuItem)
	{
	case 1:
		system("cls");
		menuItem = menu(levels, 3);
		fillFields(currentUser.game_field);
		startPosition(currentUser.game_field, levelArray[menuItem-1]);
		save(currentUser.game_field);
		break;
	case 2: 
		load(currentUser.game_field);
		break;
	case 3: return 0;
	}

	system("cls");
	showFields(currentUser.game_field);

	game(currentUser.game_field);
	win_animation();
}


