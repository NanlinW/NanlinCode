//��ˮƿ
#include <iostream>
using namespace std;

int main()
{
    int n = 0, sum = 0, temp = 0;
    while (cin >> n)
    {
        if (n == 0)
        {
           break;
        }
        sum = 0;
        while (n >= 3)
        {
            temp = n % 3;
            n = n / 3;           
            sum += n;
            n = n + temp;
            if (n == 2)
            {
                sum++;
                n = 0;
            }
        }
        cout << sum << endl;
    }

    return 0;
}

//���������ַ���a, b�е�������Ӵ