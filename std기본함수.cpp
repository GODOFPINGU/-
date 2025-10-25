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
        if (!swapped) break; // 이미 정렬됨
    }
}

int uniqueCompact(int a[], int n) { // 정렬되어 있다고 가정
    if (n == 0) return 0;
    int w = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[w - 1]) {
            a[w] = a[i];
            w++;
        }
    }
    return w; // 중복 제거 후 길이
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

    cout << "=== 기본 배열/정렬/검색 데모 ===\n";
    const int MAXN = 50;
    int n;
    int a[MAXN];

    cout << "정수 개수 입력(1~" << MAXN << "): ";
    cin >> n;
    if (!cin || n < 1 || n > MAXN) {
        cout << "입력 오류.\n";
        return 0;
    }

    cout << n << "개의 정수 입력: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "원본: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";

    bubbleSort(a, n);
    cout << "정렬: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";

    int m = uniqueCompact(a, n);
    cout << "중복 제거 후(" << m << "개): ";
    for (int i = 0; i < m; ++i) cout << a[i] << " ";
    cout << "\n";

    cout << "합계: " << sum(a, m) << "\n";
    cout << "짝수 개수: " << countEven(a, m) << "\n";

    cout << "찾을 값 입력: ";
    int key; cin >> key;
    int pos = linearSearch(a, m, key);
    if (pos == -1) cout << "값을 찾지 못했습니다.\n";
    else cout << "인덱스 " << pos << "에서 발견.\n";

    cout << "\n=== 문자열(공백 없는 단어) 처리 데모 ===\n";
    char s[101];
    cout << "단어 입력(최대 100자): ";
    cin >> s; // 공백 기준으로 입력됨
    cout << "길이: " << my_strlen(s) << "\n";
    reverse_str(s);
    cout << "뒤집은 결과: " << s << "\n";

    cout << "끝.\n";
    return 0;
}