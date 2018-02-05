#include <iostream>
#include "List.h"

int main() {

    auto *test = new List();
    bool flag = true;
    int userNum;
    char addName[100];
    int addData;
    int count;

    do{
        std::cout << "1 - Add a new node" << std::endl;
        std::cout << "2 - Display All" << std::endl;
        std::cout << "3 - Find by Name" << std::endl;
        std::cout << "4 - Find by Data" << std::endl;
        std::cout << "5 - Delete by Name" << std::endl;
        std::cout << "6 - Delete by Data" << std::endl;
        std::cout << "7 - Delete all by Name" << std::endl;
        std::cout << "8 - Delete all by Data" << std::endl;
        std::cout << "9 - Count number of Nodes" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "Please choose a selection: ";
        std::cin >> userNum;//point of the exercise is the list class so I won't bother with validation here
        std::cin.ignore(100,'\n');

        switch (userNum){
            case 1:
                std::cout << "Enter the name to add: ";
                std::cin.get(addName,100,'\n');
                std::cin.ignore(100,'\n');
                std::cout << "Enter a data to add: ";
                std::cin >> addData;
                std::cin.ignore(100,'\n');
                flag = test->addNode(addName,addData);
                if(!flag)
                    std::cout << "Error: adding a new node to the program. Exiting Program." << std::endl;
                break;
            case 2:
                test->displayAll();
                break;
            case 3:
                std::cout << "Enter the name you are looking for: ";
                std::cin.get(addName,100,'\n');
                std::cin.ignore(100,'\n');
                flag = test->findName(addName);
                if(!flag)
                {
                    std::cout << addName << " was not found in the list" << std::endl;
                    flag = true;
                } else
                {
                    std::cout << addName << " is in the list!" << std::endl;
                }
                break;
            case 4:
                std::cout << "Enter the data you are looking for: ";
                std::cin >> addData;
                std::cin.ignore(100,'\n');
                flag = test->findData(addData);
                if(!flag)
                {
                    std::cout << addData << " was not found in the list." << std::endl;
                    flag = true;
                }
                else
                {
                    std::cout << addData << " is in the list!" << std::endl;
                }
                break;
            case 5:
                std::cout << "Enter the name you want to delete: ";
                std::cin.get(addName,100,'\n');
                std::cin.ignore(100,'\n');
                flag = test->delName(addName);
                if(!flag)
                {
                    std::cout << addName << " was not found in the list" << std::endl;
                    flag = true;
                } else
                {
                    std::cout << addName << " has been deleted!" << std::endl;
                }
                break;
            case 6:
                std::cout << "Enter the data you want to delete: ";
                std::cin >> addData;
                std::cin.ignore(100,'\n');
                flag = test->delData(addData);
                if(!flag)
                {
                    std::cout << addData << " was not found in the list." << std::endl;
                    flag = true;
                }
                else
                {
                    std::cout << addData << " has been removed from the list!" << std::endl;
                }
                break;
            case 7:
                std::cout << "Enter the name you want to delete: ";
                std::cin.get(addName,100,'\n');
                std::cin.ignore(100,'\n');
                count = test->delNameAll(addName);
                std::cout << addName << " was removed from the list " << count << " times." << std::endl;
                break;
            case 8:
                std::cout << "Enter the data you want to delete: ";
                std::cin >> addData;
                std::cin.ignore(100,'\n');
                count = test->delDataAll(addData);
                std::cout << addData << " was removed from the list " << count << " times." << std::endl;
                break;
            case 9:
                count = test->countList();
                std::cout << "The list contains " << count << " nodes." << std::endl;
                break;
            case 0:
                std::cout << "Exiting the Program" << std::endl;
                flag = false;
                break;
            default:
                std::cout << "This is not a valid selection." << std::endl;
                break;
        }
    }while(flag);

    std::cout << "Deleting the List Class" << std::endl;
    delete test;
    std::cout << "List class has been deleted." << std::endl;

    return 0;
}