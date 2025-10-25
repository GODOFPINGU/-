#include <iostream>
using namespace std;

const int N = 8;          // 역 개수(고정)
const int INF = 1000000;  // 매우 큰 값(무한대 대용)

// 역 이름(번호로 선택)
const char* NAME[N] = {
"Nopo",        // 0
"Oncheonjang", // 1
"Yeonsan",     // 2
"Seomyeon",    // 3
"Beomnaegol",  // 4
"Beomil",      // 5
"Sasang",      // 6
"Centum"       // 7 (예시용)
};

void initGraph(int w[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            w[i][j] = (i == j ? 0 : INF);
        }
    }
}

void addEdge(int w[N][N], int u, int v, int cost) {
    if (u < 0 || u >= N || v < 0 || v >= N) return;
    w[u][v] = cost;
    w[v][u] = cost; // 양방향
}

void dijkstra(int w[N][N], int src, int dist[N], int prev[N]) {
    bool visited[N];
    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int iter = 0; iter < N; ++iter) {
        int u = -1;
        int best = INF;
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }
        if (u == -1) break; // 더 이상 갈 곳 없음
        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            if (w[u][v] < INF) {
                if (dist[v] > dist[u] + w[u][v]) {
                    dist[v] = dist[u] + w[u][v];
                    prev[v] = u;
                }
            }
        }
    }
}

void printStations() {
    cout << "역 목록(번호 선택)\n";
    for (int i = 0; i < N; ++i) {
        cout << "  " << i << ": " << NAME[i] << "\n";
    }
}

void printPath(int prev[N], int src, int dst) {
    if (src == dst) {
        cout << NAME[src] << "\n";
        return;
    }
    int path[N];
    int len = 0;
    int cur = dst;
    while (cur != -1) {
        path[len++] = cur;
        if (cur == src) break;
        cur = prev[cur];
    }
    if (path[len - 1] != src) {
        cout << "(경로 없음)\n";
        return;
    }
    // 거꾸로 들어있으므로 뒤에서부터 출력
    for (int i = len - 1; i >= 0; --i) {
        cout << NAME[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W[N][N];
    initGraph(W);

    // 샘플 간선(시간 단위: 분, 예시용)
    addEdge(W, 0, 1, 3); // Nopo - Oncheonjang
    addEdge(W, 1, 2, 3); // Oncheonjang - Yeonsan
    addEdge(W, 2, 3, 2); // Yeonsan - Seomyeon
    addEdge(W, 3, 4, 2); // Seomyeon - Beomnaegol
    addEdge(W, 4, 5, 3); // Beomnaegol - Beomil
    addEdge(W, 3, 6, 7); // Seomyeon - Sasang
    addEdge(W, 2, 7, 6); // Yeonsan - Centum (예시)

    cout << "[부산 지하철 최단 경로 - 간단 버전]\n";
    cout << "종료하려면 음수 입력.\n\n";

    while (true) {
        printStations();
        cout << "출발 역 번호: ";
        int s; cin >> s;
        if (!cin || s < 0) break;
        cout << "도착 역 번호: ";
        int t; cin >> t;
        if (!cin || t < 0) break;
        if (s < 0 || s >= N || t < 0 || t >= N) {
            cout << "번호 범위를 확인하세요(0~" << (N - 1) << ").\n\n";
            continue;
        }

        int dist[N], prev[N];
        dijkstra(W, s, dist, prev);

        if (dist[t] >= INF) {
            cout << "경로를 찾을 수 없습니다.\n\n";
        }
        else {
            cout << "최단 시간: " << dist[t] << "분\n";
            cout << "경로: ";
            printPath(prev, s, t);
            cout << "\n";
        }
    }
    cout << "종료합니다.\n";
    return 0;
}