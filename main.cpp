//
//  main.cpp
//  AVL
//
//  Created by Prashanti Pokharel on 11/8/21.
//



#include"Stock.h"
#include "Tree.h"

#include <iostream>
#include<fstream>
#include<string>
//************************************************************************************************
using namespace std;
//************************************************************************************************
int main()
{
    
    //Question 2
    AVLTree<int> a;
    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        int number = rand() % 5000 + 1;
        a.insert(number);
    }
    cout<<"Inorder: "<<endl;
    a.inorder();
    cout<<endl;
    cout<<"Preorder: "<<endl;
    a.preorder();
    cout<<endl;
    cout<<"Postorder: "<<endl;
    a.postorder();
    cout<<endl;
    a.height();
    cout<<"The tree height is : "<<a.height()<<endl;
    a.destroy();
    cout<<"Tree height after destroying is : " << a.height()<<endl;
    
    
    //Question 3
    const int
        displayName = 1,
        displayPrice = 2,
        insert = 3,
        all = 4,
        quit = 5;

    int input = 0;
    string name, symbol;
    double price = 0.0;



    string line;
    double dline;

    AVLTree<Stock> myTree;
    ifstream File;

    File.open("stocks.txt");
    if (!File)
    {
        cout << "Error opening file.\n";
    }

    while (getline(File, line))
    {
        Stock company;
        company.setName(line);
        getline(File, line);
        company.setSymbol(line);
        File >> dline;
        company.setPrice(dline);
        File.ignore(1000, '\n');
        myTree.insert(company);
    }

    File.close();

    while (input != quit)
    {
        cout << "               =====MENU====\n"
            << "Choose one of the following numbers to perform a task:\n";
        cout << " 1. Display name of stock using symbol.\n";
        cout << " 2. Display stock price with using sumbol.\n";
        cout << " 3. Insert a new stock\n";
        cout << " 4. Display all stocks\n";
        cout << " 5. Quit\n";

        cout << "\nEnter your Choice: ";
        cin >> input;

        if (input < displayName || input > quit)
        {
            cout << "Invalid Entry!!! \n \tPlease enter a valid menu option: ";
            cin >> input;
        }

        if (input == displayName)
        {
            cout << "Enter Stock's Symbol to display the Name: ";
            cin >> symbol;
            Stock temp("", symbol);

            Stock *ptr = myTree.search(temp);

            if (ptr == nullptr)
            {
                cout << "Not Found.\n";
            }
            else
            {
                cout << ptr->getName();
            }
            cout << endl;
        }

        else if (input == displayPrice)
        {
            cout << "Enter Stock's Symbol to display the Price: ";
            cin >> symbol;
            Stock temp("", symbol);

            Stock *ptr = myTree.search(temp);

            if (ptr == nullptr)
            {
                cout << "Not Found.\n";
            }
            else
            {
                price = ptr->getPrice();
                cout << price;
            }
            cout << endl;
        }


        else if (input == insert)
        {
            Stock newCom;
            cout << "Enter Name of new Company: ";
            cin.ignore();
            getline(cin, name);
            newCom.setName(name);

            cout << "Enter Symbol of new Company: ";
            getline(cin, symbol);
            newCom.setSymbol(symbol);

            cout << "Enter Price of new Company: ";
            cin >> price;
            newCom.setPrice(price);

            myTree.insert(newCom);
            cout << endl;
        }

        else if (input == all)
        {
            cout << "\n \t +++ALL STOCKS LIST+++\t \n";
            myTree.writeFile();
            Stock company;
            cout << endl;

        }
        else if (input == quit)
        {
            ofstream outFile;
            cout << endl;
            cout << "Writing Data to the File......\n";

            outFile.open("stocks.txt", ios::out);
            myTree.writeFile(outFile);
            outFile.close();

            cout << "Done!!\n";
        }

    }

    return 0;
}

