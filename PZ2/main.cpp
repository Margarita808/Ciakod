#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
using namespace std;

void swapRange(vector<int>& b, int x, int y, int k) {
    for (int t = 0; t < k; ++t) {
        int temp = b[x + t];
        b[x + t] = b[y + t];
        b[y + t] = temp;
    }
}

void swapSegments(vector<int>& b, int m, int n, int p) {
    int left = m;
    int right = p - 1;
    int i = n - m;
    int j = p - n;

    while (i != j) {
        if (i > j) {
            swapRange(b, left, right - j + 1, j);
            left += j;
            i -= j;
        }
        else {
            swapRange(b, right - i + 1 - j, right - i + 1, i);
            right -= i;
            j -= i;
        }
    }
    swapRange(b, left, left + i, i);
}

vector<int> toDigits(const wstring& s) {
    vector<int> result;
    for (wchar_t c : s) {
        result.push_back(c - L'0');
    }
    return result;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wstring arrayInput;
    int m, n, p;

    wcout << L"Введите массив: ";
    wcin >> arrayInput;

    wcout << L"Введите m (начало первого сегмента): ";
    wcin >> m;
    wcout << L"Введите n (граница между сегментами): ";
    wcin >> n;
    wcout << L"Введите p (конец второго сегмента + 1): ";
    wcin >> p;

    vector<int> b = toDigits(arrayInput);

    if (m < 0 || m >= n || n >= p || p > static_cast<int>(b.size())) {
        wcout << L"Некорректные значения m, n, p" << endl;
        return 1;
    }

    swapSegments(b, m, n, p);

    for (int digit : b) wcout << digit;
    wcout << endl;

    return 0;
}
