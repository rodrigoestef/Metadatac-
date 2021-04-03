#include <stdio.h>
#include <Metadata.h>
int main()

{
    Metadata *meta = new Metadata();
    meta->set((char *)"nome", (void *)"rodrigo");
    meta->set((char *)"sobrenome", (void *)"estef");
    printf("%s\n", meta->get((char *)"nome"));
    printf("%s\n", meta->get((char *)"sobrenome"));
    //overwrite test
    meta->set((char *)"nome", (void *)"abcde");
    printf("%s\n", meta->get((char *)"nome"));
}