class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cost = 0, count = 0;

        for(const int& c: costs) {
            if(cost + c > coins){
                break;
            }
            cost += c;
            count++;
        }

        return count;
    }
};