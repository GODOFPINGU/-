#include <iostream>
using namespace std;

int my_strlen(const char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void reverse_str(char s[]) {
    int i = 0, j = my_strlen(s) - 1;
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = true;
            }
        }
        if (!swapped) break; // �̹� ���ĵ�
    }
}

int uniqueCompact(int a[], int n) { // ���ĵǾ� �ִٰ� ����
    if (n == 0) return 0;
    int w = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[w - 1]) {
            a[w] = a[i];
            w++;
        }
    }
    return w; // �ߺ� ���� �� ����
}

int linearSearch(const int a[], int n, int key) {
    for (int i = 0; i < n; ++i) if (a[i] == key) return i;
    return -1;
}

int sum(const int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) s += a[i];
    return s;
}

int countEven(const int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; ++i) if (a[i] % 2 == 0) c++;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== �⺻ �迭/����/�˻� ���� ===\n";
    const int MAXN = 50;
    int n;
    int a[MAXN];

    cout << "���� ���� �Է�(1~" << MAXN << "): ";
    cin >> n;
    if (!cin || n < 1 || n > MAXN) {
        cout << "�Է� ����.\n";
        return 0;
    }

    cout << n << "���� ���� �Է�: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "����: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";

    bubbleSort(a, n);
    cout << "����: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";

    int m = uniqueCompact(a, n);
    cout << "�ߺ� ���� ��(" << m << "��): ";
    for (int i = 0; i < m; ++i) cout << a[i] << " ";
    cout << "\n";

    cout << "�հ�: " << sum(a, m) << "\n";
    cout << "¦�� ����: " << countEven(a, m) << "\n";

    cout << "ã�� �� �Է�: ";
    int key; cin >> key;
    int pos = linearSearch(a, m, key);
    if (pos == -1) cout << "���� ã�� ���߽��ϴ�.\n";
    else cout << "�ε��� " << pos << "���� �߰�.\n";

    cout << "\n=== ���ڿ�(���� ���� �ܾ�) ó�� ���� ===\n";
    char s[101];
    cout << "�ܾ� �Է�(�ִ� 100��): ";
    cin >> s; // ���� �������� �Էµ�
    cout << "����: " << my_strlen(s) << "\n";
    reverse_str(s);
    cout << "������ ���: " << s << "\n";

    cout << "��.\n";
    return 0;
}