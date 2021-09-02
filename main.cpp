/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/







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
