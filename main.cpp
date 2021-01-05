/*  Project Name   Get or Save the Boxes
    Last update     8-jan-18
    coded by        Paras Dhiman */
#include<graphics.h>
#include<mmsystem.h>
#include<stdio.h>

class single_player //  just basic functions defined
{
    public:
        int char1(int x1,int y1,int x2,int y2,int clr ,int hclr) // top char define
        {
            setcolor(clr);
            setfillstyle(1,clr);
            bar(580+x1,280+y1,700+x2,340+y2);
            setcolor(hclr);
            circle(640+x1,310+y1,25);
            bar(580+x1,340+y1,600+x2,380+y2); // left hand
            bar(680+x1,340+y1,700+x2,380+y2); // right hand
            return 0;
        } // end of char 1
        int char2(int x1,int y1,int x2,int y2,int clr ,int hclr) // right char define
        {
            setcolor(clr);
            setfillstyle(1,clr);
            bar(630+x1,270+y1,690+x2,390+y2);
            setcolor(hclr);
            circle(660+x1,330+y1,25);
            bar(590+x1,270+y1,630+x2,290+y2); // top hand
            bar(590+x1,370+y1,630+x2,390+y2); // bottom hand
            return 0;
        } // end of char 2
        int char3(int x1,int y1,int x2,int y2,int clr ,int hclr) // bottom char define
        {
            setcolor(clr);
            setfillstyle(1,clr);
            bar(580+x1,320+y1,700+x2,380+y2);
            setcolor(hclr);
            circle(640+x1,350+y1,25);
            bar(580+x1,320+y1,600+x2,280+y2); // left hand
            bar(680+x1,320+y1,700+x2,280+y2); // right hand
            return 0;
        }// end of char 3
        int char4(int x1,int y1,int x2,int y2,int clr ,int hclr) // left char define
        {
            setcolor(clr);
            setfillstyle(1,clr);
            bar(590+x1,270+y1,650+x2,390+y2);
            setcolor(hclr);
            circle(620+x1,330+y1,25);
            bar(650+x1,270+y1,690+x2,290+y2); // top hand
            bar(650+x1,370+y1,690+x2,390+y2); // bottom hand
            return 0;
        } // end of char 4
        // end of all characters
        int box(int x1,int y1,int x2,int y2) // single box defining
        {
            setfillstyle(1,11);
            bar(630+x1,145+y1,650+x2,165+y2);
            return 0;
        }
        int tutorial( int *f_t) // tutorial define for first time play
        {
            // int f_tc=1;
            FILE *reset;
            reset=fopen("media\\set.dat","w"); // read data from set.dat file to display tutorial for first time
            *f_t=1;
            //   fseek(reset,0,1);
            fprintf(reset,"%d",*f_t);
            fclose(reset);
            cleardevice();
            setfillstyle(9,13);
            setcolor(15);
            settextstyle(0,0,4);
            outtextxy(550,10,"TUTORIAL");
            settextstyle(0,0,2);
            setcolor(14);
            outtextxy(50,70,"SINGLE PLAYER");
            outtextxy(50,100,"if you win the toss then");
            outtextxy(50,160,"IF you lose the toss then");
            outtextxy(50,220,"if Player 1 win the toss then");
            outtextxy(50,250,"Player 1 moves and keys");
            outtextxy(50,300,"Player 2 moves and keys");
            outtextxy(50,420,"if Player 2 win the toss then");
            outtextxy(50,450,"Player 1 moves and keys");
            setcolor(15);
            outtextxy(50,130,"Press UP ,DOWN,RIGHT,LEFT key to move and 0 for reset the position");
            outtextxy(50,190,"Press UP,DOWN,RIGHT,LEFT key to move");
            outtextxy(50,280,"Press UP ,DOWN,RIGHT,LEFT key to move");
            outtextxy(50,330,"Press E or e for UP ,I or i for DOWN");
            outtextxy(50,360,"F or f for RIGHT,J or j for LEFT to move");
            outtextxy(50,390,"Press Space key to reset the Player 2's Position");
            outtextxy(50,480,"Press UP ,DOWN,RIGHT,LEFT key to move");
            outtextxy(50,510,"Press 0 key to reset the Player 1's Position");
            outtextxy(50,540,"Player 2 moves and keys");
            outtextxy(50,570,"Press E or e for UP ,I or i for DOWN");
            outtextxy(50,600,"F or f for RIGHT,J or j for LEFT to move");
            outtextxy(900,580,"Press any to Play");
            while(!kbhit())
            {}
            cleardevice();
            return 0;
        } //end of tutorial function
        int score(int u1,int u2, int toss, int sound_flag) // score function define
        {
            cleardevice();
            char u1_s[6],u2_s[6];
            setfillstyle(1,8);
            bar(0,0,1280,660);
            setcolor(2);
            settextstyle(0,0,4);
            outtextxy(540,25,"GAME OVER");
            if(sound_flag==10 || sound_flag==11)
                PlaySound(TEXT("media\\game_over.wav"),NULL,SND_SYNC);
            setcolor(0);
            rectangle(100,100,1180,560);
            rectangle(98,98,1182,562);
            line(328+748,200,328+748,460);
            line(640,200,640,460);
            line(642,200,642,460);
            rectangle(200,200,1078,460);
            rectangle(202,202,1078,458);
            line(202,250,1078,250);
            line(202,252,1078,252);
            setcolor(15);
            settextstyle(0,0,3);
            outtextxy(520,150,"SCORE CARD");
            sprintf(u1_s,"%d",u1);
            sprintf(u2_s,"%d",u2);
            outtextxy(370,330,u1_s);
            outtextxy(810,330,u2_s);
            settextstyle(0,0,2);
            settextstyle(0,0,3);
            if(toss==0) // if single player
            {
                outtextxy(230,215," Player's Score");
                outtextxy(660,215,"Computer's Score");
                if(u1==u2) // comparing the score u1 for player
                    outtextxy(605,475,"TIE");
                if(u1>u2)
                {
                    outtextxy(560,475,"You Win");
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\you win.wav"),NULL,SND_SYNC);
                }
                else
                {
                    outtextxy(555,475,"You Lose");
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\comp wins.wav"),NULL,SND_SYNC);
                }
            }
            if(toss==1) // if double players
            {
                outtextxy(220,215," Player 1's Score");
                outtextxy(670,215,"Player 2's Score");
                if(u1==u2) // comparing score u1 is player1 score and u2 is player 2 score
                    outtextxy(605,475,"TIE");
                if(u1>u2)
                {
                    outtextxy(500,475,"Player 1 WIn");
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\p1 win.wav"),NULL,SND_SYNC);
                }
                else
                {
                    outtextxy(500,475,"Player 2 WIn");
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\p2 win.wav"),NULL,SND_SYNC);
                }
            }
            return 0;
        } // end of score function
        pause(int *sound_flag,int *ret) // defining pause function
        {
            int sel_item = 1,  t=0,sel_key;
            int item_x=640,item_y=330;
            if(*sound_flag==10 || *sound_flag==11)
                PlaySound(TEXT("media\\pause.wav"),NULL,SND_SYNC);
            do
            {
                selection: // tag after select any option then control comes back to pause
                cleardevice();
                setcolor(15);
                setcolor(15);
                settextstyle(0,0,7);
                outtextxy(100,30,"___________________");
                outtextxy(40,20,"Get or Save The Boxes");
                rectangle(400,150,880,610);
                settextstyle(0,0,4);
                outtextxy(710,163,"_____");
                outtextxy(710,160,"PAUSE");
                rectangle(item_x-150,item_y-90,item_x+180,item_y-50);
                settextstyle( 0, 0, 3 );
                setcolor( 15 );
                outtextxy( 590, 250, "Resume" );
                outtextxy( 565, 300, "Sound ON" );
                outtextxy( 565, 350, "Sound OFF" );
                outtextxy( 610, 400, "Quit" );
                setcolor( RED );
                sel_key = getch();
                if(sel_key==72)
                {
                    if (item_y>350)
                    {
                        item_y-=50;
                        sel_item--;
                    }
                }
                if(sel_key==80)
                {
                    if (item_y<450)
                    {
                        item_y+=50;
                        sel_item++;
                    }
                }
                if(sel_key==27)
                    return *sound_flag;
                if(sel_key==13)
                {
                     sel_key = 1;
                }
            }
            while ( sel_key != 1 );
            switch(sel_item )
            {
                case 1:
                    return *sound_flag;
                    goto selection;
                break;
                case 2:
                    PlaySound(TEXT("media\\on.wav"),NULL,SND_SYNC);
                    *sound_flag=11;
                    goto selection;
                break;
                case 3:
                    *sound_flag=0;
                    goto selection;
                break;
                case 4:
                    *ret=1;
                    return 0;
                break;
                default: break;
            }
            while ( t == 0 );
            getch();
            cleardevice();
            return *sound_flag;
        } // end of pause function
        option(int *s, int *r) // option function define
        {
            int sel_item = 1, t = 0, a, p = 170,toss,ti,f_t=0;
            int sel_key;
            int item_x=640,item_y=330;
            FILE *reset_file, *reset;;
            {
                do
                {
                    selection:
                    cleardevice();
                    setcolor(15);
                    setcolor(15);
                    settextstyle(0,0,7);
                    outtextxy(100,30,"___________________");
                    outtextxy(40,20,"Get or Save The Boxes");
                    rectangle(400,150,880,610);
                    settextstyle(0,0,4);
                    outtextxy(650,163,"_______");
                    outtextxy(650,160,"OPTIONS");
                    rectangle(item_x-190,item_y-90,item_x+200,item_y-50);
                    settextstyle( 0, 0, 3 );
                    setcolor( 15 );
                    outtextxy( 550, 250, "Sound ON" );
                    outtextxy( 545, 300, "Sound OFF" );
                    outtextxy( 590, 350, "Reset" );
                    outtextxy( 520, 400, "Return Home" );
                    setcolor(RED);
                    sel_key = getch();
                    if(sel_key==72)
                    {
                        if (item_y>350)
                        {
                            item_y-=50;
                            sel_item--;
                        }
                    }
                    if(sel_key==80)
                    {
                        if (item_y<450)
                        {
                            item_y+=50;
                            sel_item++;
                        }
                    }
                    if(sel_key==13)
                    {
                        sel_key = 1;
                    }
                }
                while ( sel_key != 1 );
                switch(sel_item )
                {
                    case 1:
                        reset_file=fopen("media\\sr.dat","w+");
                        *s=1;
                        fseek(reset_file,0,0);
                        fprintf(reset_file,"%d%d",*s,*r); // writing  sound data to sr.dat file
                        fclose(reset_file);
                        cleardevice();
                        setcolor(15);
                        settextstyle(0,0,3);
                        outtextxy(640,330,"done");
                        PlaySound(TEXT("media\\on.wav"),NULL,SND_SYNC);
                        goto selection;
                    break;
                    case 2:
                        reset_file=fopen("media\\sr.dat","w+");
                        *s=0;
                        fseek(reset_file,0,1);
                        fprintf(reset_file,"%d%d",*s,*r); // writing sound data to sr.dat file
                        fclose(reset_file);
                        cleardevice();
                        setcolor(15);
                        settextstyle(0,0,3);
                        outtextxy(640,330,"done");
                        delay(500);
                        goto selection;
                    break;
                    case 3:
                        reset=fopen("media\\set.dat","w");
                        f_t=0;
                        //   fseek(reset,0,1);
                        fprintf(reset,"%d",f_t);
                        fclose(reset);
                        reset_file=fopen("media\\sr.dat","w");
                        *s=1;*r=0;
                        fprintf(reset_file,"%d%d",*s,*r);
                        fclose(reset_file);
                        cleardevice();
                        setcolor(15);
                        settextstyle(0,0,3);
                        outtextxy(640,330,"done");
                        delay(500);
                        goto selection;
                        //goto selection;
                    break;// option function
                    case 4:
                        goto end1;
                        //         goto selection; // about function
                    break;
                    default: break;
                }
            }
            while ( t == 0 );
            getch();
            end1:
            return *s;
            return *r;
        }  //end of option function
        int about() // about function defining
        {
            setcolor(15);
            setfillstyle(9,14);
            bar(0,0,1280,660);
            setfillstyle(1,0);
            bar(50,50,1230,610);
            rectangle(50,50,1230,610);
            setcolor(15);
            settextstyle(0,0,4);
            outtextxy(1060,15,"ABOUT");
            settextstyle(0,0,3);
            outtextxy(200,70,"Get or Save the boxes is a traditional");// also
            outtextxy(280,105,"sports game that is played in");//
            outtextxy(90,140,"Haryana's villages. In this game thereare 150");
            outtextxy(95,175,"boxes that're gotten as well as saved by the");//
            outtextxy(70,210,"Player form computer. If you won the toss then");
            outtextxy(70,245,"Player have to collect or get the box.Each box");
            outtextxy(100,280,"gives 10 points and if the computer touches");
            outtextxy(90,315,"Player then Player loose his power. If Player");
            outtextxy(85,350,"lose the toss then Player have to save the box");
            outtextxy(50,385,"from the computer,if computer gets the boxes then");
            outtextxy(120,420,"Player's score decreases by 10 points and if");
            outtextxy(90,455,"Player touches the computer then computer lose");
            outtextxy(10,490,"his life. If Player's Score is greater than computer");
            outtextxy(250,525,"then Player win else Player lose.");
            outtextxy(-1,600,"Press any key to return Home    Build by Paras Dhiman");
            return 0;
        } // end of about function
}; // end of single_player class
int user_save1280();
//int user_save1920(int );
int comp_save1280(int );
//int comp_save1920(int );
int p1_save( int *);
int p2_save1280( int *);
int s_player();
int d_player();
// starting function defining
int getbar()
{
    int b_x=rand()%640,b_y=rand()%300;
    int b_n=1;
    while(b_n!=15)
    {
        if(b_y>100 && b_y<<620)
        {
            delay(1);
            setfillstyle(b_n,b_n);
            bar(rand()%b_x,b_y,b_x+rand()%1200,b_y+rand()%250);
        }
    b_n++;
    }
}
int start()
{
    for(int i=0;i<20;i++)
    getbar();
    cleardevice();
    setfillstyle(10,1);
    bar(0,0,1280,660);
    delay(500);
    setcolor(7);
    settextstyle(0,0,3);
    setusercharsize(7, 1, 60, 1);
    outtextxy(60,50,"GET OR SAVE THE BOXES");
    settextstyle(0,0,3);
    outtextxy(80,450,"_______________________________________________");
    setcolor(8);
    outtextxy(400,480,"Build by Paras Dhiman");
    setfillstyle(10,1);
    bar(0,0,1280,150);
    bar(0,510,1280,660);
    delay(1500);
    return 0;
} // end of starting function
int exit_fun() // defining exit message function
{
    cleardevice();
    setfillstyle(10,1);
    bar(0,0,1280,660);
    setcolor(7);
    settextstyle(0,0,3);
    setusercharsize(7, 1, 60, 1);
    outtextxy(60,50,"GET OR SAVE THE BOXES");
    settextstyle(0,0,3);
    outtextxy(80,450,"_______________________________________________");
    setcolor(8);
    outtextxy(400,480,"Build by Paras Dhiman");
    setfillstyle(10,1);
    bar(0,0,1280,150);
    bar(0,500,1280,660);
    delay(1000);
    return 0;
} // end of exit message function
int home() // defining home function to display menu
{
    single_player sp;
    cleardevice();
    int sel_item = 1, t = 0, a, p = 170,toss,ti;
    int sel_key;
    int item_x=640,item_y=330;
    int sound_flag=0,resolution=0;
    FILE *reset_file;
    do
    {
        selection:
        cleardevice();
        setcolor(15);
        settextstyle(0,0,7);
        outtextxy(100,30,"___________________");
        outtextxy(40,20,"Get or Save The Boxes");
        rectangle(400,150,880,610);
        settextstyle(0,0,4);
        outtextxy(730,163,"____");
        outtextxy(730,160,"HOME");
        rectangle(item_x-170,item_y-90,item_x+180,item_y-50);
        settextstyle( 0, 0, 3 );
        setcolor( 15 );
        outtextxy( 490, 250, "Single Player" );
        outtextxy( 490, 300, "Double Player" );
        outtextxy( 570, 350, "Options" );
        outtextxy(590, 400, "About" );
        outtextxy( 600, 450, "Exit" );
        setcolor( RED );
        sel_key = getch();
        if(sel_key==72)
        {
            if ( item_y > 350 )
            {
                item_y-=50;
                sel_item--;
            }
        }
        if(sel_key==80)
        {
            if (item_y<500)
            {
                item_y+=50;
                sel_item++;
            }
        }
        if(sel_key==13)
        {
             sel_key = 1;
        }
    }
    while ( sel_key != 1 );
    if (sel_item==1 )
    {
    s_player(); // call single player function
    goto selection;
    }  // exit(0);
    if(sel_item==2)
    {
        d_player(); // call double function
        goto selection;
    }
    if(sel_item==3)
    {
        sp.option(&sound_flag,&resolution);
        reset_file=fopen("media\\sr.dat","r");
        fseek(reset_file,0,0);
        fscanf(reset_file,"%d",&sound_flag);
        fseek(reset_file,1,0);
        fscanf(reset_file,"%d",&resolution);
       goto selection;
    }
    if(sel_item==4)
    {
       sp.about(); // about function
        while(!kbhit())
        {
        }
    goto selection;
    }
    if(sel_item==5)
        exit_fun();
    exit (0);
    while ( t == 0 );
    getch();
    return 0;
} // end of home function
main()
{
    initwindow(1279,660," ",0,0,false,true);
    start();
    cleardevice();
    home();
    return 0;
}
/////////////////////////// defining user playing functions
user_save1280() // define user save function when user lose the toss
{
    single_player sp;
    int sound_flag=0;
    FILE *reset,*reset_file;
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag); // read sound data from the sr.dat
    fclose(reset_file);
    int ret=0; // used to  quit the game and return to the home function
    int f_time=0; // used to display the first time tutorial
    int user1_sx1=0,user1_ex1=0,user1_sy1=0,user1_ey1=0,user1_clr1=2,user1_clr2=0,user1_hclr=15;
    int user1_score=1500,user1_life=1000;
    char user1_s[6],user1_l[5];
    int user1_key;
    int ringx=0,ringy=0,ringr=0;
    int box_sx1=0,box_ex1=0,box_sy1=0,box_ey1=0;
    int box_no=150;
    char box_n[4];
    // defining computer variables
    int user2_sx1=0,user2_ex1=0,user2_sy1=-300,user2_ey1=-300;
    int user2_sx2=310,user2_ex2=310,user2_sy2=0,user2_ey2=0;
    int user2_sx3=0,user2_ex3=0,user2_sy3=320,user2_ey3=320;
    int user2_sx4=-290,user2_ex4=-290,user2_sy4=0,user2_ey4=0;
    int user2_clr1=14,user2_clr2=0,user2_hclr=0;
    int user2_score=0,user2_life=1000;
    char user2_s[6],user2_l[5];
    int text_x=0,text_y=0; // used for text position

    reset=fopen("media\\set.dat","r");
   //  fseek(reset,0,0);
    fscanf(reset,"%d",&f_time); // read tutorial data for first time
    fclose(reset);
    if(f_time==0 )
    {
        sp.tutorial(&f_time);
    }
    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr); // display user1 char before entering to the loop
    while(box_no!=0)
    {
        delay(1);
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,15,"Press ESC to Pause");
        // show computer score
        setfillstyle(1,0);
        bar(1052,50,1250,600); // to clear previous score, box no ,etc
        setcolor(15);
        line(1050,50,1050,609);
        setcolor(user2_clr1);
        settextstyle(0,0,2);
        outtextxy(1100+text_x,50+text_y,"COMPUTER");
        outtextxy(1120+text_x,70+text_y,"SCORE");
        sprintf(user2_s,"%d",user2_score);
        outtextxy(1100+text_x,120+text_y,user2_s); // print computer score
        outtextxy(1170+text_x,120+text_y,"/1500");
        outtextxy(1100+text_x,200+text_y,"________");
        outtextxy(1140+text_x,250+text_y,"Life");
        sprintf(user2_l,"%d",user2_life);
        outtextxy(1140+text_x,270+text_y,user2_l);
        setfillstyle(1,user2_clr1);
        bar(1110,300,1210,310);
        setfillstyle(1,user2_clr2);
        bar(1109,300,1109+(1000-user2_life)/10,310);
        setcolor(15);
        rectangle(1108,298,1211,311);
        outtextxy(1100+text_x,320+text_y,"________");
        outtextxy(1140+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(1120+text_x,420+text_y,box_n);
        outtextxy(1170+text_x,420+text_y,"/150");
        // end of computer score
        // show user score
        setfillstyle(1,0);
        bar(0,50,218,610); // to clear previous score, box no ,etc
        setcolor(15);
        line(220,50,220,610);
        setcolor(user1_clr1);
        outtextxy(50+text_x,50+text_y,"USER");
        outtextxy(50+text_x,70+text_y,"SCORE");
        sprintf(user1_s,"%d",user1_score);
        outtextxy(50+text_x,120+text_y,user1_s); // print computer score
        outtextxy(120+text_x,120+text_y,"/1500");
        settextstyle(0,0,2); // life printing process
        outtextxy(50+text_x,200+text_y,"________");
        outtextxy(50+text_x,250+text_y,"Life");
        sprintf(user1_l,"%d",user1_life);
        outtextxy(50+text_x,270+text_y,user1_l);
        setfillstyle(1,user1_clr1);
        bar(50,300,150,310);
        setfillstyle(1,user1_clr2);
        bar(150-(150-box_no)*10/15,300,151,310);
        setcolor(15);
        rectangle(48,298,151,311);
        outtextxy(50+text_x,320+text_y,"________");
        outtextxy(50+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(50+text_x,420+text_y,box_n);
        outtextxy(100+text_x,420+text_y,"/150");
        // end of user score
        // defining ring
        setcolor(15);
        circle(640+ringx,330+ringy,200+ringr);
        circle(640+ringx,330+ringy,202+ringr);
        // end of the ring
        //call  box function
        sp.box(box_sx1,box_sy1,box_ex1,box_ey1); // box 1
        sp.box(box_sx1+175,box_sy1+175,box_ex1+175,box_ey1+175); // box 2
        sp.box(box_sx1,box_sy1+350,box_ex1,box_ey1+350); // box 3
        sp.box(box_sx1-175,box_sy1+175,box_ex1-175,box_ey1+175); // box 2
        // end of box function
        // defining computer behavior
        // first computer
        if(user2_ey1>-220) // computer1 gets 1st box
        {
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_ey1=-300;
            user2_sy1=-300;
            box_no--;
            user2_score+=10;
            user1_score-=10;
        }
        if(user1_sy1<=user2_sy1+150) // user1 comes  to the computer 1
        {
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_ey1=-300;
            user2_sy1=-300;
        } // end of user1 comes to the computer 1
        sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
        user2_sy1++;
        user2_ey1++;
        sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
        //end of first computer
        // 2nd computer
        if(user2_sx2<220)
        {
            sp.char2(user2_sx2,user2_sy2,user2_ex2,user2_ey2,user2_clr2,user2_clr2);
            user2_ex2=300;
            user2_sx2=300;
            box_no--;
            user2_score+=10;
            user1_score-=10;
        }
        if(user1_sx1>=user2_sx2-150) // user 2 comes  to the computer 2
        {
            sp.char2(user2_sx2,user2_sy2,user2_ex2,user2_ey2,user2_clr2,user2_clr2);
            user2_ex2=300;
            user2_sx2=300;
        } // end of user 2 comes to the computer 2
        sp.char2(user2_sx2,user2_sy2,user2_ex2,user2_ey2,user2_clr2,user2_clr2);
        user2_sx2--;
        user2_ex2--;
        sp.char2(user2_sx2,user2_sy2,user2_ex2,user2_ey2,user2_clr1,user2_hclr);
        //2nd of first computer
        // 3rd computer
        if(user2_sy3<220)
        {
            sp.char3(user2_sx3,user2_sy3,user2_ex3,user2_ey3,user2_clr2,user2_clr2);
            user2_ey3=300;
            user2_sy3=300;
            box_no--;
            user2_score+=10;
            user1_score-=10;
        }
        if(user1_sy1>=user2_sy3-150) // user 3 comes  to the computer 3
        {
            sp.char3(user2_sx3,user2_sy3,user2_ex3,user2_ey3,user2_clr2,user2_clr2);
            user2_ey3=300;
            user2_sy3=300;
        } // end of user 3 comes to the computer 3
        sp.char3(user2_sx3,user2_sy3,user2_ex3,user2_ey3,user2_clr2,user2_clr2);
        user2_sy3--;
        user2_ey3--;
        sp.char3(user2_sx3,user2_sy3,user2_ex3,user2_ey3,user2_clr1,user2_hclr);
        //end of 3rd computer
        //4nd computer
        if(user2_sx4>-220)
        {
            sp.char4(user2_sx4,user2_sy4,user2_ex4,user2_ey4,user2_clr2,user2_clr2);
            user2_ex4=-300;
            user2_sx4=-300;
            box_no--;
            user2_score+=10;
            user1_score-=10;
        }
        if(user1_sx1<=user2_sx4+150) // user 2 comes  to the computer 2
        {
            sp.char4(user2_sx4,user2_sy4,user2_ex4,user2_ey4,user2_clr2,user2_clr2);
            user2_ex4=-300;
            user2_sx4=-300;
        } // end of user 2 comes to the computer 2
        sp.char4(user2_sx4,user2_sy4,user2_ex4,user2_ey4,user2_clr2,user2_clr2);
        user2_sx4++;
        user2_ex4++;
        sp.char4(user2_sx4,user2_sy4,user2_ex4,user2_ey4,user2_clr1,user2_hclr);
        //4nd of first computer
        // end of computer behavior
        if(kbhit())
        {
            user1_key=getch();
            if(user1_key==27) // for exit to the program
            {
                sp.pause(&sound_flag,&ret);
                delay(100);
                cleardevice();
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if( ret==1)
                {
                    cleardevice();
                    home();
                }
            }
            // condition for  move down
            if(user1_key==80)
            {
                if(user1_sy1>100)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    user1_sy1-=150; // stop moving down
                    user1_ey1-=150; // stop moving down
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                user1_sy1+=150; // move down
                user1_ey1+=150; // move down
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ey1>=user2_sy3-100)
                {
                    user2_life-=20;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                }
            } // end of down condition
            // move up side
            if(user1_key==72)
            {
                if(user1_sy1<0)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    user1_sy1+=150; // stop moving upside
                    user1_ey1+=150; // stop moving upside
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                user1_sy1-=150;
                user1_ey1-=150;
                sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ey1<=user2_sy1+100)
                {
                    user2_life-=20;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                }
            } // end of up  condition
            // move right side
            if(user1_key==75)
            {
                if(user1_sx1<0)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    user1_sx1+=150;
                    user1_ex1+=150;
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                user1_sx1-=150;
                user1_ex1-=150;
                sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ex1<=user2_sx4+100)
                {
                    user2_life-=20;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                }
            } // end of up  condition
            // condition for right side movement
            if(user1_key==77)
            {
                if(user1_sx1>0)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                    user1_sx1-=150; // stop moving
                    user1_ex1-=150; // stop moving
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                sp.char2(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char3(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2);
                user1_sx1+=150; // move right
                user1_ex1+=150; // move right
                sp.char4(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ex1>=user2_sx2-100)
                {
                    user2_life-=20;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                }
            } // end of up  condition
        } // end of if statement
        if(box_no==120)
        {
            user1_life=800; // computer life
        }
        if(box_no==90) // computer life
        {
            user1_life=600;
        }
        if(box_no==60)
        {
            user1_life=400;
        }
        if(box_no==30)
        {
            user1_life=200;
        }
        if(box_no<=0)
        {
            user1_life=0;
        }
        if(user1_life<=0 || user2_life<=0)
        {
            //delay(1000);
            cleardevice();
            sp.score(user1_score,user2_score,0,sound_flag);
            delay(5000);
            cleardevice();
            return 0;
        }
    } // end of while loop
    return 0;
} // end of user save 1280
comp_save1280(int sound_flag)
{
    single_player sp; // creating object for single_player class
    FILE *reset,*reset_file;
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag);
    fclose(reset_file);
    int ret=0;
    int f_time=1;
    // defining user variables in single toss as well as double toss for user 1
    int user1_sx1=0,user1_ex1=0,user1_sy1=-300,user1_ey1=-300; // user axis for first character
    int user1_sx2=300,user1_ex2=300,user1_sy2=-0,user1_ey2=0; // user axis for first character
    int user1_sx3=0,user1_ex3=0,user1_sy3=300,user1_ey3=300; // user axis for first character
    int user1_sx4=-300,user1_ex4=-300,user1_sy4=0,user1_ey4=0; // user axis for first character
    int user1_clr1=2,user1_clr2=0,user1_hclr=15; // user colors
    int user1_score=0; // user score and life
    int user1_life=1000;
    char user1_s[6],user1_l[4]; // using display the score as well as life of the user 1
    int user1_key; // selection key for user 1
    // end of user 1 variables
    // defining computer variables as well as user 2 variables
    int user2_sx1=0,user2_ex1=0,user2_sy1=0,user2_ey1=0; // axis of computer 2 and user 2
    int user2_sx2=0,user2_ex2=0,user2_sy2=0,user2_ey2=0;
    int user2_sx3=0,user2_ex3=0,user2_sy3=0,user2_ey3=0;
    int user2_sx4=-0,user2_ex4=-0,user2_sy4=0,user2_ey4=0;
    int user2_clr1=14,user2_clr2=0,user2_hclr=0; // computer 2 and user 2 colors
    int user2_score=1500 ,user2_life=1000; // computer score and life of computer user 2 score
    char user2_s[6],user2_l[4]; // to display score ans life
    // end of computer variables
    int ringx=0,ringy=0,ringr=0; // variables for ring
    int box_sx1=0,box_ex1=0,box_sy1=0,box_ey1=0; // box variables as size
    int box_no=150; // box number
    char box_n[5]; //for  display the number of boxes
    int text_x=0,text_y=0; //for text position in screen resolution
    int comp_m=0; // computer moves randomly
    reset=fopen("media\\set.dat","r");
    fseek(reset,0,0);
    fscanf(reset,"%d",&f_time);
    fclose(reset);
    if(f_time==0 )
    {sp.tutorial(&f_time);}
    // to show all user characters before entering to the loop
    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
    comp_m=rand()%5;
    while(box_no!=0)
    {
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,15,"Press ESC to Pause");
        // show computer score
        setfillstyle(1,0);
        bar(1052,50,1250,600); // to clear previous score, box no ,etc
        setcolor(15);
        line(1050,50,1050,609);
        setcolor(user2_clr1);
        settextstyle(0,0,2);
        outtextxy(1100+text_x,50+text_y,"COMPUTER");
        outtextxy(1120+text_x,70+text_y,"SCORE");
        sprintf(user2_s,"%d",user2_score);
        outtextxy(1100+text_x,120+text_y,user2_s); // print computer score
        outtextxy(1170+text_x,120+text_y,"/1500");
        outtextxy(1100+text_x,200+text_y,"________");
        outtextxy(1140+text_x,250+text_y,"Life");
        sprintf(user2_l,"%d",user2_life);
        outtextxy(1140+text_x,270+text_y,user2_l);
        setfillstyle(1,user2_clr1);
        bar(1110,300,1210,310);
        setfillstyle(1,user2_clr2);
        bar(1109,300,1109-(box_no-150)*10/15,310);
        setcolor(15);
        rectangle(1108,298,1211,311);
        outtextxy(1100+text_x,320+text_y,"________");
        outtextxy(1140+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(1120+text_x,420+text_y,box_n);
        outtextxy(1170+text_x,420+text_y,"/150");
        // end of computer score
        // show user score
        setfillstyle(1,0);
        bar(0,50,218,610); // to clear previous score, box no ,etc
        setcolor(15);
        line(220,50,220,610);
        setcolor(user1_clr1);
        outtextxy(50+text_x,50+text_y,"USER");
        outtextxy(50+text_x,70+text_y,"SCORE");
        sprintf(user1_s,"%d",user1_score);
        outtextxy(50+text_x,120+text_y,user1_s); // print computer score
        outtextxy(120+text_x,120+text_y,"/1500");
        settextstyle(0,0,2); // life printing process
        outtextxy(50+text_x,200+text_y,"________");
        outtextxy(50+text_x,250+text_y,"Life");
        sprintf(user1_l,"%d",user1_life);
        outtextxy(50+text_x,270+text_y,user1_l);
        setfillstyle(1,user1_clr1);
        bar(50,300,150,310);
        setfillstyle(1,user1_clr2);
        bar(150-(1000-user1_life)/10,300,151,310);
        setcolor(15);
        rectangle(48,298,151,311);
        outtextxy(50+text_x,320+text_y,"________");
        outtextxy(50+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(50+text_x,420+text_y,box_n);
        outtextxy(100+text_x,420+text_y,"/150");
        // end of user score
        // display the ring
        setcolor(15);
        circle(640+ringx,330+ringy,200+ringr);
        circle(640+ringx,330+ringy,202+ringr);
        // end of the ring
        //call  box function
        sp.box(box_sx1,box_sy1,box_ex1,box_ey1); // box 1
        sp.box(box_sx1+175,box_sy1+175,box_ex1+175,box_ey1+175); // box 2
        sp.box(box_sx1,box_sy1+350,box_ex1,box_ey1+350); // box 3
        sp.box(box_sx1-175,box_sy1+175,box_ex1-175,box_ey1+175); // box 2
        // end of box function
        // first computer
        if(comp_m==1)
        {
            if(user2_ey1>150) // computer1 boundary
            {
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_ey1=0;
                user2_sy1=0;
                comp_m=rand()%4;
            }
            if(user1_sy3<=user2_sy1+100) // computer 1 touches the user 3
            {
                user1_life-=10;
                if(sound_flag==10 || sound_flag==11)
                PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user1 comes to the computer 1
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sy1++;
            user2_ey1++;
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
        }//end of first computer
        // 2nd computer
        if(comp_m==2)
        {
            if(user2_sx1<-150)
            {
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sx1=0;
                user2_ex1=0;
                comp_m=rand()%4;
            }
            if(user1_sx4>=user2_sx1-100) // user 2 comes  to the computer 2
            {
                user1_life-=10;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 2 comes to the computer 2
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sx1--;
            user2_ex1--;
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
        }//2nd of first computer
        // 3rd computer
        if(comp_m==3)
        {
            if(user2_sy1<-150)
            {
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sy1=0;
                user2_ey1=0;
                comp_m=rand()%4;
            }
            if(user1_sy1>=user2_sy1-100) // user 3 comes  to the computer 3
            {
                user1_life-=10;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 3 comes to the computer 3
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sy1--;
            user2_ey1--;
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
        } //end of 3rd computer
        //4nd computer
        if(comp_m==0)
        {
            if(user2_sx1>150)
            {
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sx1=0;
                user2_ex1=0;
                comp_m=rand()%4;
            }
            if(user1_sx2<=user2_sx1+100) // user 2 comes  to the computer 4
            {
                user1_life-=10;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 2 comes to the computer 4
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sx1++;
            user2_ex1++;
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
        //4nd of first computer
        } // end of computer behavior
        if(kbhit())
        {
            user1_key=getch();
            if(user1_key==27)// for exit to the program
            {
                sp.pause(&sound_flag,&ret);
                delay(100);
                cleardevice();
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
                if( ret==1)
                {
                    cleardevice();
                    home();
                }
            }
            // condition for  move down
            if(user1_key==48)
            {
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1=-300;
                user1_ey1=-300;
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr); // to clear all rest chars
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3=300;
                user1_ey3=300;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2=300;
                user1_ex2=300;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4=-300;
                user1_ex4=-300;
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
            }
            if(user1_key==80)
            {
                if(user1_sy1>-200)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    user1_sy1-=50; // stop moving down
                    user1_ey1-=50; // stop moving down
                    box_no--;
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1+=50; // move down
                user1_ey1+=50; // move down
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ey1>=box_sx1-200) // user get the box
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of down condition
            // move up side
            if(user1_key==72)
            {
                if(user1_sy3<200)
                {
                    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                    user1_sy3+=50; // stop moving upside
                    user1_ey3+=50; // stop moving upside
                }// moving conditions
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3-=50;
                user1_ey3-=50;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                if(user1_ey3<=box_sy1+200) // user gets the box
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of up  condition
            // move left side
            if(user1_key==75)
            {
                if(user1_sx2<200)
                {
                    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                    user1_sx2+=50;
                    user1_ex2+=50;
                }// moving conditions
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2-=50;
                user1_ex2-=50;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                if(user1_ex2<=box_sx1+200) // user gets the box
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            }// end of up  condition
            // condition for right side movement
            if(user1_key==77)
            {
                if(user1_sx4>-200)
                {
                    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                    user1_sx4-=50; // stop moving
                    user1_ex4-=50; // stop moving
                }// moving conditions
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4+=50; // move right
                user1_ex4+=50; // move right
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
                if(user1_ex4>=box_sx1-200) // user gets the box
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of up  condition
        } // end of if statement
        if(box_no==120)
        {
            user2_life=800; // computer life
        }
        if(box_no==90) // computer life
        {
            user2_life=600;
        }
        if(box_no==60)
        {
            user2_life=400;
        }
        if(box_no==30)
        {
            user2_life=200;
        }
        if(box_no<=0)
        {
            user2_life=0;
        }
        if(user1_life<=0 || user2_life<=0)
        {
            cleardevice();
            sp.score(user1_score,user2_score,0,sound_flag);
            delay(5000);
            cleardevice();
            return 0;
        }
    } // end of while loop
    return 0;
} // end of computer save 1280
p1_save1280()
{
    single_player sp; // creating object for single_player class
    int sound_flag;
    FILE *reset,*reset_file;
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag);
    fclose(reset_file);
    int f_time=1;
    int ret=0;
    // defining user variables in single toss as well as double toss for user 1
    int user1_sx1=0,user1_ex1=0,user1_sy1=-300,user1_ey1=-300; // user axis for first character
    int user1_sx2=300,user1_ex2=300,user1_sy2=-0,user1_ey2=0; // user axis for first character
    int user1_sx3=0,user1_ex3=0,user1_sy3=300,user1_ey3=300; // user axis for first character
    int user1_sx4=-300,user1_ex4=-300,user1_sy4=0,user1_ey4=0; // user axis for first character
    int user1_clr1=2,user1_clr2=0,user1_hclr=15; // user colors
    int user1_score=1500; // user score and life
    int user1_life=1000;
    char user1_s[6],user1_l[4]; // using display the score as well as life of the user 1
    int user1_key; // selection key for user 1
    // end of user 1 variables
    // defining computer variables as well as user 2 variables
    int user2_sx1=0,user2_ex1=0,user2_sy1=0,user2_ey1=0; // axis of computer 2 and user 2
    int user2_sx2=0,user2_ex2=0,user2_sy2=0,user2_ey2=0;
    int user2_sx3=0,user2_ex3=0,user2_sy3=0,user2_ey3=0;
    int user2_sx4=-0,user2_ex4=-0,user2_sy4=0,user2_ey4=0;
    int user2_clr1=14,user2_clr2=0,user2_hclr=0; // computer 2 and user 2 colors
    int user2_score=0 ,user2_life=1000; // computer score and life of computer user 2 score
    char user2_s[6],user2_l[4]; // to display score ans life
    int        user2_key;
    // end of computer variables
    int ringx=0,ringy=0,ringr=0; // variables for ring
    int box_sx1=0,box_ex1=0,box_sy1=0,box_ey1=0; // box variables as size
    int box_no=150; // box number
    char box_n[5]; //for  display the number of boxes
    int g_x;
    int text_x=0,text_y=0; //for text position in screen resolution
    //        int sound_flag=0; // for on and of the sound
    int comp_m=0; // computer moves randomly
    user1_clr1+=user2_clr1;
    user2_clr1=user1_clr1-user2_clr1;
    user1_clr1-=user2_clr1;
    user1_hclr+=user2_hclr;
    user2_hclr=user1_hclr-user2_hclr;
    user1_hclr-=user2_hclr;
    reset=fopen("media\\set.dat","r");
   //  fseek(reset,0,0);
    fscanf(reset,"%d",&f_time);
    fclose(reset);
    // to show all user characters before entering to the loop
    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr); // player 1
    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
    comp_m=rand()%5;
    while(box_no!=0)
    {
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,15,"Press ESC to Pause");
        // show computer score
        setfillstyle(1,0);
        bar(1052,50,1250,600); // to clear previous score, box no ,etc
        setcolor(15);
        line(1050,50,1050,609);
        setcolor(user1_clr1);
        settextstyle(0,0,2);
        outtextxy(1100+text_x,50+text_y,"Player 2");
        outtextxy(1120+text_x,70+text_y,"SCORE");
        sprintf(user2_s,"%d",user2_score);
        outtextxy(1100+text_x,120+text_y,user2_s); // print computer score
        outtextxy(1170+text_x,120+text_y,"/1500");
        outtextxy(1100+text_x,200+text_y,"________");
        outtextxy(1140+text_x,250+text_y,"Life");
        sprintf(user1_l,"%d",user1_life);
        outtextxy(1140+text_x,270+text_y,user1_l);
        setfillstyle(1,user1_clr1);
        bar(1110,300,1210,310);
        setfillstyle(1,user1_clr2);
        bar(1109,300,1109+(1000-user1_life)/10,310);
        setcolor(15);
        rectangle(1108,298,1211,311);
        setcolor(user1_clr1);
        outtextxy(1100+text_x,320+text_y,"________");
        outtextxy(1140+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(1120+text_x,420+text_y,box_n);
        outtextxy(1170+text_x,420+text_y,"/150");
        // end of computer score
        // show user score
        setfillstyle(1,0);
        bar(0,50,218,610); // to clear previous score, box no ,etc
        setcolor(15);
        line(220,50,220,610);
        setcolor(user2_clr1);
        outtextxy(50+text_x,50+text_y,"Player 1");
        outtextxy(50+text_x,70+text_y,"SCORE");
        sprintf(user1_s,"%d",user1_score);
        outtextxy(50+text_x,120+text_y,user1_s); // print computer score
        outtextxy(120+text_x,120+text_y,"/1500");
        settextstyle(0,0,2); // life printing process
        outtextxy(50+text_x,200+text_y,"________");
        outtextxy(50+text_x,250+text_y,"Life");
        sprintf(user2_l,"%d",user2_life);
        outtextxy(50+text_x,270+text_y,user2_l);
        setfillstyle(1,user2_clr1);
        bar(50,300,150,310);
        setfillstyle(1,user2_clr2);
        bar(150-(150-box_no)*10/15,300,151,310);
        setcolor(15);
        rectangle(48,298,151,311);
        setcolor(user2_clr1);
        outtextxy(50+text_x,320+text_y,"________");
        outtextxy(50+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(50+text_x,420+text_y,box_n);
        outtextxy(100+text_x,420+text_y,"/150");
        // end of user score
        // display the ring
        setcolor(15);
        circle(640+ringx,330+ringy,200+ringr);
        circle(640+ringx,330+ringy,202+ringr);
        // end of the ring
        //call  box function
        sp.box(box_sx1,box_sy1,box_ex1,box_ey1); // box 1
        sp.box(box_sx1+175,box_sy1+175,box_ex1+175,box_ey1+175); // box 2
        sp.box(box_sx1,box_sy1+350,box_ex1,box_ey1+350); // box 3
        sp.box(box_sx1-175,box_sy1+175,box_ex1-175,box_ey1+175); // box 2
        // end of box function
        // call tutorial function
        if(f_time==0 )
        {sp.tutorial(&f_time);}
        sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
        sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
        sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
        sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
        if(kbhit())
        {
            user1_key=getch();
            if(user1_key==27) // for exit to the program
            {
                sp.pause(&sound_flag,&ret);
                delay(100);
                cleardevice();
                if(ret==1)
                {
                    cleardevice();
                    home();
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr); // player 1
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
            }
            // condition for  move down
            if(user1_key==32)
            {
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1=-300;
                user1_ey1=-300;
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr); // to clear all rest chars
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3=300;
                user1_ey3=300;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2=300;
                user1_ex2=300;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4=-300;
                user1_ex4=-300;
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
            }
            if(user1_key==105 || user1_key==73)
            {
                if(user1_sy1>-200)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    user1_sy1-=50; // stop moving down
                    user1_ey1-=50; // stop moving down
                    box_no--;
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1+=50; // move down
                user1_ey1+=50; // move down
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ey1>=box_sx1-200) // user catch the computer 3
                {
                    user2_score+=10;
                    user1_score-=10;
                    box_no--;
                }
            } // end of down condition
            // move up side
            if(user1_key==69 || user1_key==101)
            {
                if(user1_sy3<200)
                {
                    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                    user1_sy3+=50; // stop moving upside
                    user1_ey3+=50; // stop moving upside
                }// moving conditions
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3-=50;
                user1_ey3-=50;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                if(user1_ey3<=box_sy1+200) // user catch the computer 1
                {
                    user2_score+=10;
                    user1_score-=10;
                    box_no--;
                }
            } // end of up  condition
            // move left side
            if(user1_key==74 || user1_key==106)
            {
                if(user1_sx2<200)
                {
                    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                    user1_sx2+=50;
                    user1_ex2+=50;
                }// moving conditions
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2-=50;
                user1_ex2-=50;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                if(user1_ex2<=box_sx1+200) // user catch the computer 4
                {
                    user2_score+=10;
                    user1_score-=10;
                    box_no--;
                }
            }// end of up  condition
            // condition for right side movement
            if(user1_key==70 || user1_key==102)
            {
                if(user1_sx4>-200)
                {
                    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                    user1_sx4-=50; // stop moving
                    user1_ex4-=50; // stop moving
                }// moving conditions
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4+=50; // move right
                user1_ex4+=50; // move right
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
                if(user1_ex4>=box_sx1-200) // user catch the computer 3
                {
                    user2_score+=10;
                    user1_score-=10;
                    box_no--;
                }
            } // end of up  condition
            if(user1_key==75)
            {
                if(user2_sx1<-50)
                {
                    if(user2_sy1<-150)
                    {
                        sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        user2_sy1-=150;
                        user2_ey1-=150;
                        //comp_m=rand()%4;
                    }
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sx1+=150;
                    user2_ex1+=150;
                    comp_m=rand()%4;
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sx1-=150;
                user2_ex1-=150;
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
                if(user1_sx4>=user2_sx1-100) // user 2 comes  to the computer 2
                {
                    user1_life-=5;
                    if(sound_flag==10 || sound_flag==11 )
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                } // end of user 2 comes to the computer 2
            }
            if(user1_key==77)
            {
                if(user2_sx1>50)
                {
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sx1-=150;
                    user2_ex1-=150;
                    //comp_m=rand()%4;
                }
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sx1+=150;
            user2_ex1+=150;
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
            if(user1_sx2<=user2_sx1+100) // user 2 comes  to the computer 2
            {
                user1_life-=5;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 2 comes to the computer 2
        }
        if(user1_key==72)
        {
            if(user2_sy1<-50)
            {
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sy1+=150;
                user2_ey1+=150;
            }
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sy1-=150;
            user2_ey1-=150;
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
            if(user1_sy1>=user2_sy1-100) // user 3 comes  to the computer 3
            {
                user1_life-=5;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 3 comes to the computer 3
        }
        if(user1_key==80)
        {
            if(user2_sy1>50)
            {
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sy1-=150;
                user2_ey1-=150;
            }
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
            user2_sy1+=150;
            user2_ey1+=150;
            sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
            if(user1_sy3<=user2_sy1+100) // user 3 comes  to the computer 3
            {
                user1_life-=5;
                if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
            } // end of user 3 comes to the computer 3
        }
        } // end of if statement
        if(box_no==120)
        {
            user2_life=800; // computer life
        }
        if(box_no==90) // computer life
        {
            user2_life=600;
        }
        if(box_no==60)
        {
            user2_life=400;
        }
        if(box_no==30)
        {
            user2_life=200;
        }
        if(box_no==0)
        {
            user2_life=0;
        }
        if(user1_life<=0 || user2_life<=0)
        {
            cleardevice();
            sp.score(user1_score,user2_score,1,sound_flag);
            delay(5000);
            cleardevice();
            return 0;
        }
    } // end of while loop
    return 0;
} // end of p1save function
p2_save1280()
{
    single_player sp;
    int sound_flag; // creating object for single_player class
    FILE *reset,*reset_file;
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag);
    fclose(reset_file);
    int f_time=1;
    int ret=0;
    // defining user variables in single toss as well as double toss for user 1
    int user1_sx1=0,user1_ex1=0,user1_sy1=-300,user1_ey1=-300; // user axis for first character
    int user1_sx2=300,user1_ex2=300,user1_sy2=-0,user1_ey2=0; // user axis for first character
    int user1_sx3=0,user1_ex3=0,user1_sy3=300,user1_ey3=300; // user axis for first character
    int user1_sx4=-300,user1_ex4=-300,user1_sy4=0,user1_ey4=0; // user axis for first character
    int user1_clr1=2,user1_clr2=0,user1_hclr=15; // user colors
    int user1_score=0; // user score and life
    int user1_life=1000;
    char user1_s[6],user1_l[4]; // using display the score as well as life of the user 1
    int user1_key; // selection key for user 1
    // end of user 1 variables
    // defining computer variables as well as user 2 variables
    int user2_sx1=0,user2_ex1=0,user2_sy1=0,user2_ey1=0; // axis of computer 2 and user 2
    int user2_sx2=0,user2_ex2=0,user2_sy2=0,user2_ey2=0;
    int user2_sx3=0,user2_ex3=0,user2_sy3=0,user2_ey3=0;
    int user2_sx4=-0,user2_ex4=-0,user2_sy4=0,user2_ey4=0;
    int user2_clr1=14,user2_clr2=0,user2_hclr=0; // computer 2 and user 2 colors
    int user2_score=1500 ,user2_life=1000; // computer score and life of computer user 2 score
    char user2_s[6],user2_l[4]; // to display score ans life
    int        user2_key;
    // end of computer variables
    int ringx=0,ringy=0,ringr=0; // variables for ring
    int box_sx1=0,box_ex1=0,box_sy1=0,box_ey1=0; // box variables as size
    int box_no=150; // box number
    char box_n[5]; //for  display the number of boxes
    int g_x;
    int text_x=0,text_y=0; //for text position in screen resolution
    //  int sound_flag=0; // for on and of the sound
    int comp_m=0; // computer moves randomly
    reset=fopen("media\\set.dat","r");
    //  fseek(reset,0,0);
    fscanf(reset,"%d",&f_time);
    fclose(reset);
    // to show all user characters before entering to the loop
    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr); // player 1
    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
    comp_m=rand()%5;
    while(box_no!=0)
    {
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,15,"Press ESC to Pause");
        // show computer score
        setfillstyle(1,0);
        bar(1052,50,1250,600); // to clear previous score, box no ,etc
        setcolor(15);
        line(1050,50,1050,609);
        setcolor(user2_clr1);
        settextstyle(0,0,2);
        outtextxy(1100+text_x,50+text_y,"Player 2");
        outtextxy(1120+text_x,70+text_y,"SCORE");
        sprintf(user2_s,"%d",user2_score);
        outtextxy(1100+text_x,120+text_y,user2_s); // print computer score
        outtextxy(1170+text_x,120+text_y,"/1500");
        outtextxy(1100+text_x,200+text_y,"________");
        outtextxy(1140+text_x,250+text_y,"Life");
        sprintf(user2_l,"%d",user2_life);
        outtextxy(1140+text_x,270+text_y,user2_l);
        setfillstyle(1,user2_clr1);
        bar(1110,300,1210,310);
        setfillstyle(1,user2_clr2);
        bar(1109,300,1109-(box_no-150)*10/15,310);
        setcolor(15);
        rectangle(1108,298,1211,311);
        outtextxy(1100+text_x,320+text_y,"________");
        outtextxy(1140+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(1120+text_x,420+text_y,box_n);
        outtextxy(1170+text_x,420+text_y,"/150");
        // end of computer score
        // show user score
        setfillstyle(1,0);
        bar(0,50,218,610); // to clear previous score, box no ,etc
        setcolor(15);
        line(220,50,220,610);
        setcolor(user1_clr1);
        outtextxy(50+text_x,50+text_y,"Player 1");
        outtextxy(50+text_x,70+text_y,"SCORE");
        sprintf(user1_s,"%d",user1_score);
        outtextxy(50+text_x,120+text_y,user1_s); // print computer score
        outtextxy(120+text_x,120+text_y,"/1500");
        settextstyle(0,0,2); // life printing process
        outtextxy(50+text_x,200+text_y,"________");
        outtextxy(50+text_x,250+text_y,"Life");
        sprintf(user1_l,"%d",user1_life);
        outtextxy(50+text_x,270+text_y,user1_l);
        setfillstyle(1,user1_clr1);
        bar(50,300,150,310);
        setfillstyle(1,user1_clr2);
        bar(150-(1000-user1_life)/10,300,151,310);
        setcolor(15);
        rectangle(48,298,151,311);
        setcolor(user1_clr1);
        outtextxy(50+text_x,320+text_y,"________");
        outtextxy(50+text_x,380+text_y,"Box");
        sprintf(box_n,"%d",box_no);
        outtextxy(50+text_x,420+text_y,box_n);
        outtextxy(100+text_x,420+text_y,"/150");
        // end of user score
        // display the ring
        setcolor(15);
        circle(640+ringx,330+ringy,200+ringr);
        circle(640+ringx,330+ringy,202+ringr);
        // end of the ring
        //call  box function
        sp.box(box_sx1,box_sy1,box_ex1,box_ey1); // box 1
        sp.box(box_sx1+175,box_sy1+175,box_ex1+175,box_ey1+175); // box 2
        sp.box(box_sx1,box_sy1+350,box_ex1,box_ey1+350); // box 3
        sp.box(box_sx1-175,box_sy1+175,box_ex1-175,box_ey1+175); // box 2
        // end of box function
        if(f_time==0 )
        {sp.tutorial(&f_time);}
        sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
        sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
        sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
        sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
        if(kbhit())
        {
            user1_key=getch();
            if(user1_key==27) // for exit to the program
            {
                sp.pause(&sound_flag,&ret);
                if(ret==1)
                {
                    cleardevice();
                    home();
                }
                delay(100);
                cleardevice();
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr); // player 1
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
            }
            // condition for  move down
            if(user1_key==48)
            {
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1=-300;
                user1_ey1=-300;
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr); // to clear all rest chars
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3=300;
                user1_ey3=300;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2=300;
                user1_ex2=300;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4=-300;
                user1_ex4=-300;
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
            }
            if(user1_key==80)
            {
                if(user1_sy1>-200)
                {
                    sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                    user1_sy1-=50; // stop moving down
                    user1_ey1-=50; // stop moving down
                    box_no--;
                }// moving conditions
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr2,user1_clr2); // to clear all rest chars
                user1_sy1+=50; // move down
                user1_ey1+=50; // move down
                sp.char1(user1_sx1,user1_sy1,user1_ex1,user1_ey1,user1_clr1,user1_hclr);
                if(user1_ey1>=box_sx1-200) // user catch the computer 3
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of down condition
            // move up side
            if(user1_key==72)
            {
                if(user1_sy3<200)
                {
                    sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                    user1_sy3+=50; // stop moving upside
                    user1_ey3+=50; // stop moving upside
                }// moving conditions
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr2,user1_clr2);
                user1_sy3-=50;
                user1_ey3-=50;
                sp.char3(user1_sx3,user1_sy3,user1_ex3,user1_ey3,user1_clr1,user1_hclr);
                if(user1_ey3<=box_sy1+200) // user catch the computer 1
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of up  condition
            // move left side
            if(user1_key==75)
            {
                if(user1_sx2<200)
                {
                    sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                    user1_sx2+=50;
                    user1_ex2+=50;
                }// moving conditions
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr2,user1_clr2);
                user1_sx2-=50;
                user1_ex2-=50;
                sp.char2(user1_sx2,user1_sy2,user1_ex2,user1_ey2,user1_clr1,user1_hclr);
                if(user1_ex2<=box_sx1+200) // user catch the computer 4
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            }// end of up  condition
            // condition for right side movement
            if(user1_key==77)
            {
                if(user1_sx4>-200)
                {
                    sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                    user1_sx4-=50; // stop moving
                    user1_ex4-=50; // stop moving
                }// moving conditions
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr2,user1_clr2);
                user1_sx4+=50; // move right
                user1_ex4+=50; // move right
                sp.char4(user1_sx4,user1_sy4,user1_ex4,user1_ey4,user1_clr1,user1_hclr);
                if(user1_ex4>=box_sx1-200) // user catch the computer 3
                {
                    user1_score+=10;
                    user2_score-=10;
                    box_no--;
                }
            } // end of up  condition
            if(user1_key==74 || user1_key==106)
            {
                if(user2_sx1<-50)
                {
                    if(user2_sy1<-150)
                    {
                        sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                        user2_sy1-=150;
                        user2_ey1-=150;
                    }
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sx1+=150;
                    user2_ex1+=150;
                    comp_m=rand()%4;
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sx1-=150;
                user2_ex1-=150;
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
                if(user1_sx4>=user2_sx1-100) // user 2 comes  to the computer 2
                {
                    user1_life-=5;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                } // end of user 2 comes to the computer 2
            }
            if(user1_key==70 || user1_key==102)
            {
                if(user2_sx1>50)
                {
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sx1-=150;
                    user2_ex1-=150;
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sx1+=150;
                user2_ex1+=150;
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
                if(user1_sx2<=user2_sx1+100) // user 2 comes  to the computer 2
                {
                    user1_life-=5;
                    if(sound_flag==10 || sound_flag==11)
                        PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                } // end of user 2 comes to the computer 2
            }
            if(user1_key==69 || user1_key==101)
            {
                if(user2_sy1<-50)
                {
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sy1+=150;
                    user2_ey1+=150;
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sy1-=150;
                user2_ey1-=150;
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
                if(user1_sy1>=user2_sy1-100) // user 3 comes  to the computer 3
                {
                    user1_life-=5;
                    if(sound_flag==10 || sound_flag==11)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                } // end of user 3 comes to the computer 3
            }
            if(user1_key==73 || user1_key==105)
            {
                if(user2_sy1>50)
                {
                    sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                    user2_sy1-=150;
                    user2_ey1-=150;
                }
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char2(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char3(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                sp.char4(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr2,user2_clr2);
                user2_sy1+=150;
                user2_ey1+=150;
                sp.char1(user2_sx1,user2_sy1,user2_ex1,user2_ey1,user2_clr1,user2_hclr);
                if(user1_sy3<=user2_sy1+100) // user 3 comes  to the computer 3
                {
                    user1_life-=5;
                    if(sound_flag==0 || sound_flag==111)
                    PlaySound(TEXT("media\\out.wav"),NULL,SND_SYNC);
                } // end of user 3 comes to the computer 3
            }
        } // end of if statement
        if(box_no==120)
        {
            user2_life=800; // computer life
        }
        if(box_no==90) // computer life
        {
            user2_life=600;
        }
        if(box_no==60)
        {
            user2_life=400;
        }
        if(box_no==30)
        {
            user2_life=200;
        }
        if(box_no<=0)
        {
            user2_life=0;
        }
        if(user1_life<=0 || user2_life<=0)
        {
            cleardevice();
            sp.score(user1_score,user2_score,1,sound_flag);
            delay(5000);
            cleardevice();
            return 0;
        }
    } // end of while loop
    return 0;
}// end of p2 save function
//////////////////////// tossing event functions for single player and double players
s_player() // single player function
{
    int sound_flag=1,resolution=0,toss=rand()%100;
    FILE *reset_file;
    cleardevice();
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag);
    fseek(reset_file,1,0);
    fscanf(reset_file,"%d",&resolution);
    setcolor(15);
    settextstyle(0,0,5);
    outtextxy(450,50,"tossing...");
    settextstyle(0,0,4);
    outtextxy(100,150,"User          V/s        Computer ");
    settextstyle(0,0,3);
    if(sound_flag==10 || sound_flag==11)
        PlaySound(TEXT("media\\tossing.wav"),NULL,SND_SYNC);
    delay(700);
    if(toss%2==0)
    {
        outtextxy(550,530,"YOU Win");
        delay(1000);
        cleardevice();
        comp_save1280(sound_flag);
        toss++;
        return 0;
    }
    else
    {
        outtextxy(480,530,"Computer Win");
        delay(1000);
        cleardevice();
        user_save1280();
        toss++;
        return 0;
    }
return 0;
} // end of single player function
d_player() // double players function
{
    int sound_flag=1,toss=rand()%100;
    FILE *reset_file;
    cleardevice();
    reset_file=fopen("media\\sr.dat","r");
    fseek(reset_file,0,0);
    fscanf(reset_file,"%d",&sound_flag);
    fseek(reset_file,1,0);
    setcolor(15);
    settextstyle(0,0,5);
    outtextxy(450,50,"tossing...");
    settextstyle(0,0,4);
    outtextxy(100,150,"User          V/s        Computer ");
    settextstyle(0,0,3);
    if(sound_flag==10 || sound_flag==11)
        PlaySound(TEXT("media\\tossing.wav"),NULL,SND_SYNC);
    delay(700);
    if(toss%2==0)
    {
        outtextxy(490,530,"Player 1 Win");
        delay(7000);
        cleardevice();
        p2_save1280();
        return 0;
    }
    else
    {
        outtextxy(490,530,"Player 2 Win");
        delay(7000);
        cleardevice();
        p1_save1280();
        return 0;
    }
return 0;
}// end f double players function
