#include <stdio.h>
#include <windows.h>
int main(void)
{
    //允许输入中文
    SetConsoleOutputCP(CP_UTF8);
    //读取输入
    double temp;
    char unit;
restart:
    printf("请输入带单位的温度（如45C，95F，385K）：");
    scanf("%lf%c", &temp, &unit);
    //定义字符代表摄氏度、华氏度、开尔文温度
    double C, F, K;
    //判定
    if (unit == 'C')    //输入摄氏度时
    {
        C = temp;
        F = C*9/5+32;
        K = C+273.15;
        printf("转换成华氏温度为：%.3fF，转换成开尔文温度为：%.3fK\n", F, K);
    }
    if (unit == 'F')    //输入华氏度时
    {
        F = temp;
        C = (F-32)*5/9;
        K = C+273.15;
        printf("转换成摄氏温度为：%.3fC，转换成开尔文温度为：%.3fK\n", C, K);
    }
    if (unit == 'K')    //输入开尔文温度时
    {
        K = temp;
        C = K-273.15;
        F = C*9/5+32;
        printf("转换成摄氏温度为：%.3fC，转换成华氏温度为：%.3fF\n", C, F);
    }
    if (unit != 'C' && unit != 'F' && unit != 'K')    //单位不符合规范时
    {
        printf("请输入正确的温度单位！\n再试一次：\n");
        goto restart;     //前往第10行
    }
    return 0;
}