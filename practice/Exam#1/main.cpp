#include <iostream>
using namespace std;

class CQ {
public:
    CQ(char correctOption) : m_correctOption(correctOption)
    {
        m_other = 'A';
    }
    bool isCorrect(char option) const {
        return m_correctOption == option;
    }
    /*
    void switchB() const {
        m_other = m_correctOption;
    }
    void switchC() {
        m_correctOption = m_other;
    }
     */
private:
    const char m_correctOption;
    char m_other;
};

int main() {
    cout << "Hello, World!" << std::endl;

    CQ test('B');
    cout << test.isCorrect('B') << endl;

    return 0;
}


