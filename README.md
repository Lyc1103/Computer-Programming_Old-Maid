# Old Maid

> Author : Ya Chen<br>
> Date : 2021 / 4 / 3<br>
> List :
>
> > <a href = "#description">Description</a><br><a href = "#input">Input</a><br><a href = "#output">Output</a><br><a href = "#examples">Examples</a>

---

<div id = "description">

## Description

Bogay, who has very few friends, wants to play old maid with others. Can you write a program to help him? At least he can play with the computer…

</div>
<br>
<br>
<div id = "input">

## Input

<b>Note:</b> in you submission code, please add `#include "card.h"`, or you will get `CE`
in this problem, I declare a struct `Card` with below definition.

```c
struct Card
{
  int rank;
  int suit;
};
```

- `rank` is a number in `[1, 13]`
- `suit` is a number in `[1, 5]`, 1 ∼ 4 means hearts, diamonds, clubs and spades. If this card is joker, it will be 5.

You should implement 2 functions.

```c
void init_cards(struct Card cards[53]);
void draw_card(int idx);
```

- `init_cards` tells you what cards players hold, the first player (no. 0) has `cards[0...13]`, the second one has `cards[14...26]`, and the third one has `cards[27...39]`, fourth one has `cards[40...52]`. Be aware that this function may be called not only once. Each call means a new game start, so players’ hand will be reset by given argment, you can also handle other initialization you needs.
- `draw_card` means that, in this round, the `idx`-th card (starts from 0) is taken and insert to the end of the next player’s hand. The first call of this function takes a card from player 0 to player 1, and the second call is from 1 to 2, and so on. But note that if any player discards all of his hand, he/she should be skipped. If you receive an invalid `idx`, ignore it.

So, this problem I provide 2 files:

`card.h` :

```c
struct Card
{
    int rank;
    int suit;
};

void init_cards(struct Card cards[53]);
void draw_card(int idx);
```

and `main.c` :

```c
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
```

you should submit your implementation for `init_cards` and `draw_card`, don’t include main function or `Card` definition, etc. or you may get `CE`.

<br>

### Input Format

Each line means a function call in the below format:

```
cmd params
```

- `cmd` is a character either be `i` or `d`, means `init_cards` or `draw_card`, respectively.
- For command `i`, the `params` will contains 106 integers, each pair means the card suit and rank, e.g., hearts 4 will be <b>1 4</b>.
- For command `d`, `params` will be an integer that denotes `idx`.

</div>
<br>
<br>
<div id = "output">

## Output

In any moment, if a player has matched pairs so he/she can discard them, you should print the player id and these pairs in the below format:

```
player_id card_1 card_2
```

For single round of output, you should sort them by player id, and then card rank, lastly card suit.
For example, if <b>player 0</b> has cards `[(1,1),(2,1),(2,13),(3,13)]`, and <b>player 1</b> has cards `[(3,1),(4,1),(2,11),(1,11)]` (first number in parentheses means suit, second one is rank). You should print these lines.

```
0 (1, 1) (2, 1)
0 (2, 13) (3, 13)
1 (3, 1) (4, 1)
1 (1, 11) (2, 11)
```

</div>
<br>
<br>
<div id = "examples">

## Examples

### Input 1

```
i 1 11 2 7 4 6 1 12 3 6 3 2 4 10 1 4 4 11 5 0 4 1 3 3 2 10 4 3 2 3 1 6 3 10 2 2 2 11 2 13 3 12 3 1 1 1 1 13 2 8 1 5 2 4 1 2 1 8 4 7 4 5 3 5 2 9 4 12 1 7 4 4 4 13 3 7 4 8 4 9 2 12 2 6 1 9 3 9 1 10 3 4 1 3 2 5 3 8 3 13 2 1 4 2 3 111
```

### Output 1

```
0 (3, 3) (4, 3)
0 (3, 6) (4, 6)
0 (2, 10) (4, 10)
0 (1, 11) (4, 11)
1 (1, 1) (3, 1)
1 (1, 13) (2, 13)
2 (3, 5) (4, 5)
2 (1, 7) (3, 7)
2 (1, 8) (4, 8)
2 (2, 9) (4, 9)
3 (1, 9) (3, 9)
```

<br>

### Input 2

```
i 4 4 1 7 4 9 3 10 4 1 2 3 4 8 1 13 3 4 3 7 1 4 3 5 2 1 1 2 2 2 4 12 1 11 2 5 2 9 2 7 4 6 1 5 3 6 3 9 1 8 3 1 4 13 4 7 2 12 2 11 3 13 4 3 1 10 3 11 1 6 1 12 1 3 2 6 4 10 2 8 2 10 1 9 2 13 4 5 3 3 3 8 3 2 3 12 4 11 1 1 2 4 5 8 4 2
d 6
d 0
d 2
d 3
d 8
```

### Output 2

```
0 (2, 1) (4, 1)
0 (1, 4) (3, 4)
0 (1, 7) (3, 7)
1 (1, 5) (2, 5)
1 (3, 6) (4, 6)
1 (2, 9) (3, 9)
2 (1, 3) (4, 3)
2 (1, 6) (2, 6)
2 (1, 10) (4, 10)
2 (2, 11) (3, 11)
2 (1, 12) (2, 12)
3 (3, 2) (4, 2)
3 (2, 8) (3, 8)
```

<br>

### Input 3

```
i 3 12 3 9 3 11 1 13 2 8 2 9 3 5 2 5 2 10 4 10 2 7 1 1 4 9 2 2 3 2 3 13 2 4 1 5 4 1 4 2 3 3 1 4 4 6 1 9 3 7 1 12 4 4 4 5 2 13 4 7 5 6 4 3 1 7 4 8 3 1 1 10 2 11 4 11 3 10 1 2 1 11 2 12 3 8 2 6 3 4 3 6 4 12 2 3 2 1 4 13 1 3 1 6 1 8
d 0
d 1
d 9
d 5
d 0
```

### Output 3

```
0 (2, 5) (3, 5)
0 (2, 9) (3, 9)
0 (2, 10) (4, 10)
1 (3, 2) (4, 2)
1 (1, 4) (2, 4)
2 (1, 7) (4, 7)
2 (1, 10) (3, 10)
2 (2, 11) (4, 11)
3 (1, 3) (2, 3)
3 (1, 6) (2, 6)
3 (1, 8) (3, 8)
3 (2, 12) (4, 12)
1 (1, 12) (3, 12)
2 (1, 5) (4, 5)
0 (1, 11) (3, 11)
```

</div>
