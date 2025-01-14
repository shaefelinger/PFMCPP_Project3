/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




// ============================================================
struct ElectricGuitar
{
    int numberOfStrings = 6;
    int numberOfPickups = 2;
    std::string color = "blue";
    std::string name;
    float price;

    ElectricGuitar() : name("Telecaster"), price(1899.99f) 
    { 
        std::cout << "CONSTRUCTING ElectricGuitar" << std::endl;
    }

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

    void turnUpVolume()
    {
        for (int i = 0; i <= 20; ++i )
        {
            changeVolume( i * 0.5f );
        }
    }

    GuitarString string1; 
};

void ElectricGuitar::plugIn(std::string cableColor)
{
    std::cout << "You have plugged the " << cableColor << " cable into the " << ElectricGuitar::color <<  " " << ElectricGuitar::name <<std::endl;
}

void ElectricGuitar::selectPickup(int pickup)
{
    std::cout << "Switched to pickup " << pickup << std::endl;
}

void ElectricGuitar::changeVolume(float volume)
{
    std::cout << "Changed volume of " << ElectricGuitar::name <<" to " << volume << std::endl;
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
    int amountOfRam;
    float processorSpeed {2.4f};
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

    void showInfo()
    {
        std::cout << "The Computer has " << amountOfRam << "GB of RAM and a processor speed of " << processorSpeed << " GHz" << std::endl;
    }

    void powerOffCountdown();

    Application logicPro;
};

Computer::Computer() : amountOfRam(8)
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

void Computer::powerOffCountdown() 
{
    int i = 10;
    while (i > 0)
    {
        std::cout << "Power off in " << i << std::endl;
        --i;
    }
    shutDown();
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
    Bus() : numberOfSeats(24) 
    {
        std::cout << "CONSTRUCTING Bus" << std::endl;
    }

    int maximumSpeed { 110 };
    int numberOfSeats;
    std::string manufacturer = "MAN";
    float fuelConsumption = 20.3f;
    float fuelCapacity { 200.0f };

    void startEngine();
    void turnLeft(int angle);
    void openDoors(bool openAllDoors);

    void drive (int distance);
};

