class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = 0;
        int n = arr.size();
        
        for(int i : arr){
            if(i==1)
                ones++;
        }
        
        //if no ones
        if(ones==0) return {0,n-1};
        //if irregular than also 
        if(ones%3!=0) return {-1,-1};
        
        int k = ones/3;
        
        int firstone=-1,secondone=-1, thirdone = -1;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        
        //firstone
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                firstone = i;
                break;
            }
        }
        
        //find second one
        for(int i=firstone+1;i<n;i++){
            if(arr[i]==1) cnt2++;
            if(arr[i]==1 && cnt2==k){
                secondone = i;
                break;
            }
        }
        
        //find third one
        for(int i=secondone+1;i<n;i++){
            if(arr[i]==1) cnt3++;
            if(arr[i]==1 && cnt3==k){
                thirdone = i;
                break;
            }
        }
        
        //checking if they are equal
        int x = firstone, y = secondone, z = thirdone;
        while(x<n && y<n && z<n){
            if(arr[x] == arr[y] && arr[y] == arr[z]){
                x++;y++;z++;
            }
            else
                return {-1,-1};
        }
        return {x-1,y};
    }
};
