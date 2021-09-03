/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car car); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car car);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};








/*
Thing 1) electric Guitar
5 properties:
    1) number of strings (int)
    2) number of pickups (int)
    3) color (std::string)
    4) age (int)
    5) price (float)
3 things it can do:
    1) generate a Note
    2) break a String
    3) tune
 */

struct electricGuitar
{
    // number of strings (int)
    // number of pickups (int)
    // color (std::string)
    // age (int)
    // price (float)

    // generate a Note
    // break a String
    // tune
};

/*
Thing 2) computer
5 properties:
    1) amount of ram (int)
    2) processor-speed (float)
    3) size of disk (int)
    4) manufacturer (std::string)
    5) operating system (std::string)
3 things it can do:
    1) run program
    2) shut down
    3) erase disk
 */
struct computer
{
    // amount of ram (int)
    // processor-speed (float)
    // size of disk (int)
    // manufacturer (std::string)
    // operating system (std::string)

    // run program
    // shut down
    // erase disk
};

/*
Thing 3) bus
5 properties:
    1) maximum speed (int)
    2) number of seats (int)
    3) manufacturer (std::string)
    4) fuel consumption (float)
    5) color (std::string)
3 things it can do:
    1) start engine
    2) turn left
    3) open doors
 */
struct bus
{
    // maximum speed (int)
    // number of seats (int)
    // manufacturer (std::string)
    // fuel consumption (float)
    // color (std::string)

    // start engine
    // turn left
    // open doors
};

/*
Thing 4) mobile phone
5 properties:
    1) size of memory (int)
    2) size of screen (int)
    3) manufacturer (std::string)
    4) type of camera (std::string)
    5) year of manufacture (int)
3 things it can do:
    1) send message
    2) charge
    3) update operating system
 */

struct mobilePhone
{
    // size of memory (int)
    // size of screen (int)
    // manufacturer (std::string)
    // type of camera (std::string)
    // year of manufacture (int)

    // send message
    // charge
    // update operating system
};

/*
Thing 5) screen
5 properties:
    1) width (float)
    2) height (height)
    3) number of pixels (int)
    4) type (std::string)
    5) refresh rate (int)
3 things it can do:
    1) display image
    2) change brightness
    3) change contrast
 */

struct tvScreen
{
    // width (float)
    // height (height)
    // number of pixels (int)
    // type (std::string)
    // refresh rate (int)

    // display image
    // change brightness
    // change contrast
}; 

/*
Thing 6) remote control
5 properties:
    1) number of knobs (int)
    2) color (std::string)
    3) type (std::string)
    4) size (float)
    5) range (float)
3 things it can do:
    1) turn tv on
    2) change channel
    3) change volume
 */

struct tvRemoteControl
{
    // number of knobs (int)
    // color (std::string)
    // type (std::string)
    // size (float)
    // range (float)

    // turn tv on
    // change channel
    // change volume
};
/*
Thing 7) connectors
5 properties:
    1) number of hdmi-inputs (int)
    2) number of heatphone-putputs (int)
    3) type of digital-out (std::string)
    4) hasScartConnector (bool)
    5) type of power connector (std::string)
3 things it can do:
    1) output audio
    2) connect to antenna
    3) connect to power
 */

struct tvConnectors
{
    // number of hdmi-inputs (int)
    // number of heatphone-putputs (int)
    // type of digital-out (std::string)
    // hasScartConnector (bool)
    // type of power connector (std::string)

    // output audio
    // connect to antenna
    // connect to power
};

/*
Thing 8) on screen menu
5 properties:
    1) size (float)
    2) number of menu-elements (int)
    3) color (std::string)
    4) number of languages (int)
    5) default language (std::string)
3 things it can do:
    1) show Netflix 
    2) show TV-Guide
    3) activate recording
 */

struct tvOnScreenMenu
{
    // size (float)
    // number of menu-elements (int)
    // color (std::string)
    // number of languages (int)
    // default language (std::string)

    // show Netflix 
    // show TV-Guide
    // activate recording
};

/*
Thing 9)
5 properties: manufacturer
    1) name (float)
    2) headquarters location (std::string)
    3) founding year (int)
    4) name of founder (std::string)
    5) annual profit (float)
3 things it can do:
    1) go bankrupt
    2) release new model
    3) buy rival company
 */ 

struct tvManufacturer
{
    // name (float)
    // headquarters location (std::string)
    // founding year (int)
    // name of founder (std::string)
    // annual profit (float)

    // go bankrupt
    // release new model
    // buy rival company
};

/*
Thing 10) tv
5 properties:
    1) screen 
    2) remote control
    3) connectors
    4) on screen menu
    5) manufacturer
3 things it can do:
    1) change channel
    2) change volume
    3) activate smart tv
 */

struct tv
{
    // screen 
    // remote control
    // connectors
    // on screen menu
    // manufacturer

    // change channel
    // change volume
    // activate smart tv
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
