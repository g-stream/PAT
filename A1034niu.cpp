    #include<cstdio>
    #include<vector>
    #include<map>
    #include<queue>
    #include<string>
    #include<iostream>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    typedef long long LL;
    const int INF = 0x7FFFFFFF;
    const int maxn = 2e3 + 10;
    int n, k, fa[maxn], cnt[maxn], tot, z;
    int x[maxn], y[maxn], sum[maxn], p[maxn];
    string s, t, w[maxn];
    vector<string> ans;
    map<string, int> M;

    int get(int x)
    {
        return x == fa[x] ? x : fa[x] = get(fa[x]);
    }

    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n + n; i++) fa[i] = i;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> t >> z;
            if (!M[s]) w[++tot] = s, M[s] = tot;
            if (!M[t]) w[++tot] = t, M[t] = tot;
            x[i] = M[s];    y[i] = M[t];
            cnt[x[i]] += z; cnt[y[i]] += z;
        }
        for (int i = 0; i < n; i++)
        {
            int fx = get(x[i]), fy = get(y[i]);
            if (fx == fy) continue;
            if (cnt[fx]>cnt[fy]) fa[fy] = fx;
            else fa[fx] = fy;
        }
        for (int i = 1; i <= tot; i++) fa[i] = get(i), sum[fa[i]] += cnt[i], p[fa[i]]++;
        for (int i = 1; i <= tot; i++) if (sum[i] > 2*k&&p[i]>2) ans.push_back(w[i]);
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        if (ans.size())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " " << p[M[ans[i]]] << endl;
            }
        }
        return 0;
    }
