#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int acc_no;
	char* name;
	int acc_bal;
	int debt[10];
	char* username;
	char* password;
	struct node *next;
	struct node *prev;
};
typedef struct node n;

n* create_node();
void add_node();
void insert_at_end();
void delete_node();
void update();
int search(int);
void updateDatabase();
void display_from_beg();
int generateAccountNumber();
void balanceTransfer();
void loanManagement();
int loanManager(int*,int);

n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0,count_times=1;

void main()
{
	int ch,x=0,ac11,ch1,ch2;
	char x1[1000];
	//printf("1.Create Account\n 2.Delete Account\n 3.Update Database\n4.Verify Account \n5.Display Database\n6.Check Balance\n7.Deposit\n8.Withdraw\n9.Loan Management\n10.Balance Transfer\n11.Exit\n");
	mainmenu:
	printf("\n\t\tVIT Bank\n\t1.Customer Login\n\t2.Staff Login\n\t3.Exit\n");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
				cust:
				printf("\n\t\tVIT Bank : Customer\n\t1.Check Balance\n\t2.Deposit\n\t3.Withdraw\n\t4.Balance Transfer\n\t5.Exit\n");
				printf("\nEnter your choice:");
				scanf("%d",&ch1);
				if(ch1==1){
					printf("\nPlease enter the account number:");
					int ac1;
					scanf("%d", &ac1);
					int z1 = search(ac1);
					if (z1 != -9999)
					{
						int bal=ptr->acc_bal;
						printf("\nAccount number:%d\n  Account Balance:%d", ac1, bal);
					}
					else
					{
						printf("\nAccount does not exist!");
					}	
					goto cust;}
				else if(ch1==2){
					printf("\nPlease enter the account number:");
					scanf("%d", &ac11);
					int z11 = search(ac11);
					if (z11 != -9999)
					{
						int i;
						if (first == last && first == NULL)
							printf("\nlist is empty no elemnts to print");
						else
						{
							for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
								if (ptr->acc_no == ac11)
								{
									printf("Please enter the amount to be deposited:");
									int dep;
									scanf("%d",&dep);
									dep=ptr->acc_bal+dep;
									ptr->acc_bal=dep;
									break;
								}
						}
						updateDatabase();
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto cust;}
				else if(ch1==3){
					printf("\nPlease enter the account number:");
					scanf("%d", &ac11);
					int z111 = search(ac11);
					if (z111 != -9999)
					{
						int i;
						if (first == last && first == NULL)
							printf("\nSorry!No Accounts detected! Contact developer!\n");
						else
						{	
							for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
								if (ptr->acc_no == ac11)
								{
									printf("Please enter the amount to be withdrawn:");
									int with;
									scanf("%d",&with);
									with=ptr->acc_bal-with;
									ptr->acc_bal=with;
									break;
								}
						}
						updateDatabase();
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto cust;}
				else if(ch1==4){
					balanceTransfer();
					updateDatabase();
					goto cust;}
				else if(ch1==5){
					goto mainmenu;
				}
				else{
					printf("\nSorry! Invalid Input!\n");
				}
			case 2:
				start:
				printf("\t\t\tVIT Bank : Staff\n\t1.Create Account\n\t2.Delete Account\n\t3.Update Database\n\t4.Verify Account \n\t5.Display Database\n\t6.Check Balance\n\t7.Deposit\n\t8.Withdraw\n\t9.Loan Management\n\t10.Balance Transfer\n\t11.Exit\n");
				printf("\nEnter your choice:");
				scanf("%d",&ch2);
				if(ch2==1){
					insert_at_end();
					updateDatabase();
					goto start;
				}
				else if(ch2==2){
					delete_node();
					goto start;
				}
				else if(ch2==3){
					updateDatabase();
					goto start;
				}
				else if(ch2==4){
					printf("\nPlease enter the account number:");
					int ac;
					scanf("%d", &ac);
					int z = search(ac);
					if (z != -9999)
					{
						printf("\nAccount exists!");
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto start;
				}
				else if(ch2==5){
					display_from_beg();
					goto start;
				}
				else if(ch2==6){
					printf("\nPlease enter the account number:");
					int ac1;
					scanf("%d", &ac1);
					int z1 = search(ac1);
					if (z1 != -9999)
					{
						int bal=ptr->acc_bal;
						printf("\nAccount number:%d\n  Account Balance:%d", ac1, bal);
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto start;
				}
				else if(ch2==7){
					printf("\nPlease enter the account number:");
					scanf("%d", &ac11);
					int z11 = search(ac11);
					if (z11 != -9999)
					{
						int i;
						if (first == last && first == NULL)
						printf("\nlist is empty no elemnts to print");
						else
						{
							for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
								if (ptr->acc_no == ac11)
								{
									printf("Please enter the amount to be deposited:");
									int dep;
									scanf("%d",&dep);
									dep=ptr->acc_bal+dep;
									ptr->acc_bal=dep;
									
								}
						}
						updateDatabase();
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto start;
				}
				else if(ch2==8){
					printf("\nPlease enter the account number:");
					scanf("%d", &ac11);
					int z111 = search(ac11);
					if (z111 != -9999)
					{
						int i;
						if (first == last && first == NULL)
						printf("\nSorry!No Accounts detected! Contact developer!\n");
						else
						{
							for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
							if (ptr->acc_no == ac11)
							{
								printf("Please enter the amount to be withdrawn:");
								int with;
								scanf("%d",&with);
								with=ptr->acc_bal-with;
								ptr->acc_bal=with;
								
							}
						}
						updateDatabase();
					}
					else
					{
						printf("\nAccount does not exist!");
					}
					goto start;
				}
				else if(ch2==9){
					loanManagement();
					updateDatabase();
					goto start;
				}
				else if(ch2==10){
					balanceTransfer();
					updateDatabase();
					goto start;
				}
				else if(ch2==11){
					goto mainmenu;
				}
				else{
					printf("Sorry! Invalid input!");
					goto start;
				}
			case 3:
				exit(0);
		}
	}
}
/*
*ACCOUNT NUMBER GENERATED RANDOMLY HERE
*/
int generateAccountNumber()
{
	int r = rand() % 9000 + 1000;
	return r;
}
/*
BALANCE TRANSFER SUBSYSTEM
*/
void balanceTransfer()
{
	int ac11,ac22,amt;
	printf("\nPlease enter the account number:");
	scanf("%d", &ac11);
	printf("Enter the amount to be transferred:");
	scanf("%d",&amt);
	int z111 = search(ac11);
	if (z111 != -9999)
	{
		int i;
		if (first == last && first == NULL)
		printf("\nSorry!No Accounts detected! Contact developer!\n");
		else
		{
			for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
				if (ptr->acc_no == ac11)
				{
					ptr->acc_bal-=amt;
					break;
				}
		}
		printf("Please enter the account number where you want to transfer:");
		scanf("%d",&ac22);
		if (first == last && first == NULL)
			printf("\nSorry!No Accounts detected! Contact developer!\n");
		else
		{
			for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
				if (ptr->acc_no == ac22)
				{
					ptr->acc_bal+=amt;
					break;
				}
		}
		
	}
	printf("\nTransfer successful!\n");
}
/*
LOAN MANAGEMENT SUBSYSTEM
*/
void loanManagement()
{
	int ac11;
	printf("\nPlease enter the account number:");
	scanf("%d", &ac11);
	int z111 = search(ac11);
	if (z111 != -9999)
	{
		int i;
		if (first == last && first == NULL)
		printf("\nSorry!No Accounts detected! Contact developer!\n");
		else
		{
			for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
				if (ptr->acc_no == ac11)
				{
					printf("\nWelcome to LOAN MANAGEMENT SYSTEM\n");
					loanManager(ptr->debt,count_times);
					count_times++;
					return;
				}
		}
	}
}

/*
*SAVE ACCOUNT DETAILS TO FILE
*/
void updateDatabase()
{
	FILE *fptr;
	char f[1000];
	int i;
	fptr = fopen("Database.txt", "w");
	if (fptr == NULL) {
		printf("Error!");
	}
	if (first == last && first == NULL)
	{
		printf("\nNo accounts detected! Please Contact Developer!");
	}
	else
	{
		int x=0;
		for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
		{
			fprintf(fptr, "%d\n", ptr->acc_no);
			sprintf(f, "%d", ptr->acc_no);
			FILE *accptr;
			accptr = fopen(f, "w");
			fprintf(accptr, "%s\n%s\n%s\n%d", ptr->name, ptr->username, ptr->password, ptr->acc_bal);
			fclose(accptr);
		}
	}

	fclose(fptr);
}
/*
*MEMORY ALLOCATED FOR NODE DYNAMICALLY
*/
n* create_node()
{
	char* name=(char *)malloc(1000);
	char* usrnm=(char *)malloc(1000);
	char* psswd=(char *)malloc(1000);
	printf("\nEnter your name:");
	scanf("%s", name);
	
	int check=1;
	while(check==1)
	{
		printf("\nEnter your username:");
		scanf("%s",usrnm);
		check=0;
		int i;
		if (first != last || first != NULL)
		
		{
			printf("\n%d number of nodes are there\n", number);
			for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
				if (ptr->username == usrnm)
				{
					check=1;
				}
		}
		if(check==1)
		{
			printf("\nSorry!Username already taken!\n");
		}
	}
	printf("Please enter your password:");
	scanf("%s",psswd);
	printf("Enter the amount you want to deposit:");
	int balDep;
	scanf("%d", &balDep);
	number++;
	new = (n *)malloc(sizeof(n));
	new->acc_no = generateAccountNumber();
	new->name = name;
	new->username = usrnm;
	new->password = psswd;
	new->acc_bal = balDep;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
/*
*INSERTS ELEMENT AT END
*/
void insert_at_end()
{
	new = create_node();
	if (first == last && first == NULL)
	{
		first = last = new;
		first->next = last->next = NULL;
		first->prev = last->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		last = new;
		first->prev = last;
		last->next = first;
	}
}
/*
*DELETION IS DONE
*/
void delete_node()
{
	int pos, count = 0, i;
	n *prevnode;
	if (first == last && first == NULL)
		printf("\nSorry! No accounts detected! Please contact developer!\n");

	else
	{
		printf("\nPlease enter the account number:");
		int ac1;
		scanf("%d", &ac1);
		int pos = search(ac1);
		if (pos != -9999)
		{
			//int bal=ptr->acc_bal;
			//printf("\nAccount number:%d\n  Account Balance:%d", ac1, bal);
			for (ptr = first, i = 1; i<=number ; i++, ptr=ptr->next)
			{
				prevnode = ptr;
				if (pos == 1)
				{
					number--;
					last->next = prevnode->next;
					ptr->prev = prevnode->prev;
					first = ptr;
					printf("\n%d is deleted\n", prevnode->acc_no);
					free(prevnode);
					break;
				}
				else if (i == pos)
				{
					number--;
					prevnode->next = ptr->next;
					ptr->next->prev = prevnode;
					printf("\n%d is deleted\n", ptr->acc_no);
					free(ptr);
					break;
				}
			}
			char* ff="del ";
			char* ff1=(char *)malloc(7);
			char* ff2=(char *)malloc(4);
			strcpy(ff1,ff);
			sprintf(ff2, "%d\n", ac1);
			strcat(ff1,ff2);
			printf("%s",ff1);
			system(ff1);
		}
		else
		{
			printf("\nAccount does not exist!");
		}
		
		if (number < pos)
			printf(" ");

		else
		{
			
		}
	}
}
/*
.*UPDATION IS DONE FOR GIVEN OLD VAL
*/
void update(int component)
{
	int i, f = 0;
	char ov[1000];
	char nv[1000];
	if (first == last && first == NULL)
		printf("\n list is empty no elemnts for updation");
	else
	{
		for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
		{
			if (component == 1)
			{
				printf("Please enter the original name of the account holder:");
				scanf("%s", ov);
				printf("Please enter the updated name of the account holder:");
				scanf("%s", nv);
				if (ptr->name == ov)
				{
					ptr->name = nv;

					printf("value is updated to %d", ptr->acc_no);
					f = 1;
				}
			}

		}
		if (f == 0)
			printf("\n no such old value to be get updated");
	}
}
/*
*SEARCHING USING SINGLE KEY
*/
int search(int accn)
{
	int i;
	if (first == last && first == NULL)
		printf("\nlist is empty no elemnts to print");
	else
	{
		printf("\n%d number of nodes are there\n", number);
		for (ptr = first, i = 1; i <= number; i++, ptr = ptr->next)
			if (ptr->acc_no == accn)
			{
				
				return i;
			}
	}
	return -9999;
}
/*
*DISPLAYING IN BEGINNING
*/
void display_from_beg()
{
	int i;
	if (first == last && first == NULL)
		printf("\nlist is empty no elemnts to print");
	else
	{
		printf("\n%d number of nodes are there\n", number);
		for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
			printf("\n %d", ptr->acc_no);
	}
}

int array_length=10;
int stack_end_pointer=-1;
void display(int stack[10])
{
	int i;
	if(stack_end_pointer==-1)
	{
		printf("No pending loans found!");
	}
	else
	{
		for(i=0;i<stack_end_pointer;i++)
		{
			printf("%d->",stack[i]);
		}
		printf("%d",stack[stack_end_pointer]);
	}
	printf("\n");
}
void insert(int n,int stack[10])
{
	if(stack_end_pointer==9)
	{
		printf("Error:Loan qouta over!Please clear your previous loans!\n");
	}
	else
	{
		stack_end_pointer++;
		stack[stack_end_pointer]=n;
		printf("Loan registration successful!\n");
		printf("Updated list of loans:\n");
		display(stack);
	}
}
void delete(int stack[10])
{
	if(stack_end_pointer==-1)
	{
		printf("No pending loans found!\n");
	}
	else
	{
		stack[stack_end_pointer]=0;
		stack_end_pointer--;
		printf("Loan payment successful!\n");
		printf("Updated list of pending loans:\n");
		display(stack);
	}
}
int loanManager(int stack[10],int cc11)
{
	int choice,input,pos_input;
	printf("-----------Loan Management Menu--------\n");
	printf("1)Add from the end\n");
	printf("2)Delete from the end\n");
	printf("3)Display\n");
	printf("4)Exit\n");
	int i;
	for(i=1;i<cc11;i++)
	{
		delete(stack);
	}
	do
	{
		printf("Please enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Please enter the loan amount:");
				   scanf("%d",&input);
				   insert(input,stack);
				   break;
			case 2:delete(stack);
				   break;
			case 3:display(stack);
				   break;
			case 4:exit(0);
			default:printf("Error:Invalid input!\n");
		}	
	}while(choice!=6);
}
