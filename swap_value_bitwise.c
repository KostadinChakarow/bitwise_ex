/*C program to swap two number bitwise.*/


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
unsigned char swap(unsigned char input1, unsigned char input2){
	
	input1 ^= input2;
	input2 ^= input1;
	input1 ^= input2;

	return 0;
}

/******************MAIN*********************/
int main(){
	unsigned char num1 = 0;
	unsigned char num2 = 0;


	while(1){
		printf("Enter number 1\n");
		scanf("%hhu", &num1);
		printf("Enter number 2\n");
		scanf("%hhu", &num2);
		swap(num1, num2);
		printf("number 1 = %hhu\n number 2 = %hhu\n", num1, num2);
		
	}
}