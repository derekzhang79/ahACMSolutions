#include <iostream>

/*
����˼·����˵�ܼ򵥣��޷Ǿ��ǰ���Ʒ�ܼ�ֵ�����һλֱ�ӽ�λ��
����(total*100)%10������һλ��Ȼ��(total*10/10+10)�Ϳ��Եõ�Ҫ�������
���������и����⣬C++��ȡdouble������ʱ����о�������С���Ϊ4e-16���ң����»�ȡ���������С���ڶ�λΪ0��
��ô������ͻ�������5.0999999999999996������
������˵�����Ǹ������ͻ�õ�����Ĵ𰸡�����������ڻ�ȡ�����ʱ��+4e-16�����ͻᲹ���ǲ��ֲ�ֵ��Ȼ��Ϳ�������ȷ�����ּ����ˡ�
*/
using namespace std;
double bitch(double num){
    int a = num*100;
    if((a%10)!=0)
        a = a/10*10+10;
    return (double)a/100;
}

int main(int argc, const char * argv[]) {
    int T = -1;
    cin >> T;
    double result[100];
    for(int TestTime = 0; TestTime < T; TestTime++){
        int n = -1;
        double total = 0, m = -1;
        cin >> n >> m;
        for(int count = 0; count < n; count++){
            double price = -1;
            int number = -1;
            cin >> price >> number;
            price += 1e-16;
            price *= number;
            total += price;
        }
        total += 1e-8;
        total = bitch(total);
        if(total > m){
            result[TestTime] = -1;
        }
        else{
            result[TestTime] = m-total;
        }
    }
    for(int count = 0; count < T; count++){
        if(result[count] == -1)
            printf("Case %d: -1\n", count+1);
        else
            printf("Case %d: %.2lf\n", count+1, result[count]);
    }
    return 0;
}
