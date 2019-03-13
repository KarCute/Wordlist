#pragma once

#define MAX_VERTEX 401//10001
#define INF 1000001
typedef struct GNode *Graph;
struct GNode
{
	bool hasList;
	bool withCircle;
	int vertex;
	int matrix[MAX_VERTEX][MAX_VERTEX];
};