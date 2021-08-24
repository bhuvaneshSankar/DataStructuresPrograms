#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define BOOKSLENGTH 8
struct book{
    int id;
    char name[100];
    int copies;
};
struct book bookLibrary[BOOKSLENGTH];

/*
  converts a string to an integer value
*/
int getInt(char str[], int len){
    int num=0;
    for(int i=0; i<len; i++){
        char ch = str[i];
        num = (num*10) + (ch-'0');
    }
    return num;
}
/*
  parses and stores the given bookdata in the structure array
*/
void storeBookInStruct(char data[], int bookNum){
    int i=0, k=0, start=0, end=0, j=0;
    struct book b;
    while(data[i]!='\0'){
        char value[100];
        j=0;
        while(data[i+1]!='\0'){
            if(data[i]==' ' && data[i+1]==' '){
                break;
            }
            value[j++]=data[i++];
        }
        if(data[i]==' ' && data[i+1]==' '){
            if(k==0){
                //id
                b.id = getInt(value, j);
            }
            else if(k==1){
                //name
                value[j]='\0';
                strcpy(b.name, value);
            }
            k++;
            i = i+2;
        }
        else if(data[i+1]=='\0'){
            //copies
            b.copies = getInt(value, j);
            i++;
        }
    }
    bookLibrary[bookNum] = b;
}
/*
  gets the details of all the books from the file
*/
void getBooks(){
    FILE *filePointer = fopen("books_database.txt", "r");
    if(filePointer == NULL){
        printf("Cannot open the file.");
        return;
    }
    char data[100];
    int bookNum=0;
    while(fgets(data, 100, filePointer)!=NULL){
        storeBookInStruct(data, bookNum);
        bookNum++;
    }
    fclose(filePointer);
}
/*
  prints the details of the books from the structure array
*/
void viewBooks(){
    for(int i=0; i<BOOKSLENGTH; i++){
        printf("\n%d %s %d", bookLibrary[i].id, bookLibrary[i].name, bookLibrary[i].copies);
    }
}
/*
  method to request book given the id of the book
*/
void requestBook(int id){
    if(id==0 || id>20){
        printf("\nBook is id not correct.  Please try again");
        return;
    }
    int numberOfCopies = bookLibrary[id-1].copies;
    if(numberOfCopies==0){
        printf("\nThis book is presently not on our shelf.  Please try later.");
        return;
    }
    bookLibrary[id-1].copies = numberOfCopies-1;
    printf("\nCongratulations customer your book is allocated.  Please collect it from the shelf.");
    
}
/*
  method to return book given the id of the book
*/
void returnBook(int id){
    if(id==0 || id>20){
        printf("\nBook is id not correct.  Please try again");
        return;
    }
    int numberOfCopies = bookLibrary[id-1].copies;
    bookLibrary[id-1].copies = numberOfCopies+1;
    printf("\nThank you customer.  Please place the book back on the shelf.");   
}
/*
  converts an integer to string
*/
char* convertIntegerToString(int value){
    if(value == 0){
     char* str = "0";
     return str;   
    }
	static char str[32] = {0};
	int i = 30;
	for(; value && i ; --i, value /= 10){
		str[i] = "0123456789"[value % 10];
    }
	return &str[i+1];
}
/*
  commits the changes to the file when the user exits
*/
void commitChangesToDatabase(){
    FILE *filePointer = fopen("books_database.txt", "w");
    if(filePointer == NULL){
        printf("\nCannot open the file.");
        return;
    }
    for(int i=0; i<BOOKSLENGTH; i++){
        char book[200] = "";
        char* bookNo = convertIntegerToString(i+1);
        strcpy(book, bookNo);
        strcat(book, "  ");
        char* bookCopies = convertIntegerToString(bookLibrary[i].copies);
        strcat(book, bookLibrary[i].name);
        strcat(book, "  ");
        strcat(book, bookCopies);
        strcat(book, "\n");
        fputs(book, filePointer);
    }
    fclose(filePointer);
}
int main(){
    getBooks();
    int choice, id;
    do{
        printf("\n1. View list of books on shelve");
        printf("\n2. Request for a new book");
        printf("\n3. Return a book");
        printf("\n4. Exit");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                viewBooks();
                break;
            case 2:
                printf("\nEnter the book id\n");
                scanf("%d", &id);
                requestBook(id);
                break;
            case 3:
                printf("\nEnter the book id\n");
                scanf("%d", &id);
                returnBook(id);
                break;
            case 4: 
                commitChangesToDatabase();
                break;
            default:
                printf("\nEnter correct option...");
                break;
        }
    }while(choice!=4);
}
