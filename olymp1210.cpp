#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<bool>> used(n, vector<bool>(m, false));
    vector<pair<int,int>> start, end;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '1' && !used[i][j]) {
                int k = i;
                while (k + 1 < n && a[k + 1][j] == '1' && !used[k + 1][j]) k++;
                if (k > i) {
                    start.push_back({i + 1, j + 1});
                    end.push_back({k + 1, j + 1});
                    for (int t = i; t <= k; t++) used[t][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' && !used[i][j]) {
                int k = j;
                while (k + 1 < m && a[i][k + 1] == '1' && !used[i][k + 1]) k++;
                start.push_back({i + 1, j + 1});
                end.push_back({i + 1, k + 1});
                for (int t = j; t <= k; t++) used[i][t] = true;
            }
        }
    }

    cout << start.size() << '\n';
    for (int i = 0; i < (int)start.size(); i++) {
        cout << start[i].first << " " << start[i].second << " "
             << end[i].first << " " << end[i].second << " 1\n";
    }

    return 0;
}
