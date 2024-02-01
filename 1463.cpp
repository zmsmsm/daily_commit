#include <iostream>
using namespace std;
 
int memo[1000001];
int Func(int n) {
	if (n == 1) // 1을 만드는 것이므로, 연산횟수 0
	{
		return 0;
	}
	if (memo[n]>0) // 이미 호출되었었던 값이면, 그대로 반환
	{
		return memo[n];
	}
	
	// Func를 타고 계속 올라가서, memo[1]부터 하나씩 return하며 memo[n]까지 값을 할당하는 과정이라고 생각
	memo[n] = Func(n - 1) + 1; // 이는 -1을 했을 때의 연산 개수
	// -1는 n!=1이면 모두 실행할 수 있음 
	// +1은 이번에 memo[n]을 만들기 위해 수행되는 연산 개수 추가
    // 즉 +1은 최소 연산횟수가 1개 증가한다는 의미
 
	// 만약 n의 값이 2로 나눠질 때 연산해보기
	if (n%2 == 0)
	{
		int temp = Func(n / 2) + 1; // 2로 나눠졌을 때의 연산 개수 (+1은 최소 연산개수가 1개 증가한다는 의미)
		if (memo[n] > temp) // 최소값을 구하기 위해 비교하는 과정 (기존의 memo[n]값과 비교 가능)
		{
			memo[n] = temp;
		}
	}
 
	// 만약 n의 값이 3으로 나눠질 때 연산해보기
	if (n%3 == 0)
	{
		int temp = Func(n / 3) + 1; // 3로 나눠졌을 때의 연산 개수
		if (memo[n] > temp) // 최소값을 구하기 위해 비교하는 과정
		{
			memo[n] = temp;
		}
	}
 
	return memo[n];
	// memo[1]부터 memo[n]까지 각각의 재귀함수, 함수에서 return 해주는 역할
 
}
 
int main() {
	int N; // 정수 N
	cin >> N;
 
	cout<< Func(N);
	return 0;
}