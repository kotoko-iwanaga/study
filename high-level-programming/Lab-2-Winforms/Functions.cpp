#include "Functions.h"
#include <vector>

bool rowByDecrease(std::vector<std::vector<int>>& matrix, int position) {
	for (int i = 0; i < matrix.size() - 1; i++) {
		if (matrix[i][position] <= matrix[i + 1][position]) {
			return false;
		}
	}
	return true;
}
int countRows(std::vector< std::vector<int> > &matrix) {
	int result = 0;
	if (matrix.size() < 2) {
		return -1;
	}
	for (int i = 0; i < matrix[0].size(); i++) {
		if (rowByDecrease(matrix, i) == true) {
			result++;
		}
	}
	return result;
}

void resizeMatrix(std::vector<std::vector<int>> &matrix, int N, int M) {
	matrix.resize(N);
	for (int i = 0; i < N; i++) {
		matrix[i].resize(M);
	}
}

