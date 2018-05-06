# Pair 함수

## 정의
- 두 객체를 하나의 객체로 취급할 수 있도록 묶어주는 클래스
- #include <utility> 선언한다.(경험상 선언안하여도 컴파일에러 안뜸)

## 특징
- 대소 비교 및 sort함수를 이용한 정렬 가능하다. (첫 번째 인자가 같으면 두 번째 인자를 비교)
- operator(==, !=, <, >, >=, <=) 사용 가능하다.
- 두 객체의 타입은 서로 다른 타입으로 사용가능하다.
- vector의 타입으로 사용가능하다.

## 생성자
- 클래스 : 
~~~
template <class T1, class T2> struct pair;
template <typename T1, typename T2> struct pair;
~~~
- T1 : first, T2 : second 로 구분한다.
- pair<TYPE1, TYPE2> p; 와 같이 선언한다.

## 멤버 함수
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
