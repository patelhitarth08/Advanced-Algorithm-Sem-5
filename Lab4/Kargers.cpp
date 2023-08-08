#include<bits/stdc++.h>


using namespace std;


int main()
{
   int e=10,v=6;
   vector<vector<int>> graph(e,vector<int> (4,0)); // 1 & 2 for edges and 3rd for remove flag


   graph[0] = {0,1,5,0};
   graph[1] = {0,3,2,0};
   graph[2] = {0,4,1,0};
   graph[3] = {1,2,4,0};
   graph[4] = {1,3,3,0};
   graph[5] = {2,3,7,0};
   graph[6] = {2,4,6,0};
   graph[7] = {3,4,8,0};
   graph[8] = {3,5,3,0};
   graph[9] = {4,5,6,0};






   vector<int> connect(v);


   for(int i=0; i < v;i++)
   {
       connect[i]=i;
   }




   int count = v;
   srand((int)time(0));


   while(count != 2)
   {
       int random  = rand() % e;


       if(graph[random][3] !=0)
           continue;
      
       graph[random][3]=1;
      


       if(connect[graph[random][1]] !=connect[graph[random][0]])
       {


           for(int i=0;i<v;i++)
           {
               if(connect[i] == connect[graph[random][1]] || connect[i] == connect[graph[random][0]])
               connect[i] =connect[graph[random][0]] ;
              
           }
           count -- ;
       }


   }




   cout<<"Printing Removing edges"<<endl;
   int ans =0;
   for(int i=0;i<e;i++)
   {
       if(graph[i][3]!=0 || (graph[i][3] == 0 && connect[graph[i][0]] == connect[graph[i][1]]))
       {
           cout<<"Edge between " <<graph[i][0] <<" and " <<graph[i][1] <<" with value "<<graph[i][2]<<endl;
       }


       else
           ans+=graph[i][2];


   }


   cout<<"Min cut is equal to "<<ans;


   return 0;


}
