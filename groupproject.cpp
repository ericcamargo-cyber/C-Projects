#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
double totalDays;
double departureTime;
double total, allowabletotal, difference, saved;
double mealExpenses(double breakfast, double lunch, double dinner, double &total, double &allowabletotal, double &saved, double &difference) {
	total=0;
	allowabletotal=0;
	difference=0;
	saved=0;
	for (int i=1; i <= totalDays; i++)
	{
		if (i==1)
		{
			if (departureTime < 07.00)
			{
				cout << endl << "Enter the total cost of breakfast for the first day" << endl;
				cin >> breakfast;
				while (breakfast<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> breakfast;
				}
				if (breakfast>9)
				{
					difference = breakfast-9;
					allowabletotal = 9;
				}
				else if (breakfast<=9)
				{
					difference = difference + 0;
					allowabletotal = allowabletotal+breakfast;
				}
				total=total+breakfast;
				
				cout << endl << "Enter the total cost of lunch for the first day" << endl;
				cin >> lunch;
				while (lunch<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> lunch;
				}
				if (lunch>12)
				{
					difference = difference + (lunch-12);
					allowabletotal = allowabletotal+12;
				}
				else if (lunch<=12)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+lunch;
				}
				total=total+lunch;
				
				cout << endl << "Enter the total cost of dinner for the first day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+dinner;
				}
				total=total+dinner;
			}
			else if (departureTime >= 07.00 && departureTime < 12.00)
			{
				cout << endl << "Enter the total cost of lunch for the first day" << endl;
				cin >> lunch;
				while (lunch<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> lunch;
				}
				if (lunch>12)
				{
					difference = difference + (lunch-12);
					allowabletotal = allowabletotal+12;
				}
				else if (lunch<=12)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+lunch;
				}
				total=total+lunch;
				
				cout << endl << "Enter the total cost of dinner for the first day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+dinner;
				}
				total=total+dinner;
			}
			else if (departureTime >= 12.00 && departureTime < 18.00) 
			{
				cout << endl << "Enter the total cost of dinner for the first day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+dinner;
				}
				total=total+dinner;
			}
		}
		
		if (total<37)
		{
			saved = (37-total);
		}
		
		if (i==totalDays)
		{
			if (departureTime < 08.00)
			{
				cout << endl << "Enter the total cost of breakfast for the second day" << endl;
				cin >> breakfast;
				while (breakfast<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> breakfast;
				}
				if (breakfast>9)
				{
					difference = breakfast-9;
					allowabletotal = allowabletotal+9;
				}
				else if (breakfast<=9)
				{
					difference = difference + 0;
					allowabletotal = allowabletotal+breakfast;
				}
				total=total+breakfast;
				
				cout << endl << "Enter the total cost of lunch for the second day" << endl;
				cin >> lunch;
				while (lunch<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> lunch;
				}
				if (lunch>12)
				{
					difference = difference + (lunch-12);
					allowabletotal = allowabletotal+12;
				}
				else if (lunch<=12)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+lunch;
				}
				total=total+lunch;
				
				cout << endl << "Enter the total cost of dinner for the second day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = total+dinner;
				}
				total=total+dinner;
			}
			else if (departureTime >= 08.00 && departureTime < 13.00)
			{
				cout << endl << "Enter the total cost of lunch for the second day" << endl;
				cin >> lunch;
				while (lunch<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> lunch;
				}
				if (lunch>12)
				{
					difference = difference + (lunch-12);
					allowabletotal = allowabletotal+12;
				}
				else if (lunch<=12)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+lunch;
				}
				total=total+lunch;
				
				cout << endl << "Enter the total cost of dinner for the second day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+dinner;
				}
				total=total+dinner;
			}
			else if (departureTime >= 13.00 && departureTime < 19.00) 
			{
				cout << endl << "Enter the total cost of dinner for the second day" << endl;
				cin >> dinner;
				while (dinner<0)
				{
					cout << endl << "Invalid amount, cannot be negative, re-enter" << endl;
					cin >> dinner;
				}
				if (dinner>16)
				{
					difference = difference + (dinner-16);
					allowabletotal = allowabletotal+16;
				}
				else if (dinner<=16)
				{
					difference = difference+0;
					allowabletotal = allowabletotal+dinner;
				}
				total=total+dinner;
				
			}
			if (total<74)
			{
			saved =(74-total);
			}
		
		
		}
					
	
	}
	cout << endl << "Total expenses for meals : $" << total << endl;
	cout << "Total Allowoble expenses for meals: $" << allowabletotal << endl;
	cout << "Excess expenses for meals: $" << difference << endl;
	cout << "Amount Saved from meals: $" << saved << endl;
	

}

int main(int argc, char** argv) {
	double a,b,c,d,e,f,g;
	cout << "Enter the amount of Days of the trip" << endl;
	cin >> totalDays;
	mealExpenses(a,b,c,d,e,f,g);  //trying to call the funtion so the cout statements are displayed

	return 0;
}
