#include <vector>
#include <iostream>

using namespace std;

int main () {
    vector<vector <int> >map;
    for (int i = 0; i < 3; i++) {
        vector<int>temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back(i);
        }
        map.push_back(temp);
    }
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
