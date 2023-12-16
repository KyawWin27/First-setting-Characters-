/*Kyaw Win
Project 
Character interface for term Project 
Sep 08, 2023
*/

#include <iostream>
#include <string>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP




enum Race{NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character{
    public:

    /**
      Default constructor.
      Default-initializes all private members. 
      Default character name: "NAMELESS". 
      Booleans are default-initialized to False. 
      Default enum value: NONE. 
      Default Vitality, Max Armor, and Level: 0.
   */

    Character();
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

    Character(std::string Name, std::string race, int Vitality= 0, int Armor= 0, int Level= 0, bool Enemy= false);

    /**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
*/

    void setName(const std::string& Name);

    /**
       param  : the race of the Character (a string)
       post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
  */

    void setRace(const std::string& race);

    /**
    param  : an integer vitality
    pre    : vitality >= 0 : Characters cannot have negative health
    post   : sets the vitality private member to the value of the parameter
              if vitality is negative, do nothing.
  */

    void setVitality(const int& Vitality);


    /**
    param  : an integer armor level
    pre    : armor >= 0 : Characters cannot have negative armor
    post   : sets the armor private member to the value of the parameter
              if armor is negative, do nothing.
  */


    void setArmor(const int& Armor);

    /**
    param  : an integer level
    pre    : level >= 0 : Characters cannot have a negative
    post   : sets the level private member to the value of the parameter
              if level is negative, do nothing.
  */


    void setLevel(const int& Level);


    /**
   post   : sets the enemy flag to true
  */

    void setEnemy();

    /**
      return : the name of the Character
  */

    std::string getName() const;

    /**
      return : the race of the Character (a string)
   */

    std::string getRace() const;

    /**
      return : the value stored in vitality_
   */


    int getVitality() const;

    /**
      return : the value stored in armor_
   */


    int getArmor() const;


/**
      return : the value stored in level_
   */



    int getLevel() const;
    bool isEnemy() const;
    
    private:
    std::string name_;
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;


};

#endif
