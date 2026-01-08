#include<bits/stdc++.h>
using namespace std;
string up_5="芙宁娜";
vector<string> up_4={"柯莱","北斗","夏洛蒂"};
vector<string> s5={"迪卢克","迪希雅","琴","刻晴","七七","莫娜","提纳里"};
vector<string> s4={"芭芭拉","班尼特","坎蒂斯","重云","多莉","迪奥娜","珐露珊","菲谢尔","菲米尼",
"五郎","卡维","绮良良","九条裟罗","久歧忍","莱依拉","琳妮特","米卡","凝光",
"诺艾尔","雷泽","罗莎莉亚","早柚","鹿野院平藏","砂糖","托马","香菱","行秋",
"辛焱","烟绯","瑶瑶","云堇"};
string rands4(){
    return s4[rand()%s4.size()];
}
string randup4(){
    return up_4[rand()%up_4.size()];
}
string rands5(){
    return s5[rand()%s5.size()];
}
int main(){
    srand(time(0));
    cout<<"欢迎使用原神抽卡模拟器";
    cout<<"本期五星："<<up_5<<endl;
    cout<<"本期陪跑：";
    for(int i=0;i<up_4.size();i++)cout<<up_4[i]<<" ";
    cout<<"\n常驻五星：\n";
    for(int i=0;i<s5.size();i++)cout<<i+1<<'.'<<s5[i]<<endl;
    cout<<"常驻四星：\n";
    for(int i=0;i<s4.size();i++)cout<<i+1<<'.'<<s4[i]<<((i%4==3)?'\n':' ');
    int cnt=0;
    bool pre4=0;
    int bd4=1;
    int bd5=1;
    int bdup=0;
    int mgbd=0;
    bool mgbh=0;
    while(1){
    	mgbh=0;
        cnt++;
        cin.get();
        cout<<"第"<<cnt<<"抽：";
        int x=rand()%1000;
        if(bd4<10 && bd5<90){
            if(x<943){
                cout<<"抽到了[一把武器] 3*";
                bd4++;bd5++;
            }else if(x<994){
                int y=rand()%2;
                if(y || pre4){
				    cout<<"抽到了["<<randup4()<<"] 4*";
				    pre4=0;
                }else{
                    if(rand()%49 <18)
                        cout<<"抽到了[一把武器] 4*";
                    else cout<<"抽到了["<<rands4()<<"] 4*";
                    pre4=1;
                }
                bd4=1;bd5++;
            }else{
            	int z=rand()%1000;
            	if(z<982 && mgbd<3){
                	if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                	else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                	if(bdup){mgbd++;}
                	else{mgbd=0;}
            	}else{
            		mgbh=1;
            		if(!bdup && (rand()%100 <55)){cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                	else{cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                	mgbd=0;
				}
                bd5=1;bd4=1;
            }
        }
        else if(bd4>=10 && bd5<90){
            bd4=1;
            if(x<994){
                int y=rand()%2;
                if(y)cout<<"抽到了["<<randup4()<<"] 4*";
                else{
                    if(rand()%49<18)
                        cout<<"抽到了[一把武器] 4*";
                    else cout<<"抽到了["<<rands4()<<"] 4*";
                }
                bd5++;
            }else{
            	int z=rand()%1000;
            	if(z<982 && mgbd<3){
                	if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                	else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                	if(bdup){mgbd++;}
                	else{mgbd=0;}
            	}else{
            		mgbh=1;
            		if(!bdup && (rand()%100 <55)){cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                	else{cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                	mgbd=0;
				}
                bd5=1;
            }
        }else{
            int z=rand()%1000;
        	if(z<982 && mgbd<3){
                if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
               	else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
               	if(bdup){mgbd++;}
               	else{mgbd=0;}
           	}else{
           		mgbh=1;
           		if(!bdup && (rand()%100 <55)){cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
               	else{cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
               	mgbd=0;
			}
            bd5=1;
            bd4++;
        }
        cout<<"  |  x="<<x<<" 四星保底"<<bd4-1<<" 四星大保底"<<pre4<<" 五星保底"<<bd5-1<<" 五星大保底"<<bdup<<" 明光捕获"<<mgbh<<" 明光捕获保底"<<mgbd<<endl;
    }
}
