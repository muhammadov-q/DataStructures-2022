#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    for (int nCourses; cin >> nCourses && nCourses != 0;)
    {
        int nCategories;
        cin >> nCategories;

        vector<int> courses(nCourses);
        for (auto &course : courses)
        {
            cin >> course;
        }

        bool hasPassed = true;
        for (int i = 0; i < nCategories; ++i)
        {
            int nCoursesInCategory;
            cin >> nCoursesInCategory;
            int minRequired;
            cin >> minRequired;

            vector<int> categoryCourses(nCoursesInCategory);
            for (auto &course : categoryCourses)
            {
                cin >> course;
            }

            sort(categoryCourses.begin(), categoryCourses.end());

            int nTaken = 0;
            for (auto course : courses)
            {
                nTaken += binary_search(categoryCourses.begin(),categoryCourses.end(), course);
            } 
            
            if (nTaken < minRequired)
            {
                hasPassed = false;
            }
        }
        cout << (hasPassed ? "yes\n" : "no\n"); 
    }
}