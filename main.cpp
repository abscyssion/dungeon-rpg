#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <conio.h>

using namespace std;
int text_speed=40;

string name;
int hp=50, maxhp=50;
int xp=1, maxexp=5, maxexp_i=1, lvl=1;
int base_base_attack=1, item_base_attack=0;
int money=0;
int stamina=100, max_stamina=100;


void w(string);
void command();
void add_exp(int);
void dungeon(string, int, int);
int main()
{
    srand (time(NULL));

    w("Welcome to the DungeonRPG!\n");
    w("Please type your name in:\n");
    putchar('>');
    cin >> name;
    system("CLS");
    w("Welcome "+name+"!\n");
    w("Type 'help' to see available commands.\n");
    command();
    return 0;
}

void w(string s)
{
    int n=s.length()-1;
    for(int i=0; i<=n; i++)
    {
        putchar(s[i]);
        Sleep(text_speed);
    }
}

void command()
{
    string c;
    char a;

    putchar('>');
    cin >> c;

    if(c=="help")
    {
        w("Available commands:\n");
        Sleep(500);
        w("help, tavern, dungeon, stats, inventory, clear, settings, inn\n");
        Sleep(200);
        w("Do you want to read available subcommands? Y/N:");

        a=getch();

        cout << endl;
        if(a=='y')
        {
            w("Available subcommands:\n");
            Sleep(500);
            w("dungeon: 'c' - continue battle; 'i' - view and use items, 'f' - flee from the battle ,'s' - see your current stats\n");
        }
    }

    else if(c=="settings")
    {
        short int setting;
        w("Which setting would you like to change?\n");
        w("0. Back\n");
        w("1. Text speed\n");
        putchar('>');
        setting_c:
        cin >> setting;
        switch(setting)
        {
            short int a;
            case 0:
            break;

            case 1:
            w("Text speed: \n");
            w("1. Fast, 2. Medium, 3. Slow\n");
            putchar('>'); cin >> a;
            text_speed=a*20;
            w("\nText speed has been changed.\n");
            command();
            break;

            default:
            goto setting_c;
            break;
        }
    }

    else if(c=="tavern")
    {
        string choice;
        w("You see a big tavern with sign saying 'The Broken Dagger Tavern.'\n");
        Sleep(700);
        w("You walk into the tavern. "); Sleep(500); w("You see a bar to the left, a casino to the right, and an exit behind you.\n");
        Sleep(400);
        w("Where do you want to go?\n");
        tavern_choice:
        putchar('>'); cin >> choice;

        if(choice=="bar")
        {
                bool dont_have_money=false;
                short int bar_index;
                Sleep(700);
                w("Bartender: Welcome to The Broken Dagger Tavern adventurer! "); Sleep(500); w("Hungry?\n\n");
                Sleep(400);
                w("Food:\n");
                Sleep(400);
                w("1. Triceratops steak - 50c\n2. Chicken eggs - 20c\n3. Gnomes' yogurt - 10c\n4. Raspberries - 5c\n5. Oatmeal - 7c\n\n");
                Sleep(600);
                w("Drinks:\n");
                Sleep(400);
                w("6. Spirit - 15c\n7.Ale - 10c\n8.Table Wine - 20c\n9. Lager: - 8c\n\n");
                Sleep(400);
                w("0 for exit.\n");

                bar_choice:
                putchar('>'); cin >> bar_index;

                switch(bar_index)
                {
                    case 0:
                    break;
                    case 1:
                    if(money>=50){hp+=75;
                    money-=50;}else{dont_have_money=1;}
                    break;
                    case 2:
                    if(money>=20){hp+=30;
                    money-=20;}else{dont_have_money=1;}
                    break;
                    case 3:
                     if(money>=10){hp+=15;
                    money-=10;}else{dont_have_money=1;}
                    break;
                    case 4:
                     if(money>=5){hp+=8;
                    money-=5;}else{dont_have_money=1;}
                    break;
                    case 5:
                     if(money>=7){hp+=11;
                    money-=7;}else{dont_have_money=1;}
                    break;
                    case 6:
                     if(money>=15){hp+=22;
                    money-=15;}else{dont_have_money=1;}
                    break;
                    case 7:
                     if(money>=10){hp+=15;
                    money-=10;}else{dont_have_money=1;}
                    break;
                    case 8:
                     if(money>=20){hp+=30;
                    money-=20;}else{dont_have_money=1;}
                    break;
                    case 9:
                     if(money>=80){hp+=12;
                    money-=8;}else{dont_have_money=1;}
                    break;
                    default:
                    goto bar_choice;
                    break;
                }
                if(dont_have_money==false&&bar_index!=0){w("Bartender: Here you go!\n");}

                if(dont_have_money==true){w("Bartender: Don't bother me. Come with money next time.\n"); dont_have_money=false;}

        }
        else if(choice=="casino")
        {
        char a;
        w("You walk into the casino. "); Sleep(400); w("You see many slot machines.\n");
        w("Do you want to play? Y/N: "); a=getch();
        cout << endl;
        if(a=='y')
        {
            slots:
            int bet;
            string symbols[3];
            w("How much do you want to bet?\n");
            putchar('>'); cin >> bet;
            if(money>=bet&&bet>0)
            {
            w("Rolling"); Sleep(500); cout << ".";  Sleep(500); cout << ".";  Sleep(500); cout << ".\n\n";

            for(int i=0; i<=2; i++)
            {
            int randm=round(rand() % 101);

            if (randm < 50) {
			symbols[i]="\3";
            }
            else if (randm < 50 + 30) {
            symbols[i]="\5";
            }
            else if (randm < 50 + 30 + 20) {
            symbols[i]="7";
            }

            }

            cout << R"~(
 .-------------------.
| .-----------------. |
| |                 | |)~"<<endl;

cout << "| |  ["+symbols[0]+"]  ["+symbols[1]+"]  ["+symbols[2]+"]  | |";

    cout << R"~(
| |                 | |
| '-----------------' |
 '-------------------'
                )~"<<endl<<endl ;

                if(symbols[0]=="\3"&&symbols[1]=="\3"&&symbols[2]=="\3"){w("You won x1.5 coins!\n"); money+=bet*1.5;}
                else if(symbols[0]=="\5"&&symbols[1]=="\5"&&symbols[2]=="\5"){w("You won x2 coins!\n"); money+=bet*2;}
                else if(symbols[0]=="7"&&symbols[1]=="7"&&symbols[2]=="7"){w("Congratulations! You won x5 coins!\n"); money+=bet*5;}
                else{money-=bet;}
                Sleep(400);
                w("Your balance: "+to_string(money)+".\n");
                Sleep(500);
                slots2:
                w("Do you want to play again? Y/N");  a=getch(); cout << endl;
                if(a=='y'){goto slots;}
                else if(a=='n'){command();}
                else{goto slots2;}
            }
        else{w("You don't have enough money!\n"); goto slots2;}
        }
        }
        else if(choice=="exit")
        {
            command();
        }
        else{goto tavern_choice;}
    }

    else if(c=="dungeon")
    {
        if(stamina>=20)
        {
        stamina-=20;

        if(lvl>0){dungeon("Small Slime", 1, 4);}
        else if(lvl>=3){dungeon("Hungry Wolf", 6, 12);}
        else if(lvl>=5){dungeon("Stone Golem", 10, 18);}
        }
        else{w("You don't have enough stamina! You should take a nap in the local inn.\n");}
    }

    else if(c=="inn")
    {
        char a;
        w("Receptionist: Welcome to the Sunny Inn!"); Sleep(400); w(" Would you like to book a room?"); Sleep(500); w(" It will cost you 10c. Y/N:"); a=getch();
        cout<<endl;
        if(a=='y')
        {
            if(money>=10)
            {
            w("Receptionist: Here's your key.");Sleep(500); w("Goodnight!\n\n");
            Sleep(1000);
            cout<<"Z"; Sleep(400); cout<<"z"; Sleep(400); cout<<"Z"; Sleep(400); cout<<"z"; Sleep(400); cout<<"Z"; Sleep(400); cout<<"z"; Sleep(400); cout<<"Z"; Sleep(400); cout<<"z"; Sleep(400); cout<<"Z"; Sleep(400); cout<<"z"; Sleep(2000);
            stamina=max_stamina;
            money-=10;
            w("\n\nYou feel refreshed and full of energy.\n");
            command();
            }
            else{w("Receptionist: Sorry. You don't have enough money.\n"); command();}
        }
        else{command();}
    }


    else if(c=="clear")
    {
        system("CLS");
    }

    else if(c=="stats")
    {
        w(name+"'s stats:\n");
        w("HP: "+to_string(hp)+"/"+to_string(maxhp)+".\n");
        w("LVL: "+to_string(lvl)+", XP: "+to_string(xp)+"/"+to_string(maxexp)+".\n");
        w("Money: " +to_string(money)+".\n");
        w("Stamina: "+to_string(stamina)+"/"+to_string(max_stamina)+".\n");
    }
    else
    {
        w("No such command exist "+name+"!\n");
    }
    command();
}

