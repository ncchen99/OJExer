#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int i;
    int j;
    int dis;
    bool operator<(const Node& a) const {
        return a.dis < dis;
    }
} node;

int ta, N, M;  // taskAmount
int maze[1000][1000];
int dis[1000][1000];
bool flag[1000][1000];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
priority_queue<node> dispq;

void dijsktra() {
    while (!dispq.empty()) {
        flag[dispq.top().i][dispq.top().j] = true;
        for (int k = 0; k < 4; k++) {
            node nn;  //nextNode
            nn.i = dispq.top().i + mv[k][0];
            nn.j = dispq.top().j + mv[k][1];
            nn.dis = dis[nn.i][nn.j];
            if ((nn.i < N && nn.i >= 0) && (nn.j < M && nn.j >= 0) && (!flag[nn.i][nn.j])) {
                if (dispq.top().dis + maze[nn.i][nn.j] < nn.dis) {
                    nn.dis = dispq.top().dis + maze[nn.i][nn.j];
                    dispq.push(nn);
                    dis[nn.i][nn.j] = nn.dis;
                }
            }
        }
        dispq.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> ta;
    while (ta--) {
        //int p[1000][1000];
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> maze[i][j];
                flag[i][j] = 0;
                dis[i][j] = 9999999;
            }
        }
        node n = {0, 0, maze[0][0]};
        dis[0][0] = maze[0][0];
        dispq.push(n);

        dijsktra();
        cout << dis[N - 1][M - 1] << '\n';
    }
}

/*    flag[now.i][now.j] = true;1

    bool finished = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!flag[i][j]) {
                finished = false;
                i = N;
                j = M;
            }
        }
    }
    if (finished)
        return;*/
