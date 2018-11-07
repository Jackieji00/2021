#include <stdio.h>
#include <string.h>
#include "puzzle.h"

void phase1() {
    int a;
    float f;
    if(scanf("%d %f", &a, &f) != 2) {
        print_phase(1, 0);
        finish();
    }

    if(a != num) {
        print_phase(1, 0);
        finish();
    }

    int* x = (int*)(&f);
    if(a != *x) {
        print_phase(1, 0);
        finish();
    }

    print_phase(1, 1);
    pass_phase(1);
}

void phase3() {
    char str[50];
    int a;
    if(scanf("%49s %d", str, &a) != 2) {
        print_phase(3, 0);
        finish();
    }

    int len = strlen(str);
    if(len < 5) {
        print_phase(3, 0);
	    finish();
    }

    int total = 0;
    for(int i = 0; i < len; i++) {
        total += str[i];
    }

    if(a != total) {
        print_phase(3, 0);
	    finish();
    }

    print_phase(3, 1);
    pass_phase(3);
}

void phase4() {
    int a, b, c, d;
    if(scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
        print_phase(4, 0);
	    finish();
    }

    int targ = 
        1 << ((val % 6) + 24) |
    	1 << (val % 7) |
	    1 << ((val % 17) + 8);
    int comp =
        1 << (a+1) | 1 << (b-3) | 1 << (c+2) | 1 << d;

    if(targ != comp) {
        print_phase(4, 0);
	    finish();
    }

    print_phase(4, 1);
    pass_phase(4); 
}
