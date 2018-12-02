//지울수 있는 블록의 수를 반환한다.
int solution(int m, int n, vector<string> board) {
	//지워진 블록의 개수
	int answer = 0;
	//4개의 불록
	int cy[4] = { 0,0,1,1 };
	int cx[4] = { 0,1,1,0 };

	//블록을 하나도 지울 수 없으면 반복문을 종료한다.
	while (true) {
		//블록을 지울 수 있는지 검사하는 플래그
		bool flag = false;
		//보드에서 지워지는 블록의 좌표에 true값을 삽입한다.
		bool eraser[31][31] = { false, };

		//지워질 수 있는 블록 검사하기
		for (int y = 0; y < m - 1; ++y)
			for (int x = 0; x < n - 1; ++x) {
				int blocky[4], blockx[4];
				for (int i = 0; i < 4; ++i) {
					blocky[i] = y + cy[i];
					blockx[i] = x + cx[i];
				}
				//#: 빈칸이라는 표시
				//블록 4개가 빈칸이 아니고 모두 같다면 지울 수 있다.
				if (board[blocky[0]][blockx[0]] != '#' &&
					board[blocky[0]][blockx[0]] == board[blocky[1]][blockx[1]] &&
					board[blocky[1]][blockx[1]] == board[blocky[2]][blockx[2]] &&
					board[blocky[2]][blockx[2]] == board[blocky[3]][blockx[3]]) {
					flag = true;
					eraser[blocky[0]][blockx[0]] = true;
					eraser[blocky[1]][blockx[1]] = true;
					eraser[blocky[2]][blockx[2]] = true;
					eraser[blocky[3]][blockx[3]] = true;
				}
			}
		//지울 수 있는 블록이 없으면 반복문을 빠져나간다.
		if (!flag) break;

		//지워진 블록의 수를 갱신한다.
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (eraser[i][j])
					answer++;

		//지워진 블록의 자리를 채운다.
		for (int i = 0; i < n; ++i)
			//열의 밑에서 부터 검사한다.
			for (int j = m - 1; j >= 0; --j) {
				//내려가야할 블록을 임시로 저장해두는 배열
				char tmp[31];
				//tmp배열에 저장할 인덱스 계산
				int cnt = 0;
				//해당 좌료가 지워진 블록인 경우
				if (eraser[j][i]) {
					//그 위부터 지워지지 않은 블록을 모두 tmp배열에 저장한다.
					for (int k = j - 1; k >= 0; --k)
						if (!eraser[k][i])
							tmp[cnt++] = board[k][i];
					int ccnt = 0;
					//지워진 블록의 시작 좌표부터 지워지지 않은 블록들을 채워나간다.
					for (int k = j; k > (j - cnt); --k)
						board[k][i] = tmp[ccnt++];
					//블록을 채우고 남은 빈칸을 표시하기 위해 '#'문자를 삽입한다.
					for (int k = 0; k <= (j - cnt); ++k)
						board[k][i] = '#';
					break;
				}
			}
	}

	return answer;
}
