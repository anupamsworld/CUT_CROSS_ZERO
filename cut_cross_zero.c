Updates to keyboard shortcuts … On Thursday, August 1, 2024, Drive keyboard shortcuts will be updated to give you first-letters navigation.Learn more
#include<conio.h>
#include<stdio.h>
#include<windows.h>
typedef struct for_player{
char first_name[20] ;
}player ;
char plate[9][9],cpy_plate[9][9] ;
int player_option,turn,sub_turn,game_over_response,overall_point_plyr1,overall_point_plyr2,row,column,total_match,can_win,turn_of_both_plyr,view_mood=2 ;
int continue_win_plyr1,continue_win_plyr2,continue_lose_plyr1,continue_lose_plyr2,continue_match_drawn ;
int posi=0 ;
int bonus1,level;
player player1,player2 ;
/*
VARIABLE DETAILS--
player_option=to record user is playing this game with COMPUTER(1) or two player is there(2) ;
turn=which player start the match with ''x'' sign taking the first turn,if 1 then player1 oR if 2 then player2 started the match
sub_turn=it stores which player is taking turn under a certain match, if 1 then player1, if 2 then player2
game_over_response=it stores whether the match is over or not ,if 0 then not over , if 1 then player1 wins game over,if 2 player2 wins and game is over
overall_point_plyr1 and overall_point_plyr2=holds the total number(s) of won match(es) by player1 and player2 respectively
row and column=holds the row and column respectively to access the plate (which is a form of a matrix)
total_match=holds the total number(s) of match(es) have been played
can_win=it holds zero(not to confirm) or one(to confirm) the winning ability of the COMPUTER for a certain situation of a match,that means if such situation comes for a certain condition that the computer can win must, then the can_win will be into 1
turn_of_both_plyr=it holds the total number of turns is going on in a particular match including the turn of player1 and player2
continue_win_plyr1 and continue_win_plyr2=holds the continuously won match(es) for the last match(es) by the player1 and player2 respectively
continue_lose_plyr1 and continue_lose_plyr2=holds the continuously losed  match(es) for the last match(es) by the player1 and player2 respectively
continue_match_drawn=holds the continuously drawn or tied  match(es) for the last match(es)
level=holds the level chosen by the user/player ,1 for low,2 for high--- it only applicable during the match with COMPUTER
bonus1=holds how many times the player(playing with computer) unable to win because of drawn or tied match(es) or for becoming loser
view_mood=holds 1(when the view of the plate or play box is like list,here previous turns are displayed) and 0(here view is static, previous turns are not displayed here)
posi=it is used to hold the returned position by the function get_posi_for_com  for computer's position
*/
void default_for_more_match(){//this function is to default all the values to continue to the other one match
    int i,l ;
sub_turn=0 ;
game_over_response=0 ;
can_win=0 ;
turn_of_both_plyr=0 ;
for(i=0;i<3;i++){
        for(l=0;l<3;l++){
            plate[i][l]='-' ;
            cpy_plate[i][l]='-' ;
        }
}
}
void default_all(){//this function is to default all the variables
    int i,l ;
    overall_point_plyr1=0 ;
    overall_point_plyr2=0 ;
    turn=0;
    player_option=0 ;
sub_turn=0 ;
game_over_response=0 ;
total_match=1 ;
can_win=0 ;
turn_of_both_plyr=0 ;
continue_win_plyr1=0 ;
continue_win_plyr2=0 ;
continue_lose_plyr1=0 ;
continue_lose_plyr2=0 ;
continue_match_drawn=0 ;
bonus1=0 ;
level=0 ;
    for(i=0;i<3;i++){
        for(l=0;l<3;l++){
            plate[i][l]='-' ;
            cpy_plate[i][l]='-' ;
        }
    }
    strcpy(player1.first_name,"NOT IN RECORD !!") ;
    strcpy(player2.first_name,"NOT IN RECORD !!") ;
}
void match_statistics(){//this function is to display the match statistics
    printf("\n\n\tTotal match(es) have been played :: %d",total_match);
    printf("\n\n\tNumber(s) of continuously tie match(es) :: %d",continue_match_drawn);
printf("\n\n~~For %s(player 1 )",player1.first_name);
    printf("\nTotal number of times %s(player 1) have won :: %d",player1.first_name,overall_point_plyr1);
    printf("\nNumber of time(s) %s(player 1) have won continuously for last match(es) :: %d",player1.first_name,continue_win_plyr1);
    printf("\nNumber of time(s) %s(player 1) have lost continuously for last match(es) :: %d",player1.first_name,continue_lose_plyr1);
printf("\n\n~~For %s(player 2 )",player2.first_name);
    printf("\nTotal number of times %s(player 2) have won :: %d",player2.first_name,overall_point_plyr2);
    printf("\nNumber of time(s) %s(player 2) have won continuously for last match(es) :: %d",player2.first_name,continue_win_plyr2);
    printf("\nNumber of time(s) %s(player 2) have lost continuously for last match(es) :: %d",player2.first_name,continue_lose_plyr2);
}
void show_player1_name(){//function to display the the player1's name
printf("%s",player1.first_name);
}
void show_player2_name(){//function to display the the player2's name
printf("%s",player2.first_name);
}
void take_players_name(){//function to get input the name(s) of the player,playing the game
    if(player_option==1){
printf("\nType  player's First Name %c%c%c ",16,16,16);
fflush(stdin);
gets(player1.first_name);
strcpy(player2.first_name,"COMPUTER");
system("cls");
    }
    else if(player_option==2){
        printf("\nType player 1's First Name %c%c%c ",16,16,16);
        fflush(stdin);
        gets(player1.first_name);
        printf("\nType player 2's First Name %c%c%c ",16,16,16);
        fflush(stdin);
        gets(player2.first_name);
        system("cls");
    }
    if(player_option==1){
    printf("\nSO THERE IS ONE MANUAL PLAYER !\nHI ") ;
     show_player1_name() ;
    }
   else if(player_option==2){
    printf("\nSO THERE ARE TWO MANUAL PLAYERS !\nHI ") ;
    show_player1_name() ; printf("\nHI ");
    show_player2_name();
    }
}

