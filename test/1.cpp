#include <iostream>
#include <cstdio>
using namespace std;

//�����������(n^2)ģ��
//��ڲ�����1.�������� 2.���鳤�ȣ�ע���1��λ�ÿ�ʼ��
//״̬ת�Ʒ��̣�dp(i)=max{1,dp[j]+1}  (j=1,2,3,...,i-1 �� A[j]<A[i])
template<class T>
int LIS(T a[], int n)
{
	int i, j;
	int ans = 0;
	int m = 0;
	int *dp = new int[n + 1];
	
	/*
	//��������ƺ��Ƚ��鷳���Ҳ�̫����״̬ת������
	dp[1] = 1;
	for (i = 2;i <= n;i++){  //ȷ����ǰ���
		m = 0;   //��dp[i]Ϊ������ȷ���г���
		for (j = 1;j<i;j++){
			if (dp[j]>m&&a[j]<a[i])
				m = dp[j];   //�������������½��
		}
		dp[i] = m + 1;
		if (dp[i]>ans)
			ans = dp[i];
	}
	*/
	//��׼����
	for (i = 1; i <= n; i++){
		dp[i] = 1;
		for (j = 1; j <= i - 1; j++){
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {   //����Ӧ��״̬ת�Ʒ���
				dp[i] = dp[j] + 1;
			}
		}
		/* ��¼������� */
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