
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



struct details {
	char uname[50];
	int age;
	char password[100];
	char email[100];
	char mobile[10];
};


struct Shops {
	char shop[100];
	char item1[20];
	char item2[20];
	char item3[20];
	char item4[25];
	int first, second, third, fourth;
};


struct Shops m[5];
struct details s[100];

void signup();

void account_validate();
int validate();
void login();
void cart();
void shop();
void items();
void item_order(int item);

void shop_initialize();
void Shop(int shop_choice);


char t_name[100], t_password1[100];
char t_password2[100], t_email[100];
char t_mobile[100];
int flag = 1, i, j = 0, count = 0, caps = 0;
int Small = 0,total = 0 ,success = 0,special = 0, numbers = 0;
int x, choice,t_age, item_choice, n,shop_choice, search_choice, confirm,ch, item, shop_id;



int main()
{
	
	while (1) {

		
		printf("\n\n\t******************Welcome to Shop "
			"Cart*******************\n");
		printf("\n\n1)SIGNUP");
		printf("\n2)LOGIN");
		printf("\n3)EXIT");

		
		printf("\n\n\nEnter your choice : ");
		scanf("%d", &choice);


		
		switch (choice) {
		case 1: {
			
			signup();
			break;
		}
		case 2: {
			
			login();
			break;
		}
		case 3: {
			printf(
				"\n\t*************************Thank you "
				"Visit Again***********************\n\n");

			
			return 0;
		}
		default: {

			
			printf("\n\nPlease enter valid choice!!\n");
			break;
		}
		}
	}
}



void signup()
{

	printf("\n\n\t******************"
		"Welcome to Signup "
		"Page****************"
		"*\n\n");

	
	printf("\tEnter Your name : ");
	scanf("%s", t_name);

	printf("\tEnter Your Email : ");
	scanf("%s", t_email);

	
	printf("\tEnter Password : ");
	scanf("%s", t_password1);

	
	printf("\tConfirm Password : ");
	scanf("%s", t_password2);

	
	printf("\tEnter Your Mobile Number : ");
	scanf("%s", t_mobile);

	
	printf("\tEnter Your Age : ");
	scanf("%d", &t_age);

	x = validate();
	if (x == 1) {

		
		account_validate();

		
		login();
	}
}


