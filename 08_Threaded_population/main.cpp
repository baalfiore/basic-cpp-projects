
#include <iostream>
#include <pthread.h>
#include<thread>
#include <map>
#include<chrono>
#include <math.h>
#include <mutex>
using namespace std::chrono_literals;

std:: mutex g_mutex;

bool isCritical(int temp ,int danger, std::string loc)
{
    if (temp >= danger)
    {
        std::cout << "Danger! Reached dangerous temperature of: " << temp << " at " << loc << std::endl;
        return true; 
    }
    else
    {
        return false;
    }
}

// Update the reports of the current forecast.
void RefreshForecast(std::map<std::string, int> forecastMap)
{
    
    // infinite loop to run refreshing
    while(true)
    {
        // Take each value buy reference and update temperature
        for(auto &item : forecastMap)
        {
        item.second++;
        std::cout << item.first << " - " << item.second << " F" << std::endl;
            if(isCritical(item.second, 105, item.first))
            {
                std::cout  << "Thread id:" << std::this_thread::get_id << " needs to be closed"
                << std::endl;

            }

        }
        std::this_thread::sleep_for(2000ms);
    }
    
}

// Update the reports of the current forecast.
void RefreshGrowth(std::map<std::string, int> popMap, float growthRate)
{
    g_mutex.lock();

    // infinite loop to run refreshing
    while(true)
    {

        int prevPop = 0;
        // Take each value by reference and update population
        for(auto &item : popMap)
        {
            
            prevPop= item.second;
            item.second =item.second * growthRate;
           
            
        //std::cout << item.first << " - " << item.second << " people" << std::endl;
        
        }
        g_mutex.unlock();
        std::this_thread::sleep_for(1500ms);
    }
    
}

// Updates with decay of populations
void RefreshDecay(std::map<std::string, int> popMap, float decayRate)
{
    bool isAlive = true;
    // infinite loop to run refreshing
    while(true || !isAlive)
    {
        //TODO: A function that can drastically change the growth rate with a random event.

        // Take each value by reference and update population
        for(auto &item : popMap)
        {
            g_mutex.lock();
            item.second =item.second * decayRate;
            decayRate -=.01;
            if (item.second <= 0)
            {
                isAlive = false;
            }
            
        //std::cout << item.first << " - " << item.second << " people" << std::endl;
        
        }
        g_mutex.unlock();
        std::this_thread::sleep_for(3000ms);
    }
    
}

// Updates with current Population standings.
void RefreshPopulation(std::map<std::string, int> popMap)
{
    std::cout << "Simulation started..." << std:: endl; 
    bool isAlive = true;
    // infinite loop to run refreshing
    while(true || !isAlive)
    {
        //TODO: A function that can drastically change the growth rate with a random event.

        // Take each value by reference and update population
        for(auto &item : popMap)
        {
            g_mutex.lock();
   
            std::cout << item.first << " - " << item.second << " people" << std::endl;
            g_mutex.unlock();
        
        }
        std::this_thread::sleep_for(4000ms);
    }
    
}


int main()
{
 
    float growthRate = 1.06;
    float decayRate = .92;
    std::map<std::string, int> *fmptr;
    std::map<std::string, int> *pmptr;
    
    std::map<std::string, int> forecastMap = {
        {"Palm Bay", 75},
        {"Orlando", 80},
        {"Sanford", 88}
    };

    fmptr = &forecastMap;

    std::map<std::string, int> populationMap = {
        {"Palm Bay", 18000},
        {"Orlando", 36000},
        {"Sanford", 8800}
    };

    pmptr = &populationMap;
   
    std::thread weatherWorker(RefreshForecast, *fmptr);
    // consumer/ producer threads
    std::thread growthWorker (RefreshGrowth, *pmptr, growthRate);
    std::thread decayWorker (RefreshDecay, *pmptr, decayRate);
    std::thread popWorker (RefreshPopulation, *pmptr);
    
    
  
    weatherWorker.join();
    popWorker.join();
    growthWorker.join();
    decayWorker.join();




}