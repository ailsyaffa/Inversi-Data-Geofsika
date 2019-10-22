#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#define SIZE 10
#define PHI 3.14

// ALLOCATE PARAMETER
int  i, j, k, l, m;
float nilai, determinant, parameter[2][1], d[SIZE][1],hasil[2][2], gtg[3][3];
float nilai, determinant, parameter2[3][1], d[SIZE][1], temp;
char fp, fname;
int menu, kembali, datar(), miring(), refraksi(), gradient(), informasi(), bantuan();
float offset[SIZE], traveltime[SIZE], depth[SIZE], temperature[SIZE], g[SIZE][3], gtranspose[3][SIZE], inverse[3][3], matriks[3][SIZE], result[3], gtg[3][3],gtghasil[3][3], g1[SIZE][2],  gtranspose1[2][SIZE],  res[2][2], inverse1[2][2], matriks1[2][SIZE], hasil[2][2], result1[2];
float g1[SIZE][2],  gtranspose1[2][SIZE];
float determinant,determinant1, temp;
//int i,j,k,l;
//float offset[SIZE], traveltime[SIZE], depth[SIZE], temperature[SIZE], g[SIZE][3], gtranspose[3][SIZE], inverse[3][3], matriks[3][SIZE], result[3], gtg[3][3],gtghasil[3][3];
//float determinant,temp;

void input_data(float a[SIZE], float b[SIZE]);
void input_data1(float a[SIZE], float b[SIZE]);

void matrix_g1(float a[SIZE][3], float b[SIZE]);
void matrix_gt1(float a[3][SIZE], float b[SIZE][3]);
void matrix_Gtg1 (float d[3][3],float a[3][SIZE], float b[SIZE][3]);
void inverse_Gtg1(float c[3][3], float a[3][3],float  b);
void final_matrix1(float a[3][SIZE], float b[3][3], float c[3][SIZE]);

void matrix_g2 (float a[SIZE][2], float b[SIZE]);
void matrix_g3 (float a[SIZE][2], float b[SIZE]);
void matrix_gt2(float a[2][SIZE], float b[SIZE][2]);
void matrix_Gtg2 (float c[2][2], float a[2][SIZE], float b[SIZE][2]);
void inverse_Gtg2(float c[2][2], float a[2][2],float  b);
void final_matrix2(float a[2][SIZE], float b[2][2], float c[3][SIZE]);




int main() 	//Tampilan utama dari program//
{
    system("cls");
    printf("\t================================================================================================\n");
    printf("\t||                              PROGRAM INVERSI DATA GEOFISIKA                                ||\n");
    printf("\t||                                           Oleh:                                            ||\n");
	  printf("\t||                              AILSA SYAFFA DYNIA - 186199871                                ||\n");
    printf("\t||                            ANUGRAH INDAH LESTARI - 1906324302                              ||\n");
    printf("\t================================================================================================\n");
    printf("\t------------------------------------------------------------------------------------------------\n");
    printf("\t             Program ini bertujuan untuk mengolah data geofisika untuk memperoleh               \n");
    printf("\t                             parameter fisis bawah permukaan bumi                               \n");
    printf("\t------------------------------------------------------------------------------------------------\n");

    menu:
    printf("\t================================================================================================\n");
    printf("\t||              Program untuk Memperoleh Parameter Fisis Bawah Permukaan Bumi                 ||\n");
    printf("\t================================================================================================\n");
    printf("\t|| Masukkan nomor dari menu yang ingin ditampilkan                                            ||\n");
    printf("\t|| 1.Seismik Refleksi Reflektor Miring                                                        ||\n");
    printf("\t|| 2.Seismik Refleksi Reflektor Datar                                                         ||\n");
    printf("\t|| 3.Seismik Refraksi                                                                         ||\n");
    printf("\t|| 4.Model Kurva Temperatur Sumur Pemboran                                                    ||\n");
    printf("\t|| 5.Informasi                                                                                ||\n");
    printf("\t|| 6.Bantuan                                                                                  ||\n");
    printf("\t|| 7.Keluar                                                                                   ||\n");
    printf("\t================================================================================================\n");
    printf("\t||   Dimohon hanya memasukkan input sesuai dengan pilhan di atas!                             ||\n");
    printf("\t================================================================================================\n");

    switch (getch()){
			case '1':
				datar();
				return main();
				break;
			case '2':
				miring();
				return main();
				break;
			case '3':
				refraksi();
				return main();
				break;
            case '4':
		       	gradient();
		       	return main();
		        break;
			case '5':
		       	informasi();
		       	return main();
		        break;
			case '6':
				bantuan();
				return main();
				break;
			case '7':
			    system("cls");
				return 0;
            default:
                printf("\n\nMasukan Anda tidak terdapat dalam pilihan!\nSilakan masukan kembali pilihan Anda\n");
                Sleep(1000);
                return main();
		}
	}

