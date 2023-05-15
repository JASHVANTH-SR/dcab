#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for symbol table entry
typedef struct {
    char name[32];
    char type[32];
    char value[32];
    int address;
    char scope[32];
} symbol;

int hash(char* name) {
    int sum = 0;
    for (int i = 0; i < strlen(name); i++) {
        sum += name[i];
    }
    return sum % 100;
}

// Function to insert a new entry into the symbol table
void insert(symbol* table[], char* name, char* type, char* value, int address, char* scope) {
    symbol* entry = (symbol*) malloc(sizeof(symbol));
    strcpy(entry->name, name);
    strcpy(entry->type, type);
    strcpy(entry->value, value);
    entry->address = address;
    strcpy(entry->scope, scope);

    int index = hash(name);
    while (table[index] != NULL) {
        index++;
    }
    table[index] = entry;
}

// Function to search for an entry in the symbol table
symbol* search(symbol* table[], char* name) {
    int index = hash(name);
    while (table[index] != NULL) {
        if (strcmp(table[index]->name, name) == 0) {
            return table[index];
        }
        index++;
    }
    return NULL;
}

// Function to delete an entry from the symbol table
void delete(symbol* table[], char* name) {
    int index = hash(name);
    while (table[index] != NULL) {
        if (strcmp(table[index]->name, name) == 0) {
            table[index] = NULL;
            break;
        }
        index++;
    }
}

// Function to print the entire symbol table
void display(symbol* table[]) {
    printf("Name\tType\tValue\tAddress\tScope\n");
    for (int i = 0; i < 100; i++) {
        if (table[i] != NULL) {
            printf("%s\t%s\t%s\t%d\t%s\n", table[i]->name, table[i]->type, table[i]->value, table[i]->address, table[i]->scope);
        }
    }
}

// Hash function to generate an index for a given name

int main() 
{
    symbol* table[100];
    for (int i = 0; i < 100; i++) {
        table[i] = NULL;
    }

    // Example usage
    insert(table, "x", "int", "5", 1000, "global");
    insert(table, "y", "float", "3.14", 2000, "global");
    insert(table, "z", "char", "'a'", 3000, "local");
    display(table);

    symbol* entry = search(table, "y");
    if (entry != NULL) {
        printf("Found: %s %s %s %d %s\n", entry->name, entry->type, entry->value, entry->address, entry->scope);
} else {
printf("Not found\n");
}
}
