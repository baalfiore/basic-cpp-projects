#include <iostream>
using namespace std;

/**
 * 04 Quiz App
 * use structures to create a quiz app.
 * a struct for the question
 * a struct for choices.
 * 
 * */

struct Response 
{
    bool Correct;
    string text;
};

struct Question 
{
    string prompt;
    string answer;
    Response choices[3];
};

void setQuestion(Question& aQuestion, string _prompt, string _answer, Response _choices[], int arrSize)
{
    aQuestion.prompt = _prompt;
    aQuestion.answer = _answer;

    for(int i =0; i != arrSize; ++i)
    {
        aQuestion.choices[i] = _choices[i];
    }
};

bool isValidChoice(int choice, int possible)
{
    if (choice >= 0 && choice <= possible)
    {
        return true;
    }
    else 
    {
        cout << "Invalid choice please choose from the available options." << endl;
        return false;
    }
}

// sets the response with the text is the correct answer.
void setResponse( Response& _response, string _text, bool Correct)
{
    _response.Correct = Correct;
    _response.text = _text;
}

//validates the response of the user for a correct answer.
bool isCorrect(Question& _question, Response choice, int& score)
{
  
    if (_question.answer != choice.text)
    {
        cout << "Incorrect." << endl;
       
        return false;
    }
    else 
    {
        cout << "You are correct! " << endl;
         score+=1;
        return true;
    }
}

void displayError()
{
    cout << "An Error has occurred. " << endl;
}

void displayScore(int& score)
{
    cout << "----- Current score: " << score << endl;
}

void displayQuestion(Question& _question, Response _response[], int arrSize, int& _score)
{   
    displayScore(_score);
    cout << _question.prompt << "?" << endl;
    for(int x =0; x != arrSize; ++x)
    {
        cout << "   " << x+1 << ". " << _response[x].text << endl;
    } 

    cout << "Enter the number of your choice (1 -" << arrSize << ")" << endl;
    int choice;
    cin >> choice;
    cout << "\nYou have selected: " << choice << endl;
    if (isValidChoice(choice -1, arrSize)!= false)
    {
        isCorrect(_question, _response[choice-1], _score);
    }
    else 
    {
        displayError();
    }
    
}

int main() 
{
    // Initialize variables
    Question q1;
    Question* qptr = &q1;
    Response r1, r2, r3;
    Response responses[] = {r1, r2, r3};

    int score = 0;
    int* scorePtr = NULL;

    scorePtr = &score;

    int arrSize = sizeof(responses)/sizeof(responses[0]);

    setResponse(responses[0], "periods", false);
    setResponse(responses[1], "commas", true);
    setResponse(responses[2], "dashes", false);
    setQuestion(*qptr, "What do Loggerhead tracks look like?", "commas", responses, arrSize );
    displayQuestion(*qptr, responses, arrSize, *scorePtr);

    setResponse(responses[0], "in the ocean", false);
    setResponse(responses[1], "on grassy soil", false);
    setResponse(responses[2], "on shore", true);
    setQuestion(*qptr, "Where do female turtle typically lay their eggs at?", "on shore", responses, arrSize );
    displayQuestion(*qptr, responses, arrSize, *scorePtr);

}



