#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>


using namespace std;

void show(char[]);      
void design();          
void gotoxy(int,int);   
void lru();              
void fifo();            
void opt();              
void compare();          
void new_algo();         //an updated algorithm combining lru and FIFO


int s=2;                                                       
char ch[50];                                                  
int i,k=0,c,n,f,a[5000];
    
int main()
{
    int z,y;
    
    design();
    system("cls");
    
 diff:   cout<<"enter the length of the reference string (Limit 5000): ";      
   cin>>n;
   cout<<"the reference string is: ";
   for(i=0;i<n;i++)
      {
	  a[i]=rand()%100;
	  cout<<a[i];}   
   cout<<"\nenter the frame size (Limit 20): ";
      cin>>f; 
    
same: cout<<"Choose the page replacement algorithm you want to use\n";
    cout<<"1.LRU\n2.FIFO\n3.OPTIMAL\n4.NEW ALGO\n5.COMPARE\n";
    cin>>z;
    system("cls");
    cout<<"Reference string : ";
    for(i=0;i<n;i++)
      cout<<a[i];                                                     
      cout<<"\n";
    switch(z)
    {
    	case 1: lru(); 
		        break;
		case 2: fifo();
		        break;
		case 3: opt();
		        break;
		case 4: new_algo();
		        break;
		case 5: compare();
		        break;
    	default: cout<<"enter the right choice\n";
    	         break;
	}
	
	cout<<"\n\n\nchoose what you want to do next\n";
	cout<<"\n\n1.perform a different algorithm on the same reference string\n2.enter a new reference string and perform the desired algorithm\n3.exit the program\n";
    cin>>y;
    switch(y)
    {
    	case 1: goto same;
    	        break;
    	case 2: goto diff;
    	        break;
    	case 3: goto con;
    	        break;
        default : cout<<"enter the right choice\n";
                  break;
	}
  con:  cout<<"\n\nPress any key to exit";
    _getch();
    
    system("cls");
    gotoxy(17,10);
    cout<<"Initialising shut down sequence in...";
    for(i=5;i>0;i--)
    {
      gotoxy(35,13);
      cout<<i;
      Sleep(500);
    }
    
    return 0;
}

void lru()
{
   int i,j,k,l,p=15,c=0;
   int b[20],q,min=50;
   string fault = "";
     
   for(j=0;j<f;j++)
      b[j]=-1;                             
      //cout<<"\n\nstring\t\tFault\t\tFrames";
   for(i=0;i<n;i++)
   {
      for(j=0;j<f;j++)
      {
         if(a[i]==b[j])                 
           break;
         else 
           continue;               
      }
      
      if(j==f)
      {
         for(k=0;k<f;k++)
           if(b[k]==-1)
           {
              b[k]=a[i];                  
         
              break;         
           }
           
          if(k==f)
          {
             min=50;
             for(j=0;j<f;j++)
             {
               l=i-1;
               while(l>=0)
               { 
                 if(a[l]==b[j])
                 {
                    if(l<min)
                    {  
                       min=l;
                       p=j;
                    }     
                    break;
                 }
                 l--;
               }
             }
           }       
           b[p]=a[i];  
           c++;
           fault = "Fault";
             
      }          
        //cout<<"\n\n";
        // cout<<a[i]<<"\t\t"<<fault<<"\t\t";
        // fault = "";
        // for(k=0;k<f;k++)
        //   cout<<b[k]<<"   ";
          
   }  
    cout<<"\n\npage fault by LRU is: "<<c<<"\n\n";   
}

void fifo()
{
int i,j,k,l=0,c=0;
int b[20];
	          
   for(j=0;j<f;j++)       
      b[j]=-1; 
	 // cout<<"\n\nstring\t\tFrames";                
   for(i=0;i<n;i++)
   {
      for(j=0;j<f;j++)   
      {
         if(b[j]==a[i])     
           break;
         else
           continue;   
      }
      if(j==f)
      {
         for(k=0;k<f;k++)
            if(b[k]==-1)  
            {   
                b[k]=a[i];
                c++;
                break;             
            }
         if(k==f)              
         {
            while(1)
            {
               b[l]=a[i];    
               c++;
               l++;
               break;      
            }      
            if(l==f)
              l=0;    
         }
      }
    //cout<<"\n\n";
    //cout<<a[i]<<"\t\t";
      //for(k=0;k<f;k++)        
        //cout<<b[k]<<"   ";
   }
   cout<<"\n\npage fault by fifo is "<<c<<"\n";
}

