#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
 
class product {
private:
    int    stock;            //items in stock
    int    added;            //added stock
    int    purchased;        //purchased items(reduces stock)
    string name;             //name of item
    float  price;            //price of item
    int    total_purchase;   //total number of purchsed quantity (as the same thing can be purchased many times)
    int    total_added;      //total number of added quantity (as the sam thing can be added many times)
 
public:
    //fuctions to input all private variables
    void setstock(int x) {
        stock = x;
    }
    void setname(string x) {
        name = x;
    }
    void setprice(float x) {
        price = x;
    }
 
    //functions to output all private variables
    int getstock() {
        return stock;
    }
    string getname() {
        return name;
    }
    float getprice() {
        return price;
    }
    int gettotal_purchase() {
        return total_purchase;
    }
    int gettotal_added() {
        return total_added;
    }
 
    //function that calculates total qyantity added per product
    void total_in(int x) {
        added = x;
        total_added += added;
    }
    //function that calculates total quantity purchased per product and inputs purchase
    void total_out( int x) {
        purchased = x;
        total_purchase += purchased;
    }
 
    //function that restocks the items
    void restock() {
        stock += added;
    }
 
    //function that deducts purchased items from stock
    void destock() {
        //if...else used in case the purchase demand exceeds items in stock
        if (stock >= purchased) {
            stock -= purchased;
        }
        else {
            cout << "\nSORRY! WE ONLY HAVE " << stock << " OF IT IN STOCK\n";
            purchased = 0;      //useful when calculating in reciept, 0 will not regester
        }
    }
    //resets variables so that all functions can be used again
    void reset_inout() {
        total_added = 0;
        total_purchase = 0;
        purchased = 0;
        added = 0;
 
    }
};
 
 
//function to buy stuff
void buy_stuff(product object[10]) {
    //declairing variables:
    char yesno;             //if the user wants to buy another product
    int choice;             //product number entered
    int purchased;          //number of products bought (for passing into input function)
    float total_price = 0;      //total price of products
 
        system("cls");
        cout << "**ATTENTION! ATTENTION!**\n";
        cout << "\nPASAL STORE PRESENTS: 'The More, The Less' offer!\n";
        cout << "Buy more items and get up to 20\% discount!\n";
        cout << "Purchase products worth more than 500, 1000, and 2000 and get 5, 10 and 20 percent discount respectively\n\n";
        system("pause");
        system("cls");
        cout << "\n\n\nWHAT WOULD YOU LIKE TO BUY?\n\n\n";
        cout << setw(15) << "Product No." << setw(40) << "Product Name" << setw(20) << "Price" << endl;
        for (int i = 0; i < 10; i++) {
            cout << setw(15) << i + 1 << setw(40) << object[i].getname() << setw(20) << object[i].getprice() << endl;       //displays menu in format: 1. Biscuit 40
        }
again:
        cout << "\n\n ENTER PRODUCT NUMBER OF THE ITEM YOU WANT TO BUY: ";
        cin >> choice;
        if (choice > 10 && choice < 1) {
            cout << "\n\nThere is no product with the number" << choice;
            goto again;
        }
        cout << "\n\nHOW MANY OF IT WOULD YOU LIKE TO BUY?: ";
        cin >> purchased;
        object[choice - 1].total_out(purchased);
        object[choice - 1].destock();
       
        cout << "\n\nPRESS ' Y ' TO BUY ANOTHER PRODUCT ";
        cin >> yesno;
        if (yesno == 'y' || yesno == 'Y') {
            goto again;
        }
    system("cls");
    cout << "\n\nYOU BOUGHT THE FOLLOWING ITEMS: \n\n";
    cout << setw(15) << "Product No." << setw(40) << "Product Name" << setw(20) << "Price Per Unit";
    cout << setw(15) << "Quantity" << setw(20) << "Total" << endl;
    for (int i = 0; i < 10; i++) {
        total_price += object[i].gettotal_purchase() * object[i].getprice();                //total price
        //only displays if stuff is purchased
        if (object[i].gettotal_purchase() > 0) {
            cout << setw(15) << i + 1 << setw(40) << object[i].getname() << setw(20) << object[i].getprice();                       //format: 1 biscuit 13 5 65
            cout << setw(15) << object[i].gettotal_purchase() << setw(20) << total_price << endl;
        }
    }
    cout << "\nTotal: " << setw(99) << "Rs. " << total_price << endl;
    //discounts offer above certain prices  
    if (total_price > 500) {
        cout << "'The more, The less' discount: " << setw(75) << "Rs. " << 0.05*total_price;
        total_price -= 0.05*total_price;
        cout << "Net Total: " << setw(95) << "Rs. " << total_price;
    }
    else if (total_price > 1000) {
        cout << "'The more, The less' discount: " << setw(75) << "Rs. " << 0.1*total_price;
        total_price -= 1 * total_price;
        cout << "Net Total: " << setw(95) << "Rs. " << total_price;
    }
    else if (total_price > 2000) {
        cout << "'The more, The less' discount: " << setw(75) << "Rs. " << 0.2*total_price;
        total_price -= 0.2*total_price;
        cout << "Net Total: " << setw(95) << "Rs. " << total_price;
    }
 
    cout << "\n\n\n******THANK YOU FOR VISITING!******\n\n";
    system("pause");
    system("cls");
}
 
 
//function to add products
void add_stuff(product object[10]) {
    //declairing variable
    char yesno;             //if the user wants to add another product
    int choice;             //product number entered
    int added;              //number of products added (for passing into input function)
add:
 
    do {
        system("cls");
        cout << "\n\n\nWHAT WOULD YOU LIKE TO ADD IN THE STOCK?\n\n\n";
        cout << setw(15) << "Product No." << setw(40) << "Product Name" << setw(20) << "Items in Stock" << endl;
        for (int i = 0; i < 10; i++) {
            cout << setw(15) << i + 1 << setw(40) << object[i].getname() << setw(20) << object[i].getstock() << endl;       //displays menu in format: 1. Biscuit 40
        }
        cout << "\n\n ENTER PRODUCT NUMBER OF THE ITEM YOU WANT TO ADD TO STOCK: ";
        cin >> choice;
        if (choice > 10) {
            cout << "\n\nThere is no product with the number" << choice;
            goto add;
        }
        cout << "\n\nHOW MANY OF IT WOULD YOU LIKE TO ADD?: ";
        cin >> added;
        object[choice - 1].total_in(added);
        object[choice - 1].restock();
 
        cout << "\n\nPRESS ' Y ' TO ADD ANOTHER PRODUCT ";
        cin >> yesno;
    } while (yesno == 'y' || yesno == 'Y');
    system("cls");
    cout << "\n\nYOU ADDED THE FOLLOWING ITEMS: \n\n";
    cout << setw(15) << "Product No." << setw(40) << "Product Name" << setw(25) << "No. of Product Added";
    cout << setw(15) << "New Stock" << endl;
    for (int i = 0; i < 10; i++) {
        if (object[i].gettotal_added() > 0) {
            cout << setw(15) << i + 1 << setw(40) << object[i].getname() << setw(20) << object[i].gettotal_added();                     //format: 1 biscuit 5 105
            cout << setw(15) << object[i].getstock() << endl;
        }
    }
    cout << "\n\n\n****************THANK YOU******************\n\n";
    system("pause");
    system("cls");
}
 
