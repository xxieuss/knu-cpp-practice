#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cfloat> 
#include <stdexcept>

using namespace std;

// 1.
int positiveCosCounter (int a, int b){
    if (a > b) {
        throw invalid_argument("Error in positiveCosCounter: Interval start 'a' cannot be greater than end 'b'.");
    }
    int counter = 0;
    for (int x = a; x <= b; x++){
        if (cos(x) > 0) counter++;
    }
    return counter;
}

double maxCos (int a, int b){
    if (a > b) {
        throw invalid_argument("Error in maxCos: Interval start 'a' cannot be greater than end 'b'.");
    }
    double maxValue = cos(a);
    for (int x = a+1; x <= b; x++){
        if (cos(x) > maxValue) maxValue = cos(x);
    }
    return maxValue;
}

int SinLessThanCosCounter (int a, int b){
    if (a > b) {
        throw invalid_argument("Error in SinLessThanCosCounter: Interval start 'a' cannot be greater than end 'b'.");
    }
    int counter = 0;
    for (int x = a; x <= b; x++){
        if (sin(x) < cos(x)) counter++;
    }
    return counter;
}


// 2.
double elementSum(double arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in elementSum: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in elementSum: Array size must be positive.");
    }

    double sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] < i) sum += arr[i];
    }
    return sum;
}

int maxOddNum(int arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in maxOddNum: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in maxOddNum: Array size must be positive.");
    }

    bool found = false;
    int maxNum = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] % 2 != 0) {
            if(!found || arr[i] > maxNum){
                maxNum = arr[i];
                found = true;
            } 
        }
    }
    if (!found){
        throw runtime_error("Error in maxOddNum: No odd numbers found in the sequence.");
    }
    return maxNum;
}

double checkDigits(double arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in checkDigits: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in checkDigits: Array size must be positive.");
    }

    double sum = 0;
    for (int i = 0; i<n; i++){
        if (arr[i] > 1) sum += arr[i];
    }
    return sum;
}

int replaceOddWithZero(int arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in replaceOddWithZero: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in replaceOddWithZero: Array size must be positive.");
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 != 0){
            arr[i] = 0;
            count++;
        }
    }
    return count;
}

void replaceEvenPositionWithTwenty(int arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in replaceEvenPositionWithTwenty: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in replaceEvenPositionWithTwenty: Array size must be positive.");
    }

    for (int i = 0; i < n; i+=2){
        arr[i] = 20;
    }
}

// 3.
bool checkUnderlineSymbol(char *string){
    if (string == nullptr) {
        throw invalid_argument("Error in checkUnderlineSymbol: String pointer is null.");
    }
    
    while (*string != '\0') {
        if (*string == '_') return 1;
        ++string;
    }
    return 0;
}

bool checkUpperSymbol(char *string){
    if (string == nullptr) {
        throw invalid_argument("Error in checkUpperSymbol: String pointer is null.");
    }
    
    while (*string != '\0') {
        if (*string >= 'A' && *string <= 'Z') return 1;
        ++string;
    }
    return 0;
}

int countUpperSymbol(char *string){
    if (string == nullptr) {
        throw invalid_argument("Error in countUpperSymbol: String pointer is null.");
    }

    int count = 0;
    while (*string != '\0') {
        if (*string >= 'A' && *string <= 'Z') count++;
        ++string;
    }
    return count;
}

bool checkEvenBrackets(char *string){
    if (string == nullptr) {
        throw invalid_argument("Error in checkEvenBrackets: String pointer is null.");
    }

    int openCount = 0;
    int closeCount = 0;
    while (*string != '\0') {
        if (*string == '(') openCount++;
        if (*string == ')') closeCount++;
        ++string;
    }
    return (openCount == closeCount);
}


