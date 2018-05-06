# Sring 함수

## 정의
- String은 문자열을 담기 위한 container이다.
- #include <string> 선언이 필요하다.

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

## 확장, 문자열 추가
<pre><code>string a = "Hello";
a += "World";        //방법1
a.append("World");   //방법2
</code></pre>

## 길이
<pre><code>string a = "Hello World";
int len = a.length();   //방법1
int len = a.size();     //방법2
</code></pre>

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

## 특정 위치 문자 찾기
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
