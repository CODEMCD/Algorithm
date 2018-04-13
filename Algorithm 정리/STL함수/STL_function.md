# STL 함수

## Sring 함수
### 정의
- String은 문자열을 담기 위한 container이다.
- #include <string> 선언이 필요하다.

### 생성
<pre><code>string str = "abcd";
string str2;
str2 = "abcd";
</code></pre>

### 복사
<pre><code>string a = "Hello World";
string b;
a = b;

char c[100] = "Good bye";
string d = c;
</code></pre>
- strcpy함수와 같은 함수 대신에 '='operation을 사용하여 복사한다.

### 출력
<pre><code>cout << a << endl;
printf("%s\n", a.c_str());
</code></pre>
- 주의할 점은 printf함수로 string을 출력해야 할 경우 반드시 c_str()을 사용하여 char * 형식으로 변환하여 출력해야 한다.

### 확장, 문자열 추가
<pre><code>string a = "Hello";
a += "World";        //방법1
a.append("World");   //방법2
</code></pre>

### 길이
<pre><code>string a = "Hello World";
int len = a.length();   //방법1
int len = a.size();     //방법2
</code></pre>

### 부분 문자열(Substring)
-  string 내 저장된 부분 문자열을 알고 싶을 때 substr()을 사용한다.
<pre><code>string a = "Hello World";
string s1 = a.substr(0, 3);  // "Hel"
string s2 = a.substr(1, 3);  // "ell"
string s3 = a.substr(0, a.length() - 1);  // "Hello Worl"
string s4 = a.substr(1);  // "ello World"
</code></pre>

### 비교
<pre><code>string a = "ABCDE";
string b = "ABDDD";

cout << (a == b) << endl;  // 0(FALSE)
cout << (a != b) << endl;  // 1(TRUE)
cout << (a < b) << endl;   // 1(TRUE)
cout << (a >= b) << endl;  // 0(FALSE)
</code></pre>

### 특정 위치 문자 찾기
<pre><code>string a = "Hello World";
char a1 = a.at(0);  // 'H'
char a2 = a.at(1);  // 'e'
</code></pre>
<pre><code>string a = "Hello World";
if (a.find("World") != string::npos) {
	printf("SUCCESS!!\n");
}
</code></pre>
- 지정한 문자열이 발견된 첫 위치를 반환한다.

***

## Vector 함수

### 정의
- 대표적인 시퀀스 컨테이너로 배열과 유사하다.
- #include <vector> 선언이 필요하다.

### 특징
- 크기를 동적으로 변경가능하고, 순차, 랜덤 접근이 가능하다. 하지만 배열과 비슷하게 중간 삽입, 삭제가 비효율적이다.

### 생성자
<table>
<thead>
<tr>
  <th>vector타입 변수명</th>
  <th>설명</th>
</tr>
</thead>
<tbody>
<tr>
  <td>vector타입 v</td>
  <td>빈 컨테이너 v</td>
</tr>
<tr>
  <td>vector타입 v(n)</td>
  <td>n개의 원소를 갖는 v</td>
</tr>
<tr>
  <td>vector타입 v(n, x)</td>
  <td>x 값으로 초기화된 n개의 원소를 갖는 v</td>
</tr>
</tbody>
</table>

### 멤버함수
<table>
<thead>
<tr>
  <th>함수명</th>
  <th>설명</th>
</tr>
</thead>
<tbody>
<tr>
  <td>v.assign( n, x )</td>
  <td>v에 x값으로 n개의 원소를 할당한다.</td>
</tr>
<tr>
  <td>v.at( n )</td>
  <td>v의 n번째 원소를 참조한다.</td>
</tr>
<tr>
  <td>v.back()</td>
  <td>v의 마지막 원소를 참조한다.</td>
</tr>
<tr>
  <td>i = v.begin()</td>
  <td>i는 v의 첫 원소를 가리키는 반복자</td>
</tr>
<tr>
  <td>i = v.end()</td>
  <td>i는 v의 마지막 원소를 가리키는 반복자</td>
</tr>
<tr>
  <td>s = v.capacity()</td>
  <td>s는 v에 할당된 공간의 크기</td>
</tr>
<tr>
  <td>v.clear()</td>
  <td>v의 모든 원소를 제거한다.</td>
