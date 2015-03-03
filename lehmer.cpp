#include <cstdio>
#include <cstring>

const int N = 10001;
int n;

int t[N]; /* prefix sums */

void update(int i)
{   while(i < n)
    {   t[i] += 1;
        i |= i + 1;
    }
}

int get(int i)
{   int s = 0;
    while(i >= 0)
    {   s += t[i];
        i = (i & (i + 1)) - 1;
    }
    return s;
}

int p[N]; /* permutation */
int d[N]; /* Lehmer code */

/* permutation -> Lehmer */
void rank()
{   memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++)
    {   d[i] = p[i] - get(p[i] - 1);
        update(p[i]);
    }
}

/* Lehmer -> permutation */
void unrank()
{   memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++)
    {   int l = 0, r = n - 1;
        while(l <= r)
        {   int m = (l + r) / 2;
            int z = m + 1 - get(m);
            if(z >= d[i] + 1)
            {   p[i] = m;
                r = m - 1;
            }
            else
            {   l = m + 1;
            }
        }
        update(p[i]);
    }
}

int main(void)
{   return 0;
}
