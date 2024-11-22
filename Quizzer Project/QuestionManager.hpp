#ifndef _QUESTION_MANAGER
#define _QUESTION_MANAGER

#include "Question.hpp"
#include <vector>
using namespace std;

class QuestionManager
{
    public:
    static void LoadQuestions( string filename );
    static Question& GetNextQuestion();
    static bool IsEmpty();

    private:
    static vector<Question> m_questions;
    static int m_currentIndex;
};

#endif
