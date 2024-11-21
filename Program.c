#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* left;
    struct Book* right;
} Book;

Book* createBook(int id, char* title, char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}

Book* insertBook(Book* root, int id, char* title, char* author) {
    if (root == NULL) {
        return createBook(id, title, author);
    }
    if (id < root->id) {
        root->left = insertBook(root->left, id, title, author);
    } else if (id > root->id) {
        root->right = insertBook(root->right, id, title, author);
    }
    return root;
}

Book* searchBookByID(Book* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return searchBookByID(root->left, id);
    } else {
        return searchBookByID(root->right, id);
    }
}

Book* searchBookByTitle(Book* root, char* title) {
    if (root != NULL) {
        if (strcmp(root->title, title) == 0) {
            return root;
        }
        Book* foundBook = searchBookByTitle(root->left, title);
        if (foundBook == NULL) {
            foundBook = searchBookByTitle(root->right, title);
        }
        return foundBook;
    }
    return NULL;
}

Book* searchBookByAuthor(Book* root, char* author) {
    if (root != NULL) {
        if (strcmp(root->author, author) == 0) {
            return root;
        }
        Book* foundBook = searchBookByAuthor(root->left, author);
        if (foundBook == NULL) {
            foundBook = searchBookByAuthor(root->right, author);
        }
        return foundBook;
    }
    return NULL;
}

Book* deleteBook(Book* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->id) {
        root->left = deleteBook(root->left, id);
    } else if (id > root->id) {
        root->right = deleteBook(root->right, id);
    } else {
        if (root->left == NULL) {
            Book* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Book* temp = root->left;
            free(root);
            return temp;
        }
        Book* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->id = temp->id;
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->right = deleteBook(root->right, temp->id);
    }
    return root;
}

void updateBook(Book* root, int id, char* newTitle, char* newAuthor) {
    Book* book = searchBookByID(root, id);
    if (book != NULL) {
        strcpy(book->title, newTitle);
        strcpy(book->author, newAuthor);
    } else {
        printf("Book with ID %d not found.\n", id);
    }
}

void inorderTraversal(Book* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("ID: %d, Title: %s, Author: %s\n", root->id, root->title, root->author);
        inorderTraversal(root->right);
    }
}

void freeTree(Book* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Book* library = NULL;
    int choice, id;
    char title[100], author[100];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book by ID\n");
        printf("3. Search Book by Title\n");
        printf("4. Search Book by Author\n");
        printf("5. Delete Book\n");
        printf("6. Update Book\n");
        printf("7. Display All Books\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                getchar(); // To consume the newline character left by scanf
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline character
                printf("Enter book author: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                library = insertBook(library, id, title, author);
                printf("Book added successfully!\n");
                break;
            case 2:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                Book* foundBookByID = searchBookByID(library, id);
                if (foundBookByID != NULL) {
                    printf("Book found: ID: %d, Title: %s, Author: %s\n", foundBookByID->id, foundBookByID->title, foundBookByID->author);
                } else {
                    printf("Book with ID %d not found.\n", id);
                }
                break;
            case 3:
                printf("Enter book title to search: ");
                getchar();
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                Book* foundBookByTitle = searchBookByTitle(library, title);
                if (foundBookByTitle != NULL) {
                    printf("Book found: ID: %d, Title: %s, Author: %s\n", foundBookByTitle->id, foundBookByTitle->title, foundBookByTitle->author);
                } else {
                    printf("Book with title '%s' not found.\n", title);
                }
                break;
            case 4:
                printf("Enter book author to search: ");
                getchar();
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                Book* foundBookByAuthor = searchBookByAuthor(library, author);
                if (foundBookByAuthor != NULL) {
                    printf("Book found: ID: %d, Title: %s, Author: %s\n", foundBookByAuthor->id, foundBookByAuthor->title, foundBookByAuthor->author);
                } else {
                    printf("Book by author '%s' not found.\n", author);
                }
                break;
            case 5:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                library = deleteBook(library, id);
                printf("Book deleted successfully!\n");
                break;
            case 6:
                printf("Enter book ID to update: ");
                scanf("%d", &id);
                printf("Enter new book title: ");
                getchar();
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter new book author: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                updateBook(library, id, title, author);
                printf("Book updated successfully!\n");
                break;
            case 7:
                printf("Library Inventory:\n");
                inorderTraversal(library);
                break;
            case 8:
                freeTree(library);
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
