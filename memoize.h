#ifndef MEMOIZE_H
#define MEMOIZE_H
#define CACHE_SIZE 1500
extern char* memoized[CACHE_SIZE];
extern char* converter(int input_money);

char* memoize(int input_money);
void initialize_memo();
#endif
