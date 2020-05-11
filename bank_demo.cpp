#include<stdio.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct bank     //Declaring The Structure For Linked List
{
	int acc_no;
	char username[100];
	char password[50];
	int acc_balance;
	char name[100];
	struct bank *next;
}bank;
time_t tt;
int acno=100000,y=1;
int buffer=strlen(ctime(&tt))+2;
bank *head=NULL;



//Functions For UI
void space();
void space2();
void hd();
void print();
int log_in();
char menu();

//Functions For Working
int cash(int n,bank *t);
void edit();
void sign_up();
void dlt();
void update();
bank* crtdb(char n[100],char u[100],char p[50],int b,int a);
int autofill();
void cashmemo(int i,int ac, int p,int a,int n);
void crt(char n[100],char u[100],char p[50],int b);



void space()
{ 
	printf("                       ");
}

void space2()
{
	printf("           ");
}

int autofill()
{
	FILE *fp;
	char ch;
	bank *t;
	fp=fopen("Customer_database.txt","rt");
	if(fp==NULL)
	return 0;
		
	int e=1,m=0;
	int ac,b,i;
		char n[100],u[100],p[50];
	char k;
	for(k=getc(fp);k!=EOF;k=getc(fp))
	{
		if(k == '\n')
		{
	
		e++;

		}
		
	}
		rewind(fp);
	
	for(i=0;i<e;i++)
		{
			//printf("%d",e);
		fscanf(fp,"%d%s%s%s%d",&ac, n, u, p,&b);
		t= crtdb(n,u,p,b,ac);
		}
	fclose(fp);
		acno=t->acc_no;
}

bank* crtdb(char n[100],char u[100],char p[50],int b,int a)
{
	

	bank *newnode=(bank*)malloc(sizeof(bank));
	newnode->acc_balance=b;
	strcpy(newnode->name,n);
	strcpy(newnode->username,u);
	strcpy(newnode->password,p);

	acno++;
	newnode->acc_no=a;
	newnode->next=NULL;
	
	if(head==NULL)
	head=newnode;
	else
	{
		
		bank *tmp=head;
		while(tmp->next!=NULL)
		tmp=tmp->next;
		tmp->next=newnode;
	
	}
	//print();
	fflush(stdin);
	return(newnode);
}

void update()
{
	FILE *fp1=fopen("Customer_database.txt","w");
	bank *tmp;
	tmp=head;
	if(head!=NULL)
	while(tmp!=NULL)
	{
		if(tmp==head)
		fprintf(fp1,"%d %s %s %s %d",tmp->acc_no,tmp->name,tmp->username,tmp->password,tmp->acc_balance);
		else
		fprintf(fp1,"\n%d %s %s %s %d",tmp->acc_no,tmp->name,tmp->username,tmp->password,tmp->acc_balance);
	tmp=tmp->next;
	}
	fclose(fp1);
}

int main()
{
	if(y==1)
	autofill();
	y=1234;
	int p=1;
	while(p)
	{
	update();
	hd();
	char n=menu();
	switch(n)
	{
		
		case '1':
			sign_up();
			break;
		case '2':
			log_in();
			
			break;
		case '3':
			dlt();
			break;
		case '4':
			edit();
			break;
		case '5':
			space();space();
			printf("Thank You For Using This Bank!");
			exit(0);
			break;
		case '9':
			print();
			break;
		default:
			break;
	}
	}

	return 0;
	
}

void hd()
{
	printf("\n");printf("\n");
	space();space2();
	for(int i=0;i<10;i++)
	printf("*");
	printf("*    Welcome To Our Bank!    *");
	for(int i=0;i<10;i++)
	printf("*");
	printf("\n\n\n\n\n\n\n");
}

void print()
{
	
		bank *tmp=head;;
		int i=1;
		
//space();
	printf(" ------------------------------------------------------------------------------------------------------------\n");
		//space();
			printf("|");
			printf("    Serial NO.    |    Account No.    |    Name     |      User Name      |    Password    |    Balance    |");
			printf("\n");
		while(tmp!=NULL)
		{
	//	space();
			printf("|");
			printf("                  |                   |             |                     |                |               |");
			printf("\n");	
	//	space();
			printf("|");
		 	printf("        %d                %d             %s          %s             %s            %d       ",i,tmp->acc_no,tmp->name,tmp->username,tmp->password,tmp->acc_balance);
			printf("\n");
		i++;
		    tmp=tmp->next;}
//	space();
			printf("|");
			printf("                  |                   |             |                     |                |               |");
			printf("\n");
	//	space();
	printf(" ------------------------------------------------------------------------------------------------------------\n");
}

