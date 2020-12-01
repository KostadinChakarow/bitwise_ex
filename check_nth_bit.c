
/*C program to check if nth bit is set or not.*/


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
unsigned char check_nth_bit(unsigned char input, unsigned char bit){
	int i = 0;
	unsigned char check = 1;

	while(1){
		decimal_to_binary(check);
		if(i == bit){
			printf("in if\n");
			if(input & check){
				printf("high bit check");
				return 1;
			}
			else
				return 0;
		}
		check = check << 1;
		i++;
	}
}
/******************MAIN*********************/
int main(){
	unsigned char num_entered = 0;
	unsigned char bit_place = 0;
	_Bool check = 0;
	while(1){
		printf("Enter number to check\n");
		scanf("%hhu", &num_entered);
		printf("Enter bit number:\n");
		scanf("%hhu", &bit_place);
		printf("The binary of %hhu is: \n", num_entered);
		decimal_to_binary(num_entered);
		check = check_nth_bit(num_entered, bit_place);
		printf("check - %d\n", check);
		if(check == 1)
			printf("The nth bit is set 1\n");
		else
			printf("The nth bit is 0\n");

	}
}