#include "pch.h"
#include "FindLongestWordList.h"
#include "ReadFile.h"

bool isIsolated[MAX_VERTEX] = { 0 };
Graph CreateGraph(vector<string> words)
{
	Graph G = (Graph)malloc(sizeof(struct GNode));
	if (!G)
	{
		cout << "there is no enough space" << endl;
		exit(0);
	}
	G->vertex = words.size();
	G->hasList = false;
	G->withCircle = false;
	for (int i = 0; i < G->vertex; i++)
	{
		bool isolated = true;
		for (int j = 0; j < G->vertex; j++)
		{
			if (i == j)
			{
				G->matrix[i][j] = 0;
			}
			else
			{
				if (words[i][words[i].length() - 1] == (words[j][0]))
				{
					G->matrix[i][j] = 1;
					G->hasList = true;
					isolated = false;
				}
				else
				{
					G->matrix[i][j] = 0;
				}
			}
		}
		if (isolated)
		{
			isIsolated[i] = true;
		}
	}
	return G;
}


int visited[MAX_VERTEX] = { 0 };	//unvisited
void hasCircle(Graph G, int v)
{
	visited[v] = -1;	//being visited
	for (int i = 0; i < G->vertex; i++)
	{
		if (G->matrix[v][i] == 1 && visited[i] == 0)
		{
			hasCircle(G, i);
			visited[i] = 1;		//visited
		}
		if (G->matrix[v][i] == 1 && visited[i] == -1)
		{
			G->withCircle = true;
			return;
		}
		if (G->withCircle)
		{
			return;
		}
	}
}

int r_visited[MAX_VERTEX] = { 0 };
vector<int> word_list;
vector<int> ans;
void DFS(Graph G, int v, vector<string> words, char tail)
{
	r_visited[v] = 1;
	word_list.push_back(v);
	for (int i = 0; i < G->vertex; i++)
	{
		if (G->matrix[v][i] == 1 && r_visited[i] == 0)
		{
			DFS(G, i, words, tail);
		}
	}
	if (tail != 0 && words[v].at(words[v].length() - 1) != tail)
	{
		word_list.pop_back();
		r_visited[v] = 0;
		return;
	}
	if (word_list.size() > ans.size())
	{
		ans = word_list;
	}
	word_list.pop_back();
	r_visited[v] = 0;
}

int max_length = 0;
int current_length = 0;
void DFS_Length(Graph G, int v, vector<string> words, char tail)
{
	r_visited[v] = 1;
	word_list.push_back(v);
	current_length += words[v].length();
	for (int i = 0; i < G->vertex; i++)
	{
		if (G->matrix[v][i] == 1 && r_visited[i] == 0)
		{
			DFS_Length(G, i, words, tail);
		}
	}
	if (tail != 0 && words[v].at(words[v].length() - 1) != tail)
	{
		word_list.pop_back();
		current_length -= words[v].length();
		r_visited[v] = 0;
		return;
	}
	if (current_length > max_length)
	{
		max_length = current_length;
		ans = word_list;
	}
	word_list.pop_back();
	current_length -= words[v].length();
	r_visited[v] = 0;
}

int dist[MAX_VERTEX][MAX_VERTEX];
int path[MAX_VERTEX][MAX_VERTEX];
int getListWithWord(vector<string> words, int len, vector<string> &answer, char head, char tail, bool enable_loop)
{
	if (enable_loop)
	{
		Graph G = CreateGraph(words);

		if (!G->hasList)
		{
			cout << "Invalid File! There is no word list in the file." << endl;
			exit(0);
		}

		for (int i = 0; i < G->vertex; i++)
		{
			if (isIsolated[i])
			{
				continue;
			}
			if (head != 0 && words[i].at(0) != head)
			{
				continue;
			}
			DFS(G, i, words, tail);
		}

		int size = ans.size();
		for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		{
			answer.push_back(words[*i]);
		}
		return size;
	}

	else
	{
		ReduceWords(words);
		Graph G = CreateGraph(words);

		if (!G->hasList)
		{
			cout << "Invalid File! There is no word list in the file." << endl;
			exit(0);
		}

		hasCircle(G, 0);
		if (G->withCircle)
		{
			cout << "Invalid File! The words can form words ring." << endl;
			exit(0);
		}

		for (int i = 0; i < G->vertex; i++)
		{
			for (int j = 0; j < G->vertex; j++)
			{
				path[i][j] = j;

				if (i == j)
				{
					dist[i][j] = 0;
					continue;
				}

				dist[i][j] = (G->matrix[i][j] == 1) ? 1 : INF;
			}
		}

		for (int k = 0; k < G->vertex; k++)
		{
			if (isIsolated[k])
			{
				continue;
			}
			for (int i = 0; i < G->vertex; i++)
			{
				if (isIsolated[i])
				{
					continue;
				}
				for (int j = 0; j < G->vertex; j++)
				{
					if (dist[i][k] == INF || dist[k][j] == INF)
						continue;

					if (dist[i][k] + dist[k][j] > dist[i][j] || dist[i][j] == INF)
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = path[i][k];
					}
				}
			}
		}

		int start = 0;
		int end = 0;
		int max = 0;
		for (int i = 0; i < G->vertex; i++)
		{
			if (isIsolated[i])
			{
				continue;
			}

			for (int j = 0; j < G->vertex; j++)
			{
				if (dist[i][j] == INF)
					continue;

				if (head != 0 && words[i].at(0) != head)
					continue;

				if (tail != 0 && words[j].at(words[j].length() - 1) != tail)
					continue;

				if (dist[i][j] > max)
				{
					max = dist[i][j];
					start = i;
					end = j;
				}
			}
		}

		int list_length = 1;
		while (start != end)
		{
			answer.push_back(words[start]);
			start = path[start][end];
			list_length++;
		}
		answer.push_back(words[end]);
		return list_length;
	}
}


