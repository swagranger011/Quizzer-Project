#include "Question.hpp"

#include "NotImplementedException.hpp"

#include <iostream>
using namespace std;

//! Default constructor - Initialize m_question and m_answer to empty strings.
Question::Question()
{
    m_question = m_answer = "";
}

//! Parameterized constructor - Call the Setup function to initialize the question and answer.
Question::Question( string question, string answer )
{
    Setup( question, answer );
}

//! Set up m_question and m_answer using the parameters.
void Question::Setup( string question, string answer )
{
    //throw NotImplementedException( "Question::Setup" );
    m_question = question;
    m_answer = answer;
}

//! Display the question text.
void Question::Display()
{
    //throw NotImplementedException( "Question::Display" );
    cout << m_question;
}

//! Compare the parameter answer to the actual m_answer (case-insensitive). Return true if they match; false otherwise.
bool Question::IsAnswerCorrect( string answer )
{
    //throw NotImplementedException( "Question::IsAnswerCorrect" );
    if (m_answer == answer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//! Return the value of m_answer.
string Question::GetAnswer()
{
    //throw NotImplementedException( "Question::GetAnswer" );
    return m_answer;
}

//! Converts the parameter string to all upper-case.
string Question::ToUpper( string original )
{
    string upper = "";
    for ( unsigned int i = 0; i < original.size(); i++ )
    {
        upper += toupper( original[i] );
    }
    return upper;
}

//! Inputs question information from an input stream
/**
Question format:
QUESTION_BEGIN
QUESTION
What is 2+2?
ANSWER
4
QUESTION_END
*/
istream& operator>>( istream& in, Question& object )
{
    //throw NotImplementedException( "operator>>( istream&, Question& )" );
    string buffer;

    getline(in, buffer);

    while ((getline(in, buffer)) && (buffer != "QUESTION_END"))
    {
        if (buffer == "QUESTION")
        {
            getline(in, object.m_question);
        }
        else
        {
            getline(in, object.m_answer);
        }
    }
    return in;
}



