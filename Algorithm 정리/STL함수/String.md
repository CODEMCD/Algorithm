# String 함수

## 정의
- String은 문자열을 담기 위한 container이다.
- ```#include <string>``` 선언이 필요하다.

## 멤버 함수
### .assign
- 문자열 할당
- ( 문자열 ): 문자열을 할당한다.
- ( 개수, 문자 ): 문자를 해당 개수만큼 할당한다.
- ( 문자열, 시작 위치, 개수 ): 매개변수 문자열의 시작 위치부터 개수만큼을 호출한 문자열에 할당한다.
~~~
string s1, s2, s3;
s1.assign("ABCDEFG");    // s1 = "ABCDEFG"
s2.assign(3, 'a');       // s2 = "aaa"
s3.assign(s1, 2, 4);     // s3 = "CDEF" (문자열 s1의 인덱스 2부터 4개를 복사하여 할당한다.)
~~~

### .append
- +연산자의 역할처럼 문자열 끝에 추가
- ( 문자열 ): 문자열을 추가한다.
- ( 개수, 문자 ): 문자를 해당 개수만큼 추가한다.
- ( 문자열, 시작 위치, 개수 ): 매개변수 문자열의 시작 위치부터 개수만큼을 호출한 문자열에 추가한다.
~~~
string s1, s2;
s1.append("ABCDEF");    // s1 = "ABCDEF"
s1.append(3, 'x');      // s1 = "ABCDEFxxx"
s2.append(s1, 2, 4);    // s2 = "CDEF"
s2 += "x";              // s2 = "CDEFx"
~~~

### .clear
- 문자열의 내용을 모두 삭제
```
s.clear();
```

### .compare
- 문자열 비교(사전순)
- 문자열이 서로 같으면 0, 앞에 것이 크면 양수값, 뒤에 것이 크면 음수값을 반환한다.
```
s1.compare(s2);   //s1 == s2: 0, s1 > s2: 양수값, s1 < s2: 음수값 반환
```

### .empty
- 문자열이 비어있는지 확인
```
s.empty();
```

### .erase
- 문자열 삭제
- ( 시작 위치, 개수 ): 시작 위치부터 개수만큼의 문자를 삭제한다.
```
string s = "ABCDEF";
s.erase(0, 3);          //s = "DEF" (인덱스 0부터 3개의 문자를 삭제한다.)
```

### .find
- 특정 문자열을 찾고, 그 시작 위치를 반환
- ( 문자 ): 인덱스 0부터 해당 문자를 찾고, 그 시작 위치를 반환한다.
- ( 문자열 ): 인덱스 0부터 해당 문자열을 찾고, 그 시작 위치를 반환한다.
- ( 문자열, 인덱스 값 ): 해당 인덱스값부터 해당 문자열을 찾고, 그 시작 위치를 반환한다.
```
string s1 = "ABCD";
string s2 = "B";

int location = s1.find(s2);
location = s1. find(s2, x);
location = s1.find_first_of(s2, x);
location = s1.find_first_not_of(s2, x);
```

### .replace
- 문자열 대체
- ( 시작 위치, 개수, 문자열 ): 호출한 문자열의 시작 위치부터 개수만큼의 문자를 해당 문자열로 대체한다.
```
string s = "ABC_DEF";
s.replace(4, 3, "ZZZ");   //s = "ABC_ZZZ"
```

### .insert
- 문자열을 지정한 위치에 삽입
- ( 시작 위치, 문자열 ): 시작 위치에 문자열을 삽입한다.
```
string s = "ABCDEF";
s.insert(2, "XX");     // s = "ABXXCDEF"
```

### .pop_back/.push_back
- pop_back: 문자열에서 가장 뒤에 있는 문자 하나를 반환한다.
- push_back: 문자열에서 가장 뒤에 문자 하나를 삽입한다.
```
string s = "ABCDEF";
s.pop_back();          // s = "ABCDE"
s.push_back('X');      // s = "ABCDEX"
```

### .size/.length/.max_size
- .size/.length: 문자열의 크기를 반환한다.
- .max_size: 문자열이 최대로 가질 수 있는 크기를 반환한다.
```
string s = "ABCDEF";
int size = s.size();       // size = 6 (실제 사용되고 있는 크기)
int length = s.length();   // length = 6 (문자열의 길이)
```

### .capacity
- 할당된 메모리의 크기를 반환(reallocation 없이 사용할 수 있는 문자수를 반환)
- capacity가 size보다 클때, 속도가 더 빠르다.(capacity가 크면 기존 공간에 추가하면 되지만 작으면 메모리를 할당해야 하기 때문이다.)
```
string s = "ABCDEF";
int capacity = s.capacity();   // size = 6, capacity = 15
```

### .reserve
- reallocation을 피하기 위해 메모리의 최소용량을 지정
- ( 크기 ): 크기만큼의 여유 메모리를 할당한다. (해당 크기가 현재 capacity보다 작으면 효과는 없다.)
```
string s = "ABCDEF";   // size = 6, capacity = 15
s.reserve(100);        // size = 6, capacity = 111 
s.reserve(1000);       // size = 6, capacity = 1007
```

### .swap
- 문자열 교환
```
string s1 = "ABCD";
string s2 = "1234";
s1.swap(s2);           // s1 = "1234", s2 = "ABCD"
s2.swap(s1);           // s1 = "ABCD", s2 = "1234"
```

### .at
- 문자열에서 특정 위치의 문자를 반환
```
string s = "ABCDEF";
char ch = s.at(3)       // ch = 'D'
```

### .c_str
- string 문자열을 char* 형으로 변환하여 반환한다.
```
string s= ABCDEF";
int length = strlen(s.c_str());
```

### .date
### .copy
### .back
### .front
### .begin
### .end




## 생성
<pre><code>string str = "abcd";
string str2;
str2 = "abcd";
</code></pre>

## 복사
<pre><code>string a = "Hello World";
string b;
a = b;

char c[100] = "Good bye";
string d = c;
</code></pre>
- strcpy함수와 같은 함수 대신에 '='operation을 사용하여 복사한다.

## 출력
<pre><code>cout << a << endl;
printf("%s\n", a.c_str());
</code></pre>
- 주의할 점은 printf함수로 string을 출력해야 할 경우 반드시 c_str()을 사용하여 char * 형식으로 변환하여 출력해야 한다.

## 부분 문자열(Substring)
-  string 내 저장된 부분 문자열을 알고 싶을 때 substr()을 사용한다.
<pre><code>string a = "Hello World";
string s1 = a.substr(0, 3);  // "Hel"
string s2 = a.substr(1, 3);  // "ell"
string s3 = a.substr(0, a.length() - 1);  // "Hello Worl"
string s4 = a.substr(1);  // "ello World"
</code></pre>

## 비교
<pre><code>string a = "ABCDE";
string b = "ABDDD";

cout << (a == b) << endl;  // 0(FALSE)
cout << (a != b) << endl;  // 1(TRUE)
cout << (a < b) << endl;   // 1(TRUE)
cout << (a >= b) << endl;  // 0(FALSE)
</code></pre>
