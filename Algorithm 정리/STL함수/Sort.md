# Sort 함수

## 정의
- 범위내에서 원소들을 정렬하는 함수이다.
- #include <algorithm> 선언한다.

## 특징
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
