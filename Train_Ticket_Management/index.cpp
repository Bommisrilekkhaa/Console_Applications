#include <bits/stdc++.h>
using namespace std;

class Ticket {
    public:
    static int lower_berth;
    static int upper_berth;
    static int rac_berth;
    static int waiting_berth;
    static vector<int> lowerNumber;
    static vector<int> upperNumber;
    static vector<int> racNumber;
    static vector<int> waitingNumber;
};

int Ticket::lower_berth=1;
int Ticket::upper_berth=1;
int Ticket::rac_berth=1;
int Ticket::waiting_berth=1;
vector<int> Ticket::lowerNumber = {1};
vector<int> Ticket::upperNumber = {1};
vector<int> Ticket::racNumber = {1};
vector<int> Ticket::waitingNumber = {1};


int ind = 0;

class Passenger {
    public:
    static int passenger_id;
    string prefered_berth;
    Passenger(int id,string berth){
        passenger_id = id;
        berth = prefered_berth;
    }
};

int Passenger::passenger_id = 1;

class TicketManager : public Ticket{
    public:
    static int Ticketid;
    int TrainId = 1;
    int PassengerId;
    string berthAlloted;
    static vector<pair<Passenger,pair<string,int>>> booked_ticket;
    int Number;
    void BookTicket(Passenger p,int number,string berth){
        if(berth == "L" and lower_berth > 0){
            lower_berth--;
            booked_ticket.push_back({p,{berth,lowerNumber.front()}});
            lowerNumber.erase(lowerNumber.begin());
            return;
        }
        if(berth == "U" and upper_berth > 0){
            upper_berth--;
            booked_ticket.push_back({p,{berth,upperNumber.front()}});
            upperNumber.erase(upperNumber.begin());
            return;
        }
        if(lower_berth>0){
            lower_berth--;
            booked_ticket.push_back({p,{berth,lowerNumber.front()}});
            lowerNumber.erase(lowerNumber.begin());
            return;
        }
        if(upper_berth>0){
            upper_berth--;
            booked_ticket.push_back({p,{berth,upperNumber.front()}});
            upperNumber.erase(upperNumber.begin());
            return;
        }
        if(rac_berth>0){
            rac_berth--;
            booked_ticket.push_back({p,{berth,racNumber.front()}});
            racNumber.erase(racNumber.begin());
            return;
        }
        if(waiting_berth>0){
            waiting_berth--;
            booked_ticket.push_back({p,{berth,waitingNumber.front()}});
            waitingNumber.erase(waitingNumber.begin());
            return;
        }
        cout<<"All tickets are filled"<<endl;
    }
    void cancel(){

    }
};

int TicketManager::Ticketid = 1;


int main(){

        

}

