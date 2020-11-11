//
// Create a linked list using data from the Employee_Data.txt file
//

#include <iostream>//preprocessor directives
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#define skip2 (cout << endl << endl);

struct employee_data
{
    string firstname;
    string lastname;
    char initial;
    unsigned int ID;
    double hours;
    double wage;
    double pay;
    // Insert link here
    employee_data* link;//node linker pointer
};


void print_data(employee_data &person);//function prototypes


int main(void)
{
    ifstream infile;
    infile.open("/Users/sydneykeller/Desktop/C++/Employee_Data.txt");
    // You will need to change the path to the data file for your computer
    string line;
    employee_data *employee = new employee_data; // Pointer to employee_data type
    unsigned int count = 0;

    if (!infile)
    {
        cout << "Unable to open the employeed data file." << endl;
        system("pause");
        return 1; // Error code for file open error
    }

    cout << "Employee Data File opened." << endl;
    // Read and ingnore the first two lines of the file.
    // They are not data lines.

    getline(infile, line);
    getline(infile, line);

    // Read in the data for the first employee
    infile >> employee->firstname >> employee->lastname >> employee->initial  //error here
        >> employee->ID >> employee->hours >> employee->wage
        >> employee->pay;

    print_data(*employee);

employee_data *root, *current_node, *new_node;

    // 1. Add code to create a root node for the linked list

    current_node = new employee_data;

    // Fill in the data from the first employee.

infile  >> employee->firstname >> employee->lastname >> employee->initial
        >> employee->ID >> employee->hours >> employee->wage
        >> employee->pay;

    print_data(*employee);

    //set link to null

    current_node->link = NULL;

    //save the entry point

     root = current_node;


        // 2. Now write a loop that will read and link the remaining nine
        // employee data records into a linked list.

     infile.ignore(1);
        while (count <= 7)//loop through remaining 9 records in file
        {
            new_node = new employee_data;//gives us space
            infile >> new_node->firstname >> new_node->lastname >> new_node->initial
                >> new_node->ID >> new_node->hours >> new_node->wage
                >> new_node->pay;
            skip2

            new_node->link = NULL;//set link to NULL
            current_node->link = new_node;//current node and new node are linked
            current_node = new_node; //clean up and move your pointer over
            count++;
        }
        skip2
        

        current_node = root; //points to the beginning
        cout << "EMPLOYEE RECORD" << endl;
        print_data(*current_node);


        // 3. Traverse the linked list printing out the data for each employee
        // You can call the print_data function in a loop for this.

    while (current_node != NULL)
        {
            cout << "EMPLOYEE RECORD"; skip2

            //move to second node in the list

            current_node = current_node->link;//take link in current node and make that our current node link moves the link across

            print_data(*current_node);

        }
    


    system("pause");
    return 0;
}

void print_data(employee_data &person)
{
    cout << endl;
    cout << fixed << setprecision(2) << left;
    cout << person.firstname << " " << person.initial
        << " " << person.lastname << endl;
    cout << setw(15) << "ID:" << person.ID << endl;
    cout << setw(15) << "Hours Worked:" << person.hours << endl;
    cout << setw(15) << "Wage:" << person.wage << endl;
    cout << setw(15) << "Gross Pay:" << person.pay << endl << endl;
    cout << right;
    return;
}

