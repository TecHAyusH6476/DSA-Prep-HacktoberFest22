#include <bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> profit,
   vector<int> weight, int N)
{

 int numOfElements = profit.size();
 int i;
 multimap<double, int> ratio;
 double max_profit = 0;
 for (i = 0; i < numOfElements; i++) {
  ratio.insert(make_pair(
   (double)profit[i] / weight[i], i));
 }
 multimap<double, int>::reverse_iterator it;
 for (it = ratio.rbegin(); it != ratio.rend();
  it++) {
  double fraction = (double)N / weight[it->second];
  if (N >= 0
   && N >= weight[it->second]) {
   max_profit += profit[it->second];
   N -= weight[it->second];
  }

  else if (N < weight[it->second]) {
   max_profit += fraction
      * profit[it->second];
   break;
  }
 }
 cout << "Maximum profit earned is:"
  << max_profit;
}


int main()
{
 int n,N;
 cout<<"Enter the no of pairs of (Profit,weight) : ";
 cin>>n;
 cout<<"Enter the maximum weight : ";
 vector<int> profit(n), weight(n);
 cin>>N;

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the pair no "<<i+1<<" : "<<endl;
   cin>>profit[i]>>weight[i];
 }

 maxProfit(profit, weight, N);
}
