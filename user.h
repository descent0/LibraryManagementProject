

int displayAvailableBooks() {
 
    fileToBookLinkedListConversion();
    struct Book* current = bookHead;

    if (current == NULL) {
        printf("\nNO BOOKS EXIST!!!!!\n");
        return 0;
    } else {
        printf("\nTitle\tAuthor\tQuantity\tAvailable Quantity\n");
        while (current != NULL && current->availableQuantity > 0) {
            printf("%s\t%s\t%d\t%d\n", current->title, current->author, current->quantity, current->availableQuantity);
            current = current->next;
        }
        return 1;
    }
}

// Function to check if the user has issued books
void checkUserIssuedBooks() {
    fileToDetailsLinkedList();
    struct details* current = detailHead;
    found = 0;
    while (current != NULL) {
        if (strcmp(current->username, USERNAME) == 0) {
            found = 1;
            break;
        }
        current = current->next;
    }
}


void issueBook() {
    char bookname[50], authorname[50];
    checkUserIssuedBooks();

    if (found == 1) {
        printf("\n\n\n\t\tYou can only issue one book at a time");
    } else {
        printf("\n\n\t\t\t AVAILABLE BOOK LIST IS\n\n");
        if(displayAvailableBooks()){
        fileToDetailsLinkedList();
        printf("\n\nEnter the bookname you want to issue: ");
        scanf("%49s", bookname);
        printf("\nEnter the author name: ");
        scanf("%49s", authorname);
        appendDetails(USERNAME, bookname, authorname);
        detailsLinkedListToFile(); 
        fileToBookLinkedListConversion();
        struct Book* currentBook = bookHead;

        while (currentBook != NULL) {
            if (strcmp(currentBook->title, bookname) == 0) {
                currentBook->availableQuantity = currentBook->availableQuantity - 1;
                break;
            }
            currentBook = currentBook->next;
        }
        bookLinkedListToFileConversion(); 
        printf("/n Thankyou for borrowing...PLz return it within 7 days\n\n");
    }
}
}


void returnBook() {
    char bookname[50], authorname[50];
    checkUserIssuedBooks();

    if (found == 0) {
        printf("\n\n\n\t\tYou have not issued any book yet");
    } else {
        fileToDetailsLinkedList();
        printf("\n\nEnter the bookname you want to return: ");
        scanf("%49s", bookname);
        printf("\nEnter the author name: ");
        scanf("%49s", authorname);

        struct details* currentDetail = detailHead;
        struct details* prevDetail = NULL;

        while (currentDetail != NULL) {
            if (strcmp(currentDetail->username, USERNAME) == 0 &&
                strcmp(currentDetail->bookname, bookname) == 0 &&
                strcmp(currentDetail->authorname, authorname) == 0) {
                if (prevDetail == NULL) {
                    detailHead = currentDetail->next;
                } else {
                    prevDetail->next = currentDetail->next;
                }

                free(currentDetail);
                detailsLinkedListToFile(); 
                fileToBookLinkedListConversion();
                struct Book* currentBook = bookHead;

                while (currentBook != NULL) {
                    if (strcmp(currentBook->title, bookname) == 0) {
                        currentBook->availableQuantity = currentBook->availableQuantity + 1;
                        break;
                    }
                    currentBook = currentBook->next;
                }

              bookLinkedListToFileConversion(); 
                printf("\n\nBook returned successfully\n");
                return;
            }

            prevDetail = currentDetail;
            currentDetail = currentDetail->next;
        }

        printf("\n\nWrong Book credentials");
    }
}


//authentication details.....
int authentication(char username[50], char password[50]){
	struct User* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            return 1; // Authentication successful
        }
        current = current->next;
    }

    return 0;
}


//login
void userlogin(){
	char username[50], password[50];

    printf("Enter your username: ");
    scanf("%49s", username);
   if(checkingOfUsername(username)){
   	   printf("Enter your password: ");
    scanf("%49s", password);

    if (authentication(username, password)) {
        printf("Login successful!\n");
        	strcpy(USERNAME,username);
        userMenu();
    } else {
        printf("Login failed. Invalid username or password.\n");
    }

   }else{
   	printf("User doesnt exist\n\n");
   }

 
}

void changePasswordAsUser(){
	char password[50];
 	fileToLinkedListConversion();
 	struct User* current=head;
 
        while (current != NULL&&strcmp(current->username, USERNAME) != 0) {
            current = current->next;
        }
        printf("\nEnter the new password\n");
        scanf("%s",&password);
        strcpy(current->password,password);
       LinkedListToFileConversion();
    
}



void userMenu() {
    while (1) {
        int choice;
        header();
        printf("Welcome, %s!\n", USERNAME);
        printf("1. Issue Book\n");
        printf("2. Return Book\n");
        printf("3. displayAvailaibleBooks\n");
        printf("4. ChangeYourPassword\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                issueBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
			     displayAvailableBooks();
		        break;		    
            case 4:
                changePasswordAsUser();
                break;
            case 5: 
                return;
            default:
                printf("Wrong key pressed!\n");
        }
    }
}







