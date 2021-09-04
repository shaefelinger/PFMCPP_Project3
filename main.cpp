 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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

struct ElectricGuitar
{
    // number of strings (int)
    int numberOfStrings = 6;
    // number of pickups (int)
    int numberOfPickups = 2;
    // color (std::string)
    std::string color = "blue";
    // age (int)
    int age = 12;
    // price (float)
    float price = 1299.99f;

    struct GuitarString
    {
        std::string manufacturer = "Ernie Ball";
        int number = 0;
        bool isWound = true;
        float width = 0.52f;
        std::string material = "steel";

        void breakString();
        void tune (float pitch);
        void pluck(int fret); 
    };

    // generate a Note
    void generateNote(GuitarString string, int fretPosition);
    // break a String
    void breakString(GuitarString stringNumber);
    // tune
    void tune(GuitarString stringNumber, float referencePitch); 

    GuitarString string; 
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
struct Computer
{
    // amount of ram (int) in gigabyte
    int amountOfRam = 64;
    // processor-speed (float)in GHz
    float processorSpeed = 2.4f;
    // size of disk (int) in terrabyte
    int sizeOfDisk = 4;
    // manufacturer (std::string)
    std::string manufacturer = "Apple";
    // operating system (std::string)
    std::string operatingSystem = "MacOS";

    struct Application
    {
        std::string name = "Logic Pro";
        std::string manufacturer = "Apple";
        std::string appType = "audio";
        float size = 1.1f;
        std::string version = "10.5";

        void start();
        void close();
        void install(std::string filePath);
    };

    // run program
    void runProgram(Application program, int priority);
    // shut down
    void shutDown();
    // erase disk
    void eraseDisk(std::string volumeName);

    Application application;
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
struct Bus
{
    // maximum speed (int)
    int maximumSpeed = 100;
    // number of seats (int)
    int numberOfSeets = 18;
    // manufacturer (std::string)
    std::string manufacturer = "MAN";
    // fuel consumption (float)
    float fuelConsumption = 20.3f;
    // color (std::string)

    // start engine
    void startEngine();
    // turn left
    void turnLeft(int angle);
    // open doors
    void openDoors(bool openAllDoors);
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

struct MobilePhone
{
    // size of memory (int)
    int sizeOfMemory = 2;
    // size of screen (int)
    int sizeOfScreen = 2;
    // manufacturer (std::string)
    std::string manufacturer = "Nokia";
    // type of camera (std::string)
    std::string typeOfCamera = "none";
    // year of manufacture (int)
    int yearOfManufacture = 1995;

    // send message
    void sendMessage(std::string message);
    // charge
    void charge(); 
    // update operating system
    bool updateOperatingSystem(float osVersion);
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

struct TvScreen
{
    // width (float)
    float width = 62.3f;
    // height (float)
    float height = 33.4f;
    // number of pixels (int)
    int numberOfPixels = 921600;
    // type (std::string)
    std::string type = "LED";
    // refresh rate (int)
    int refreshRate = 60;

    // display image
    void displayImage(std::string imgName = "defaultImage");
    // change brightness
    void changeBrightness(float brightness);
    // change contrast
    void changeContrast(float contrast);
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

struct TvRemoteControl
{
    // number of knobs (int)
    int numberOfKnobs = 22;
    // color (std::string)
    std::string color = "black";
    // type (std::string)
    std::string type = "infrared";
    // size (float)
    float size = 10.2f;
    // range (float)
    float range = 20.4f;

    // turn tv on
    void turnTvOn(int inputNumber = 0, int channelNumber = 1);
    // change channel
    void changeChannel(int channelNumber = 1);
    // change volume
    void changeVolume(float newVolume = 3.2f);
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

struct TvConnectors
{
    // number of hdmi-inputs (int)
    int numberHdmiInputs = 2;
    // number of heatphone-putputs (int)
    int numberHeadphoneOuts = 3;
    // type of digital-out (std::string)
    std::string digitalOutType = "spdif";
    // hasScartConnector (bool)
    bool hasScartConnector = false;
    // type of power connector (std::string)
    std::string powerConnectorType = "external";

    // output audio
    void outputAudio(float volume = 6.2f, int output = 2);
    // connect to antenna
    bool connectToAntenna();
    // connect to power
    bool connectToPower(int powerSocket = 0);
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

struct TvOnScreenMenu
{
    // size (float)
    float size = 10.4f;
    // number of menu-elements (int)
    int menuElements = 12;
    // color (std::string)
    std::string color = "gray";
    // number of languages (int)
    int numberOfLanguages = 9;
    // default language (std::string)
    std::string language = "english";

    // show Netflix 
    void showNetflix(std::string showTitle, int season, int episode);
    // show TV-Guide
    void showTVGuide(int week);
    // activate recording
    void activateRecoding(int channel);
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

struct TvManufacturer
{
    // name (float)
    std::string name = "SONY";
    // headquarters location (std::string)
    std::string headquartersLocation = "Japan";
    // founding year (int)
    int foundingYear = 1946;
    // name of founder (std::string)
    std::string founder = "Masaru Ibuka";
    // annual profit (float)
    float annualProfit = 1178.8f;

    // go bankrupt
    void goBankrupt(bool payAllDebts);
    // release new model
    bool releasNewModel(std::string modelName, float price);
    // buy rival company
    bool buyRivalCompany(std:: string company, float price);
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

struct Tv
{
    // screen 
    TvScreen screen;
    // remote control
    TvRemoteControl remoteControl;
    // connectors
    TvConnectors connectors;
    // on screen menu
    TvOnScreenMenu onScreenMenu;
    // manufacturer
    TvManufacturer manufacturer;

    // change channel
    void changeChannel(int channelNumber, bool useRemoteControl);
    // change volume
    void changeVolume(float newVolume, bool useRemoteControl);
    // activate smart tv
    void activateSmartTv(int menuItem = 0);
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
