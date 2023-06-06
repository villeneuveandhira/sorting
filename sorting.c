#include <stdio.h>
#include <string.h>

// function untuk menampilkan isi array
void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function untuk insertion sorting
void insertionSort(int n, int arr[], char x) {
    int i, j, key;
    // perulangan dilakukan sebanyak isi array yang dimulai dari indeks 1
    for (i = 1; i < n; i++) {
        // array ke-i akan menjadi data untuk sisipkan
        key = arr[i];
        j = i - 1;
        // perulangan terhadap isi array yang berada sebelum indek ke-i
        /* perulangan berlangsung hingga mencapai indeks ke-0 atau selama
        array ke-j nilainya lebih besar dari key (array[j] > key)*/
        if (x == 'a') {
            while (j >= 0 && key < arr[j]) {  // ascending
                // geser array ke kanan
                arr[j + 1] = arr[j];
                j--;
            }
        } else if (x == 'd') {
            while (j >= 0 && key > arr[j]) {  // descending
                // geser array ke kanan
                arr[j + 1] = arr[j];
                j--;
            }
        }
        // menempatkan key pada array[j + 1]
        arr[j + 1] = key;
    }
}

// function untuk selection sorting
void selectionSort(int n, int arr[], char x) {
    int i, j, temp, minIndex;
    for (i = 0; i < n - 1; i++) {
        // inisialisasi untuk indeks elemen minimal
        minIndex = i;
        /* perulangan mencari indeks dengan nilai minimum pada array dari
        elemen setelah i (i+1) hingga elemen terakhir array */
        for (j = i + 1; j < n; j++) {
            if (x == 'a') {
                if (arr[minIndex] > arr[j]) {  // ascending
                    minIndex = j;
                }
            } else if (x == 'd') {
                if (arr[minIndex] < arr[j]) {  // descending
                    minIndex = j;
                }
            }
        }
        // tukar posisi nilai pada indeks minimal dengan indeks i
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// function untuk bubble sorting
void bubbleSort(int n, int arr[], char x) {
    int temp, swap;
    // perulangan hingga seluruh data hingga data tidak ada yang ditukar
    do {
        // nilai swap untuk penanda ada data yang ditukar atau tidak
        swap = 0;
        // cek semua data
        for (int i = 0; i < n - 1; i++) {
            // jika data ke-i lebih besar dari data i selanjutnya
            if (x == 'a') {
                if (arr[i] > arr[i + 1]) {  // ascending
                    // tukar data
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    // penanda bahwa ada data yang ditukar
                    swap = 1;
                }
            } else if (x == 'd') {
                if (arr[i] < arr[i + 1]) {  // descending
                    // tukar data
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    // penanda bahwa ada data yang ditukar
                    swap = 1;
                }
            }
        }
    } while (swap == 1);
}

// function untuk quick sorting
void quickSort(int n, int arr[], int l, int r, char x) {
    int i, j, temp, pivot;
    if (l < r) {
        pivot = l;
        i = l;
        j = r;
        while (i < j) {
            if (x == 'a') {  // ascending
                while ((arr[i] <= arr[pivot]) && (i < r)) {
                    i = i + 1;
                }
                while (arr[j] > arr[pivot]) {
                    j = j - 1;
                }
            }
            if (x == 'd') {  // descending
                while ((arr[i] >= arr[pivot])) {
                    i = i + 1;
                }
                while (arr[j] < arr[pivot]) {
                    j = j - 1;
                }
            }
            if (i <= j) {
                // tukar data i dan j
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        // melakukan sorting untuk sub-bagian
        quickSort(n, arr, l, j - 1, x);  // kiri
        quickSort(n, arr, j + 1, r, x);  // kanan
    }
}
/*
    (https://www.javatpoint.com/quick-sort)
    algoritma quick sorting =
    1. inisialisasi [kiri], [kanan], dan [pivot] dimulai dari pinggir (kiri);
    2. jika nilai [kanan] > [pivot], maka [j] bergeser (--) sampai false;
    3. jika nilai [i] saat ini < [j] saat ini, maka menukar data;
    4. karena [pivot] > [kanan], [pivot] pindah ke kanan;
    5. jika nilai [kiri] < [pivot], maka [i] bergeser (++) sampai false;
    6. karena [pivot] > [kiri], [pivot] pindah ke kiri;
    7. langkah (no.2);
    8. langkah (no.3);
    9. langkah (no.5);
    10. setelah posisi [kiri], [kanan], [pivot] sama, melakukan sub-sorting;
    11. sub-sorting kiri dengan [kiri] = l, dan [kanan] = j-1;
    12. sub-sorting kanan dengan [kiri] = j+1, dan [kanan] = r;
*/

int main() {
    int n;
    printf("Jumlah data (n):\n");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Isi array[%d]:", i);
        scanf("%d", &arr[i]);
    }

    printf("Array SEBELUM di-sorting:\n");
    printArray(n, arr);

    char metode;
    printf("Pilih metode sorting:\n");
    printf("i = insertion\n");
    printf("s = selection\n");
    printf("b = bubble\n");
    printf("q = quick\n");
    scanf(" %c", &metode);

    char x;
    printf("'Ascending/Descending' (a/d)\n");
    scanf(" %c", &x);

    if (metode == 'i') {
        if (x == 'a') {
            insertionSort(n, arr, 'a');
        } else if (x == 'd') {
            insertionSort(n, arr, 'd');
        } else {
            return 0;
        }
    } else if (metode == 's') {
        if (x == 'a') {
            selectionSort(n, arr, 'a');
        } else if (x == 'd') {
            selectionSort(n, arr, 'd');
        } else {
            return 0;
        }
    } else if (metode == 'b') {
        if (x == 'a') {
            bubbleSort(n, arr, 'a');
        } else if (x == 'd') {
            bubbleSort(n, arr, 'd');
        } else {
            return 0;
        }
    } else if (metode == 'q') {
        if (x == 'a') {
            quickSort(n, arr, 0, n - 1, 'a');
        } else if (x == 'd') {
            quickSort(n, arr, 0, n - 1, 'd');
        } else {
            return 0;
        }
    }

    printf("Array SETELAH di-sorting:\n");
    printArray(n, arr);
    return 0;
}