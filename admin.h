
void addUser() {
    fileToLinkedListConversion();
    char username[50], password[50];

  
    printf("Enter the username: ");
    scanf("%99s", username);
    if(checkingOfUsername(username)){
    	printf("\n\n!!!!!!!!!!User name already exist!!!!!!!!\n\n");
    	addUser();
	}else{
    printf("Enter the password: ");
    scanf("%49s", password);
    appendUser(username,password);
    LinkedListToFileConversion();
    printf("\nUser added successfully\n");
}
}

void deleteUser() {
    fileToLinkedListConversion();
    char username[50];
    
    printf("Enter the username to delete: ");
    scanf("%49s", username);

    struct User* current = head;
    struct User* prev = NULL;

    while (current != NULL && strcmp(current->username, username) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
         LinkedListToFileConversion();
        printf("\nUSer deleted successfully\n");
    } else {
        printf("\nUser not found\n");
    }
}
 void changePasswordAsAdmin(){
 	char username[50], password[50];
 	fileToLinkedListConversion();
 	struct User* current=head;
 	printf("\nEnter the username for resetting the password\n");
 	scanf("%s",&username);
 	if (current == NULL) {
        printf("\nNO USER EXISTS!!!!!\n");
    } else {
        while (current != NULL&& strcmp(current->username, username) != 0) {
            current = current->next;
        }
        printf("\nEnter the new password\n");
        scanf("%s",&password);
        strcpy(current->password,password);
    }
    LinkedListToFileConversion();
 	
 }

void displayUserList() {
    fileToLinkedListConversion();
    struct User* current = head;
    if (current == NULL) {
        printf("\nNO USER EXISTS!!!!!\n");
    } else {
        printf("\nUsers\tPasswords\n");
        while (current != NULL) {
            printf("%s\t%s\n", current->username, current->password);
            current = current->next;
        }
    }
}



void addBook() {
    fileToBookLinkedListConversion();
    char title[100], author[50];
    int quantity;
    int availaibleQuantity;

    printf("Enter the title: ");
    scanf("%99s", title);

    printf("Enter the author: ");
    scanf("%49s", author);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    
    availaibleQuantity=quantity;
    appendBook(title, author, quantity,availaibleQuantity);
    bookLinkedListToFileConversion();

    printf("\nBook added successfully\n");
}

void removeBook() {
    fileToBookLinkedListConversion();
    char title[100];

    printf("Enter the title to delete: ");
    scanf("%99s", title);

    struct Book* current = bookHead;
    struct Book* prev = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            bookHead = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
        bookLinkedListToFileConversion();
        printf("\nBook deleted successfully\n");
    } else {
        printf("\nBook not found\n");
    }
}

void displayBookList() {
    fileToBookLinkedListConversion();
    struct Book* newBook = bookHead;
    if (newBook == NULL) {
        printf("\nNO BOOKS EXIST!!!!!\n");
    } else {
        printf("\nTitle\tAuthor\tQuantity\tAvailable Quantity\n");
        while (newBook != NULL) {
            printf("%s\t\t%s\t\t%d\t\t%d\n", newBook->title, newBook->author, newBook->quantity, newBook->availableQuantity);
            newBook = newBook->next;
        }
    }
}

void issuedData() {
    fileToDetailsLinkedList();
    struct details* temp = detailHead;
    
    if (temp == NULL) {
        printf("\n\n!!!!!!!!!No data exists\n");
    } else {
        printf("\nUsername\tBookname\tAuthorname\n");
        while (temp != NULL) {
            printf("%s\t\t%s\t\t%s\n", temp->username, temp->bookname, temp->authorname);
            temp = temp->next;
        }
    }
}


void adminMenu() {
    while (1) {
        int choice;
        header();
        printf("Welcome Admin\n");
        printf("1. Add Users\n");
        printf("2. Remove Users\n");
        printf("3. ChangePasswords\n");
        printf("4. Display Users\n");
        printf("5. Add Book\n");
        printf("6. Remove Book\n");
        printf("7. Display Books\n");
        printf("8. Issued DATA\n");
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
			    changePasswordAsAdmin();
			    break;
            case 4:
                displayUserList();
                break;
            case 5:
                addBook();
                break;
            case 6:
                removeBook();
                break;
            case 7:
                displayBookList();
                break;
            case 8:
			     issuedData();    
			     break;
            case 9:
                return;
            default:
                printf("Wrong key pressed!\n");
        }
    }
}





















