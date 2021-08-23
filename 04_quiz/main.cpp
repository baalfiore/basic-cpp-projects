#include <iostream>
#include <string>
#include <vector>
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

void setQuestion(Question& aQuestion, string _prompt, string _answer, vector<Response> _choices)
{
    aQuestion.prompt = _prompt;
    aQuestion.answer = _answer;

    for(int i =0; i != _choices.size(); ++i)
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
//void setResponse( Response& _response, string _text, bool Correct)
void setResponse( Response& _response, string _text, bool Correct)
{
    _response.Correct = Correct;
    _response.text = _text;
}

void storeResponse(Response& _response, vector<Response> _rlist)
{
    _rlist.push_back(_response);
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

void storeQuestion(vector<Question> _qvec, Question& _question)
{
    _qvec.push_back(_question);
}

//displays a message if an error was encountered.
void displayError()
{
    cout << "An Error has occurred. " << endl;
}

//displays the user's current score.
void displayScore(int& score)
{
    cout << "----- Current score: " << score << endl;
}

Response getResponse(Response & _response)
{
    return _response;
}

void storeResponse(vector<Response>& _rvec, Response& _response)
{
    _rvec.push_back(_response);
}

void printAllResponses(vector<Response>& _rvec)
{
    for (int i = 0; i < _rvec.size() && !_rvec.empty(); ++i)
        cout << _rvec[i].text << endl;
}

Response getChoice(Question& _question, vector<Response> _response, int & _score)
{
    int arrSize = _response.size();
    int choice;
    //should be made into a function
    cout << "Enter the number of your choice (1 -" << arrSize << ")" << endl;
    
  
    cin >> choice;
    cout << "\nYou have selected: " << choice << endl;
    //storeResponse(getResponse(_response[choice-1])) ;
    if (isValidChoice(choice -1, arrSize)!= false)
    {
        isCorrect(_question, _response[choice-1], _score);
        //storeResponse(_response, _response[choice-1]);
    }
    else if (!isCorrect(_question, _response[choice-1], _score))
    {
        storeResponse(_response, _response[choice-1]);
    }
    else
    {
        displayError();
    }
}

//display the user's interface for prompts and questions.
//void displayQuestion(Question& _question, Response _response[], int arrSize, int& _score)
void displayQuestion(Question& _question, vector<Response> _response, int& _score)
{   
    displayScore(_score);
    cout << _question.prompt << endl;
    for(int x =0; x != _response.size(); ++x)
    {
        cout << "   " << x+1 << ". " << _response[x].text << endl;
    } 
    cout << "getting choice" << endl;
    getChoice(_question, _response, _score);
    
}

int main() 
{
    // Initialize variables
    Question q1;
    Question* qptr = &q1;
    Response r1, r2, r3;
    //Response responses[] = {r1, r2, r3};

    Response* cptr;
    vector<Question> qlist;
    vector<Response> rlist;
    vector<Response> choices;

    int score = 0;
    int* scorePtr = NULL;

    scorePtr = &score;
    cptr = &r1;

    //int arrSize = sizeof(responses)/sizeof(responses[0]);

    setResponse(*cptr, "periods", false);
    storeResponse(rlist, *cptr);
    setResponse(*cptr, "commas", true);
    storeResponse(rlist, *cptr);
    setResponse(*cptr, "dashes", false);
    setQuestion(*qptr, "What do Loggerhead tracks look like?", "commas", rlist );
    
    displayQuestion(*qptr, rlist, *scorePtr);
    
    //storeQuestion(qlist, *qptr);

    //setResponse(responses[0], "in the ocean", false);
    //setResponse(responses[1], "on grassy soil", false);
    //setResponse(responses[2], "on shore", true);
    //setQuestion(*qptr, "Where do female turtle typically lay their eggs at?", "on shore", choices);
    //displayQuestion(*qptr, responses, arrSize, *scorePtr);

}



