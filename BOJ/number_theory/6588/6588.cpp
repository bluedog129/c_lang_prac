#include <stdio.h>
#include <string.h>

using namespace std;

void erasto(bool *check) {
    check[0] = false;
    check[1] = false;

    for (int i = 2; i * i < 1000001; i++) {
        if (check[i] == false) continue;
        
        for (int j = i * i; j < 1000001; j += i) {
            check[j] = false;
        }
    }
    // 2는 짝수이므로 골드바흐 추측의 연산에서 제외하여야 함
    check[2] = false;
}

int main() {
    bool flag = false;
    int n = 1;

    // 에라스토테네스로 소수인 수들 체크 해놓음
    bool check[1000001];
    memset(check, 1, sizeof(check));
    erasto(check);

    while(n) {
        // n받고
        scanf("%d", &n);

        // 입력 받은 값을 만드는 소수들을 구한다. 
        // (n / 2 이하의 소수에서 i를 찾을 수 있음)
        for (int i = 3; i <= n / 2; i += 2) {
            if (check[i] && check[n - i]) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = true;
                break;
            }
        }

        // 답이 없는경우
        if(!flag) printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}