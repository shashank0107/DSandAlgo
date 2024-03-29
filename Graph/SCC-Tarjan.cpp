/* Tarjan */
int dfn[N], lowLink[N], ndfn, comp[N], instack[N];
stack<int> st;
vector<vector<int> > comps;
vector<int> adj[N];

void pre() {
    comps.clear(), ndfn = 0;
    LP(i,n+2) dfn[i] = -1, g[i].clear(), adj[i].clear();
}
void tarjan(int v) {
    dfn[v] = lowLink[v] = ndfn++, instack[v] = 1;
    st.push(v);

    for (auto ch : g[v]) {
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowLink[v] = min(lowLink[v], lowLink[ch]);
        } else if (instack[ch]) {
            lowLink[v] = min(lowLink[v], dfn[ch]);
        }
    }
    if (lowLink[v] == dfn[v]) {
        comps.pb(vector<int>());
        int x = -1;
        while (x != v) {
            x = st.top(), st.pop(), instack[x] = 0;
            comps.back().pb(x);
            comp[x] = comps.size()-1;
        }
    }
}
void makeCompGraph() {
    for (int v = 1; v <= n; v++) for (auto nb : g[v]) if (comp[nb] != comp[v]) adj[comp[v]].pb(comp[nb]);
}
/* Tarjan Ends */
