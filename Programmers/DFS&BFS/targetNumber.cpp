#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target);
int dfs(int index, bool op, int cnum, vector<int> num, int t);

int main() {

	vector<int> numbers;
	int target;

	solution(numbers, target);
	return 0;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer += dfs(0, true, 0, numbers, target);
    answer += dfs(0, false, 0, numbers, target);

    return answer;
}

int dfs(int index, bool op, int cnum, vector<int> num, int t)
{
    int ans = 0;

    if (op) { cnum += num[index]; }
    else { cnum -= num[index]; }

    if (index == num.size()-1) {
        if (cnum == t) { return 1; }
        else { return 0; }
    } else {

        ans += dfs(index+1, true, cnum, num, t);
        ans += dfs(index+1, false, cnum, num, t);
        return ans;
    }

    return 0;
}