</tr>
<tr>
  <td>v.empty()</td>
  <td>v가 비어있는지 확인한다.</td>
</tr>
<tr>
  <td>p2 = v.erase( p1 )</td>
  <td>p1이 가리키는 원소를 제거하고 p2는 다음 원소를 가리킨다.</td>
</tr>
<tr>
  <td>v.front()</td>
  <td>v의 첫 번째 원소를 참조한다.</td>
</tr>
<tr>
  <td>i = v.insert( p, x )</td>
  <td>p가 가리키는 위치에 x를 삽입하고 i는 삽입한 원소를 가리키는 반복자</td>
</tr>
<tr>
  <td>v.insert( p, n, x )</td>
  <td>p가 가리키는 위치에 n개의 x값을 삽입한다.</td>
</tr>
<tr>
  <td>s = v.max_size()</td>
  <td>s는 v가 담을 수 있는 최대 원소의 개수(메모리 크기)</td>
</tr>
<tr>
  <td>v.push_back( x )</td>
  <td>v의 마지막에 x값을 추가한다.</td>
</tr>
<tr>
  <td>v.pop_back()</td>
  <td>v의 마지막 원소를 제거한다.</td>
</tr>
<tr>
  <td>i = v.rbegin()</td>
  <td>i는 v의 역 순차열의 첫 원소를 가리키는 반복자</td>
</tr>
<tr>
  <td>i = v.rend()</td>
  <td>i는 v의 역 순차열의 끝을 표시하는 반복자</td>
</tr>
<tr>
  <td>v.reserve( n )</td>
  <td>n개의 원소를 저장할 공간을 예약한다.</td>
</tr>
<tr>
  <td>v.resize( n )</td>
  <td>v의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.</td>
</tr>
<tr>
  <td>v.resize( n, x )</td>
  <td>v의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.</td>
</tr>
<tr>
  <td>v.size()</td>
  <td>v의 원소 개수</td>
</tr>
<tr>
  <td>v1.swap( v2 )</td>
  <td>v1과 v2를 swap한다.</td>
</tr>
</tbody>
</table>

### 연산자
<table>
<thead>
<tr>
  <th>연산자</th>
  <th>설명</th>
</tr>
</thead>
<tbody>
<tr>
  <td>v1 == v2</td>
  <td>v1과 v2의 모든 원소가 같은가? (bool)</td>
</tr>
<tr>
  <td>v1 != v2</td>
  <td>v1과 v2의 모든 원소 중 하나라도 다른 원소가 있는가? (bool)</td>
</tr>
<tr>
  <td>v1 < v2</td>
  <td>문자열 비교와 같이 v2가 v1보다 큰가?</td>
</tr>
<tr>
  <td>v1 > v2</td>
  <td>문자열 비교와 같이 v1이 v2보다 큰가?</td>
</tr>
<tr>
  <td>v[i]</td>
  <td>v의 i번째 원소를 참조한다.</td>
</tr>
</tbody>
</table>

***

## Pair 함수

### 정의
- 두 객체를 하나의 객체로 취급할 수 있도록 묶어주는 클래스
- #include <utility> 선언한다.(경험상 선언안하여도 컴파일에러 안뜸)

### 특징
- 대소 비교 및 sort함수를 이용한 정렬 가능하다. (첫 번째 인자가 같으면 두 번째 인자를 비교)
- operator(==, !=, <, >, >=, <=) 사용 가능하다.
- 두 객체의 타입은 서로 다른 타입으로 사용가능하다.
- vector의 타입으로 사용가능하다.

### 생성자
- 클래스 : 
~~~
template <class T1, class T2> struct pair;
template <typename T1, typename T2> struct pair;
~~~
- T1 : first, T2 : second 로 구분한다.
- pair<TYPE1, TYPE2> p; 와 같이 선언한다.

### 멤버 함수
<table>
<thead>
<tr>
  <th>함수명</th>
  <th>설명</th>
</tr>
</thead>
<tbody>
<tr>
  <td>p.first</td>
  <td>p의 첫 번째 원소를 반환한다.</td>
</tr>
<tr>
  <td>p.second</td>
  <td>p의 두 번째 원소를 반환한다.</td>
</tr>
<tr>
  <td>make_pair( a, b )</td>
  <td>a와 b를 삽입한 pair를 생성한다.</td>
</tr>
</tbody>
</table>

***

