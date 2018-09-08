/*
 * loan.c
 *
 *  Created on: 08-Sep-2018
 *      Author: vamshidhar
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef NULL
#define NULL   ((void *) 0)
#endif
int main(){


    float loan_amount, interest_rate, monthly_payment, balance_amount, interest,principle_amount,numberArray[16];
    int n, j=1,i,q,p=1;
    FILE *myFile;
    myFile = fopen("New .txt", "r");

    //read file into array


    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < 10; i++){
        fscanf(myFile, "%f,", &numberArray[i] );
    }

    for (i = 0; i < 10; i++){
        printf("Number is: %f\n\n", numberArray[i]);
    }

    fclose(myFile);
	i=numberArray[0];
	printf("i value is %d\n",i);

		for(q=0;q<i;q++,p=p+3){ j=1;
		loan_amount=numberArray[p];
		interest_rate=numberArray[p+1];
		monthly_payment=numberArray[p+2];
	printf("Payment \t monthly_payment\t interest \t principle_amount    balance_amount\n");

        while(loan_amount>=0)
        {
            interest = loan_amount*interest_rate/12;
            loan_amount=loan_amount+interest;
            balance_amount=loan_amount-monthly_payment;
            principle_amount=monthly_payment-interest;

 			if(balance_amount>=0)
               { printf(" %5d\t\t %.2f\t\t\t %.2f\t\t\t%.2f   %.2f\n",j, monthly_payment,interest,principle_amount,balance_amount);
                	}
            else
            {
				principle_amount=balance_amount+monthly_payment-interest;
				printf(" %5d\t\t %.2f\t\t\t %.2f\t\t\t%.2f\t  0\n",j, (principle_amount+interest),interest, principle_amount);
				printf("total number of installments are:%d\n",j);

            }
			loan_amount = balance_amount;
            j++;
        }


	}


    return 0;
}

