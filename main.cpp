#include <bits/stdc++.h>
using namespace std;
const int N=3;
int p=0,draw=1;
char board[3][3];
char player[2]={'X','O'};
void init();
void showconfig();
int checkwin();
int checklegal(int, int, char);
int main()
{
    int m=0,i,j;
    init();
    showconfig();
    while(checkwin()==0 && m<9)
    {
        cout<<"Player "<<p+1<<" 's move:";
        cin>>i>>j;
        if(checklegal(i-1,j-1,player[p])==1)
        {
           showconfig();
        }
        else
        {
            continue;
        }
         p=(p+1)%2;
    }
    if(draw==1)
    {
        cout<<"The game is drawn";
    }

}
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            board[i][j]=' ';
        }
    }
}
void showconfig()
{
    cout<<"------"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
        cout<<"------"<<endl;
    }
}
int checklegal(int i,int j,char c)
{
    if(i>=0 && j>=0 &&i<3 && j<3)
    {
        if(board[i][j]==' ')
        {
            board[i][j]=c;
            return 1;
        }
        else
        {
            cout<<"Not a possible move"<<endl;
            return 0;
        }
    }
}
int checkwin()
{
    for(int i=0;i<N;i++)
    {
        int count=0;
        for(int j=0;j<N;j++)
        {
            if(board[i][j]=='X')
            {
                count++;
            }
            else
            {
                break;
            }
            if(count==3)
            {
                draw=0;
                cout<<"The winner of the game is player 1"<<endl;
                return 1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        for(int j=0;j<N;j++)
        {
            if(board[i][j]=='O')
            {
                count++;
            }
            else
            {
                break;
            }
            if(count==3)
            {
                draw=0;
                cout<<"The winner of the game is player 2"<<endl;
                return 1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        for(int j=0;j<N;j++)
        {
            if(board[j][i]=='X')
            {
                count++;
            }
            else
            {
                break;
            }
            if(count==3)
            {
                draw=0;
                cout<<"The winner of the game is player 1"<<endl;
                return 1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        for(int j=0;j<N;j++)
        {
            if(board[j][i]=='O')
            {
                count++;
            }
            else
            {
                break;
            }
            if(count==3)
            {
                draw=0;
                cout<<"The winner of the game is player 2"<<endl;
                return 1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        if(board[i][i]=='X')
        {
            count++;
        }
        if(count==3)
        {
            draw=0;
            cout<<"The winner of the game is player 1"<<endl;
            return 1;
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        if(board[i][2-i]=='X')
        {
            count++;
        }
        if(count==3)
        {
            draw=0;
            cout<<"The winner of the game is player 1"<<endl;
            return 1;
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        if(board[i][i]=='O')
        {
            count++;
        }
        if(count==3)
        {
            draw=0;
            cout<<"The winner of the game is player 2"<<endl;
            return 1;
        }
    }
    for(int i=0;i<N;i++)
    {
        int count=0;
        if(board[i][2-i]=='O')
        {
            count++;
        }
        if(count==3)
        {
            draw=0;
            cout<<"The winner of the game is player 2"<<endl;
            return 1;
        }
    }

    return 0;

}
