/*
Program Name: Employee Info Displayer
Programmer Name: Wasim Algamal
Description: Using created classes, program asks for sample data from various employees
			 and then calculates each employee's pay and displays it in console and log file
Date Created: 11/22/20
*/

#pragma once

using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ios>

//Description: prints dividers for organizational purposes
//Post-condition: prints dividers
void printDivider(ofstream& outFile) {
	cout << "--------------------------------------------\n";
	outFile << "--------------------------------------------\n";
}

class Employee {
private:
	string firstName;
	string lastName;
	string socialSec;
	string empNum;
public:
	//CONSTRUCTOR AND DE-CONSTRUCTOR
	Employee() {
		firstName = "XXXXXX";
		lastName = "XXXXXX";
		socialSec = "XXXXXXXXX";
		empNum = "XXXX";
	}

	~Employee() {};

	//SETTERS
	void setFirstName(ofstream& outFile) {
		string fName;
		cout << "Please enter your first name: ";
		outFile << "Please enter your first name: ";
		cin.clear();
		cin.ignore();
		cin >> fName;
		outFile << "\nUser Entered: " << fName << endl;
		firstName = fName;
		printDivider(outFile);
	}

	void setLastName(ofstream& outFile) {
		string lName;
		cout << "Please enter your last name: ";
		outFile << "Please enter your last name: ";
		cin.clear();
		cin.ignore();
		cin >> lName;
		outFile << "\nUser Entered: " << lName << endl;
		lastName = lName;
		printDivider(outFile);
	}

	void setSocialSec(ofstream& outFile) {
		int checkLength = 9;
		bool loop = true;
		string userSSN;

		while (loop == true) {
			cout << "Please enter your social security number.\n(Please ONLY include numbers; no dashes): ";
			outFile << "Please enter your social security number.\n(Please ONLY include numbers; no dashes): ";
			cin >> userSSN;
			outFile << "\nUser Entered: " << userSSN << endl;

			if (userSSN.size() == checkLength) {
				for (int i = 0; i < 9; i++) {
					if (isdigit(userSSN[i])) {
						loop = false;
					}
					else {
						cout << "Sorry, you have entered an invalid Social Security Number. Try again.\n";
						outFile << "Sorry, you have entered an invalid Social Security Number. Try again.\n";
						loop = true;
						break;
					}
				}

			}
			else {
				cout << "Sorry, you have entered an invalid Social Security Number. Try again.\n";
				outFile << "Sorry, you have entered an invalid Social Security Number. Try again.\n";
				loop = true;
			}
		}

		socialSec = userSSN;
		printDivider(outFile);
	}

	void setEmpNum(ofstream& outFile) {
		int checkLength = 4;
		bool loop = true;
		string userEmpNum;

		while (loop == true) {
			cout << "Please enter your employee number.\n(Three numbers and a letter at the end): ";
			outFile << "Please enter your employee number.\n(Three numbers and a letter at the end): ";
			cin >> userEmpNum;
			outFile << "\nUser Entered: " << userEmpNum << endl;

			if (userEmpNum.size() == checkLength) {

				for (int i = 0; i < 3; i++) {
					if (isdigit(userEmpNum[i])) {
						loop = false;
					}
					else {
						cout << "Sorry, you have entered an invalid Employee Number. Try again.\n";
						outFile << "Sorry, you have entered an invalid Employee Number. Try again.\n";
						loop = true;
						break;
					}

					if (loop == true) {
						break;
					}

					if (isalpha(userEmpNum[3])) {
						userEmpNum[3] = toupper(userEmpNum[3]);
						break;
					}
					else {
						cout << "Sorry, you have entered an invalid Employee Number. Try again.\n";
						outFile << "Sorry, you have entered an invalid Employee Number. Try again.\n";
						loop = true;
					}
				}
			}
			else {
				cout << "Sorry, you have entered an invalid Employee Number. Try again.\n";
				outFile << "Sorry, you have entered an invalid Employee Number. Try again.\n";
				loop = true;
			}
		}
		empNum = userEmpNum;
		printDivider(outFile);
	}

	//GETTERS
	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	string getSocialSec() {
		return socialSec;
	}

	string getEmpNum() {
		return empNum;
	}

	//PRINTS
	void printFirstName(ofstream& outFile) {
		cout << "First Name: " << firstName << endl;
		outFile << "First Name: " << firstName << endl;
	}

	void printLastName(ofstream& outFile) {
		cout << "Last Name: " << lastName << endl;
		outFile << "Last Name: " << lastName << endl;
	}

	void printSocialSec(ofstream& outFile) {
		cout << "Social Security: XXX-XX-";
		outFile << "Social Security: XXX-XX-";

		for (int i = 5; i < 9; i++) {
			cout << socialSec[i];
			outFile << socialSec[i];
		}

		cout << endl;
		outFile << endl;
	}

