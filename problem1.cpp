#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;


struct Session{
    string name;
    int starting_time;
    int duration;
    
};

int main(){
    ifstream f;
    f.open("schedule.txt");
    vector<Session> vec;
    Session temp;
    string TEMP;
    int numb;


    while(!(f.eof())){
        f >> TEMP;
        temp.name = TEMP;
        f >> numb;
        temp.starting_time = numb;
        f >> numb;
        temp.duration = numb;
        vec.push_back(temp);
    }


    sort(vec.begin(),vec.end(), [](const Session& left, const Session& right){
        return left.starting_time + left.duration < right.starting_time + right.duration;
    });


    int no_of_sessions = 0;
    int prev_ending_time = 0; // This is the ending time of the latest session we attend.


    for (int i = 0; i < vec.size(); i++){
        if (vec[i].starting_time >= prev_ending_time) { //If the starting time of the ith session is after the ending time of previous session, It will be the next session
            no_of_sessions++;
            prev_ending_time = vec[i].duration + vec[i].starting_time; // Changing the latest ending time
        }
    }
    cout << no_of_sessions << "\n";
}