void Bus::startEngine()
{
    std::cout << "Engine of Bus started. The maximum speed is " << maximumSpeed << " km/h" <<std::endl;
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

void Bus::drive (int distance) 
{
    float fuelLeft, fuelUsed;
    int i = 0; 
    while ( i <= distance )
    {
        fuelUsed =  i * fuelConsumption / 100;
        fuelLeft =  fuelCapacity - fuelUsed;

        if ( fuelLeft < 0 ) 
        {
            std::cout << "YOU RAN OUT OF FUEL!!!" << std::endl;
            break;
        }

        std::cout << "You have driven " << i << " Km and used " << fuelUsed << " liters of fuel. You have " << fuelLeft << " liters left." << std::endl;
        i += 50;        
    }
}
// ============================================================

struct MobilePhone
{
    MobilePhone();
    int sizeOfMemory = 2;
    int sizeOfScreen = 2;
    std::string manufacturer;
    std::string typeOfCamera = "none";
    int yearOfManufacture = 1995;
    int chargingStatus { 12 };

    void sendMessage(std::string message);
    void charge(int percentage); 
    bool updateOperatingSystem(float osVersion);
};

MobilePhone::MobilePhone() : manufacturer("Nokia"), yearOfManufacture(1995)
{
    std::cout << "CONSTRUCTING MobilePhone" << std::endl;
}

void MobilePhone::sendMessage(std::string message)
{
    std::cout << "Message sent: " << message << std::endl;
}

void MobilePhone::charge(int percentage)
{
    while (chargingStatus < percentage)
    {
        std::cout << "Charging Status: " << chargingStatus << std::endl;
        chargingStatus += 5;
    }
    std::cout << "Phone is charged to " << percentage << "%" << std::endl;
}

bool MobilePhone::updateOperatingSystem(float osVersion)
{
    std::cout << "Updated Operating System to Version " << osVersion << " on this " << manufacturer << "-phone from " << yearOfManufacture << std::endl;
    return true;
}
// ============================================================

struct TvScreen
{
    TvScreen() 
    {
        std::cout << "CONSTRUCTING TvScreen" << std::endl;
    }

    float width = 62.3f;
    float height = 33.4f;
    int numberOfPixels = 921600;
    std::string type { "LED" };
    int refreshRate { 60 };

    std::string displayImage(std::string imgName = "defaultImage");
    void changeBrightness(float brightness);
    void changeContrast(float contrast);
    std::string getInfo();
    void displayTenImages();
}; 

std::string TvScreen::displayImage(std::string imgName)
{
    std::cout << "Displaying Image: " << imgName << std::endl;
    return "This is a message from the TV-Screen: I'm now showing the Image " + imgName;
}

void TvScreen::changeBrightness(float brightness)
{
    std::cout << "Changed brightness to: " << brightness << std::endl;
}

void TvScreen::changeContrast(float contrast)
{
    std::cout << "Changed contrast to: " << contrast << std::endl;
}

std::string TvScreen::getInfo()
{
    return "This is a " + type + " screen with a refresh rate of " + std::to_string(refreshRate) + " Hz"; 
}

void TvScreen::displayTenImages() 
{
    for ( int i = 0; i < 10; ++i )
    {
        displayImage("Crazy Cat " + std::to_string(i + 1) );
    }
}
// ============================================================

struct TvRemoteControl
{
    TvRemoteControl();
    int numberOfKnobs = 22;
    std::string color  { "black" };
    std::string type { "infrared" };
    float size = 10.2f;
    float range = 20.4f;

    void turnTvOn(int inputNumber = 0, int channelNumber = 1);
    void changeChannel(int channelNumber = 1);
    void changeVolume(float newVolume);

    int pressRandomKnob() 
    {
        int knob = rand() % numberOfKnobs + 1; // not really random - the sequence is always the same
        return knob;
    }

    void pressRandomKnobs(int amount)
    {
        std::cout << "Pressing random knobs: "; 
        // srand(time(0)); // tried to get a more random sequence. but it produces errors. 
        for ( int i = 0; i < amount; ++i )
        {
            std::cout << pressRandomKnob() << ( (i < amount - 1) ? " - " : "");
        }
        std::cout << std::endl;
    }
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
    std::cout << "Changed to channel " << channelNumber << " with the " << type << " remote control" << std::endl;
}

void TvRemoteControl::changeVolume(float newVolume = 3.2f)
{
    std::cout << "Changed volume to " << newVolume << std:: endl;
}
// ============================================================

struct TvConnectors
{
    TvConnectors();
    int numberHdmiInputs;
    int numberHeadphoneOuts = 3;
    std::string digitalOutType;
    bool hasScartConnector = false;
    std::string powerConnectorType = "external";

    void outputAudio(float volume = 6.2f, int output = 2);
    bool connectToAntenna();
    bool connectToPower(int powerSocket = 1);
    void testOutputs();
};

TvConnectors::TvConnectors() : numberHdmiInputs(3), digitalOutType("spdif") 
{
    std::cout << "CONSTRUCTING TvConnectors" << std::endl;
}

void TvConnectors::outputAudio(float volume, int output)
{
    std::cout << "Audio Output " << output << " running. Volume: " << volume << std::endl;
    std::cout << "The " << digitalOutType << " digital output is also working" << std::endl;
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

void TvConnectors::testOutputs()
{   
    for ( int i = 0; i < numberHdmiInputs; ++i )
    {
        std::cout << "Testing HDMI Input " << i + 1 << std::endl;
    }

    for ( int i = 0; i < numberHeadphoneOuts; ++i )
    {
        std::cout << "Testing Headphone Output " << i + 1 << std::endl;
    }

    std::cout << "Testing " << digitalOutType << " Output" << std::endl;
}
// ============================================================

struct TvOnScreenMenu
{
    TvOnScreenMenu();
    float size = 10.4f;
    int menuElements = 12;
    std::string color { "gray" };
    int numberOfLanguages = 9;
    std::string language { "english" };

    void showNetflix(std::string showTitle, int season, int episode);
    void showTVGuide(int week);
    void activateRecoding(int channel);

    void getLanguage();

    void getWeekGuide(int startWeek, int endWeek) 
    {
        for (int i = startWeek; i <= endWeek; ++i )
        {
            showTVGuide(i);
        }
    }
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

void TvOnScreenMenu::getLanguage()
{
    std::cout << "The onscreen-menu is displayed in " << language << ", but you can choose any of the " << numberOfLanguages <<" languages" << std::endl;
}

// ============================================================

struct TvManufacturer
{
    TvManufacturer();
    std::string name;
    std::string headquartersLocation = "Japan";
    int foundingYear = 1946;
    std::string founder = "Masaru Ibuka";
    float annualProfit = 1178.8f;

    void goBankrupt(bool payAllDebts);
    bool releasNewModel(std::string modelName, float price);
    bool buyRivalCompany(std:: string company, float price);

    void tryToBuyRival(std:: string company, float startingPrice);
};

TvManufacturer::TvManufacturer() : name("SONY"), headquartersLocation("Japan")
{
    std::cout << "CONSTRUCTING TvManufacturer" << std::endl;
}

void TvManufacturer::goBankrupt(bool payAllDebts)
{
    std::cout << TvManufacturer::name << " is bankrup!! " ;
    if (payAllDebts)
    {
        std::cout << "But they will pay their debts!" << std::endl;
    } 
    else
    {
        std::cout << "And they will not pay their debts!" << std::endl;
    }
}

bool TvManufacturer::releasNewModel(std::string modelName, float price)
{
    std::cout << "We have just released the new " << modelName << " for only " << price << std::endl;
    return true;
}

bool TvManufacturer::buyRivalCompany(std:: string company, float price)
{
    std::cout << TvManufacturer::name << " tried to buy " << company << " for $" << price << ". ";
    if (price > 999.f)
    {
        return true;
    }
    return false;
}

void TvManufacturer::tryToBuyRival(std:: string company, float startingPrice)
{
    float biddingPrice = startingPrice;
    while( !buyRivalCompany(company, biddingPrice) )
    {
        std::cout << "The Offer was rejected!" << std::endl;
        biddingPrice += 100.0f;
    }
    std::cout << "The Offer was finally accepted!" << std::endl;
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

    void fadeOut(float startingVolume);
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
        std::cout << std::endl;
    }
}

void Tv::activateSmartTv(int menuItem)
{
    std::cout << "SmartTV-Menu Item " << menuItem << " activated!" << std::endl;
}

void Tv::fadeOut(float startingVolume)
{
    float i = startingVolume;
    while ( i > 0 )
    {
        changeVolume(i, false);
        i -= 0.5f;
    }
    changeVolume(0, false);
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
    std::cout << "============================================================" << std::endl;

    ElectricGuitar telecaster;
    telecaster.plugIn("green");
    telecaster.selectPickup(1);
    telecaster.changeVolume(9.9f);
    telecaster.string1.breakString();
    telecaster.string1.tuneString(442.2f);
    telecaster.string1.pluckString(12);
    std::cout << "Price: " << telecaster.price << std::endl;
    std::cout << "String-Manufacturer: " << telecaster.string1.manufacturer << std::endl;
    telecaster.turnUpVolume();
    std::cout << "============================================================" << std::endl;

    Computer macbook;
    macbook.runProgram("Ableton", 10);
    macbook.shutDown();
    macbook.eraseDisk("Macintosh HD");
    macbook.logicPro.start();
    macbook.logicPro.close();
    macbook.logicPro.install("Macintosh HD");
    macbook.showInfo();
    
    std::cout << macbook.logicPro.name << " by " << macbook.logicPro.manufacturer << " has a size of " << macbook.logicPro.size << " GB" << std::endl;

    macbook.powerOffCountdown();
    std::cout << "============================================================" << std::endl;

    Bus schoolBus;
    schoolBus.startEngine();
    schoolBus.turnLeft(30);
    schoolBus.openDoors(false);
    schoolBus.openDoors(true);
    std::cout << "This Bus made by " << schoolBus.manufacturer << " has " << schoolBus.numberOfSeats << " Seats and a maxiumum speed of " << schoolBus.maximumSpeed << " km/h" << std::endl;
    schoolBus.drive(1500);
    std::cout << "============================================================" << std::endl;

    MobilePhone iPhone;
    iPhone.manufacturer = "Apple";
    iPhone.yearOfManufacture = 2018;
    iPhone.sendMessage("Hey !!");
    iPhone.charge(55); 
    bool updateSuccess = iPhone.updateOperatingSystem(11.2f);
    std::cout << (updateSuccess ? "The Update was succesful" : "Could not update!") << "\n";
    std::cout << iPhone.manufacturer << " build this phone in " << iPhone.yearOfManufacture << "\n" << std::endl;
    
    MobilePhone nokiaPhone;
    nokiaPhone.sendMessage("A message from the Nokia");
    nokiaPhone.charge(99);
    nokiaPhone.updateOperatingSystem(1.2f);
    std::cout << nokiaPhone.manufacturer << " build this phone in " << nokiaPhone.yearOfManufacture << std::endl;
    std::cout << "============================================================" << std::endl;

    TvScreen samsungScreen;
    samsungScreen.displayImage("Grumpy cat");
    std::cout << samsungScreen.displayImage("Funny cat") << std::endl;
    samsungScreen.changeBrightness(12.3f);
    samsungScreen.changeContrast(22.43f);
    std::cout << samsungScreen.getInfo() << std::endl;
    samsungScreen.displayTenImages();
    std::cout << "============================================================" << std::endl;

    TvRemoteControl samsungRemote;
    samsungRemote.turnTvOn();
    samsungRemote.changeChannel(4);
    samsungRemote.changeVolume(11.2f);
    std::cout << "You are using a " << samsungRemote.color << " " << samsungRemote.type << " remote with " << samsungRemote.numberOfKnobs << " knobs" << std::endl;
    samsungRemote.pressRandomKnobs(10);
    std::cout << "============================================================" << std::endl;

    TvConnectors samsungConnectors;
    samsungConnectors.connectToPower();
    std::cout << (samsungConnectors.connectToAntenna() ? "success!" : "failed!" ) << std::endl;;
    samsungConnectors.outputAudio(8.8f, 1);
    std::cout << "This TV has " << samsungConnectors.numberHdmiInputs << " HDMI inputs and " << samsungConnectors.numberHeadphoneOuts << " headphone outputs" << std::endl; 
    samsungConnectors.testOutputs();
    std::cout << "============================================================" << std::endl;

    TvOnScreenMenu samsungMenu;
    samsungMenu.showNetflix("Breaking Bad", 3, 4);
    samsungMenu.showTVGuide(22);
    samsungMenu.activateRecoding(12); 
    samsungMenu.getLanguage();
    samsungMenu.getWeekGuide(4, 12);
    std::cout << "============================================================" << std::endl;

    TvManufacturer sony;
    sony.goBankrupt(false);
    sony.releasNewModel("TV2000x", 1299.99f);
    std::cout << ( sony.buyRivalCompany("LG", 1.99f) ?  "The offer was accepted" : "The offer was rejected" ) << "\n" << std::endl;
    sony.tryToBuyRival("Grundig", 2.99f);

    TvManufacturer samsung;
    samsung.name = "SAMSUNG";
    samsung.goBankrupt(true);
    std::cout << ( samsung.buyRivalCompany("SONY", 1999.99f) ?  "The offer was accepted" : "The offer was rejected" ) << std::endl;
    std::cout << "============================================================" << std::endl;

    Tv toshibaTv;
    toshibaTv.changeChannel(11, true);
    toshibaTv.changeChannel(12, false);
    toshibaTv.changeVolume(12.2f, true);
    toshibaTv.activateSmartTv(3);
    toshibaTv.fadeOut(8.8f);
    toshibaTv.manufacturer.name = "TOSHIBA";
    std::cout << "You now have a new TV by " << toshibaTv.manufacturer.name << std::endl;
    toshibaTv.manufacturer.goBankrupt(true);

    std::cout << "good to go!" << std::endl;
}
