/*
Kyaw Win
Project Characters
Character implementation for term Project 1
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include <cctype>

/**
      Default constructor.
      Default-initializes all private members. 
      Default character name: "NAMELESS". 
      Booleans are default-initialized to False. 
      Default enum value: NONE. 
      Default Vitality, Max Armor, and Level: 0.
   */

Character::Character(){
    name_ = "NAMELESS";   
    race_ = NONE;
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
    enemy_ = false;

}

/**
  Parameterized constructor.
  param      : The name of the character (a string in UPPERCASE)
  param      : The race of the character (a string)
  param      : The character's vitality (a non-negative integer) , with default  
                value 0
  param      : The character's max armor level (a non-negative integer), with 
                default value 0
  param      : The character's level (non-negative integer), with default value 0
  param      : A flag indicating whether the character is an enemy, with default 
                value false
  post       : The private members are set to the values of the corresponding 
                parameters.
  */


Character::Character(std::string Name, std::string race, int Vitality, int Armor, int Level, bool Enemy): 
name_{Name}, vitality_{Vitality}, armor_{Armor}, level_{Level}, enemy_{Enemy} {


    setName(Name);
    enemy_ = Enemy;
    setRace(race);
   
   if(Vitality >= 0) {    //checks if the vitality is negative
    vitality_ = Vitality;       //if the vitality is negative, then it is set to a 0 because it cannot be negative
   }

   else{
    vitality_ = 0;

   }

   if(Armor >= 0){      //checks if the Armor is negative
    armor_ = Armor;         //if the armor is positive, then it is set equal

   }

   else{
    armor_ = 0;

   }

   if(Level >= 0){     //checks if the level is negative

    level_ = Level;       //if the level is npositive, then it is set equal


   }

    else{
        level_ = 0;

   }

}

/**
            param  : the name of the Character
            post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
*/


void Character::setName(const std::string& Name){
    std::string empt = ""; //creates an empty string for later

    for(int i = 0; i < Name.length(); i++){  //loops through the parameters

        if(isalpha(Name[i])){  //checks if the value of the parameter is an alphabetical character
            empt += char(toupper(Name[i]));  //sets the empty string to the value of the parameter in uppercase and increment the value to the valid parameters


        }

    }
    
    if(empt == ""){     //checks if the given parameter does not have any valid alphabetical characters
        name_ = "NAMELESS"; //if the given value does not have any valid alphabetical characters, then it sets the name_ to be Nameless
    } 
    
    else {
        name_ = empt;  //otherwise it sets empt equal to name_


    }


}


/**
      @return : the name of the Character
  */


 
std::string Character::getName() const{
    return name_;   //returns the name of a character


}


/**
       param  : the race of the Character (a string)
       post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
  */


void Character::setRace(const std::string& race){
    if(race == "HUMAN"){     //checks if the race is valid
        race_ = HUMAN;      //if the race is valid, then it sets the character's race to the value of parameters 
    } 
    
    else if(race == "ELF"){
        race_ = ELF;

    } 
    
    else if(race == "DWARF"){
        race_ = DWARF;

    }

    else if(race == "LIZARD"){
        race_ = LIZARD;

    }

    else if(race == "UNDEAD"){
        race_ = UNDEAD;

    }

    else{
        race_ = NONE;  //if the race is invalid, then the race is set to be None
    }


}


/**
      return : the race of the Character (a string)
   */


std::string Character::getRace()const {
    if(race_ == NONE){  //checks if the race is valid or invalid
        return "NONE";  //if the race is invalid, then it returns none

    }
    
    else if(race_ == HUMAN){  //chekcs if the race is valid or invalid
        return "HUMAN";       //if the race is valid, then it returns the character
    }

    else if(race_ == ELF){  //chekcs if the race is valid or invalid
        return "ELF";      //if the race is valid, then it returns the character
    }

    else if(race_ == DWARF){     //chekcs if the race is valid or invalid
        return "DWARF";          //if the race is valid, then it returns the character

    }

    else if(race_ == LIZARD){    //chekcs if the race is valid or invalid
        return "LIZARD";        //if the race is valid, then it returns the character
    }

    else {    //checks if the race is valid or invalid
        return "UNDEAD";        //if the race is valid, then it returns the character
    }
}

/**
    param  : an integer vitality
    pre    : vitality >= 0 : Characters cannot have negative health
    post   : sets the vitality private member to the value of the parameter
              if vitality is negative, do nothing.
  */


void Character::setVitality(const int& Vitality){
    if(Vitality >= 0){          //chekcs if the vitality has a positive value
        vitality_ = Vitality;   //if the vitality is positive, then it sets the vitality private member to the value of the parameter


    }

}

/**
      @return : the value stored in vitality_
   */


int Character::getVitality()const {
    return vitality_;   //returns the value stored in vitality_


}

/**
    param  : an integer armor level
    pre    : armor >= 0 : Characters cannot have negative armor
    post   : sets the armor private member to the value of the parameter
              if armor is negative, do nothing.
  */



void Character::setArmor(const int& Armor){
    if(Armor >= 0){    //checks if the armor has a positive value
        armor_ = Armor;   //sets armor private member to the value of the parameter


    }


}

/**
      return : the value stored in armor_
   */



int Character::getArmor()const {
    return armor_;   //returns the value stored in armor_


}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
              if level is negative, do nothing.
  */



void Character::setLevel(const int& Level) {
    if(Level >= 0){   //checks if the the level is a positive value
        level_ = Level;   //sets level private memeber to the balue of the parameter


    }


}


/**
      return : the value stored in level_
   */



int Character::getLevel()const {
    return level_;    //returns the value stored in level_


}

/**
    return true if the character is an enemy, false otherwise

    Note: this is an accessor function and must follow the same convention as all accessor  
          functions even if it is not called getEnemy
   */

bool Character::isEnemy()const {
    return enemy_;


}


/**
   post   : sets the enemy flag to true
  */


void Character::setEnemy(){
    enemy_ = true;


}
