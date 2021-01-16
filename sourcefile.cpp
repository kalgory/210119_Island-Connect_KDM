#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> node;
int N = 0;

int solution(int,vector<vector<int> >);

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

int find(int a) {
    if (a == node[a]) return a;
    return node[a] = find(node[a]);
}

bool merge(int a,int b) {
    a=find(a);
    b=find(b);
    cout<<"current  \t"<<a<<"\t"<<b<<endl;
    if(a==b) return false;
    if(b<a) swap(a,b);
    node[a]=a;
    node[b]=a;
    return true;
}

int main() {
    cin >> N;
    vector <vector<int> > temp(N + 1, vector<int>(3, 0));

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp[i][j];
        }
    }
    solution(N,temp);
}

int solution(int n, vector <vector<int> > costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    node.resize(n);
    for (int i = 0; i < n; i++) {
        node[i] = i;
    }
    for(int i=0;i<costs.size();i++){
        if(merge(costs[i][0],costs[i][1])) answer+=costs[i][2];
    }
    return answer;
}