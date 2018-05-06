# Vector 함수

## 정의
- 대표적인 시퀀스 컨테이너로 배열과 유사하다.
- #include <vector> 선언이 필요하다.

## 특징
- 크기를 동적으로 변경가능하고, 순차, 랜덤 접근이 가능하다. 하지만 배열과 비슷하게 중간 삽입, 삭제가 비효율적이다.

## 생성자
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

## 멤버함수
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

## 연산자
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
