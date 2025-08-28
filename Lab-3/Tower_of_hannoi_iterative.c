#include <stdio.h>
#include <math.h>

void move(int disk, char from, char to) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void moveBetweenPoles(int *srcTop, int *destTop, char s, char d) {
    if (*srcTop == 0) {  
        move(*destTop, d, s);
        *srcTop = *destTop;
        *destTop = 0;
    } 
    else if (*destTop == 0) {  
        move(*srcTop, s, d);
        *destTop = *srcTop;
        *srcTop = 0;
    } 
    else if (*srcTop > *destTop) {  
        move(*destTop, d, s);
        *srcTop = *destTop;
        *destTop = 0;
    } 
    else {
        move(*srcTop, s, d);
        *destTop = *srcTop;
        *srcTop = 0;
    }
}

void tower_of_hanoi(int n, char src, char aux, char dest) {
    int totalMoves = pow(2, n) - 1;
    int sTop = n, aTop = 0, dTop = 0;
    if (n % 2 == 0) {
        char temp = dest;
        dest = aux;
        aux = temp;
    }
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetweenPoles(&sTop, &dTop, src, dest);
        } else if (i % 3 == 2) {
            moveBetweenPoles(&sTop, &aTop, src, aux);
        } else {
            moveBetweenPoles(&aTop, &dTop, aux, dest);
        }
    }
}

int main() {
    int disks;
    printf("Enter number of Disks: ");
    scanf("%d", &disks);
    printf("Steps to solve Tower of Hanoi:\n");
    tower_of_hanoi(disks, 'A', 'B', 'C');
    return 0;
}


int main() {
    int disks;
    printf("Enter number of Disks: ");
    scanf("%d", &disks);
    printf("The instructions to solve Tower of Hanoi are:\n");
    tower_of_hanoi(disks, 'A', 'B', 'C');    return 0;
}
