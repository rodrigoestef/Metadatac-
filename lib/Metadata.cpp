
#include "Metadata.h"
#define HASH_KEY 51241

Metadata::Metadata()
{
	memset(this->hashs, 0, sizeof(Node *) * ARRAY_SIZE);
}

uint8_t Metadata::createHash(char *key)
{
	uint64_t hashkey = 0;
	while (*key)
	{
		hashkey = (hashkey << 5) + HASH_KEY * *key;
		key++;
	}
	return hashkey % ARRAY_SIZE;
}

void *Metadata::get(char *key)
{
	uint8_t hash = this->createHash(key);
	Node *node = this->hashs[hash];
	while (node)
	{

		if (!strcmp(node->key, key))
		{
			return node->value;
		}
		node = node->Next;
	}
	return 0;
}

void Metadata::set(char *key, void *value)
{
	uint8_t hash = this->createHash(key);
	Node *node = this->hashs[hash];
	Node *nextElement = (Node *)malloc(sizeof(Node));
	nextElement->key = key;
	nextElement->value = value;
	nextElement->Next = 0;
	if (!node)
	{
		this->hashs[hash] = nextElement;
		return;
	}
	while (node)
	{
		if (node->key == key)
		{
			free(nextElement);
			node->value = value;
			return;
		}
		if (node->Next == 0)
		{
			node->Next = nextElement;
			return;
		}
		node = node->Next;
	}
}
