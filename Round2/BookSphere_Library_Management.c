#include<stdio.h>
#include<string.h>

struct Library {
    char name[50];
    char auth[40];
    char genre[45];
    char i_date[20];
    char r_date[20];
    int status;    
};

struct Library library[40];
int count = 0, i;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char *arr, int size) {
    fgets(arr, size, stdin);
    arr[strcspn(arr, "\n")] = '\0';
}

void add() {
    clearBuffer();
    
    printf("Book Name: ");
    readString(library[count].name, sizeof(library[count].name));
    
    for(i = 0; i < count; i++) {
        if(strcmp(library[i].name, library[count].name) == 0) {
            printf("Book is Already in File\n");
            printf("Enter Again: ");
            readString(library[count].name, sizeof(library[count].name));
            break;
        }
    }  
    printf("Book Author: ");
    readString(library[count].auth, sizeof(library[count].auth));
        
    printf("Book Genre: ");
    readString(library[count].genre, sizeof(library[count].genre));
    
    printf("Choose Status of Book\n(1. Available 0. Not Available)\nSelect(1/0): ");
    scanf("%d", &library[count].status);
    
    printf("\nBook Added Successfully!\n");
    count++;
}

void display() {
    if(count != 0) {
        printf("\nIndex\t%-25s\t%-20s\t%-15s\tStatus\n", "Book Name", "Author", "Genre");
        for(i = 0; i < count; i++) {
            printf("%d \t%-25s\t%-20s\t%-15s\t%s\n", 
            (i + 1), library[i].name, library[i].auth, library[i].genre, 
            library[i].status == 1 ? "Available" : "Issued");
        }
    } else {
        printf("\nNo books in Library!!\n");
    }
}

void delete() {
    clearBuffer();
    int found = 0,j;
    char str[50];
    printf("Enter Book name to delete: ");
    readString(str, sizeof(str));
    
    if(count != 0) {
        for(i = 0; i < count; i++) {
            if(strcmp(str, library[i].name) == 0) {
                for(j = i; j < count - 1; j++) {
                    library[j] = library[j + 1];    
                }
                found = 1;
                count--;
                printf("\nDeleting Book...\n");
                break;
            }
        }
        if(found == 0) {
            printf("Book not Found!\n");
        }    
    } else {
        printf("No Records Available!\n");
    }
}

void issue() {
    clearBuffer();
    int found = 0;
    char str[50];
    
    printf("\nEnter Book Name to Issue: ");
    readString(str, sizeof(str));
    
    for(i = 0; i < count; i++) {
        if(strcmp(str, library[i].name) == 0) {
            if(library[i].status == 1) {
                library[i].status = 0;
                printf("\nBook Issued Successfully!\n");
            } else {
                printf("\nBook is already issued to someone else!\n");
            }
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Book Not Found in Library!\n");
    }
}

void return_book() {
    clearBuffer();
    int found = 0;
    char str[50];
    printf("Enter Name of Book to Return: ");
    readString(str, sizeof(str));
    
    for(i = 0; i < count; i++) {
        if(strcmp(str, library[i].name) == 0) {
            if(library[i].status == 0) {
                library[i].status = 1;
                printf("\nBook Returned Successfully!\n");
            } else {
                printf("\nBook is already marked as available!\n");
            }
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Book Not Found!\n");
    }
}

void availableBooks() {
    printf("\nAvailable Books are: \n");
    int any = 0;
    for(i = 0; i < count; i++) {
        if(library[i].status == 1) {
            printf("- %s\n", library[i].name);
            any = 1;
        }
    }
    if(!any) printf("None of the books are currently available.\n");
}

void fileSave() {
    FILE *fp = fopen("book_data.txt", "w");
    if(fp != NULL) {
        if(count != 0) {
            for(i = 0; i < count; i++) {
                fprintf(fp, "%d. %s, %s, %s, %d\n", 
                (i + 1), library[i].name, library[i].auth, library[i].genre, library[i].status);
            }
            printf("\nSaved to File Successfully!\n");
        } 
		else {
            printf("No books to save!\n");
        }
        fclose(fp);
    } 
	else {
        printf("File Not Opened!\n");
    }
}

int main() {
    int n;    
    printf("========== BookSphere- Library Management System ==========");
    
    while(1) {
        printf("\nSelect (1-8)\n1. Add Books\n2. View Books\n3. Delete Books\n4. Issue Book\n5. Return Book \n6. Status \n7. File Save \n8. Exit");
        printf("\n\nEnter Your Choice: ");
        
        if (scanf("%d", &n) != 1) {
            printf("Please enter a valid number.\n");
            clearBuffer();
            continue;
        }
        
        switch(n) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: delete(); break;
            case 4: issue(); break;
            case 5: return_book(); break;
            case 6: availableBooks(); break;
            case 7: fileSave(); break;
            case 8: 
                fileSave();
                printf("See ya Later! Good Day!\n");
                return 0;
            default:
                printf("Invalid Input! Enter Again..\n");
        }
    }    
}

