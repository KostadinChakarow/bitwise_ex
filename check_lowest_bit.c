/*C program to check for the lowest set bit of a number.*/


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
unsigned char find_trailing_zero(unsigned char input){
	int i = 0;              		//Cycle controlling variable
	unsigned char check = 1;		//Mask to checck high bit
	//unsigned char lowest_high_bit = 0;		//count high set bits in number

	while(i < 8){
			if(input & check){
				return i;
			}
			check = check << 1;
			i++;
		}
		
	return 0;
}
/******************MAIN*********************/
int main(){
	unsigned char num_entered = 0;
	unsigned char bit_place = 0;
	int trailing_zero_num = 0;

	while(1){
		printf("Enter number to check\n");
		scanf("%hhu", &num_entered);
		printf("The binary of %hhu is: \n", num_entered);
		decimal_to_binary(num_entered);
		trailing_zero_num = find_lowest_set(num_entered) - 1;
		printf("The number of trailing zeros in %hhu is %hhu\n", num_entered, lowest_bit_set);
	}
}