	void printEmpNum(ofstream& outFile) {
		cout << "Employee Number: ";
		outFile << "Employee Number: ";

		for (int i = 0; i < 3; i++) {
			cout << empNum[i];
			outFile << empNum[i];
		}

		cout << "-";
		cout << empNum[3] << endl;
		outFile << "-";
		outFile << empNum[3] << endl;
	}
};

class SalaryEmployeePay: public Employee {
private:
	float annPay;
	float weekPay;
	int taxCode;
public:
	//CONSTRUCTOR AND DE-CONSTRUCTOR
	SalaryEmployeePay() {
		annPay = 0.00;
		weekPay = 0.00;
		taxCode = 1;
	}

	~SalaryEmployeePay() {};

	//SETTERS
	void setAnnPay(ofstream& outFile) {
		float userAnnPay;
		bool loop = true;

		cout << "Enter your annual pay: ";
		outFile << "Enter your annual pay: ";
		cin.clear();
		cin.ignore();
		cin >> userAnnPay;
		outFile << "\nUser Entered: " << userAnnPay << endl;

		annPay = userAnnPay;
		printDivider(outFile);
	}
	
	void setWeekPay() {
		weekPay = annPay / 52;		
	}

	void setTaxCode(ofstream& outFile) {
		int userTaxCode;
		bool loop = true;

		while (loop == true) {
			cout << "1 = 25%" << endl <<
				"2 = 20%" << endl <<
				"3 = 15%" << endl <<
				"Enter your tax code: ";
			outFile << "1 = 25%" << endl <<
				"2 = 20%" << endl <<
				"3 = 15%" << endl <<
				"Enter your tax code: ";
			cin.clear();
			cin.ignore();
			cin >> userTaxCode;
			outFile << "\nUser Entered: " << userTaxCode << endl;

			if (userTaxCode >= 1 && userTaxCode <= 3) {
				loop = false;
			}
			else {
				cout << "You have entered an invalid number. Try again.\n";
				outFile << "You have entered an invalid number. Try again.\n";
				loop = true;
			}
		}
		taxCode = userTaxCode;
		printDivider(outFile);
	}

	//GETTERS
	float getAnnPay() {
		return annPay;
	}

	float getWeekPay() {
		return weekPay;
	}

	int getTaxCode() {
		return taxCode;
	}

	//PRINTS
	void printAnnPay(ofstream& outFile) {
		cout << "Annual Pay: $" << fixed << setprecision(2) << annPay << endl;			
		outFile << "Annual Pay: $" << fixed << setprecision(2) << annPay << endl;			
	}

	void printWeekPay(ofstream& outFile) {
		cout << "Weekly Pay: $" << fixed << setprecision(2) << weekPay << endl;		
		outFile << "Weekly Pay: $" << fixed << setprecision(2) << weekPay << endl;		
	}

	void printTaxCode(ofstream& outFile) {
		cout << "Tax Code: " << fixed << setprecision(2) << taxCode << endl;		
		outFile << "Tax Code: " << fixed << setprecision(2) << taxCode << endl;		
	}
};

class HourlyEmployee: public Employee {
private:
	float hourPayRate;
	int hoursWorked;
public:
	//CONSTRUCTOR AND DE-CONSTRUCTOR
	HourlyEmployee() {
		hourPayRate = 0.00;
		hoursWorked = 0;
	}

	~HourlyEmployee() {};

	//SETTERS
	void setHourPayRate(ofstream& outFile) {
		float HPR;
		bool loop = true;
		while (loop == true) {
			cout << "Please enter your hourly pay rate: ";
			outFile << "Please enter your hourly pay rate: ";
			cin.clear();
			cin.ignore();
			cin >> HPR;
			outFile << "\nUser Entered: " << HPR << endl;

			if (HPR >= 10 && HPR <= 75) {
				loop = false;
			}
			else {
				cout << "You have entered an invalid rate. Try again.\n";
				outFile << "You have entered an invalid rate. Try again.\n";
				loop = true;
			}
		}
		hourPayRate = HPR;
		printDivider(outFile);
	}

	void setHoursWorked(ofstream& outFile) {
		int HW;
		bool loop = true;
		while (loop == true) {
			cout << "Please enter your number of hours worked: ";
			outFile << "Please enter your number of hours worked: ";
			cin.clear();
			cin.ignore();
			cin >> HW;
			outFile << "\nUser Entered: " << HW << endl;

			if (HW >= 0 && HW <= 60) {
				loop = false;
			}
			else {
				cout << "You have entered an invalid number. Try again.\n";
				outFile << "You have entered an invalid number. Try again.\n";
				loop = true;
			}
		}
		hoursWorked = HW;
		printDivider(outFile);
	}

