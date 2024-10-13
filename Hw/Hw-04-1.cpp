#include <iostream>
using namespace std;

struct Student{
    double Q1sc;
    double Q2sc;
    double Midsc;
    double Finsc;
    double Avg;
    char gradeLetter;
};

void Counter(Student& st){
    st.Avg = st.Q1sc*10*0.125 + st.Q2sc*10*0.125 + st.Midsc*0.25 + st.Finsc*0.5;
}

void Grader(Student& st){
    double avg = st.Avg;
    if (avg >= 90){
        st.gradeLetter = 'A';
    }
    else if (avg >= 80){
        st.gradeLetter = 'B';
    }
    else if (avg >= 70){
        st.gradeLetter = 'C';
    }
    else if (avg >= 60){
        st.gradeLetter = 'D';
    }
    else{
        st.gradeLetter = 'F';
    }
}

int main(){
    Student st;
    cout << "Quiz 1 score (0-10), Quiz 2 score (0-10), Midterm score (0-100), Final Score  (0-100)" << endl;
    cin >> st.Q1sc >> st.Q2sc >> st.Midsc >> st.Finsc;
    Counter(st);
    Grader(st);
    cout << "Student Record:" << endl << "Quiz 1 score: " << st.Q1sc << endl
         << "Quiz 2 score: " << st.Q2sc << endl << "Midterm score: " << st.Midsc << endl
         << "Final score: " << st.Finsc << endl << "Average Score: " << st.Avg << endl
         << "Grade: " << st.gradeLetter;
    return 0;
}