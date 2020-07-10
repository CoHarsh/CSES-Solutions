/*
Problem Name: Tree Isomorphism I
Problem Link: https://cses.fi/problemset/task/1700
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

string dfs(int s, int p, vector<int> adj[]) {
    vector<string> v;
    for (auto i: adj[s]) {
        if (i != p) 
            v.push_back(dfs(i, s, adj));
    }
    sort(v.begin(), v.end());
    string ans = "(";
    for (auto i: v)
        ans += i;
    ans += ')';
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> adj1[n+1], adj2[n+1];
        for (int i = 1; i < n; i++) {
            int x,y; cin>>x>>y;
            adj1[x].push_back(y);
            adj1[y].push_back(x);
        }
        for (int i = 1; i < n; i++) {
            int x,y; cin>>x>>y;
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
        string s1 = dfs(1, -1, adj1);
        string s2 = dfs(1, -1, adj2);
        if (s1 == s2)
            cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}