void print_user(bank *tmp)
{
	
		
		int i=1;
		
//space();
	printf(" ------------------------------------------------------------------------------------------------------------\n");
		//space();
			printf("|");
			printf("    Serial NO.    |    Account No.    |    Name     |      User Name      |    Password    |    Balance    |");
			printf("\n");
		
	//	space();
			printf("|");
			printf("                  |                   |             |                     |                |               |");
			printf("\n");	
	//	space();
			printf("|");
		 	printf("        %d                %d             %s          %s             %s            %d       ",i,tmp->acc_no,tmp->name,tmp->username,tmp->password,tmp->acc_balance);
			printf("\n");
		
//	space();
			printf("|");
			printf("                  |                   |             |                     |                |               |");
			printf("\n");
	//	space();
	printf(" ------------------------------------------------------------------------------------------------------------\n");
}


void crt(char n[100],char u[100],char p[50],int b)
{
	bank *newnode=(bank*)malloc(sizeof(bank));
	newnode->acc_balance=b;
	strcpy(newnode->name,n);
	strcpy(newnode->username,u);
	strcpy(newnode->password,p);

	acno++;
	newnode->acc_no=acno;
	newnode->next=NULL;
	
	if(head==NULL)
	head=newnode;
	else
	{
		bank *tmp=head;
		
		while(tmp->next!=NULL)
		tmp=tmp->next;
		tmp->next=newnode;
	}
	space();space();
	printf("Your Account no. is :- %d",newnode->acc_no);
	cashmemo(1,newnode->acc_no,0,newnode->acc_balance,newnode->acc_balance+0);

	//print();
	fflush(stdin);
}

int cash(int n,bank *t)
{
	bank *tmp;
	int c;
	
		switch(n)
		{
			case 1:
			{ 
			space();space();
				printf("Enter the ammount to deposit! ");
				scanf("%d",&c);printf("\n");
					cashmemo(1,t->acc_no,t->acc_balance,c,t->acc_balance+c);
				t->acc_balance=t->acc_balance+c;
							space();space();

				printf("%d Successfully added to your account! \n\n ",c);
							space();space();
				update();
			

				printf("current balance : %d\n",t->acc_balance);
				break;
					
			}	
			case 2:
				{
			space();space();

				printf("Enter the ammount to Withdrawl! ");
				scanf("%d",&c);
				if(c<t->acc_balance)
				{
					cashmemo(2,t->acc_no,t->acc_balance,c,t->acc_balance-c);
				t->acc_balance=t->acc_balance-c;
			space();space();
				printf(" %d Successfully deducted from your account! \n\n",c);
							space();space();
				printf("current balance : %d\n",t->acc_balance);}

				else
				{
			space();space();
				printf("Their is not sufficient Money! \n\n");
											space();space();

								printf("current balance : %d\n",t->acc_balance);}
				update();
				break;
				}
			case 3:
				{
					int a,l=0;
					bank *tmp=head;
			space();space2();
					printf("Enter the acc_no to send the money!");
					scanf("%d",&a);
			space();space();
					printf("Enter the ammount to send! ");
				    scanf("%d",&c);
				    if(c<t->acc_balance)
				    {
					while(tmp!=NULL)
					{
						if(tmp->acc_no==a)
						
					{l=1;
					break;}
					else
					tmp=tmp->next;
					}
				if(l==1)
				{ 
					cashmemo(3,t->acc_no,t->acc_balance,c,t->acc_balance-c);
					cashmemo(1,tmp->acc_no,tmp->acc_balance,c,tmp->acc_balance+c);

				t->acc_balance=t->acc_balance-c;
				tmp->acc_balance=tmp->acc_balance+c;
		space();space2();

				printf("%d Successfully added to your given account! \n \n ",c);
						space();space();

				printf("current balance : %d\n",t->acc_balance);}

				else
				{
	space();space();
				printf("Account dose not exist!  \n");
					space();space();
				 printf("Please Enter valid Details!\n");
				 	space();space();
				printf("current balance : %d\n",t->acc_balance);}}

					else
					{
	space();space();
				printf("Their is not sufficient Money! \n\n");
									space();space();

								printf("current balance : %d\n",t->acc_balance);}
				update();
			
				break;
				}
			case 4:
				print_user(t);
				break;
			case 5:
				cashmemo(4,t->acc_no,0,0,0);
				break;
			case 6:
				main();
					break;
			default:
					printf("Enter Valid Choice!");
		}
		
}

