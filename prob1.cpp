#include <iostream>
#include <sstream>

#define MINSIZE 8											//Minimum size of password
#define MAXSIZE 14 												// Max size of password

using namespace std;

int break_passwords(string passwords,string password_status[][2]);                      // Breaks the password by semicolon
void first_space_remove(string password_status[][2],int size)     ;                     // remove the starting space 
int min_char_check(string password, int pass_size, char first, char last);				// check for minimum condition;
int min_special_char_check(string password, int pass_size)	;			                
int blank_check(string password, int pass_size);										// check for blank spaces in password
int special_char_check(string password, int pass_size);									// check for the special char
int length_check(int pass_size);														// check for password length
void passwords_status(string password_status[][2], int pass_size);                      // complete a 2 dim array by alloting their status
void print(string password_status[][2], int pass_size);									// print the passwords and their status

int main() {
	int size;
	string passwords, password_status[100][2];
	getline(cin, passwords); 										// Take input multiple passwords seperated by semicolon	
	size = break_passwords(passwords,password_status);
	first_space_remove(password_status, size);
	passwords_status(password_status, size);
	print(password_status,size);
	return 0;
}

int break_passwords(string passwords,string password_status[][2]){
	istringstream ss(passwords); // 
	int i = 0;
	string pass; 
	while(getline(ss, pass, ';')) {
		password_status[i][0] = pass;
		i++;		
	}
	return i;
}

void first_space_remove(string password_status[][2],int size){   // It removes the space just after semicolon 
	int j;
	for(int i = 1; i < size; i++){  							 // First password does not have extra space at the starting of password string
		for(j = 0; j < password_status[i][0].size()-1; j++){     
			password_status[i][0][j] = password_status[i][0][j+1];  // change the string by replacing the space
		}
		password_status[i][0][j] = '\0';
		
	}
}

int min_char_check(string password, int pass_size, char first, char last){   // It checks the condition that password have at least 1 char between first and second.
	for(int i = 0; i < pass_size; i++){
		if(password[i] >= first && password[i] <= last){
			return 1;
		}
	}
	return 0;
}

int min_special_char_check(string password, int pass_size){   // It checks the condition that password have at least 1 char between first and second.
	for(int i = 0; i < pass_size; i++){
		if(password[i] == '$' || password[i] == '#' || password[i] == '@' || password[i] == '%'){
			return 1;
		}
	}
	return 0;
}
int blank_check(string password, int pass_size){    // check for a blank space between a password
	for(int i = 0; i < pass_size; i++){
		if(password[i] == ' '){
			return 0;
		}
	}
	return 1;
}
int special_char_check(string password, int pass_size){    // check for some spacial characters like '+-,.='
	for(int i = 0; i < pass_size; i++){
		if(password[i] == '+' || password[i] == '-' || password[i] == ',' || password[i] == '.' || password[i] == '='){
			return 0;
		}
	}
	return 1;
}  
int length_check(int pass_size){                           // check for the length of a password
	if(pass_size >= MINSIZE && pass_size <= MAXSIZE){
		return 1;
	}
	else{
		return 0;
	}
}

void passwords_status(string password_status[][2], int size){    // It assign the status of the password.
	int pass_size;
	string password;
	for(int i = 0; i < size; i++){
		password = password_status[i][0];
		pass_size = password_status[i][0].size();
		if(	min_char_check(password,pass_size,'a','z')==0 || min_char_check(password,pass_size,'0','9')==0 ||
			min_char_check(password,pass_size,'A','Z')==0 || min_special_char_check(password, pass_size)==0 ||
			blank_check(password,pass_size) == 0 || special_char_check(password,pass_size) == 0 ||
			length_check(pass_size) == 0 ){              // if anyone is returning 0  then password is False othervise Ture
			password_status[i][1] = "False";
		}
		else{
			password_status[i][1] = "True";
		}	
	}
}

void print(string password_status[][2], int size){      // Print the password and its status
	for(int i = 0; i < size; i++){
		cout << password_status[i][0] << ", " << password_status[i][1] << endl;
	}
}



//http://ideone.com/bCfFMU
//http://ideone.com/7o86AA