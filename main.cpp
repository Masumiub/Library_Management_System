#include<iostream>
#include<list>
using namespace std;

struct book{
    string name;
    string author;
    string status;
    int popularity;

};

book b;
list<book> mylist;



void adding_new_book(){
    cout<< "Enter Book Name: ";
    cin>> b.name;
    cout<< "Enter Author Name: ";
    cin>> b.author;
    cout<< "Enter Status(available/borrowed): ";
    cin>> b.status;
    cout<< "Enter How many times this book was borrowed: ";
    cin>> b.popularity;
    mylist.push_back(b);
}
void display_all_books(){
    int i=1;

    for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
    cout<< i<< ".";
    cout<< "Book Name: ";
    cout<< it->name<<endl;
    cout<< "Author Name: ";
    cout<< it->author<< endl;
    cout<< "Status: ";
    cout<< it->status<< endl;

    i++;
    }
}

void display_available_books(){
    int i=1;
    cout<< "Displaying available books only:"<< endl;
    for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
    if(it->status == "available"){
        cout<< i<< ".";
        cout<< "Book Name: ";
        cout<< it->name<<endl;
        cout<< "Author Name: ";
        cout<< it->author<< endl;
        cout<< "Status: ";
        cout<< it->status<< endl;
        i++;
    }
    }
}

void check_availability(){
string str; int count=0;
cout<< "Enter a book name to check availability: ";
cin>> str;
for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
    if(it->name == str){
        count++;
        cout<< "Status: ";
        cout<< it->status<< endl;
        return;
    }else{
        count =0;
    }
    }
if(count==0){
    cout<< "Sorry. Book Not Found!"<< endl;
}

}

void change_status(){
string str;
int count=0;
cout<< "Enter a book name to change status: ";
cin>> str;
for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
    if(it->name == str){
            count++;
            string tmp="";
        cout<< "Change Status: ";
        cin>> tmp;
        it->status=tmp;
        return;
    }else{
        count =0;
    }

}
if(count==0){
cout<< "Book Not Found!"<< endl;
}
}

void find_most_popular_book(){
    int max_popular;
    b.popularity= max_popular;
    string book_name;
for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
    if(max_popular<it->popularity){
        max_popular=it->popularity;
        book_name=it->name;
    }
}
cout<< "Our Recommended Book(Most popular right now): "<< book_name<< endl;
}


void delete_a_book(){
    string str;
    cout<< "Enter a book name to Delete: ";
    cin>> str;
    for(list<book>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
        if(it->name==str){
            mylist.erase(it);
            break;
        }
    }

}



int main(){
    cout<< "Welcome to Library Management System!"<< endl;
    cout<< "Store Some Books in your Library First: "<< endl;
    cout<< "\nHow many books you want to store first?";
    int n;
    cin>> n;


    for(int i=1; i<=n; i++){
    cout<< "Enter Book Name: ";
    cin>> b.name;
    cout<< "Enter Author Name: ";
    cin>> b.author;
    cout<< "Enter Status(available/borrowed): ";
    cin>> b.status;
    cout<< "Enter How many times this book was borrowed: ";
    cin>> b.popularity;
    mylist.push_back(b);
    }


adding_new_book();
delete_a_book();
display_available_books();
display_all_books();
check_availability();
change_status();
find_most_popular_book();

return 0;
}

