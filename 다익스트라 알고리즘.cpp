#include <iostream>      // 입출력 사용
#include <vector>        // 벡터 사용
#include <queue>         // 우선순위 큐 사용
#include <limits>        // 무한대 상수 사용 (INF)
using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대 상수 설정

// 간선 정보를 담을 구조체
struct Edge
{
    int to;       // 도착 정점
    int weight;   // 가중치
};

// 다익스트라 알고리즘 함수
void dijkstra(int start, const vector<vector<Edge>>& graph)
{
    int n = graph.size();                // 정점 개수
    vector<int> dist(n, INF);            // 최단 거리 배열 (초기값 INF)
    dist[start] = 0;                     // 시작 정점까지의 거리는 0

    // (거리, 정점) 형태로 저장하는 우선순위 큐 (거리 기준 오름차순)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start }); // 시작점 추가

    while (!pq.empty())
    {
        int currentDist = pq.top().first; // 현재까지의 거리
        int currentNode = pq.top().second; // 현재 정점
        pq.pop();

        // 이미 더 짧은 경로가 있다면 패스
        if (currentDist > dist[currentNode])
            continue;

        // 현재 정점에서 연결된 모든 간선 확인
        for (const auto& edge : graph[currentNode])
        {
            int nextNode = edge.to;
            int newDist = currentDist + edge.weight;

            // 더 짧은 경로를 찾으면 업데이트
            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({ newDist, nextNode });
            }
        }
    }

    // 결과 출력
    cout << "정점 " << start << "으로부터의 최단 거리\n";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << i << " : 도달 불가\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; // 정점 수, 간선 수
    cout << "정점 개수와 간선 개수를 입력하세요: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V); // 인접 리스트 생성

    cout << "간선을 입력하세요 (시작 끝 가중치):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w }); // 방향 그래프
    }

    int start;
    cout << "시작 정점을 입력하세요: ";
    cin >> start;

    dijkstra(start, graph);

    return 0;
}