//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
  
  int lim = 0;
  int ctr=0;
  unordered_map<int,int> mp;
  unordered_map<int,int> del;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        lim = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.count(key))
        {
            del[key] = ctr++;
            return mp[key];
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp.size() == lim)
        {
            if(mp.count(key))
            {
                mp[key] = value;
                del[key] = ctr;
            }
            else
            {
                int mini = INT_MAX;
                int k = -1;
                for(auto it : del)
                {
                    if(it.second < mini)
                    {
                        mini=it.second;
                        k= it.first;
                    }
                    // we got the key with minimumtime
                }
                if(k!=-1)
                {
                    mp.erase(k);
                    del.erase(k);
                }
                mp[key] = value;
                del[key] = ctr;
            }
        }
        else
        {
                mp[key] = value;
                del[key] = ctr;           
        }
        ctr++;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends