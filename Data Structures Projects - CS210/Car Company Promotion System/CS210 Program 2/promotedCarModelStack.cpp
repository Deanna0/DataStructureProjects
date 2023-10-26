#include "promotedCarModelStack.h"

/**
 * I the undersigned promise that the submitted assignment is my own work. While I was 
 * free to discuss ideas with others, the work contained is my own. I recognize that 
 * should this not be the case; I will be subject to penalties as outlined in the course 
 * syllabus.
 * 
 * Name: Deanna Omron
 * RedID: 824834355
 * 
 */


/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push(string model, int price) {
  
  //Checks to see if carNameAndPrice vector is empty & creates car, maxMode, & minModel objects to be inserted into their respective vectors
  if (carNameAndPrice.empty()){
    car = PromotedModel(model, price);
    maxModel = PromotedModel(model, price);
    minModel = PromotedModel(model, price);

    carNameAndPrice.push_back(car); 
    highestAndLowestPrice.push_back(maxModel); 
    highestAndLowestPrice.push_back(minModel); 
  } 

  /*
  * If passed in price is greater than maxModel's price, create a new PromotedModel car &
  * replace maxModel with new price 
  * 
  * Input car into carNameAndPrice along with the new price for highestAndLowestPrice
  */
  if (price > maxModel.getPromotedPrice()){
    car = PromotedModel(model, price);
    carNameAndPrice.push_back(car);
    maxModel = PromotedModel(model, price);
    highestAndLowestPrice.push_back(maxModel);  
    highestAndLowestPrice.push_back(minModel);  
  }

 /*
  * If passed in price is less than minModel's price, create a new PromotedModel car &
  * replace minModel with new price 
  * 
  * Input car into carNameAndPrice along with the new price for highestAndLowestPrice
  */
  if (price < minModel.getPromotedPrice()){
    car = PromotedModel(model, price);
    carNameAndPrice.push_back(car);
    minModel = PromotedModel(model, price);
    highestAndLowestPrice.push_back(maxModel); 
    highestAndLowestPrice.push_back(minModel); 
  }

  /*
  * If the price is not greater or less than the min/maxModel then create PromotedModel car, 
  * input that into carNameAndPrice along with the same min/maxModels into highestAndLowestPrice
  */
  if(!(price >= maxModel.getPromotedPrice()) && !(price <= minModel.getPromotedPrice())){
    car = PromotedModel(model, price);
    carNameAndPrice.push_back(car);
    highestAndLowestPrice.push_back(maxModel); 
    highestAndLowestPrice.push_back(minModel);
  }


}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
   
  //Makes sure the carNameAndPrice vector isn't empty
  if (carNameAndPrice.empty()){
    throw std::logic_error("Promoted car model stack is empty");
  }
  
  //stores last item of carNameAndPrice vector for use 
  topOfCarStack = carNameAndPrice.back();

  //Checks to see if the last PromotedModel object in carNameAndPrice matches both the max & min prices
  //Finds and saves the next min and max prices
  if ((topOfCarStack.getPromotedPrice() == maxModel.getPromotedPrice()) && (topOfCarStack.getPromotedPrice() == minModel.getPromotedPrice())){
    poppedItem = carNameAndPrice.back();
    carNameAndPrice.pop_back();
    highestAndLowestPrice.pop_back();
    highestAndLowestPrice.pop_back();

    minModel = highestAndLowestPrice.back();
    maxModel = highestAndLowestPrice.at(highestAndLowestPrice.size() - 2);
  } else {
    
    //Checks to see if the last object just matches the min price & pops one item from carNameAndPrice while two for highestAndLowestPrice
    //Finds and saves the next min price
    if (topOfCarStack.getPromotedPrice() == minModel.getPromotedPrice()){ 
      poppedItem = carNameAndPrice.back();
      carNameAndPrice.pop_back();
      highestAndLowestPrice.pop_back();
      highestAndLowestPrice.pop_back();

      minModel = highestAndLowestPrice.back();
    } 

    //Checks to see if the last object just matches the max price & pops one item from carNameAndPrice while two for highestAndLowestPrice
    //Finds and saves the next max price
    if (topOfCarStack.getPromotedPrice() == maxModel.getPromotedPrice()) {
      poppedItem = carNameAndPrice.back();
      carNameAndPrice.pop_back();
      highestAndLowestPrice.pop_back();
      highestAndLowestPrice.pop_back();

      maxModel = highestAndLowestPrice.at(highestAndLowestPrice.size() - 2);
    }

  } 

  //Checks to see if the last object matches neither the max or the min prices & pops one item from carNameAndPrice while two for highestAndLowestPrice
  if (!(topOfCarStack.getPromotedPrice() == maxModel.getPromotedPrice()) && !(topOfCarStack.getPromotedPrice() == minModel.getPromotedPrice())){
    poppedItem = carNameAndPrice.back();
    carNameAndPrice.pop_back();
    highestAndLowestPrice.pop_back();
    highestAndLowestPrice.pop_back();
  }  
  

  return poppedItem;
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
  
  //Checks to see if carNameAndPrice vector is empty
  if (carNameAndPrice.empty()){
    throw std::logic_error("Promoted car model stack is empty");
  }

  return carNameAndPrice.back();
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return maxModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {

 //Checks to see if carNameAndPrice vector is empty
 if (carNameAndPrice.empty()){
    throw std::logic_error("Promoted car model stack is empty");
  }

 return maxModel;
}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return minModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
  
  //Checks to see if carNameAndPrice vector is empty
  if (carNameAndPrice.empty()){
    throw std::logic_error("Promoted car model stack is empty");
  }

  return minModel;
}