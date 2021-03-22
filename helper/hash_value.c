#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;

struct node {
	int key;
	int value;
	struct node* next;
};

struct bucket {
	struct node* head;
	int count;
};

struct node* createNode(int key, int value)
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

int hashFuction(int key)
{
	return key % SIZE;
}

void insert(int key, int value)
{
	int hashIndex = hashFuction(key);
	struct node* newNode = createNode(key, value);

	if (hashTable[hashIndex].count == 0) {
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count=1;
	}
	else {
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count ++;
	}
	return;
}

void removeNode(int key)
{
	int hashIndex = hashFuction(key);
	struct node* nowNode = hashTable[hashIndex].head;
	struct node* beforeNode = NULL;

	if (nowNode == NULL) {
		printf("no no no\n");
		return;
	}

	while (nowNode != NULL) {
		if (nowNode->key == key) {
			if (nowNode != hashTable[hashIndex].head) {
				beforeNode->next = nowNode->next;
			}
			else {
				hashTable[hashIndex].head = nowNode->next;
			}
			hashTable[hashIndex].count--;
			free(nowNode);
			break;
		}

		beforeNode = nowNode;
		nowNode = nowNode->next;
	}
	printf("no key in here\n");
	return;
}

void searchNode(int key)
{
	int hashIndex = hashFuction(key);
	struct node* nowNode = hashTable[hashIndex].head;
	if (nowNode == NULL) {
		printf("no data, search fuction\n");
	}

	while (nowNode != NULL) {
		if (nowNode->key == key) {
			printf("find data key-[%d], value-[%d]\n", 
				nowNode->key, nowNode->value);
			break;
		}
		nowNode = nowNode->next;
	}

	printf("search all data, but not here.\n");
	return;

}
