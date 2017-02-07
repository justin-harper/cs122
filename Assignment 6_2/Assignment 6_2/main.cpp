/*
Justin Harper
10696738

version 1.0
*/



#include "Customer.h"
#include "CheckoutLine.h"
#include "CheckoutSimFunctions.h"

#include "RandomNumberGenerator.h"

#include <time.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>





//using namespace std;
int main(void)
{

	RandomNumberGenerator rand{ 0 };
	std::vector<CheckoutLine> checkoutLane;
	std::ofstream outputFile("output.csv");


	int customerId = 0;

	int randomCheckstand;
	int userInput;
	int newCustomer = 0;
	int serviceTime = 0;
	int probNewCustomerArives = 0;
	int randService;

	double avg = 0;


	

	userInput = getCheckLanes();
	randService = getRandBound();

	std::system("cls");

	//J will be number of checkstands
	for (int j = 0; j < userInput; j++)
	{

		checkoutLane.push_back( CheckoutLine{ j } );
	}



	//main loop for 720 "ticks"
	for (int tick = 0; tick < 720; tick++)
	{
		

//region 4A	
		newCustomer = rand.getRandomNumber(0, 5);


		//If the random number is less than or equal to the probability of a new customer 
		//arriving(Step #3), reset the probability back to 0 and go to Step 4B
		if (newCustomer <= probNewCustomerArives)
		{
//region 4B

			//A new customer has arrived, create a new customer whose arrival time is equal to the 
			//current simulation time and whose service time is a randomly generated number between 1
			//and 4.
			probNewCustomerArives = 0;
			serviceTime = rand.getRandomNumber(0, randService);
			customerId++;
			Customer newCusty{ customerId, tick, serviceTime };

			//Next, try to find an empty checkstand. If one exists, place the customer in the line at 
			//that checkstand. If no empty checkstand exists, randomly select a checkstand for the
			//customer to enter.
			bool cont = true;
			for (int numLines = 0; numLines < checkoutLane.size() && cont; numLines++)
			{
				if (checkoutLane[numLines].isEmpty())
				{	//an empty line exits place the custmer in the empty line
					checkoutLane[numLines].addCustomer(newCusty);
					newCusty.setLineNumber(numLines);
					cont = false;
				}
			}
			if (cont == true)
			{	//no empty lines were found
				//randomly select a checkstand for the customer to enter
				int randLine = rand.getRandomNumber(0, (checkoutLane.size() - 1));
				checkoutLane[randLine].addCustomer(newCusty);
				newCusty.setLineNumber(randLine);

			}

		}
//end 4B
//end 4A


//region 4C
		else
		{//the number is greater than the probability of a new customer arriving (Step #3), 
		 //increment the probability of the new customer arriving by 1, Go to Step 4C


			//For each checkstand in the simulation: 
			for (int numCheckstands = 0; numCheckstands < checkoutLane.size(); numCheckstands++)
			{
				//i.If there is at least one customer in the checkstand, go to 4.C.II.Otherwise, go back
				//to 4.C (look at the next checkstand in the simulation).
				if (!(checkoutLane[numCheckstands].isEmpty()))
				{
					//ii.If the first customer in line has not received a departure time, calculate one.
					//Departure time = current tick + customers service time.
					if(checkoutLane[numCheckstands].getFirstCustomer().getDepartTime() == -5)
					{
						checkoutLane[numCheckstands].getFirstCustomer().setDepartTime(tick + checkoutLane[numCheckstands].getFirstCustomer().getServiceTime());
	
					}
					
					
					/*if (checkoutLane[numCheckstands].getFirstCustomer().getTest() == -5)
					{
						checkoutLane[numCheckstands].getFirstCustomer().setTest(tick + checkoutLane[numCheckstands].getFirstCustomer().getServiceTime());
					}
					*/






					//iii.If the total time elapsed is greater than the first customer's departure time, then the 
					//customer has completed the checkout process.Remove them from the queue.
					if (tick > checkoutLane[numCheckstands].getFirstCustomer().getDepartTime())
					{
						checkoutLane[numCheckstands].serviceCustomer();
					}

				}

			}

			probNewCustomerArives++;


		}
//end 4C
		
		
		//end tick loop 
	}

	

//region 5


		/*After the simulation completes, write the results to a CSV file in the following format :
		<Customer ID>, <Arrival Time>, <Time to Check Out>, <Departure Time>, <Total Wait>, <LineNumber>.

		Also include the total number of customers generated during the simulation at the top of the CSV
		file.Note that an example CSV file will be included with this assignment description.I have
		provided a CsvWriter class to aid in the construction of CSV files.*/

	outputFile << "                                  " << std::endl << "Customer ID" << "," << "Arrival Time" << ","
		<< "Time to Check out" << "," << "Departure Time" << ","
		<< "Total Wait" << "," << "Line Number" << "," << std::endl;

	for (int numCheckout = 0; numCheckout < checkoutLane.size(); numCheckout++)
	{
		

		for (int numServiced = 0; numServiced < checkoutLane[numCheckout].getServiceCustomer().size(); numServiced++)
		{
			

			Customer custy = checkoutLane[numCheckout].getServiceCustomer()[numServiced];

			avg += custy.getTotalWaitTime();


			outputFile << custy.getCustomerId() << "," << custy.getArrivalTime() << "," << custy.getServiceTime() << ","
				<< custy.getDepartTime() << "," << custy.getTotalWaitTime() << "," << numCheckout + 1 << "," << std::endl;
		}
	}

	
	//thought it would be handy to have the avg wait time
	avg = avg / customerId;

	
	outputFile.seekp(0, ios::beg);
	outputFile.precision(2);
	outputFile << "Average Wait Time" << "," << avg;


	outputFile.close();
	system("output.csv\0");

	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
