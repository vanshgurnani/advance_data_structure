#include <iostream>

using namespace std;

class graph{
    int cost[10][10];
    int tcities;

    public:
    graph();
    void create();
    void display();
    int prims(int start_v);

};

graph::graph(){
    tcities = 0;
    cout << "\nEnter the number of cities: ";
    cin >> tcities;
    for (size_t i = 0; i < tcities; i++)
    {
        for (size_t j = 0; j < tcities; j++)
        {
            cost[i][j] = 999;
        }
        
    }
    
}

void graph::create(){
    for (size_t i = 0; i < tcities; i++)
    {
        for (size_t j = i+1; j < tcities; j++)
        {
            cout << "Enter the cost of " << i << j << ": ";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
        
    }
    
}

void graph::display(){
    for (size_t i = 0; i < tcities; i++)
    {
        for (size_t j = 0; j < tcities; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
    
}

int graph::prims(int start_v){
    int nearest[tcities];
    int t[tcities-1][3];
    int mincost = 0, j;
    nearest[start_v] = -1;
    for (size_t i = 0; i < tcities; i++)
    {
        if (i != start_v)
        {
            nearest[i] = start_v;
        }
        
    }
    int r = 0;
    for (size_t i = 1; i < tcities; i++)
    {
        int min = 999;
        for (size_t k = 0; k < tcities; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]]<min)
            {
                j=k;
                min = cost[k][nearest[k]];
            }
            
        }

        t[r][0] = j;
        t[r][1] = nearest[j];
        t[r][2] = cost[j][nearest[j]];
        r = r+1;
        mincost = mincost + cost[j][nearest[j]];
        nearest[j] = -1;

        for (size_t k = 0; k < tcities; k++)
        {
            if(nearest[k] != -1 && cost[k][nearest[k]]> cost[k][j])
                nearest[k] = j;
        }
    }

    for (size_t i = 0; i < tcities-1; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }

    return mincost;
    
}



int main(){
    int min;
    int start_v = 0;
    graph a;
    a.create();
    a.display();
    cout << "\nEnter start vertex: ";
    cin >> start_v;
    min = a.prims(start_v);
    cout << "\nMinimun cost: " << min;

    return 0;
}