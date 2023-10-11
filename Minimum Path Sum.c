//遞迴

int minPartialPathSum(int** grid,int row, int col, int** cache) {
    if (row==0 && col==0){
        return grid[0][0];
    }
    if (cache[row][col]!=0){
        return cache[row][col];
    }

    int min = INT_MAX;

    if(row-1>=0){
        int upMin = minPartialPathSum(grid,row-1, col, cache);
        if(upMin<min){
            min = upMin;
        }
    }

    if(col-1>=0){
        int leftMin = minPartialPathSum(grid,row, col-1, cache);
        if(leftMin<min){
            min = leftMin;
        }
    }

    cache[row][col]=min+grid[row][col];
    return cache[row][col];
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];

    int** cache = malloc(sizeof(int*)*m);
    for (int i=0;i<m;i++){
        cache[i] = calloc(n,sizeof(int));
    }
    int result = minPartialPathSum(grid,m-1,n-1,cache);
    for (int i=0;i<m;i++){
        free(cache[i]);
    }
    free(cache);
    return result;
}
