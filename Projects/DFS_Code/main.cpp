#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graphs{
private:
    vector<set <int>>  letter;              // под цифрой лежат цифры куда можной пойти
    vector<int> colors;                     // 0 - белый   1 - серый    2 - черный
public:
    Graphs(){
        colors.resize(10,0);
        letter.resize(10);
    }

    void add(int from, int to){
        letter[from].insert(to);
    }

    void print(){
        for (set <int> i : letter) {
            for (int g : i) cout << g << "  ";
            cout << endl;
        }
    }
};

int main() {
    Graphs Letters;
    string BeforeWord, NowWord;

    cin >> BeforeWord;
    int i = 0;

    while(cin >> NowWord){
        while(BeforeWord[i] == NowWord[i] and i < 4) i++;
        Letters.add(BeforeWord[i] - 'A', NowWord[i] - 'A');
        BeforeWord = NowWord;
    }

    Letters.print();

    cout << "check! \n";
    return 0;
}