#include "QuestionManager.hpp"

#include "NotImplementedException.hpp"

#include <iostream>
#include <fstream>
using namespace std;

vector<Question> QuestionManager::m_questions;
int QuestionManager::m_currentIndex;

//! Load the quiz questions from a text file.
void QuestionManager::LoadQuestions( string filename )
{
    //throw NotImplementedException( "QuestionManager::LoadQuestions" );
    ifstream input(filename);
    Question inputQuestion;

    while (input >> inputQuestion)
    {
        m_questions.push_back(inputQuestion);
    }
    
    cout << m_questions.size() << " questions loaded\n";
}

//! Return the current question and increment the index counter.
Question& QuestionManager::GetNextQuestion()
{
    return m_questions[ m_currentIndex++ ];
}

//! Returns whether we're out of questions or not.
bool QuestionManager::IsEmpty()
{
    return m_currentIndex == m_questions.size();
}
