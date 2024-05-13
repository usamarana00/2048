#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int score = 0;
int high=0;
void upmove(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;		//l is for first row and r is incrementing according to j.
		for(i=1;i<4;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
						score+=a[li][ri];
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}


void newGame (int a[4][4])
{
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      a[i][j] = 0;
}



void downmove(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						
						a[i][j]=0;
						score+=a[li][ri];
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftmove(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
						score+=a[li][ri];
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightmove(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
						score+=a[li][ri];
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int a[4][4])
{
	int li,ri;
	srand(time(0)); // using srand to initialize random number
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(a[li][ri]==0)
		{
			a[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void disp(int a[4][4])
{	
	 // message displayed in the start
	cout<<"\n\n";
	cout<<"\n\t\t\t\tscore = "<<score<<endl;
	cout<<"\n\t\t\t\tscore = "<<high<<endl;
	int i,j;
	for(i=0;i<4;i++) // initiallzing the grid 
	{
		cout<<"\t\t\t\t+------------------------+\n\t\t\t\t";// for the rows
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|     ";// if the value is of an index is zero then display empty spaces
			else
				cout<<"|  "<<a[i][j]<<"  "; // else display the value and then display some space after the value
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t\n";
	cout<<"Press Esc anytime to quit the game\n";
	cout<< "Press \' n \' to start a new game \n";
	cout<< "Press \' UpArrow \' to shift up \n";
	cout<< "Press \' DownArrow \' to shift down \n";
	cout<< "Press \' Right Arrow \' to shift right \n";
	cout<< "Press \' LeftArrow \' to shift Left \n";
}

int check(int tmp[4][4],int a[4][4]) // takes two arrays as parameters
{
	int fl=1,i,j;// initializing an flag
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j]) // if corresponding elements are not equal 
    		{
    			fl=0; // change flag to zero
    			break;
			}
	return fl; // or return the flag
}

int checkover(int a[4][4])
{
	int fl=0,gl=0,i,j; // flag
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0) // if the index-value is empty then change the flag to one
    		{
    			fl=1;
				break;	
			}
			
	for(i=0;i<3;i++) 
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j]) // if the rows or the columns have same values 
    		{
    			gl=1; // change the flag to 1
    			break;
			}
			
	if(fl || gl) return 1; // return 1 if f1 OR g1 is True
	else return 0;
}
int main()
{
    cout<<"\n\t\t2048 GAME\n\n\n";
    // cout<<"\n\n\t\t\tPress any key to start\n\n\t\t";
    char choose;
    while (true) {
        cout << "(P) Play Game\n";
        cout << "(Q) Quit\n";
        cout << "Enter: ";
        cin >> choose;
        
        
        if (choose == 'P'||choose=='p') {
            // getch();
            system("cls");
            int i1,i2,i3,i4,i,j;
            int a[4][4]={0},tmp[4][4]={0};
            srand(time(0));
            i1=rand()%4;
            i2=rand()%4;
            while(1)
            {
                i3=rand()%4;
                i4=rand()%4;
                if(i3!=i1 && i4!=i2) break;
            }
            a[i1][i2]=2;
            a[i3][i4]=4;
            disp(a);
            
            int ch;
            while (1)
            {
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                        tmp[i][j]=a[i][j];
                ch=getch();
                system("cls");
                if (ch=='n') newGame(a);
                if(ch==72) upmove(a);
                if(ch==80) downmove(a);
                if(ch==75) leftmove(a);
                if(ch==77) rightmove(a);
                if(ch==27) break;
                
                if(!check(tmp,a))
                    addblock(a);
                disp(a);
                    if (high< score) {
                        high= score;
                        
                    }
                    
                if(!checkover(a))
                {
                    cout<<"\n\n\t\t\tGAME OVER!!\n\n\n"<<"final score: "<<score<<endl<<"\nhigh score: "<<high<<endl ;
                        if (score> high){
                            high = score;
                            cout<<"New high score: "<<high<<endl;
                        }
                    getch();
                    break;
                } 
            }
        } else if (choose == 'Q'||choose=='q') {
            cout << "Thanks for playing!\n";
            exit(0);
        } else {
            cout << "Invalid input, please enter 'p' or 'q'.\n";
        }
    }
    return 0;
}
