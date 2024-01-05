#include <iostream>

using namespace std;
//variables declaration
char array[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player='x';
int xCounter=0,oCounter=0;
void printMatrix()
{

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<array[0][0]<<"  |  "<<array[0][1]<<"  |  "<<array[0][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<array[1][0]<<"  |  "<<array[1][1]<<"  |  "<<array[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<array[2][0]<<"  |  "<<array[2][1]<<"  |  "<<array[2][2]<<" \n";
    cout<<"\t     |     |     \n";
}
void play()
{
    cout<<"Choose Your Position - (player : "<<player<<" ) "<<endl;
    char position;
    cin>>position;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(array[i][j]==position)
            {
                array[i][j]=player;
                break;
            }
        }
    }
    if(player=='x')
        player='o';
    else
        player='x';
}
char playerWin()
{
    int test=0;
    //test Row
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(array[i][j]!='x'&&array[i][j]!='o')
                test++;
            if(array[i][j]=='x')
                xCounter++;
            else if(array[i][j]=='o')
                oCounter++;
            if(xCounter==3||oCounter==3)
            {
                if(xCounter>oCounter)
                    return 'x';
                else
                    return 'o';
            }
        }
        xCounter=oCounter=0;
    }
    //test colome
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(array[i][j]!='x'&&array[i][j]!='o')
                test++;
            if(array[j][i]=='x')
                xCounter++;
            else if(array[j][i]=='o')
                oCounter++;
            if(xCounter==3||oCounter==3)
            {
                if(xCounter>oCounter)
                    return 'x';
                else
                    return 'o';
            }
        }
        xCounter=oCounter=0;
    }
    //test diagonal && anti_diagonal
    if(array[0][0]=='x'&&array[1][1]=='x'&&array[2][2]=='x')
        return 'x';
    else if(array[0][0]=='o'&&array[1][1]=='o'&&array[2][2]=='o')
        return 'o';
    else if(array[0][2]=='x'&&array[1][1]=='x'&&array[2][0]=='x')
        return 'x';
    else if(array[0][2]=='o'&&array[1][1]=='o'&&array[2][0]=='o')
        return 'o';
    if(test==0)
        return 'z';
    return '.';
}
int main()
{
    system("cls");
    system("Color 4F");
    while(playerWin()=='.')
    {
        printMatrix();
        play();
        system("cls");
    }
    printMatrix();
    if(playerWin()=='z')
        cout<<"\n No Winner !! "<<endl;
    else
        cout<<"\nThe Winer of Game is : ( "<<playerWin()<<" ) , Congratulation"<<endl;
    return 0;
}
