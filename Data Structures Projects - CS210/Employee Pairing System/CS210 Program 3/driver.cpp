/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Oct 2022
 */

#include "orgtree.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void assert_(bool didPass, string message) { //never ended up using this & just used my own tests
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    /*
     * Construct the following organization chart for testing
     *                1
     *           /    \    \
     *           2    3    4
     *          / \  / \   \
     *          5 6  7 8   9
     *         /   \       \
     *         10  11      12
     */

    Employee *head = new Employee(1, vector<int>{2, 3, 4});
    Employee *e2 = head->getDirectReports().at(0);
    Employee *e3 = head->getDirectReports().at(1);
    Employee *e4 = head->getDirectReports().at(2);

    e2->addDirectReports(vector<int>{5, 6});
    e3->addDirectReports(vector<int>{7, 8});
    e4->addDirectReport(9);

    Employee *e5 = e2->getDirectReports().at(0);
    Employee *e6 = e2->getDirectReports().at(1);
    Employee *e9 = e4->getDirectReports().at(0);

    e5->addDirectReport(10);
    e6->addDirectReport(11);
    e9->addDirectReport(12);

    //Tells me if Orgtree::isEmployeePresentInOrg is working 
    if (Orgtree::isEmployeePresentInOrg(head, 1)){
        cout << "1 has been found " << endl; //Return this if working
    } else {
        cout << "1 has not been found " << endl;
    }

    if (Orgtree::isEmployeePresentInOrg(head, 12)){
        cout << "12 has been found " << endl; //Return this if working
    } else {
        cout << "12 has not been found " << endl;
    }

    if (Orgtree::isEmployeePresentInOrg(head, -2)){
        cout << "-2 has been found " << endl;
    } else {
        cout << "-2 has not been found " << endl; //Return this if working
    }

    if (Orgtree::isEmployeePresentInOrg(head, 13)){
        cout << "13 has been found" << endl;
    } else {
        cout << "13 has not been found " << endl; //Return this if working 
    }


    //Tells me if Orgtree::findEmployeeLevel can find the levels of all the nodes
    vector<int> v1{ -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    for (int i = 0; i < v1.size(); i++) {
        cout << i << " is at level " << Orgtree::findEmployeeLevel(head, i, 0) << endl;
    }

    cout << endl;


    //Tells me if Orgtree::findNumOfManagersBetween is working
    if (Orgtree::findNumOfManagersBetween(head, 5, 6) == 1){ 
        cout << "You got it right!" << endl;
    } else {
        cout << "Yout got it wrong" << endl;
    }

    if (Orgtree::findNumOfManagersBetween(head, 5, 9) == 3){
        cout << "You got it right!" << endl;
    } else {
        cout << "Yout got it wrong" << endl;
    }

    if (Orgtree::findNumOfManagersBetween(head, 9, 5) == 3){
        cout << "You got it right!" << endl;
    } else {
        cout << "Yout got it wrong" << endl;
    }

    if (Orgtree::findNumOfManagersBetween(head, 11, 12) == 5){
        cout << "You got it right!" << endl;
    } else {
        cout << "Yout got it wrong" << endl;
    }

    if (Orgtree::findNumOfManagersBetween(head, 55, 99) == -1){
        cout << "You got it right!" << endl;
    } else {
        cout << "Yout got it wrong" << endl;
    }

    cout << endl;

    //Tells me if Orgtree::deleteOrgtree
    Orgtree::deleteOrgtree(head);

    cout << endl;

    //Tells me if Orgtree::findClosestSharedManager
    Employee* testClosestManager = Orgtree::findClosestSharedManager(head, 2, 3); //1
    cout << testClosestManager->getEmployeeID() << endl;

    Employee* testClosestManager2 = Orgtree::findClosestSharedManager(head, 10, 12); //1
    cout << testClosestManager2->getEmployeeID() << endl;

    Employee* testClosestManager3 = Orgtree::findClosestSharedManager(head, 7, 8); //3
    cout << testClosestManager3->getEmployeeID() << endl;

    Employee* testClosestManager4 = Orgtree::findClosestSharedManager(head, 6, 11); //6
    cout << testClosestManager4->getEmployeeID() << endl;

    Employee* testClosestManager5 = Orgtree::findClosestSharedManager(head, 8, 9); //1
    cout << testClosestManager5->getEmployeeID() << endl;

    Employee* testClosestManager7 = Orgtree::findClosestSharedManager(head, 8, 99); //return null
    if (testClosestManager7 == nullptr){
        cout << "This test passed" << endl;
    } else {
        cout << "This test failed" << endl;
    }

    Employee* testClosestManager11 = Orgtree::findClosestSharedManager(head, 88, 99); //return null
    if (testClosestManager11 == nullptr){
        cout << "This test passed" << endl;
    } else {
        cout << "This test failed" << endl;
    }

    cout << endl;

    /*
    *
    * My own tree #1 ~~~~~ the null tree
    * 
    * 
    */
    
    cout << "My Null Tree Starts Here";

    cout << endl;

    Employee *headNullTester = new Employee();  

    //Tells me if Orgtree::isEmployeePresentInOrg is working 
    if (Orgtree::isEmployeePresentInOrg(headNullTester, 1)){
        cout << "1 has been found " << endl; 
    } else {
        cout << "This tree is empty" << endl; //Return this if working
    }  

    //Tells me if Orgtree::findEmployeeLevel can find the levels of all the nodes
    vector<int> v1{ -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    for (int i = 0; i < v1.size(); i++) {
        cout << i << " is at level " << Orgtree::findEmployeeLevel(headNullTester, i, 0) << endl; //Return i is at level -1
    }

    //Tells me if Orgtree::findNumOfManagersBetween is working
    if (Orgtree::findNumOfManagersBetween(head, 5, 6) == 1){ 
        cout << "You got it right!" << endl;
    } else {
        cout << "This tree is empty" << endl; //Return this if correct
    }

    //Tells me if Orgtree::findClosestSharedManager
    Employee* testClosestManager10 = Orgtree::findClosestSharedManager(headNullTester, 2, 3); //1
    if (testClosestManager10 == nullptr){
        cout << "This test passed" << endl;
    } else {
        cout << "This test failed" << endl;
    }
    
    //Tells me if Orgtree::findNumOfManagersBetween is working
    if (Orgtree::findNumOfManagersBetween(head, 55, 99) == -1){
        cout << "You got it wrong" << endl;
    } else {
        cout << "You got it right!" << endl;
    }
    
}