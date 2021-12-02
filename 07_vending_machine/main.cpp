#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Vendor
{
  private:
    std::string name;
    double profit;
    std::string company;
  
  public:
    std::string phoneNumber;
};

// Logging class for debugging
class Log
{
    private:
        std::string logPath;
        fstream logFile;
    public:
        std::string filename;

    Log()
    {
        filename = "log";
        logFile.open(filename.c_str(), ios::out);
    }

    ~Log()
    {
        cout << "Removing Logging file" << endl;
        std::remove(filename.c_str());
    }

    bool isOpen( fstream _logFile)
    {
        if (_logFile.is_open())
        {
            cout << "Logger is operational\n";
            _logFile.close();
            return true; 
        }
        else
        {
            cout << "Logger is terminated\n";
            return false;
        }
    } 

    void readLog(fstream _logFile)
    {
        if(_logFile.is_open())
        {
            std::string line;
            while (getline(_logFile, line))
            {
                std::cout << line <<endl;
            }
            _logFile.close();
        }
    }

    void appendLog(fstream _logFile, std::string text)
    {
        _logFile << text << endl;
    }    
};


int main()
{
    std::string inventoryList = "inventory.txt";

    fstream myFile;
}
