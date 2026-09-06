#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> num;
    int num_count;

    cin >> num_count;

    for (int i = 0; i < num_count; i++) {
        int number;
        cin >> number;
        num.push_back(number);
    }

    //vector_sort
    int loop_count = 0;
    if (num_count % 2 == 0) {
        loop_count = (num_count / 2) - 1;
    }
    else {
        loop_count = (num_count / 2);
    }
    for (int i = 0; i < loop_count; i++) {
        int smallest_index = i;
        int largest_index = num_count - (i + 1);

        for (int j = i + 1; j < num_count - (i + 1); j++) {
            if (num.at(j) < num.at(smallest_index)) {
                smallest_index = j;
            }

            if (num.at(j) > num.at(largest_index)) {
                largest_index = j;
            }
        }

        int temp_num = num.at(i);
        num.at(i) = num.at(smallest_index);
        num.at(smallest_index) = temp_num;

        temp_num = num.at(num_count - (i + 1));
        num.at(num_count - (i + 1)) = num.at(largest_index);
        num.at(largest_index) = temp_num;

    }

    for (int i = 0; i < num_count; i++) {
        cout << num.at(i) << " ";
    }

    return 0;
}