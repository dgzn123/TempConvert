#include <stdio.h>
#include <windows.h>
void clearInputBuffer()    //干扰清除模块
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    //不断读取字符，直到遇到换行符或文件结尾
}
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
    clearInputBuffer();    //清除输入内容中的换行符，排除干扰
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
    char judge;
    printf("还想继续转换吗？请输入Y（继续）或N（结束）：");
    scanf("%c",&judge);
    clearInputBuffer();    //清除换行符，排除干扰
    if (judge == 'Y')
    {
        goto restart;
    }
    if (judge == 'N')
    {
        system("pause");
        return 0;
    }
}