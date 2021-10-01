#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define deb(x)          cout << #x << "=" << x << endl
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n;
vi arr, seg, present;

void buildTree(int s, int e, int idx) {
	if (s == e) {
		seg[idx] = 1;
		return;
	}

	int mid = (s + e) / 2;
	buildTree(s, mid, 2 * idx);
	buildTree(mid + 1, e, 2 * idx + 1);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	return;
}

int query(int s, int e, int qs, int qe, int idx) {
	if (s > qe || e < qs) {
		return 0;
	}

	if (s >= qs and e <= qe) {
		return seg[idx];
	}

	int mid = (s + e) / 2;
	int L = query(s, mid, qs, qe, 2 * idx);
	int R = query(mid + 1, e, qs, qe, 2 * idx + 1);
	return L + R;
}

void update(int s, int e, int i, int idx) {
	if (i < s || i > e) {
		return;
	}

	if (s == e) {
		seg[idx] = 0;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, i, 2 * idx);
	update(mid + 1, e, i, 2 * idx + 1);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	return;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	arr.resize(n);
	seg.resize(4 * n + 1);
	present.resize(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	buildTree(0, n - 1, 1);

	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;

		int s = 0;
		int e = n - 1;
		int ans_id = -1;

		while (s <= e) {
			int mid = (s + e) / 2;
			int sub = query(0, n - 1, 0, mid, 1);
			if (sub > id) {
				e = mid - 1;
			} else if (sub < id) {
				s = mid + 1;
			} else {
				if (present[mid]) {
					ans_id = mid;
					break;
				}
				else {
					e = mid - 1;
				}
			}
		}

		present[ans_id] = 0;
		update(0, n - 1, ans_id, 1);

		//cout<<ans_id<<" ";

		cout << arr[ans_id] << " ";
	}
}

int32_t main()
{
	clock_t begin = clock();
	c_p_c();
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}