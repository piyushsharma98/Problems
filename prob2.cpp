#include <iostream>
#include  <string>

using namespace std;

void Secret_key(string pattern);

int main(){
	string pattern; 
	cout << "Please Enter the pattern of X and Y : " << endl;									// assign string variable 
	cin >> pattern;										// take string input as pattern
	Secret_key(pattern);								// function is called to find secret key
	return 0;

}

void Secret_key(string pattern){
	int i,j;
	int num_y=0;  										// no of consecutive Y
	int max_num=0;  									// max number printed	
	int pre_num=0; 										// last printed number
	int size = pattern.size();  						// pattern length
	for(i=0;i < size;i++){		
		num_y = 0;
		if(pattern[i]=='Y'){                            // if Y is found
			if(i==0){									// if 1st digit
				j = 0;
				while(pattern[j]=='Y' && j < size){  	// finds number of consecutive Y including first Y 
					num_y++;
					j++;
				}
				max_num = num_y + 1;  			 		// Max number to print
				cout << max_num << max_num-1;			// print max number and next digit
				pre_num = max_num-1;  			 		// last printed number
			}
			else{
				pre_num--;   					 		// if not starting Y than decrease the pre_num value and print
				cout << pre_num;
			}

		}
		else if(pattern[i]=='X'){
			j = i+1;
			while(pattern[j]=='Y' && j < size){  		// finds number of consecutive Y after X
				num_y++;
				j++;
			}

			if(i==0){                            		// if 1st digit
				max_num = max_num + num_y + 2;   		// if first X then max_num is increased by number of consecutive Y + 2
				pre_num++;  					 		// Pre_num is increase because it is X 
				cout << pre_num << max_num;     		// Prints 1 and next digit 
				pre_num = max_num;               		// assign previous digit
			}			
			else{                                		// if not 1st digit
				max_num = max_num + num_y + 1;   		// assign max digit
				cout << max_num;				 		// print max digit
				pre_num = max_num;               		// assign previous digit
			}			

		}

	}
}




// http://ideone.com/7o86AA