void opt()
{
   int i,j,k,l,p,c=0,s;
   int b[20],q,max;
   
   for(j=0;j<f;j++)
   b[j]=-1;                
   //cout<<"\n\nstring\t\tFrames";   
   for(i=0;i<n;i++)
   {
                   
                    for(k=0;k<f;k++)
                           if(b[k]==a[i])
                           goto here;
                                    
                   
                   for(j=0;j<f;j++)
                   {
                                   if(b[j]==-1)               
                                    {
                                                       b[j]=a[i];
                                                       c++;
                                                       goto here;
                                    }
                                               
                   }
          
                   if(j==f)
                   {
                                    l=i+1,max=0;
                           for(j=0;j<f;j++)
                           {
                           
                                             for(s=l;s<n;s++)
                                             { 
                                               if(a[s]==b[j])
                                               {
                                                             if(s>max)
                                                             {  
                                                                max=s;
                                                                p=j;
                                                             }     
                                                             break;
                                               }
                                                
                                             }
                                             if(s==n)
                                             {
                                               max=s;
                                               p=j;
                                             }
                                             
                           }
                   }       
                   b[p]=a[i];  
                    c++; 
                     
  here:  cout<<"";
    //cout<<"\n\n";
    //cout<<a[i]<<"\t\t";
      //for(k=0;k<f;k++)        
        //cout<<b[k]<<"   ";
          
   }  
    cout<<"\n\npage fault by optimal is: "<<c<<"\n";   
}

void compare()
{
	lru();
	fifo();
	opt();
	new_algo();
}

void new_algo()
{
    int i, j, k, l, p = 15, c1 = 0, r, curr=0;
    int b[20], q, min = 50;
    int c2 = 0, s;
    int max;



    for (j = 0; j < f; j++)
        b[j] = -1;

    for (i = 0; i < n; i++)
    {
        r = i % 2;
        if (r == 0)
        {
            for (j = 0; j < f; j++)
            {
                if (a[i] == b[j])
                    break;
                else
                    continue;
            }

            if (j == f)
            {
                for (k = 0; k < f; k++)
                    if (b[k] == -1)
                    {
                        b[k] = a[i];

                        break;
                    }

                if (k == f)
                {
                    min = 50;
                    for (j = 0; j < f; j++)
                    {
                        l = i - 1;
                        while (l >= 0)
                        {
                            if (a[l] == b[j])
                            {
                                if (l < min)
                                {
                                    min = l;
                                    p = j;
                                }
                                break;
                            }
                            l--;
                        }
                    }
                }
                b[p] = a[i];
                c1++;

            }
            cout << "";
            //for(k=0;k<f;k++)
              //cout<<b[k];

        }
        else if (r != 0) {

            for (j = 0; j < f; j++)   
            {
                if (b[j] == a[i])
                    break;
                else
                    continue;
            }
            if (j == f)
            {
                for (k = 0; k < f; k++)
                    if (b[k] == -1)
                    {
                        b[k] = a[i];
                        c2++;
                        break;
                    }
                if (k == f)
                {
                    while (1)
                    {
                        b[curr] = a[i];     
                        c2++;
                        curr++;
                        break;
                    }
                    if (curr == f)
                        curr = 0;
                }
            }
        here:   cout << "";
            //for(k=0;k<f;k++)
            //cout<<b[k];

        }
    }

    cout << "\n\nthe page fault by new algorithm is : " << c1 + c2;
}


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x; coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void show(char ch[50])
{
     for(int i=0;ch[i]!='\0';i++)
     {
             cout<<ch[i];
             Sleep(100);
     }
}


void design()
{
    char ch[50];
    int i;
    
    cout<<"--------------------------------------------------------------------------------";
    gotoxy(0,23);
    cout<<"--------------------------------------------------------------------------------";

    for(i=0;i<22;i++)
    {
     gotoxy(0,i+1);
     cout<<"|"<<endl;
    }    
    
    for(i=0;i<22;i++)
    {
     gotoxy(79,i+1);
     cout<<"|"<<endl;
    }   
    
    gotoxy(1,1);
    cout<<"******************************************************************************"; 
    
    gotoxy(1,22);
    cout<<"******************************************************************************"; 

    for(i=0;i<20;i++)
    {
     gotoxy(1,i+2);
     cout<<"*"<<endl;
    }
    
    for(i=0;i<20;i++)
    {
     gotoxy(78,i+2);
     cout<<"*"<<endl;
    }
    
    gotoxy(2,2);
    cout<<"----------------------------------------------------------------------------";
    
    gotoxy(2,21);
    cout<<"----------------------------------------------------------------------------";

    for(i=0;i<20;i++)
    {
     gotoxy(2,i+2);
     cout<<"|"<<endl;
    }    
    
    for(i=0;i<20;i++)
    {
     gotoxy(77,i+2);
     cout<<"|"<<endl;
    }   
    
    
    gotoxy(28,6);
    strcpy_s(ch,"PAGE REPLACEMENT ALGORITHM");
    show(ch);
    
       
    Sleep(500);
   
    gotoxy(35,12);
    cout<<"loading....";
    Sleep(500);
    
    gotoxy(10,13);
    for(i=0;i<59;i++)
    {
      cout<<"!";
      Sleep(15);
    }
    
    gotoxy(35,12);
    cout<<"                         ";
    
    gotoxy(10,13);
    cout<<"                                                                 ";
    
    gotoxy(27,13);
    cout<<"press any key to continue....";
    _getch();
}
