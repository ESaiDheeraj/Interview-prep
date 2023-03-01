#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int N)
    {
        parent.resize(N);
        size.resize(N);
        for (int i = 0; i < N; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void make_set(int v) // this function is (rarely) used only when we want to make a separate tree of v.
    {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) // path compression optimization is used in the last return statement.
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) // union by size optimization is followed, big tree will become parent of small tree.
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;      // a is now the parent of b.
            size[a] += size[b]; // so, add b's tree size to a's tree size.
        }
    }
};

int main()
{
    DSU dsu(10);
    cout << dsu.find_set(1) << endl;
    dsu.union_sets(2, 1);
    cout << dsu.find_set(1) << endl;
    return 0;
}