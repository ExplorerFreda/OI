# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cmath>
# define rep(i,j,k) for (int i=j; i<=k; i++)
using namespace std;
const int MAX_N = 20;
double  a[MAX_N][MAX_N];
double  ans[MAX_N];
int     ul[MAX_N], ur[MAX_N];
int     N;
 
int main() {
	freopen("sphere.in","r",stdin);
	freopen("sphere.out","w",stdout);
    scanf("%d",&N);
    memset(ul, 0, sizeof(ul));
    memset(ur, 0, sizeof(ur));
    memset(a, 0, sizeof(a));
    rep(i, 1, N+1) rep(j, 1, N) {
        scanf("%lf",&a[i][j]);
        a[i][N+1] += a[i][j] * a[i][j];
        a[i][j] *= 2.0;
    }
    rep(i, 1, N) rep(j, 1, N+1) 
        a[i][j] -= a[N+1][j];
    rep(t, 1, N) {
        double maxi = 0;
        int l, r;
        rep(i, 1, N) if (!ul[i]) 
            rep(j, 1, N) if (fabs(a[i][j]) > fabs(maxi) && !ur[j])
                maxi = a[i][j], l = i, r = j;
        ul[l] = 1, ur[r] = 1;
        rep(i, 1, N) if (i != l) {
            double reduce = a[i][r]/a[l][r];
            rep(j, 1, N+1) a[i][j] -= reduce * a[l][j];
        }
    }
    rep(i, 1, N) rep(j, 1, N) 
        if (fabs(a[i][j]) > 1e-8) ans[j] = a[i][N+1]/a[i][j];
    rep(i, 1, N-1) printf("%.3lf ",ans[i]);
    printf("%.3lf\n",ans[N]);
	fclose(stdout);
    return 0;
}