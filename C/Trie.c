#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Trie_Node
{
    struct Trie_Node *pointers[26];
    int word;
    int index;
} trie;

trie *createNode()
{
    trie *reference;
    reference = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++)
    {
        reference->pointers[i] = NULL;
    }
    reference->word = 0;
    reference->index = 0;
    return reference;
}
trie *root = NULL;
char String_Set[100][20] = {};
int stringsIndex = 0;

int Search_Trie(char string[])
{
    trie *cat = root;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        int ref = (int)(string[i] - 'a');
        if (cat->pointers[ref] == NULL)
            return 0;
        cat = cat->pointers[ref];
    }
    return 1;
}
void Insert_Trie(char string[])
{
    int length = strlen(string);
    trie *cat = root;
    for (int i = 0; i < length; i++)
    {
        int ref = (int)(string[i] - 'a');
        if (cat->pointers[ref] == NULL)
        {
            cat->pointers[ref] = createNode();
        }
        cat = cat->pointers[ref];
    }
    cat->word = 1;
    cat->index = stringsIndex;
    for (int i = 0; i < length; i++)
    {
        String_Set[stringsIndex][i] = string[i];
    }
    stringsIndex++;
}

void display(trie *root, char s[], int len)
{
    if (root->word)
    {
        s[len] = '\0';
        printf("%s\n", s);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->pointers[i] != NULL)
        {
            s[len] = i + 'a';
            display(root->pointers[i], s, len + 1);
        }
    }
}

int main()
{
    root = createNode();
    Insert_Trie("hello");
    Insert_Trie("fruit");
    Insert_Trie("renamed");
    int huh = Search_Trie("hello");

    char s[20];

    display(root, s, 0);

    if (huh == 1)
    {
        printf("Search Element Found \n");
    }
}