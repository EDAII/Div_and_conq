#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> pontos;

int nAleatorio(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
}

int menor_dist(vector<pair<int,int>> v){
    if(v.size()==1) return 100;
    if(v.size()==2) return sqrt( pow(v[1].first - v[0].first,2) + pow(v[1].second-v[0].second,2) );
    else {
        vector<pair<int,int>> e;
        vector<pair<int,int>> d;
        for(int i=0;i<v.size()/2;i++){
            e.push_back(v[i]);
        }
        for(int i=v.size()/2;i<v.size();i++){
            d.push_back(v[i]);
        }
        cout << endl << "-----------------------" <<endl;
        for(int i=0;i<e.size();i++){
            cout << e[i].first << "|" << e[i].second <<endl;
        }
        cout << "-----------------------" <<endl;
        for(int i=0;i<d.size();i++){
            cout << d[i].first << "|" << d[i].second <<endl;
        }
        cout << "-----------------------" <<endl;

        int md = min(menor_dist(e),menor_dist(d));
        vector<pair<int,int>> c;
        int mediana = (v[(v.size()/2)-1].first+v[v.size()/2].first)/2;
        cout << "Mediana: " << mediana << endl<< "Menor distância até agora nessa área: " << md <<endl;
        for(int i=0;i<v.size();i++){
            if(v[i].first<mediana+md && v[i].first>mediana-md) c.push_back(v[i]);
        }
        if(!c.empty()) cout << "Pontos que distam " << md << " da linha L:" <<endl;
        for(int i=0;i<c.size();i++){
            cout << c[i].first << "|" << c[i].second <<endl;
        }
        if(!c.empty() && c.size()!= v.size()) return min(menor_dist(c),md);
        else return md;

    }
}

int main(){
    srand((unsigned)time(0));

    int x,y,n=16;
    pair <int,int> ponto;

    for(int i=0;i<n;i++){
        x = nAleatorio(0,100);
        y = nAleatorio(0,100);
        ponto = make_pair (x,y);
        pontos.push_back(ponto);
    }
    for(int i=0;i<n;i++){
        cout << pontos[i].first << "|" << pontos[i].second <<endl;
    }
    cout <<endl;
    sort(pontos.begin(), pontos.end());
    for(int i=0;i<n;i++){
        cout << pontos[i].first << "|" << pontos[i].second <<endl;
    }
    cout << endl << "A menor distância entre pontos é: " << menor_dist(pontos) <<endl;
}
