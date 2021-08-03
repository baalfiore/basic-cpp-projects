#include <iostream>
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

    sptr = &disney;
    setSponsor(*sptr, "Disney Conservation Fund", "1995");
    sptr = &wildlife;
    setSponsor(wildlife, "Wildlife Collections", "2018");
    sptr = &tarte;
    setSponsor(tarte, "Tarte Cosmetics", "1999");
    tptr = &poptart;
    setTurtle(poptart, "Poptart", "Female", 110.2, 97.1, "Loggerhead", wildlife);
    tptr = &raya;
    setTurtle(raya, "Raya", "Female", 87.1, 83.7, "Loggerhead", disney);
    tptr = &coral;
    setTurtle(coral, "Coral", "Female", 97.5, 91.0, "Loggerhead/HawksBill", tarte);

    printTurtle(poptart);
    printTurtle(raya);
    printTurtle(coral);
};