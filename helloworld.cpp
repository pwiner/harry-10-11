#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct text;
typedef struct text text;

struct text
{
    int capacity;
    char *content;
};

// Create a new text structure, containing a copy of the given string.
text *newText(char *s)
{
    int size = 24;

    while (strlen(s) >= size)
        size *= 2;

    text *t = (text *)malloc(sizeof(text));

    *t = (text){size, (char *)malloc(size)};

    strcpy(t->content, s);
    return t;
}

void append(text *t1, text *t2)
{

    int size = 24;
    int targetSize = strlen(t1->content) + strlen(t2->content);

    while (targetSize >= size)
        size *= 2;

    t1->content = (char *)realloc(t1->content, size);
    t1->capacity = size;
    strcat(t1->content, t2->content);
}

int main()
{
    char s[100];

    strcpy(s, "Hello Boozer");
    text *t1 = newText(s);

    strcpy(s, " we love you, Boozer");
    text *t2 = newText(s);

    append(t1, t2);
}