void initial_load(){//to load initial needs
    int i,l ;
    printf("\nWELCOME !!");
    Sleep(1000);
    printf("\nGAME IS BEING LOADED !!");
    Sleep(3*1000);
    system("cls");
    for(i=0;i<4;i++){
        printf("\nLoading");
        for(l=0;l<5;l++){
            Sleep(400);
            printf(".");
        }
        system("cls");
    }
}
void about_me(){//function of details about programmer(ANUPAM CHANDA)me
    printf("\nNAME \t\t%c \tANUPAM CHANDA %c %c\nGENDER \t\t%c \tMale %c\nAGE \t\t%c \t18+\nE-MAIL ID \t%c \tmailmeanupamchanda@gmail.com\nWEB SITE \t%c \tanupamsworld.wapka.me",16,2,3,16,11,16,16,16);
    Sleep(900);
    printf("\n\nHELLO !! Dear user, I am ANUPAM CHANDA, have made this game with my own thought and logic, if this matches with other one(with other algorithm or any game) then I am not responsible for that. If anybody claims about this algorithm, then I can show him my own code, personally !\nThank you...\n\n\n");
    }
    void about_game(){//function about the game and help about this game
    printf("\n\t~~ CUT CROSS ZERO ~~     Version :: 3.0     Released on 17/11/2015");
    printf("\nMy contact information has been provided in option no 4. ");
    printf("\nThe game is :: There are 3x3 position box ,two possible sign ''x''  and ''o''");
    printf("\nHere you can play this game with the computer ,that means with automated program logic.Whatever you choose you have to give input the position number.");
    printf("\nThe input from the players should be in the form of a number. which will be the position number. Example of position has been showed below.");
    printf("\n\n 1 2 3 \n 4 5 6 \n 7 8 9 ");
    printf("\nAnd the winner will be that player who will form a structure of straight line of ''x''-s or ''o''-s. Keep in mind that the no of ''x''-s or ''o''-s is 3 and of course in straight line formate.That means 3 sign adjacently.");
    printf("\nHere are some example for you. ");
    printf("\n\nPress 'g'");
    char en_char1='\t' ;
    do{
            fflush(stdin);
            en_char1=getch();
    }while(en_char1!='g');
    printf("\n\n x - - \n x - - \n x - - \n\n OR \n\n o - - \n - o - \n - - o ");
    printf("\n\nWhere these following types of formate will not be accepted for winning.");
    printf("\n\n x x - \n - x - \n - - - \n\nOR\n\n - - - \n - o o \n - o - ");
    printf("\n\nPress 'g'");
    char en_char='\t' ;
    do{
            fflush(stdin);
            en_char=getch();
    }while(en_char!='g');
    printf("\n\nSo give the position number to put your sign to that position.");
    //printf("For example if you put something in the position (3,2) means no. 3 row and no. 2 column then just type 3<space>2<enter> OR 3<enter>2<enter>  thats all.");
    printf("\nYes! This is clear that which member will take which symbol whether ''o'' or ''x'' will be selected by the computer.");
    printf("\nYou have to just remember what symbol have been provided to you. Then play with this symbol with opponent player just giving position in the above mentioned manner.");
    printf("\nOther commands will be provided during play time.\nALL THE BEST  !!!!  %c %c",3,2);
    printf("\n\n\n");
}
void take_turn(){//function to take turn
    if(player_option==2){
printf("\nPress 1 for %s(player 1) and 2 for %s(player 2)     and 99 to go to Main menu:: ",player1.first_name,player2.first_name);
    }
    else if(player_option==1){
        printf("\n1. Yes\n2. No (where the Computer will take the first turn)\n\n99. to go to Main menu");
    }
    printf("\n%c%c%c ",16,16,16);
    fflush(stdin);
    scanf("%d",&turn);
    if(turn!=1 && turn!=2 && turn!=99){
        printf("\nSorry !! press right option !!");
        take_turn();
        return ;
    }
    else if(turn==99){
        return ;
    }
}
void show_plate(){//to show plate
    int i,l ;
    printf("\n");
     printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n ",218,196,196,196,194,196,196,196,194,196,196,196,191);
    for(i=0;i<3;i++){
            if(i==1 || i==2)
            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n ",195,196,196,196,197,196,196,196,197,196,196,196,180);
        for(l=0;l<3;l++){
        printf("%c %c ",179,plate[i][l]);
        }
        printf("%c",179);
        Sleep(80);
        printf("\n");
    }
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n ",192,196,196,196,193,196,196,196,193,196,196,196,217);
}
void winner_with_sign(char winner_sign){//to set the game_over_response taking the sign , which was taken by the winner
//winner_sign=the sign , which was taken by the winner
if(winner_sign=='x'){
        game_over_response=turn ;
    }
    else if(winner_sign=='o'){
        if(turn==1){
            game_over_response=2 ;
        }
        else if(turn==2){
            game_over_response=1 ;
        }
    }
}
int check_game_over_response(int which_plate){
    if(which_plate==1){
        if((plate[0][0]==plate[0][1] && plate[0][1]==plate[0][2]) && (plate[0][0]=='x' || plate[0][0]=='o')){
            winner_with_sign(plate[0][0]);
        }
        else if((plate[1][0]==plate[1][1] && plate[1][1]==plate[1][2]) && (plate[1][0]=='x' || plate[1][0]=='o')){
            winner_with_sign(plate[1][0]);
        }
        else if((plate[2][0]==plate[2][1] && plate[2][1]==plate[2][2]) && (plate[2][0]=='x' || plate[2][0]=='o')){
            winner_with_sign(plate[2][0]);
        }
        else if((plate[0][0]==plate[1][0] && plate[1][0]==plate[2][0]) && (plate[0][0]=='x' || plate[0][0]=='o')){
            winner_with_sign(plate[0][0]);
        }
        else if((plate[0][1]==plate[1][1] && plate[1][1]==plate[2][1]) && (plate[0][1]=='x' || plate[0][1]=='o')){
            winner_with_sign(plate[0][1]);
        }
        else if((plate[0][2]==plate[1][2] && plate[1][2]==plate[2][2]) && (plate[0][2]=='x' || plate[0][2]=='o')){
            winner_with_sign(plate[0][2]);
        }
        else if((plate[0][0]==plate[1][1] && plate[1][1]==plate[2][2]) && (plate[0][0]=='x' || plate[0][0]=='o')){
            winner_with_sign(plate[0][0]);
        }
        else if((plate[0][2]==plate[1][1] && plate[1][1]==plate[2][0]) && (plate[0][2]=='x' || plate[0][2]=='o')){
            winner_with_sign(plate[0][2]);
        }
    }
    else if(which_plate==2){
        if((cpy_plate[0][0]==cpy_plate[0][1] && cpy_plate[0][1]==cpy_plate[0][2]) && (cpy_plate[0][0]=='x' || cpy_plate[0][0]=='o')){
                //printf("\nreturning with condition 1");
                return 1 ;
        }
        else if((cpy_plate[1][0]==cpy_plate[1][1] && cpy_plate[1][1]==cpy_plate[1][2]) && (cpy_plate[1][0]=='x' || cpy_plate[1][0]=='o')){
            //printf("\nreturning with condition 2");
            return 1 ;
        }
        else if((cpy_plate[2][0]==cpy_plate[2][1] && cpy_plate[2][1]==cpy_plate[2][2]) && (cpy_plate[2][0]=='x' || cpy_plate[2][0]=='o')){
            //printf("\nreturning with condition 3");
            return 1 ;
        }
        else if((cpy_plate[0][0]==cpy_plate[1][0] && cpy_plate[1][0]==cpy_plate[2][0]) && (cpy_plate[0][0]=='x' || cpy_plate[0][0]=='o')){
            //printf("\nreturning with condition 4");
            return 1 ;
        }
        else if((cpy_plate[0][1]==cpy_plate[1][1] && cpy_plate[1][1]==cpy_plate[2][1]) && (cpy_plate[0][1]=='x' || cpy_plate[0][1]=='o')){
            //printf("\nreturning with condition 5");
            return 1 ;
        }
        else if((cpy_plate[0][2]==cpy_plate[1][2] && cpy_plate[1][2]==cpy_plate[2][2]) && (cpy_plate[0][2]=='x' || cpy_plate[0][2]=='o')){
            //printf("\nreturning with condition 6");
            return 1 ;
        }
        else if((cpy_plate[0][0]==cpy_plate[1][1] && cpy_plate[1][1]==cpy_plate[2][2]) && (cpy_plate[0][0]=='x' || cpy_plate[0][0]=='o')){
            //printf("\nreturning with condition 7");
            return 1 ;
        }
        else if((cpy_plate[0][2]==cpy_plate[1][1] && cpy_plate[1][1]==cpy_plate[2][0]) && (cpy_plate[0][2]=='x' || cpy_plate[0][2]=='o')){
            //printf("\nreturning with condition 8");
            return 1 ;
        }
        else
            return 0 ;
    }
}
void put_in_plate(int which_plate,int stop_opponent,int row,int column){//to put sign into the particular position of the plate
    //which_plate=hold in which plate (plate or cpy_plate) perticular sign is to be set
    //stop_opponent=holds zero(whether to stop the opponent blocking/preventing the straight line form) or 1(not to stop)
    if(which_plate==1){
        if(sub_turn==turn){
            plate[row][column]='x' ;
        }
        else if(sub_turn!=turn){
            plate[row][column]='o' ;
        }
    }
    else if(which_plate==2){
        if(stop_opponent==0){
            if(sub_turn==turn){
                cpy_plate[row][column]='x' ;
            }
            else if(sub_turn!=turn){
                cpy_plate[row][column]='o' ;
            }
        }
        else if(stop_opponent==1){
             if(sub_turn==turn){
                cpy_plate[row][column]='o' ;
            }
            else if(sub_turn!=turn){
                cpy_plate[row][column]='x' ;
            }
        }
    }
}
void copy_plate(){//to copy the plate[][] into cpy_plate[][]
    int i,l ;
    for(i=0;i<3;i++){
        for(l=0;l<3;l++){
            cpy_plate[i][l]=plate[i][l] ;
        }
    }
}
int get_posi_for_com(){//function to analysis position in which the COMPUTER will put its sign
    int bonus_wait;
    int i,l,com_posi=0,com_game_over_response=0 ;
//com_game_over_response=holds 1(where the COMPUTER checks by various method and checking function return 1,, when one of the 8 winning conditions satisfied) or holds zero for not satisfaction
    if(level==1){
        bonus_wait=3 ;
    }
    else if(level==2){
        bonus_wait=5 ;
    }
    copy_plate();
        for(i=0;i<3;i++){
            for(l=0;l<3;l++){
                com_posi=com_posi+1 ;
                //printf("\nincreasing com_posi=%d",com_posi);
                if(plate[i][l]=='-'){
                        put_in_plate(2,0,i,l) ;
                        com_game_over_response=check_game_over_response(2) ;
                        copy_plate();
                        if(com_game_over_response==1){
                                //printf("\nreturing com_posi=%d",com_posi);
                            return com_posi ;
                        }
                }
            }
        }
        //printf("\ncom_game_over_response=%d",com_game_over_response);
        //printf("\ncontinue_lose_plyr1=%d;;continue_match_drawn=%d;;bonus1=%d",continue_lose_plyr1,continue_match_drawn,bonus1);
        if(com_game_over_response==0){
                    com_posi=0 ;
                for(i=0;i<3;i++){
                    for(l=0;l<3;l++){
                        com_posi=com_posi+1;
                        //printf("\nincreasing com_posi=%d,stop_opponent",com_posi);
                        if(plate[i][l]=='-'){
                            put_in_plate(2,1,i,l);
                            com_game_over_response=check_game_over_response(2) ;
                            copy_plate();
                            if(com_game_over_response==1){
                                    //printf("\nreturing com_posi=%d",com_posi);
                                    //printf("\ncom_game_over_response=%d",com_game_over_response);
                                if(bonus1<bonus_wait)
                                    return com_posi ;
                                else if(bonus1>=bonus_wait){
                                    bonus1=0 ;
                                    com_game_over_response=0 ;
                                }
                            }
                        }
                    }
                }
                //printf("\ncom_game_over_response=%d,after stop_opponent",com_game_over_response);
        }
        //printf("\ncom_game_over_response=%d",com_game_over_response);
            if(com_game_over_response==0){
                if(turn==2){
                    if(turn_of_both_plyr==1){
                        if(plate[1][1]=='-'){
                            return 5 ;
                        }
                    }
                    else if(turn_of_both_plyr==3){
                        if(plate[0][1]=='o' || plate[1][0]=='o' || plate[1][2]=='o' || plate[2][1]=='o'){
                            if(plate[2][1]!='o' && plate[0][1]=='-'){
                                    can_win=1 ;
                                    return 2 ;
                               }
                            else if(plate[1][2]!='o' && plate[1][0]=='-'){
                                    can_win=1 ;
                                return 4 ;
                            }
                            else if(plate[1][0]!='o' && plate[1][2]=='-'){
                                    can_win=1 ;
                                return 6 ;
                            }
                            else if(plate[0][1]!='o' && plate[2][1]=='-'){
                                    can_win=1 ;
                                return 8 ;
                            }
                        }
                    }
                    else if(turn_of_both_plyr==5 && can_win==1){
                            if(plate[0][1]=='x'){
                                    if(plate[0][0]=='-'){
                                        return 1 ;
                                    }
                                    else if(plate[0][2]=='-'){
                                        return 3 ;
                                    }
                            }
                            else if(plate[1][0]=='x'){
                                if(plate[0][0]=='-'){
                                    return 7 ;
                                }
                                else if(plate[2][0]=='-'){
                                    return 1 ;
                                }
                            }
                            else if(plate[1][2]=='x'){
                                if(plate[0][2]=='-'){
                                    return 3 ;
                                }
                                else if(plate[2][2]=='-'){
                                    return 9 ;
                                }
                            }
                            else if(plate[2][1]=='x'){
                                if(plate[2][0]=='-'){
                                    return 9 ;
                                }
                                else if(plate[2][2]=='-'){
                                    return 7 ;
                                }
                            }
                    }
                }
            }
            if(com_game_over_response==0){
                if(plate[1][1]=='-'){
                        //printf("\nreturning 5");
                    return 5 ;
                }
                else if(plate[0][0]=='-' && total_match%2==0){
                    //printf("\nreturning 1");
                    return 1 ;
                }
                else if(plate[2][0]=='-' && total_match%3==0){
                    //printf("\nreturning 4");
                    return 7 ;
                }
                else if(plate[2][2]=='-' && total_match%5==0){
                    //printf("\nreturning 8");
                    return 9 ;
                }
                else if(plate[0][2]=='-'){
                    //printf("\nreturning 6");
                    return 3 ;
                }
                        com_posi=0 ;
                    for(i=0;i<3;i++){
                        for(l=0;l<3;l++){
                                com_posi=com_posi+1 ;
                            if(plate[i][l]=='-'){
                                return com_posi ;
                            }
                        }
                    }
            }
}
void get_posi_row_column(){//to get position(variable 'posi') and row and column respect to that posi,,from the player or COMPUTER
            do{
                do{
                        if(sub_turn==1){
                            printf("\n\nIts %s(player 1's) turn ~ give position(19 to exit from this Match) ::  ",player1.first_name);
                            printf("%c%c%c ",16,16,16);
                            fflush(stdin);
                            scanf("%d",&posi);
                        }
                        else if(sub_turn==2){
                                if(player_option==2){
                            printf("\n\nIts %s(player 2's) turn ~ give position(19 to exit from this Match) :: ",player2.first_name);
                            printf("%c%c%c ",16,16,16);
                            fflush(stdin);
                            scanf("%d",&posi);
                                }
                                else if(player_option==1){
                                    posi=get_posi_for_com();
                                    printf("\n%s has taken position %d",player2.first_name,posi);
                                }
                        }
                    if(posi!=1 && posi!=2 && posi!=3 && posi!=4 && posi!=5 && posi!=6 && posi!=7 && posi!=8 && posi!=9 && posi!=19){
                        printf("\nThe position you have entered is not in range or wrong. This should be one of 1 to 9 for position and 19 to go to main menu!!");
                    }
                    else if(posi == 10){
                        exit(1);
                    }
                }while(posi!=1 && posi!=2 && posi!=3 && posi!=4 && posi!=5 && posi!=6 && posi!=7 && posi!=8 && posi!=9 && posi!=19);
                        if(posi==1){
                            row=0;
                            column=0;
                        }
                        else if(posi==2){
                            row=0;
                            column=1;
                        }
                        else if(posi==3){
                            row=0;
                            column=2;
                        }
                        else if(posi==4){
                            row=1;
                            column=0;
                        }
                        else if(posi==5){
                            row=1;
                            column=1;
                        }
                        else if(posi==6){
                            row=1;
                            column=2;
                        }
                        else if(posi==7){
                            row=2;
                            column=0;
                        }
                        else if(posi==8){
                            row=2;
                            column=1;
                        }
                        else if(posi==9){
                            row=2;
                            column=2;
                        }
                            if(plate[row][column]!='-'  && posi!=19){
                                printf("\nNo way! The position you have chosen has been used !! Try another one.");
                            }
            }while(plate[row][column]!='-' && posi!=19);
}
void cycle_the_game(){//function to control the total game process
    char p ;
    show_plate();
            if(turn==1){
                printf("\nSo its %s's(player 1) turn ,, %s(player 1) will take 'x' symbol !!",player1.first_name,player1.first_name);
                printf("\nThats why %s(player 2) will take 'o' symbol !!",player2.first_name);
            }
            else if(turn==2){
                printf("\nSo its %s's(player 2) turn ,, %s(player 2) will take 'x' symbol !!",player2.first_name,player2.first_name);
                printf("\nThats why %s(player 1) will take 'o' symbol !!",player1.first_name);
            }
    sub_turn=turn;
    for(;game_over_response==0;){
            turn_of_both_plyr=turn_of_both_plyr+1 ;
            int i,j,blank_response=0 ;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(plate[i][j]=='-')
                        blank_response=blank_response+1 ;
                }
            }
            if(blank_response>0){
                if(sub_turn==1){
                    get_posi_row_column();
                    if(posi==19){
                        break ;
                    }
                    put_in_plate(1,0,row,column);
                    check_game_over_response(1);
                    sub_turn=2 ;
                }
                else if(sub_turn==2){
                        get_posi_row_column();
                        if(posi==19){
                            break ;
                        }
                        put_in_plate(1,0,row,column);
                        check_game_over_response(1);
                        sub_turn=1 ;
                }
                if(view_mood==2){
                    system("cls");
                    if(player_option==1 && sub_turn==1){
                        printf("\n%s has taken position %d",player2.first_name,posi);
                    }
                }
                    show_plate() ;
            }
            else if(blank_response==0){
                continue_match_drawn=continue_match_drawn+1 ;
                continue_win_plyr1=0 ;
                continue_win_plyr2=0 ;
                continue_lose_plyr1=0 ;
                continue_lose_plyr2=0 ;
                bonus1=bonus1+1 ;
                printf("\n\n\nGAME IS OVER !!! IT IS TIED !!");
                break;
            }
    }
    if(game_over_response==1){
            overall_point_plyr1=overall_point_plyr1+1 ;
            continue_win_plyr1=continue_win_plyr1+1 ;
            continue_win_plyr2=0 ;
            continue_lose_plyr2=continue_lose_plyr2+1 ;
            continue_lose_plyr1=0 ;
            continue_match_drawn=0 ;
            bonus1=0 ;
        printf("\n\nCONGRATULATION, %s !! YOU HAVE WON THIS MATCH !! ",player1.first_name);
    }
    else if(game_over_response==2){
        overall_point_plyr2=overall_point_plyr2+1 ;
        continue_win_plyr2=continue_win_plyr2+1 ;
        continue_win_plyr1=0 ;
        continue_lose_plyr1=continue_lose_plyr1+1 ;
        continue_lose_plyr2=0 ;
        continue_match_drawn=0 ;
        bonus1=bonus1+1 ;
        if(player_option==2){
        printf("\n\nCONGRATULATION, %s !! YOU HAVE WON THIS MATCH !! ",player2.first_name);
        }
        else if(player_option==1){
            printf("\n\nSORRY %s, %s HAVE WON THIS MATCH !! ",player1.first_name,player2.first_name);
        }
    }
        printf("\n\n%s(PLAYER 1) HAS WON %d TIME(s) AND %s(PLAYER 2) HAS WON %d TIME(s).",player1.first_name,overall_point_plyr1,player2.first_name,overall_point_plyr2);
    do{
        printf("\n\nWant to play one more match ?? Press 'y'\nDo not want to play more ?? Press 'n'\nWant match statistics ?? Press 's'");
        printf("\n%c%c%c ",16,16,16);
        fflush(stdin);
        p=getch();
        if(p=='y'){
            default_for_more_match();
            total_match=total_match+1 ;
            if(turn==1){
                turn=2 ;
            }
            else if(turn==2){
                turn=1 ;
            }
                cycle_the_game();
        }
        else if(p=='n'){
            //options();
        }
        else if(p=='s'){
            system("cls");
            match_statistics();
        }
        else{
            printf("\nSorry !! You pressed neither ''y'' nor ''n'' nor ''s''!!");
        }
    }while((p!='y' && p!='n') || p=='s');
}
void options(){//function of game option
    int op1;
    do{
printf("\n\n\n~~ CUT CROSS ZERO ~~          Version :: 3.0\n\nCHOOSE OPTION\n1. PLAY WITH COMPUTER \n2. PLAY TWO PLAYERS \n3. HELP ABOUT THIS GAME \n4. ABOUT PROGRAMMER \n5. QUIT FROM GAME \n6. CHANGE MOOD \n%c%c%c ",16,16,16);
fflush(stdin);
scanf("%d",&op1);
if(op1!=1 && op1!=2 && op1!=3 && op1!=4 && op1!=5 && op1!=6){
        system("cls");
    printf("\n\nSorry !! You have entered wrong option,try right one....");
}
    }while(op1!=1 && op1!=2 && op1!=3 && op1!=4 && op1!=5 && op1!=6);
if(op1==1){
    default_all();
    player_option=1;
    take_players_name();
    do{
    printf("\n\nCHOOSE LEVEL...\n1. LOW LEVEL\n2. HIGH LEVEL\n\n99. to go to Main menu ");
    printf("\n%c%c%c ",16,16,16);
    fflush(stdin);
    scanf("%d",&level);
    if(level!=1 && level!=2 && level!=99){
        printf("\nSorry!! You have entered wrong.");
    }
    }while(level!=1 && level!=2 && level!=99);
    if(level!=99){
        printf("\nFine !! Now say, do you want to take first turn with 'x' sign ?? \n");
        take_turn();
        if(turn!=99){
            cycle_the_game();
        }
    }
}
else if(op1==2){
    default_all();
    player_option=2 ;
    take_players_name();
    printf("\nFine !! Now say which player wants to take first turn with 'x' sign ?? \n");
    take_turn();
    if(turn!=99){
        cycle_the_game();
    }
}
else if(op1==3){
    system("cls");
    about_game();
    //options();
}
else if(op1==4){
    system("cls");
    about_me();
    //options();
}
else if(op1==5){
    exit(0);
}
else if(op1==6){
    system("cls");
    {
        int temp_view_mood=view_mood ;
        do{

                    printf("\n\nCHANGE VIEW MOOD");
                    if(view_mood==1){
                        printf("(LIST VIEW)");
                    }
                    else if(view_mood==2){
                        printf("(STATIC VIEW)");
                    }
                    printf("\n\n1.LIST VIEW (play box will be shown in list, here previous turn will be shown)\n\n2.STATIC VIEW (play box will be shown in a single static box, previous turn will not be shown)\n\n%c%c%c ",16,16,16);
                    fflush(stdin);
                    scanf("%d",&temp_view_mood);
                    if(temp_view_mood!=1 && temp_view_mood!=2){
                        system("cls") ;
                        printf("\nSorry ! Wrong entry. Try again...");
                        Sleep(1000) ;
                    }
        }while(temp_view_mood!=1 && temp_view_mood!=2) ;
        view_mood=temp_view_mood ;
    }
    if(view_mood==1){
            system("cls");
        printf("\nVIEW MOOD Successfully changed to LIST VIEW");
        Sleep(1000);
    }
    else if(view_mood==2){
            system("cls");
        printf("\nVIEW MOOD Successfully changed to STATIC VIEW");
        Sleep(1000);
    }
    //options();
}
}
main(){
    char start ;
    printf("\nPress Any Key");
    start=getch();
    system("cls");
    if(start!='?'){
    initial_load();
    }
    while(1){
        options();
    }
getch();
}