## Sort 함수

### 정의
- 범위내에서 원소들을 정렬하는 함수이다.
- #include <algorithm> 선언한다.

### 특징
- 정렬 방식은 오름차순, 내림차순 등 사용자가 정의할 수 있으며, 동일한 원소에 대해서는 그 순서가 보장되지 않는다.
- int, char, string 등 모든 타입에 대해 정렬 가능하며, 사용자가 정의한 객체 역시 연산자 오버로딩을 정의해주면 정렬이 가능하다.
- 문자열 정렬을 할 때 사전순으로 정렬된다.
- 동일한 원소에 대해서 그 원소들의 상대적 순서를 보장해 주는 라이브러리가 존재한다.
- 퀵 정렬뿐 아니라 컴파일러에서 다양한 방식의 정렬을 복합적으로 사용한다.
- GCC의 경우 Intro Sort와 원소의 개수가 적을 경우 Insertion Sort를 사용한다고 알려져 있다.
- 기본적으로 오름차순 정렬을 수행한다.

## 사용 예제
1. 기본
~~~
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int arr[5];
	arr[0] = 0;
	arr[1] = 4;
	arr[2] = 3;
	arr[3] = 1;
	arr[4] = 5;
	sort(arr, arr + 5);

	for (int i = 0; i < 5; i++)
	     cout << arr[i] << endl;

	return 0;
}
~~~
> 결과 <br>0 <br>1 <br>2 <br>3 <br>4 <br>5

2. 내림차순 정렬
~~~
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	int arr[5];
	arr[0] = 0;
	arr[1] = 4;
	arr[2] = 3;
	arr[3] = 1;
	arr[4] = 5;

	sort(arr, arr + 5, greater<int>());

	for (int i = 0; i < 5; i++)
	         cout << arr[i] << endl;

	return 0;
}
~~~
> 결과 <br>5 <br>4 <br>3 <br>2 <br>1 <br>0
- 이 외에도 여러가지 방법이 있다.

3. Vector 정렬
~~~
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<char> v;
	v.push_back('c');
	v.push_back('b');
	v.push_back('e');
	v.push_back('a');
	v.push_back('g');

	sort(v.begin(), v.end());

	for (int i = 0; i < 5; i++)
	         cout << v[i] << endl;

	return 0;
}
~~~
> 결과 <br>a <br>b <br>c <br>d <br>e <br>g

4. 사용자 정의 객체 정렬(Class)
~~~
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
	     this->name = name;
	     this->age = age;
	}
};

bool compare(const Person &a, const Person &b) {
	return a.age < b.age;
}

int main() {
	vector<Person> v;
	v.push_back(Person("MinJi", 22));
	v.push_back(Person("Kangho", 28));
	v.push_back(Person("Minho", 26));
	v.push_back(Person("Strange Yun", 25));
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	   cout << v[i].age << ", " << v[i].name << endl;

}
~~~
> 결과 <br>22, MinJi <br>25, Strange Yun <br>26, Minho <br>28, Kangho

5. 사용자 정의 객체 정렬(Struct)
~~~
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct _person
{
	string name;
	int age;
}Person;

bool compare(const Person &a, const Person &b) {
	return a.age < b.age;
}

int main() {
	vector<Person> v;
	Person person;
	person.name = "MinJi"; person.age = 22;
	v.push_back(person);
	person.name = "Kangho"; person.age = 28;
	v.push_back(person);
	person.name = "Minho"; person.age = 26;
	v.push_back(person);
	person.name = "Strange Yun"; person.age = 25;
	v.push_back(person);
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].age << ", " << v[i].name << endl;

}
~~~
> 결과 <br>22, MinJi <br>25, Strange Yun <br>26, Minho <br>28, Kangho

6. Pair 정렬
~~~
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(20, "A_Jiwoo"));
	v.push_back(pair<int, string>(21, "B_Songju"));
	v.push_back(pair<int, string>(21, "C_Induk"));
	v.push_back(pair<int, string>(21, 
        "D_SeungHyun"));
	v.push_back(pair<int, string>(20, "E_Soyen"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	   cout << v[i].first << ", " << v[i].second << 
          endl;

}
~~~
> 결과 <br>20, A_Jiwoo <br>20, E_Soyen <br>21, B_Songju <br>21, C_Induk <br>21, D_SeungHyun
