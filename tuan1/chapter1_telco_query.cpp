//C++ 
#include <bits/stdc++.h> 
using namespace std;

int is_valid(string number) {
    if (number.length() != 10) return 0;
    for (size_t i = 0; i < number.length(); i++) {
        if (!isdigit(number[i])) return 0;
    }
    return 1;
}

int time_to_seconds(string time_str) {
    int h, m, s;
    sscanf(time_str.c_str(), "%d:%d:%d", &h, &m, &s);
    return h*3600 + m*60 + s;
}



int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<string, int> number_calls;
    map<string, int> time_call;
    int valid_phone = 1;
    int total_calls = 0;
    
    string line;
    
    while (true) {
        string cmd, from_number, to_number, date, from_time, end_time;
        cin >> cmd;
        
        if (cmd == "#") break;
        
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        
        if (!is_valid(from_number) || !is_valid(to_number)) valid_phone = 0;
        
        int start_second = time_to_seconds(from_time);
        int end_second = time_to_seconds(end_time);
        
        number_calls[from_number]++;
        time_call[from_number] += (end_second - start_second);
        total_calls++;
    }
    
    while(true) {
        string query;
        cin >> query;
        
        if (query == "#") break;
        
        if (query == "?check_phone_number") {
            cout << valid_phone << endl;
        }
        else if (query == "?number_calls_from") {
            string phone_number;
            cin >> phone_number;
            cout << (number_calls.count(phone_number) ? number_calls[phone_number] : 0) << endl;
        }
        else if (query == "?number_total_calls") {
            cout << total_calls << endl;
        }
        else if (query == "?count_time_calls_from") {
            string phone_number;
            cin >> phone_number;
            cout << (time_call.count(phone_number) ? time_call[phone_number] : 0) << endl;
        }
    }
    
    return 0;
    
}
