/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Nov 2022
 */

#include "connectedcities.h"

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
void asserts(bool didPass, string message) {
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
    
    // Begin Testing
    // A few sample testing code are provided below  
    
    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding required for assignment 4
    
    // IMPORTANT: You should construct at least one different city graph similar to the one above
    //
    // Also make sure to construct graphs for testing the edge cases, 
    // such as empty graph (NO node), one node graph, two nodes graph, etc.
    //My testing

    //Empty Graph
    vector<string> cities_4;
    vector<pair<string, string> > trainRoutes4;

    vector<CityNode> cities4 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_4, trainRoutes4);
    asserts(cities4.empty(), "First city should be Nothing");

    //One City
    vector<string> cities_3 {"SD"};
    vector<pair<string, string> > trainRoutes3;

    trainRoutes3.emplace_back("SD","SD");

    vector<CityNode> cities3 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3, trainRoutes3);
    asserts(cities3.at(0).getCity() == "SD", "First city should be SD");
    asserts(cities3.at(0).getReachableCities().size() == 1, "Train starting from city SD can reach 1 city");


    //Straight Line
    vector<string> cities_2 {"SD", "LA", "SK"};

    vector<pair<string, string> > trainRoutes2;

    trainRoutes2.emplace_back("SD", "LA");
    trainRoutes2.emplace_back("LA", "SK");
    
    vector<CityNode> cities2 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2, trainRoutes2);

    asserts(cities2.at(0).getCity() == "SD", "First city should be SD");
    for(int i = 0; i < cities2.at(0).getDirectRoutedCities().size(); i++){ //print stuff in getDirectRoutedCities
        cout << cities2.at(0).getDirectRoutedCities().at(i) << endl;
    }
        //DirectRouted should be LA
    asserts(cities2.at(0).getReachableCities().size() == 3, "Train starting from city SD can reach 3 cities");
    for(int i = 0; i < cities2.at(0).getReachableCities().size(); i++){ //print stuff in getReachableCities
        cout << cities2.at(0).getReachableCities().at(i) << endl;
    }
        //Reachable cities shoudl be SD, LA, SK

    asserts(cities2.at(1).getCity() == "LA", "Second city should be LA");
    for(int i = 0; i < cities2.at(1).getDirectRoutedCities().size(); i++){ //print stuff in getDirectRoutedCities
        cout << cities2.at(1).getDirectRoutedCities().at(i) << endl;
    }
        //DirectRouted should be SK
    asserts(cities2.at(1).getReachableCities().size() == 2, "Train starting from city LA can reach 2 cities");
    for(int i = 0; i < cities2.at(1).getReachableCities().size(); i++){ //print stuff in getReachableCities
        cout << cities2.at(1).getReachableCities().at(i) << endl;
    }
        //Reachable cities should be LA, SK

    asserts(cities2.at(2).getCity() == "SK", "Third city should be SK");
    for(int i = 0; i < cities2.at(2).getDirectRoutedCities().size(); i++){ //print stuff in getDirectRoutedCities
        cout << cities2.at(2).getDirectRoutedCities().at(i) << endl;
    }
        //DirectRouted should be nothing 
    asserts(cities2.at(2).getReachableCities().size() == 1, "Train starting from city SK can reach 1 city");
    for(int i = 0; i < cities2.at(2).getReachableCities().size(); i++){ //print stuff in getReachableCities
        cout << cities2.at(2).getReachableCities().at(i) << endl;
    }
        //Reachable cities should be SK



    //Shen's testing
    //cities returned from the above call are sorted according to 
    //the ascending order of the city names and 
    //the descending order of the size of reachableCities starting from those cities
    
     /* Construct a graph for testing
        *    SD ---> DL <--------         
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */

    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};

    vector<pair<string, string> > trainRoutes;

    //Graph that shen gives us
    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("SJ", "SK");

    trainRoutes.emplace_back("IV", "DL");
    
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");

    vector<CityNode> cities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1, trainRoutes);


    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities"); 
    
    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");
    
    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");
    
    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities");
    
    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from city JL can reach 4 cities");
    
    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from city BV can reach 3 cities");
        
    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");

    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from city OD can reach 3 cities");

    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from city BU can reach 1 city");

    

    cout << endl << "All test cases passed!" << endl;

    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}