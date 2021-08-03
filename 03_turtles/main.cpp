#include <iostream>
#include <array>
using namespace std;

/**
 * 03 - Turtles
 * Description: Learning structures using turtle information from the sea turtle conservancy group.
 *  Concepts used:
 *      - Pointers
 *      - Structs
 */

// The blueprint/struct for a Turtle profile.
struct Turtle 
{
    string name;
    double sLength;
    double sWidth;
    string lastSeen;
    string tagDate;
    string species;
    string sex;
    int totalDistance;
    int lastUpdate;
    string sponsor;
};

// Struct for sponsor.
struct Sponsor
{
    string name;
    string founded;
};

// Sets the information for a Turtle Profile.
void setTurtle(Turtle& aTurtle, string name, string sex, double sLength, double sWidth, string species, Sponsor aSponsor)
{
    aTurtle.name = name;
    aTurtle.sex = sex;
    aTurtle.sLength = sLength;
    aTurtle.sWidth = sWidth;
    aTurtle.species= species;
    aTurtle.sponsor = aSponsor.name;
}

// Takes in the memory address of a sponsor
void setSponsor(Sponsor& aSponsor, string name, string year)
{
    aSponsor.name = name;
    aSponsor.founded = year;
};

// Prints the sponsor's basic information.
void printSponsor(Sponsor aSponsor)
{
    cout << "Group Name :" << aSponsor.name << endl;
    cout << "Founded in :" << aSponsor.founded << endl;
};

// Prints the Turtle profile.
void printTurtle(Turtle aTurtle)
{
    cout << "Name: " << aTurtle.name << endl;
    cout << "Sex: " << aTurtle.sex << endl;
    cout << "Carapace length (cm): " << aTurtle.sLength << endl;
    cout << "Carapace width (cm): "<< aTurtle.sWidth << endl;
    cout << "Species : "<< aTurtle.species << endl;
    cout << "Sponsored by :"<< aTurtle.sponsor << "\n\n" <<endl;
};

int main()
{
    // Turtle objects
    Turtle poptart, raya, coral;
    // Sponsor objects
    Sponsor disney, wildlife, tarte;
  
    //Initialize turtle pointer and sponsor pointers.
    Turtle *tptr = NULL;
    Sponsor *sptr = NULL;

    // Arrays
    Turtle turtles[] = { poptart, raya, coral};
    Sponsor sponsors[] = { wildlife, disney, tarte};
   
    int arrSize =  (sizeof(turtles)/sizeof(turtles[0]));
    int i = 0;

    setSponsor(sponsors[0], "Wildlife Collections", "2018");
    setSponsor(sponsors[1], "Disney Conservation Fund", "1995");
    setSponsor(sponsors[2], "Tarte Cosmetics", "1999");
    
    setTurtle(turtles[0], "Poptart", "Female", 110.2, 97.1, "Loggerhead", sponsors[1]);
    setTurtle(turtles[1], "Raya", "Female", 87.1, 83.7, "Loggerhead", sponsors[0]);
    setTurtle(turtles[2], "Coral", "Female", 97.5, 91.0, "Loggerhead/HawksBill", sponsors[2]);

    sptr = sponsors;
    tptr = turtles;

    do {
        cout << "tptr @: " << tptr << endl;
        printTurtle(*tptr);
        printSponsor(*sptr);
        tptr+=1;
        sptr+=1;
        i+=1;
    } while(i!=arrSize);

};