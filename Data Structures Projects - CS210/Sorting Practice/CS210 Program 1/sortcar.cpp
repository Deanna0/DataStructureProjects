#include "sortcar.h"

/**
 * @brief sort car inventory
 * 
 * @param carInventory      input car inventory array
 * @param promotionOrder    car promotion order
 * @return vector<string>   sorted car inventory according to the car promotion order
 * 
 * Time complexity has to be linear: O(N), N is the size/length of the input car inventory array
 * Space complexity has to be constant: O(1), hint: sorting can be done by mutating 
 *                                      the input car inventory array.
 */

/**
 * I the undersigned promise that the submitted assignment is my own work.
 * While I was free to discuss ideas with others, the work contained is my own.
 * I recognized that should this not be the case; I will be subjected to penaliteis as outlined
 * in the course syllabus.
 *
 * Name: deanna omron
 * redID: 824834355
 */
vector<string> SortCar::sortCarInventory(vector<string> carInventory, vector<string> promotionOrder) {


    int j = 0; //Keeps an overall counter for the car inventory when sorting

    //Outer loop individually compares promotionOrder to each index in carInventory
    for (unsigned long i = 0; i < (promotionOrder.size() - 1); i++){


        //If promotionOrder matches carInventory increment to the next element in carInventory
        if (promotionOrder.at(i) == carInventory.at(j)){
            if (j < (carInventory.size() - 1)){
                j++;
            }
        }

        //If promotionOrder does not match carInventory at a particular index
        if (!(promotionOrder.at(i) == carInventory.at(j))){

            //Runs from index j onwards through the rest of carInvetory & compares elements to promotionOrder
            for (int k = j; k <= (carInventory.size() - 1); k++){
                string temp = carInventory.at(j); //Record the not matching element in carInventory

                if (promotionOrder.at(i) == carInventory.at(k)){ //If match is found swap elements in j & k
                    carInventory.at(j) = carInventory.at(k);
                    carInventory.at(k) = temp;

                    j++; //Increment to next index in carInventory
                }
            }
        }
    }

        return carInventory;
}

  
