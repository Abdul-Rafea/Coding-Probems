#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_set<int> unique_numbers;

        for (int i = 0; i < digits.size(); i++) {
            if (digits.at(i) == 0) {
                continue;
            }

            int index1 = i;

            for (int j = 0; j < digits.size(); j++) {
                if (j == index1) {
                    continue;
                }

                int index2 = j;

                for (int k = 0; k < digits.size(); k++) {
                    if (k == index1 || k == index2) {
                        continue;
                    }

                    if (digits.at(k) % 2 == 0) {
                        int number = (digits.at(i) * 100) + (digits.at(j) * 10) + digits.at(k);
                        unique_numbers.insert(number);
                    }
                }
            }
        }

        return unique_numbers.size();
    }
};

int main() {
    Solution solution;
    vector<int> numbers = { 1, 2, 3, 4 };

    int combinations = solution.totalNumbers(numbers);

    cout << "Even Numbers: " << combinations;

	return 0;
}