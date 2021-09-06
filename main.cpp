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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
  
    void run(bool startWithLeftFoot);

    struct Foot
    {
        int stepSize()
        {
            return 2;
        }

        void stepForward()
        {
            //
        }
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::run(bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
        std::cout << "started running with the left foot" << std::endl;
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
        std::cout << "started running with the right foot" << std::endl;
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();      
}

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


// ============================================================
struct ElectricGuitar
{
    int numberOfStrings = 6;
    int numberOfPickups = 2;
    std::string color = "blue";
    std::string name = "Telecaster";
    float price = 1299.99f;

    struct GuitarString
    {
        std::string manufacturer = "Ernie Ball";
        int number = 1;
        bool isWound = true;
        float width = 0.52f;
        std::string material = "steel";

        void breakString();
        void tuneString (float referencePitch);
        void pluckString(int fret); 
    };

    void plugIn(std::string cableColor);
    void selectPickup(int pickup);
    void changeVolume(float volume);

    GuitarString string1; 
};

void ElectricGuitar::plugIn(std::string cableColor)
{
    std::cout << "You have plugged in the " << cableColor << " cable into the " << ElectricGuitar::color <<  " " << ElectricGuitar::name <<std::endl;
}

void ElectricGuitar::selectPickup(int pickup)
{
    std::cout << "Switched to pickup " << pickup << std::endl;
}

void ElectricGuitar::changeVolume(float volume)
{
    std::cout << "Changed Volume of " << ElectricGuitar::name <<" to " << volume << std::endl;
}

void ElectricGuitar::GuitarString::breakString()
{
    std::cout << "String " << ElectricGuitar::GuitarString::number << " just broke!! ";
    if (ElectricGuitar::GuitarString::isWound)
    {
        std::cout << "This is a wound string - how did that happen??" << std::endl;;
    }
    else  
    {
        std::cout << std::endl;
    }
}

void ElectricGuitar::GuitarString::tuneString(float referencePitch)
{
    std::cout << "String " << ElectricGuitar::GuitarString::number << " is tuned @ " << referencePitch << " Hz" <<std::endl;
}

void ElectricGuitar::GuitarString::pluckString(int fret)
{
    std::cout << "Plucked String " << ElectricGuitar::GuitarString::number << " / fret " << fret << std::endl;
}

// ============================================================
struct Computer
{
    int amountOfRam = 64;
    float processorSpeed = 2.4f;
    int sizeOfDisk = 4;
    std::string manufacturer = "Apple";
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

    void runProgram(std::string program, int priority);
    void shutDown();
    void eraseDisk(std::string volumeName);

    Application logicPro;
};

void Computer::runProgram(std::string program, int priority)
{
    std::cout << "Running " << program << " with priority " << priority << std::endl;
}

void Computer::shutDown()
{
    std::cout << "Computer shut down!" << std::endl;
}

void Computer::eraseDisk(std::string volumeName)
{
    std::cout << "Erased Disk " << volumeName << std::endl;
}

void Computer::Application::start()
{
    std::cout << Computer::Application::name << " started" << std::endl;
}

void Computer::Application::close()
{
    std::cout << Computer::Application::name << " closed" << std::endl;
}

void Computer::Application::install(std::string filePath)
{
    std::cout << Computer::Application::name << " installed on " << filePath << std::endl;
}
// ============================================================

struct Bus
{
    int maximumSpeed = 100;
    int numberOfSeets = 18;
    std::string manufacturer = "MAN";
    float fuelConsumption = 20.3f;

    void startEngine();
    void turnLeft(int angle);
    void openDoors(bool openAllDoors);
};

void Bus::startEngine()
{
    std::cout << "Engine of Bus started" << std::endl;
}

void Bus::turnLeft(int angle)
{
    std::cout << "Turned left " << angle << " degrees" << std::endl;
}

void Bus::openDoors(bool openAllDoors)
{
    if(openAllDoors)
    {
        std::cout << "Opened all doors" << std::endl;
    }
    else 
    {
        std::cout << "Opened a single door" << std::endl;
    }
}
// ============================================================

struct MobilePhone
{
    int sizeOfMemory = 2;
    int sizeOfScreen = 2;
    std::string manufacturer = "Nokia";
    std::string typeOfCamera = "none";
    int yearOfManufacture = 1995;

    void sendMessage(std::string message);
    void charge(); 
    bool updateOperatingSystem(float osVersion);
};

void MobilePhone::sendMessage(std::string message)
{
    std::cout << "Message sent: " << message << std::endl;
}

void MobilePhone::charge()
{
    std::cout << "Phone is charged!" << std::endl;
}

bool MobilePhone::updateOperatingSystem(float osVersion)
{
    std::cout << "Updated Operating System to Version " << osVersion << std::endl;
    return true;
}
// ============================================================

struct TvScreen
{
    float width = 62.3f;
    float height = 33.4f;
    int numberOfPixels = 921600;
    std::string type = "LED";
    int refreshRate = 60;

    void displayImage(std::string imgName = "defaultImage");
    void changeBrightness(float brightness);
    void changeContrast(float contrast);
}; 

void TvScreen::displayImage(std::string imgName)
{
    std::cout << "Displaying Image: " << imgName << std::endl;
}

void TvScreen::changeBrightness(float brightness)
{
    std::cout << "Changed brightness to: " << brightness << std::endl;
}

void TvScreen::changeContrast(float contrast)
{
    std::cout << "Changed contrast to: " << contrast << std::endl;
}
// ============================================================

struct TvRemoteControl
{
    int numberOfKnobs = 22;
    std::string color = "black";
    std::string type = "infrared";
    float size = 10.2f;
    float range = 20.4f;

    void turnTvOn(int inputNumber = 0, int channelNumber = 1);
    void changeChannel(int channelNumber = 1);
    void changeVolume(float newVolume);
};

void TvRemoteControl::turnTvOn(int inputNumber, int channelNumber)
{
    std::cout << "TV is on. Input " << inputNumber << " / Channel " << channelNumber << std::endl;
}

void TvRemoteControl::changeChannel(int channelNumber)
{
    std::cout << "Changed to channel " << channelNumber << std::endl;
}

void TvRemoteControl::changeVolume(float newVolume = 3.2f)
{
    std::cout << "Changed volume to " << newVolume << std:: endl;
}
// ============================================================

struct TvConnectors
{
    int numberHdmiInputs = 2;
    int numberHeadphoneOuts = 3;
    std::string digitalOutType = "spdif";
    bool hasScartConnector = false;
    std::string powerConnectorType = "external";

    void outputAudio(float volume = 6.2f, int output = 2);
    bool connectToAntenna();
    bool connectToPower(int powerSocket = 1);
};

void TvConnectors::outputAudio(float volume, int output)
{
    std::cout << "Audio Output " << output << " running. Volume: " << volume << std::endl;
}

bool TvConnectors::connectToAntenna()
{
    std::cout << "Connected to Antenna" << std::endl;
    return true;
}

bool TvConnectors::connectToPower(int powerSocket)
{
    std::cout << "Connection to power socket " << powerSocket << " failed" << std::endl;
    return false;
}
// ============================================================

struct TvOnScreenMenu
{
    float size = 10.4f;
    int menuElements = 12;
    std::string color = "gray";
    int numberOfLanguages = 9;
    std::string language = "english";

    void showNetflix(std::string showTitle, int season, int episode);
    void showTVGuide(int week);
    void activateRecoding(int channel);
};

void TvOnScreenMenu::showNetflix(std::string showTitle, int season, int episode)
{
    std::cout << "Showing " << showTitle << " - Season " << season << " - Episode " << episode << std::endl;
}

void TvOnScreenMenu::showTVGuide(int week)
{
    std::cout << "Displaying TV-Guide for week " << week << std::endl;
}

void TvOnScreenMenu::activateRecoding(int channel)
{
    std::cout << "Recoding Channel " << channel << std::endl;
}
// ============================================================

struct TvManufacturer
{
    std::string name = "SONY";
    std::string headquartersLocation = "Japan";
    int foundingYear = 1946;
    std::string founder = "Masaru Ibuka";
    float annualProfit = 1178.8f;

    void goBankrupt(bool payAllDebts);
    bool releasNewModel(std::string modelName, float price);
    bool buyRivalCompany(std:: string company, float price);
};

void TvManufacturer::goBankrupt(bool payAllDebts)
{
    std::cout << "Sorry - we're bankrup!! " ;
    if (payAllDebts)
    {
        std::cout << "But we will pay our debts!" << std::endl;
    } 
    else
    {
        std::cout << "And we will not pay our debts!" << std::endl;
    }
}

bool TvManufacturer::releasNewModel(std::string modelName, float price)
{
    std::cout << "We have just released the new " << modelName << " for only " << price << std::endl;
    return true;
}

bool TvManufacturer::buyRivalCompany(std:: string company, float price)
{
    std::cout << TvManufacturer::name << " has just bought " << company << " for $" << price  << std::endl;
    return true;
}
// ============================================================

struct Tv
{
    TvScreen screen;
    TvRemoteControl remoteControl;
    TvConnectors connectors;
    TvOnScreenMenu onScreenMenu;
    TvManufacturer manufacturer;

    void changeChannel(int channelNumber, bool useRemoteControl);
    void changeVolume(float newVolume, bool useRemoteControl);
    void activateSmartTv(int menuItem = 0);
};

void Tv::changeChannel(int channelNumber, bool useRemoteControl)
{
    if (useRemoteControl)
    {
        channelNumber++;
    }
}

void Tv::changeVolume(float newVolume, bool useRemoteControl)
{
    newVolume = 3.3f;
    useRemoteControl = false;
}

void Tv::activateSmartTv(int menuItem)
{
    menuItem++;
}

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
    Person runner;
    runner.run(false);
    std::cout << "============================================================" << std::endl;

    ElectricGuitar telecaster;
    telecaster.plugIn("green");
    telecaster.selectPickup(1);
    telecaster.changeVolume(9.9f);
    telecaster.string1.breakString();
    telecaster.string1.tuneString(442.2f);
    telecaster.string1.pluckString(12);
    std::cout << "============================================================" << std::endl;

    Computer macbook;
    macbook.runProgram("Ableton", 10);
    macbook.shutDown();
    macbook.eraseDisk("Macintosh HD");
    macbook.logicPro.start();
    macbook.logicPro.close();
    macbook.logicPro.install("Macintosh HD");
    std::cout << "============================================================" << std::endl;

    Bus schoolBus;
    schoolBus.startEngine();
    schoolBus.turnLeft(30);
    schoolBus.openDoors(true);
    std::cout << "============================================================" << std::endl;

    MobilePhone iPhone;
    iPhone.sendMessage("Hey !!");
    iPhone.charge(); 
    iPhone.updateOperatingSystem(11.2f);
    std::cout << "============================================================" << std::endl;

    TvScreen samsungScreen;
    samsungScreen.displayImage("Funny cat");
    samsungScreen.changeBrightness(12.3f);
    samsungScreen.changeContrast(22.43f);
    std::cout << "============================================================" << std::endl;

    TvRemoteControl samsungRemote;
    samsungRemote.turnTvOn();
    samsungRemote.changeChannel(4);
    samsungRemote.changeVolume(11.2f);
    std::cout << "============================================================" << std::endl;

    TvConnectors samsungConnectors;
    samsungConnectors.connectToPower();
    samsungConnectors.connectToAntenna();
    samsungConnectors.outputAudio(8.8f, 1);
    std::cout << "============================================================" << std::endl;

    TvOnScreenMenu samsungMenu;
    samsungMenu.showNetflix("Breaking Bad", 3, 4);
    samsungMenu.showTVGuide(22);
    samsungMenu.activateRecoding(12); 
    std::cout << "============================================================" << std::endl;

    TvManufacturer sony;
    sony.goBankrupt(true);
    sony.releasNewModel("TV2000x", 1299.99f);
    sony.buyRivalCompany("LG", 1.99f);
    std::cout << "============================================================" << std::endl;



    std::cout << "good to go!" << std::endl;
}
