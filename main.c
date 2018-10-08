/*
    Autor: YAMB <c@yamb.codes>
    Datum: 07.10.2018
    KiW Kapitel 30 - Der Neubeginn -
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXCHARLENGTH 255
#define SATZ1 "Heute will ich keine Entscheidungen selber treffen"
#define SATZ2 "Wenn ich keine Entscheidung selber treffe, ist dies der Tag, der mir zuteil wird."
#define SATZ3 "Ich habe keine Frage. Ich habe vergessen, was ich entscheiden soll."
#define SATZ4 "Wenigstens kann ich entscheiden, dass ich nicht mag, was ich gerade jetzt empfinde. "
#define SATZ5 "Und ich hoffe deshalb, dass ich unrecht hatte."
#define SATZ6 "Ich möchte dies auf andere Weise sehen."
#define SATZ7 "Vielleicht gibt es eine andere Weise, dies anzusehen.\nWas kann ich dabei verlieren, wenn ich frage?"
#define NSATZ1 "Bedenke welche Art von Tag du haben möchtest, und sage dir, dass eine Möglichkeit besteht, dank welcher dieser Tag gerade so verlaufen kann. Und dann versuche wieder, den Tag zu haben, den du haben willst."
#define NSATZ2 "Sage dir tagsüber - immer, wenn du daran denkst und einen Augenblick der Ruhe zur Besinnung hast - noch einmal, welche Art von Tag du haben willst, welche Gefühle du empfinden möchtest, was dir geschehen soll und welche Dinge du erfahren möchtest"
#define NSATZ3 "Werde dir klar darüber, dass du von dir aus eine Frage formuliert hast und eine Antwort nach eigenem Ermessen vorgegeben haben musst."
#define NSATZ4 "Soviel steht fest, und damit wird der Weg geebnet für den nächsten leichten Schritt."
#define NSATZ5 "Das wirkt dem Gefühl des Widerstands entgegen, das du empfindest, und erinnert dich daran, dass die Hilfe dir nicht aufgedrängt wird."
#define NSATZ6 "Jetzt hast du dein Denken über diesen Tag geändert und hast dich daran erinnert, was du wirklich willst."
#define NSATZ7 "So kannst du nun eine sinnvolle Frage stellen, und damit wird die Antwort gleichfalls Sinn ergeben."


struct saetze{

    char hauptsatz[MAXCHARLENGTH];
    char nebensatz[MAXCHARLENGTH];

};

void askFrame( unsigned short *const asker );
void showFrames( const struct saetze *const strptr, const unsigned short *const asker );

int main()
{
    unsigned short asker=0;
    struct saetze ekiw[7];
    struct saetze *strptr = ekiw;

    system("clear");

    printf(" D E R   N E U B E G I N N\n\n\n");
    printf(" B E K Ä M P F E   D I C H   N I C H T   S E L B S T !\n\n\n");
    sleep(1);

    strncpy(ekiw[0].hauptsatz, SATZ1, MAXCHARLENGTH);
    strncpy(ekiw[1].hauptsatz, SATZ2, MAXCHARLENGTH);
    strncpy(ekiw[2].hauptsatz, SATZ3, MAXCHARLENGTH);
    strncpy(ekiw[3].hauptsatz, SATZ4, MAXCHARLENGTH);
    strncpy(ekiw[4].hauptsatz, SATZ5, MAXCHARLENGTH);
    strncpy(ekiw[5].hauptsatz, SATZ6, MAXCHARLENGTH);
    strncpy(ekiw[6].hauptsatz, SATZ7, MAXCHARLENGTH);
    strncpy(ekiw[0].nebensatz, NSATZ1, MAXCHARLENGTH);
    strncpy(ekiw[1].nebensatz, NSATZ2, MAXCHARLENGTH);
    strncpy(ekiw[2].nebensatz, NSATZ3, MAXCHARLENGTH);
    strncpy(ekiw[3].nebensatz, NSATZ4, MAXCHARLENGTH);
    strncpy(ekiw[4].nebensatz, NSATZ5, MAXCHARLENGTH);
    strncpy(ekiw[5].nebensatz, NSATZ6, MAXCHARLENGTH);
    strncpy(ekiw[6].nebensatz, NSATZ7, MAXCHARLENGTH);
    
    askFrame(&asker);
    showFrames(strptr, &asker);
    system("clear");
    
    return 0;

}

void showFrames( const struct saetze *const strptr, const unsigned short *const asker ){

    char term;
    unsigned short a = (*asker==1) ? (0) : ((*asker==2) ? (2) : (3));
    unsigned short e = (*asker==1) ? (2) : ((*asker==2) ? (3) : (7));

    for(int i = a; i < e; i++){

        system("clear");
        printf("%s\n\n", &strptr[i].hauptsatz);
        sleep(1);
        printf("%s\n\n", &strptr[i].nebensatz);
        scanf("%c", &term);

    }

}

void askFrame( unsigned short *const asker ){

    char term;

    printf(" B I T T E   A U S W Ä H L E N:\n\n\n");
    sleep(1);
    printf(" 1. Der Widerstand ist stark und die Hingabe schwach.\n\n");
    printf(" 2. Ich habe bereits geurteilt und die Antwort wird Angriff provozieren.\n\n");
    printf(" 3. Ich kann jetzt nicht von meiner Frage lassen!\n\n\n > ");

    if(scanf("%hu%c", asker, &term) != 2 || term != '\n'){

            *asker=1;

    }

    *asker = (*asker > 3 || *asker < 1) ? (1) : (*asker);

}
