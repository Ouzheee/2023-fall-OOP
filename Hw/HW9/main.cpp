#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* cSpell:disable */
class BasicTicket{
    public:
        BasicTicket(string name, string depart, string arrive, int flightnum, float prices);
        float getPrice(); 

    protected:
        string Name;
        string Depart;
        string Arrive;
        int flight;
        float price;
        
};

class PremiumTicket : public BasicTicket{
    public:
        PremiumTicket(string name, string depart, string arrive, int flightnum, float prices, int seatNumber);
        float getPrice();
        int seatNum;
};

BasicTicket::BasicTicket(string name, string depart, string arrive, int flightnum, float prices): Name(name), 
Depart(depart), Arrive(arrive),flight(flightnum), price(prices) {}

PremiumTicket::PremiumTicket(string name, string depart, string arrive, int flightnum, float prices
, int seatNumber) : BasicTicket(name, depart, arrive, flightnum, prices), seatNum(seatNumber) {}

float BasicTicket::getPrice(){
    return static_cast<int>(price);
}

float PremiumTicket::getPrice(){
    return static_cast<int>(1.1* BasicTicket::getPrice());
}

int Total(vector<PremiumTicket> Pre, vector<BasicTicket> Bas){
    int sum=0;
    for (int i=0; i<Pre.size(); i++){
        sum += Pre[i].getPrice();
    }
    for (int i=0; i<Bas.size(); i++){
        sum += Bas[i].getPrice();
    }
    return sum;
}

int main(){
    vector<PremiumTicket> Pre;
    vector<BasicTicket> Bas;
    vector<bool> Seq;
    int n, FlightNum, seat;
    float Prices;
    string Pasname, Decity, Arcity; 
    cout << "number of passenger" << endl;
    cin >> n;
    

    for (int j=0; j<n; j++){
        cout << "information"<< endl; 
        cin >> Pasname >> Decity >> Arcity >> FlightNum >> Prices >> seat;
        if (seat == 0){
            Seq.push_back(true);
            Bas.push_back(BasicTicket(Pasname, Decity, Arcity, FlightNum, Prices));
        }
        else{
            Seq.push_back(false);
            Pre.push_back(PremiumTicket(Pasname, Decity, Arcity, FlightNum, Prices, seat));
        }
    }
    int p=0,b=0;
    cout << "Price of both tickets :" << endl;
    while ((p+b) < Seq.size()){
        if (Seq[p+b]){
            cout << Bas[b].getPrice() << endl;
            b++;
        }
        else{
            cout << Pre[p].getPrice() << endl;
            p++;
        }
    }
    cout << "Total  cost of all tickets: " << Total(Pre, Bas) << endl;

    return 0;
}

