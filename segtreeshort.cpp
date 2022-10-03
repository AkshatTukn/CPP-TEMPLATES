struct segtree
{ 
  vector<PLL>store;
  ll n;
  void init(ll x)
  {
    n=x;
    store.resize(x*4,{0,-1});
  }
void build(ll start,ll end,ll ind,vector<ll>vals)
{
      if(start == end)
      {
         store[ind] = {vals[start],start};
         return;
      }
 
 ll mid = start+ (end-start)/2;
build(start,mid,2*ind+1,vals);
build(mid+1,end,2*ind+2,vals);

store[ind]=Max(store[2*ind+1],store[2*ind+2]);
}

pair<long,long>query1(ll start,ll end,ll ind,ll l, ll r)
{
    if((l < start && r<start ) || (l>end && r>end))
          {
             return {-9223372036854775807LL,0};
         }
 if(start>=l && end<=r)
 {
  return store[ind];
 }
ll mid= start + (end-start)/2;
PLL OPS1= query1(start,mid,2*ind+1,l,r);
PLL OPS2= query1(mid+1,end,2*ind+2,l,r);

return Max(OPS1,OPS2);
}
void update(ll start,ll end,ll ind,ll need_ind,ll valAdd)
{
 if(start == end)
 {
     store[ind].F += valAdd;
     return;
 }

ll mid = start+ (end-start)/2;
if(need_ind<=mid)
{
 update(start,mid,2*ind+1,need_ind,valAdd);
}else
{
  update(mid+1,end,2*ind+2,need_ind,valAdd);
}
store[ind]=Max(store[2*ind+1],store[2*ind+2]);
}

};
