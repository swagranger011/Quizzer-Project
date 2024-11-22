#ifndef _QUESTION
#define _QUESTION

#include <string>
#include <istream>
using namespace std;

class Question
{
    public:
    Question();
    Question( string question, string answer );
    void Setup( string question, string answer );
    void Display();
    bool IsAnswerCorrect( string answer );
    string GetAnswer();

    private:
    string m_question;
    string m_answer;

    string ToUpper( string original );

    friend istream& operator>>( istream& in, Question& object );
};

#endif
