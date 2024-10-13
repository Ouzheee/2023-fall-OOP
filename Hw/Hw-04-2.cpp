#include <iostream>
using namespace std;

class Student{
    private:
        double Q1sc;
        double Q2sc;
        double Midsc;
        double Finsc;
        double Avg;
        char gradeLetter;
    public:
        void Counter();
        void Grader();
        void SetQ1(double inQ1);
        void SetQ2(double inQ2);
        void SetMid(double inMid);
        void SetFin(double inFi);
        void SetAvg(double avg);
        void SetG(char inLet);
        double getQ1();
        double getQ2();
        double getMid();
        double getFin();
        double getAvg();
        char getGrade();
        
};

void Student::Counter(){
    Avg = Q1sc*10*0.125 + Q2sc*10*0.125 + Midsc*0.25 + Finsc*0.5;
}
void Student::Grader(){
    if (Avg >= 90){
        gradeLetter = 'A';
    }
    else if (Avg >= 80){
        gradeLetter = 'B';
    }
    else if (Avg >= 70){
        gradeLetter = 'C';
    }
    else if (Avg >= 60){
        gradeLetter = 'D';
    }
    else{
        gradeLetter = 'F';
    }
}
void Student::SetQ1(double inQ1){
    Q1sc = inQ1;
}
void Student::SetQ2(double inQ2){
    Q2sc = inQ2;
}
void Student::SetMid(double inMid){
    Midsc = inMid;
}
void Student::SetFin(double inFi){
    Finsc = inFi;
}
void Student::SetAvg(double inavg){
    Avg = inavg;
}
void Student::SetG(char inLet){
    gradeLetter = inLet;
}

double Student::getQ1(){
    return Q1sc;
}
double Student::getQ2(){
    return Q2sc;
}
double Student::getMid(){
    return Midsc;
}
double Student::getFin(){
    return Finsc;
}
double Student::getAvg(){
    return Avg;
}
char Student::getGrade(){
    return gradeLetter;
}


int main(){
    Student st;
    double Q1, Q2, Mi, Fi;
    cout << "Quiz 1 score (0-10), Quiz 2 score (0-10), Midterm score (0-100), Final Score  (0-100)" << endl;
    cin >> Q1 >> Q2 >> Mi >> Fi;
    st.SetQ1(Q1);
    st.SetQ2(Q2);
    st.SetMid(Mi);
    st.SetFin(Fi);
    st.Counter();
    st.Grader();

    cout << "Student Record:" << endl << "Quiz 1 score: " << st.getQ1() << endl
         << "Quiz 2 score: " << st.getQ2() << endl << "Midterm score: " << st.getMid() << endl
         << "Final score: " << st.getFin() << endl << "Average Score: " << st.getAvg() << endl
         << "Grade: " << st.getGrade();
    return 0;
}