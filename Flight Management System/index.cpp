#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

map<string, string> users;
map<string,deque<string>> prev_pass;
vector<string> User_name;
vector<string> Password;
vector<string> Email;
vector<string> Dob;

string admin_email = "abcd@gm.com";
string admin_pass = "@admin";

vector<string> flight_name;
vector<string> flight_no;
map<string,string> dept_air;
map<string,string> arr_air;
map<string,string> dept_time;
map<string,string> arr_time;
map<string,string> dept_date;
map<string,int> seat;
map<string,string> status;


//under construction
void add(){
    cout<<"Enter the flight name:";
    string name;
    cin>>name;
    flight_name.push_back(name);
    cout<<"Enter the flight number:";
    string number;
    cin>>number;
    flight_no.push_back(number);
    cout<<"Enter the flight departure airport:";
    string dept;
    cin>>dept;
    dept_air[flight_no]=dept;
    cout<<"Enter the flight arrival airport:";
    string arr;
    cin>>arr;
    arr_air[flight_no]=arr;
    cout<<"Enter the flight arrival time:";
    string time1;
    cin>>time1;
    dept_time[flight_no]=time1;
    cout<<"Enter the flight arrival airport:";
    string arr;
    cin>>arr;
    arr_air[flight_no]=arr;
     cout<<"Enter the flight arrival airport:";
    string arr;
    cin>>arr;
    arr_air[flight_no]=arr;
    cout<<"Enter the flight arrival airport:";
    string arr;
    cin>>arr;
    arr_air[flight_no]=arr;
    cout<<"Enter the flight arrival airport:";
    string arr;
    cin>>arr;
    arr_air[flight_no]=arr;
}

void admin(){
    int flag=0;
    int choice;
    cout<<"1.Add"<<endl<<"2.Delete"<<endl<<"3.Edit"<<endl<<"4.View"<<endl<<"5.Search"<<endl<<"6.History"<<endl;
    do {
    cout << "Enter the choice:";
        cin >> choice;
        switch (choice) {
            case 1: {
                // add();
                break;
            }
            case 2: {
                // Delete();
                break;
            }
            case 3:{
                // Edit();
                break;
            }
            case 4:{
                // View();
                break;
            }
            case 5: {
                // Search();
                break;
            }
            case 6:{
                // History();
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                flag = 1;
            }
        }
        cout << "Do you want to continue? Press Y to continue";
        string res;
        cin >> res;
        if (res != "Y") flag = 0;
    } while (flag);    
    cout<<"You are no longer a admin!"<<endl;
}

void forget_pass(){
    cout<<"To change new Password:-"<<endl;
    labelA:
    cout<<"Enter your email:";
    string email;
    cin>>email;
    int flag=0;
    // string pass;
    for(auto i:users){
        if(i.first==email){
            flag=1;
            // pass=i.second;
        }
    }
    if(flag==0){
        cout<<"Invalid email id"<<endl;
        goto labelA;
    }
    label1:
    cout<<"Enter the new Password:";
    string password;
    cin>>password;
    if (password == email) {
        cout << "Password should not be email or username"<<endl;
        goto label1;
    }
    if (password.size() > 15 || password.size() < 8) { 
        cout << "Password length should be 8 to 15 characters" << endl;
        goto label1;
    }
    int digit = 0, upper = 0, spl = 0, lower = 0;
    for (auto i : password) {
        if (isupper(i))  upper++;
        if (islower(i))  lower++;
        if (isdigit(i))  digit++;
        if (i == '$' || i == '&' || i == '@' || i == '%' || i == '*')  spl++;
    }
    if (upper == 0 || lower == 0 || digit == 0 || spl == 0) {
        cout << "Password should include one upper case, one lower case, one digit, one special character" << endl;
        goto label1;
    }
    int n = password.size();
    for (int i = 0; i < n; i++) {
        if (isupper(password[i]))
            password[i] = password[i] - 'A' + 2;
        if (islower(password[i]))
            password[i] = password[i] - 'a' + 2;
    }
    for(auto i:prev_pass[email]){
        if(i==password){
            cout<<"The new password should not match with the last used passwords"<<endl;
            goto label1;
        }
    }
    users[email]=password;
    if(prev_pass[email].size()>3)
    prev_pass[email].pop_front();
    prev_pass[email].push_back(password);
    cout<<"Your password is changed successfully!"<<endl;
}

void process(){
    // pass
}


