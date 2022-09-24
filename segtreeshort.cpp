struct segtree{
    vector<ll> st; //segement tree array (contains all nodes)
    ll n;
    void init(ll val){
        n = val;
        st.resize(n*4,0);
    }
 
    void build(ll start,ll end,ll idx,vector<ll>&arr){
        if(start==end){
            st[idx] = arr[start]; return;
        }
        ll mid = start + (end-start)/2;
        build(start,mid,2*idx + 1,arr);
        build(mid+1,end,2*idx + 2,arr);
        st[idx] = max(st[2*idx + 1],st[2*idx + 2]);
    }
 
    ll query(ll start,ll end,ll idx,vector<ll>&arr,ll l,ll r){
        if(l<start && r<start || l>end && r>end) return 0;
        if(start>=l && end<=r) return st[idx];
        ll mid = start + (end-start)/2;
        ll q1 = query(start,mid,2*idx + 1,arr,l,r);
        ll q2 = query(mid+1,end,2*idx + 2,arr,l,r);
        return max(q1,q2);
    }
 
    void update(ll start,ll end,ll idx,vector<ll>&arr,ll req_idx,ll req_val){
        if(start==end){
            st[idx] = req_val; return;
        }
        ll mid = start + (end-start)/2;
        if(req_idx<=mid){
            update(start,mid,2*idx + 1,arr,req_idx,req_val);
        }
        else{
            update(mid+1,end,2*idx + 2,arr,req_idx,req_val);
        }
        st[idx] = max(st[2*idx + 1],st[2*idx + 2]);
    }
 
    void display(){
        for(auto itr:st){
            cout<<itr<<" ";
        }
        cout<<en;
    }
};