void cashmemo(int i,int ac, int p,int a,int n)
{
    	time(&tt);
    	char t[50];
    	int u;
		if(i==1)
		{
		strcpy(t,ctime(&tt));
		u=strlen(t);
		if(t[u-1]=='\n')
		t[u-1]='\0';
		FILE *fp1=fopen("cashmemo.txt","a+");
		fprintf(fp1,"%d %s %d %d %d\n",ac,t,p,a,n);
		fclose(fp1);
		}
			if(i==2)
		{
		strcpy(t,ctime(&tt));
		u=strlen(t);
		if(t[u-1]=='\n')
		t[u-1]='\0';
			FILE *fp1=fopen("cashmemo.txt","a+");
		fprintf(fp1,"%d %s %d %d %d\n",ac,t,p,a,n);
		fclose(fp1);

		}
			if(i==3)
		{
		strcpy(t,ctime(&tt));
		u=strlen(t);
		if(t[u-1]=='\n')
		t[u-1]='\0';
		FILE *fp1=fopen("cashmemo.txt","a+");
		fprintf(fp1,"%d %s %d %d %d\n",ac,t,p,a,n);
		
		fclose(fp1);
		}
			if(i==4)
		{
			
			FILE *fp=fopen("cashmemo.txt","rt");
		int e=0,l=0;
		int q=ac;
			char k;
	for(k=getc(fp);k!=EOF;k=getc(fp))
	{
		if(k == '\n')
		{
		e++;
		}
		
	}
		fclose(fp);
		//printf("\n e=%d",e);
		FILE *fp1=fopen("cashmemo.txt","rt");
	for(i=0;i<e;i++)
		{
	
		fscanf(fp1,"%d",&ac);
		fgets(t,buffer,fp1);
		fscanf(fp1,"%d%d%d",&p,&a,&n);

		if(ac==q)
		{
		l++;
		}
		
		}
		
		fclose(fp1);
		//		printf("\n l=%d",l);

		space();
		printf("----------------------------------------------------------------------------------------\n");
		space();
			printf("|"); 
			printf("  AccNo. |          Date & Time          | Old Ammount | Given Ammount | Final Ammount |");
			printf("\n");


		fp1=fopen("cashmemo.txt","rt");
	for(i=0;i<e;i++)
		{
	
		fscanf(fp1,"%d",&ac);
		fgets(t,buffer,fp1);
		fscanf(fp1,"%d%d%d",&p,&a,&n);
		if(ac==q)
		{
	space();
			printf("|                                                                                       |\n");
	space();
	
		
		if(n>p)
		printf("| %d  :-  %s  :    %d      +     %d     =     %d     \n",ac,t,p,a,n);
		else
		printf("| %d  :-  %s  :    %d     -     %d       =     %d    \n",ac,t,p,a,n);
		l--;
		}
		if(l==0)
		break;
		
		}
		fclose(fp1);
	space();
		printf("----------------------------------------------------------------------------------------\n");
	}
}	


