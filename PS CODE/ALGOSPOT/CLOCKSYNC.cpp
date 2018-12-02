#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MIN(a,b) ((a)>(b)?(b):(a))
vector<int> clocks;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//linked[i][j] = 'x': i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�.
//linked[i][j] = '.': i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�.
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
//��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ���Ѵ�.
bool areAligned(const vector<int> &clocks)
{
   for (int clock = 0; clock < CLOCKS; clock++) {
      if (clocks[clock] != 12)
         return false;
   }
   return true;
}
//swtch�� ����ġ�� ������.
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
//clocks: ���� �ð���� ����
//swtch: �̹��� ���� ����ġ�� ��ȣ
//�� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ
//���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ�Ѵ�.
int solve(vector<int> &clocks, int swtch)
{
   if (swtch == SWITCHES)
      return areAligned(clocks) ? 0 : INF;
   //�� ����ġ�� 0�� ������ ������ �� �� ������ �������� ��� �õ��Ѵ�.
   int ret = INF;
   for (int cnt = 0; cnt < 4; cnt++) {
      ret = MIN(ret, cnt + solve(clocks, swtch + 1));
      push(clocks, swtch);
   }
   //push(clocks, swtch)�� �� �� ȣ��Ǿ����� clocks�� ������ ���� ���°� �ȴ�.
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