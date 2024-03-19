#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char b[100][100];
int n;

void setRandom(char b[][100], int n, int frequency[])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            b[i][j] = char(rand() % (67 - 65 + 1) + 65);
            while(frequency[(int(b[i][j]) - 65)] <= 0)
                b[i][j] = char(rand() % (67 - 65 + 1) + 65);
            frequency[(int(b[i][j]) - 65)]--;
        }
    }

    for(int i = 0; i <= n; i++)
    {  
        b[0][i] = '.';
        b[i][0] = '.';
        b[i][n + 1] = '.';
        b[n + 1][i] = '.';
    }
    b[n + 1][n + 1] = '.';
}

void printArray(char a[][100], int n)
{
    for(int i = 0; i <= n + 1; i++)
    {
        for(int j = 0; j <= n + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkPath(int i, int j, int x, int y, int eco, int prei, int prej, char c)
{
    
    char temp = b[i][j];
    b[i][j] = '*';

    if(i == x && j == y)
    {
        cout << "YES" << endl;
        printArray(b, n);
        b[i][j] = temp;
        return true;
    }

    bool found = 0;
    int tracker = 0;
    for(int k = 0; k < 4; k++)
    {
        int it = i + dx[k];
        int jt = j + dy[k];

        if(it >= 0 && it <= n + 1 && jt >= 0 && jt <= n + 1 && (b[it][jt] == '.' || b[it][jt] == c))
        {
            if(b[it][jt] == c && (it != x || jt != y))
                continue;
            int tempi = prei;
            int tempj = prej;
            if(prei == -1 && prej == -1 )
            {
                prei = it;
                prej = jt;
            }
            if(prei != it && prej != jt)
            {
                eco--;
                tracker = 1;
            }
            if(eco < 0)
            {
                eco++;
                tracker = 0;
                continue;
            }
            prei = i;
            prej = j;
            if (checkPath(it, jt, x, y, eco, prei, prej, c))
                found = 1;
            if(tracker)
            {
                eco++;
                tracker = 0;
            }
            prei = tempi;
            prej = tempj;
        }
    }
    b[i][j] = temp;
    if (found)
        return found;
    return false;
}




int main() {
    srand(time(NULL));

    cin >> n;
    
    int countN = (n * n) / 3;
    int frequency[3] = {countN, countN, countN};
    setRandom(b, n, frequency);
    printArray(b, n);
    while(1)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        int eco = 2;
        if(checkPath(i, j, x, y, eco, - 1, - 1, b[i][j]))
        {
            b[i][j] = '.';
            b[x][y] = '.';
        }
        cout << "---------------------------" << endl;
        printArray(b, n);
    }


    return 0;
}

