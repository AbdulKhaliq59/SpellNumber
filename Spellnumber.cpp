#include<iostream>
#include<vector>
using namespace std;
vector<pair<string, int>> numbers{
                                  {"Billion", 1000000000},{"Million", 1000000},{"Thousand", 1000},{"Hundred", 100},
                                  {"Ninety", 90},{"Eighty", 80},{"Seventy", 70},{"Sixty", 60},{"Fifty", 50},
                                  {"Forty", 40},{"Thirty", 30},{"Twenty", 20},{"Nineteen", 19},{"Eighteen", 18},
                                  {"Seventeen", 17},{"Sixteen", 16},{"Fifteen", 15},{"Fourteen", 14},{"Thirteen", 13},
                                  {"Twelve", 12},{"Eleven", 11},{"Ten", 10},{"Nine", 9},{"Eight", 8},{"Seven", 7},
                                  {"Six", 6},{"Five", 5},{"Four", 4},{"Three", 3},{"Two", 2},{"One", 1},{"Zero",0}
                                 };
//~~~~~~~~~~~~Function To check Number's range and display the spelling of that number~~~~~~~~~~~~~~                                 
string solve(int input) 
{
 if(input < 0)
 return "Unsupported Input..." ;
   if (input == 0) return "Zero";
   string result;
   for (auto& num : numbers) 
   {
      if (num.second <= input) 
      {
         if (num.second >= 100) 
         {
            result = solve(input / num.second) + " " + num.first;
            if (input > (input / num.second) * num.second)
            {
               result += " " + solve(input - (input / num.second) * num.second);
            } 
         } 
         else 
         {
            result = num.first + (input > num.second ? " " + solve(input - num.second) : "");
         }
         break;
      }
   }
   return result;
}

int main() 
{
    int number;
    cout <<"Enter Your Number to convert \n";
    cin>>number;
    cout<< solve(number) <<endl;
    return 0;
}