// 4.
void digitsArrow(double arrow[], int n){
    if (arrow == nullptr) {
        throw invalid_argument("Error in digitsArrow: Array pointer is null.");
    }
    if (n < 1) {
        throw invalid_argument("Error in digitsArrow: n must be at least 1.");
    }

    arrow[0] = (double)n*(n+1)/2.0;
    for (int k = 2; k <= n; k++){
        double denominator = (2.0*k-1)*2.0*k;
        if (denominator == 0) {
             throw runtime_error("Error in digitsArrow: Division by zero detected.");
        }
        arrow[k] = (n+k)*(n-k+1)*arrow[k-1] / denominator;
    }
}


// 5.

// Написати функцію, що для цілого масиву знаходить довжину найбільшої підпослідовності різних елементів.
int checkDifNum (int arr[], int n){
    if (arr == nullptr) {
        throw invalid_argument("Error in checkDifNum: Array pointer is null.");
    }
    if (n <= 0) {
        throw invalid_argument("Error in checkDifNum: Array size must be positive.");
    }
    if (n == 1) return 1; 

    int maxLength = 1;
    int curLength = 1;
    
    for (int i=1; i<n; i++){
        if (arr[i] != arr[i-1]) {
            curLength++;
        } else{
            if (curLength > maxLength) maxLength = curLength;
            curLength = 1;
        }
    }
    
    if (curLength > maxLength) maxLength = curLength;
    
    return maxLength;
}

// Написати функцію, що для цілого масиву знаходить найбільше число,
// яке в своїй сімірковій (base-7) системі числення не містить цифру '2'.
int findSevDigWithout2(int arr[], int n){
    if (arr == nullptr) throw invalid_argument("Error: Array is null.");
    if (n <= 0) throw invalid_argument("Error: Size must be positive.");
    int maxNum = -1;
    bool found = false;
    for (int i = 0; i < n; i++){
        bool tempHas2 = false;
        long long temp = arr[i];
        if (temp < 0) temp = -temp;
        if (temp == 0) {
            tempHas2 = false;
        }
        while (temp > 0 && !tempHas2){
            int digit = temp % 7;
            if (digit == 2){
                tempHas2 = true;
            }
            temp /= 7;
        }
        if (!tempHas2){
            if (!found || arr[i] > maxNum){
                maxNum = arr[i];
                found = true;
            }
        }
    }
    if (found) return maxNum;
    throw runtime_error("Error: No number without digit '2' in base-7 found.");
}


// Написати функцію, що для цілого масиву знаходить число,
// яке містить у своєму розкладі на прості дільники мінімальну кількість простих дільників.
// Якщо таких чисел декілька, обрати найбільше з них.
int findNumberWithMinPrimeDivisors (int arr[], int n){
    if (arr == nullptr) throw invalid_argument("Error: Array is null.");
    if (n <= 0) throw invalid_argument("Error: Size must be positive.");

    int minDivisors = 1000000;
    int result = -1;
    bool foundAny = false;
    
    for (int i=0; i<n; i++){
        long long temp = arr[i]; // long long для безпеки
        if (temp < 0) temp = -temp;
        
        int divisorsCount = 0;
        
        if (temp > 1) { 
            for (long long d=2; d*d <= temp; d++){
                if (temp % d == 0){
                    divisorsCount++;
                    while (temp % d == 0){
                        temp /= d;
                    }
                }
            }
            if (temp > 1) divisorsCount++;
        }
        
        if (!foundAny || divisorsCount < minDivisors){
            minDivisors = divisorsCount;
            result = arr[i];
            foundAny = true;
        }
        else if (divisorsCount == minDivisors && arr[i] > result){
            result = arr[i];
        }
    }
    
    // Теоретично, якщо масив не пустий, ми завжди знайдемо число, але для надійності:
    if (!foundAny) throw runtime_error("Error: Could not determine result (possibly empty array).");
    return result;
}