void add_exp(int how_many)
{
    xp+=how_many;

    if(xp>=maxexp)
    {
        lvl++;
        maxexp_i++;
        maxexp=maxexp*maxexp_i;

        base_attack=lvl*2;
        w(name+" has leveled up! His/her level is now "+to_string(lvl)+".\n");
    }
}

void dungeon(string mob_name, int mob_lvl_min, int mob_lvl_max)
{
    char a;

    int mob_lvl = ceil(rand() % mob_lvl_max + mob_lvl_min);

    int mob_hp = mob_lvl*3;
    int mob_atk = mob_lvl*1.5;

    int dmg, mob_dmg;

    w(name+" walks into the dungeon...\n");
    Sleep(700);
    w("...and he/she encounters "+to_string(mob_lvl)+"lvl "+mob_name+"!\n");
    Sleep(500);
    while(true)
    {


        dung_choice:
        a=getch();

        if(a=='c'){}

        else if(a=='i')
        {
            w("Inventory: \n");
        }

        else if(a=='f')
        {
            w("Fleed from the battle!\n");
            command();
        }

        else if(a=='s')
        {
            w("HP: "+to_string(hp)+"/"+to_string(maxhp)+"\n");
            w("LVL: "+to_string(lvl)+", XP: "+to_string(xp)+"/"+to_string(maxexp)+"\n");
            w("Money: " +to_string(money)+"\n");
            goto dung_choice;
        }

        else
        {
            goto dung_choice;
        }

        mob_dmg = ceil(rand() % mob_atk+2 + mob_atk-1);
        w(mob_name+" deals "+to_string(mob_dmg)+" damage to "+name+"!\n");
        hp-=mob_dmg;
        Sleep(200);

        dmg = ceil(rand() % base_attack+2+1 + base_attack-1);
        w(name+" deals "+to_string(dmg)+" damage to "+mob_name+"!\n");
        mob_hp-=dmg;
        Sleep(200);

        if(hp<=0)
        {
            w(name+" has died... \n");
            Sleep(300);
            w("He/she has lost 50% of his money...\n");
            hp=hp/10;
            money=money/2;
            if(money<0){money=0;}
            command();
            break;
        }


        if(mob_hp<=0)
        {
            w(mob_name+" has been slain! "+name+" has earned "+to_string(mob_lvl*2)+" xp and "+to_string(mob_lvl*2)+" money!\n");
            add_exp(mob_lvl*2);
            money+=mob_lvl*2;
            command();
            break;
        }
    }
}
