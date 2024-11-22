#include "QuizzerApp.hpp"
#include "QuestionManager.hpp"

#include <iostream>
#include <string>
using namespace std;

QuizzerApp::QuizzerApp()
{
    m_totalAnswered = 0;
    m_totalCorrect = 0;
}

void QuizzerApp::Run()
{
    QuestionManager::LoadQuestions( "questions.txt" );

    while ( !QuestionManager::IsEmpty() )
    {
        Question& question = QuestionManager::GetNextQuestion();
        question.Display();

        string answer;
        cout << " Your answer: ";
        getline( cin, answer );

        bool isCorrect = question.IsAnswerCorrect( answer );

        if ( isCorrect )
        {
            cout << endl << "CORRECT!" << endl;
            cout << "-----------------------------" << endl;
            m_totalCorrect++;
        }
        else
        {
            cout << endl << "WRONG! The answer was " << question.GetAnswer() << endl;
            cout << "-----------------------------" << endl;
        }

        m_totalAnswered++;
    }

    float score = ( float(m_totalCorrect) / float(m_totalAnswered) ) * 100;

    cout << "-----------------------------" << endl;
    cout << endl << "QUIZ RESULT" << endl;
    cout << "Total correct:     " << m_totalCorrect << endl;
    cout << "Total questions:   " << m_totalAnswered  << endl;
    cout << "SCORE:             " << score << "%" << endl;
}
