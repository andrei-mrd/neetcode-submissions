class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> numbers;

        for(auto& n : nums) {
            numbers[n] += 1;
        }

        bool first = true;
        int sequence = 0;
        int longestSequence = 0;
        int lastNumber = 0;

        for(auto& p : numbers) {
            if(first == true) {
                sequence += 1;
                lastNumber = p.first;
                first = false;
            }else {
                if(p.first - lastNumber == 1) {
                    sequence += 1;
                    lastNumber = p.first;
                }else {
                    if(sequence > longestSequence) {
                        longestSequence = sequence;
                        sequence = 1;
                        lastNumber = p.first;
                    }else {
                        sequence = 1;
                        lastNumber = p.first;
                    }
                }
            }
        }
        if(sequence > longestSequence) {
            longestSequence = sequence;
        }
        return longestSequence;
    }
};
