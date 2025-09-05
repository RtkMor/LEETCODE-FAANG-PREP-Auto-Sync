class NumArray {
public:
    vector<int> segTree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n, 0);
        build(nums, 0, 0, n-1);
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            segTree[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, 2*node+1, l, mid);
        build(nums, 2*node+2, mid+1, r);
        segTree[node] = segTree[2*node+1] + segTree[2*node+2];
    }

    void update(int index, int val) {
        updateHelper(0, 0, n-1, index, val);
    }

    void updateHelper(int node, int l, int r, int idx, int val) {
        if (l == r) {
            segTree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) updateHelper(2*node+1, l, mid, idx, val);
        else updateHelper(2*node+2, mid+1, r, idx, val);

        segTree[node] = segTree[2*node+1] + segTree[2*node+2];
    }

    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return segTree[node];
        int mid = (l + r) / 2;
        return query(2*node+1, l, mid, ql, qr) +
               query(2*node+2, mid+1, r, ql, qr);
    }
};
