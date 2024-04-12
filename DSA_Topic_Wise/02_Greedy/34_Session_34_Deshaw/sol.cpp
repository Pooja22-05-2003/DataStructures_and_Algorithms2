/*
Organically brain says.-> that all the numbers which are absent we make a list of them in sorted order 

-> What will be the next task 

-> Put these number lists in the original array somehow. 

-> The first number of our new array should be coming at first place of original array generally 

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> arr)
{
    unordered_map<int, int> freq;
    unordered_map<int, int> used;

    for (auto it : arr)
        freq[it]++;

    // trial will store the missing element in the sorted order
    // sorted order because we are iterating from 1 to n, and that is the sorted order traversal
    vector<int> trial;

    // numbers in the array are present from 1 to n
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            trial.push_back(i);
        }
    }

    // take two pointers, i will travel throught the original array and j will travel through the trial array

    int u = trial.size();
    int i = 0; // i travel through the trial arr

    int v = 0; // v travel through the original arr
    while (v < n)
    {

        if (i <= u - 1)

        {

            int yy = trial[i];

            if (arr[v] > n)
            {
                freq[arr[v]]--;
                arr[v] = yy;
                used[yy] = 1;
                i++;
            }
            else if (arr[v] > yy)
            {

                if (freq[arr[v]] >= 2)
                {
                    freq[arr[v]]--;
                    arr[v] = yy;

                    used[yy] = 1;
                    i++;
                }

                else
                {
                    freq[arr[v]]--;
                    if (used[arr[v]] == 0)
                    {
                        used[arr[v]] = 1;
                    }
                    else
                    {
                        arr[v] = yy;
                        used[yy] = 1;
                        i++;
                    }
                }
            }
            else
            {
                freq[arr[v]]--;
                if (used[arr[v]] == 0)
                {
                    used[arr[v]] = 1;
                }

                else
                {
                    arr[v] = yy;
                    used[yy] = 1;
                    i++;
                }
            }
        }

        // else will run, if trial array exhausted
        else
        {
            freq[arr[v]]--;
            used[arr[v]] = 1;
        }

        v++;
    }
    return arr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = solve(n, arr);

    // cout << "ans:" << ans << endl;
    for(auto it: ans) cout<<it<<",";
    cout<<endl;
    return 0;
}

/*
Input1:
7
6 4 9 10 34 56 54


Output:
ans:68





*/