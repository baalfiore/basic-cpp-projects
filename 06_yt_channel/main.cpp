#include <iostream>
#include<list>
#include <string>
using namespace std;

class contentCreator {
private: 
    string Name;
    int SubscribersCount;
    // can change from string to of type videos.

protected:
    
    string OwnerName;
    list<string>PublishedVideos;
    int contentQuality;

public:
    contentCreator(string _name, string _ownerName)
    {
        Name = _name;
        OwnerName = _ownerName;
        SubscribersCount = 0;
    }

    void printInfo()
    {
        cout << "\n\nName: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "Subscribers: " << SubscribersCount << endl;
        cout << "Videos: ";
        for(string vid : PublishedVideos)
        {
            cout << vid << endl;
        }
    }

    void checkAnalytics()
    {
        if (contentQuality < 5)
        {
             cout << Name << " has flagged by the community as bad." << endl;

        }
        else
        {
            cout << "This content has been widely approved by the community" << endl;
        }
    }

    void Subscribe(){
        SubscribersCount++;
    }

    void Unsubscribe(){
        if (SubscribersCount>0)
        {
            SubscribersCount--;
        }
    }

    string getName()
    {
        return Name;
    }

    void setName( string _name)
    {
        Name = _name;   
    }

    string getOwnerName()
    {
        return OwnerName;
    }

    void setOwnerName(string _ownerName)
    {
        OwnerName = _ownerName;
    }

    // adds a video to the content creator's channel.
    void publishVideo(string _video){
        PublishedVideos.push_back(_video);
    }

};

//derived class of content creator
class  gamingChannel:public contentCreator {
    
    private:
    list<string> games;
    // public denotes that anything is public wil be available
    // invokes the baseclass' construct.
    public:
    gamingChannel(string _name, string _ownerName):contentCreator(_name, _ownerName){
    }

    // retrieves the entire list of games.
    list<string> getGames()
    {
        return games;
    }
    void addGames(string _game)
    {
        games.push_back(_game);
    }

    // removes a particular game from the list.
    void removeGames(string _game)
    {
        if (!games.empty())
        {
            games.remove(_game);
        }
        else
        {
            cout << "No games in list" << endl;
        }
    }

};

int main(){
    
    gamingChannel aztecross("Aztecross", "Ross");
    contentCreator gamegrumps("Game grumps", "Arin Hanson");

    aztecross.Subscribe();
    aztecross.Subscribe();
    aztecross.Subscribe();
    aztecross.Unsubscribe();
    aztecross.publishVideo("Glassway GM guide");


    aztecross.printInfo();
    aztecross.addGames("Destiny 2");

    contentCreator * yt1 = &aztecross;

    yt1->checkAnalytics();
    
}
