#include <iostream>
#include <string>

using namespace std;

void generateCombinations() {
    char A[] = { 'a', 'b', 'c' };
    char B[] = { 'x', 'y', 'z' };
    char C[] = { '0', '1' };

    string D[18];
    int j = 0;

    for (int iC = 0; iC < 2; ++iC)
        for (int iA = 0; iA < 3; ++iA)
            for (int iB = 0; iB < 3; ++iB) {
                D[j] = string(1, C[iC]) + A[iA] + B[iB];
                j++;
            }

    cout << "C x A x B: \n";
    for (int i = 0; i < 18; ++i) {
        cout << D[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

void performSetOperations() {
    int n;
    cout << "Enter the number of elements in the universe U: ";
    cin >> n;

    int U[100];
    int A[100], B[100];
    int Abit[100] = { 0 }, Bbit[100] = { 0 };

    cout << "Enter the elements of the universe U: ";
    for (int i = 0; i < n; ++i)
        cin >> U[i];

    int ka;
    cout << "Enter the number of elements in set A: ";
    cin >> ka;

    cout << "Enter the elements of set A: ";
    for (int i = 0; i < ka; ++i)
        cin >> A[i];

    int kb;
    cout << "Enter the number of elements in set B: ";
    cin >> kb;

    cout << "Enter the elements of set B: ";
    for (int i = 0; i < kb; ++i)
        cin >> B[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < ka; ++j)
            if (U[i] == A[j]) {
                Abit[i] = 1;
                break;
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < kb; ++j)
            if (U[i] == B[j]) {
                Bbit[i] = 1;
                break;
            }

    int notA[100], AperB[100], AobB[100], ArizB[100], AxorB[100];

    for (int i = 0; i < n; ++i) {
        notA[i] = 1 - Abit[i];
        AperB[i] = Abit[i] & Bbit[i];
        AobB[i] = Abit[i] | Bbit[i];
        ArizB[i] = Abit[i] & ~Bbit[i];
        AxorB[i] = Abit[i] ^ Bbit[i];
    }

    cout << "Bit A: ";
    for (int i = 0; i < n; ++i)
        cout << Abit[i] << " ";

    cout << "\nBit B: ";
    for (int i = 0; i < n; ++i)
        cout << Bbit[i] << " ";

    cout << "\nnot A: ";
    for (int i = 0; i < n; ++i)
        cout << notA[i] << " ";

    cout << "\nAperB: ";
    for (int i = 0; i < n; ++i)
        cout << AperB[i] << " ";

    cout << "\nAob B: ";
    for (int i = 0; i < n; ++i)
        cout << AobB[i] << " ";

    cout << "\nA \\ B: ";
    for (int i = 0; i < n; ++i)
        cout << ArizB[i] << " ";

    cout << "\nAxorB: ";
    for (int i = 0; i < n; ++i)
        cout << AxorB[i] << " ";

    cout << endl;
}

int main() {
    generateCombinations();
    performSetOperations();
    return 0;
}