#include <iostream>
#include <vector>
#include <string>
#include <map>



int main()
{
	int n;
	std :: cin >> n;
	std :: vector<bool> res(n,true);
	int x = 2;
	while(x * x < n)
	{
		if(res[x])
		{
			for(int y = x * x; y < n;y += x)
			{
				res[y] = false; 
			}
			
		}
		x++;
	}
	for(int i=0;i<n;i++)
	{
		if(res[i]) std :: cout << i << " ";
	}

	return 0;
}
