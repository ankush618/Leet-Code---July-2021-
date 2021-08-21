class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int n=mat.length;
        int m=mat[0].length;
        if(m*n!=r*c)
            return mat;
        int [][] newmat = new int[r][c];
        
        int sc=0,sr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sc==c){
                    sr++;
                    sc=0;
                }
                newmat[sr][sc]=mat[i][j];
                sc++;
            }
        }
        return newmat;
    }
}
//code by shreyashi bansal
