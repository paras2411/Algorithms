#include<bits/stdc++.h>
using namespace std;

typedef struct node{
  int x;
  int y;
  node* nxt;
  node* prev;
}point;

double y(point* p1, point* p2, double x){
  double a = p2->y - p1->y;
  double b = p1->x - p2->x;
  double c = a * (p1->x) + b * (p1->y);
  double cut = (c - a*(double)x) / b;
  return cut;
}

point* Convexhull(vector<array<int, 2>> &ps){

  int n = ps.size();
  if(n < 4){
    point *nod1 = new point();
    nod1->x = ps[0][0];
    nod1->y = ps[0][1];
    // cout << ps[0][0] << " " << ps[0][1] << endl;
    point *head = nod1;
    for(int i=1; i<n; i++){
      point *nod2 = new point();
      nod2->x = ps[i][0];
      nod2->y = ps[i][1];
      nod1->nxt = nod2;
      nod2->prev = nod1;
      nod1 = nod1->nxt;
      // cout << ps[i][0] << " " << ps[i][1] << endl;
    }
    // cout << endl;
    nod1->nxt = head;
    head->prev = nod1;
    return head;
  }

  vector<array<int, 2>> A, B;
  for(int i=0; i<n/2; i++){
    A.push_back(ps[i]);
  }
  double x = ((double)ps[n/2-1][0] + (double)ps[n/2][0])/2.0;   // the vertical axis where uppermost and lowermost cut is calculated
  for(int i=n/2; i<n; i++){
    B.push_back(ps[i]);
  }
  point *head1 = Convexhull(A);
  point *head2 = Convexhull(B);

  point *curr_A = head1;
  point *curr_B = head2;
  int max_x = curr_A->x, min_x = curr_B->x;

  while(curr_A->nxt != head1){
    curr_A = curr_A->nxt;
    max_x = max(max_x, curr_A->x);
  }
  while(curr_B->nxt != head2){
    curr_B = curr_B->nxt;
    min_x = min(min_x, curr_B->x);
  }
  curr_A = head1;
  curr_B = head2;
  while(curr_A->x != max_x) curr_A = curr_A->nxt;
  while(curr_B->x != min_x) curr_B = curr_B->nxt;

  point *temp_A = curr_A;
  point *temp_B = curr_B;

  while(y(curr_A->prev, curr_B, x) > y(curr_A, curr_B, x) || y(curr_A, curr_B->nxt, x) > y(curr_A, curr_B, x)){
    if(y(curr_A->prev, curr_B, x) > y(curr_A, curr_B, x)){
      curr_A = curr_A->prev;
    }
    else{
      curr_B = curr_B->nxt;
    }
  }
  point *a1 = curr_A;
  point *b1 = curr_B;  // points for uppermost cut

  curr_A = temp_A, curr_B = temp_B;

  while(y(curr_A->nxt, curr_B, x) < y(curr_A, curr_B, x) || y(curr_A, curr_B->prev, x) < y(curr_A, curr_B, x)){
    if(y(curr_A->nxt, curr_B, x) < y(curr_A, curr_B, x)){
      curr_A = curr_A->nxt;
    }
    else{
      curr_B = curr_B->prev;
    }
  }

  point *a2 = curr_A; // points for lowermost cut
  point *b2 = curr_B;

  // linking the nodes to form the final convex hull
  a1->nxt = b1;
  b1->prev = a1;
  b2->nxt = a2;
  a2->prev = b2;
  point *head = a1;


  return head;
}

int main(){

  vector<array<int, 2>> a = {{1, 3}, {5, 2}, {10, 11}, {7, 1}, {4, 4}, {100, 100}};

  sort(a.begin(), a.end());
  point *head = Convexhull(a);

  point *nod = head;
  cout << "(" << nod->x << ", " << nod->y << ") -> ";
  while(nod->nxt != head){
    nod = nod->nxt;
    cout << "(" << nod->x << ", " << nod->y << ") -> ";
  }
  cout << "(" << head->x << ", " << head->y << ")" << endl;
  return 0;
}
