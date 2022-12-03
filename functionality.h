/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay, int& colorNum/*, bool lvlUP=0*/){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
            for (int i=0;i<4;i++)
            {
              gameGrid[point_2[i][1]][point_2[i][0]]=colorNum; //for storing the shape in gamegrid, color will be colorNum
            }
            int n=rand()%7;
            colorNum=rand()%8;
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2; //it will extract random piece from BLOCKS, using value of n, as in BLOCKS array, each row has a different piece
                    point_1[i][1] = BLOCKS[n][i] / 2; //same as above
                }
            
        } 
        timer=0,delay=0.3;
    }
}


/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void checkLine() //checks if a line is completely filled, if filled it clears it
{
    int k=0;
    for (int i=0;i<M;i++) //loop will run till length of rows
    {
        int count=0;
        for (int j=N;j>0;j--) //till columns
        {
            if (gameGrid[i][j]) //as it is in loop, only a specific row and a specific column will be checked, if 1 or filled
            {
              count++; //in a single row it will tell how many columns are 1 or filled
            }
            gameGrid[k][j]=gameGrid[i][j];
        }
        if (count<N) // if count is less than column ( N=10), it means a whole row is not filled 
        {
          k++;
        }
    }
}
void movementFn(int delta_x)  // movement function (left and right movement)
{
       for (int i=0;i<4;i++)  
       {
          point_2[i][0]=point_1[i][0];
          point_1[i][0]+=delta_x;  // as point_1[i][0] is x-axis, we add value of delta_x to move it left or right
       }
       if (!anamoly()) //restricting the blocks in GameField or from overlapping each other
       {
          for (int i=0;i<4;i++)
          {
            point_1[i][0]=point_2[i][0];
          }
       }
}
/*bool rotatePossible()
{

}*/
void rotationFn() //Rotation Function
{
    int temp_a,temp_b,i=0,centre_0=point_1[1][0],centre_1=point_1[1][1];
    // centre_0 is x-axis pivot, while center_1 is y-axis pivot, [1][0] or [1][1] 
    while(i<4)
    {
      temp_a=point_1[i][1]-centre_1;
      temp_b=point_1[i][0]-centre_0;
      point_1[i][0]=centre_0-temp_a;
      point_1[i][1]=centre_1+temp_b;
      i++;
    }
}

int GameOver() //GameOver Fn
{
  int end=0;
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<2; j++)
    {
      if(gameGrid[i][j]==1)
      end++;
    }
  }
  return end;
}
void menu()
{
   std::cout<<"End"<<std::endl;
}
void firstRun(int& colorNum) //a fn to remove a single piece as first shape when game starts
{
      int n=rand()%7;
      colorNum=rand()%7;
      for (int i=0;i<4;i++)
      {
        point_1[i][0] = BLOCKS[n][i] % 2; 
        point_1[i][1] = BLOCKS[n][i] / 2; 
      }
}
void instantDrop(int& colorNum)
{
  while(anamoly())
  {
    for (int i=0;i<4;i++)
    {
        point_2[i][0]=point_1[i][0];
        point_2[i][1]=point_1[i][1];
        point_1[i][1]+=1; 
        
    }
    if (!anamoly())
    {
       for (int i=0;i<4;i++)
       {
          gameGrid[point_2[i][1]][point_2[i][0]]=colorNum; //for storing the shape in gamegrid, color will be colorNum
       } 
       break;
    }
    
  }
  
}
bool shadowAnamoly(int tmp1[4][2],int tmp2[4][2])
{
    for (int i=0;i<4;i++)
        if (tmp1[i][0]<0 || tmp1[i][0]>=N || tmp1[i][1]>=M)
            return 0;
        else if (gameGrid[tmp1[i][1]][tmp1[i][0]])
            return 0;
    return 1;
}  
void shadowMove(int delta_x,int tmp1[4][2],int tmp2[4][2])
{
  for (int i=0;i<4;i++)  
       {
          tmp1[i][0]=tmp2[i][0];
          tmp1[i][0]+=delta_x;  // as point_1[i][0] is x-axis, we add value of delta_x to move it left or right
       }
       if (!shadowAnamoly(tmp1,tmp2)) //restricting the blocks in GameField or from overlapping each other
       {
          for (int i=0;i<4;i++)
          {
            tmp1[i][0]=tmp2[i][0];
          }
       }
}
  
void shadowFn(int delta_x, int colorNum,int tmp_1[4][2],int tmp_2[4][2])
{
  for(int i=0 ;i<4; i++)
  {
    for(int j=0; j<2; j++)
    {
      tmp_1[i][j]=point_1[i][j];
      tmp_2[i][j]=point_1[i][j];
    }
  }

  
        while(shadowAnamoly(tmp_1,tmp_2))
        {
          for (int i=0;i<4;i++){
            tmp_2[i][0]=tmp_1[i][0];
            tmp_2[i][1]=tmp_1[i][1];
            tmp_1[i][1]+=1;                   
        }
        }
     
     if(delta_x)
     {
        shadowMove(delta_x,tmp_1,tmp_2);
     }
}
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
