#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int maxProfit(vector<int> &prices)
{
    // int maxProfit = 0;
    // for (int i = 0; i < prices.size(); i++) // buy
    // {
    //     for (int j = i + 1; j < prices.size(); j++) // sell
    //     {
    //         if(prices[j] - prices[i] > maxProfit){
    //             maxProfit = prices[j] - prices[i];
    //         }
    //     }
    // }




    
    // int maxProfit = 0;
    // int buyIndex = 0;
    // while (buyIndex < prices.size())
    // {
    //     for (int j = buyIndex + 1; j < prices.size(); j++) // sell
    //     {
    //         if (prices[j] - prices[buyIndex] > maxProfit)
    //         {
    //             maxProfit = prices[j] - prices[buyIndex];
    //         }
    //     }
    //     buyIndex++;
    // }





    // auto buyPrice = min_element(prices.begin(), prices.end());
    // auto buyDay = find(prices.begin(), prices.end(), *buyPrice); // returns iterator pointing to the target
    // int buyDayIdx = distance(prices.begin(), buyDay);
    // cout << "we will buy stock on day: " << buyDayIdx + 1 << " at $" << *buyPrice << endl;

    // auto sellPrice = max_element(prices.begin() + buyDayIdx, prices.end());
    // if (*sellPrice <= *buyPrice)
    // {
    //     return 0;
    // }
    // cout << "we will sell stock at $" << *sellPrice << endl;
    // int maxProfit = *sellPrice - *buyPrice;





    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {2, 4, 1};
    auto result = maxProfit(prices);
    cout << result;
    return 0;
}