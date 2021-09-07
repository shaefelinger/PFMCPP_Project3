/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





// ============================================================
struct ElectricGuitar
{
    ElectricGuitar();
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

ElectricGuitar::ElectricGuitar()
{
    std::cout << "CONSTRUCTING ElectricGuitar" << std::endl;
}

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
    std::cout << "String " << ElectricGuitar::GuitarString::number << " is tuned to " << referencePitch << " Hz" <<std::endl;
}

void ElectricGuitar::GuitarString::pluckString(int fret)
{
    std::cout << "Plucked String " << ElectricGuitar::GuitarString::number << " / fret " << fret << std::endl;
}

// ============================================================
struct Computer
{
    Computer();
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

Computer::Computer()
{
    std::cout << "CONSTRUCTING Computer" << std::endl;
}

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
    Bus();
    int maximumSpeed = 100;
    int numberOfSeats = 18;
    std::string manufacturer = "MAN";
    float fuelConsumption = 20.3f;

    void startEngine();
    void turnLeft(int angle);
    void openDoors(bool openAllDoors);
};

Bus::Bus()
{
    std::cout << "CONSTRUCTING Bus" << std::endl;
}

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
    MobilePhone();
    int sizeOfMemory = 2;
    int sizeOfScreen = 2;
    std::string manufacturer = "Nokia";
    std::string typeOfCamera = "none";
    int yearOfManufacture = 1995;

    void sendMessage(std::string message);
    void charge(); 
    bool updateOperatingSystem(float osVersion);
};

MobilePhone::MobilePhone()
{
    std::cout << "CONSTRUCTING MobilePhone" << std::endl;
}

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
    TvScreen();
    float width = 62.3f;
    float height = 33.4f;
    int numberOfPixels = 921600;
    std::string type = "LED";
    int refreshRate = 60;

    std::string displayImage(std::string imgName = "defaultImage");
    void changeBrightness(float brightness);
    void changeContrast(float contrast);
}; 

TvScreen::TvScreen()
{
    std::cout << "CONSTRUCTING TvScreen" << std::endl;
}

std::string TvScreen::displayImage(std::string imgName)
{
    std::cout << "Displaying Image: " << imgName << std::endl;
    return "This is a message from the TV-Screen: I'm now showing the Image: " + imgName;
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
    TvRemoteControl();
    int numberOfKnobs = 22;
    std::string color = "black";
    std::string type = "infrared";
    float size = 10.2f;
    float range = 20.4f;

    void turnTvOn(int inputNumber = 0, int channelNumber = 1);
    void changeChannel(int channelNumber = 1);
    void changeVolume(float newVolume);
};

TvRemoteControl::TvRemoteControl()
{
    std::cout << "CONSTRUCTING TvRemoteControl" << std::endl;
}

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
    TvConnectors();
    int numberHdmiInputs = 2;
    int numberHeadphoneOuts = 3;
    std::string digitalOutType = "spdif";
    bool hasScartConnector = false;
    std::string powerConnectorType = "external";

    void outputAudio(float volume = 6.2f, int output = 2);
    bool connectToAntenna();
    bool connectToPower(int powerSocket = 1);
};

TvConnectors::TvConnectors()
{
    std::cout << "CONSTRUCTING TvConnectors" << std::endl;
}

void TvConnectors::outputAudio(float volume, int output)
{
    std::cout << "Audio Output " << output << " running. Volume: " << volume << std::endl;
}

bool TvConnectors::connectToAntenna()
{
    std::cout << "Trying to connect to antenna: ";
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
    TvOnScreenMenu();
    float size = 10.4f;
    int menuElements = 12;
    std::string color = "gray";
    int numberOfLanguages = 9;
    std::string language = "english";

    void showNetflix(std::string showTitle, int season, int episode);
    void showTVGuide(int week);
    void activateRecoding(int channel);
};

TvOnScreenMenu::TvOnScreenMenu()
{
    std::cout << "CONSTRUCTING TvOnScreenMenu" << std::endl;
}

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
    TvManufacturer();
    std::string name = "SONY";
    std::string headquartersLocation = "Japan";
    int foundingYear = 1946;
    std::string founder = "Masaru Ibuka";
    float annualProfit = 1178.8f;

    void goBankrupt(bool payAllDebts);
    bool releasNewModel(std::string modelName, float price);
    bool buyRivalCompany(std:: string company, float price);
};

TvManufacturer::TvManufacturer()
{
    std::cout << "CONSTRUCTING TvManufacturer" << std::endl;
}

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
    std::cout << TvManufacturer::name << " tried to buy " << company << " for $" << price  << std::endl;
    return true;
}
// ============================================================

struct Tv
{
    Tv();
    TvScreen screen;
    TvRemoteControl remoteControl;
    TvConnectors connectors;
    TvOnScreenMenu onScreenMenu;
    TvManufacturer manufacturer;

    void changeChannel(int channelNumber, bool useRemoteControl);
    void changeVolume(float newVolume, bool useRemoteControl);
    void activateSmartTv(int menuItem = 0);
};

Tv::Tv()
{
    std::cout << "CONSTRUCTING Tv" << std::endl;
}

void Tv::changeChannel(int channelNumber, bool useRemoteControl)
{
    std::cout << "You have switched to Channel " << channelNumber;
    if (useRemoteControl)
    {
        std::cout << " with the remote control." << std::endl;
    }
    else
    {
        std::cout << "." << std::endl;
    }
}

