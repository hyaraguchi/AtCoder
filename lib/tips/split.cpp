#include <vector>
#include <string>
using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

int main() {
    string line;
    // line を ',' で区切る。
    vector<string> tmp = split(line, ',');

    return 0;
}