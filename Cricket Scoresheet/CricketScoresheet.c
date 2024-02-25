#include<stdio.h>
#include<stdlib.h>

void req_rate(float a, float b, float c, float d, float e);
void runs_needed(int a, int b, int c, int d, int e);
void projected_score(int a, int b, int c, int d, float e);
void result(int a, int b, int e, int g, char f, char c[], char d[]);
float curr_rate(float a, float b, float c);
void ball_played(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *i, int *j);
int string_comp(char a[], char b[], char c[]);
float curr_rate(float a, float b, float c);
int main(int argc, char *argv[]) {
    int wd=0, nb=0, lb=0, b=0, extras=0, overs=0, T_overs=0, k=0, balls=0, T=0, score=0, wickets=0, target=0, q=0, c[11], j=1, f=0, s=0;
    float c_rate;
    char toss[15], team_1[15], team_2[15], choice, runs;
    printf("Match between:\n");
    gets(team_1);
    printf("versus\n");
    gets(team_2);
    printf("Toss won by:\n");
    gets(toss);
    printf("Enter B to choose bat first and F to field first:");
    scanf("%c", &choice);
    printf("Enter overs to be played by each side: ");
    scanf("%d", &T_overs);
    system("cls");
    T= string_comp(team_1, team_2, toss);
    while(overs<=T_overs || overs>=T_overs){
        do{
            if(wickets>q){
                *(c+wickets)=score;
            }
            q=wickets;
            system("cls");
            printf("\t\t\t%s vs %s (%d-overs match)\n", team_1, team_2, T_overs);
            if(T==1){
                if(choice=='B'||choice=='b'){
                    printf("%s won the toss and elected to bat first\n", team_1);
                    printf("\n\n%s %d-%d\t\tovers %d.%d\t\t", team_1, score, wickets, overs, balls);
                }
                else if(choice=='F'||choice=='f'){
                    printf("%s won the toss and elected to field first\n", team_1);
                    printf("\n\n%s %d-%d\t\tovers %d.%d\t\t", team_2, score, wickets, overs, balls);
                }
            }
            else if(T==2){
                if(choice=='B'||choice=='b'){
                    printf("%s won the toss and elected to bat first\n", team_2);
                    printf("\n\n%s %d-%d\t\tovers %d.%d\t\t", team_2, score, wickets, overs, balls);
                }
                else if(choice=='F'||choice=='f'){
                    printf("%s won the toss and elected to field first\n", team_2);
                    printf("\n\n%s %d-%d\t\tovers %d.%d\t\t", team_1, score, wickets, overs, balls);
                }
            }
            if (overs>0&&score>20){
                if(overs==T_overs||wickets==10){
                    printf("\n");
                    k++;
                    break;
                }
                c_rate= curr_rate(score,overs,balls);
                printf("run rate %0.2f\n",c_rate);
            }
            if(balls==0){
                printf("\n");
                if(extras>0){
                    printf("extras: %d(wd %d, nb %d, lb %d, b %d)\t", extras, wd, nb, lb, b);
                }
                if(f>0||s>0){
                    printf("boundaries: %d fours, %d sixes\n", f, s);
                }
                else
                printf("\n");
            }
            if(overs>0&&score>20&&balls==0){
                projected_score(score,overs,T_overs,balls,c_rate);
            }
            print("\n");
            if(overs==T_overs||wickets==10){
                k++;
                break;
            }
            ball_played(&balls,&score,&wickets,&extras,&wd,&nb,&lb,&b,&f,&s);
        }while(balls<6);
        if(balls==6){
            balls=0;
        }
        if(overs<T_overs){
            overs++;
        }
        if(k>0){
            break;
        }
    }
    printf("\nextras: %d(wd %d, nb %d, lb %d, b %d)\tboundaries: %d fours, %d sixes\n", extras, wd, nb, lb, b, f, s);
    if(wickets>0){
        printf("\nfall of wickets: ");
        for(j=1; j<=wickets; j++){
            if(j==1||j==6)
            printf("\n");
            else
            printf("\t");
            printf("%d-%d",j,c[j]);
        }
    }
    printf("\n\ninnings completed.");
    sleep(10);
    for(k=10;k>=0;k--){
        system("cls");
        printf("\n\n\n\n\t\t\tINNINGS BREAK...\n\t\t\t\t%d", k);
        sleep(1);
    }
    target=score+1,score=0,overs=0,k=0,wd=0,nb=0,lb=0,b=0,balls=0,wickets=0,extras=0,j=0,q=0,f=0,s=0;
    while(overs<=T_overs||overs>=T_overs){
        do{
            if(wickets>q){
                *(c+wickets)=score;
            }
            q=wickets;
            system("cls");
            printf("\t\t\t%s vs %s (%d-overs match)\n", team_1, team_2, T_overs);
            if(T==1){
                if(choice=='B'||choice=='b'){
                    printf("%s gives target of %d runs to %s to win\n", team_1, target, team_2);
                    printf("\n\n%s %d-%d\t overs %d.%d\t", team_2, score, wickets, overs, balls);
                }
                else if(choice=='F'||choice=='f'){
                    printf("%s gives target of %d runs to %s to win\n", team_2, target, team_1);
                    printf("\n\n%s %d-%d\t overs %d.%d\t", team_1, score, wickets, overs, balls);
                }
            }
            else if(T==2){
                if(choice=='B'||choice=='b'){
                    printf("%s gives target of %d runs to %s to win\n", team_2, target, team_1);
                    printf("\n\n%s %d-%d\t overs %d.%d\t", team_1, score, wickets, overs, balls);
                }
                else if(choice=='F'||choice=='f'){
                    printf("%s gives target of %d runs to %s to win\n", team_1, target, team_2);
                    printf("\n\n%s %d-%d\t overs %d.%d\t", team_2, score, wickets, overs, balls);
                }
        }

        
    }
    }
