// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         if(n==0){
//             return true;
//         }
//         for(int i=0;i<flowerbed.size();i++){
//             if(flowerbed[i]==0){
//                 bool left= (i==0)||(flowerbed[i-1]==0);
//                 bool right =(i==flowerbed.size()-1)|| (flowerbed[i+1]==0);
//             }
//             if(left && right){
//                 flowerbed[i]=1;
//                 n--;
//                 if(n==0){
//                     return true;

//                 }
//             }
//         }
//         return false;
        
//     }
// };

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int l = flowerbed.size();
         
        if(n == 0)
            return true;
        
        
        for(int i = 0; i<l; i++) {
            
            if(flowerbed[i] == 0) {
                
                bool leftEmpty   = (i == 0) || (flowerbed[i-1] == 0);
                
                bool rightEmpty  = (i == l-1) || (flowerbed[i+1] == 0);
                
                if(leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0)
                        return true;
                }
                
            }
            
        }
        
        return false;
        
    }
};