void Tv::changeVolume(float newVolume, bool useRemoteControl)
{
    std::cout << "Volume changed to " << newVolume;
    if (useRemoteControl)
    {
        std::cout << " with the remote control." << std::endl;
    }
    else
    {
        std::cout << "." << std::endl;
    }
}

void Tv::activateSmartTv(int menuItem)
{
    std::cout << "SmartTV-Menu Item " << menuItem << " activated!" << std::endl;
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
    Example::main();
    
    ElectricGuitar telecaster;
    telecaster.plugIn("green");
    telecaster.selectPickup(1);
    telecaster.changeVolume(9.9f);
    telecaster.string1.breakString();
    telecaster.string1.tuneString(442.2f);
    telecaster.string1.pluckString(12);
    std::cout << "Price: " << telecaster.price << std::endl;
    std::cout << "String-Manufacturer: " << telecaster.string1.manufacturer << std::endl;
    std::cout << "============================================================" << std::endl;

    Computer macbook;
    macbook.runProgram("Ableton", 10);
    macbook.shutDown();
    macbook.eraseDisk("Macintosh HD");
    macbook.logicPro.start();
    macbook.logicPro.close();
    macbook.logicPro.install("Macintosh HD");
    std::cout << "The Computer has " << macbook.amountOfRam << "GB of RAM and a processor speed of " << macbook.processorSpeed << " GHz" << std::endl;
    std::cout << macbook.logicPro.name << " by " << macbook.logicPro.manufacturer << " has a size of " << macbook.logicPro.size << " GB" << std::endl;
    std::cout << "============================================================" << std::endl;

    Bus schoolBus;
    schoolBus.startEngine();
    schoolBus.turnLeft(30);
    schoolBus.openDoors(false);
    schoolBus.openDoors(true);
    std::cout << "This Bus made by " << schoolBus.manufacturer << " has " << schoolBus.numberOfSeats << " Seats and a maxiumum speed of " << schoolBus.maximumSpeed << " km/h" << std::endl;
    std::cout << "============================================================" << std::endl;

    MobilePhone iPhone;
    iPhone.manufacturer = "Apple";
    iPhone.yearOfManufacture = 2018;
    iPhone.sendMessage("Hey !!");
    iPhone.charge(); 
    bool updateSuccess = iPhone.updateOperatingSystem(11.2f);
    std::cout << "The Update was succesful: " << (updateSuccess ? "The Update was succesful" : "Could not update!") << "\n";
    std::cout << iPhone.manufacturer << " build this phone in " << iPhone.yearOfManufacture << "\n" << std::endl;
    
    MobilePhone nokiaPhone;
    nokiaPhone.sendMessage("A message from the Nokia");
    nokiaPhone.charge();
    nokiaPhone.updateOperatingSystem(1.2f);
    std::cout << nokiaPhone.manufacturer << " build this phone in " << nokiaPhone.yearOfManufacture << std::endl;
    std::cout << "============================================================" << std::endl;

    TvScreen samsungScreen;
    samsungScreen.displayImage("Grumpy cat");
    std::cout << samsungScreen.displayImage("Funny cat") << std::endl;
    samsungScreen.changeBrightness(12.3f);
    samsungScreen.changeContrast(22.43f);
    std::cout << "This is a " << samsungScreen.type << " screen with a refresh rate of " << samsungScreen.refreshRate << " Hz" << std::endl;
    std::cout << "============================================================" << std::endl;

    TvRemoteControl samsungRemote;
    samsungRemote.turnTvOn();
    samsungRemote.changeChannel(4);
    samsungRemote.changeVolume(11.2f);
    std::cout << "You are using a " << samsungRemote.color << " " << samsungRemote.type << " remote with " << samsungRemote.numberOfKnobs << " knobs" << std::endl;
    std::cout << "============================================================" << std::endl;

    TvConnectors samsungConnectors;
    samsungConnectors.connectToPower();
    std::cout << (samsungConnectors.connectToAntenna() ? "success!" : "failed!" ) << std::endl;;
    samsungConnectors.outputAudio(8.8f, 1);
    std::cout << "This TV has " << samsungConnectors.numberHdmiInputs << " HDMI inputs and " << samsungConnectors.numberHeadphoneOuts << " headphone outputs" << std::endl; 
    std::cout << "============================================================" << std::endl;

    TvOnScreenMenu samsungMenu;
    samsungMenu.showNetflix("Breaking Bad", 3, 4);
    samsungMenu.showTVGuide(22);
    samsungMenu.activateRecoding(12); 
    std::cout << "The onscreen-menu is displayed in " << samsungMenu.language << ", but you can choose any of the " << samsungMenu.numberOfLanguages <<" languages" << std::endl;
    std::cout << "============================================================" << std::endl;

    TvManufacturer sony;
    sony.goBankrupt(false);
    sony.releasNewModel("TV2000x", 1299.99f);
    std::cout << ( sony.buyRivalCompany("LG", 1.99f)?  "The offer was accepted" : "The offer was rejected") 

    TvManufacturer samsung;
    samsung.goBankrupt(true);
    std::cout << "============================================================" << std::endl;


    Tv samsungTv;
    samsungTv.changeChannel(11, true);
    samsungTv.changeChannel(12, false);
    samsungTv.changeVolume(12.2f, true);
    samsungTv.activateSmartTv(3);

    std::cout << "good to go!" << std::endl;
}
