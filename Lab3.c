//
//  main.c
//  Lab3_369A
//
//  Created by Mohammed AlRukhayes on 23/09/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define FRAME_WIDTH 64
#define FRAME_HEIGHT 64
#define BLOCK_SIZE 8 // Example block size

#define FRAME_R 16
#define FRAME_C 16
#define WINDOW_R 4
#define WINDOW_C 8

//#define FRAME 16
//#define WINDOW 16


int main()
{
            //y, x
    int frame[FRAME_R][FRAME_C] = {{9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7},
                                {9, 7, 7, 7, 7, 5, 6, 7, 8, 9, 10, 11, 6, 7, 7, 7},
                            {9, 7, 7, 7, 7, 3, 12, 14, 16, 18, 20, 6, 6, 7, 7, 7},
                            {9, 7, 7, 7, 7, 4, 18, 21, 24, 27, 30, 33, 6, 7, 7, 7},
                            {0, 7, 7, 7, 7, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},
                            {0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70,  75},
                            {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90},
                            {0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105},
                            {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120},
                            {0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135},
                            {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150},
                            {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165},
                            {9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3},
                            {9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3},
                            {9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3},
                            {9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3}};
    
    int window[WINDOW_R][WINDOW_C] = {{9, 9, 9, 9,9, 9, 9, 9},
                                    {9, 9, 9, 9,9, 9, 9, 9},
                                    {9, 9, 9, 9,9, 9, 9, 9},
                                    {9, 9, 9, 9,9, 9, 9, 9}};
    

    //16x16
//    {{0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
//        {1, 2, 3, 4, 2, 3, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30},
//        {2, 3, 4, 5, 3, 4, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45},
//        {3, 4, 5, 6, 4, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},
//        {0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70,  75},
//        {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90},
//        {0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105},
//        {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120},
//        {0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135},
//        {0, 1, 2, 3, 4, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150},
//        {1, 2, 3, 4, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165},
//        {2, 3, 4, 5, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3},
//        {3, 4, 5, 6, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4},
//        { 0, 14, 28, 42, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5},
//        {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6}};
    
   
    //The block
    int x1, x2, y1, y2; //s2
    
    int sss = 0;
    int SAD;
    int minSAD = 500; //s0
    int c = 0, r = 0; //s3
    bool exit = false; //s4
    bool right = false; //s4
    bool down = false; //s4
    bool up = false; //s4
    bool left = false; //s4
    int Rmaxbound = FRAME_C + 1; //s1
    int Dmaxbound = FRAME_R + 1; //s1
    int Lminbound = -1; //s1
    int Uminbound = 0; //s1
    
    //to exit
    int countforexit = 0;
    int check[1000];
    int sumforexit = 0;
    int A, B, C, D;
    
    //initilizing block
    y1 = 0; y2 = WINDOW_R;
    x1 = 0; x2 = WINDOW_C;
    
    
    if(FRAME_C > WINDOW_C){ //Frame size = Window size
        right = true;
    }
    
    else if (FRAME_R > WINDOW_R){
        down = true;
    }
    
    while(exit == false){
    
    A = y1 * 1024;
    B = y2 * 128;
    C = x1 * 16;
    D = x2;
    
    check[countforexit] = 0;
    countforexit++;
    sumforexit = A + B + C + D;
        
    //reach the middle
    for (int i = 0; i < countforexit; i++) {
    
    if (check[i] == sumforexit){
        exit = true;
        break;
    }
    }//for
    
    check[countforexit - 1] = sumforexit;
        
    //calclating SAD
    SAD = 0;
    for(int i = y1; i < y2; i++){ //y
        for(int j = x1; j < x2; j++){ //x
            sss = abs(frame[i][j] - window[i-y1][j-x1]);
            SAD = SAD + sss;
        }
    }
        
        
    //Checking minSAD
    if(minSAD > SAD){
        minSAD = SAD;
        c = x1; //record c
        r = y1; //record r
    }
        
    
    //moving right
    if (right && !exit){
        if ((x2 + 1) == Rmaxbound){
            Rmaxbound--;
            right = false;
            down = true; //start down

        }
        else{
            x1++;
            x2++;
        }
    }
    
    //moving down
    if (down && !exit){
        if ((y2+1) == Dmaxbound){
            
            Dmaxbound--;
            down = false;
            left = true; //start left

        }
        else{
            y1++;
            y2++;
        }
    }

    //moving left
    if (left && !exit){
        if ((x1-1) == Lminbound){
            Lminbound++;
            
            left = false;
            up = true; //start up
         
        }
        else{
            x1--;
            x2--;
        }
    }

    //moving up
    if (up && !exit){
        if ((y1-1) == Uminbound){
            Uminbound++; //smaller bound
            
            up = false;
            right = true; //start right
            x1++;
            x2++;
        }
        else{
            y1--;
            y2--;
        }
    }
        
    
        
        
    }//while
    
    //return center block to print it
    if(right){x1--;x2--;}
    if(down){y1--;y2--;}
    if(left){x1++;x2++;}
    if(up){y1++;y2++;}
    
    //current x, y position
    printf("position of the box corners\n");
    printf("x = %d, %d y = %d, %d\n", x1, x2-1, y1, y2-1);

    printf("\n");

    //current block
    int count = 0;
    for(int i = y1; i < y2; i++){ //y
    for(int j = x1; j < x2; j++){ //x
        printf("%d ", frame[i][j]);
        ++count;
        if (count == WINDOW_C){
            printf("\n");
            count = 0;
        }
    }
    }
    
    printf("\n");
    
    //Cordinates
    printf("(r, c) = %d, %d\nThe minSAD = %d\n", r, c, minSAD);

    return 0;
}
