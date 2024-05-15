#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class User {
public:
    int user_id;
    string name;
    
    User(int id, string name) : user_id(id), name(name) {}

    bool operator==(const User& other) const {
        return user_id == other.user_id && name == other.name;
    }
};

namespace std {
    template <>
    struct hash<User> {
        size_t operator()(const User& user) const {
            return hash<int>()(user.user_id) ^ hash<string>()(user.name);
        }
    };
}

class Policies {
public:
    int policy_id;
    string policy_name;
    int duration;

    Policies(int policy_id, string name, int dur) : policy_id(policy_id), policy_name(name), duration(dur) {}
};

class Policy_Manager {
public:
    unordered_map<User, vector<Policies>> availed_policies;
    vector<Policies> available;

    vector<Policies> get_policies() {
        return available;
    }

    void add_policy(Policies p) {
        available.push_back(p);
    }

    Policy_Manager() {}

    void book_policy(User user, Policies p) {
        availed_policies[user].push_back(p);
    }

    void display_booked_policies() {
        for(auto& entry : availed_policies) {
            User user = entry.first;
            cout << "Booked policies for User " << user.user_id << " (" << user.name << "):" << endl;
            for(auto& pol : entry.second) {
                cout << pol.policy_name << endl;
            }
            cout << endl;
        }
    }

    vector<Policies> get_Active_Policies(User user, int dura) {
        vector<Policies> avail_policies = availed_policies[user];
        vector<Policies> active;
        for(auto& pol : avail_policies) {
            if(dura < pol.duration) {
                active.push_back(pol);
            }
        }
        return active;
    }
};

int main() {
    int id = 1;
    Policies one(id++, "house", 10);
    Policies two(id++, "bike", 5);
    Policies three(id++, "car", 3);

    Policy_Manager pm;
    pm.add_policy(one);
    pm.add_policy(two);
    pm.add_policy(three);

    vector<Policies> avail = pm.get_policies();
    for(auto& pol : avail) {
        cout << pol.policy_name << endl;
    }

    User user(1, "cse");
    pm.book_policy(user, one);
    pm.book_policy(user, three);

    pm.display_booked_policies();

    vector<Policies> active = pm.get_Active_Policies(user, 5);

    return 0;
}


