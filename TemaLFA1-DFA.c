#include <bits/stdc++.h>

using namespace std
ifstream f("index.txt");
ofstream g("oindex.txt");
int i,j,k,nrstarifinale,nrstariinitiale,starifinale[1001],stariinitiale[1001],nrCuv;
vector <pair<int,char>>gr[1001];
string cuvinte;
bool talent(const string &cuvinte,int curent,int starifinale[],int nrF)
{
    bool ok=0;
    int curr=0;
    int lex = cuvinte.size();
    while(curr<lex)
    {
        char litera = cuvinte[curr];
        bool litera_ap = 0;
        for(int i=0; i<gr[curent].size(); i++)
        {
            if(gr[curent][i].second() == litera)
            {
                litera_ap = true;
                curent = gr[curent][i].first();
                break;
            }
        }
        if(!litera_ap)
            return false;
        ++curr;
    }

    for(i=0; i<nrF; i++)
    {
        if(curent == starifinale[i])
            return true;
    }
    return false;

}
int main()
{
    int N;
    f>>N;
    for(int i=0; i<N; i++)
    {
        f>>stari[i];
    }
    int M;
    f>>M;
    for(int i=0; i<M; i++)
    {
        int x;
        int y;
        char lit;
        f>>x>>y>>lit;
        gr[x].push_back(make_pair(y,lit));
    }
    int S;
    f>>S;
    int nrF;
    f>>nrF;
    for(int i=0; i<nrF; i++)
    {
        f>>starifinale[i];
    }
    f>>cuvinte;
    for(int i=0; i<nrCuv; i++)
    {
        cin>>cuvinte;
        if(talent(cuvinte,S,starifinale,nrF))
            g<<"da"<<endl;
        else
            g<<"nu"<<endl;
    }
    return 0;
}
