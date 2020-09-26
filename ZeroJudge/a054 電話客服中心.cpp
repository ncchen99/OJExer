//zerojudge a054
#include <bits/stdc++.h>
using namespace std;

int main()

{
///
string input_1;
int dictionary[26] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
char array[9];
int array_int[9];
int array_mul[8] = {8,7,6,5,4,3,2,1};
int buff_1;
int buff_2;
int check_code;
int z;
///
while(cin>>input_1)
{
for(int i=0;i<9;i++)
{
array[i]=input_1[i];
array_int[i]=array[i]-48;
}
for(int i=0;i<26;i++)
{
buff_1=dictionary[i]/10;
buff_2=dictionary[i]%10;
check_code = 0;
check_code += buff_1 + buff_2 * 9;
for(int j=0;j<8;j++)
{
check_code+=array_int[j]*array_mul[j];
}
z=10-(check_code%10);
if((check_code+array_int[8])%10==0)//s(各位相對數字乘積的總和) + 檢查碼(最後一個數字) % 10 == 0
{
printf("%c",i+65);
}
}
cout<<endl;
}
return 0;
}