int usr_lg(bank *t)
{
	hd();
	space();space();
	printf("       Welcome %s\n\n\n\n",t->name);

	
space();space2();
	printf(" -----------------------------------------------\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("                1.Cash Deposite!                ");
	printf("|\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("                2.Cash Withdrawl!               ");
	printf("|\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("                3. Fund Transfer!               ");
	printf("|\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
		printf("             4.Account Information!             ");
	printf("|\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("               5.Transaction Info               ");
	printf("|\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
		printf("                   6.Log Out!                  ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");

space();space2();	printf(" -----------------------------------------------\n");
int n;
	
	printf("\n");printf("\n");
	space();space2();
	printf("        Enter Your Choice Please!:  ");
	scanf("%d",&n);
	printf("\n");
	cash(n,t);


}

char menu()
{
	char n;
space();space2();
	printf(" -----------------------------------------------\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("            1. Add a new Account!              ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("                 2. Log In!                    ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("       3. Delete Your Existing Account!        ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
		printf("      4. Edit Your Username Or Password!       ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");
space();space2();
	printf("|");
	printf("              5. Exit Programe!                ");
	printf(" |\n");
space();space2();
	printf("|");
	printf("                                                |\n");

space();space2();	printf(" -----------------------------------------------\n");
	printf("\n");printf("\n");
space();space2();
	printf("           Enter Your Choice Please!:  ");
	scanf("%c",&n);
	printf("\n");
	return n;
}


void sign_up()
{
				hd();
				int balance;
				char unm[100],name[100],pass[50];
space();
	printf(" ----------------------------------------------------------------------\n");
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");
	printf("                  Enter Your Name : ");
		scanf("%s", name);
			fflush(stdin);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");
	printf("            Enter a User Name for your Account : ");
		scanf("%s", unm);
			fflush(stdin);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");
	printf("                     Enter A Password : ");
		scanf("%s", pass);	
		fflush(stdin);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");
	printf("            Enter A Opening Balance For Your Account : ");
		scanf("%d",&balance);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf(" ----------------------------------------------------------------------\n");
	crt(name,unm,pass,balance);
}

void edit()
{
	char k[100],o[100],h[100];
	int a,p,z=0;
	space();space2();
	bank *tmp=head;
	printf("Do You Want To change Your User ID? (0/1)");
	scanf("%d",&p);
	if(p==1)
	{
	space();space2();
		printf("Enter Your Account No. ");
		scanf("%d",&a);
	space();space2();
		printf("Enter Your Password to Confirm! ");
		scanf("%s", o);
		while(tmp!=NULL)
	{
		if(tmp->acc_no==a)
		{
			if(strcmp(tmp->password,o)==0)
			{
			space();space2();
			printf("Enter New User ID: ");
			scanf("%s", h);
			strcpy(tmp->username,h);
			z=1;
			break;
			}
			else
			
			space();space();
				printf("Wrong Password!");
				z=2;
				break;
		}
		
		else
		{
				tmp=tmp->next;
				
				
		}
	}
	
	if(z==0)
	{space();space();
	printf("Account Dose Not Exist!");}
	}
	
	else if(p==0)
	{
		int b;
space2();
		printf("To change Your password we Need Your UserID , account no., Name , Current Balance\n");
space();space2();
		printf(" Enter Your Accno.: ");
		scanf("%d",&a);
space();space2();
		printf(" Enter Your User ID: ");
		scanf("%s", o);
space();space2();
		printf(" Enter Your Name: ");
		scanf("%s", k);
space();space2();
		printf(" Enter Current Balance: ");
		scanf("%d",&b);
	while(tmp!=NULL)
	{
		if(tmp->acc_no==a)
		{
			if(strcmp(tmp->username,o)==0 && strcmp(tmp->name,k)==0 && tmp->acc_balance==b)
			{
		space();space2();
			printf("Enter New Password: ");
			scanf("%s", h);
			strcpy(tmp->password,h);
			z=1;
			break;
			}
			else
			{
			space();space();
				printf("Wrong Details Given!");
				z=2;
				break;
			}
		}
		else
		{
				tmp=tmp->next;
				
				
		}
	}
		if(z==0)
		{
			space();space();
	printf("Account Dose Not Exist!");}	

	}
}


int log_in()
{
	char unm[100],pass[50];
	space();
	printf(" ----------------------------------------------------------------------\n");
space();
	printf("|");
	printf("                                                                       |\n");

space();
	printf("");
	printf("                  Enter Your User Name : ");
		scanf("%s", unm);
			fflush(stdin);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");
	printf("                   Enter Your Password : ");
		scanf("%s", pass);	
		fflush(stdin);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf(" ----------------------------------------------------------------------\n");

	bank *tmp;
	tmp=head;
	int i=0,n=1,k=0;
	char q;
	while(tmp!=NULL)
	{
		if(strcmp(tmp->username,unm)==0)
		{
			if(strcmp(tmp->password,pass)==0)
			{
			usr_lg(tmp);
			k=1;
			}
			else
			{
				space();space();
				printf("Wrong username / Password!\n");
				space();space2();
				printf("Do You Want To change Your id/pass ? (Y/N)");
				scanf("%c",&q);
					k=3;
				if(q=='Y' || q== 'y')
				{
				edit();
				break;}
				else
				return 0;
			
			}
		}
		else
		{
				tmp=tmp->next;
				
				
		}
	}
	if(k==0)
	{
	space();space2();
		printf("There is no account linked to the given Details! \n");
	space();space2();
		printf("   Do You Want to create an Account? (Y/N)");
				scanf("%c",&q);
				if(q=='Y' || q=='y')
				{
				sign_up();
				return 0;
				}
				else
				return 0;
	
				
	}
}


void dlt()
{
	int a;
	char p[50];
space();
	printf(" ----------------------------------------------------------------------\n");
	space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf("");space2();
	printf("      Enter Your Account no.!");
	scanf("%d",&a);
space();
	printf("|");
	printf("                                                                       |\n");
	space();
	printf("");space2();
	printf("      Enter your password to confirm! ");
	scanf("%s", p);
space();
	printf("|");
	printf("                                                                       |\n");
space();
	printf(" ----------------------------------------------------------------------\n");
	bank *tmp=head;
	bank *t=head;
	int y=0;
	
	while(tmp!=NULL)
	{
		if(tmp->acc_no==a)
		{
		
			if(strcmp(tmp->password,p)==0)
			{
				if(tmp==head)
				{
					head=tmp->next;
					tmp->next=NULL;
					free(tmp);y=1;space();space();
					printf("Account Deleted Successfully!\n");
			//		print();
				}
				else{
				t->next=tmp->next;
				tmp->next=NULL;
				free(tmp);y=1;space();space();
				printf("Account Deleted Successfully!\n");
			//	print();
				break;
			}}
			else
			{
			space();space();	printf("Incorrect Password!\n");
			y=2;
			break;}
		}
		else
		{
		
			t=tmp;
			tmp=tmp->next;
		}
	}
	if(y==0)
	{
		space();space();
	printf("Account Dose Not Exist!\n");}
}
	