int informasi()		//menu informasi//
{
    system ("cls");
		  		printf("\t\t===================================================================  \n");
			    printf("\t\t|| INVERSI DATA GEOFISIKA  v.1.0                                 ||  \n");
			    printf("\t\t===================================================================  \n");
			    printf("\t\t||                                                               ||  \n");
			    printf("\t\t|| Oleh Anugrah Indah Lestari dan Ailsa Syaffa Dynia             ||  \n");
			    printf("\t\t|| Untuk memperoleh parameter fisis bawah permukaan bumi         ||  \n");
			    printf("\t\t|| ALL RIGHTS RESERVED & COPYRIGHT 2019                          ||  \n");
			    printf("\t\t||                                                               ||  \n");
		    	printf("\t\t===================================================================  \n");
		    	printf("\t\t|| Tekan apa saja untuk kembali ke menu utama                    ||  \n");
		    	printf("\t\t===================================================================\n\n");
		    	getch();
                fflush(stdin);
}

int bantuan()		//menu untuk cara penggunaan//
{
    system ("cls");
				  printf("\t\t\t===============================================================================\n");
			    printf("\t\t\t|| CARA PENGGUNAAN PROGRAM                                                   ||\n");
			    printf("\t\t\t=============================================================================== \n");
			    printf("\t\t\t|| Pada menu Seismik Refleksi Reflektor Datar, masukkan data lapangan Anda   ||\n");
			    printf("\t\t\t|| sehingga dapat diperoleh parameter kecepatan dan kedalaman lapisan tanah  ||\n");
          printf("\t\t\t||                                                                           ||\n");
			    printf("\t\t\t|| Pada menu Seismik Refleksi Reflektor Miring, masukkan data lapangan Anda  ||\n");
			    printf("\t\t\t|| sehingga dapat diperoleh parameter kecepatan dan kedalaman lapisan tanah  ||\n");
			    printf("\t\t\t||                                                                           ||\n");
			    printf("\t\t\t|| Pada menu Seismik Refleksi Refraktor, masukkan data lapangan Anda         ||\n");
          printf("\t\t\t|| sehingga dapat diperoleh parameter kecepatan                              ||\n");
          printf("\t\t\t||                                                                           ||\n");
				  printf("\t\t\t|| Pada menu Model Temperatur Sumur Pemboran, masukkan data lapangan Anda    ||\n");
          printf("\t\t\t|| sehingga dapat diperoleh model matematika antara temperatur dan           ||\n");
				  printf("\t\t\t|| kedalaman permukaan                                                       ||\n");
		    	printf("\t\t\t===============================================================================\n");
		    	printf("\t\t\t|| Tekan apa saja untuk kembali ke menu utama                                ||\n");
		    	printf("\t\t\t===============================================================================\n\n");
		    	getch();
                fflush(stdin);
}


int miring(){
    system ("cls");
    input_data(offset,traveltime);
    matrix_g1(g,offset);
	matrix_gt1(gtranspose, g);

	matrix_Gtg1(gtghasil,gtranspose, g);

    // CALCULATE DETERMINANT --> determinant

	for (i = 0; i < 3; i++)
		determinant = determinant + (gtghasil[0][i]*(gtghasil[1][(i+1)%3]*gtghasil[2][(i+2)%3] - gtghasil[1][(i+2)%3]*gtghasil[2][(i+1)%3]));
    // Print Determinant
	printf("\n\ndeterminant: %f\n", determinant);
	inverse_Gtg1(inverse, gtghasil, determinant);
//Final Matrix
	final_matrix1(matriks, inverse, gtranspose);

// FINAL RESULTS
	for (j=0; j<3; j++){
		for (i = 0; i < SIZE; i++){
		    temp = matriks[j][i] * pow(traveltime[i],2);
		    result[j] = result[j] + temp;
		}
	}
// PARAMETER MODEL
    printf("Parameter Model :");
	for (j=0; j<3; j++){
		printf("%.10f\n", result[j]);
 	}
// PARAMETER
	float kecepatan = 1/sqrt(result[2]);
	float kedalaman = sqrt((pow(kecepatan,2)*result[0])/4);
	float a = asin((pow(kecepatan,2)*result[1])/(4*kedalaman));
	float deg = a*360/(2*PHI);

	printf("\n");
      	printf("Kecepatan : %f\n", kecepatan);
      	printf("Kedalaman : %f\n", kedalaman);
      	printf("Sudut Reflektor : %f\n", deg);

        printf("\n\n");
        printf("===================================================================  \n");
		    printf("|| Tekan apa saja untuk kembali ke menu utama                    ||  \n");
	    	printf("===================================================================\n\n");
		getch();
        fflush(stdin);
}
int i,j,k,l;

