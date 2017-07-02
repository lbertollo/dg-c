#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.c>
//Feito por Lucas Bertollo
struct strc{
int monsterhp,monsteratkmin,monsteratkmax,monsterdef,playerhp,playeratkmin,playerdef ,playeratkmax;
int playerhpdef,playerpots;
int monstercatego,monsternivel;
int statusatk,statusdef,statushp;
} globalvar;

void rndMonster(int level)
{
    int monsternivel,randvar,monstername;
    int monsterhp = 10,monsteratkmin = 1 ,monsteratkmax = 3,monsterdef = 2;
    srand ( time(NULL) );

    //Escolhe Nome
    monstername = rand() % 3;

    //Escolhe nivel
    randvar = rand() %101;

    if(randvar < 60)
    {
        monsternivel = 0;
    }

    else if(randvar < 70)
    {
        monsternivel = 1;
    }

    else if(randvar < 90)
    {
        monsternivel = 2;
    }
    else
    {
        monsternivel = 3;
    }

    //Calcula Hp do Monstro

    if (monsternivel == 0)
    {
        monsterhp = monsterhp + (level * 1); //??
        monsteratkmin = monsteratkmin + (level * 1);
        monsteratkmax = monsteratkmax + (monsteratkmin * 2);
        monsterdef = monsterdef + (level * 1);
    }
    else if(monsternivel == 1)
    {
        monsterhp = monsterhp + ((monsterhp - (level/2)) * (level * 2)); //??
        monsteratkmin = monsteratkmin + (level * 2);
        monsteratkmax = monsteratkmax + (monsteratkmin * 2);
        monsterdef = monsterdef + (level * 2);
    }
    else if(monsternivel == 2)
    {
        monsterhp = monsterhp + ((monsterhp - level) * (level * 3)); //??
        monsteratkmin = monsteratkmin + (level * 3);
        monsteratkmax = monsteratkmax + (monsteratkmin * 3);
        monsterdef = monsterdef + (level * 3);
    }
    else if(monsternivel == 3)
    {
        monsterhp = monsterhp + monsterhp * (level * 4); //??
        monsteratkmin = monsteratkmin + (level * 5);
        monsteratkmax = monsteratkmax + (monsteratkmin * 3);
        monsterdef = monsterdef + (level * 4);
    }

    //Adiciona valores para a Struct global

    globalvar.monsteratkmin = monsteratkmin;
    globalvar.monsteratkmax = monsteratkmax;
    globalvar.monsterhp = monsterhp;
    globalvar.monsterdef = monsterdef;
    globalvar.monsternivel = monsternivel;
    globalvar.monstercatego = monstername;
}
int onBattle(int level,char *nomeheroi)
{
        int randchest,randomizepot;
        const char *monsternames[4][3] = {
        {"Rat","Bat","Spider"},
        {"Goblin","Orc","Dwarf"},
        {"Dragon","Lich","Banshee"},
        {"Demon","Hydra","Giant Spider"}
        };
    srand ( time(NULL) );
    char opcaobattle;
    randchest = rand() % 101;
    if(randchest > 95)
    {
      chestFound(nomeheroi);
    }

    rndMonster(level);

    do{
/*Logo na Batalha*/{
        printf("\n");
        printf("    ____                                         \n");
        printf("   / __ \\ __  __ ____   ____ _ ___   ____   ____ \n");
        printf("  / / / // / / // __ \\ / __ `// _ \\ / __ \\ / __ \\\n");
        printf(" / /_/ // /_/ // / / // /_/ //  __// /_/ // / / /\n");
        printf("/_____/ \\__,_//_/ /_/ \\__, / \\___/ \\____//_/ /_/ \n");
        printf("                     /____/                      \n\n");
        printf("    ______                        __\n");
        printf("   / ____/_____ ____ _ _      __ / /___   _____\n");
        printf("  / /    / ___// __ `/| | /| / // // _ \\ / ___/\n");
        printf(" / /___ / /   / /_/ / | |/ |/ // //  __// /    \n");
        printf(" \\____//_/    \\__,_/  |__/|__//_/ \\___//_/\n\n");
}
//Batalha interface
    //printf("monster %d/%d",globalvar.monstercatego,globalvar.monsternivel);
    printf("--------------------Level %d--------------------\n", level);
    printf("              Monster name:%s \n",monsternames[globalvar.monstercatego][globalvar.monsternivel]);
    printf("              Monster Life:%d \n",globalvar.monsterhp);
    printf("              --------Vs--------                        \n");
    printf("              Player name:%s \n", nomeheroi);
    printf("              Player life:%d \n", globalvar.playerhp);
    printf("-----------------------------------------------\n");
    printf("\n");
    printf("---------------------Menu----------------------\n");
    printf("                 A - Attack \n");
    printf("                 D - Defend \n");
    printf("                 P - Potion[%d]\n",globalvar.playerpots);
    printf("-----------------------------------------------\n");
    scanf(" %c",&opcaobattle);
    switch(opcaobattle)
    {
        case 'a':
        danoPMonster();
        break;

        case 'd':
        //naoimplementado
        break;

        case 'p':
        if(globalvar.playerpots == 0)
        {
            printf("Voce nao tem pots\n");
            break;
        }
        else
        {
        randomizepot = rand() % 10 + 3;
        break;
        }
    }
    danoPPlayer();
    system("cls");
  }while(((globalvar.monsterhp >= 0) && (globalvar.playerhp >= 0)));
  //Retorna resultado da batalha Game over ou passou de level
  if(globalvar.monsterhp < 1)
    {
        return 0;
    }
  else if(globalvar.playerhp < 1)
    {
        return 1;
    }
}
onStats()
{
    int points = 0;
    char op;
    points = points + 4;
    globalvar.playerhp = globalvar.playerhpdef;
    srand ( time(NULL) );
    while(points != 0){
    printf("------------------AddStats-----------------\n");
    printf("Attack: %d ~ %d.   Defence: %d.   HP: %d.\n", globalvar.playeratkmin, globalvar.playeratkmax, globalvar.playerdef, globalvar.playerhp);
    printf("Points Left:%d                           \n",points);
    printf("1 - Adicionar em Attack [%d]                 \n",globalvar.statusatk);
    printf("2 - Adicionar em Defence [%d]               \n",globalvar.statusdef);
    printf("3 - Adicionar em HP [%d]                     \n",globalvar.statushp);
    printf("-------------------------------------------\n");
    scanf(" %c",&op);
    switch(op)
    {
    case '1':
        globalvar.statusatk += 1;
        globalvar.playeratkmin += 2;
        globalvar.playeratkmax += 3;
        points -= 1;
        break;
    case '2':
        globalvar.statusdef += 1;
        globalvar.playerdef += 1;
        points = points - 1;
        break;
    case '3':
        globalvar.statushp +=  1;
        globalvar.playerhp += 3;
        globalvar.playerhpdef += 3;
        points = points - 1;
        break;
    }
    system("cls");
}
    printf("Continuando Aventura...\n");
}
chestFound(char *nomeheroi)
{
    char op;
    int randomize;
    printf("%s achou um bau!\n",nomeheroi);
    printf("\n");
    printf("---------Menu---------\n");
    printf("A - Abrir\n");
    printf("S - Seguir em frente\n");
    printf("----------------------\n");
        switch(op)
        {
        case 'a':
            randomize = rand() % 5;
            if(randomize == 0)
            {
                randomize = rand() %4;
                printf("Voce ganhou: %d pontos de HP", randomize);
                globalvar.statushp += randomize;
            }
            else if(randomize == 1)
            {
                randomize = rand() %4;
                printf("Voce ganhou: %d pontos de Atk", randomize);
                globalvar.statusatk += randomize;
            }
            else if(randomize == 2)
            {
                randomize = rand() %4;
                printf("Voce ganhou: %d pontos de Def", randomize);
                globalvar.statusdef += randomize;
            }
            else if(randomize == 3)
            {
                printf("Buh! um monstro apareceu...");
            }
            else if(randomize == 4)
            {
                printf("%s achou uma Potion!",nomeheroi);
                globalvar.playerpots += 1;
            }
            system("cls");
            break;

            case 's':
                system("cls");
            break;
        }
}
danoPMonster()
{
    //Randomiza attack para o monstro

    int rndDamage,rndDefMonster, checkNegativo;
    rndDamage = rand() % globalvar.playeratkmax;
    rndDefMonster = rand() % globalvar.monsterdef;
    checkNegativo = rndDamage - rndDefMonster;
    if(checkNegativo  > 0)
    {
        globalvar.monsterhp -= (rndDamage - rndDefMonster);
    }
}
danoPPlayer()
{
    //Ramdomize attack para Player
    int rndDamage,rndDefPlayer, checkNegativo;
    rndDamage = rand() % globalvar.monsteratkmax;
    rndDefPlayer = rand() % globalvar.playerdef;
    checkNegativo = rndDamage - rndDefPlayer;
    if(checkNegativo  > 0)
    {
        globalvar.playerhp -= (rndDamage - rndDefPlayer);
    }
}
main()
{
    textcolor(WHITE+BLINK);

    //inicia variaveis globais e algumas basicas para o funcionamento
    int level = 1, op, gameover=0, recivegameover;
    char *nomeheroi;
    globalvar.playerhpdef = 20;
    globalvar.playerhp = 20;
    globalvar.playeratkmin = 13;
    globalvar.playeratkmax = 17;
    globalvar.playerdef = 5;
    globalvar.playerpots = 0;
    printf("______                                    \n");
    printf("|  _  \\                                   \n");
    printf("| | | |_   _ _ __   __ _  ___  ___  _ __  \n");
    printf("| | | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\ \n");
    printf("| |/ /| |_| | | | | (_| |  __/ (_) | | | |\n");
    printf("|___/  \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|\n");
    printf("                    __/ |                 \n");
    printf("                   |___/                  \n");
    printf(" _____                    _           \n");
    printf("/  __ \\                  | |          \n");
    printf("| /  \\/_ __ __ ___      _| | ___ _ __ \n");
    printf("| |   | '__/ _` \\ \\ /\\ / / |/ _ \\ '__|\n");
    printf("| \\__/\\ | | (_| |\\ V  V /| |  __/ |   \n");
    printf(" \\____/_|  \\__,_| \\_/\\_/ |_|\\___|_|   \n");
    printf("\n");
    printf("1- New Dungeon Run\n");
    printf("2-Exit\n");
    scanf(" %d",&op);

    switch(op)
    {
        case 1:

            //Nome do heroi

            printf("Nome do Heroi:\n");
            scanf("%s",nomeheroi);
            system("cls");

            //Inicia jogo

            while(gameover != 1){
            recivegameover = onBattle(level,nomeheroi);
            if(recivegameover == 0)
                {
                    level += 1;
                    gameover = 0;
                    onStats();
                }
            else if(recivegameover == 1)
                {

                    gameover = 1;
                    printf("Game Over\n");
                }

        }
        break;

        case 2:
            system("pause");
        break;

        default:
            printf("Entre uma opcao valida\n");
        break;

    }
system("pause");
}
