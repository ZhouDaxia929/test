#include <iostream>
#include <cstdio>
using namespace std;

//最长上升子序列(n^2)模板
//入口参数：1.数组名称 2.数组长度（注意从1号位置开始）
//状态转移方程：dp(i)=max{1,dp[j]+1}  (j=1,2,3,...,i-1 且 A[j]<A[i])
template<class T>
int LIS(T a[], int n)
{
	int i, j;
	int ans = 0;
	int m = 0;
	int *dp = new int[n + 1];
	
	/*
	//这个方法似乎比较麻烦，且不太符合状态转换方程
	dp[1] = 1;
	for (i = 2;i <= n;i++){  //确定当前起点
		m = 0;   //以dp[i]为根的正确序列长度
		for (j = 1;j<i;j++){
			if (dp[j]>m&&a[j]<a[i])
				m = dp[j];   //满足条件，更新结果
		}
		dp[i] = m + 1;
		if (dp[i]>ans)
			ans = dp[i];
	}
	*/
	//标准程序
	for (i = 1; i <= n; i++){
		dp[i] = 1;
		for (j = 1; j <= i - 1; j++){
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {   //这里应用状态转移方程
				dp[i] = dp[j] + 1;
			}
		}
		/* 记录最长子序列 */
		if (dp[i] > ans) ans = dp[i];
	}
	return ans;
}


int main() {
	int n;
	while (scanf("%d", &n) == 1 & n > 0) {
		int *arr = new int[n + 1];
		int i = 1;
		while (i<n+1) {
			cin >> arr[i++];
		}
		cout << LIS(arr, n) << endl;
	}
	return 0;
}