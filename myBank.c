#include <stdio.h>
#include <math.h>
#include "myBank.h"

double arr[R_SIZE][C_SIZE]={{0}};
//arr[] => account number
//arr[][] => balance
int openAcc = 0;
void O (){ //open account
	if(openAcc >= 50){
		printf("ERROR: Too many bank accounts \n");
		return;
	}
	int k = -1;
	for(int i = 0; i < C_SIZE; i++){
		if(arr[0][i] == CLOSE){
			k = i;
			i = C_SIZE;
		}
	}
	if (k == -1){
		printf("ERROR: Too many bank accounts \n");
	}
	double m = 0;
	printf("Please enter amount for deposit: ");
	if(scanf(" %lf", &m) == 1){
		if(m <= 0){
			printf("Invalid Amount \n");
			return;
		}
		arr[0][k] = OPEN;
		arr[1][k] = m;
		printf("New account number is %d \n", k + 901);
		openAcc++;
		return;
	}
	printf("Failed to read the amount \n");
}

void B (){ //balance of account
	if(openAcc == 0){
		printf("This account is closed \n");
		return;
	}
	int a;
	printf("Please enter account number: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			printf("The balance of account number %d is: %.2lf \n", a, arr[1][i]);
		}else return;
	}else printf("Invalid input \n");
}

void D (){ //deposit to account
	// if(openAcc == 0){
	// 	printf("ERROR: All accounts are closed \n");
	// 	return;
	// }
	int a;
	printf("Please enter account number: ");
	if((scanf(" %d", &a) == 1)&&(a >= 0)){
		int i = a - 901;
		if(check(i)){
			double d;
			printf("Please enter the ammount to deposit: ");
			if(scanf(" %lf", &d) == 1){			
				if(d < 0){
					printf("Cannot deposit a negative ammount \n");
					return;
				}
				arr[1][i] += d;
				printf("The new balance is: %.2lf \n", arr[1][i]);
			}else printf("Failed to read the ammount\n");
		}else return;
	}else printf("Invalid account number \n");
	
}
void W (){ //withdraw from account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a = 0;
	printf("Please enter account number: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			double d;
			printf("Please enter the amount to withdraw: ");
			if(scanf(" %lf", &d) == 1){		
				if(d < 0){
					arr[1][i] -= d;
					printf("The new balance is: %.2lf \n", arr[1][i]);
					return;
				}
				else if(d > arr[1][i]){
					printf("Cannot withdraw more then the balance \n");
					return;
				}
				arr[1][i] -= d;
				printf("The new balance is: %.2lf \n", arr[1][i]);
			}else printf("Invalid input \n");
		}else return;
	}else printf("Invalid input \n");
}

void C (){ //close account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a = 0;
	printf("Please enter account number: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			arr[0][i] = CLOSE;
			arr[1][i] = 0;
			printf("Closed account number %d \n", a);
			openAcc--;
		}else return;
	}else printf("Invalid input \n");
}

void I (){ //add interest by %
	if(openAcc == 0){
		printf("Invalid interest rate no accounts are open \n");
		return;
	}else{
		double a;
		printf("Please enter interest rate:");
		if(scanf(" %lf", &a) == 1){
			if(a < 0){
				printf("Cannot interest negative number \n");
				return;
			}
			a = a / 100;
			for(int i = 0; i < C_SIZE; i++){
				if(arr[0][i] == OPEN){
						arr[1][i] += (arr[1][i] * a);
				}
			}
			a *= 100;
			printf("Interest of %.2lf", a);
			printf(" has been added. \n");
		}else printf("Failed to read the interest rate \n");
	}
}
void P (){ //print all open accounts
	if (openAcc == 0){
		return;
	}else{
		int counter = 0;
		for(int i = 0; i < C_SIZE; i++){
			if(arr[0][i] == OPEN){
				counter++;
				printf("The balance of account number %d is: %.2f\n" , i + 901, arr[1][i]);
			}
		}
		printf("\n");
	}
}

void E (){
	openAcc = 0;
	for (int i = 0; i < C_SIZE; i++){
		arr[0][i] = 0;
		arr[1][i] = 0;
	}
	printf("Exiting program \n");
}

_Bool check (int i){
	if (i < 0 || i > 49){
		printf("Error: Invalid account number \n");
		return 0;
	}
	if(!isOpen (i)){
		printf("This account is closed \n");
		return 0;
	}
	return 1;
}

_Bool isOpen (int i){
	if(arr[0][i] == CLOSE){
		return 0;
	}return 1;
}