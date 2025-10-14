#include <iostream>      // ����� ���
#include <vector>        // ���� ���
#include <queue>         // �켱���� ť ���
#include <limits>        // ���Ѵ� ��� ��� (INF)
using namespace std;

const int INF = numeric_limits<int>::max(); // ���Ѵ� ��� ����

// ���� ������ ���� ����ü
struct Edge
{
    int to;       // ���� ����
    int weight;   // ����ġ
};

// ���ͽ�Ʈ�� �˰��� �Լ�
void dijkstra(int start, const vector<vector<Edge>>& graph)
{
    int n = graph.size();                // ���� ����
    vector<int> dist(n, INF);            // �ִ� �Ÿ� �迭 (�ʱⰪ INF)
    dist[start] = 0;                     // ���� ���������� �Ÿ��� 0

    // (�Ÿ�, ����) ���·� �����ϴ� �켱���� ť (�Ÿ� ���� ��������)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start }); // ������ �߰�

    while (!pq.empty())
    {
        int currentDist = pq.top().first; // ��������� �Ÿ�
        int currentNode = pq.top().second; // ���� ����
        pq.pop();

        // �̹� �� ª�� ��ΰ� �ִٸ� �н�
        if (currentDist > dist[currentNode])
            continue;

        // ���� �������� ����� ��� ���� Ȯ��
        for (const auto& edge : graph[currentNode])
        {
            int nextNode = edge.to;
            int newDist = currentDist + edge.weight;

            // �� ª�� ��θ� ã���� ������Ʈ
            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({ newDist, nextNode });
            }
        }
    }

    // ��� ���
    cout << "���� " << start << "���κ����� �ִ� �Ÿ�\n";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << i << " : ���� �Ұ�\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; // ���� ��, ���� ��
    cout << "���� ������ ���� ������ �Է��ϼ���: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V); // ���� ����Ʈ ����

    cout << "������ �Է��ϼ��� (���� �� ����ġ):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w }); // ���� �׷���
    }

    int start;
    cout << "���� ������ �Է��ϼ���: ";
    cin >> start;

    dijkstra(start, graph);

    return 0;
}