//function to display stock and prices
void see_stuff(product object[10]) {
    system("cls");
    cout << "\n\n\nHERE IS THE DETAIL ON ALL OF OUR PRODUCTS\n\n\n";
    cout << setw(15) << "Product No." << setw(40) << "Product Name" << setw(20) << "Items in Stock" << setw(20) << "Price" << endl; //format: 1 Biscuit 100 10.5
    for (int i = 0; i < 10; i++) {
        cout << setw(15) << i + 1 << setw(40) << object[i].getname() << setw(20) << object[i].getstock() << setw(20) << object[i].getprice() << endl;
    }
    system("pause");
    system("cls");
}
 
//main function
int main() {
    product stuff[10];              //class array
 
    //declairing variables
    int choice;
 
    // declaring product name and price
    stuff[0].setname("Coconut biscuits");                       stuff[0].setprice(12.0);
    stuff[1].setname("Wai Wai noodles");                        stuff[1].setprice(20.0);
    stuff[2].setname("Cadbury Dairy Milk");                     stuff[2].setprice(45.5);
    stuff[3].setname("Lays");                                   stuff[3].setprice(50.0);
    stuff[4].setname("Rara Noodles");                           stuff[4].setprice(18.5);
    stuff[5].setname("Khajurko Puff");                          stuff[5].setprice(50.0);
    stuff[6].setname("Nanglo Doughnut");                        stuff[6].setprice(15.0);
    stuff[7].setname("Nanglo whole-wheat bread");               stuff[7].setprice(65.0);
    stuff[8].setname("Dabur Real fruit juice");                 stuff[8].setprice(30.0);
    stuff[9].setname("Coca-Cola");                              stuff[9].setprice(35.5);
 
    // declairing the number of items in stock and setting purchased = 0 for easy calculation  
    for (int i = 0; i < 10; i++) {
        stuff[i].setstock(100);
    }
 
    cout << "\n\n\nWELCOME TO PASAL STORE\n\n\n";
start:
    for (int i = 0; i < 10; i++) {
        stuff[i].reset_inout();
    }
    cout << "WHAT DO YOU WANT TO DO?\n\n";
    cout << "1. Go shopping\n";
    cout << "2. View products in stock with prices\n";
    cout << "3. Add products to stock\n";
    cout << "4. Quit\n";
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;
 
    switch (choice) {
    case 1:
        buy_stuff(stuff);
        break;
    case 2:
        see_stuff(stuff);
        break;
    case 3:
        add_stuff(stuff);
        break;
    case 4:
        goto end;
    default:
        system("cls");
        cout << "\n\nCHOICE INVALID\n\n";
        goto start;
    }
    goto start;
    end:
 
    return 0;
}
