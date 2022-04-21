#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream read("your input file.txt", ios::in);
    ofstream write("your output file.txt", ios::app);

    string text, choice = "0";
    string old_replacement; //what you dont want
    string new_replacement; //what you want
    int start, count = 0;

    do
    {
        cout << "\nWhat do you want? \n1. Insert new item into current line 2. Replace the whole line \nYour choice: ";
        cin >> choice; // choice variable use string as user might type alphabet
        cout << endl;
        if (choice != "1" && choice != "2")
        {
            cout << "Error! You had enter invalid option!" << endl;
        }

    } while (choice != "1" && choice != "2");

    if (choice == "2")
    {
        cout << "Old text: ";
        getline(cin, old_replacement);
        getline(cin, old_replacement);
    }

    cout << "New text: ";
    getline(cin, new_replacement);
    getline(cin, new_replacement);


    read.clear();
    read.seekg(0, ios::beg);

    if (choice == "1")
    {

        do
        {
            cout << "\nWhere to replace in the line? \n1.Start 2.End \nYour choice: ";
            cin >> choice; // choice variable use string as user might type alphabet
            cout << endl;
            if (choice != "1" && choice != "2")
            {
                cout << "Error! You had enter invalid option!" << endl;
            }

        } while (choice != "1" && choice != "2");

        if (choice == "1")
        {
            while (!read.eof())
            {
                getline(read, text);
                write << new_replacement << text << endl;
            }
        }

        if (choice == "2")
        {
            while (!read.eof())
            {
                getline(read, text);
                write << text << new_replacement << endl;
            }
        }

        cout << "Successfully update!" << endl;

    }



    if (choice == "2")
    {
        while (!read.eof())
        {
            getline(read, text);
            count++;
        }

        read.clear();
        read.seekg(0, ios::beg);

        for (start = 0; start <= count; start++)
        {
            getline(read, text);
            while (text.find(old_replacement) != string::npos)
            {
                text.replace(text.find(old_replacement), old_replacement.length(), new_replacement);
            }
            write << text;
        }

        cout << "Successfully update!" << endl;
    }


    return 0;
}