#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 23 September 2021
Topik praktikum     : Matriks
Deskripsi           : ADT Matriks
*/

/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    m->rowEff = nRow;
    m->colEff = nCol;
    
    int i,j;
    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            m->contents[i][j] = 0;
        }
    }
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return m.rowEff-1;
}

Index getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return m.colEff-1;
}
boolean isIdxEff(Matrix m, Index i, Index j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i >= 0 && i <= getLastIdxRow(m) && j >= 0 && j <= getLastIdxCol(m));
}
ElType getElmtDiagonal(Matrix m, Index i)
/* Mengirimkan elemen m(i,i) */
{
    return m.contents[i][i];
}

ElType getElmt(Matrix m, Index i, Index j)
/* Mengirimkan elemen m(i,j) */
{
    return m.contents[i][j];
}
/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    CreateMatrix(mIn.rowEff, mIn.colEff, mRes);

    int i,j;
    for (i = 0; i <= getLastIdxRow(*mRes); i++){
        for (j = 0; j <= getLastIdxCol(*mRes); j++){
            mRes->contents[i][j] = mIn.contents[i][j];
        }
    }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    CreateMatrix(nRow, nCol, m);

    int i,j;
    for (i = 0; i <= getLastIdxRow(*m); i++){
        for (j = 0; j <= getLastIdxCol(*m); j++){
            scanf("%d", &(m->contents[i][j]));
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i,j;
    for (i = 0; i <= getLastIdxRow(m); i++){
        for (j = 0; j <= getLastIdxCol(m); j++){
            printf((
                (j != getLastIdxCol(m)) ? "%d " : 
                ((i != getLastIdxRow(m)) ? "%d\n" : "%d")
                ), m.contents[i][j]);
        }
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix m3;
    CreateMatrix(m1.rowEff, m1.colEff, &m3);

    int i,j;
    for (i = 0; i <= getLastIdxRow(m3); i++){
        for (j = 0; j <= getLastIdxCol(m3); j++){
            m3.contents[i][j] = m1.contents[i][j] + m2.contents[i][j];
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix m3;
    CreateMatrix(m1.rowEff, m1.colEff, &m3);

    int i,j;
    for (i = 0; i <= getLastIdxRow(m3); i++){
        for (j = 0; j <= getLastIdxCol(m3); j++){
            m3.contents[i][j] = m1.contents[i][j] - m2.contents[i][j];
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix m;
    CreateMatrix(m1.rowEff, m2.colEff, &m);
    int i, j, k;
    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m2); j++){
            for(k = 0; k <= getLastIdxCol(m1); k++){
                ELMT(m, i, j) += (ELMT(m1, i, k)*ELMT(m2, k, j));
            }
        }
    }
    return m;
}

Matrix multiplyConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix mr;
    CreateMatrix(m.rowEff, m.colEff, &mr);

    int i,j;
    for (i = 0; i <= getLastIdxRow(mr); i++){
        for (j = 0; j <= getLastIdxCol(mr); j++){
            mr.contents[i][j] = x*m.contents[i][j];
        }
    }
    return mr;
}
void pMultiplyConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    Matrix MNew = multiplyConst(*m, k);
    *m = MNew;
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    boolean result = (count(m1) == count(m2));
    if (result){
        int i,j;
        for (i = 0; i <= getLastIdxRow(m1); i++){
            for (j = 0; j <= getLastIdxCol(m1); j++){
                result = result && (m1.contents[i][j] == m2.contents[i][j]);
            }
        }
    }
    return result;
}

boolean isNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return (!isEqual(m1, m2));
}

boolean isSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
    return (m1.rowEff == m2.rowEff && m1.colEff == m2.colEff);
}
/* ********** Operasi lain ********** */
int count(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (m.rowEff*m.colEff);
}
/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (m.rowEff == m.colEff);
}

boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    boolean result = isSquare(m);
    int i,j;
    for (i = 0; i <= getLastIdxRow(m); i++){
        for (j = 0; j <= getLastIdxCol(m); j++){
            result = result && (m.contents[i][j] == m.contents[j][i]);
        }
    }
    return result;
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    boolean result = isSquare(m);
    if (result){
        int i,j;
        for (i = 0; i <= getLastIdxRow(m); i++){
            for (j = 0; j <= getLastIdxCol(m); j++){
                result = result && ((i != j) ? (m.contents[i][j] == 0) : (m.contents[i][j] == 1));
            }
        }
    }
    return result;
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int nonzero = 0,i,j;

    for (i = 0; i <= getLastIdxRow(m); i++){
        for (j = 0; j <= getLastIdxCol(m); j++){
            nonzero += (m.contents[i][j] == 0 ? 0 : 1);
        }
    }

    return (20*nonzero <= count(m));
}
Matrix inverse1(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    Matrix MNew = inverse1(*m);
    *m = MNew;
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    int size = ROWS(m);
    float n[size][size];
    int i, j;

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            n[i][j] = ELMT(m, i, j);
        }
    }

    float result = 1;
    int swapped = 0;

    while (size > 0){
        boolean swap = false;
        i = 0;
        if (n[size-1][size-1] == 0){
            while (i < (size-1) && (!swap)){
                if (n[i][size-1] == 0){
                    i++;
                } else {
                    swap = true;
                }
            }
        }
        if (i == (size-1) && (size > 1)){
            return 0;
        } else if (swap){
            for(j = 0; j < size; j++){
                float temp = n[size-1][j];
                n[size-1][j] = n[i][j];
                n[i][j] = temp;
            }
        }
        for (i = 0; i < (size-1); i++){
            for(j=0; j<size; j++){
                n[i][j] -= n[size-1][j]*(n[i][size-1]/n[size-1][size-1]);
            }
        }
        result *= n[size-1][size-1];
        swapped = (swapped+(swap ? 1 : 0))%2;
        size--;
    }
    float finalresult = (result*(swapped==0 ? 1.0f : -1.0f));
    return ((finalresult < 0.5f && finalresult > -0.5f) ? 0.0f : finalresult);
}
void transpose(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix MNew;
    CreateMatrix(m->rowEff, m->colEff, &MNew);

    int i,j;
    for (i = 0; i <=  getLastIdxRow(MNew); i++){
        for (j = 0; j <= getLastIdxCol(MNew); j++){
            MNew.contents[i][j] = m->contents[j][i];
        }
    }

    *m = MNew;
}

float rowMean (Matrix m, Index i){
    int j,sum = 0, n = 0;
    for (j = 0; j <= getLastIdxCol(m); j++){
        sum += m.contents[i][j];
        n++;
    }
    return sum/(n*1.0f);
}

float colMean (Matrix m, Index j){
    int i,sum = 0, n = 0;
    for (i = 0; i <= getLastIdxRow(m); i++){
        sum += m.contents[i][j];
        n++;
    }
    return sum/(n*1.0f);
}

void rowExtremes (Matrix m, Index i, ElType * max, ElType * min){
    int j;
    *max = m.contents[i][0];
    *min = m.contents[i][0];
    for (j = 0; j <= getLastIdxCol(m); j++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        } else if (ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }
    }
    return;
}

void colExtremes (Matrix m, Index j, ElType * max, ElType * min){
    int i;
    *max = m.contents[0][j];
    *min = m.contents[0][j];
    for (i = 0; i <= getLastIdxRow(m); i++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        } else if (ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }
    }
    return;
}

int countValOnRow (Matrix m, Index i, ElType X){
    int j, n = 0;
    for (j = 0; j <= getLastIdxCol(m); j++){
        n += (m.contents[i][j] == X ? 1 : 0);
    }
    return n;
}

int countValOnCol (Matrix m, Index j, ElType X){
    int i, n = 0;
    for (i = 0; i <= getLastIdxRow(m); i++){
        n += (m.contents[i][j] == X ? 1 : 0);
    }
    return n;
}

boolean isSegitigaBawah(Matrix m){
    int i;
    int j;
    boolean hasil = isSquare(m);
    if (hasil){
        for (i=0;i<=getLastIdxRow(m);i++){
            for (j=0; j<=getLastIdxCol(m);j++){
                if (i < j){
                    hasil = getElmt(m,i,j) == 0;}
            }
            }}
    return hasil;
}

void Detri(Matrix m, int *Det){
    int i,j = 0;
    if (!(isSegitigaBawah(m))) {
        *Det = 0;
    }
    else{
        while(i<=getLastIdxRow(m)){
            *Det *= getElmtDiagonal(m,i,i);
            i = i + 1;
        }
    } 


}