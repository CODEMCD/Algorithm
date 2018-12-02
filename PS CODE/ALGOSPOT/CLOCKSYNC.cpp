#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MIN(a,b) ((a)>(b)?(b):(a))
vector<int> clocks;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//linked[i][j] = 'x': i번 스위치와 j번 시계가 연결되어 있다.
//linked[i][j] = '.': i번 스위치와 j번 시계가 연결되어 있지 않다.
const char linked[SWITCHES][CLOCKS + 1] = {
   //0123456789012345
   "xxx.............",
   "...x...x.x.x....",
   "....x.....x...xx",
   "x...xxxx........",
   "......xxx.x.x...",
   "x.x...........xx",
   "...x..........xx",
   "....xx.x......xx",
   ".xxxxx..........",
   "...xxx...x...x.."
};
//모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int> &clocks)
{
   for (int clock = 0; clock < CLOCKS; clock++) {
      if (clocks[clock] != 12)
         return false;
   }
   return true;
}
//swtch번 스위치를 누른다.
void push(vector<int> &clocks, int swtch)
{
   for (int clock = 0; clock < CLOCKS; clock++) {
      if (linked[swtch][clock] == 'x') {
         clocks[clock] += 3;
         if (clocks[clock] == 15)
            clocks[clock] = 3;
      }
   }
}
//clocks: 현재 시계들의 상태
//swtch: 이번에 누를 스위치의 번호
//가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환
//만약 불가능하다면 INF 이상의 큰 수를 반환한다.
int solve(vector<int> &clocks, int swtch)
{
   if (swtch == SWITCHES)
      return areAligned(clocks) ? 0 : INF;
   //이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
   int ret = INF;
   for (int cnt = 0; cnt < 4; cnt++) {
      ret = MIN(ret, cnt + solve(clocks, swtch + 1));
      push(clocks, swtch);
   }
   //push(clocks, swtch)가 네 번 호출되었으니 clocks는 원래와 같은 상태가 된다.
   return ret;
}

int main(void)
{
   int tc;
   scanf("%d", &tc);
   while (tc--) {
      for (int i = 0; i < CLOCKS; i++) {
         int cl;
         scanf("%d", &cl);
         clocks.push_back(cl);
      }
      int ans = solve(clocks, 0);
      if (ans >= INF)
         printf("-1\n");
      else
         printf("%d\n", ans);

      clocks.clear();
   }
}