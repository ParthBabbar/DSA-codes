class Solution {
private:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
        
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int element = digits[index] - '0';
        string value = mapping[element];
        
        for(int j=0;j<value.length();j++){
            output.push_back(value[j]);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        int i=0;
        
        if(digits.length()==0){
            return ans;
        }
        string output="";
        
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,i,ans,mapping);
        return ans;
    }
};
