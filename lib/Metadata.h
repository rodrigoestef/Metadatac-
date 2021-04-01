
#ifndef METADATA_H_
#define METADATA_H_
#include <stdlib.h>
#include <cstdint>
#include <cstring>
#include <string.h>
#define ARRAY_SIZE 100

struct Node
{
	char *key;
	void *value;
	Node *Next;
};

class Metadata
{
private:
	Node *hashs[ARRAY_SIZE];
	uint8_t createHash(char *key);

public:
	Metadata();
	void *get(char *key);
	void set(char *key, void *value);
};

#endif /* METADATA_H_ */