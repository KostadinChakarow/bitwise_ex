
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
unsigned char set_nth_bit(unsigned char input, unsigned char bit){
	int i = 0;
	unsigned char check = 1;
	unsigned char loc_input = input;
	unsigned char loc_bit = bit;

	while(1){
		if(i == loc_bit){
			if(loc_input & check)
				return 0;
			else {
				loc_input = loc_input | check;
				return loc_input;
			}
		}
		check = check << 1;
		i++;
	}
}
/******************MAIN*********************/
int main(){
	unsigned char num_entered = 0;
	unsigned char bit_place = 0;
	unsigned char  set_bit= 0;
	while(1){
		printf("Enter number to check\n");
		scanf("%hhu", &num_entered);
		printf("Enter bit number:\n");
		scanf("%hhu", &bit_place);
		printf("The binary of %hhu is: \n", num_entered);
		decimal_to_binary(num_entered);
		set_bit = set_nth_bit(num_entered, bit_place);
		if(set_bit != 0){
			printf("The new number with bit %hhu set is: \n", bit_place);
			decimal_to_binary(set_bit);
			
		}
		else{
			printf("The %hhu bit is already set\n", bit_place);
			decimal_to_binary(num_entered);
		}
		bit_place = 0;
		set_bit = 0;
		num_entered = 0;


	}
}