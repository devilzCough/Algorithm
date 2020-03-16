#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pingBall {
	int x, y;
	int direction;
	int score;
} PingBall;

PingBall playGame(PingBall ball);

int T, N;
int X, Y; // start position
int board[105][105] = {0}; // y, x
int pos[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // up:0, down:1, left:2, right:3

int main()
{
	int maxScore = -1
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		// input board values
		for (int i = 0; i < N; i++) {
			for (int j =0; j < N; j++)
				scanf("%d", &board[i][j]);
		}
		PingBall ball;
		for (int y = 0; y < N; y++) {
			Y = y;
			for (int x = 0; x < N; x ++) {
				X = x;
				int maxDire = -1;
				// one Cell
				// startDirection. up, down, left, right
				for (int sd = 0; sd < 4; sd++) {
					ball.x = X + pos[sd][0];
					ball.y = Y + pos[sd][1];
					ball.direction = sd;
					ball.score = 0

					while(ball.direction != -1) {
						ball = playGame(ball);
					}
					maxDire = max(maxDire, ball.score);
				}
				maxScore = max(maxScore, maxDire)
			}
		}


		printf("%d %d\n", t, maxScore);
	}

	return 0;
}

PingBall playGame(PingBall ball)
{
	
}
