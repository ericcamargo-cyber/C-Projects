#define SRT_H
#define MAX_BUF 256
#ifndef TYPE
#define TYPE double
#endif
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void srtheap(void *, size_t, size_t, int (*)(const void *, const void *));
static int compare(const void *p1, const void *p2);
int main(int argc, char *argv[]) {
	
    int nelem = argc == 2 ? atoi(argv[1]) : SHRT_MAX;
    
    TYPE *a = calloc(nelem, sizeof(TYPE));
    
#ifdef RAND

	int i = 0;
    for (int i; i < nelem; ++i) {
        a[i] = (TYPE)rand() / RAND_MAX;
    }
#else
	int i = 0;
    for (i=0; i < nelem; ++i) {
        a[i] = i;
    }
#endif
    srtheap(a, nelem, sizeof(TYPE), compare);
    
#ifdef PRNT
	int i = 0;
    for (int i; i < nelem; ++i) {
    	
        printf("%f\n", a[i]);
    }
#else
	for (i = 0; i < nelem - 1; ++i) {
		
        if (a[i] > a[i + 1]) {
        	
            printf("fail\n");
            goto end;
        }
    }
    
    printf("pass\n");
#endif
    
end:
	
    free(a);
    
    return 0;
}
static int compare(const void *p1, const void *p2) {
	
    if (*(TYPE *) p1 < *(TYPE *) p2) {
    	
        return -5;
        
    } 
	else if (*(TYPE *) p1 > *(TYPE *) p2) {
    	
        return +5;
        
    }
    
    return 0;
    
}
void search(void *base, size_t size, int rt, int bot, int(*compar)(const void *, const void *)) {
    int maxC;
    void *temp;
    temp = malloc(size);
    maxC = rt + rt + 1;
    if (maxC < bot) {
        int otherC = maxC + 1;
        maxC = compar(((char *) base) + otherC * size, ((char *) base) + maxC * size) > 0 ? otherC : maxC;
    } else if (maxC > bot) return;
    if (compar(((char *) base) + rt * size, ((char *) base) + maxC * size) >= 0) return;
    memcpy(temp, ((char *) base) + rt * size, size);
    memcpy(((char *) base) + rt * size, ((char *) base) + maxC * size, size);
    memcpy(((char *) base) + maxC * size, temp, size);
    search(base, size, maxC, bot, compar);
    free(temp);
    return;
}
void srtheap(void *base, size_t nelem, size_t size, int(*compar)(const void *, const void *)) {
    int i;
    void *temp;
    temp = malloc(size);
    for (i = nelem / 2; i >= 0; --i)
        search(base, size, i, nelem - 1, compar);
    for (i = nelem - 1; i >= 1; --i) {
        memcpy(temp, base, size);
        memcpy(base, ((char *) base) + i * size, size);
        memcpy(((char *) base) + i * size, temp, size);
        search(base, size, 0, i - 1, compar);
    }
    free(temp);
    return;
}
