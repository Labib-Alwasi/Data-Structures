#include <iostream>
#include "date.hpp"

using namespace std;

int main() {

    date dates[21];
    int daynumber[21], y,m,d, counter=0;
    cout << "Enter the dates in year month day format, one per line. To finish, enter the date 0 0 0." << endl;

    cin >> y >> m >> d;
    while(y != 0 && m != 0 && d != 0)  {
        dates[counter] = date(y,m,d);
        counter++;
        cin >> y >> m >> d;
    }

    for(int i = 0; i < counter; i++) {
        dates[counter] = date(y, m, d);
        daynumber[i] = dates[i].get_date_number();
    }
    for(int starting_point = 0; starting_point < counter; starting_point++) {
        int index_of_smallest_so_far = starting_point;
        int smallest_so_far = daynumber[index_of_smallest_so_far];
        date temp = dates[index_of_smallest_so_far];
        for (int i = starting_point + 1; i < counter; i++) {
            if (daynumber[i] < smallest_so_far) {
                smallest_so_far = daynumber[i];
                index_of_smallest_so_far = i;
                temp = dates[i];
            }
        }

        daynumber[index_of_smallest_so_far] = daynumber[starting_point];
        daynumber[starting_point] = smallest_so_far;
        dates[index_of_smallest_so_far] = dates[starting_point];
        dates[starting_point] = temp;

    }
    for (int i = 0; i < counter; i++) {
        dates[i].print_diagnostics();
        cout << daynumber[i] << endl;
    }
    return 0;
}