void sign_in(){
    labelA:
    cout<<"Sign IN"<<endl;
    cout<<"Enter your Email id:";
    int flag=0;
    string email;
    string pass;
    cin>>email;
    for(auto i:users){
        if(i.first==email){
            flag=1;
            pass=i.second;
        }
    }
    if(flag==0){
        cout<<"Invalid email id"<<endl;
        goto labelA;
    }
    label1:
    cout <<"To enter the password press 1"<<endl<<"If you forget password press 0"<<endl;
    int pf;
    cin>>pf;
    if(pf==1){
        string password;
        cin>>password;
        int n = password.size();
        for (int i = 0; i < n; i++) {
            if (isupper(password[i]))
                password[i] = password[i] - 'A' + 2;
            if (islower(password[i]))
                password[i] = password[i] - 'a' + 2;
        }
        if(password==pass){
            cout<<"You have successfully signed in!"<<endl;
            process();
        }
        else{
            cout<<"Password is incorrect!"<<endl;
            goto label1;
        }
    }
    else{
        forget_pass();
    }
}

void registerUser() {
    int flag = 1;
    while (flag) {
        cout << "New user" << endl;
        cout << "Enter the user_name:";
        string username;
        cin >> username;
        int flag1=0;
        for (auto i : User_name) {
            if (i == username) {
                cout << "UserName already exists" << endl;
                flag1=1;
                continue;
            }
        }
        if(flag1==1) continue;
        cout << "Enter the email:";
        string email;
        cin >> email;
        flag1=0;
        for (auto i : Email) {
            if (i == email) {
                cout << "Email already exists" << endl;
                flag1=1;
                continue;
            }
        }
        if(flag1==1) continue;
        label1:
        cout<<"Enter the Date of birth:";
        string dob;
        cin>>dob;
        // stringstream ss(dob);
        // string delim="-";
        // string ans;
        // int i=0;
        // flag1=0;
        // while(getline(ss,ans,delim)){
        //     if(i==0){
        //         if(ans-'0'>31&&ans-'0'<1){
        //             flag1=1;
        //             break;
        //         }
        //     }
        //     else if(i==1){
        //         if(ans-'0'>12&&ans-'0'<1){
        //             flag1=1;
        //             break;
        //         }
        //     }
        //     else{
        //         if(ans-'0'==0){
        //             flag1=1;
        //             break;
        //         }
        //     }
        // }
        // if(flag1==1){
        //     cout<<"Date of birth is invalid!"<<endl<<"It should be in the format dd-mm-yyyy"<<endl;
        //     goto label1;
        // }
        labelA:
        string password;
        cout<<"Enter the password:";
        cin >> password;
        if (password == email || password == username) {
            cout << "Password should not be email or username"<<endl;
            goto labelA;
        }
        if (password.size() > 15 || password.size() < 8) { 
            cout << "Password length should be 8 to 15 characters" << endl;
            goto labelA;
        }
        int digit = 0, upper = 0, spl = 0, lower = 0;
        for (auto i : password) {
            if (isupper(i))  upper++;
            if (islower(i))  lower++;
            if (isdigit(i))  digit++;
            if (i == '$' || i == '&' || i == '@' || i == '%' || i == '*')  spl++;
        }
        if (upper == 0 || lower == 0 || digit == 0 || spl == 0) {
            cout << "Password should include one upper case, one lower case, one digit, one special character" << endl;
            goto labelA;
        }
        int n = password.size();
        for (int i = 0; i < n; i++) {
            if (isupper(password[i]))
                password[i] = password[i] - 'A' + 2;
            if (islower(password[i]))
                password[i] = password[i] - 'a' + 2;
        }
        User_name.push_back(username);
        // Password.push_back(password);
        Email.push_back(email);
        users[email] = password;
        prev_pass[email].push_back(password);
        flag = 0; 
        cout<<"User registered.Now You can Login"<<endl;
        sign_in();
    }
}



int main() {
    cout << "Welcome to Flight Booking System" << endl;
    cout << "1.Register" << endl << "2.Sign in" << endl << "3.Admin Login" << "4.Exit"<<endl;
    int choice;
    int flag = 0;
    do {
    cout << "Enter the choice:";
        cin >> choice;
        switch (choice) {
            case 1: {
                registerUser();
                continue;
                break;
            }
            case 2: {
                sign_in();
                break;
            }
            case 3:{
                admin();
                break;
            }
            case 4: {
                cout << "Thank you" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                flag = 1;
            }
        }
        cout << "Do you want to continue? Press Y to continue";
        string res;
        cin >> res;
        if (res != "Y") flag = 0;
    } while (flag);

    return 0;
}
