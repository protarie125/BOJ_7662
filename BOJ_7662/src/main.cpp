#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

priority_queue<int> pq1{};
priority_queue<int, vector<int>, greater<int>> pq2{};
map<int, int> reco{};

void insert(int n) {
    pq1.push(n);
    pq2.push(n);

    if (reco.end() == reco.find(n))
        reco.insert({ n, 0 });

    reco[n] += 1;
}

void popMax() {
    while (!pq1.empty() && 0 == reco[pq1.top()])
        pq1.pop();

    if (pq1.empty())
        return;

    auto max = pq1.top();
    pq1.pop();

    reco[max] -= 1;
}

void popMin() {
    while (!pq2.empty() && 0 == reco[pq2.top()])
        pq2.pop();

    if (pq2.empty())
        return;

    auto min = pq2.top();
    pq2.pop();

    reco[min] -= 1;
}

int getMax() {
    return pq1.top();
}

int getMin() {
    return pq2.top();
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        pq1 = priority_queue<int>{};
        pq2 = priority_queue<int, vector<int>, greater<int>>{};
        reco = map<int, int>{};

        int k;
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            string q;
            int n;
            cin >> q >> n;

            if ("I" == q) {
                insert(n);
            }
            else if ("D" == q) {
                if (1 == n) {
                    popMax();
                }
                else if (-1 == n) {
                    popMin();
                }
            }
        }

        while (!pq1.empty() && 0 == reco[pq1.top()])
            pq1.pop();

        while (!pq2.empty() && 0 == reco[pq2.top()])
            pq2.pop();

        if (pq1.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << getMax() << ' ' << getMin() << '\n';
        }
    }

    return 0;
}