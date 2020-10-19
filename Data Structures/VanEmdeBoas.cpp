#include <bits/stdc++.h>
using namespace std;


typedef struct node{
  int min, max, siz;
  node* summary;
  vector<node*> clusters;

  node(int size)
  {
    siz = size;
    min = -1;
    max = -1;

    if (siz <= 2) {
      summary = NULL;
      clusters = vector<node*>(0, NULL);
      return;
    }

    int no_clusters = ceil(sqrt(size));
    summary = new node(no_clusters);
    clusters = vector<node*>(no_clusters, NULL);

    for (int i = 0; i < no_clusters; i++) {
      clusters[i] = new node(ceil(sqrt(size)));
    }

  }
}veb;


int high(int x, int size){
  int siz = ceil(sqrt(size));
  int i = x / siz;
  return i;
}
int low(int x, int size){
  int siz = ceil(sqrt(size));
  int j = x % siz;
  return j;
}

int index(int i, int j, int size){
  int siz = ceil(sqrt(size));
  int ind = i * siz + j;
  return ind;
}

/*
  Operations -> Insert, Successor, del
*/
void insert(veb* root, int key){

  if (root->min == -1) {

    root->min = key;
    root->max = key;
  }
  else {

    if (key < root->min) {
      swap(root->min, key);
    }

    if (key > root->max) {
      root->max = key;
    }

    if (root->siz > 2) {

      int i = high(key, root->siz);
      int j = low(key, root->siz);
      if (root->clusters[i]->min == -1) {

        insert(root->summary, i);
        root->clusters[i]->min = j;
        root->clusters[i]->max = j;
      }
      else {
        insert(root->clusters[i], j);
      }
    }

  }
}

int successor(veb* root, int key){

  if (root->siz == 2) {

    if (key == 0 && root->max == 1) {
      return 1;
    }
    else {
      return -1;
    }
  }

  else if (root->min != -1 && key < root->min) {

    return root->min;
  }
  else{

    int i = high(key, root->siz);
    int j = low(key, root->siz);

    if (root->clusters[i]->max != -1 && j < root->clusters[i]->max) {

      j = successor(root->clusters[i], j);
      return index(i, j, root->siz);
    }
    else {

      i = successor(root->summary, i);

      if (i == -1) {
        return -1;
      }
      else{

        j = root->clusters[i]->min;
        return index(i, j, root->siz);
      }
    }
  }
}

void del(veb* root, int key){

  if(root->max == root->min){

    root->min = -1;
    root->max = -1;
  }
  else if(root->siz == 2){

    if (key == 0){
      root->min = 1;
    }
    else{
      root->min = 0;
    }
    root->max = root->min;
  }
  else{

    int i = high(key, root->siz);
    int j = low(key, root->siz);

    if(key == root->min){

      int first_cluster = root->summary->min;
      key = index(first_cluster, root->clusters[first_cluster]->min, root->siz);
      root->min = key;
    }

    del(root->clusters[i], j);

    if(root->clusters[i]->min == -1){

      del(root->summary, i);
      if(key == root->max){

        int max_in_summary = root->summary->max;
        if (max_in_summary == -1) {

          root->max = root->min;
        }
        else {

          root->max = index(max_in_summary, root->clusters[max_in_summary]->max, root->siz);
        }
      }
    }
    else if (key == root->max) {

      root->max = index(i, root->clusters[i]->max, root->siz);
    }
  }
}

int main()
{

  veb* root = new veb(8);

  // Tests
  insert(root, 2);
  insert(root, 3);
  insert(root, 6);
  cout << root->min << " " << root->max << endl;
  del(root, 6);
  cout << root->min << " " << root->max << endl;
  insert(root, 7);
  insert(root, 5);
  cout << successor(root, 3) << endl;
  cout << successor(root, 7) << endl;

}
