#include<stdio.h>

int x, a, b, c, p;

int main() {
    scanf("%d%d%d%d", &x, &a, &b, &c);
    while (x > 0) {
        a++; p++; x--;
        if (a==35) { a=0; x+=30; }
        if (!x) break;
        
        b++; p++; x--;
        if (b==100) { b=0; x+=60; }
        if (!x) break;
        
        c++; p++; x--;
        if (c==10) { c=0; x+=9; }
        if (!x) break;
    }
    
    printf("Martha plays %d times before going broke." ,p);
}
