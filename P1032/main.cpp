/*
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define maxn 15
using namespace std;
struct node{
    string str;
    int step;
};

string a,b;
string original[maxn];
string translate[maxn];
int n,ans;
map<string,int> ma;

string trans(const string &str,int i,int j)
{
    string ans = "";
    if (i+original[j].length() > str.length())
        return ans;

    for (int k=0; k < original[j].length();k++)
        if (str[i+k] != original[j][k])
            return ans;

    ans = str.substr(0,i);
    ans+=translate[j];
    ans+=str.substr(i+original[j].length());
    return ans;
}

void bfs()
{
    queue <node> q;
    node s;
    s.str = a;
    s.step = 0;
    q.push(s);

    while (!q.empty()){
        node u = q.front();
        q.pop();
        string temp;

        if(ma.count(u.str) == 1)
            continue;

        if (u.str == b){
            ans = u.step;
            break;
        }
        ma[u.str] = 1;
        for (int i=0;i < u.str.length();i++)
            for (int j=0; j<n; j++)
            {
                temp = trans(u.str,i,j);
                if (temp != ""){
                    node v;
                    v.str = temp;
                    v.step = u.step+1;
                    q.push(v);
                }
            }
    }
    if (ans > 10 || ans == 0)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;

}

int main(){
    cin >> a >> b;

    while (cin >> orginal[n] >> translated[n])
        n++;
    bfs();
    return 0;
}
 */



#include <bits/stdc++.h>
#include <queue>
#include <set>
using namespace std;

struct Node{
    string str;
    int step;
    Node(){}
    Node(string str, int s): str(str), step(s){}
};
int n;
string original[15], translate[15];
string a, b;
int ans;

string trans(const string &str,int i,int j)
{
    string ans = "";
    if (i+original[j].length() > str.length())
        return ans;

    for (int k=0; k < original[j].length();k++)
        if (str[i+k] != original[j][k])
            return ans;

    ans = str.substr(0,i);
    ans+=translate[j];
    ans+=str.substr(i+original[j].length());
    return ans;
}


void bfs() {
    queue<Node> que;
    set<string> s;
    que.push(Node(a, 0));

    while (!que.empty()) {
        Node temp = que.front();
        que.pop();

        if (temp.str == b)
        {
            ans = temp.step;
            break;
        }
        if (s.count(temp.str) || temp.step >= 10)
            continue;
        s.insert(temp.str);
//        for (int i = 0; i < n; i++){
//            int idx = temp.str.find(original[i]);
//            if (idx < temp.str.length()) {
//                string newStr = temp.str.substr(0, idx);
//                newStr += translate[i];
//                if (idx + original[i].length() < temp.str.length())
//                    newStr += temp.str.substr(idx+original[i].length());
//cout << newStr<<endl;
//                que.push(Node(newStr, temp.step+1));
//            }
//        }
        for (int i=0;i < temp.str.length();i++)
            for (int j=0; j<n; j++) {
                string newStr = trans(temp.str, i, j);
                if (newStr != "") {
                    que.push(Node(newStr, temp.step + 1));
                }
            }
    }

    if (ans != 0 && ans <= 10)
        cout << ans << endl;
    else
        cout << "NO ANSWER!" << endl;
}

/*
void bfs()
{
    queue <Node> q;
    set<string>se;
    Node s(a,0);
    q.push(s);

    while (!q.empty()){
        Node u = q.front();
        q.pop();
        string temp;

        if(se.count(u.str) == 1)
            continue;

        if (u.str == b){
            ans = u.step;
            break;
        }
        se.insert(u.str);
        for (int i=0;i < u.str.length();i++)
            for (int j=0; j<n; j++)
            {
                temp = trans(u.str,i,j);
                if (temp != ""){
                    Node v;
                    v.str = temp;
                    v.step = u.step+1;
                    q.push(v);
                }
            }
    }
    if (ans > 10 || ans == 0)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;

}
*/


//int main() {
//    cin >> a >> b;
//    cin >> n;
//    getchar();
//    for (int i = 0; i < n; i++)
//       cin >> original[i] >> translate[i];
////    for (int i = 0; i < n; i++)
////        cout << original[i] << ' '<<translate[i]<<endl;
//    bfs();
//    return 0;
//}

int main(){
    cin >> a >> b;
    while (cin >> original[n] >> translate[n])
        n++;
    bfs();
    return 0;
}
