/*
过去的2012年对小Ｑ来说是很悲催的一年，失恋了12次，每次都要郁闷1个来月。
好在小Q是个体育迷，在最痛苦的时候，他常常用观看各种体育节目来麻醉自己，比如伦
敦奥运会期间，小Q就常常在周末邀上一群单身同事聚在自己的蜗居，一边畅饮啤酒，一
边吹牛。
小Q最喜欢看的是跳水，主要原因也是因为这个项目有中国人参加，而且中国队员获
胜的几率很大，一般不会再给自己添堵，不然何谈看体育疗情伤呢。
跳水项目的一个重要环节就是裁判打分，小Q他们有时候会觉得某个裁判不公平，是
不是有意在压中国队员的分数。于是每当一个队员跳水完毕，他们几个也像电视上的裁判那
样给队员打分，并且规定，谁的分数和最终得分最接近谁就是他们当中的最佳裁判，现场奖
励啤酒一杯！
其中，最终得分是这样计算的：N个人打分，去掉一个最高分，去掉一个最低分，然后
剩余分数相加，再除以N-2即为最终得分。
凭借“看体育疗情伤”而练就的专业体育知识，小Q几乎每局必胜，这一夜，小Ｑ注
定要烂醉如泥了......
Input
输入包含多组测试用例。
每组测试用例首先是一个整数N，表示裁判的人数，然后接着是N个实数，表示N个
裁判的打分Pi，N为0时结束输入。
[TechnicalSpecification]
5<=N<=20
0<=Pi<=10
Output
请计算并输出最佳裁判的编号，每组数据输出占一行，若有多人并列最佳裁判，只要求
输出编号最小的那个。
特别说明：裁判编号按照打分的顺序从1开始，依次类推，最后一人编号为N。
SampleInput
58.39.28.78.99.0
0
SampleOutput
4
*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
void main(){
   const int COUNT=20;
   float score[COUNT];
   int n=0;

   while(true){
       cin>>n;
       if(n==0) return;
       float all=0;
       float max=0,min=10;
       int maxid=0,minid=0;
       for(int i=0;i<n;i++)
       {
           cin>>score[i];
           all+=score[i];
            if(score[i]>max)
            {
                max=score[i];
                maxid=i;
            }
            if(score[i]<min)
            {
                min=score[i];
                minid=i;
            }
       }
       float avg=(all-score[maxid]-score[minid])/(n-2);
       float min_inl=10;
       int min_inlid=0;
       for(int i=0;i<n;i++)
       {
           float inl=abs(avg-score[i]);
           if(inl<min_inl)
           {
               min_inl=inl;
               min_inlid=i;
           }
       }
       printf("%d\n",min_inlid+1);
   }//end-while