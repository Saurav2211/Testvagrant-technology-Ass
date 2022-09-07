#include <bits/stdc++.h>
using namespace std;

class Basket{
    
public:
    string product;
    int price;
    int gst;
    int Qty;
    
    Basket(string pro,int prc,int g,int qt){
        
        product=pro;
        price=prc;
        gst=g;
        Qty=qt;
    }
    double Amount(vector<Basket>mybucket,int n){
        
        int discount = 5;
        int amt=0;
        for(int i=0;i<n;i++){
            
            Basket bst = mybucket[i];
            
            if(bst.price>500){
                amt+=bst.Qty*(bst.price-(bst.price*(discount/100))+(bst.price*bst.gst/100));
            }
            else{
                amt+=bst.Qty*(bst.price+(bst.price*bst.gst/100));
            }
            
        }
        return amt;
        
    }
    
    string maxGST(vector<Basket> mybucket,int n){
        
        double maxv=0;
        double res=1;
        string ans;
        
        for(int i=0;i<n;i++){
            
            maxv=0;
            Basket bst = mybucket[i];
            
            maxv=(bst.price*(bst.gst*100)*(bst.Qty) );
            
            if(maxv>res){
                res=maxv;
                ans=bst.product;
            }
            
        }
        return ans;      
        
        
    }
    
    
};


int main(){
    
   Basket b1("Leather wallet",1100,18,1);
   
   Basket b2("Umbrella" ,900,12,2);
   Basket b3("Cigarette" ,200,28,3);
   Basket b4("Honey" ,100,0,4);
   vector<Basket> mybasket;
   
   mybasket.push_back(b1);
   mybasket.push_back(b2);
   mybasket.push_back(b3);
   mybasket.push_back(b4);
   
   int n=4;
   
   
   
   cout<<b1.Amount(mybasket,n)<<endl;
   cout<<b1.maxGST(mybasket,n);
   
   
   
    
}