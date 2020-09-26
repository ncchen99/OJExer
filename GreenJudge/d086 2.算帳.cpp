/**********************************************************************************/
/*  Problem: d086 "2.算帳" from 106年台中區複賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 212KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-09-12 19:55:38                                     */
/**********************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct item
{
    string snum;//SerialNumber
    int pprice;//ProductPrice
    int amount;
};
int main()
{
    vector<item> product;
    item tmp;
    double total=0;
    while(cin>>tmp.snum)
    {
        if(tmp.snum=="0000000000")
            break;
        cin>>tmp.pprice>>tmp.amount;
        bool found=false;
        for(int i=0; i<product.size(); i++)
        {
            if(product[i].snum==tmp.snum)
            {
                product[i].amount+=tmp.amount;
                found=true;
                break;
            }
        }
        if(not found)
        {
            product.push_back(tmp);
        }
    }
    for(int i=0; i<product.size(); i++)
        {
            //cout <<product[i].snum<<" "<<product[i].pprice<<" "<<product[i].amount<<endl;
        }
    for(int i=0; i<product.size(); i++)
    {
        if(product[i].snum[0]=='X')//買一松一 3件=2件的錢
        {
            total+=product[i].amount/2*product[i].pprice+(product[i].amount%2)*product[i].pprice;
            //cout<<product[i].amount/2*product[i].pprice+(product[i].amount%2)*product[i].pprice<<endl;
        }
        else if(product[i].snum[0]=='Y')
        {
            total+=(product[i].amount/2)*product[i].pprice+(product[i].amount/2)*product[i].pprice*0.5+(product[i].amount%2)*product[i].pprice;
            //cout<<(product[i].amount/2)*product[i].pprice+(product[i].amount/2)*product[i].pprice*0.5+(product[i].amount%2)*product[i].pprice<<endl;
        }
        else
        {
            total+=product[i].amount*product[i].pprice;
        }
        //cout<<product->first<<" "<<product->second<<endl;
    }
    cout<<total<<endl;
}