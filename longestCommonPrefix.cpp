#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        char character;
        auto shortstring = min_element(strs.begin(), strs.end(), [](const string one, const string two){return one.length() < two.length();});
        int length = shortstring->length();
        int index = 0;
        while (index < length){
            for (string str: strs){
                if (prefix.length() < index + 1){
                    prefix += str[index];
                    character = str[index];
                    continue;
                }
                if (character != str[index]){
                    return prefix.substr(0, prefix.length() - 1);
                }
            }
            ++index;
        }
        return prefix;
    }
};
