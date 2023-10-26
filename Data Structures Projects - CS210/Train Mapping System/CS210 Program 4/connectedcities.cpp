#include "connectedcities.h"

/**
 * I the undersigned promise that the submitted assignment is my own work. While I was 
 * free to discuss ideas with others, the work contained is my own. I recognize that 
 * should this not be the case; I will be subject to penalties as outlined in the course 
 * syllabus. 
 * 
 * name: deanna omron
 * redID: 824834355
 * 
 */


/**
 * <p>
 * Part A 
 * ---------------------------------------------------------------------------------------
 * For each city in a city list, find the list of reachable cities starting from the city 
 * following the train routes, and sort the cities in the descending order based on the 
 * number of their reachable cities.  
 * 
 * Required specifications - 
 *
 * Given a list of cities, and a list of one-way train routes from one city to another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
 *    cities starting from the city following the train routes and store those reachable cities to 
 *    the CityNode's reachableCities collection. 
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.  
 *
 *    Note: The train route can go from the starting city and stop at several cities 
 *          before reaching the destination city, all cities including the starting city and 
 *          the destination city along the path would be counted as reachable cities from 
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the train can 
 *    reach the greatest number of destination cities following the given one-way routes. 
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
 *    all reachable cities from a starting city given the train routes, using an iterative 
 *    approach would result in a 30% penalty to your assignment 4 grade.  
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for hints.
 * 
 * Assumptions - 
 * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example, 
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
 *    Los Angeles (LA). 
 *
 * <p>
 * Part B
 * ---------------------------------------------------------------------------------------
 * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 * 
 * ---------------------------------------------------------------------------------------
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route represented 
 *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }   
 *                       refer to driver.cpp for more examples.  
 *
 * @return       A list of CityNode in the descending order based on the number of their 
 *               reachable cities following the train routes
 
* @see         
*/

// Follow the steps in the specification above to implement. 

  // You may want to implement each step in the above specification in 
  // a separate function.

  // Think what would be a good data structure to store the City Graph.
  // Each node/vertice represents a city and each has an adjacent list of cities
  // that can be reached directly from the city.
  // You can use a STL collection to store
  // the graph of city nodes, so that given a city code,
  // you can find the corresponding CityNode object instantaneously.
  // Think Which data structure would give you the best lookup ability
  // by using a key. 

  // Hint for DFS:
  // You may want to use a separate function to implement the 
  // recursive Depth-First-Search algorithm for finding all reachable cities
  // starting from a city using its direct routes to other cities, and their
  // connected cities, and so on and so forth until all cities along
  // reachable paths are traversed.

  // Use the general approach described in zyBook 20.6 Graphs: Depth-first search
  // Follow what Figure 20.6.1 presents

  // A suggested separate recursive function for the DFS part could be:
  // void depthFirstSearchReachableCities(
  //      cityGraph, // a collection of a STL collection type  
  //      string startingCity, 
  //      vector<string> &reachableCities, // list of cities to add reachable cities along the recursive call  
  //      set<string> &visitedCities); // list of cities to track if a city is already visited along DFS search
  // what would be the base condition? --> the startingCity is already visited

  // Hint for sorting:
  // you can leverage the std::sort  


void ConnectedCities::populateReachableCitiesDFS(unordered_map<string, CityNode> cityGraph, string startingCity,vector<string> &reachableCity, vector<string> &visited ){
   
    auto search = cityGraph.find(startingCity); //Searches Graph Collection for starting city
    
    //Searches for startingCity in visited to see if we have been there already
    vector<string>::iterator itr;
    itr = find(visited.begin(), visited.end(), startingCity);
  
    //Base Case: If startingCity has been visited, stop recursion 
    if (itr != visited.end()){ 
      return;
    } 

    //If startingcity is in Graph Collection then
    // 1. Add startingCity to visited & reachableCity
    // 2. Get DirectRoutedCity of startingCity
    // 3. Iterate through each DirectRoutedCity to see if they are reachable from startingCity
    if(search != cityGraph.end()) {
      visited.push_back(startingCity);
      reachableCity.push_back(startingCity);

      CityNode c = search->second;
      c.getDirectRoutedCities();

      for (int i = 0; i < c.getDirectRoutedCities().size(); i++ ){
        populateReachableCitiesDFS(cityGraph, c.getDirectRoutedCities().at(i), reachableCity, visited);
      }

      
    }
    
}


//sorts in ascending order by alphabetical order
bool ConnectedCities::compareByCityCode(CityNode city1, CityNode city2){ 
  return city1.getCity() < city2.getCity();
}

//sorts in descending order by number of reachable cities
bool ConnectedCities::compareByNumberOfReachableCities(CityNode city1, CityNode city2){ 
  return city1.getReachableCities().size() > city2.getReachableCities().size();
}

vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(
                                    vector<string> cities, 
                                    vector< pair<string, string> > trainRoutes) {
                                        
  // Write your implementation here.

  //Checks if the graph recieved was empty 
  //Returns an empty graph 
  if (cities.empty()){
    vector<CityNode> empty;
    return empty;
  }

  unordered_map<string, CityNode> allCities2; //Graph Collection
  vector<string> visitedNode = vector<string>(); //vector of visited nodes for dfs search
  vector<string> reachableCities = vector<string>(); //vector of cities that are one edge away from starting city
  vector<CityNode> returnedGraph = vector<CityNode>(); //Graph Collection as a vector to be returned
  string startingCity; 
  

  //creates new CityNodes, gives them names, & adds each node to a vector of allCities2
  for (int i = 0; i < cities.size(); i++){ 
        CityNode newCity = CityNode(cities.at(i));
        allCities2.emplace(cities.at(i), newCity);
  }

  //Populates each CityNode with Directly Routed Cities from trainRoutes
  for (int i = 0; i < cities.size(); i++){
    for (int j = 0; j < trainRoutes.size(); j++){
      if (allCities2.at(cities.at(i)).getCity() == trainRoutes.at(j).first){
        allCities2.at(cities.at(i)).addADirectRoutedCity(trainRoutes.at(j).second);
      }
    }
  }

  //Populates each CityNode with Reachable Cities from DirectRoutedCity
  for (int k = 0; k < cities.size(); k++){
   
      populateReachableCitiesDFS(allCities2, allCities2.at(cities.at(k)).getCity(), reachableCities, visitedNode);
      allCities2.at(cities.at(k)).setReachableCities(reachableCities); //Adds all reachable cities to CityNode
      visitedNode.clear(); 
      reachableCities.clear();

  }

  //Put every CityNode from unordered_map allCities2 to vector returnedGraph 
  for (auto i : allCities2){
    returnedGraph.push_back(i.second);
  }

  stable_sort(returnedGraph.begin(), returnedGraph.end(), compareByCityCode); //Sorts in alphabetical order ascending
  stable_sort(returnedGraph.begin(), returnedGraph.end(), compareByNumberOfReachableCities); //Sorts by number of reachable cities descending
  
  return returnedGraph; 
}



