#include <stdio.h>
#include "card.h"

struct Card output_cards[10][20][10];
struct Card cards_list[10][20];
int _id_ = -1;

void init_cards_list()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cards_list[i][j].suit = 0;
            cards_list[i][j].rank = 0;
        }
    }
}

void init_output_cards()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                output_cards[i][j][k].suit = 0;
                output_cards[i][j][k].rank = 0;
            }
        }
    }
}

void PrintCards_list()
{
    for (int id = 0; id < 4; id++)
    {
        printf("id = %d\n", id);
        for (int i = 0; i < 20; i++)
        {
            if (cards_list[id][i].suit != 0)
            {
                printf("%d(%d, %d) ", i, cards_list[id][i].suit, cards_list[id][i].rank);
            }
        }
        puts("");
    }
}

void SortAndPrint()
{
    for (int id = 0; id < 4; id++)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (output_cards[id][i][j].suit == 0 || output_cards[id][i][k].suit == 0)
                        continue;
                    if (output_cards[id][i][j].suit > output_cards[id][i][k].suit)
                    {
                        int tmp = output_cards[id][i][j].suit;
                        output_cards[id][i][j].suit = output_cards[id][i][k].suit;
                        output_cards[id][i][k].suit = tmp;
                    }
                }
            }

            // print solution
            for (int j = 0; j < 3; j += 2)
            {
                if (output_cards[id][i][j].suit == 5 || output_cards[id][i][j + 1].suit == 5)
                    ;
                else if (output_cards[id][i][j].suit != 0 && output_cards[id][i][j + 1].suit != 0)
                {
                    printf("%d (%d, %d) (%d, %d)\n", id, output_cards[id][i][j].suit, output_cards[id][i][j].rank, output_cards[id][i][j + 1].suit, output_cards[id][i][j + 1].rank);
                    for (int k = 0; k < 20; k++)
                    {
                        if ((output_cards[id][i][j].suit == cards_list[id][k].suit) && (output_cards[id][i][j].rank == cards_list[id][k].rank))
                        {
                            // printf("%d %d\n", output_cards[id][i][j].suit, k);
                            for (int l = k; l < 19; l++)
                            {
                                cards_list[id][l].suit = cards_list[id][l + 1].suit;
                                cards_list[id][l].rank = cards_list[id][l + 1].rank;
                            }
                            // PrintCards_list();
                        }
                    }
                    for (int k = 0; k < 20; k++)
                    {
                        if (output_cards[id][i][j + 1].suit == cards_list[id][k].suit && output_cards[id][i][j + 1].rank == cards_list[id][k].rank)
                        {
                            // printf("%d %d\n", output_cards[id][i][j + 1].suit, k);
                            for (int l = k; l < 19; l++)
                            {
                                cards_list[id][l].suit = cards_list[id][l + 1].suit;
                                cards_list[id][l].rank = cards_list[id][l + 1].rank;
                            }
                            // PrintCards_list();
                        }
                    }
                }
            }
        }
    }
}

void init_cards(struct Card cards[53])
{
    init_cards_list();
    init_output_cards();
    // PrintCards_list();
    _id_ = -1;

    int flag = 0;
    for (int id = 0; id < 4; id++)
    {
        for (int i = flag + 13 * id; i <= 13 * (id + 1); i++)
        {
            cards_list[id][i - (flag + 13 * id)].suit = cards[i].suit;
            cards_list[id][i - (flag + 13 * id)].rank = cards[i].rank;
            for (int j = 0; j < 4; j++)
            {
                if (output_cards[id][cards[i].rank][j].suit == 0)
                {
                    output_cards[id][cards[i].rank][j].suit = cards[i].suit;
                    output_cards[id][cards[i].rank][j].rank = cards[i].rank;
                    // printf("%d (%d, %d)\n", id, output_cards[id][cards[i].rank][j].suit, output_cards[id][cards[i].rank][j].rank);
                    break;
                }
            }
        }
        flag = 1;
    }
    // PrintCards_list();

    SortAndPrint();
    // PrintCards_list();
    // puts("");

    return;
}
void draw_card(int idx)
{
    _id_ += 1;
    int id = _id_ % 4, cards_list_id_len = 0;
    struct Card tmp_card;
    // PrintCards_list();
    // puts("");
    for (int i = 0; i < 20; i++)
    {
        if (cards_list[id][i].suit == 0)
        {
            cards_list_id_len = i;
            break;
        }
    }
    // printf("%d\n", cards_list_id_len);

    // int _idx_ = idx % cards_list_id_len;
    int _idx_ = idx;
    if (idx >= cards_list_id_len || cards_list_id_len == 0)
    {
        _id_ -= 1;
        return;
    }
    // search for idx
    tmp_card.suit = cards_list[id][_idx_].suit;
    tmp_card.rank = cards_list[id][_idx_].rank;
    for (int i = _idx_; i < 19; i++)
    {
        cards_list[id][i].suit = cards_list[id][i + 1].suit;
        cards_list[id][i].rank = cards_list[id][i + 1].rank;
    }
    for (int i = 0; i < 20; i++)
    {
        if (cards_list[(id + 1) % 4][i].suit == 0)
        {
            cards_list[(id + 1) % 4][i].suit = tmp_card.suit;
            cards_list[(id + 1) % 4][i].rank = tmp_card.rank;
            break;
        }
    }

    init_output_cards();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (output_cards[i][cards_list[i][j].rank][k].suit == 0)
                {
                    output_cards[i][cards_list[i][j].rank][k].suit = cards_list[i][j].suit;
                    output_cards[i][cards_list[i][j].rank][k].rank = cards_list[i][j].rank;
                    // printf("%d (%d, %d)\n", id, output_cards[id][cards[i].rank][j].suit, output_cards[id][cards[i].rank][j].rank);
                    break;
                }
            }
        }
    }

    SortAndPrint();
    // PrintCards_list();
    // puts("");
    // puts("");

    return;
}
