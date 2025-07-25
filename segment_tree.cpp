#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  int long long
#define  endl "\n"
struct Node
{
    long long val;

    Node()
    {
        // update this variable to a value that has no effect on the answer of the operation
        val = 1e15;
    }

    Node(long long x)
    {
        val = x;
    }
    void change (int x )
    {
        val+=x ;

    }

};

struct SegTree
{
    int tree_size;
    vector<Node> seg_data;
    SegTree(int n)
    {
        tree_size = 1;
        while (tree_size < n) tree_size *= 2;
        seg_data.resize(2 * tree_size, Node());
    }

    // update this function for the desired operation
    Node merge(Node & lf, Node & ri)
    {
        Node ans = Node();
        ans.val = min(lf.val, ri.val);
        return ans;
    }

    void init(vector<long long> & nums, int ni, int lx, int rx) {

        if(rx - lx == 1)
        {
            if(lx < (int)nums.size())
            {
                seg_data[ni] = Node(nums[lx]);
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;
        init(nums, 2 * ni + 1, lx, mid);
        init(nums, 2 * ni + 2, mid, rx);

        seg_data[ni] = merge(seg_data[2 * ni + 1], seg_data[2 * ni + 2]);
    }

    void init(vector<int> & nums)
    {
        init(nums, 0, 0, tree_size);
    }

    void set(int idx, long long value, int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            seg_data[node] = Node(value);
            return;
        }

        int mid = (lx + rx) / 2;
        if(idx < mid)
            set(idx, value, 2 * node + 1, lx, mid);
        else
            set(idx, value, 2 * node + 2, mid, rx);

        seg_data[node] = merge(seg_data[2 * node + 1], seg_data[2 * node + 2]);
    }
    void set(int idx, long long value) // zero indexed
    {
        set(idx, value, 0, 0, tree_size);
    }

    Node get_range(int l, int r, int node, int lx, int rx)
    {
        if(lx >= l && rx <= r)
            return seg_data[node];
        if(rx <= l || lx >= r)
            return Node();

        int mid = (lx + rx) / 2;

        Node lf = get_range(l, r, 2 * node + 1, lx, mid);
        Node ri = get_range(l, r, 2 * node + 2, mid, rx);
        return merge(lf, ri);
    }

    long long get_range(int l, int r) // zero indexed range and get from l to r-1, i.e [l,r)
    {
        return get_range(l, r, 0, 0, tree_size).val;
    }
};
void solve()
{
    
}
signed main()
{
    int t = 1; cin>>t;
    while (t--)
    {
        
    }
    
}
