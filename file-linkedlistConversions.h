struct User {
    char username[50];
    char password[50];
    struct User*next;
};
struct User* head ;



struct Book {
    char title[100];
    char author[50];
    int quantity;
    int availableQuantity; 
    struct Book* next;
};
struct Book* bookHead;




struct details {
    char username[50];
    char bookname[50];
    char authorname[50];
    struct details* next;
};
struct details* detailHead;



void appendUser(char username[], char password[]) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    if (!newUser) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;

    if (head == NULL) {
        head = newUser;
    } else {
        struct User* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newUser;
    }
}

void fileToLinkedListConversion() {
    FILE* file = fopen("user.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char username[50], password[50];

    // Check if the file is empty
    if (fscanf(file, "%49s %49s", username, password) != 2) {
        head = NULL;
    } else {
        fseek(file, 0, SEEK_SET); // Reset the file position to the beginning
        head = NULL;

        // Read data and populate the linked list
        while (fscanf(file, "%49s %49s", username, password) == 2) {
            appendUser(username, password);
        }
    }

    fclose(file);
}

void LinkedListToFileConversion() {
    FILE* file = fopen("user.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    struct User* current = head;

    while (current != NULL) {
        fprintf(file, "%s %s\n", current->username, current->password);
        current = current->next;
    }

    fclose(file);
}



void appendBook(char title[], char author[], int quantity,int availaibleQuantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (!newBook) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->availableQuantity = availaibleQuantity;  // Initialize availableQuantity to quantity
    newBook->next = NULL;

    if (bookHead == NULL) {
        bookHead = newBook;
    } else {
        struct Book* current = bookHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}

void fileToBookLinkedListConversion() {
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char title[100], author[50];
    int quantity;
    int availaibleQuantity;

    if (fscanf(file, "%99s %49s %d", title, author, &quantity,&availaibleQuantity) != 3) {
        bookHead = NULL;
    } else {
        fseek(file, 0, SEEK_SET);
        bookHead = NULL;
        while (fscanf(file, "%99s %49s %d %d", title, author, &quantity, &availaibleQuantity) == 4) {
        appendBook(title, author, quantity, availaibleQuantity);  
      }

    }

    fclose(file);
}

void bookLinkedListToFileConversion() {
    FILE* file = fopen("books.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    struct Book* current = bookHead;

    while (current != NULL) {
        fprintf(file, "%s %s %d %d\n", current->title, current->author, current->quantity, current->availableQuantity);
        current = current->next;
    }

    fclose(file);
}


void appendDetails(char username[], char bookname[], char authorname[]) {
    struct details* newDetail = (struct details*)malloc(sizeof(struct details));
    if (!newDetail) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newDetail->username, username);
    strcpy(newDetail->bookname, bookname);
    strcpy(newDetail->authorname, authorname);
    newDetail->next = NULL;

    if (detailHead == NULL) {
        detailHead = newDetail;
    } else {
        struct details* current = detailHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newDetail;
    }
}


void fileToDetailsLinkedList() {
    FILE* file = fopen("detail.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char username[50], bookname[50], authorname[50];

    if (fscanf(file, "%49s %49s %49s", username, bookname, authorname) != 3) {
        detailHead = NULL;
    } else {
        fseek(file, 0, SEEK_SET);
        detailHead = NULL;

        while (fscanf(file, "%49s %49s %49s", username, bookname, authorname) == 3) {
            appendDetails(username, bookname, authorname);
        }
    }

    fclose(file);
}


void detailsLinkedListToFile() {
    FILE* file = fopen("detail.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    struct details* current = detailHead;

    while (current != NULL) {
        fprintf(file, "%s %s %s\n", current->username, current->bookname, current->authorname);
        current = current->next;
    }

    fclose(file);
}

//check if username exists..
int checkingOfUsername(char username[50]){
	fileToLinkedListConversion();
	struct User*current =head;
	if(current==NULL){
	return 0;
	}else{
	while(current!=NULL){
		 if (strcmp(current->username, username) == 0 ) {
            return 1; 
        }
        current = current->next;
	}

}
return 0;
}