// Написати функцію, що для цілого масиву знаходить мінімальне число,
// яке містить у своєму розкладі на прості дільники менше ніж 3 простих дільники.
int findMinNumberWithLessThan3Divisors (int arr[], int n){
    if (arr == nullptr) throw invalid_argument("Error: Array is null.");
    if (n <= 0) throw invalid_argument("Error: Size must be positive.");

    int minNum = 1000000;
    bool found = false;
    
    for (int i=0; i<n; i++){
        long long temp = arr[i];
        if (temp < 0) temp = -temp;

        int divisorsCount = 0;
        if (temp > 1) {
            for (long long d=2; d*d <= temp; d++){
                if (temp % d == 0){
                    divisorsCount++;
                    while (temp % d == 0){
                        temp /= d;
                    }
                }
            }
            if (temp > 1) divisorsCount++;
        }
        
        if (divisorsCount <= 3){
            if (!found || arr[i] < minNum){
                minNum = arr[i];
                found = true;
            }
        }
    }
    if (found) return minNum;
    
    throw runtime_error("Error: No number with less than 3 prime divisors found.");
}

// Написати функцію, що для цілого масиву і інтервалу [a, b) знаходить пару елементів з парною кількістю простих дільників,
// які розташовані найближче один до одного. Якщо таких пар декілька, обрати пару з найменшим добутком. 
// Повернути знайдені елементи через посилання.
int countPrimeDivisors(int num) {
    if (num == INT_MIN) {
        throw overflow_error("Error: INT_MIN not supported in countPrimeDivisors.");
    }
    int temp = abs(num);
    int count = 0;
    
    if (temp <= 1) return 0; 

    for (int d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            count++;
            while (temp % d == 0) {
                temp /= d;
            }
        }
    }
    if (temp > 1) count++;
    return count;
}
void findClosestPair(int arr[], int a, int b, int &res1, int &res2) {
    if (arr == nullptr) {
        throw invalid_argument("Error in findClosestPair: Array pointer is null.");
    }
    if (a >= b || a < 0) {
        throw invalid_argument("Error in findClosestPair: Invalid interval indices.");
    }

    int minDistance = INT_MAX;
    long long minProduct = LLONG_MAX;
    int lastIndex = -1;
    bool foundPair = false;
    
    for (int i = a; i < b; i++) {
        // Тут ми можемо спіймати помилку від countPrimeDivisors, якщо там буде INT_MIN
        if (countPrimeDivisors(arr[i]) % 2 == 0) {
            if (lastIndex != -1) {
                int currentDistance = i - lastIndex;
                long long currentProduct = (long long)arr[i] * arr[lastIndex];

                if (currentDistance < minDistance) {
                    minDistance = currentDistance;
                    minProduct = currentProduct;
                    res1 = arr[lastIndex];
                    res2 = arr[i];
                    foundPair = true;
                }
                else if (currentDistance == minDistance) {
                    if (currentProduct < minProduct) {
                        minProduct = currentProduct;
                        res1 = arr[lastIndex];
                        res2 = arr[i];
                        foundPair = true;
                    }
                }
            }
            lastIndex = i;
        }
    }
    if (!foundPair) {
        throw runtime_error("Error: No suitable pair found in the interval.");
    }
}

// Написати функцію, що для цілого інтервалу [a, b) знаходить число,
// яке містить у своєму розкладі на прості дільники найбільший показник степеня 3.
int findNumMaxPower3(int a, int b) {
    if (a >= b) {
        throw invalid_argument("Error in findNumMaxPower3: Invalid interval (a >= b).");
    }

    int resultNum = a;
    int maxPower = -1;

    for (int i = a; i < b; i++) {
        if (i == 0) continue; 

        long long temp = i; // Використовуємо long long для безпеки
        if (temp < 0) temp = -temp;

        int currentPower = 0;
        while (temp > 0 && temp % 3 == 0) {
            currentPower++;
            temp /= 3;
        }

        if (currentPower > maxPower) {
            maxPower = currentPower;
            resultNum = i;
        }
    }
    return resultNum;
}

