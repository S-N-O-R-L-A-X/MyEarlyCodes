#include <bits/stdc++.h>
using namespace std;

bool flag = false;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        flag = false;
        int a[100001]={0};
        int b[101];
        int n;
        cin >> n;
        memset(a, false, sizeof(bool) * 100001);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (a[x] && y != b[a[x]-1]) {
                flag = true;
            }
            a[x] = i+1;
            b[i] = y;
        }
        if (n == 1) {
            printf("Lucky dxw!\n");
            continue;
        }
        if (flag) {
            printf("Poor dxw!\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (a[b[i]] > 0) {
                flag = true;
                printf("Poor dxw!\n");
                break;
            }
        }
        if (flag) continue;
        else printf("Lucky dxw!\n");
    }
}
