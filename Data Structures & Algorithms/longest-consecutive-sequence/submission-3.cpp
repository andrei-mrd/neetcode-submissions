class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> numbers;

        for(auto& n : nums) {
            numbers[n] += 1;
        }

        vector<int> sequence;
        bool first = true;
        int longestSeqLength = 0;
        int lastNumber;
        

        for(auto& p : numbers) {
            if(first == true) {
                sequence.push_back(p.first);
                lastNumber = p.first;
                first = false;
            } else {
                if(p.first - lastNumber == 1) {
                    sequence.push_back(p.first);
                    lastNumber = p.first;
                } else {
                    if(sequence.size() > longestSeqLength) {
                        longestSeqLength = sequence.size();
                        sequence.clear();
                        sequence.push_back(p.first);
                        lastNumber = p.first;
                    }else {
                        sequence.clear();
                        sequence.push_back(p.first);
                        lastNumber = p.first;
                    }
                }
            }
        }
    
        
        if(sequence.size() > longestSeqLength) {
            longestSeqLength = sequence.size();
        }
        
        return longestSeqLength;
    }
};