// Написати функцію, що для цілого числа n знаходить кількість його простих дільників,
// які входять у його розклад з показником степеня не більше 5.
int countPrimesWithLowPower(long long n) {
    if (n == 0) {
        throw domain_error("Error: Zero does not have a defined prime factorization.");
    }
    
    if (n < 0) {
        if (n == LLONG_MIN) {
             throw overflow_error("Error: LLONG_MIN overflow in countPrimesWithLowPower.");
        }
        n = -n;
    }
    
    if (n == 1) return 0;

    int validDivisorsCount = 0;
    
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            int power = 0;
            while (n % d == 0) {
                power++;
                n /= d;
            }
            if (power <= 5) {
                validDivisorsCount++;
            }
        }
    }
    if (n > 1) {
        validDivisorsCount++;
    }
    return validDivisorsCount;
}

// Написати функцію, що для цілого числа n знаходить кількість його простих дільників,
// які містять у своєму десятковому записі цифру 1.
bool hasDigitOne(long long num) {
    if (num == LLONG_MIN) {
        throw overflow_error("Error: LLONG_MIN overflow in hasDigitOne.");
    }
    if (num < 0) num = -num;
    
    while (num > 0) {
        if (num % 10 == 1) {
            return true;
        }
        num /= 10;
    }
    return false;
}
int countPrimeDivisorsWithOne(long long n) {
    if (n == 0) {
        throw domain_error("Error: Zero does not have a defined prime factorization.");
    }
    if (n == LLONG_MIN) {
         throw overflow_error("Error: LLONG_MIN overflow in countPrimeDivisorsWithOne.");
    }
    if (n < 0) n = -n;
    if (n == 1) return 0;

    int count = 0;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {            
            if (hasDigitOne(d)) {
                count++;
            }
            while (n % d == 0) {
                n /= d;
            }
        }
    }
    if (n > 1) {
        if (hasDigitOne(n)) {
            count++;
        }
    }
    return count;
}

// Написати функцію, що для цілого числа знаходить суму його простих дільників,
// які входять у його розклад з показником степеня не більше 4.
long long sumPrimeFactors(long long n){
	if (n<=1) return 0;
	long long sum = 0;
	
	long long exp = 0;
	while (n%2 == 0){
		n /= 2;
		exp++;
	}
	if (exp > 0 && exp <= 4) sum += 2;
	
	for (long long i=3; i*i<=n; i+=2){
		exp = 0;
		while (n%i == 0){
			n /= i;
			exp++;
		}
		if (exp > 0 && exp <= 4) sum += i;
	}
	
	if (n > 1) sum += n;
	
	return sum;
}

// Написати функцію, що для цілого числа знаходить простий дільник,
// який входить у його розклад у найбільшому степені.
// Якщо таких дільників декілька, повернути найменший з них.
long long primeDivisorMaxPower(long long n) {
    if (n == 0) {
        throw domain_error("Zero has no prime factorization");
    }
    if (n == LLONG_MIN) {
        throw overflow_error("LLONG_MIN cannot be negated");
    }
    if (n < 0) n = -n;
    if (n == 1) {
        throw runtime_error("1 has no prime divisors");
    }

    long long resultDivisor = -1;
    int maxPower = 0;  // Ініціалізуємо 0, бо степінь завжди >=1

    // Обробка 2 окремо (оптимально)
    int power = 0;
    while (n % 2 == 0) {
        power++;
        n /= 2;
    }
    if (power > maxPower) {
        maxPower = power;
        resultDivisor = 2;
    }

    // Непарні дільники
    for (long long d = 3; d * d <= n; d += 2) {
        if (n % d == 0) {
            power = 0;
            while (n % d == 0) {
                power++;
                n /= d;
            }
            if (power > maxPower) {
                maxPower = power;
                resultDivisor = d;
            }
        }
    }
    // Якщо залишився простий дільник > sqrt(n)
    if (n > 1) {
        // Його степінь = 1
        if (maxPower < 1 || (maxPower == 1 && n < resultDivisor)) {
            resultDivisor = n;
            maxPower = 1;
        }
    }
    return resultDivisor;
}

int main(){
    // Приклад виклику з перехопленням помилок:
    /*
    try {
        int arr[] = {2, 4, 6};
        maxOddNum(arr, 3);
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    */
    return 0;
}