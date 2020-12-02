/*C program to flip a number.*/


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
unsigned char total_ones(unsigned char input){
	unsigned char i = 0;
	unsigned char count_one = 0;
	unsigned char check_for_one = 1;

	while(i < 8){
		if(input & check_for_one)
			count_one++;
		check_for_one = check_for_one << 1;
		i++;
	}
	return count_one;
}
unsigned char total_zeros(unsigned char input){
	unsigned char i = 0;
	unsigned char count_zero = 0;
	unsigned char check_for_zero = 1;

	while(i < 8){
		if((input & check_for_zero) == 0)
			count_zero++;
		check_for_zero = check_for_zero << 1;
		i++;
	}
	return count_zero;
}
/******************MAIN*********************/
int main(){
	unsigned char num_entered = 0;
	unsigned char ones = 0;
	unsigned char zeros = 0;

	while(1){
		printf("Enter number to check\n");
		scanf("%hhu", &num_entered);
		printf("The binary of %hhu is: \n", num_entered);
		decimal_to_binary(num_entered);
		ones = total_ones(num_entered);
		zeros = total_zeros(num_entered);
		printf("The number of ones is: %hhu\n the number of zeros is: %hhu\n", ones, zeros);
	}
}