	//GETTERS
	float getHourPayRate() {
		return hourPayRate;
	}

	int getHoursWorked() {
		return hoursWorked;
	}

	//PRINTS
	void printHourPayRate(ofstream& outFile){
		cout << "Hourly Pay Rate: " << fixed << setprecision(2) << hourPayRate << endl;
		outFile << "Hourly Pay Rate: " << fixed << setprecision(2) << hourPayRate << endl;
	}

	void printHoursWorked(ofstream& outFile) {
		cout << "Hours Worked: " << fixed << setprecision(2) << hoursWorked << endl;
		outFile << "Hours Worked: " << fixed << setprecision(2) << hoursWorked << endl;
	}
};

class HourlyEmployeePay: public HourlyEmployee {
private:
	float OTPayRate;
	int taxCode;
	bool workStatus;
public:
	//CONSTRUCTOR AND DE-CONSTRUCTOR
	HourlyEmployeePay() {
		OTPayRate = 0.00;
		taxCode = 1;
		workStatus = true;
	}

	~HourlyEmployeePay() {};

	//SETTERS
	void setOTPayRate() {
		float OTPR = 0.00;

		if (getHoursWorked() > 40) {
			OTPR = getHourPayRate() * 1.5;
		}

		OTPayRate = OTPR;
	}

	void setTaxCode(ofstream& outFile) {
		int userTaxCode;
		bool loop = true;

		while (loop == true) {
			cout << "1 = 25%" << endl <<
				"2 = 20%" << endl <<
				"3 = 15%" << endl <<
				"Enter your tax code: ";
			outFile << "1 = 25%" << endl <<
				"2 = 20%" << endl <<
				"3 = 15%" << endl <<
				"Enter your tax code: ";
			cin.clear();
			cin.ignore();
			cin >> userTaxCode;
			outFile << "\nUser Entered: " << userTaxCode << endl;

			if (userTaxCode >= 1 && userTaxCode <= 3) {
				loop = false;
			}
			else {
				cout << "You have entered an invalid number. Try again.\n";
				outFile << "You have entered an invalid number. Try again.\n";
				loop = true;
			}
		}
		taxCode = userTaxCode;
		printDivider(outFile);
	}

	void setWorkStatus(ofstream& outFile) {
		char workStat;

		cout << "Are you working full time or part time?" << endl <<
			"Enter 'F' for full time, or anything else for part time: ";
		outFile << "Are you working full time or part time?" << endl <<
			"Enter 'F' for full time, or anything else for part time: ";
		cin.clear();
		cin.ignore();
		cin >> workStat;
		outFile << "\nUser entered: " << workStat << endl;

		workStat = toupper(workStat);

		if (workStat == 'F') {
			workStatus = true;
		}
		else {
			workStatus = false;
		}		
		printDivider(outFile);
	}

	//GETTERS
	float getOTPayRate() {
		return OTPayRate;
	}

	int getTaxCode() {
		return taxCode;
	}

	string getWorkStatus() {
		if (workStatus == true) {
			return "Full Time";
		}
		else {
			return "Part time";
		}		
	}

	//PRINTS
	void printOTPayRate(ofstream& outFile) {
		cout << "Overtime Pay Rate: " << OTPayRate << endl;
		outFile << "Overtime Pay Rate: " << OTPayRate << endl;
	}

	void printTaxCode(ofstream& outFile) {
		cout << "Tax Code: " << taxCode << endl;
		outFile << "Tax Code: " << taxCode << endl;
	}

	void printWorkStatus(ofstream& outFile) {
		cout << "Work Status: ";
		outFile << "Work Status: ";

		if (workStatus == true) {
			cout << "Full Time" << endl;
			outFile << "Full Time" << endl;
		}
		else {
			cout << "Part Time" << endl;
			outFile << "Part Time" << endl;
		}
	}
};

class AgencyEmployeePay: public HourlyEmployee {
private:
	string companyToPay;
public:
	//CONSTRUCTOR AND DE-CONSTRUCTOR
	AgencyEmployeePay() {
		companyToPay = "XXXXXX";
	}

	~AgencyEmployeePay() {};

	//SETTERS
	void setCompay(ofstream& outFile) {
		string companyName;
		cout << "Please enter your company name: ";
		outFile << "Please enter your company name: ";
		cin.clear();
		cin.ignore();
		getline(cin, companyName);
		outFile << "\nUser entered: " << companyName << endl;
		companyToPay = companyName;
		printDivider(outFile);
	}

	//GETTERS
	string getCompany() {
		return companyToPay;
	}

	//PRINTS
	void printCompany(ofstream& outFile) {
		cout << "Company Name: " << companyToPay << endl;
		outFile << "Company Name: " << companyToPay << endl;
	}
};