int validate()
{
	
	for (i = 0; t_name[i] != '\0'; i++) {
		if (!((t_name[i] >= 'a' && t_name[i] <= 'z')
			|| (t_name[i] >= 'A' && t_name[i] <= 'Z'))) {
			printf("\nPlease enter the valid Name!\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;
		
		for (i = 0; t_email[i] != '\0'; i++) {
			if (t_email[i] == '@' || t_email[i] == '.')
				count++;
		}
		if (count >= 2 && strlen(t_email) >= 5) {
			
			if (!strcmp(t_password1, t_password2)) {
				if (strlen(t_password1) >= 8
					&& strlen(t_password1) <= 12) {
					caps = 0;
					Small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; t_password1[i] != '\0';
						i++) {
						if (t_password1[i] >= 'A'
							&& t_password1[i] <= 'Z')
							caps++;
						else if (t_password1[i] >= 'a'
								&& t_password1[i] <= 'z')
							Small++;
						else if (t_password1[i] >= '0'
								&& t_password1[i] <= '9')
							numbers++;
						else if (t_password1[i] == '@'
								|| t_password1[i] == '&'
								|| t_password1[i] == '#'
								|| t_password1[i] == '*')
							special++;
					}
					if (caps >= 1 && Small >= 1
						&& numbers >= 1 && special >= 1) {
						
						if (t_age != 0 && t_age > 0) {
							
							if (strlen(t_mobile) == 10) {
								for (i = 0; i < 10; i++) {
									if (t_mobile[i] >= '0'
										&& t_mobile[i]
											<= '9') {
										success = 1;
									}
									else {
										printf(
											"\n\nPlease");
										printf(
											"Enter Valid ");
										printf(
											"Mobile "
											"Number\n\n");
										return 0;
										break;
									}
								}

								
								if (success == 1)
									return 1;
							}
							else {
								printf("\n\nPlease Enter "
									"the 10 digit "
									"mobile number\n\n");
								return 0;
							}
						}
						else {
							printf("\n\nPlease Enter the "
								"valid age\n\n");
							return 0;
						}
					}
					else {
						printf(
							"\n\nPlease Enter the strong "
							"password, Your password must "
							"contain atleast one "
							"uppercase,Lowercase, Number "
							"and special character\n\n ");
						return 0;
					}
				}
				else {
					printf("\nYour Password is very "
						"short\nLength must between 8 "
						"to 12\n\n");
					return 0;
				}
			}
			else {
				printf("\nPassword Mismatch\n\n");
				return 0;
			}
		}
		else {
			printf("\nPlease Enter Valid E-Mail\n\n");
			return 0;
		}
	}
}


void account_validate()
{
	for (i = 0; i < 100; i++) {
		
		if (!(strcmp(t_email, s[i].email)
			&& strcmp(t_password1, s[i].password))) {
			printf("\n\nAccount Already Existed. Please "
				"Login !\n\n");
			login();
			break;
		}
	}

	
	if (i == 100) {
		strcpy(s[j].uname, t_name);
		s[j].age = t_age;
		strcpy(s[j].password, t_password1);
		strcpy(s[j].email, t_email);
		strcpy(s[j].mobile, t_mobile);
		j++;
		printf("\n\n\nAccount Successfully Created!\n\n");
	}
}


void login()
{
	printf("\n\n\t******************"
		"Welcome to Login "
		"Page********************"
		"****\n\n");
	printf("\n\nLOGIN\n\n");
	printf("\t Enter Your Email: ");

	
	scanf("%s", t_email);
	printf("\t Enter Your Password: ");

	
	scanf("%s", t_password1);

	for (i = 0; i < 100; i++) {
		
		if (!strcmp(s[i].email, t_email)) {
			
			if (!strcmp(s[i].password, t_password1)) {
				printf("\n\nWelcome %s, ", s[i].uname);
				printf(
					"Your are successfully logged in\n\n ");
				printf(
					"We Provide two ways of search : \n ");
				printf("1) Search By Shop\n ");
				printf("2) Search by item\n ");
				printf("3) Exit\n\n");
				printf("Please Enter your choice : ");
				scanf("%d", &search_choice);

				
				switch (search_choice) {
				case 1: {
					shop();
					break;
				}
				case 2: {
					items();
					break;
				}
				case 3: {
					
					main();
					break;
				}
				default: {
					
					printf("Please Enter the valid "
						"choice!!!\n\n");
					break;
				}
				}
				break;
			}
			else {
				
				printf("\n\nInvalid Password!!\n ");
				printf("Please Enter the correct "
					"password\n\n");
				login();
				break;
			}
		}
		else {
			
			printf("\n\nAccount doesn't exist, Please "
				"signup!!\n\n ");
			main();
			break;
		}
	}
}



void shop_initialize()
{
	
	strcpy(m[1].shop, "Puma");
	strcpy(m[1].item1, "puma sneaker V2");
	strcpy(m[1].item2, "mens dryflex");
	strcpy(m[1].item3, "one8x puma");
	m[1].first = 3499;
	m[1].second = 2999;
	m[1].third = 5999;

	strcpy(m[2].shop, "USA");
	strcpy(m[2].item1, "US polo Tshirt");
	strcpy(m[2].item2, "Shoes");
	strcpy(m[2].item3, "shirt");
	m[2].first = 999;
	m[2].second = 2000;
	m[2].third = 1499;

	strcpy(m[3].shop, "WROGN");
	strcpy(m[3].item1, "Mens Watch");
	strcpy(m[3].item2, "mens solid jacket");
	strcpy(m[3].item3, "casusal T-shirt");
	m[3].first = 2000;
	m[3].second = 2239;
	m[3].third = 799;
}


void shop()
{
	
	shop_initialize();

	
	printf("\n\nPlease Choose the Shop \n\n1) %s\n2) "
		"%s\n3) %s",
		m[1].shop, m[2].shop, m[3].shop);
	printf("\n4) Exit\n\nPlease ");
	printf("select the shop\t");

	
	scanf("%d", &shop_choice);
	if (shop_choice > 4) {
		printf("Please Enter the");
		printf("valid choice\n\n");
		shop();
	}
	else if (shop_choice == 4)
		main();
	else{
		
		Shop(shop_choice);
	}
}


void Shop(int shop_choice)
{
	
	total = 0;

	while (1) {

		printf("\n\nList of items available ");

		printf("in %s\n\n1) %s --> %d\n",
			m[shop_choice].shop, m[shop_choice].item1,
			m[shop_choice].first);

		printf("2) %s --> %d\n3) %s --> %d\n",
			m[shop_choice].item2, m[shop_choice].second,
			m[shop_choice].item3, m[shop_choice].third);

		printf("4) Cart\n5) Exit\n\nPlease Enter ");
		printf("Your Choice : ");
		scanf("%d", &item_choice);

		
		if (item_choice == 1) {
			printf("Please Enter the ");
			printf("Count of %s\t", m[shop_choice].item1);
			scanf("%d", &n);
			total = total + (n * m[shop_choice].first);
		}
		else if (item_choice == 2) {
			printf("Please Enter the Count");
			printf("of %s : ", m[shop_choice].item1);
			scanf("%d", &n);
			total = total + (n * m[shop_choice].second);
		}
		else if (item_choice == 3) {
			printf("Please Enter the Count");
			printf("of %s : ", m[shop_choice].item3);
			scanf("%d", &n);
			total = total + (n * m[shop_choice].third);
		}

		else if (item_choice == 4) {
			cart();
		}
		else if (item_choice == 5) {
			shop();
		}
		else {
			printf("Please Enter the");
			printf("valid Choice\n\n");
		}
	}
}

void items()
{
	total = 0;
	
	shop_initialize();
	while (1) {

		
		printf("\n\nPlease choose the ");
		printf("item\n\n1) %s /t--> %d\n2) %s/t --> %d",
			m[1].item1, m[1].first, m[1].item2,
			m[1].second);

		printf("\n3) %s/t --> %d\n4) %s/t --> %d\n",
			m[1].item3, m[1].third, m[2].item1,
			m[2].first);

		printf("5) %s/t --> %d\n6) %s/t --> %d\n",
			m[2].item2, m[2].second, m[2].item3,
			m[2].third);

		printf("7) %s/t --> %d\n8) %s/t --> %d\n",
			m[3].item1, m[3].first, m[3].item2,
			m[3].second);

		printf("9) %s/t --> %d\n10) Cart\n", m[3].item3,
			m[3].third);
		printf("11) Exit");
		printf("\nPlease Enter Your Choice : ");
		scanf("%d", &item);
		if (item > 10) {
			printf("Please Enter the ");
			printf("valid choice\n\n");
			items();
		}
		
		else if (item == 10)
			cart();
		else if (item == 11)
			
			return;
		
		else
			item_order(item);
	}
}


void item_order(int item)
{

	if (item >= 1 && item <= 3)
		shop_id = 1;
	else if (item >= 4 && item <= 6)
		shop_id = 2;
	else
		shop_id = 3;
	if ((item % 3) == 1) {
		
		printf("Please Enter the");
		printf(" Count of %s : ", m[shop_id].item1);
		scanf("%d", &n);
		total = total + (n * m[shop_id].first);
	}
	else if ((item % 3) == 2) {
		
		printf("Please Enter the ");
		printf("Count of %s\t", m[shop_id].item2);
		scanf("%d", &n);
		total = total + (n * m[shop_id].second);
	}
	else if ((item % 3) == 0) {
		
		printf("Please Enter the Count of %s\t",
			m[shop_id].item3);
		scanf("%d", &n);
		total = total + (n * m[shop_id].third);
	}
}


void cart()
{
	
	printf("\n\n\n\n\t*********************************"
		"Cart*********************************");
	printf("\n\nYour Total Order Amount is : %d\n", total);
	printf("\n\nDo You wish to order (y=1/n=0) : ");
	scanf("%d", &ch);
	if (ch == 1) {
		printf("\n\nThank You for your Order");
		printf("\nYour item is on the way. Welcome again "
			"\n\n ");

		main();
		return;
	}
	else if (ch == 0) {
		printf("To cancel Your Order = 1 \nTo Exit = 0 ");
		printf("Select option : ");
		scanf("%d", &confirm);
		if (confirm == 1) {
			
			printf("\n\nOops! Your item is cancelled!! "
				"Exiting..\n\n");
			printf("Thank You visit again!\n");
			main();
			return;
		}
		else {
						printf("\n\n\t\t************Thank ""You******************\n\n");
			login();
		}
	}
	else {
		
		printf("\n\nPlease Enter the correct choice\n\n ");
		cart();
	}
}