int datar(){
    system ("cls");
    //int i,j,k,l;
   	//float offset[SIZE], traveltime[SIZE], g1[SIZE][2],  gtranspose1[2][SIZE],  res[2][2], inverse1[2][2], matriks1[2][SIZE],result[3];
	//float determinant;
	input_data(offset, traveltime);
	matrix_g2(g1, offset);
	matrix_gt2(gtranspose1, g1);
	matrix_Gtg2(hasil, gtranspose1, g1);

// CALCULATE DETERMINANT --> determinant
	determinant1 =hasil[0][0]*hasil[1][1] - hasil[1][0]*hasil[0][1];
// Print Determinant
	printf("\n\ndeterminant: %.2f\n", determinant1);
// Adjoint
	res[0][0] = hasil[1][1];
	res[0][1] = (hasil[1][0])*(-1);
	res[1][0] = (hasil[0][1])*(-1);
	res[1][1] = hasil[0][0];

	inverse_Gtg2(inverse1, res, determinant1);
	final_matrix2(matriks1, inverse1, gtranspose1);

// FINAL RESULTS
	for (j=0; j<2; j++){
		for (i = 0; i < SIZE; i++){
		    result1[j] += matriks1[j][i] * pow(traveltime[i],2);
		}
	}
//- Print Parameter Model
    printf("Parameter Model :");
	for (j=0; j<2; j++){
		printf("%f\n", result1[j]);
	}
// PARAMETER
	float kecepatan = 1/sqrt(result1[1]);
	float kedalaman = sqrt((pow(kecepatan,2)*result1[0])/4);

	printf("\n");
      	printf("Kecepatan : %f\n", kecepatan);
      	printf("Kedalaman : %f\n", kedalaman);

      	printf("\n\n");
        printf("===================================================================  \n");
	    	printf("|| Tekan apa saja untuk kembali ke menu utama                    ||  \n");
	    	printf("===================================================================\n\n");
		getch();
        fflush(stdin);
}

int refraksi(){
    system ("cls");
//	int i,j,k,l;
//	float offset[SIZE], traveltime[SIZE], g1[SIZE][2],  gtranspose1[2][SIZE],  res[2][2], inverse1[2][2], matriks1[2][SIZE], result[2];
//	float determinant;

	input_data(offset, traveltime);
	matrix_g3(g1, offset);
	matrix_gt2(gtranspose1, g1);
	matrix_Gtg2(hasil, gtranspose1, g1);

// Adjoint
	res[0][0] = hasil[1][1];
	res[0][1] = (hasil[1][0])*(-1);
	res[1][0] = (hasil[0][1])*(-1);
	res[1][1] = hasil[0][0];

// CALCULATE DETERMINANT --> determinant
	determinant1 =hasil[0][0]*hasil[1][1] - hasil[1][0]*hasil[0][1];


// Print Determinant
	printf("\n\ndeterminant: %.2f\n", determinant1);

//Inverse
    inverse_Gtg2(inverse1, res, determinant1);
	final_matrix2(matriks1, inverse1, gtranspose1);

// FINAL RESULTS
	for (j=0; j<2; j++){
		for (i = 0; i < SIZE; i++){
		    result1[j] += matriks1[j][i] * (traveltime[i]);
		}
	}
//- Print Parameter Model
    printf("Parameter Model :");
	for (j=0; j<2; j++){
		printf("%.2f\n", result1[j]);
	}
// PARAMETER
	float kecepatan = 1/sqrt(result1[1]);
	float gradt = result1[0];

	printf("\n");
    printf("Kecepatan : %f\n", kecepatan);
    printf("Intersep : %f\n", gradt);

      	printf("\n\n");
        printf("===================================================================  \n");
	    	printf("|| Tekan apa saja untuk kembali ke menu utama                    ||  \n");
	     	printf("===================================================================\n\n");
		getch();
        fflush(stdin);
}

