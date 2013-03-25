using namespace std;
//test for git
int maxlong=0;
int findnext(int* num, int n,int startid,int d,int before,int nowlong){
    int nextid=-1;
    for(int i=startid;i<n;i++){
        if(i==nextid)
            break;
        if(num[i]-num[before]>d)
        {
            before=i;
            int tmp=findnext(num,n,i+1,d,before,nowlong+1);
            if(nextid==-1)
                nextid=tmp;
        }
        if(i==n-1)
        {
            if(maxlong<nowlong)
                maxlong=nowlong;
        }
    }
    return nextid;
}
void main(){
   int num[100000];
   int n=0;
   int d;
   while(true){
       cin>>n;
       if(n==-1){
        return;
       }
       cin>>d;
       maxlong=0;
       for(int i=0;i<n;i++){
           cin>>num[i];
       }
       findnext(num, n,1, d, 0,1);
       printf("%d\n",maxlong);
   }
   
}