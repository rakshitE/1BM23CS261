// Java Program to solve the n-queens problem
import java.util.*;

class GfG {

    // Function to check if it is safe to place
    // the queen at board[row][col]
    static boolean isSafe(int[][] mat, 
                          	int row, int col) {
        int n = mat.length;

        // Check this col on upper side
        for (int i = 0; i < row; i++)
            if (mat[i][col] == 1)
                return false;

        // Check upper diagonal on left side
        for (int i = row - 1, j = col - 1; 
             		i >= 0 && j >= 0; i--, j--)
            if (mat[i][j] == 1)
                return false;

        // Check upper diagonal on right side
        for (int i = row - 1, j = col + 1;
             		j < n && i >= 0; i--, j++)
            if (mat[i][j] == 1)
                return false;

        return true;
    }

    static boolean placeQueens(int row, int[][] mat) {
        int n = mat.length;

        // base case: If all queens are placed
        // then return true
        if (row == n)
            return true;

        // Consider the row and try placing
        // queen in all columns one by one
        for (int i = 0; i < n; i++) {

            // Check if the queen can be placed
            if (isSafe(mat, row, i)) {
                mat[row][i] = 1;
                if (placeQueens(row + 1, mat))
                    return true;
                mat[row][i] = 0;
            }
        }
        return false;
    }

    // Function to find the solution
    // to the N-Queens problem
    static List<Integer> nQueen(int n) {

        // Initialize the board
        int[][] mat = new int[n][n];

        // If the solution exists
        if (placeQueens(0, mat)) {

            // to store the columns of the queens
            List<Integer> ans = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1) {
                        ans.add(j + 1);
                    }
                }
            }
          
            return ans;
        } 
      	else
            return Collections.singletonList(-1);
    }

    public static void main(String[] args) {
        int n = 4;
        List<Integer> ans = nQueen(n);
        for (int i : ans) {
            System.out.print(i + " ");
        }
    }
}
