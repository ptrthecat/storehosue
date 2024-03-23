//Kondziolka Piotr
#include <iostream> 
using namespace std; 

string command;
long long int W_amount,R_amount,S_amount,P_amount;
long long int total=0;

struct place
{
    unsigned short int commodity;
    char label[2]={'0','0'};
};

struct shelf
{   
    place places[128];
    short int Pamount = 0;
};
    
struct rack
{
    shelf shelves[128];
    short int Samount = 0;
};
    
struct warehouse
{
    rack racks[128];
    shelf hand_shelf;
    short int Ramount = 0;
};

struct Storehouse
{
    warehouse warehouses[128];
    rack handy_rack;
    shelf handy_shelf;
    short int Wamount = 0;
};

Storehouse storehouse;


int main()
{
    
    long long int sum=0;
    while(command!="END")
    {
        cin>>command;

        if(command=="SET-AP")
        {
            int w,r,s,P;
            cin>>w>>r>>s>>P;

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount || s<0 || s>=128 || s>=storehouse.warehouses[w].racks[r].Samount) 
                cout<<"error"<<endl;
            else
            {
                
                for(int i=storehouse.warehouses[w].racks[r].shelves[s].Pamount; i<P; i++)
                {   
                    total-=storehouse.warehouses[w].racks[r].shelves[s].places[i].commodity;

                    storehouse.warehouses[w].racks[r].shelves[s].places[i].commodity=0;
                    storehouse.warehouses[w].racks[r].shelves[s].places[i].label[0]='0';
                    storehouse.warehouses[w].racks[r].shelves[s].places[i].label[1]='0';
                }

                for(int i=P; i<storehouse.warehouses[w].racks[r].shelves[s].Pamount; i++)
                {   
                    total-=storehouse.warehouses[w].racks[r].shelves[s].places[i].commodity;

                    storehouse.warehouses[w].racks[r].shelves[s].places[i].commodity=0;
                    storehouse.warehouses[w].racks[r].shelves[s].places[i].label[0]='0';
                    storehouse.warehouses[w].racks[r].shelves[s].places[i].label[1]='0';
                }

                storehouse.warehouses[w].racks[r].shelves[s].Pamount=P;
            }

        }

        if(command=="SET-AS")
        {
            int w,r,S,P;
            cin>>w>>r>>S>>P;

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount) 
                cout<<"error"<<endl;
            else
            {
                //storehouse.warehouses[w].racks[r].Samount=S;

                for(int i=0; i<S; i++)
                {
                    for(int j=storehouse.warehouses[w].racks[r].shelves[i].Pamount; j<P; j++)
                    {   
                        total-=storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity;

                        storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity=0;
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[0]='0';
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[1]='0';
                    }
                    
                    for(int j=P; j<storehouse.warehouses[w].racks[r].shelves[i].Pamount; j++)
                    {   
                        total-=storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity;

                        storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity=0;
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[0]='0';
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[1]='0';
                    }
                    
                storehouse.warehouses[w].racks[r].shelves[i].Pamount=P;
                }


                for(int i=S; i<storehouse.handy_rack.Samount; i++)
                {

                    for(int j=0; j<storehouse.warehouses[w].racks[r].shelves[i].Pamount; j++)
                    {   
                        total-=storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity;

                        storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity=0;
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[0]='0';
                        storehouse.warehouses[w].racks[r].shelves[i].places[j].label[1]='0';
                    }
                    
                storehouse.warehouses[w].racks[r].shelves[i].Pamount=0;
                }

                storehouse.warehouses[w].racks[r].Samount=S;
            }

        }

        if(command=="SET-AR")
        {
            int w,R,S,P;
            cin>>w>>R>>S>>P;

            if(w<0 || w>=128 || w>=storehouse.Wamount || P<0 || P>128) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<R; i++)
                {
                    for(int j=0; j<S; j++)
                    {
                        for(int k=storehouse.warehouses[w].racks[i].shelves[j].Pamount; k<P; k++)
                        {   
                            total-=storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity;

                            storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity=0;
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[0]='0';
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[1]='0'; 
                        }

                        for(int k=P; k<storehouse.warehouses[w].racks[i].shelves[j].Pamount; k++)
                        {   
                            total-=storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity;

                            storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity=0;
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[0]='0';
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[1]='0'; 
                        }
                        
                        storehouse.warehouses[w].racks[i].shelves[j].Pamount=P;
                    }

                    for(int j=S; j<storehouse.warehouses[w].racks[i].Samount; j++)
                    {
            
                        for(int k=0; k<storehouse.warehouses[w].racks[i].shelves[j].Pamount; k++)
                        {   
                            total-=storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity;

                            storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity=0;
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[0]='0';
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[1]='0'; 
                        }
                        
                        storehouse.warehouses[w].racks[i].shelves[j].Pamount=0;
                    }

                    storehouse.warehouses[w].racks[i].Samount=S;
                }

                for(int i=R; i<storehouse.warehouses[w].Ramount; i++)
                {
                    
                    for(int j=0; j<storehouse.warehouses[w].racks[i].Samount; j++)
                    {
            
                        for(int k=0; k<storehouse.warehouses[w].racks[i].shelves[j].Pamount; k++)
                        {   
                            total-=storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity;

                            storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity=0;
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[0]='0';
                            storehouse.warehouses[w].racks[i].shelves[j].places[k].label[1]='0'; 
                        }
                        
                        storehouse.warehouses[w].racks[i].shelves[j].Pamount=0;
                    }

                    storehouse.warehouses[w].racks[i].Samount=0;
                }
               
                storehouse.warehouses[w].Ramount=R;
            }

        }

        if(command=="SET-AW")
        {
            int W,R,S,P;
            cin>>W>>R>>S>>P;

            for(int i=0; i<W; i++)
            {
                for(int j=0; j<R; j++)
                {
                    for(int k=0; k<S; k++)
                    {
                        for(int l=storehouse.warehouses[i].racks[j].shelves[k].Pamount; l<P; l++)
                        {   
                            total-=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;

                            storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=0;
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[0]='0';
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[1]='0'; 
                        }

                        for(int l=P; l<storehouse.warehouses[i].racks[j].shelves[k].Pamount; l++)
                        {   
                            total-=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;

                            storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=0;
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[0]='0';
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[1]='0'; 
                        }

                        storehouse.warehouses[i].racks[j].shelves[k].Pamount=P;
                    }

                    for(int k=S; k<storehouse.warehouses[i].racks[j].Samount; k++)
                    {
                        
                        for(int l=0; l<storehouse.warehouses[i].racks[j].shelves[k].Pamount; l++)
                        {   
                            total-=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;

                            storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=0;
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[0]='0';
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[1]='0'; 
                        }

                        storehouse.warehouses[i].racks[j].shelves[k].Pamount=0;
                    }

                    storehouse.warehouses[i].racks[j].Samount=S;
                }
                
                for(int j=R; j<storehouse.warehouses[i].Ramount; j++)
                {
                    
                    for(int k=0; k<storehouse.warehouses[i].racks[j].Samount; k++)
                    {
                        
                        for(int l=0; l<storehouse.warehouses[i].racks[j].shelves[k].Pamount; l++)
                        {   
                            total-=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;

                            storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=0;
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[0]='0';
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[1]='0'; 
                        }

                        storehouse.warehouses[i].racks[j].shelves[k].Pamount=0;
                    }

                    storehouse.warehouses[i].racks[j].Samount=0;
                }
                storehouse.warehouses[i].Ramount=R;
            }

            for(int i=W; i<storehouse.Wamount; i++)
            {
                
                for(int j=0; j<storehouse.warehouses[i].Ramount; j++)
                {
                    
                    for(int k=0; k<storehouse.warehouses[i].racks[j].Samount; k++)
                    {
                        
                        for(int l=0; l<storehouse.warehouses[i].racks[j].shelves[k].Pamount; l++)
                        {   
                            total-=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;

                            storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=0;
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[0]='0';
                            storehouse.warehouses[i].racks[j].shelves[k].places[l].label[1]='0'; 
                        }

                        storehouse.warehouses[i].racks[j].shelves[k].Pamount=0;
                    }

                    storehouse.warehouses[i].racks[j].Samount=0;
                }
            }
            
            storehouse.Wamount=W;
        }

        if(command=="SET-HW")
        {
            int w,P;
            cin>>w>>P;

            if(w<0 || w>=128 || w>=storehouse.Wamount || P>128) 
                cout<<"error"<<endl;
            else
            {
                for(int i=storehouse.warehouses[w].hand_shelf.Pamount; i<P; i++)
                {   
                    total-=storehouse.warehouses[w].hand_shelf.places[i].commodity;

                    storehouse.warehouses[w].hand_shelf.places[i].commodity=0;
                    storehouse.warehouses[w].hand_shelf.places[i].label[0]='0';
                    storehouse.warehouses[w].hand_shelf.places[i].label[1]='0';
                }

                for(int i=P; i<storehouse.warehouses[w].hand_shelf.Pamount; i++)
                {   
                    total-=storehouse.warehouses[w].hand_shelf.places[i].commodity;

                    storehouse.warehouses[w].hand_shelf.places[i].commodity=0;
                    storehouse.warehouses[w].hand_shelf.places[i].label[0]='0';
                    storehouse.warehouses[w].hand_shelf.places[i].label[1]='0';
                }

                storehouse.warehouses[w].hand_shelf.Pamount=P; 
            }
                       
        }

        if(command=="SET-HR")
        {
            int S,P;
            cin>>S>>P;
    
            if(S>=128 || P>128) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<S; i++)
                {   
                    for(int j=storehouse.handy_rack.shelves[i].Pamount; j<P; j++)
                    {   
                        total-=storehouse.handy_rack.shelves[i].places[j].commodity;

                        storehouse.handy_rack.shelves[i].places[j].commodity=0;
                        storehouse.handy_rack.shelves[i].places[j].label[0]='0';
                        storehouse.handy_rack.shelves[i].places[j].label[1]='0';
                    }
                    
                    for(int j=P; j<storehouse.handy_rack.shelves[i].Pamount; j++)
                    {   
                        total-=storehouse.handy_rack.shelves[i].places[j].commodity;

                        storehouse.handy_rack.shelves[i].places[j].commodity=0;
                        storehouse.handy_rack.shelves[i].places[j].label[0]='0';
                        storehouse.handy_rack.shelves[i].places[j].label[1]='0';
                    }
                    
                storehouse.handy_rack.shelves[i].Pamount=P;
                }


                for(int i=S; i<storehouse.handy_rack.Samount; i++)
                {
                    
                    for(int j=0; j<storehouse.handy_rack.shelves[i].Pamount; j++)
                    {   
                        total-=storehouse.handy_rack.shelves[i].places[j].commodity;

                        storehouse.handy_rack.shelves[i].places[j].commodity=0;
                        storehouse.handy_rack.shelves[i].places[j].label[0]='0';
                        storehouse.handy_rack.shelves[i].places[j].label[1]='0';
                    }
                    
                storehouse.handy_rack.shelves[i].Pamount=0;
                }

                storehouse.handy_rack.Samount=S;
            }
        }

        if(command=="SET-HS")
        {
            int P;
            cin>>P;

            if(P>128) 
                cout<<"error"<<endl;
            else
            {
                for(int i=storehouse.handy_shelf.Pamount; i<P; i++)
                {   
                    total-=storehouse.handy_shelf.places[i].commodity;

                    storehouse.handy_shelf.places[i].commodity=0;
                    storehouse.handy_shelf.places[i].label[0]='0';
                    storehouse.handy_shelf.places[i].label[1]='0';
                }

                for(int i=P; i<storehouse.handy_shelf.Pamount; i++)
                {   
                    total-=storehouse.handy_shelf.places[i].commodity;

                    storehouse.handy_shelf.places[i].commodity=0;
                    storehouse.handy_shelf.places[i].label[0]='0';
                    storehouse.handy_shelf.places[i].label[1]='0';
                }
            }

            storehouse.handy_shelf.Pamount=P;
        }

        if(command=="PUT-W") 
        {
            int w,r,s,p,A;
            cin>>w>>r>>s>>p>>A;
            
            if(w>=128 || r>=128 || s>=128 || p>=128 || w<0 || r<0 || s<0 || p<0 || A<0 || w>=storehouse.Wamount || r>=storehouse.warehouses[w].Ramount || s>=storehouse.warehouses[w].racks[r].Samount || p>=storehouse.warehouses[w].racks[r].shelves[s].Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=65535 || storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity+A>=65535) 
            {   
                total+=65535-storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity;
                storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity=65535;
            }
            else
            {
                storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity+=A;
                total+=A;
            }
        }

        if(command=="PUT-H") 
        {   
            long long int w,p,A;
            cin>>w>>p>>A;

            if(w>=128 || p>=128 || w<0 || p<0 || A<0 || w>=storehouse.Wamount || p>=storehouse.warehouses[w].hand_shelf.Pamount)  
                cout<<"error"<<endl;
            
            else if(A>65535 || storehouse.warehouses[w].hand_shelf.places[p].commodity+A>65535) 
            {   
                total+=65535-storehouse.warehouses[w].hand_shelf.places[p].commodity;
                storehouse.warehouses[w].hand_shelf.places[p].commodity=65535;
            }
            else
            {
                storehouse.warehouses[w].hand_shelf.places[p].commodity+=A; 
                total+=A;
            }
        }
        
        if(command=="PUT-R") 
        {
            long long int s,p,A;
            cin>>s>>p>>A;

            if(s>=128 || p>=128 || s<0 || p<0 || A<0 || s>=storehouse.handy_rack.Samount  || p>=storehouse.handy_rack.shelves[s].Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=65535 || storehouse.handy_rack.shelves[s].places[p].commodity+A>=65535) 
            {   
                total+=65535-storehouse.handy_rack.shelves[s].places[p].commodity;
                storehouse.handy_rack.shelves[s].places[p].commodity=65535;
            }
            else
            {
                storehouse.handy_rack.shelves[s].places[p].commodity+=A;
                total+=A;
            }
        }

        if(command=="PUT-S") 
        {
            long long int p,A;
            cin>>p>>A;

            if(p>=128 || p<0 || A<0 || p>=storehouse.handy_shelf.Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=65535 || storehouse.handy_shelf.places[p].commodity+A>=65535) 
            {   
                total+=65535-storehouse.handy_shelf.places[p].commodity;
                storehouse.handy_shelf.places[p].commodity=65535;
            }
            else
            {
                storehouse.handy_shelf.places[p].commodity+=A;
                total+=A;
            }
        }

        if(command=="FILL")
        {
            int W,R,S,P,A;
            cin>>W>>R>>S>>P>>A; 
        
            if(W > 128 || R > 128 || S > 128 || P > 128 || A > 65535 || W < 0 || R < 0 || S < 0 || P < 0 || A < 0)
                cout<<"error"<<endl;    
            else
            {   
                W_amount = W;
                R_amount = R;
                S_amount = S;
                P_amount = P;

                
                for(int i=0; i<W; i++)
                for(int j=0; j<R; j++)
                for(int k=0; k<S; k++)
                for(int l=0; l<P; l++)
                {    

                    //ogolnie
                    storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity=A;
                    
                    //podreczna polka magazynu
                    storehouse.warehouses[i].hand_shelf.places[l].commodity=A;
                
                    //podreczny regal skladu
                    storehouse.handy_rack.shelves[k].places[l].commodity=A;
                    
                    //podreczna polka skladu
                    storehouse.handy_shelf.places[l].commodity=A;
                }
                
                //ustawiam ilosci regalow/polek/miejsc potem dla podrecznych
                storehouse.Wamount=W_amount;

                for(int i=0; i<W; i++) 
                    storehouse.warehouses[i].Ramount=R_amount;
                
                for(int i=0; i<W; i++)
                for(int j=0; j<R; j++)
                    storehouse.warehouses[i].racks[j].Samount=S_amount;

                for(int i=0; i<W; i++)
                for(int j=0; j<R; j++)
                for(int k=0; k<S; k++)
                    storehouse.warehouses[i].racks[j].shelves[k].Pamount=P_amount;

                storehouse.handy_shelf.Pamount=P;
                storehouse.handy_rack.Samount=S;

                for(int k=0; k<S; k++)
                    storehouse.handy_rack.shelves[k].Pamount=P;
                
                for(int i=0; i<W; i++)
                    storehouse.warehouses[i].hand_shelf.Pamount=P;

                //GET-E
                total = (long long int)W*R*S*P*A + (long long int)W*P*A + (long long int)S*P*A + (long long int)P*A;
            }
            
        }

        if(command=="POP-W")
        {
            int w,r,s,p,A;
            cin>>w>>r>>s>>p>>A;
            
            if(w>=128 || r>=128 || s>=128 || p>=128 || w<0 || r<0 || s<0 || p<0 || A<0 || w>=storehouse.Wamount || r>=storehouse.warehouses[w].Ramount || s>=storehouse.warehouses[w].racks[r].Samount || p>=storehouse.warehouses[w].racks[r].shelves[s].Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity || storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity-A<=0) 
            {   
                total-=storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity;
                storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity=0;
            }
            else
            {
                storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity-=A;
                total-=A;
            }
        }

        if(command=="POP-H")
        {
            int w,p,A;
            cin>>w>>p>>A;

            if(w>=128  || p>=128 || w<0 || p<0 || A<0 || w>=storehouse.Wamount || p>=storehouse.warehouses[w].hand_shelf.Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=storehouse.warehouses[w].hand_shelf.places[p].commodity || storehouse.warehouses[w].hand_shelf.places[p].commodity-A<=0) 
            {   
                total-=storehouse.warehouses[w].hand_shelf.places[p].commodity;
                storehouse.warehouses[w].hand_shelf.places[p].commodity=0;
            }
            else
            {
                storehouse.warehouses[w].hand_shelf.places[p].commodity-=A;
                total-=A;
            }
        }

        if(command=="POP-R")
        {
            int s,p,A;
            cin>>s>>p>>A;

            if(s>=128 || p>=128 || s<0 || p<0 || A<0 || s>=storehouse.handy_rack.Samount || p>=storehouse.handy_rack.shelves[s].Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=storehouse.handy_rack.shelves[s].places[p].commodity || storehouse.handy_rack.shelves[s].places[p].commodity-A<=0) 
            {   
                total-=storehouse.handy_rack.shelves[s].places[p].commodity;
                storehouse.handy_rack.shelves[s].places[p].commodity=0;
            }
            else
            {
                storehouse.handy_rack.shelves[s].places[p].commodity-=A;
                total-=A;
            }
        }

        if(command=="POP-S")
        {   
            int p,A;
            cin>>p>>A;

            if(p>=128 || p<0 || A<0 || p>=storehouse.handy_shelf.Pamount)  
                cout<<"error"<<endl;
            
            else if(A>=storehouse.handy_shelf.places[p].commodity || storehouse.handy_shelf.places[p].commodity-A<=0) 
            {   
                total-=storehouse.handy_shelf.places[p].commodity;
                storehouse.handy_shelf.places[p].commodity=0;
            }
            else
            {            
                storehouse.handy_shelf.places[p].commodity-=A;
                total-=A;
            }
        }

        if(command=="MOV-W")
        {
            int w1,r1,s1,w2,r2,s2,p,A;
            cin>>w1>>r1>>s1>>w2>>r2>>s2>>p>>A;

            if(w1>=128 || r1>=128 || s1>=128 || p>=128 || w1<0 || r1<0 || s1<0 || p<0 || A<0 
            || w1>=storehouse.Wamount || r1>=storehouse.warehouses[w1].Ramount || s1>=storehouse.warehouses[w1].racks[r1].Samount || p>=storehouse.warehouses[w1].racks[r1].shelves[s1].Pamount
            || w2>=128 || r2>=128 || s2>=128 || p>=128 || w2<0 || r2<0 || s2<0 || p<0 || A<0 
            || w2>=storehouse.Wamount || r2>=storehouse.warehouses[w2].Ramount || s2>=storehouse.warehouses[w2].racks[r2].Samount || p>=storehouse.warehouses[w2].racks[r2].shelves[s2].Pamount)  
                cout<<"error"<<endl;
            else 
            {
                if( A>= storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity)
                {   
                    A = storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity; //ilosc dostepna

                    if(storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity + A>=65535)
                    {
                        storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity=(storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity+storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity)-65535;
                        storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity+=A;
                        storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity=0;
                    }
                }
                else
                {   
                    if(storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity + A>=65535)
                    {
                        storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity=(storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity+storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity)-65535;
                        storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.warehouses[w2].racks[r2].shelves[s2].places[p].commodity+=A;
                        storehouse.warehouses[w1].racks[r1].shelves[s1].places[p].commodity-=A;
                    }

                }
            }
    
        }

        if(command=="MOV-H")
        {
            int w,r,s,p,A;
            cin>>w>>r>>s>>p>>A;

            if(w>=128 || r>=128 || s>=128 || p>=128 || w<0 || r<0 || s<0 || p<0 || A<0 || w>=storehouse.Wamount || r>=storehouse.warehouses[w].Ramount 
            || s>=storehouse.warehouses[w].racks[r].Samount || p>=storehouse.warehouses[w].racks[r].shelves[s].Pamount || p>=storehouse.warehouses[w].hand_shelf.Pamount)
                cout<<"error"<<endl;
            else 
            {
                if( A>= storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity)
                {   
                    A = storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity; //ilosc dostepna

                    if(storehouse.warehouses[w].hand_shelf.places[p].commodity + A>=65535)
                    {
                        storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity=(storehouse.warehouses[w].hand_shelf.places[p].commodity + storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity)-65535;
                        storehouse.warehouses[w].hand_shelf.places[p].commodity =65535;
                    }
                    else
                    {
                        storehouse.warehouses[w].hand_shelf.places[p].commodity +=A;
                        storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity=0;
                    }
                }
                else
                {   
                    if(storehouse.warehouses[w].hand_shelf.places[p].commodity  + A>=65535)
                    {
                        storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity=(storehouse.warehouses[w].hand_shelf.places[p].commodity + storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity)-65535;
                        storehouse.warehouses[w].hand_shelf.places[p].commodity =65535;
                    }
                    else
                    {
                        storehouse.warehouses[w].hand_shelf.places[p].commodity +=A;
                        storehouse.warehouses[w].racks[r].shelves[s].places[p].commodity-=A;
                    }
                }
            }
        }

        if(command=="MOV-R")
        {
            int w,r,s1,s2,p,A;
            cin>>w>>r>>s1>>s2>>p>>A;

            if(w>=128 || r>=128 || s1>=128 || p>=128 || w<0 || r<0 || s1<0 || p<0 || A<0 
            || w>=storehouse.Wamount || r>=storehouse.warehouses[w].Ramount || s1>=storehouse.warehouses[w].racks[r].Samount || p>=storehouse.warehouses[w].racks[r].shelves[s1].Pamount
            || s2>=128 || s2<0 || s2>=storehouse.handy_rack.Samount || p>=storehouse.handy_rack.shelves[s2].Pamount)  
                cout<<"error"<<endl;
            else 
            {
                if( A>= storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity)
                {   
                    A = storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity; //ilosc dostepna

                    if(storehouse.handy_rack.shelves[s2].places[p].commodity + A>=65535)
                    {
                        storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity=(storehouse.handy_rack.shelves[s2].places[p].commodity + storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity)-65535;
                        storehouse.handy_rack.shelves[s2].places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.handy_rack.shelves[s2].places[p].commodity+=A;
                        storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity=0;
                    }
                }
                else
                {   
                    if(storehouse.handy_rack.shelves[s2].places[p].commodity + A>=65535)
                    {
                        storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity=(storehouse.handy_rack.shelves[s2].places[p].commodity+storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity)-65535;
                        storehouse.handy_rack.shelves[s2].places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.handy_rack.shelves[s2].places[p].commodity+=A;
                        storehouse.warehouses[w].racks[r].shelves[s1].places[p].commodity-=A;
                    }

                }
            }
        }

        if(command=="MOV-S")
        {
            int s,p,A;
            cin>>s>>p>>A;

            if(s>=128 || p>=128 || s<0 || p<0 || A<0 
            || s>=storehouse.handy_rack.Samount || p>=storehouse.handy_rack.shelves[s].Pamount
            || p>=storehouse.handy_shelf.Pamount)  
                cout<<"error"<<endl;
            else 
            {
                if( A>= storehouse.handy_rack.shelves[s].places[p].commodity)
                {   
                    A = storehouse.handy_rack.shelves[s].places[p].commodity; //ilosc dostepna

                    if(storehouse.handy_shelf.places[p].commodity + A>=65535)
                    {
                        storehouse.handy_rack.shelves[s].places[p].commodity=(storehouse.handy_shelf.places[p].commodity + storehouse.handy_rack.shelves[s].places[p].commodity)-65535;
                        storehouse.handy_shelf.places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.handy_shelf.places[p].commodity+=A;
                        storehouse.handy_rack.shelves[s].places[p].commodity=0;
                    }
                }
                else
                {   
                    if(storehouse.handy_shelf.places[p].commodity + A>=65535)
                    {
                        storehouse.handy_rack.shelves[s].places[p].commodity=(storehouse.handy_shelf.places[p].commodity + storehouse.handy_rack.shelves[s].places[p].commodity)-65535;
                        storehouse.handy_shelf.places[p].commodity=65535;
                    }
                    else
                    {
                        storehouse.handy_shelf.places[p].commodity+=A;
                        storehouse.handy_rack.shelves[s].places[p].commodity-=A;
                    }
                }
            }
        }

        if(command=="GET-E")
        {
            // long long int sum=0;

            // for(int i=0; i<storehouse.Wamount; i++)
            // for(int j=0; j<128; j++)
            // for(int k=0; k<128; k++)
            // for(int l=0; l<128; l++)
            // {   
            //     //if(!(j>=storehouse.warehouses[i].Ramount) && !(k>=storehouse.warehouses[i].racks[j].Samount) && !(l>=storehouse.warehouses[i].racks[j].shelves[k].Pamount))
            //         sum+=storehouse.warehouses[i].racks[j].shelves[k].places[l].commodity;   
            // }

            // for(int i=0; i<storehouse.Wamount; i++)
            // for(int l=0; l<128; l++)
            // {   
            //     //if(!(l>=storehouse.warehouses[i].hand_shelf.Pamount))
            //         sum+=storehouse.warehouses[i].hand_shelf.places[l].commodity;
            // }

            // for(int k=0; k<128; k++)
            // for(int l=0; l<128; l++)
            // {   
            //     //if(!(k>=storehouse.handy_rack.Samount) && !(l>=storehouse.handy_rack.shelves[k].Pamount)) 
            //         sum+=storehouse.handy_rack.shelves[k].places[l].commodity;
            // }
            
            // for(int l=0; l<128; l++)
            //     //if(!(l>=storehouse.handy_shelf.Pamount)) 
            //         sum+=storehouse.handy_shelf.places[l].commodity;

            // cout<<sum<<endl;
            cout<<total<<endl; 
        }

        if(command=="GET-W")
        {
            int w;
            cin>>w;

            long long int sum=0;

            if(w<0 || w>=128 || w>=storehouse.Wamount) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<storehouse.warehouses[w].Ramount; i++)
                for(int j=0; j<128; j++)
                for(int k=0; k<128; k++)
                    //if( !(j>=storehouse.warehouses[w].racks[i].Samount) && !(k>=storehouse.warehouses[w].racks[i].shelves[j].Pamount))
                        sum+=storehouse.warehouses[w].racks[i].shelves[j].places[k].commodity;

                for(int k=0; k<storehouse.warehouses[w].hand_shelf.Pamount; k++) 
                    //if(!(k>=storehouse.handy_shelf.Pamount))
                        sum+=storehouse.warehouses[w].hand_shelf.places[k].commodity;
            
                cout<<sum<<endl;
            }
        }

        if(command=="GET-RW")
        {
            int w,r;
            cin>>w>>r;

            long long int sum=0;

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<storehouse.warehouses[w].racks[r].Samount; i++)
                for(int j=0; j<128; j++)
                    if(!(j>=storehouse.warehouses[w].racks[r].shelves[i].Pamount))
                        sum+=storehouse.warehouses[w].racks[r].shelves[i].places[j].commodity;
                    
                cout<<sum<<endl;
            }
        }

        if(command=="GET-RH")
        {   
            long long int sum=0;

            for(int i=0; i<storehouse.handy_rack.Samount; i++)
            for(int j=0; j<128; j++)
                if(!(j>=storehouse.handy_rack.shelves[i].Pamount))
                    sum+=storehouse.handy_rack.shelves[i].places[j].commodity;
                
            cout<<sum<<endl;
        }

        if(command=="GET-SW")
        {
            int w,r,s;
            cin>>w>>r>>s;

            long long int sum=0;

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount || s<0 || s>=128 || s>=storehouse.warehouses[w].racks[r].Samount) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<storehouse.warehouses[w].racks[r].shelves[s].Pamount; i++)
                        sum+=storehouse.warehouses[w].racks[r].shelves[s].places[i].commodity;
                    
                cout<<sum<<endl;
            }
        }

        if(command=="GET-SH")
        {
            int w;
            cin>>w;

            long long int sum=0;

            if(w<0 || w>=128 || w>=storehouse.Wamount) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<storehouse.warehouses[w].hand_shelf.Pamount; i++)
                        sum+=storehouse.warehouses[w].hand_shelf.places[i].commodity;
                    
                cout<<sum<<endl;
            }
        }

        if(command=="GET-SR")
        {
            int s;
            cin>>s;

            long long int sum=0;

            if(s<0 || s>=128 || s>=storehouse.handy_rack.Samount) 
                cout<<"error"<<endl;
            else
            {
                for(int i=0; i<storehouse.handy_rack.shelves[s].Pamount; i++)
                        sum+=storehouse.handy_rack.shelves[s].places[i].commodity;
                    
                cout<<sum<<endl;
            }
        }

        if(command=="GET-S")
        {
            long long int sum=0;

            for(int i=0; i<storehouse.handy_shelf.Pamount; i++)
                sum+=storehouse.handy_shelf.places[i].commodity;
                    
            cout<<sum<<endl;
        }
        
        if(command=="SET-LW")
        {   
            int w,r,s,p;
            char dd[2];
            cin>>w>>r>>s>>p>>dd[0]>>dd[1];

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount || s<0 || s>=128 || s>=storehouse.warehouses[w].racks[r].Samount || p<0 || p>=128 || p>=storehouse.warehouses[w].racks[r].shelves[s].Pamount) 
                cout<<"error"<<endl;
            else
            {
                storehouse.warehouses[w].racks[r].shelves[s].places[p].label[0]=dd[0];
                storehouse.warehouses[w].racks[r].shelves[s].places[p].label[1]=dd[1];
            }
        }
        
        if(command=="SET-LH")
        {
            int w,p;
            char dd[2];
            cin>>w>>p>>dd[0]>>dd[1];

            if(w<0 || w>=128 || w>=storehouse.Wamount || p<0 || p>=128 || p>=storehouse.handy_shelf.Pamount) 
                cout<<"error"<<endl;
            else
            {
                storehouse.warehouses[w].hand_shelf.places[p].label[0]=dd[0];
                storehouse.warehouses[w].hand_shelf.places[p].label[1]=dd[1];
            }
        }

        if(command=="SET-LR")
        {
            int s,p;
            char dd[2];
            cin>>s>>p>>dd[0]>>dd[1];

            if(s<0 || s>=128 || s>=storehouse.handy_rack.Samount || p<0 || p>=128 || p>=storehouse.handy_rack.shelves[s].Pamount) 
                cout<<"error"<<endl;
            else
            {
                storehouse.handy_rack.shelves[s].places[p].label[0]=dd[0];
                storehouse.handy_rack.shelves[s].places[p].label[1]=dd[1];
            }
        }

        if(command=="SET-LS")
        {
            int p;
            char dd[2];
            cin>>p>>dd[0]>>dd[1];

            if(p<0 || p>=128 || p>=storehouse.handy_shelf.Pamount) 
                cout<<"error"<<endl;
            else
            {
                storehouse.handy_shelf.places[p].label[0]=dd[0];
                storehouse.handy_shelf.places[p].label[1]=dd[1];
            }
        }

        if(command=="GET-LW")
        {
            int w,r,s,p;
            cin>>w>>r>>s>>p;

            if(w<0 || w>=128 || w>=storehouse.Wamount || r<0 || r>=128 || r>=storehouse.warehouses[w].Ramount || s<0 || s>=128 || s>=storehouse.warehouses[w].racks[r].Samount || p<0 || p>=128 || p>=storehouse.warehouses[w].racks[r].shelves[s].Pamount) 
                cout<<"error"<<endl;
            else
            {   
                if(storehouse.warehouses[w].racks[r].shelves[s].places[p].label[0]=='0' && storehouse.warehouses[w].racks[r].shelves[s].places[p].label[1]=='0')
                    cout<<"--"<<endl;
                else
                {
                    cout<<storehouse.warehouses[w].racks[r].shelves[s].places[p].label[0];
                    cout<<storehouse.warehouses[w].racks[r].shelves[s].places[p].label[1]<<endl;
                }
            }
        }

        if(command=="GET-LH")
        {
            int w,p;
            cin>>w>>p;

            if(w<0 || w>=128 || w>=storehouse.Wamount || p<0 || p>=128 || p>=storehouse.warehouses[w].hand_shelf.Pamount) 
                cout<<"error"<<endl;
            else
            {   
                if(storehouse.warehouses[w].hand_shelf.places[p].label[0]=='0' && storehouse.warehouses[w].hand_shelf.places[p].label[1]=='0')
                    cout<<"--"<<endl;
                else
                {
                cout<<storehouse.warehouses[w].hand_shelf.places[p].label[0];
                cout<<storehouse.warehouses[w].hand_shelf.places[p].label[1]<<endl;
                }
            }
        }

        if(command=="GET-LR")
        {
            int s,p;
            cin>>s>>p;

            if(s<0 || s>=128 || s>=storehouse.handy_rack.Samount || p<0 || p>=128 || p>=storehouse.handy_rack.shelves[s].Pamount) 
                cout<<"error"<<endl;
            else
            {   
                if(storehouse.handy_rack.shelves[s].places[p].label[0]=='0' && storehouse.handy_rack.shelves[s].places[p].label[1]=='0') 
                    cout<<"--"<<endl;
                else
                {
                    cout<<storehouse.handy_rack.shelves[s].places[p].label[0];
                    cout<<storehouse.handy_rack.shelves[s].places[p].label[1]<<endl;
                }
            }
        }

        if(command=="GET-LS")
        {
            int p;
            cin>>p;

            if(p<0 || p>=128 || p>=storehouse.handy_shelf.Pamount) 
                cout<<"error"<<endl;
            else
            {   
                if(storehouse.handy_shelf.places[p].label[0]=='0' && storehouse.handy_shelf.places[p].label[1]=='0')
                    cout<<"--"<<endl;
                else
                {
                    cout<<storehouse.handy_shelf.places[p].label[0];
                    cout<<storehouse.handy_shelf.places[p].label[1]<<endl;
                }
            }
        }
    }

    return 0;
}
