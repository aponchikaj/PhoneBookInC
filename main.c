#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// phone book in C By Lazare Mirziashvili
// Functions I'm gonna make: Add Contact, Delete Contact, Update Contact
// Get Contacts, Get Contact (by name) 

typedef char string;

typedef struct {
	string name[100]; // e.g Lazare , Giorgi....
	string phone[100]; // e.g 123 456 789....
	int index; // e.g 1,2,3,4....
	string countryCode[3]; // e.g +995 / +1 ....	
} contact;

#define MAX_CONTACTS 100
static contact CONTACTS[MAX_CONTACTS];
int CONTACTS_SIZE = 0;

int AddContact(string name[100],string phone[100],string countryCode[3]);
int DeleteContact(int index);
int UpdateContact(int index);
int GetContacts();
int GetContact(int index);

bool compareStrings(string str1[100], string str2[100]);
int StringLength(string str[100]);

int main(void){

	printf("\n\nWelcome to Phone Book made in C By Lazare Mirziashvili\n");
		
	while(true){
		printf("\n\nMENU:\n1. Add Contact\n2. Delete Contact\n3. Update Contact\n4. Get Contacts\n5. Get Contact\n6. Exit\n\n Choose: ");
		int option;
		
		scanf("%d",&option);
		
		if(option == 1){	
			string name[100];
			string phone[100];
			string countryCode[3];
			printf("\n\nEnter Contact's name: ");
			scanf(" %s",name);
			printf("\n\nEnter Contact's phone: ");
			scanf(" %s",phone);
			printf("\n\nEnter Contact's country code: ");
			scanf(" %s",countryCode);
			AddContact(name,phone,countryCode);
		}else if(option == 2){
			int index;
			printf("\n\nEnter user Index: ");
			scanf(" %d",&index);
			DeleteContact(index);
		}else if(option == 3){
			int index;
			printf("\n\nEnter user index: ");
			scanf(" %d",&index);
			UpdateContact(index);
		}else if(option == 4){
			GetContacts();
		}else if(option == 5){
			int index;
			printf("\n\nEnter user index: ");
			scanf(" %d",&index);
			GetContact(index);
		}else if(option == 6){
			printf("Goodbye !");
			return 0;
		}
	}

	return 0;
}

int StringLength(string str[100]){
	int length = 0;
	
	int i=0;
	while(str[i] != '\0'){
		i++;
		length++;
	}

	return length;
};

bool compareStrings(string str1[100], string str2[100]){
	int str1Length = StringLength(str1);
	int str2Length = StringLength(str2);

	if(str1Length < str2Length || str1Length > str2Length){
		return 1;
	}

	for(int i =0;i<str1Length;i++){
		if(str1[i] != str2[i]) return 1;
	}

	return 0;
}

int AddContact(string name[100],string phone[100],string countryCode[3]){
	for(int i =0;i<CONTACTS_SIZE;i++){
		if(!compareStrings(name, CONTACTS[i].name) && !compareStrings(phone, CONTACTS[i].phone)){
			printf("Contact with same number already exists !");
			return 1;
		}
	}
	
	strcpy(CONTACTS[CONTACTS_SIZE].name, name);
	strcpy(CONTACTS[CONTACTS_SIZE].phone, phone);
	strcpy(CONTACTS[CONTACTS_SIZE].countryCode, countryCode);
	CONTACTS[CONTACTS_SIZE].index = CONTACTS_SIZE;

	CONTACTS_SIZE++;

	printf("Added successfully !");
	return 0;
}

int DeleteContact(int index){
	for(int i =0;i<CONTACTS_SIZE;i++){
		if(CONTACTS[i].index == index){
			char savedName[100];
			strcpy(savedName, CONTACTS[i].name);
			CONTACTS[i].name[0] = '\0';
			CONTACTS[i].phone[0] = '\0';
			int savedIndex = CONTACTS[i].index;
			CONTACTS[i].index = -1;
			CONTACTS[i].countryCode[0] = '\0';
			CONTACTS_SIZE--;
			printf("%s with index %d has been deleted !",savedName,savedIndex);
			return 0;
		}
	}


	printf("User was not found !");
	return 1;
}

int UpdateContact(int index){
	for(int i =0;i<CONTACTS_SIZE;i++){
		if(CONTACTS[i].index == index){
			printf("Changing: \n1. Name\n2. Phone\n3. Country Code\n");
			int option;
			
			scanf("%d",&option);
			if(option == 1){
				string newName[100];
				printf("Enter new Name: ");
				scanf(" %s",newName);
				
				strcpy(newName, CONTACTS[i].name);
				printf("Success !");
				return 0;
			}else if(option == 2){
				string newPhone[100];
				printf("Enter new Phone: ");
				scanf(" %s",newPhone);
			
				strcpy(newPhone,CONTACTS[i].phone);
				printf("Success !");
				return 0;
			}else if(option == 3){
				string newCountryCode[3];
				printf("Enter new Country Code: (without including '+'): ");
				scanf(" %s",newCountryCode);
				printf("Success !");
				return 0;
			}else {printf("Invalid operation Try again later!");return 1;}
		}
	}

	printf("User not found !");
	return 1;
}

int GetContacts(){
	if(CONTACTS_SIZE == 0){
		printf("Woops... No contacts found !");
		return 0;
	}
	
	for(int i=0;i<CONTACTS_SIZE;i++){
		printf(" #%d | %s | %s | %s ",CONTACTS[i].index, CONTACTS[i].name,CONTACTS[i].countryCode,CONTACTS[i].phone);
	}

	return 0;
}
int GetContact(int index){
	if(CONTACTS_SIZE == 0){ printf("You don't have contacts");return 1;};

	for(int i =0;i<CONTACTS_SIZE;i++){
		if(CONTACTS[i].index == index){
			printf(" #%d | %s | %s | %s",CONTACTS[i].index,CONTACTS[i].name,CONTACTS[i].countryCode,CONTACTS[i].phone);
			return 0;
		}
	}

	printf("Index not found !");
	return 1;
}
