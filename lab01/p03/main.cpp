#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const int kNameWidth = 30;
    const int kAvgWidth = 40;
    
    for (string name; cin >> name;)
    {
        double sum = 0;
        int nGrades = 0;
        for (int grade; cin >> grade;) 
        {
            sum += grade;
            ++nGrades;
        }

        cout << setfill('.') << fixed << setprecision(2);
        if (nGrades != 0)
        {
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAvgWidth) << sum / nGrades << "\n";
        }
        else
        {
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAvgWidth) << "no data" << "\n"; 
        }
        cin.clear();
    }
}
