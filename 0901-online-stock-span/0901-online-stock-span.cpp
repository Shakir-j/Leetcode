/* // Brute Force Approach
class StockSpanner {
public:

    vector<int> arr;

    StockSpanner() {
        // vector<int> arr;
    }
    
    int next(int price) {
        arr.push_back(price);
        int count = 1;
        for(int i = arr.size() - 2; i >= 0; i--) {
            if(arr[i] <= price) {
                count++;
            } else {
                break;
            }
        }

        return count;
    }
}; */

// Optimal Approach
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;

    StockSpanner() {
        
    }

    int next(int price) {
        index++;
        
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});

        return ans;
    }
};




 

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */