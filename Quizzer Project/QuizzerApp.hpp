#ifndef _QUIZZER_APP
#define _QUIZZER_APP

class QuizzerApp
{
    public:
    QuizzerApp();
    void Run();

    private:
    void Menu_Question();
    void Menu_QuizEnd();

    int m_totalAnswered;
    int m_totalCorrect;
};

#endif