int getListWithLength(vector<string> words, int len, vector<string> &answer, char head, char tail, bool enable_loop)
{
	if (enable_loop)
	{
		Graph G = CreateGraph(words);

		if (!G->hasList)
		{
			cout << "Invalid File! There is no word list in the file." << endl;
			exit(0);
		}

		for (int i = 0; i < G->vertex; i++)
		{
			if (isIsolated[i])
			{
				continue;
			}
			if (head != 0 && words[i].at(0) != head)
			{
				continue;
			}
			DFS_Length(G, i, words, tail);
		}

		int size = ans.size();
		for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		{
			answer.push_back(words[*i]);
		}
		return size;
	}

	else
	{
		ReduceWords(words);
		Graph G = CreateGraph(words);

		if (!G->hasList)
		{
			cout << "Invalid File! There is no word list in the file." << endl;
			exit(0);
		}


		hasCircle(G, 0);
		if (G->withCircle)
		{
			cout << "Invalid File! The words can form words ring." << endl;
			exit(0);
		}

		for (int i = 0; i < G->vertex; i++)
		{
			for (int j = 0; j < G->vertex; j++)
			{
				path[i][j] = j;

				if (i == j)
				{
					dist[i][j] = 0;
					continue;
				}

				dist[i][j] = (G->matrix[i][j] == 1) ? words[j].length() : INF;
			}
		}

		for (int k = 0; k < G->vertex; k++)
		{
			if (isIsolated[k])
			{
				continue;
			}

			for (int i = 0; i < G->vertex; i++)
			{
				if (isIsolated[i])
				{
					continue;
				}

				for (int j = 0; j < G->vertex; j++)
				{
					if (dist[i][k] == INF || dist[k][j] == INF)
						continue;

					if (dist[i][k] + dist[k][j] > dist[i][j] || dist[i][j] == INF)
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = path[i][k];
					}
				}
			}
		}

		int start = 0;
		int end = 0;
		int max = 0;
		for (int i = 0; i < G->vertex; i++)
		{
			if (isIsolated[i])
			{
				continue;
			}

			for (int j = 0; j < G->vertex; j++)
			{
				if (dist[i][j] == INF)
					continue;

				if (head != 0 && words[i].at(0) != head)
					continue;

				if (tail != 0 && words[j].at(words[j].length() - 1) != tail)
					continue;

				if (dist[i][j] + (int)words[i].length() > max)
				{
					max = dist[i][j] + words[i].length();
					start = i;
					end = j;
				}
			}
		}

		int list_length = 1;
		while (start != end)
		{
			answer.push_back(words[start]);
			start = path[start][end];
			list_length++;
		}
		answer.push_back(words[end]);
		return list_length;
		return 0;
	}
}


int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	vector<string> words_vec;
	vector<string> ans;
	for (int i = 0; i < len; i++)
	{
		string s = words[i];
		words_vec.push_back(s);
	}
	int length = getListWithWord(words_vec, len, ans, head, tail, enable_loop);
	for (int i = 0; i < length; i++)
	{
		string s = ans[i];
		strcpy_s(result[i], s.length() + 1, s.c_str());
	}
	return length;
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	vector<string> words_vec;
	vector<string> ans;
	for (int i = 0; i < len; i++)
	{
		string s = words[i];
		words_vec.push_back(s);
	}
	int length = getListWithLength(words_vec, len, ans, head, tail, enable_loop);
	for (int i = 0; i < length; i++)
	{
		string s = ans[i];
		strcpy_s(result[i], s.length() + 1, s.c_str());
	}
	return length;
}