int gradient(){
    system ("cls");
    input_data1(temperature, depth);
    matrix_g1(g,temperature);
	matrix_gt1(gtranspose, g);
	matrix_Gtg1(gtghasil,gtranspose, g);
	// CALCULATE DETERMINANT --> determinant

	for (j = 0; j < 3; j++)
		determinant = determinant + (gtghasil[0][j] * (gtghasil[1][(j+1)%3]*gtghasil[2][(j+2)%3]-gtghasil[1][(j+2)%3]*gtghasil[2][(j+1)%3]));
    // Print Determinant
	printf("\n\ndeterminant: %.2f\n", determinant);
	inverse_Gtg1(inverse, gtghasil, determinant);

// Print Determinant
	printf("\n\ndeterminant: %.2f\n", determinant);

// Final Matrix
	final_matrix1(matriks, inverse, gtranspose);

// FINAL RESULTS
	for (j=0; j<3; j++){
		for (i = 0; i < SIZE; i++){
		    temp = matriks[j][i] * (depth[i]);
		    result[j] = result[j] + temp;
		}
	}
// PARAMETER MODEL
    printf("Parameter Model :");
	for (j=0; j<3; j++){
		printf("%.10f\n", result[j]);
	}
// PARAMETER
    printf("Model Kurva Temperatur = %f + %fx + %fx^2\n", result[0], result[1], result[2]);

      	printf("\n\n");
        printf("===================================================================  \n");
	    	printf("|| Tekan apa saja untuk kembali ke menu utama                    ||  \n");
	    	printf("===================================================================\n\n");
		getch();
        fflush(stdin);
}





void input_data(float a[SIZE], float b[SIZE]) {
//INPUT DATA
	int i,j;
	printf("Masukkan nilai offset: \n"); // value of x
	for (i = 0; i < SIZE; i++){
		scanf("%f", &a[i]);
	}
	printf("Masukkan nilai travel time: \n"); // value of t
	for (j = 0; j < SIZE; j++){
		scanf("%f", &b[j]);
	}
}

void input_data1(float a[SIZE], float b[SIZE]) {
//INPUT DATA
	int i,j;
	printf("Masukkan nilai temperatur: \n"); // value of x
	for (i = 0; i < SIZE; i++){
		scanf("%f", &a[i]);
	}
	printf("Masukkan nilai kedalaman: \n"); // value of t
	for (j = 0; j < SIZE; j++){
		scanf("%f", &b[j]);
	}
}

