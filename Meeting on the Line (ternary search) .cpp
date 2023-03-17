#include<bits/stdc++.h>
using namespace std;
int t,n,x;
vector<long double> ans;
long double huy(long double x,vector<int> & X, vector<int> & T)
{
    long double picaro=DBL_MIN;
    for(int i=0;i<=X.size()-1;i++)
    {
        picaro=max(picaro,abs(x- double(X[i]))+ double(T[i]));
    }
    return picaro;
}
int main()
{
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        vector<int> X,T;
        long double left=INT_MAX,right=INT_MIN;
        long double mi=DBL_MAX,index,mid1,mid2,f1,f2;
        cin >> n;
        for(int j=1;j<=n;j++)
        {
            cin >> x;
            long double h=x;
            left=min(left,h);
            right=max(right,h);
            X.push_back(x);
        }
        for(int j=1;j<=n;j++)
        {
            cin >> x;
            T.push_back(x);
        }
        long double a=huy(left,X,T),b=huy(right,X,T);
        mi=min(a,b);
        if(mi==a) index=left;
        if(mi==b) index=right;
        while(right-left>=1e-6)
        {
            cout << right << " " << left << endl;
            mid1=left+(right-left)/3;
            mid2=right-(right-left)/3;
            f1=huy(mid1,X,T);
            f2=huy(mid2,X,T);
            cout << f1 << " " << f2 << endl;
            cout << endl;
            mi=min(mi,min(f1,f2));
            if(mi==f1) index=mid1;
            if(mi==f2) index=mid2;
            if(f1==f2)
            {
                left=mid1;
                right=mid2;
            }
            if(f1>f2)
            {
                left=mid1;
            }
            if(f1<f2)
            {
                right=mid2;
            }
        }
        ans.push_back(index);
    }
    for(auto i:ans)
    {
        cout << i << endl;
    }
}
