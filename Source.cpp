/*
Program Name: Employee Info Displayer
Programmer Name: Wasim Algamal
Description: Using created classes, program asks for sample data from various employees 
			 and then calculates each employee's pay and displays it in console and log file
Date Created: 11/22/20
*/

#include "AllClasses.h"

//Description: sets control variable
//Pre-condition: passes control from main and asks user to override it
//Post-condition: control is set to user's desired choice
void setControl(char& control) {
	char temp;
	cout << "*NOTE: IF YOU ENTER ANYTHING OTHER THAN 'Y', IT WILL BE CONSIDERED AS A NO\n";
	cout << "Would you like to enter data for another employee? [Y/N]: ";
	cin >> temp;
	control = temp;
}

int main() {
	int userSelect;
	char control = 'y';
	SalaryEmployeePay salEmp;
	HourlyEmployeePay hourEmp;
	AgencyEmployeePay agentEmp;
	ofstream outFile;
	outFile.open("pay.dat");

	cout << "Hello, and welcome to the Employee Data Displayer.\n\n";
	outFile << "Hello, and welcome to the Employee Data Displayer.\n\n";

	while (control == 'y' || control == 'Y') {
		cout << "Please select what type of employee you are: \n";
		outFile << "Please select what type of employee you are: \n";

		cout << "1: Salary Employee\n";
		cout << "2: Hourly Employee\n";
		cout << "3: Agency Employee\n";

		outFile << "1: Salary Employee\n";
		outFile << "2: Hourly Employee\n";
		outFile << "3: Agency Employee\n";

		cout << "Selection: ";
		outFile << "Selection: ";
		cin >> userSelect;
		outFile << userSelect;

		cout << endl;
		outFile << endl;

		switch (userSelect) {
		case 1:
			cout << "You have selected \"Salary Employee\".\n";
			outFile << "You have selected \"Salary Employee\".\n";

			//SETTER
			salEmp.setFirstName(outFile);
			salEmp.setLastName(outFile);
			salEmp.setSocialSec(outFile);
			salEmp.setEmpNum(outFile);
			salEmp.setAnnPay(outFile);
			salEmp.setWeekPay();
			salEmp.setTaxCode(outFile);

			cout << "Results:\n";
			outFile << "Results:\n";

			//PRINTS
			salEmp.printFirstName(outFile);
			salEmp.printLastName(outFile);
			salEmp.printSocialSec(outFile);
			salEmp.printEmpNum(outFile);
			salEmp.printAnnPay(outFile);
			salEmp.printWeekPay(outFile);
			salEmp.printTaxCode(outFile);

			//USED ONLY TO TEST GET METHODS
			/*cout << "First Name: " << salEmp.getFirstName() << endl;
			outFile << "First Name: " << salEmp.getFirstName() << endl;
			cout << "Last Name: " << salEmp.getLastName() << endl;
			outFile << "Last Name: " << salEmp.getLastName() << endl;
			cout << "Unmasked Social Security: " << salEmp.getSocialSec() << endl;
			outFile << "Unmasked Social Security: " << salEmp.getSocialSec() << endl;
			cout << "Unmasked Employee Number: " << salEmp.getEmpNum() << endl;
			outFile << "Unmasked Employee Number: " << salEmp.getEmpNum() << endl;
			cout << "Annual Pay: $" << salEmp.getAnnPay() << endl;
			outFile << "Annual Pay: $" << salEmp.getAnnPay() << endl;
			cout << "Week Pay: $" << salEmp.getWeekPay() << endl;
			outFile << "Week Pay: $" << salEmp.getWeekPay() << endl;
			cout << "Tax Code: " << salEmp.getTaxCode() << endl;
			outFile << "Tax Code: " << salEmp.getTaxCode() << endl;*/
			
			setControl(control);
			printDivider(outFile);
			break;
		case 2:
			cout << "You have selected \"Hourly Employee\".\n";
			outFile << "You have selected \"Hourly Employee\".\n";

			//SETTER
			hourEmp.setFirstName(outFile);
			hourEmp.setLastName(outFile);
			hourEmp.setSocialSec(outFile);
			hourEmp.setEmpNum(outFile);
			hourEmp.setHourPayRate(outFile);
			hourEmp.setHoursWorked(outFile);
			hourEmp.setOTPayRate();
			hourEmp.setTaxCode(outFile);
			hourEmp.setWorkStatus(outFile);

			cout << "Results:\n";
			outFile << "Results:\n";

			//PRINTS
			hourEmp.printFirstName(outFile);
			hourEmp.printLastName(outFile);
			hourEmp.printSocialSec(outFile);
			hourEmp.printEmpNum(outFile);
			hourEmp.printHourPayRate(outFile);
			hourEmp.printHoursWorked(outFile);
			hourEmp.printOTPayRate(outFile);
			hourEmp.printTaxCode(outFile);
			hourEmp.printWorkStatus(outFile);

			//USED ONLY TO TEST GET METHODS
			/*cout << "First Name: " << hourEmp.getFirstName() << endl;
			outFile << "First Name: " << hourEmp.getFirstName() << endl;
			cout << "Last Name: " << hourEmp.getLastName() << endl;
			outFile << "Last Name: " << hourEmp.getLastName() << endl;
			cout << "Unmasked Social Security: " << hourEmp.getSocialSec() << endl;
			outFile << "Unmasked Social Security: " << hourEmp.getSocialSec() << endl;
			cout << "Unmasked Employee Number: " << hourEmp.getEmpNum() << endl;
			outFile << "Unmasked Employee Number: " << hourEmp.getEmpNum() << endl;
			cout << "Hourly Pay Rate: $" << hourEmp.getHourPayRate() << endl;
			outFile << "Hourly Pay Rate: $" << hourEmp.getHourPayRate() << endl;
			cout << "Hours Worked: " << hourEmp.getHoursWorked() << endl;
			outFile << "Hours Worked: " << hourEmp.getHoursWorked() << endl;
			cout << "Overtime Pay Rate: $" << hourEmp.getOTPayRate() << endl;
			outFile << "Overtime Pay Rate: $" << hourEmp.getOTPayRate() << endl;
			cout << "Tax Code: " << hourEmp.getTaxCode() << endl;
			outFile << "Tax Code: " << hourEmp.getTaxCode() << endl;
			cout << "Work Status: " << hourEmp.getWorkStatus() << endl;
			outFile << "Work Status: " << hourEmp.getWorkStatus() << endl;*/

			setControl(control);
			printDivider(outFile);
			break;
		case 3:
			cout << "You have selected \"Agency Employee\".\n";
			outFile << "You have selected \"Agency Employee\".\n";

			//SETTER
			agentEmp.setFirstName(outFile);
			agentEmp.setLastName(outFile);
			agentEmp.setSocialSec(outFile);
			agentEmp.setEmpNum(outFile);
			agentEmp.setHourPayRate(outFile);
			agentEmp.setHoursWorked(outFile);
			agentEmp.setCompay(outFile);

			cout << "Results:\n";
			outFile << "Results:\n";

			//PRINTS
			agentEmp.printFirstName(outFile);
			agentEmp.printLastName(outFile);
			agentEmp.printSocialSec(outFile);
			agentEmp.printEmpNum(outFile);
			agentEmp.printHourPayRate(outFile);
			agentEmp.printHoursWorked(outFile);
			agentEmp.printCompany(outFile);


			//USED ONLY TO TEST GET METHODS
			/*cout << "First Name: " << agentEmp.getFirstName() << endl;
			outFile << "First Name: " << agentEmp.getFirstName() << endl;
			cout << "Last Name: " << agentEmp.getLastName() << endl;
			outFile << "Last Name: " << agentEmp.getLastName() << endl;
			cout << "Unmasked Social Security: " << agentEmp.getSocialSec() << endl;
			outFile << "Unmasked Social Security: " << agentEmp.getSocialSec() << endl;
			cout << "Unmasked Employee Number: " << agentEmp.getEmpNum() << endl;
			outFile << "Unmasked Employee Number: " << agentEmp.getEmpNum() << endl;
			cout << "Hourly Pay Rate: $" << agentEmp.getHourPayRate() << endl;
			outFile << "Hourly Pay Rate: $" << agentEmp.getHourPayRate() << endl;
			cout << "Hours Worked: " << agentEmp.getHoursWorked() << endl;
			outFile << "Hours Worked: " << agentEmp.getHoursWorked() << endl;
			cout << "Company: " << agentEmp.getCompany() << endl;
			outFile << "Company: " << agentEmp.getCompany() << endl;*/

			setControl(control);
			printDivider(outFile);
			break;
		default:
			cout << "SORRY TRY AGAIN!\n";
			outFile << "SORRY TRY AGAIN!\n";
			break;
		}
	}

	outFile.close();
	return 0;
}