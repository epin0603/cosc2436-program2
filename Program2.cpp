/////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Eddie G. Pineda         								   //
//Date: 10/22/2022										   //
//Program Statement: Create a program that creates an array of six DivSales objects. The user      //
//                   enters the sales for four quarters for each division,and the program should   //
//                   display a table showing the division sales for each quarter. Then display     //
//                   the total corporate sales for the year.                                       //
//                       *Use an array with four elements that holds four quarters of sales for    //
//                        the division.                                                            //
//                       *Use a private static variable to hold the total corporate sales for all  //
//                        divisions for the entire year.                                           //
//                       *Use a member function that takes four arguments that represent the four  //
//                        quarters. The values should be copied into the array that holds the      //
//                        sales data. The total fo the four should be added to the static variable //
//                       *Use a function that takes an integer argument within 0 to 3. The         //
//                        argumet is used as a subscript into the division quarterly sales array.  //
//                        The function should return the value of the array element with that      //
//                        subscript.                                                               //
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

class DivSales{ //Class
private:    
    double sales[4];        // There are 4 quarters
    static double totalSales; //Static vatiable that holds total sales
public:     
    DivSales(); //Constructor
    void setSales(double, double, double, double); //Member function that gets sales for all four quarters
    double getQSales(int q) //Function that returns the value of the array element wih a subscript from 0 to 3
    {
        return sales[q]; //Returns chosen quarter sales
    }
    double getCorpSales() //Function that returns total sales
    {
        return totalSales; //Returns total sales
    }
};

double DivSales::totalSales = 0; //Initializer for static variable

DivSales::DivSales() { //Constructor definition
    for (int i = 0; i < 4; i++) { //Parses through all four quarters
        sales[i] = 0; //Sets value of sales for each quarter to 0
    }
}

void DivSales::setSales(double firstQ, double secondQ, double thirdQ, double fourthQ) { //Member function that copies quarterly sales into sales[] and adds to the total sales
    double totNum = 0; //Temporary variable used to sum up all of the quartely sales

    sales[0] = firstQ; //Copies first quarter to sales
    sales[1] = secondQ; //Copies second quarter to sales
    sales[2] = thirdQ; //Copies third quarter to sales
    sales[3] = fourthQ; //Copies fourth quarter to sales

    for (int i = 0; i < 4; i++) { //For loop that parses through all four quarters
        totNum += getQSales(i); //Quarter sales are added to temp variable
    }
    totalSales += totNum; //Temp variable is added to the current total sales
}



int main() {
    DivSales divisions[6]; //Creates array for all six divisions
    double firstQuarter, secondQuarter, thirdQuarter, fourthQuarter; //Temporarily stores the values for each quarter

    for (int i = 0; i < 6; i++) { //For loop that parses through all six divisions
        cout << "Divison: " << (i + 1) << endl; //Prints out the current division number
        cout << "Enter the sales for the first quarter: ";
        cin >> firstQuarter;
        cout << "Enter the sales for the second quarter: ";
        cin >> secondQuarter;
        cout << "Enter the sales for the third quarter: ";
        cin >> thirdQuarter;
        cout << "Enter the sales for the fourth quarter: ";
        cin >> fourthQuarter;

        divisions[i].setSales(firstQuarter, secondQuarter, thirdQuarter, fourthQuarter); //Uses setSales to store sales for all four quarters
        cout << endl; //Ends the line for legibility
    }
    
    cout << "Sales Report:" << endl;
    for (int i = 0; i < 6; i++) { //Parses through all six divisions
        cout << "Division " << (i + 1) << " "; //Prints out the division and its number
        
        for (int j = 0; j < 4; j++) { //Parses through all four quarter sales
            cout << "Q" << (j + 1) << ": $" << divisions[i].getQSales(j) << "   "; //Prints out the current quarter sales
        }
        cout << endl << endl; //Ends two lines for legibility
    }

    cout << "Total Corporate Sales: " << divisions[0].getCorpSales() << endl; //Prints out the total corporate sales from all six divisions for the year

	return 0;
}
