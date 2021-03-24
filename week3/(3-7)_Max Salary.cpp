#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iterator>
#include<ctime>
#include<sstream>
//#include<string>

using namespace std;
typedef long long ll;

int functor(string a,string b)
{
string ab = a.append(b);
string ba = b.append(a);

return ab.compare(ba)>0?1:0;
}

string max_salary(vector<string>&v,int n)
{
    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: sorting some papers has numbers to get max salary (sorting some numbers descending)
    //pre-required: sorted numbers as string in vector
    //Max n size will be 10^2 ==> int
    //Max input number will be 10^3 ==> 4 digit
    //Max result will be (input digits * 100) 4 digit * 100 = 400 digits ==> String is better (no range enough for 400 digit LOL)
    //Sort Algorithm O(n) = nlog(n)
    // This Algorithm ==> O(n)= n ==> total = n + nlog(n) = nlog(n)
    //////////////////////////////////////////////////////////////////////////////////////////////


    /*
    //convert from int to string (to concatenate)
    for(int i=0;i<n;i++)
    {
        stringstream ss;
        ss<<v[i];
        string temp;
        ss>>temp;
        str+=temp;
    }*/

    /*sort(v.rbegin(),v.rend());
    string res = v[0];
    for(int k=1;k<n;k++)
    {
        string x= res;
        string y= v[k];
        int m=max(x.length(),y.length());
        for(int i=0;i<m;i++)
        {
           if(x[i]>y[i])
           {
               res=x+y;
               break;
           }

            else if(y[i]>x[i])
            {
                res=y+x;
                break;
            }

            else if(i==x.length()-1)
            {
               res=x+y;
               break;
            }

            else if(i==y.length()-1)
            {
               res=y+x;
               break;
            }
        }*
    }

    sort(v.rbegin(),v.rend());
    string res =v[0];
    int curr=0;
    int i;
    for(i=1;i<n;i++)
    {
        if(v[i]+res>res+v[i] && i<n) //if(v[curr][0]==v[i][0]&& v[curr].length()>v[i].length())
        {
            res = v[i]+res;
            swap(v[curr],v[i]);
        }
        else
            res+=v[i];


    }*/
    string res;
    sort(v.begin(),v.end(),functor);
    for(int i=0;i<n;i++)
    {
        res+=v[i];
    }
    return res;

}


string max_salary2(vector<string>&v,int n)
{
    sort(v.rbegin(),v.rend());
    string res="";
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {

          if(v[j]+v[i]>v[i]+v[j])  //problem was in forgetting last condition //v[j][0]>=v[i][0]&& v[i].length()>v[j].length() //if((isize>jsize && v[j]>=v[i].substr(0,jsize) && v[i][0]>v[i][isize-1]) || (v[j]>v[i]))
          {
              string temp = v[j];
              v.erase((v.begin())+j);
              v.insert((v.begin())+i,temp);
              i--;
              break;
          }

        }
    }

    for(i=0;i<n;i++)
    {
        res+=v[i];
    }
    return res;
}




int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<max_salary2(v,n)<<'\n';

    /*//Stress Testing
    srand(time(0));
    int n = 1+rand()%100; // generate rand number in range 1:100
    vector<string> v(n);
    //cout<<"n= "<<n<<'\n';
    while(true)
    {
        cout<<"\n\nv=";
        for(int i =0;i<n;i++)
            {
                stringstream ss;
                string s;
                ss<<1+rand()%1000;
                ss>>s;
                v[i]=s;        //fill the vector by random number in range 1:100
                cout<<' '<<s;
            }
            cout<<'\n';
            sort(v.rbegin(),v.rend());
            cout<<"v=";
            for(int i=0;i<n;i++)
                cout<<v[i]<<' ';
            cout<<'\n';
            string x1 = max_salary(v,n);
            string x2 = max_salary2(v,n);
            cout<<x1<<'\n';
            cout<<x2<<'\n';
            if(x1 == x2 ) //&& x1.length()>=x2.length();
                cout<<"OK\n\n"<<'\n';

            else //if(x1>x2 )
            {
                if(x1>x2)
                    cout<<"NO X1>X2\n\n"<<'\n';
                else
                    cout<<"NO X2>X1\n\n"<<'\n';

                break;
            }


            //system("PAUSE");
    }*/


}


