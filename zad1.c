
/*Write a C program to input any number from user 
and check whether the Least Significant Bit (LSB) of the given number is set (1) or not (0). How to check whether the least significant bit of a number is set or unset using bitwise operator in C programming. C program to get the 
status of least significant bit of a number.*/


/******************INCLUDES*****************/
#include <stdio.h>
/******************DEFINES******************/
/******************FUNCTIONS****************/
unsigned char decimal_to_binary(unsigned char input){
	unsigned char binary[9];
	int i = 0;                  //varible to conrol the first for loop
	int j = 0;					//variable to control the second for loop

	for(i = 0; i < 8; i++){
		if(input > 0 ){             //put the remainder in array if *binP > 0
			binary[i] = (input % 2);
			input = input / 2;
			
		}
		else                        //else put 0s
			binary[i] = 0;
		
	}
	for(j = i - 1; j >= 0; j--){
		printf("%d", binary[j]);	//print the array from last to first element
	}
	printf("\n");
	return 0;
}
unsigned char check_least(unsigned char input){
	if(input & 128)
		return 1;
	else
		return 0;
}
/******************MAIN*********************/
int main(){
	unsigned char num_entered = 0;
	_Bool check = 0;
	while(1){
		printf("Enter number to check\n");
		scanf("%hhu", &num_entered);
		printf("The binary of %hhu is: \n", num_entered);
		decimal_to_binary(num_entered);
		check = check_least(num_entered);
		if(check == 1)
			printf("The most significant bit is set 1\n");
		else
			printf("The least significant bit is 0\n");

	}
}