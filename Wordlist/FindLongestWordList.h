#pragma once
#include "pch.h"
#include "Graph.h"

Graph CreateGraph(vector<string> words);
void hasCircle(Graph G, int v);
int getListWithWord(vector<string> words, int len, vector<string> &answer, char head, char tail, bool enable_loop);
int getListWithLength(vector<string> words, int len, vector<string> &answer, char head, char tail, bool enable_loop);
void DFS(Graph G, int v, vector<string> words, char tail);
void DFS_Length(Graph G, int v, vector<string> words, char tail);

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);