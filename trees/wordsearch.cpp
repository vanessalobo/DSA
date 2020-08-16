#include<string>
#include<iostream>

#include<bits/stdc++.h>
#include <vector>
int main()
{

    vector<string> s;
    s.push_back("cat");
    s.push_back("cct");
    s.push_back("cct");
    vector<vector<char>> mat;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            mat[i][j]=s[i].at(j);
        }

    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
