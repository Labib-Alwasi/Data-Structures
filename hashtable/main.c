#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_STRING_SIZE 20 //max length of a string
#define ARRAY_SIZE 10      //best be prime

typedef struct Element person;
struct Element
{
    //TODO
    char name[MAX_STRING_SIZE];
    int age;
    //int count[ARRAY_SIZE]; nope
};

person *hashTable[ARRAY_SIZE];

unsigned int hash_function(char *name)
{
    int length = strnlen(name, ARRAY_SIZE); //why????????????????????????????????
    unsigned int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash += name[i];
        hash = (hash * name[i]) % ARRAY_SIZE;
    }
    return hash;
}

void init_hash()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
    //table is empty
}

void print_table()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("\t%i\t----\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
}

bool insert(person *name)
{
    if (name == NULL)
    {
        return false;
    }
    int index = hash_function(name->name);

    if (hashTable[index] != NULL)
    {
        return false;
    }
    hashTable[index] = name;
    return true;
}

person *search(char *name)
{
    int index = hash_function(name);
    if ((hashTable[index] != NULL) && 
      (strcmp(hashTable[index]->name, name) == 0))
    {
        return hashTable[index];
    }
    else
    {
        return NULL;
    }
}

int main()
{
    init_hash();

    person jacob = {.name = "Jacob", .age = 256};
    person kate = {.name = "Kate", .age = 27};
    person mpho = {.name = "Mpho", .age = 14};

    insert(&jacob);
    insert(&kate);
    insert(&mpho);
    print_table();

    person *tmp = search("Jacob");
    if (tmp == NULL)
    {
        printf("Couldn't find");
    }
    else
    {
        printf("Found it\n");
    }
    tmp = search("elizabeth");
    if (tmp == NULL)
    {
        printf("Couldn't find");
    }
    else
    {
        printf("Found it\n");
    }
}