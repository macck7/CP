#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n];

    for(int i=0 ; i<n ; i++){
      cin>>arr[i];

    }

    int travellers[m];
    for(int i=0 ; i<m ; i++){
      cin>>travellers[i];
    }
    
    vector<int> age_se(n,-3);
    vector<int> piche_se(n,-3);


    for( int i=1 ; i<n ; i++){
      if(arr[i]==1){
        age_se[i]=0;
      }
    }
    age_se[0]=0;

    for( int i=1 ;i<n ;i++){ 
      if(age_se[i]==-3){
        if( i !=1){
          if(age_se[i-1]==-1){
            age_se[i]=-1;
          }
          else{
            age_se[i]=age_se[i-1]+1;
          }
        }
        else{
          if( arr[0]==1){
            age_se[i]=1;
          }
          else{
            age_se[i]=-1;
          }
        }
      }
    }



    for( int i=0 ; i<n ;i++){
      if(arr[i]==2){
        piche_se[i]=0;
      }
    }

    piche_se[0]=0;

    if( arr[n-1]==0){
      piche_se[n-1]=-1;
      //cout<<piche_se[n-1]<<endl;
    }
    else{
      if( arr[n-1]!=1){
        piche_se[n-1] = 0;
      }
      else{
        piche_se[n-1]=-1;
      }
    }

    for( int i =n-2 ; i>0 ; i--){
      if( piche_se[i]==-3){
        if(piche_se[i+1] ==-1){
          piche_se[i]=-1;
        }
        else{
          piche_se[i]=piche_se[i+1]+1;
        }
      }
    }

    for( int i=0 ;i<n ; i++ ){
      if( arr[i]==2){
        age_se[i]=0;
      }
    }

    for( int i=0 ;i<n ;i++){
      if(arr[i]==1){
        piche_se[i]=0;
      }
    }

/*
    for( auto a:age_se){
      cout<<a<<" ";
    }
    cout<<endl;
    for( auto b:piche_se){
      cout<<b<<" ";
    }
    cout<<endl;

*/

    vector<int> v(n,-3);

    for( int i=0 ; i<n ; i++){
      if( arr[i]!=0){
        v[i]=0;
      }
    }
    for( int i=0 ;i<n ;i++){
      if(v[i]==-3){
        if(age_se[i]==-1 and piche_se[i]==-1){
          v[i]=-1;
        }
        else if(age_se[i]!=-1 and piche_se[i]!=-1){
          v[i]= min(age_se[i],piche_se[i]);
        }
        else{
          v[i]=(age_se[i]==-1)?piche_se[i]:age_se[i];
        }
      }
    }
    for(int i=0 ; i<m;i++){
      cout<<v[travellers[i]-1]<<" ";
    }
    cout<<endl;
   
  }   
  return 0;
}
