class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;

        for(int pile : piles) {
            maxi = max(maxi, pile);
        }

        int l = 1;
        int r = maxi;
        int lowestk = maxi;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int k = mid;

            long long hrs = 0;

            for(int pile : piles) {
                if(pile < k) {
                    hrs += 1;
                }
                else if(pile % k != 0) {
                    hrs += pile / k + 1;
                }
                else {
                    hrs += pile / k;
                }
            }

            if(hrs <= h) {
                lowestk = k;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return lowestk;
    }
};