// supermarket project c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;


double total(int price, int qunatity) {// calculates price of product with the quantity 
    int total;
    total = qunatity * price;
    return total;
}

//Searching cart function 
void search(string a[], int numberUsed, string target) {
    for (int i = 0; i < numberUsed; i++) {
        if (target == a[i]) {
            cout << "The iteam is found in the cart, it's number " << i + 1 << " in the cart" << endl << endl;
        }
    }

}

int main()
{
    cout << setw(50) << "*********************" << endl;
    cout << setw(55) << "WELCOME TO PICK'N GO SUPERMARKET" << endl;
    cout << setw(50) << "*********************" << endl;
    cout << endl;
    int question, owners_choice2, products_num, main_menu2;
    string main_menu;
    char owners_choice;
    //Asking user if he/she is owner or customer, if invalid answer it will loop until user enters a valid answer (Sara)
    cout << "Are you an Owner (1) or a Customer (2)?" << endl;
    cin >> question;
    cout << endl;
    //Arrays
    string Products[100] = { "0" };
    double Prices[100] = { 0 };
    int ID[100] = { 0 };

    while (true)
    {
        if (question == 1)
        {
            //Main Menu
            cout << endl;
            question = true;
            cout << "Hello Owner!" << endl;
            cout << endl;
            cout << "What would you like to do: " << endl;
            cout << "a. Preview list of available products" << endl;
            cout << "b. Create a list of products" << endl;
            cout << "c. Edit list of products" << endl;
            cout << "d. Edit products prices" << endl;
            cout << "e. Exit Owner's List" << endl;
            cin >> owners_choice;
            cout << endl;

            //Submenu
            switch (owners_choice)
            {
                //Preview list of available products 
            case('a'):
            {
                int count3 = 0;
                cout << "Preview list of availabe products:" << endl;
                for (int l = 0; l < (sizeof(Products) / sizeof(Products[0])); l++)
                {
                    if (Prices[l] == 0 && ID[l] == 0)
                    {
                        count3++;
                        continue;
                    }
                }

                if (count3 == 100)
                {
                    cout << setw(60) << left << "No products are currently available." << endl;
                    cout << endl;
                    cout << "Would you like to (1) return to main menu or (2) create a new list? ";
                    cin >> owners_choice2;
                    if (owners_choice2 == 1)
                    {
                        break;
                    }
                }
                else
                {
                    cout << "The available products are: " << endl;
                    cout << endl;
                    cout << setw(25) << left << "Product ID" << setw(25) << left << "Product name" << setw(30) << left << "Price" << endl;
                    cout << endl;
                    for (int j = 0; j < (sizeof(Products) / sizeof(Products[0])); j++)
                    {
                        if (Prices[j] == 0.00 && ID[j] == 0)
                        {
                            continue;
                        }
                        else
                            cout << setw(25) << left << ID[j] << setw(25) << left << Products[j] << setw(25) << left << Prices[j] << "$" << endl;
                    }
                    cout << endl;
                    cout << "Would you like to exit to main menu? ";
                    cin >> main_menu;
                    if (main_menu == "Yes" || main_menu == "yes")
                    {
                        continue;
                    }
                    break;
                }
                //no 'break;' so the user enters the "create a list" option
            }

            //Create a list of products 
            case('b'):
            {
                products_num = 0;
                cout << endl;
                cout << "Create a list of products:" << endl;
                cout << "How many products will be in the list? ";
                cin >> products_num;
                for (int o = 0; o < products_num; o++)
                {
                    cout << "Please enter the product ID: ";
                    cin >> ID[o];
                    cout << "Please enter the product name: ";
                    cin >> Products[o];
                    cout << "please enter " << Products[o] << "'s price: ";
                    cin >> Prices[o];
                }
                cout << "Data saved. Would you like to return to main menu? ";
                cin >> main_menu;
                if (main_menu == "Yes" || main_menu == "yes")
                {
                    continue;
                }
                break;
            }

            //Edit list of products 
            case('c'):
            {   int edit, additional_items, count = 1, k = 0, count4 = 0;
            cout << setw(10) << left << "Edit list of products:" << endl;
            for (int n = 0; n < (sizeof(Products) / sizeof(Products[0])); n++)
            {
                if (Prices[n] == 0 && ID[n] == 0)
                {
                    count4++;
                    continue;
                }
            }

            if (count4 == 100)
            {
                cout << setw(60) << left << "No products are currently available." << endl;
                cout << endl;
                cout << "Would you like to return to main menu? ";
                cin >> main_menu;
                if (main_menu == "yes" || main_menu == "Yes")
                {
                    break;
                }
            }
            else
            {
                cout << "Do you want to (1) add or (2) delete products? ";
                cin >> edit;
                cout << endl;
                if (edit == 1)
                {
                    cout << "How many items do you want to add? ";
                    cin >> additional_items;
                    while (count <= additional_items)
                    {
                        cout << "Enter the ID of the product you wish to add: ";
                        cin >> ID[products_num + k];
                        cout << "Enter the name of the product you wish to add: ";
                        cin >> Products[products_num + k];
                        cout << "Enter the price of the product you wish to add: ";
                        cin >> Prices[products_num + k];
                        count++;
                        ++k;
                    }
                    cout << endl;
                    cout << "Do want to (1) return to main menu or (2) delete products from the list? ";
                    cin >> main_menu2;
                    if (main_menu2 == 1)
                    {
                        continue;
                    }
                    else if (main_menu2 == 2)
                    {
                        edit = 2;
                    }
                }
                if (edit == 2)
                {
                    int number_of_items_deleted, count_2 = 0, deleted_ID, count6 = 0;
                    cout << "How many products would you like to delete? ";
                    cin >> number_of_items_deleted;
                    while (count_2 < number_of_items_deleted)
                    {
                        cout << "Enter the product's ID: ";
                        cin >> deleted_ID;
                        count_2++;
                        for (int w = 0; w < (sizeof(Products) / sizeof(Products[0])); w++)
                        {
                            if (ID[w] != deleted_ID)
                            {
                                count6++;
                            }
                            else
                            {
                                ID[w] = 0;
                                Products[w] = "0";
                                Prices[w] = 0.00;
                            }
                        }
                    }
                    if (count6 == 100)
                    {
                        cout << "Invalid ID. Would you like to return to main menu? ";
                        cin >> main_menu;
                        if (main_menu == "yes" || main_menu == "Yes")
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << endl;
                        cout << "List edited successfully. Would you like to return to main menu?" << endl;
                        cin >> main_menu;
                        if (main_menu == "Yes" || main_menu == "yes")
                        {
                            continue;
                        }
                    }
                    break;
                }
            }
            cout << endl;
            cout << "List edited successfully. Would you like to return to main menu?" << endl;
            cin >> main_menu;
            if (main_menu == "Yes" || main_menu == "yes")
            {
                continue;
            }
            break;
            }

            //Edit product price 
            case ('d'):
            {
                int new_price, productid, count7 = 0, count5 = 0;
                cout << "Edit product prices" << endl;
                for (int z = 0; z < (sizeof(Products) / sizeof(Products[0])); z++)
                {
                    if (Prices[z] == 0 && ID[z] == 0)
                    {
                        count5++;
                        continue;
                    }
                }

                if (count5 == 100)
                {
                    cout << setw(60) << left << "No products are currently available." << endl;
                    cout << endl;
                    cout << "Would you like to return to main menu? ";
                    cin >> main_menu;
                    if (main_menu == "yes" || main_menu == "Yes")
                    {
                        break;
                    }
                }
                else
                {
                    cout << "How many products do you wish to change the prices of? " << endl;
                    cin >> new_price;
                    for (int f = 0; f < new_price; f++)
                    {
                        cout << "Enter product ID: ";
                        cin >> productid;
                        for (f = 0; f < (sizeof(Products) / sizeof(Products[0])); f++)
                        {
                            if (ID[f] == productid)
                            {
                                cout << "Please enter your new price: ";
                                cin >> Prices[f];
                            }
                            else
                            {
                                count7++;
                            }
                        }
                    }
                    if (count7 == 100)
                    {
                        cout << "Invalid ID. Would you like to return to main menu? ";
                        cin >> main_menu;
                        if (main_menu == "yes" || main_menu == "Yes")
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "Price edited successfully. Would you like to return to main menu? ";
                        cin >> main_menu;
                        if (main_menu == "Yes" || main_menu == "yes")
                        {
                            continue;
                        }
                        break;
                    }
                }
            }
            }
        }
        else if (question == 2)
        {
            question = true;
            string continuee = "yes", saved[100] = {}, word, answer, answer2;
            int product_ID, quantity, j = 0;
            double saved_price[100] = {};

            cout << "Hello Customer!" << endl;
            //Previweing the list for customer 
            while (continuee == "Yes" || continuee == "YES" || continuee == "yes") {
                cout << setw(20) << left << "ID" << setw(20) << left << "    Products" << setw(5) << left << "  |  " << "Price" << endl << endl;
                for (int i = 0; i < 100; i++) {
                    cout << setw(20) << left << ID[i] << setw(20) << left << Products[i] << setw(5) << left << "  |  " << setw(5) << left << Prices[i] << " $" << endl;
                }
                cout << endl;

                //Cout and Cin of products 
                cout << "Please enter the number of the product you wish to purchase " << endl;
                cin >> product_ID;
                cout << "Please enter the quantity you want of this product " << endl;
                cin >> quantity;
                for (int i = 0; i < (sizeof(Products) / sizeof(Products[0])); i++) {
                    if (ID[i] == product_ID) {
                        saved[j] = Products[i];
                        saved_price[j] = total(Prices[i], quantity);
                        j++;
                    }

                }
                cout << "Product is added to the cart" << endl;
                cout << "Do you wish to buy more products " << endl;
                cin >> continuee;

                cout << endl << endl;
                while (continuee == "Yes" || continuee == "YES" || continuee == "yes")
                {
                    cout << setw(20) << left << "ID" << setw(20) << left << "    Products" << setw(5) << left << "  |  " << "Price" << endl << endl;
                    for (int i = 0; i < 100; i++) {
                        cout << setw(20) << left << ID[i] << setw(20) << left << Products[i] << setw(5) << left << "  |  " << setw(5) << left << Prices[i] << " $" << endl;
                    }
                    cout << endl;

                    cout << "Please enter the number of the product you wish to purchase " << endl;
                    cin >> product_ID;
                    cout << "Please enter the quantity you want of this product " << endl;
                    cin >> quantity;
                    for (int i = 0; i < (sizeof(Products) / sizeof(Products[0])); i++) {
                        if (ID[i] == product_ID) {
                            saved[j] = Products[i];
                            saved_price[j] = total(Prices[i], quantity);
                            j++;
                        }

                    }
                    cout << "Product is added to the cart" << endl;
                    cout << "Do you wish to buy more products " << endl;
                    cin >> continuee;

                    cout << endl << endl;
                }

                //Preview cart 
                cout << "your cart " << endl;
                for (int j = 0; j < 100; j++) {
                    cout << setw(30) << left << saved[j] << setw(30) << left << saved_price[j] << endl;

                }
                int add = 0;
                for (int j = 0; j < 100; j++) {
                    add += saved_price[j];
                }
                cout << endl << endl;
                cout << "Total price to be paid: " << add << endl;

                //Search cart 
                cout << "Do you want to search your cart?" << endl; cin >> answer;

                if (answer == "yes" || answer == "Yes" || answer == "YES") {

                    cout << "Please enter product you want to search for: "; cin >> word;
                    search(saved, 100, word);


                }
                else {

                    cout << endl;
                }
                cout << "Press 1 if you wish to continue shopping, press 2 if you want to checkout" << endl;
                int answer2;
                cin >> answer2;
                if (answer2 == 1)
                {
                    cout << "Hello Customer!" << endl;
                    //Previweing the list for customer 
                    while (continuee == "Yes" || continuee == "YES" || continuee == "yes") {
                        cout << setw(20) << left << "ID" << setw(20) << left << "    Products" << setw(5) << left << "  |  " << "Price" << endl << endl;
                        for (int i = 0; i < 100; i++) {
                            cout << setw(20) << left << ID[i] << setw(20) << left << Products[i] << setw(5) << left << "  |  " << setw(5) << left << Prices[i] << " $" << endl;
                        }
                        cout << endl;

                        //Cout and Cin of products 
                        cout << "Please enter the number of the product you wish to purchase " << endl;
                        cin >> product_ID;
                        cout << "Please enter the quantity you want of this product " << endl;
                        cin >> quantity;
                        for (int i = 0; i < (sizeof(Products) / sizeof(Products[0])); i++) {
                            if (ID[i] == product_ID) {
                                saved[j] = Products[i];
                                saved_price[j] = total(Prices[i], quantity);
                                j++;
                            }

                        }
                        cout << "Product is added to the cart" << endl;
                        cout << "Do you wish to buy more products " << endl;
                        cin >> continuee;

                        cout << endl << endl;
                        while (continuee == "Yes" || continuee == "YES" || continuee == "yes")
                        {
                            cout << setw(20) << left << "ID" << setw(20) << left << "    Products" << setw(5) << left << "  |  " << "Price" << endl << endl;
                            for (int i = 0; i < 100; i++) {
                                cout << setw(20) << left << ID[i] << setw(20) << left << Products[i] << setw(5) << left << "  |  " << setw(5) << left << Prices[i] << " $" << endl;
                            }
                            cout << endl;

                            cout << "Please enter the number of the product you wish to purchase " << endl;
                            cin >> product_ID;
                            cout << "Please enter the quantity you want of this product " << endl;
                            cin >> quantity;
                            for (int i = 0; i < (sizeof(Products) / sizeof(Products[0])); i++) {
                                if (ID[i] == product_ID) {
                                    saved[j] = Products[i];
                                    saved_price[j] = total(Prices[i], quantity);
                                    j++;
                                }

                            }
                            cout << "Product is added to the cart" << endl;
                            cout << "Do you wish to buy more products " << endl;
                            cin >> continuee;

                            cout << endl << endl;
                        }

                        //Preview cart 
                        cout << "your cart " << endl;
                        for (int j = 0; j < 100; j++) {
                            cout << setw(30) << left << saved[j] << setw(30) << left << saved_price[j] << endl;

                        }
                        int add = 0;
                        for (int j = 0; j < 100; j++) {
                            add += saved_price[j];
                        }
                        cout << endl << endl;
                        cout << "Total price to be paid: " << add << endl;

                        //Search cart 
                        cout << "Do you want to search your cart?" << endl; cin >> answer;

                        if (answer == "yes" || answer == "Yes" || answer == "YES") {

                            cout << "Please enter product you want to search for: "; cin >> word;
                            search(saved, 100, word);


                        }
                        else {

                            cout << endl;
                        }
                        cout << "Press 1 if you wish to continue shopping, press 2 if you want to checkout" << endl;
                        int answer2;
                        cin >> answer2;
                    }

                }




            }
            break;
        }
        else
        {
            cout << "Invalid input, please try again..." << endl;
            cin >> question;
            continue;
        }

    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
