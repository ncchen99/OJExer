#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N=0,M=0,now=0,big=0,sum=0;
    cin>>N>>M;
    vector<int> choosenum(N);
    vector<int> ans;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin>>now;
            if (now>big)
                big=now;
        }
        choosenum.at(i)=big;
        big=0;
    }
    for (int i=0; i<choosenum.size(); i++)
        sum+=choosenum.at(i);
    for (int i=0; i<choosenum.size(); i++)
    {
        if (sum%choosenum.at(i)==0)
            ans.push_back(choosenum.at(i));
    }
    cout<<sum<<endl;
    if(ans.empty())
    {
        cout<<-1<<endl;
    }
    else
    {
        for (int i=0; i<ans.size()-1; i++)
            cout<<ans.at(i)<<" ";
        cout<<ans.at(ans.size()-1)<<endl;
    }
}
