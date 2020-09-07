#include<iostream>
using namespace std;
#include<vector>

long long maxpairwiseproduct(const vector<int> &numbers)
{
	int n=numbers.size();
	long long result=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(((long long)(numbers[i])) * numbers[j] > result)
			{
			   result = ((long long)(numbers[i])) * numbers[j];	
			}
		}
	}
	return result;
}
long long maxpairwiseproductfast(const vector<int> &numbers)
{
	int n=numbers.size();
	int max1=-1;
	for(int i=0;i<n;++i)
	  if((max1 == -1) || (numbers[i] > numbers[max1]))
	   max1 = i;
	
	int max2=-1;   
	for(int j=0;j<n;++j)
	  if((j != max1) && ((max2==-1) || (numbers[j] > numbers[max2])))
	  max2=j;
	
	return ((long long)(numbers[max1])) * numbers[max2];     
}
int main()
{
	int n;
	cin>>n;
	vector<int> numbers(n);
	for(int i=0;i<n;++i)
	{
		cin>>numbers[i];
	}
	long long result=maxpairwiseproductfast(numbers);
	cout<<result<<"\n";
	return 0;
}
