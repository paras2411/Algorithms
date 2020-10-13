#include<bits/stdc++.h>

using namespace std;

void Convexhull(vector<array<int, 2>> ps){

  int n = ps.size();
  int start = -1, prev = -1;

  vector<int> vertices;

  for(int i=0; i<n && i != start; i++){

    for(int j=0; j<n; j++){

      if(j == prev || j == i) continue;

      int right = 0, left = 0;
      for(int k=0; k<n; k++){

        if(i == k || j == k) continue;

        array<int, 2> a = ps[i], b = ps[j], p = ps[k];
        p[0] -= a[0];
        p[1] -= a[1];
        b[0] -= a[0];
        b[1] -= a[1];

        int cross_product = b[0] * p[1] - b[1] * p[0];

        right += (cross_product > 0);
        left += (cross_product < 0);
      }
      if(right == 0 || left == 0){
        if(start == -1) start = i;
        prev = i;
        i = j-1;
        if(j != start) vertices.push_back(j);
        break;
      }
    }
  }
  n = vertices.size();
  cout << "(" << ps[start][0] << ", " << ps[start][1] << ") -> ";
  for(int i=0; i<n; i++){
    cout << "(" << ps[vertices[i]][0] << ", " << ps[vertices[i]][1] << ") -> ";
  }
  cout << "(" << ps[start][0] << ", " << ps[start][1] << ")" << endl;
}

int main(){

  // vector<array<int, 2>> a = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
  //                     {3, 0}, {0, 0}, {3, 3}};

  vector<array<int, 2>> a = {{1, 3}, {5, 2}, {10, 11}, {7, 1}, {4, 4}, {100, 100}};

  Convexhull(a);

  return 0;
}
