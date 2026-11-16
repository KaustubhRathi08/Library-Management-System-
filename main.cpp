
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool issued;

    Book() {
        issued = false;
    }

    void addBook() {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
        cout << "\nBook added successfully!\n";
    }

    void displayBook() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: "
             << (issued ? "Issued" : "Available");
        cout << "\n-------------------------";
    }
};

class Library {
private:
    Book books[100];
    int count = 0;

public:
    void addBook() {
        if (count >= 100) {
            cout << "\nLibrary is full!\n";
            return;
        }

        books[count].addBook();
        count++;
    }

    void displayBooks() {
        if (count == 0) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n--- BOOK LIST ---\n";
        for (int i = 0; i < count; i++) {
            books[i].displayBook();
        }
        cout << endl;
    }

    void searchBook() {
        string key;
        bool found = false;

        cin.ignore();
        cout << "\nEnter title or author to search: ";
        getline(cin, key);

        for (int i = 0; i < count; i++) {
            if (books[i].title.find(key) != string::npos ||
                books[i].author.find(key) != string::npos) {
                books[i].displayBook();
                found = true;
            }
        }

        if (!found)
            cout << "\nBook not found!\n";
    }

    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (!books[i].issued) {
                    books[i].issued = true;
                    cout << "\nBook issued successfully!\n";
                } else {
                    cout << "\nBook is already issued!\n";
                }
                return;
            }
        }

        cout << "\nBook ID not found!\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (books[i].issued) {
                    books[i].issued = false;
                    cout << "\nBook returned successfully!\n";
                } else {
                    cout << "\nBook was not issued!\n";
                }
                return;
            }
        }

        cout << "\nBook ID not found!\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                cout << "\nThank you for using the Library System!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
