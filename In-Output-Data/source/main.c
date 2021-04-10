#include <stdio.h>
#include <stdlib.h>
#include "card.h"

int main()
{
    char cmd;
    while (scanf("%c", &cmd) != EOF)
    {
        if (cmd == 'i')
        {
            struct Card cards[53];
            for (int i = 0; i < 53; i++)
                scanf("%d %d", &cards[i].suit, &cards[i].rank);
            init_cards(cards);
        }
        else if (cmd == 'd')
        {
            int idx;
            scanf("%d", &idx);
            draw_card(idx);
        }
    }

    return 0;
}
