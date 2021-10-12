//number of islands
//given a grid "1" and "0", continous 1's augments to make 1 group of island, find the number of islands.
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int m,n; cin >> m >> n;
	
	vector<vector<char>> grid;
	grid.assign(m,vector<char>(n,'0'));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x;
			cin >> x;
			grid[i][j] = x;
		}
	}
	vector<vector<bool>> vis;
	vis.assign(m,vector<bool>(n,0));
	vector<pair<int,int>> directions({{-1,0},{1,0},{0,-1},{0,1}});
	auto inBounds = [&] (int row,int col){
		return row>=0 and col>=0 and row<m and col<n;
	};

	int answer = 0;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == '1' and vis[i][j]!=true){
				answer++; //we believe that when we see a component of unseen group, we increment ans++ and believe that all connected parts will be visited and marked 1.
			
				queue<pair<int,int>> q;
				q.push({i,j});
				vis[i][j] = true;	
				while(!q.empty()){
					pair<int,int> p = q.front(); q.pop();

	
					for(auto dir : directions){
						int newrow = p.first + dir.first;
						int newcol = p.second + dir.second;

						if(inBounds(newcol,newrow)){
							if(grid[newrow][newcol]=='1' and !vis[newrow][newcol]){
								q.push({newrow,newcol});
								vis[newrow][newcol] = true;
							}
						}

					}
				}

			}
		}
	}
 	cout << answer << endl;
		
}