void matrix_g1(float a[SIZE][3], float b[SIZE]){
    int i,j;
// BUILDING MATRIX G --> g
	for (i = 0; i < SIZE; i++){
		for (j=0; j <3; j++){
			a[i][0] = 1;
			a[i][1] = b[i]; // value of x
			a[i][2] = b[i] * b[i]; // value of x^2
		}
	}
//Print Matrix G
	printf("Matriks G :");
	for (i = 0; i < SIZE; i++){
		printf("\n");
		for(j = 0; j < 3; j++)
		printf("%.2f\t",a[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void matrix_gt1(float a[3][SIZE], float b[SIZE][3]){
// BUILDING MATRIX G TRANSPOSE --> gtranspose
	for ( i = 0; i < SIZE; i++){
		for ( j = 0 ; j < 3 ; j++ ){
			a[j][i] = b[i][j];
		}
	}
// Print Matrix Gt
	printf("Matriks G transpose:");
	for (i = 0; i < 3; i++){
		printf("\n");
		for( j = 0 ; j < SIZE ; j++ ){
			printf("%.2f\t", a[i][j]);
		}
		printf("\n\n");
	}
}

void matrix_Gtg1 (float d[3][3],float a[3][SIZE], float b[SIZE][3]){
// BUILDING MATRIX Gt*G --> hasil
	for (j = 0; j <3; j++){
		for (k = 0; k < 3; k++){
			for (i = 0; i < SIZE; i++){
				d[j][k] += a[j][i] * b[i][k];
			}
		}
	}
//Print Matrix Gt*G
	printf("Gt x G :\n");
	for (j = 0; j <3; j++){
		printf("\n");
		for (k = 0; k < 3; k++){
			printf("%.2f\t", d[j][k]);
		}
		printf("\n\n");
	}
}

void inverse_Gtg1(float c[3][3], float a[3][3],float  b){
    int j,k;
// BUILDING INVERSE OF Gt*G --> inverse
	for (k = 0; k < 3; k++){
		for (j=0; j <3; j++)
			c[j][k]= ((a[(j+1)%3][(k+1)%3]*a[(j+2)%3][(k+2)%3]) - (a[(j+1)%3][(k+2)%3]*a[(j+2)%3][(k+1)%3]))/b;
	}
//Print Inverse
	printf("Invers Gt x G :");
	for (k=0; k <3; k++){
        printf("\n");
		for (j = 0; j < 3; j++){
			printf("%f\t", c[k][j]);
		}
		printf("\n\n");
	}
}

void final_matrix1(float a[3][SIZE], float b[3][3], float c[3][SIZE]){
    int i,j,l;
// CALCULATE inv(Gt*G) * Gt --> matriks
    for (j=0; j <3; j++){
		for (l=0; l <3; l++){
			for (i = 0; i < SIZE; i++)
				a[j][i] += b[j][l] * c[l][i];
		}
	}
// Print Matrix
	printf("Matriks Inv(Gt*G)*Gt :");
	for (j=0; j <3; j++){
		printf("\n");
		for (i = 0; i < SIZE; i++){
			printf("%f\t", a[j][i]);
		}
		printf("\n\n");
	}
}




void matrix_g2 (float a[SIZE][2], float b[SIZE]) {
	int i,j;
	// BUILDING MATRIX G --> g
		for (i = 0; i < SIZE; i++){
			a[i][0] = 1;
			a[i][1] = pow(b[i],2); // value of x^2
		}
	// Print Matrix G
		printf("Matriks G :");
		for (i = 0; i < SIZE; i++){
			printf("\n");
			for(j = 0; j < 2; j++)
			printf("%.2f\t",a[i][j]);
			printf("\n");
		}
		printf("\n\n");
}

void matrix_g3 (float a[SIZE][2], float b[SIZE]) {
	int i,j;
	// BUILDING MATRIX G --> g
		for (i = 0; i < SIZE; i++){
			a[i][0] = 1;
			a[i][1] = b[i]; // value of x
		}
	// Print Matrix G
		printf("Matriks G :");
		for (i = 0; i < SIZE; i++){
			printf("\n");
			for(j = 0; j < 2; j++)
			printf("%.2f\t",a[i][j]);
			printf("\n");
		}
		printf("\n\n");
}

void matrix_gt2(float a[2][SIZE], float b[SIZE][2]){
	int i,j;
	// BUILDING MATRIX G TRANSPOSE --> gtranspose
		for ( i = 0; i < SIZE; i++){
			for ( j = 0 ; j < 2 ; j++ ){
				a[j][i] = b[i][j];
			}
		}
	// Print Matrix Gt
		printf("Matriks G transpose:");
		for (i = 0; i < 2; i++){
			printf("\n");
			for( j = 0 ; j < SIZE ; j++ ){
				printf("%.2f\t", a[i][j]);
			}
			printf("\n\n");
		}
}

void matrix_Gtg2 (float c[2][2], float a[2][SIZE], float b[SIZE][2]){
	int i,j,k;
	// BUILDING MATRIX Gt*G --> hasil
    for (j = 0; j <2; j++){
		for (k = 0; k < 2; k++){
			for (i = 0; i < SIZE; i++){
				c[j][k] += a[j][i] * b[i][k];
			}
		}
	}
	// Print Matrix Gt*G
		printf("Gt x G :\n");
		for (j = 0; j <2; j++){
			printf("\n");
			for (k = 0; k < 2; k++){
				printf("%.10f\t", c[j][k]);
			}
			printf("\n\n");
		}
}

void inverse_Gtg2(float c[2][2], float a[2][2],float  b){
	int j,k;
	// BUILDING INVERSE OF Gt*G --> inverse
		for (k = 0; k < 2; k++){
			for (j=0; j <2; j++){
				c[j][k] = a[j][k]/b;
			}
		}
	// Print Inverse
		printf("Invers Gt x G :");
		for (k=0; k <2; k++){
			printf("\n");
			for (j = 0; j < 2; j++){
				printf("%.10f\t", c[k][j]);
			}
			printf("\n\n");
		}

}

void final_matrix2(float a[2][SIZE], float b[2][2], float c[2][SIZE]){
	int i,j,l;
	// CALCULATE inv(Gt*G) * Gt --> matriks
		for (j=0; j <2; j++){
			for (l=0; l <2; l++){
				for (i = 0; i < SIZE; i++){
					a[j][i] += b[j][l] * c[l][i];
				}
			}
		}
	// Print Matrix
		printf("Matriks Inv(Gt*G)*Gt :");
		for (l=0; l <2; l++){
			printf("\n");
			for (i = 0; i < SIZE; i++){
				printf("%.10f\t", a[l][i]);
			}
			printf("\n\n");
		}
}

//tantangan selanjutnya: membaca dari file xls, outputnya betuk file lain
