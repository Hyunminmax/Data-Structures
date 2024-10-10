// Big O 판단하기
// 기본적으로 T(n)에서 실제로 큰 의미를 갖는 것은 최고차항의 차수(n^m)이라 했다. 
// 위 방식으로 풀면 아래와 같은 답이 나오는가? 
// 1. 3n+2 = O(n)
// 2. 7n^3+3n^2+2 = O(n^3)
// 3. 2^n+n^2 = O(2^n)
// 4. n+logn = O(n)
// 5. n+nlogn = O(n)
// 6. 2^n+n^3 = O(2^n)

// 최고차항의 의미가 뭐지?
// 최고차항은 n이 커질수록 가장 중요한 항이다.
// 따라서 5번의 답은 틀렸다. 
// 5. n+nlogn에서 n보다 n에 logn을 곱한것이 더 크기 때문에 nlogn이 최고차항이다. 
// 5. n+nlogn = O(nlogn)