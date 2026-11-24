class RandomizedSet {
public:

    unordered_map<int,int>mp;
    vector<int>v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.contains(val))
      {v.push_back(val);    // adding value to the vector

      mp[val]=v.size()-1;     // storing [ index : value ]
      return true;
      }    

      return false;

    }
    
    bool remove(int val) {
        if(mp.contains(val))  // if present
        {
            int i=mp[val];
            int le=v.back();

            v[i]=le;

            v.pop_back();

            mp.erase(val);

            if(val!=le)     // updating th eindex of the last element 
            mp[le]=i;

            return true;

        }

        return false;
    }
    
    int getRandom() {
        if(v.size()!=0)
        {int index=rand()%v.size();

        return v[index];}

        return v[0];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */