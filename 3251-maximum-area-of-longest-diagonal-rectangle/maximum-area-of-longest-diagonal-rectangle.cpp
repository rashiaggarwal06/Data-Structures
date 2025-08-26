class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions){
        //Variable to find max area 
        int mx_Area = 0;
        //variable to find max diagonal
        long long max_dia = 0; 
        //Automatically iterate oover the dimensions l and w
        for(auto &rect : dimensions){
            int l = rect[0], w = rect[1];
            //Diagonal value
            long long dia = 1LL * l * l + 1LL * w * w; 
            //Find area
            int area = l * w;
            //Id diagonal is maximum than max diagonal, or diagonal is equal to max diagonal and area is greate than the max_area, then we have to make max diagonal as the current value and should update the area also
            if(dia > max_dia || (dia == max_dia && area > mx_Area)){
                max_dia = dia;
                mx_Area = area;
            }
        }
        //Return max area
        return mx_Area;
    }
};