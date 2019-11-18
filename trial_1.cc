#include<dos.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

#define bucketSize 512
using namespace std;
void bktInput(int a,int b) {
if(a>bucketSize)
cout<<"\n\t\tBucket overflow";
else {
delay(500);
while(a>b){
cout<<"\n\t\t"<<b<<" bytes outputted.";
a-=b;
delay(500);
}
if (a>0) cout<<"\n\t\tLast "<<a<<" bytes sent\t";
cout<<"\n\t\tBucket output successful";
}
}
void main( ) {
int op, pktSize;
randomize();
cout<<"Enter output rate : "; cin>>op;
for(int i=1;i<=5;i++){
delay(random(1000));
pktSize=randi(1000);
cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
bktInput(pktSize,op);
}
}
