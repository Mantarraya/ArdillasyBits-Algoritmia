#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CHAR 300 /* Maxima cantidad de caracteres por linea */

/* Estructura utilizada para el listado de Sunat */

typedef struct sunat{
	long ruc;
	int dni;
	char nombres[40];
	char apPaterno[30];
	char apMaterno[30];
	int dia;
	int mes; 
	int anio;
	char estado[30];
	int montoFact;
} tipoSunat;

/* Estructura utilizada para el listado de Reniec */

typedef struct reniec{
	int dni;
	char nombres[40];
	char apPaterno[30];
	char apMaterno[30];
	char genero[30];
	char cargaFamiliar[30];
} tipoReniec;

/* Estructura utilizada para el listado de Infocorp */

typedef struct infocorp{
	int dni;
	char nombres[40];
	char apPaterno[30];
	char apMaterno[30];
	int riesgo;
} tipoInfocorp;

/* Estructura utilizada para el listado de Personas */

typedef struct persona{
	int dni;
	char nombres[40];
	char apPaterno[30];
	char apMaterno[30];
} tipoPersona;


void leerRegistroSunat(tipoSunat sunat[], int *nPersonas){

	/* Preparar Archivo */

	FILE *db_sunat;
	db_sunat = fopen("DB_SUNAT.txt", "r");

	/* Leer Datos */

	char linea[MAX_CHAR];
	long ruc;
	int dni;
	char *nombre;
	char *apPat;
	char *apMat;
	int dia, mes, anio;
	char *estado;
	int montoFact;
	tipoSunat s;

	int cnt = 0;
	while (fgets(linea, MAX_CHAR, db_sunat) != NULL && strlen(linea) != 0){

		ruc = atol(strtok(linea, ","));
		dni = atoi(strtok(NULL, ","));
		nombre = strtok(NULL, ",");
		apPat = strtok(NULL,",");
		apMat = strtok(NULL,",");
		dia = atoi(strtok(NULL,"/"));
		mes = atoi(strtok(NULL,"/"));
		anio = atoi(strtok(NULL,","));
		estado = strtok(NULL,",");
		montoFact = atol(strtok(NULL,","));
	
		s.ruc = ruc;
		s.dni = dni;
		strcpy(s.nombres,nombre);
		strcpy(s.apPaterno,apPat);
		strcpy(s.apMaterno,apMat);
		s.dia = dia;
		s.mes = mes;
		s.anio = anio;       
		strcpy(s.estado,estado);
		s.montoFact = montoFact;

		sunat[cnt] = s;
		cnt++;
	}

	*nPersonas = cnt;

	/* Cerrar Archivo */
	 fclose(db_sunat);

}

void leerRegistroReniec(tipoReniec reniec[], int *nPersonas){

	/* Preparar Archivo */

	FILE *db_reniec;
	db_reniec = fopen("DB_RENIEC.txt", "r");

	/* Leer Datos */

	char linea[MAX_CHAR];
	int dni;
	char *nombre;
	char *apPat;
	char *apMat;
	char *genero;
	char *cargaFamiliar;
	tipoReniec r;

	int cnt = 0;
	while (fgets(linea, MAX_CHAR, db_reniec) != NULL && strlen(linea) != 0){

		dni = atoi(strtok(linea, ","));
		nombre = strtok(NULL, ",");
		apPat = strtok(NULL,",");
		apMat = strtok(NULL,",");
		genero = strtok(NULL,",");
		cargaFamiliar = strtok(NULL,","); cargaFamiliar[2] = '\0';
        
		r.dni = dni;
		strcpy(r.nombres,nombre);
		strcpy(r.apPaterno,apPat);
		strcpy(r.apMaterno,apMat);
		strcpy(r.genero,genero);        
		strcpy(r.cargaFamiliar,cargaFamiliar);

		reniec[cnt] = r;
		cnt++;

	}

	*nPersonas = cnt;

	/* Cerrar Archivo */

	fclose(db_reniec);

}

void leerRegistroInfocorp(tipoInfocorp infocorp[], int *nPersonas){

	/* Preparar Archivo */

	FILE *db_infocorp;
	db_infocorp = fopen("DB_INFOCORP.txt", "r");

	/* Leer Datos */

	char linea[MAX_CHAR];
	int dni;
	char *nombre;
	char *apPat;
	char *apMat;
	int riesgo;
	tipoInfocorp i;	

	int cnt = 0;
	while (fgets(linea, MAX_CHAR, db_infocorp) != NULL && strlen(linea) != 0){

		dni = atoi(strtok(linea,",")); 
 		nombre = strtok(NULL,","); 
 		apPat = strtok(NULL,","); 
 		apMat = strtok(NULL,","); 
 		riesgo = atoi(strtok(NULL,","));

		i.dni = dni;
		strcpy(i.nombres,nombre);
		strcpy(i.apPaterno,apPat);
		strcpy(i.apMaterno,apMat);
		i.riesgo = riesgo;

		infocorp[cnt] = i;
		cnt++;
	}

	*nPersonas = cnt;

	/* Cerrar Archivo */
	fclose(db_infocorp);

}

void leerRegistroPersonas(tipoPersona persona[], int *nPersonasBanco){

	/* Preparar Archivo */

	FILE *archPersonas;
	archPersonas = fopen("Archivo_Personas.txt", "r");

	/* Leer Datos */

	char linea[MAX_CHAR];
	int dni;
	char *nombre;
	char *apPat;
	char *apMat;
	tipoPersona p;	

	int cnt = 0;
	while (fgets(linea, MAX_CHAR, archPersonas) != NULL && strlen(linea) != 0){

		dni = atoi(strtok(linea,",")); 
 		nombre = strtok(NULL,","); 
 		apPat = strtok(NULL,","); 
 		apMat = strtok(NULL,","); 

		p.dni = dni;
		strcpy(p.nombres,nombre);
		strcpy(p.apPaterno,apPat);
		strcpy(p.apMaterno,apMat);

		persona[cnt] = p;
		cnt++;
	}

	*nPersonasBanco = cnt;

	/* Cerrar Archivo */
	fclose(archPersonas);


}

void imprimirGuiones(){
	int i;
	for (i = 0; i < 130; i++)
		printf("-");
	printf("\n");
}

void imprimirCabecera1(){

	imprimirGuiones();

	printf("%80s\n", "TRABAJO PARCIAL - ALGORITMIA");
	imprimirGuiones();
	printf("%95s\n", "ORDENAMIENTO DE LOS ARCHIVOS DB_INFOCORP DB_RENIEC DB_SUNAT");

	imprimirGuiones();
	
}

void imprimirCabecera2(){

	imprimirGuiones();
;
	printf("%96s\n", "BUSQUEDA Y CALCULO DE LA LINEA DE CREDITO DE LOS BANCOS A B C");

	imprimirGuiones();
	
}

void verificarArchivo(int *numArchivo){

	printf("\n¿QUE ARCHIVO DESEA ORDENAR?:\n\n");
	printf("1. DB_INFOCORP \n2. DB_RENIEC \n3. DB_SUNAT\n\n");
	printf("ARCHIVO N°: ");			

	/* Verificamos que el numero del archivo pertenezca al rango correspondiente */

	while (1){
		
		scanf("%d", &*numArchivo);

		if (*numArchivo >= 1 && *numArchivo <= 3)
			break;
		else
			printf("\n%90s\n\n","¡EL NUMERO DEL ARCHIVO NO PERTENECE AL RANGO!");
			printf("ARCHIVO N°: ");		

	}

}

void verificarCampos(int numArchivo, int *campo1, int *campo2){

	printf("\nESCRIBA 2 CAMPOS POR LOS QUE DESEA ORDENAR:\n\n");
	printf("1. NOMBRE\n2. APELLIDO PATERNO\n3. APELLIDO MATERNO\n4. DNI\n");

	if (numArchivo == 1)
		printf("5. RIESGO\n\n");
	else if (numArchivo == 2)
		printf("5. GENERO\n6. CARGA FAMILIAR\n\n");
	else if (numArchivo == 3)
		printf("5. RUC\n6. MONTO FACTURA\n7. FECHA\n8. ESTADO\n\n");
	printf("CAMPOS N°: ");
		
	/* Verificamos que el campo pertenezca al rango y que sean distintos*/

	while (1){

		scanf("%d %d", &*campo1, &*campo2);

		if ((numArchivo == 1) && (*campo1 != *campo2) && (*campo1 >= 1) && (*campo1 <= 5) && (*campo2 >= 1) && (*campo2 <= 5))
			break;
		else if ((numArchivo == 2) && (*campo1 != *campo2) && (*campo1 >= 1) && (*campo1 <= 6) && (*campo2 >= 1) && (*campo2 <= 6))
			break;
		if ((numArchivo == 3) && (*campo1 != *campo2) && (*campo1 >= 1) && (*campo1 <= 8) && (*campo2 >= 1) && (*campo2 <= 8))
			break;
		else
			printf("\n%95s\n\n","¡LOS CAMPOS NO PERTENECEN AL RANGO Y/O SON IGUALES");

		printf("CAMPOS N°: ");

	}

}

void verificarAlgoritmo(int *numAlgoritmo){

	printf("\n¿MEDIANTE QUE ALGORITMO DESEA ORDENAR?:\n\n");
	printf("1. BUBBLE SORT \n2. SHELL SORT\n\n");
	printf("ALGORITMO N°: ");

	while (1){

		scanf("%d", &*numAlgoritmo);

		if (*numAlgoritmo >= 1 && *numAlgoritmo <= 2)
			break;
		else
			printf("\n%95s\n\n","¡EL NUMERO DEL ALGORITMO NO PERTENECE AL RANGO!");

		printf("ALGORITMO N°: ");

	}

}

/* Comparar segun de acuerdo al segundo campo (desempate) */

int desempate_infocorp(tipoInfocorp a, tipoInfocorp b, int campo2){

	if(campo2 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
			return 1;
		else                                             /* a.nombres = b.nombres */
			return 0; 
	}
	else if(campo2 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return 0;
	}
	else if(campo2 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return 0;
	}
	else if(campo2 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return 0;
	}
	else if (campo2 == 5){
		if (a.riesgo < b.riesgo)
			return -1;
		else if (a.riesgo > b.riesgo)
			return 1;
		else
			return 0;
	}

}

int desempate_reniec(tipoReniec a, tipoReniec b, int campo2){

	if(campo2 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
			return 1;
		else                                             /* a.nombres = b.nombres */
			return 0; 
	}
	else if(campo2 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return 0;
	}
	else if(campo2 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return 0;
	}
	else if(campo2 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return 0;
	}
	else if (campo2 == 5){
		if( strcmp(a.genero,b.genero) < 0)         
			return -1; 
		else if(strcmp(a.genero,b.genero) > 0)     
			return 1;
		else                                             
			return 0;
	}
	else if (campo2 == 6){
		if( strcmp(a.cargaFamiliar,b.cargaFamiliar) < 0)         
			return -1; 
		else if(strcmp(a.cargaFamiliar,b.cargaFamiliar) > 0)     
			return 1;
		else                                             
			return 0;
	}

}

int desempate_sunat(tipoSunat a, tipoSunat b, int campo2){

	if(campo2 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
            return 1;
		else                                             /* a.nombres = b.nombres */
			return 0; 
    }
    else if(campo2 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return 0;
	}
	else if(campo2 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return 0;
	}
	else if(campo2 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return 0;
 	}
	else if(campo2 == 5){
		if( a.ruc < b.ruc)
			return -1;
		else if(a.ruc > b.ruc)
			return 1;
		else
			return 0;
	}
	else if(campo2 == 6){
		if( a.montoFact < b.montoFact)
			return -1;
		else if(a.montoFact > b.montoFact)
			return 1;
		else
			return 0;
	}
	else if(campo2 == 7){
		if( a.anio*10000 + a.mes*100 + a.dia < b.anio*10000 + b.mes*100 + b.dia)
			return -1;
		else if(a.anio*10000 + a.mes*100 + a.dia > b.anio*10000 + b.mes*100 + b.dia)
			return 1;
		else
			return 0;
	}
	else if(campo2 == 8){
		if( strcmp(a.estado,b.estado) < 0)         
			return -1;
		else if(strcmp(a.estado,b.estado) > 0)   
			return 1;
		else                                             
			return 0;
	}

}

/* Comparar segun de acuerdo al primer campo */

int comparar_infocorp(tipoInfocorp a, tipoInfocorp b, int campo1, int campo2){

	if (campo1 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
			return 1;
		else                                             /* a.nombres = b.nombres */
			return desempate_infocorp(a,b,campo2); 
	}
	else if (campo1 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return desempate_infocorp(a,b,campo2);
	}
	else if (campo1 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return desempate_infocorp(a,b,campo2);
	}
	else if (campo1 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return desempate_infocorp(a,b,campo2);
	}
	else if (campo1 == 5){
		if (a.riesgo < b.riesgo)
			return -1;
		else if (a.riesgo > b.riesgo)
			return 1;
		else
			return desempate_infocorp(a,b,campo2);

	}

}

int comparar_reniec(tipoReniec a, tipoReniec b, int campo1, int campo2){

	if(campo1 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
		return 1;
		else                                             /* a.nombres = b.nombres */
			return desempate_reniec(a,b,campo2); 
	}
	else if(campo1 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return desempate_reniec(a,b,campo2);
	}
	else if(campo1 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return desempate_reniec(a,b,campo2);
	}
	else if(campo1 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return desempate_reniec(a,b,campo2);
	}
	else if (campo1 == 5){
		if( strcmp(a.genero,b.genero) < 0)         
			return -1; 
		else if(strcmp(a.genero,b.genero) > 0)     
			return 1;
		else                                             
			return desempate_reniec(a,b,campo2);
	}
	else if (campo1 == 6){
		if( strcmp(a.cargaFamiliar,b.cargaFamiliar) < 0)         
			return -1; 
		else if(strcmp(a.cargaFamiliar,b.cargaFamiliar) > 0)     
			return 1;
		else                                             
			return desempate_reniec(a,b,campo2);
	}
	

}

int comparar_sunat(tipoSunat a, tipoSunat b, int campo1, int campo2){

	if(campo1 == 1){
		if( strcmp(a.nombres,b.nombres) < 0)             /* a.nombres < b.nombres */
			return -1;
		else if(strcmp(a.nombres,b.nombres) > 0)         /* a.nombres > b.nombres */
			return 1;
		else                                             /* a.nombres = b.nombres */
			return desempate_sunat(a,b,campo2); 
	}
	else if(campo1 == 2){
		if( strcmp(a.apPaterno,b.apPaterno) < 0)         /* a.apPaterno < b.apPaterno */
			return -1; 
		else if(strcmp(a.apPaterno,b.apPaterno) > 0)     /* a.apPaterno > b.apPaterno */
			return 1;
		else                                             /* a.apPaterno = b.apPaterno */
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 3){
		if( strcmp(a.apMaterno,b.apMaterno) < 0)         /* a.apMaterno < b.apMaterno */
			return -1;
		else if(strcmp(a.apMaterno,b.apMaterno) > 0)     /* a.apMaterno > b.apMaterno */
			return 1;
		else                                             /* a.apMaterno = b.apMaterno */
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 4){
		if( a.dni < b.dni)
			return -1;
		else if(a.dni > b.dni)
			return 1;
		else
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 5){
		if( a.ruc < b.ruc)
			return -1;
		else if(a.ruc > b.ruc)
			return 1;
		else
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 6){
		if( a.montoFact < b.montoFact)
			return -1;
		else if(a.montoFact > b.montoFact)
			return 1;
		else
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 7){
		if( a.anio*10000 + a.mes*100 + a.dia < b.anio*10000 + b.mes*100 + b.dia)
			return -1;
		else if(a.anio*10000 + a.mes*100 + a.dia > b.anio*10000 + b.mes*100 + b.dia)
			return 1;
		else
			return desempate_sunat(a,b,campo2);
	}
	else if(campo1 == 8){
		if( strcmp(a.estado,b.estado) < 0)         
			return -1;
		else if(strcmp(a.estado,b.estado) > 0)   
			return 1;
		else                                             
			return desempate_sunat(a,b,campo2);
	}


}

/* Algoritmos Bubble Sort para cada registro */

void bubbleSort_Infocorp(tipoInfocorp infocorp[], int n, int campo1, int campo2){

	int i, j;
	tipoInfocorp aux;

	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (comparar_infocorp(infocorp[j], infocorp[j+1], campo1, campo2) == 1){ /* infocorp[j].campo > infocorp[j+1].campo */
				aux = infocorp[j];
				infocorp[j] = infocorp[j+1];
				infocorp[j+1] = aux;
			}
		}
	}

}

void bubbleSort_Reniec(tipoReniec reniec[], int n, int campo1, int campo2){

	int i, j;
	tipoReniec aux;

	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (comparar_reniec(reniec[j], reniec[j+1], campo1, campo2) == 1){ /* reniec[j].campo > reniec[j+1].campo */
				aux = reniec[j];
				reniec[j] = reniec[j+1];
				reniec[j+1] = aux;
			}
		}
	}

}

void bubbleSort_Sunat(tipoSunat sunat[], int n, int campo1, int campo2){

	int i, j;
	tipoSunat aux;

	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (comparar_sunat(sunat[j], sunat[j+1], campo1, campo2) == 1){ /* sunat[j].campo > sunat[j+1].campo */
				aux = sunat[j];
				sunat[j] = sunat[j+1];
				sunat[j+1] = aux;
			}
		}
	}

}

/* Algoritmos Shell Sort para cada registro */

void shellSort_Infocorp(tipoInfocorp infocorp[], int n, int campo1, int campo2){

	int i, j;
	
	int inc = n/2;
	
	while (inc > 0){
		for (i = inc; i <= n-1; i++){
			tipoInfocorp temp = infocorp[i];
			j = i;
			while (j >= inc && comparar_infocorp(infocorp[j-inc], temp, campo1, campo2) == 1){ /* infocorp[j-inc] > temp */
				infocorp[j] = infocorp[j-inc];
				j = j - inc;
			}
			
			infocorp[j] = temp;
		}
		
		inc = inc/2;
	}

}

void shellSort_Reniec(tipoReniec reniec[], int n, int campo1, int campo2){

	int i, j;
	
	int inc = n/2;
	
	while (inc > 0){
		for (i = inc; i <= n-1; i++){
			tipoReniec temp = reniec[i];
			j = i;
			while (j >= inc && comparar_reniec(reniec[j-inc], temp, campo1, campo2) == 1){ /* reniec[j-inc] > temp */
				reniec[j] = reniec[j-inc];
				j = j - inc;
			}
			
			reniec[j] = temp;
		}
		
		inc = inc/2;
	}

}

void shellSort_Sunat(tipoSunat sunat[], int n, int campo1, int campo2){

	int i, j;
	
	int inc = n/2;
	
	while (inc > 0){
		for (i = inc; i <= n-1; i++){
			tipoSunat temp = sunat[i];
			j = i;
			while (j >= inc && comparar_sunat(sunat[j-inc], temp, campo1, campo2) == 1){ /* sunat[j-inc] > temp */
				sunat[j] = sunat[j-inc];
				j = j - inc;
			}
			
			sunat[j] = temp;
		}
		
		inc = inc/2;
	}

}

void imprimirEspacios(FILE *archSalida ,int n){
	int i;
	for (i = 0; i < n; i++){
		fprintf(archSalida, " ");
	}
}

void imprimirRegistroInfocorp(char nombArchSal[], tipoInfocorp infocorp[], int nPersonas){

	/* Crear Archivo */

	FILE *archSalida;
	archSalida = fopen(nombArchSal, "w");

	/* Imprimir Archivo */

	int i;
	fprintf(archSalida,"| DNI          ||              NOMBRE             ||           APELLIDO PATERNO        ||     APELLIDO MATERNO    ||         RIESGO      |\n");
	for(i = 0; i < nPersonas; i++){

		fprintf(archSalida, "%.8d", infocorp[i].dni);
		imprimirEspacios(archSalida, 20);

		fprintf(archSalida, "%s", infocorp[i].nombres);
		imprimirEspacios(archSalida, 40 - strlen(infocorp[i].nombres));

		fprintf(archSalida, "%s", infocorp[i].apPaterno);
		imprimirEspacios(archSalida, 30 - strlen(infocorp[i].apPaterno));

		fprintf(archSalida, "%s", infocorp[i].apMaterno);
		imprimirEspacios(archSalida, 30 - strlen(infocorp[i].apMaterno));

		fprintf(archSalida, "%d\n", infocorp[i].riesgo);

	}

	/* Cerrar Archivo */

	fclose(archSalida);

}

void imprimirRegistroReniec(char nombArchSal[], tipoReniec reniec[], int nPersonas){

	/* Crear Archivo */

	FILE *archSalida;
	archSalida = fopen(nombArchSal, "w");

	/* Imprimir Archivo */

	int i;
	fprintf(archSalida,"| DNI          ||           NOMBRE             ||      APELLIDO PATERNO    ||   APELLIDO MATERNO    ||    GENERO  ||     RIESGO      |\n");
	for(i = 0; i < nPersonas; i++){

		fprintf(archSalida, "%.8d", reniec[i].dni);
		imprimirEspacios(archSalida, 15);

		fprintf(archSalida, "%s", reniec[i].nombres);
		imprimirEspacios(archSalida, 35 - strlen(reniec[i].nombres));

		fprintf(archSalida, "%s", reniec[i].apPaterno);
		imprimirEspacios(archSalida, 25 - strlen(reniec[i].apPaterno));

		fprintf(archSalida, "%s", reniec[i].apMaterno);
		imprimirEspacios(archSalida, 25 - strlen(reniec[i].apMaterno));

		fprintf(archSalida, "%s", reniec[i].genero);
		imprimirEspacios(archSalida, 15 - strlen(reniec[i].genero));

		fprintf(archSalida, "%s\n", reniec[i].cargaFamiliar);

	}

	/* Cerrar Archivo */

	fclose(archSalida);

}

void imprimirRegistroSunat(char nombArchSal[], tipoSunat sunat[], int nPersonas){

	/* Crear Archivo */

	FILE *archSalida;
	archSalida = fopen(nombArchSal, "w");

	/* Imprimir Archivo */

	int i;
	fprintf(archSalida,"|   RUC       ||     DNI     ||       NOMBRE         ||            APELLIDOS        ||      FECHA    ||   ESTADO    ||   MONTO FACTURA |\n");
	for(i = 0; i < nPersonas; i++){

		fprintf(archSalida, "%11ld", sunat[i].ruc);
		imprimirEspacios(archSalida, 8);

		fprintf(archSalida, "%.8d", sunat[i].dni);
		imprimirEspacios(archSalida, 8);

		fprintf(archSalida, "%s", sunat[i].nombres);
		imprimirEspacios(archSalida, 25 - strlen(sunat[i].nombres));

		fprintf(archSalida, "%s", sunat[i].apPaterno);
		imprimirEspacios(archSalida, 15 - strlen(sunat[i].apPaterno));

		fprintf(archSalida, "%s", sunat[i].apMaterno);
		imprimirEspacios(archSalida, 15 - strlen(sunat[i].apMaterno));

		fprintf(archSalida, "%.2d/%.2d/%.4d", sunat[i].dia, sunat[i].mes, sunat[i].anio);
		imprimirEspacios(archSalida, 7);

		fprintf(archSalida, "%s", sunat[i].estado);
		imprimirEspacios(archSalida, 20 - strlen(sunat[i].estado));

		fprintf(archSalida, "%7d\n", sunat[i].montoFact);

	}

	/* Cerrar Archivo */

	fclose(archSalida);

}

void obtenerRegistroOrdenado(int numArchivo, int numAlgoritmo, char nombArchSal[], tipoInfocorp infocorp[], tipoReniec reniec[], tipoSunat sunat[], 
	                         int campo1, int campo2, int nPersonas){	

	/* Iniciamos el conteo de tiempo */
	 clock_t t_ini_sort = clock();

	if (numArchivo == 1){

		if (numAlgoritmo == 1)
			bubbleSort_Infocorp(infocorp, nPersonas, campo1, campo2);
		else
			shellSort_Infocorp(infocorp, nPersonas, campo1, campo2); 

		imprimirRegistroInfocorp(nombArchSal, infocorp, nPersonas); 

	}
	else if (numArchivo == 2){

		if (numAlgoritmo == 1)
			bubbleSort_Reniec(reniec, nPersonas, campo1, campo2);
		else
			shellSort_Reniec(reniec, nPersonas, campo1, campo2);

		imprimirRegistroReniec(nombArchSal, reniec, nPersonas);

	}
	else if (numArchivo == 3){

		if (numAlgoritmo == 1)
			bubbleSort_Sunat(sunat, nPersonas, campo1, campo2);
		else
			shellSort_Sunat(sunat, nPersonas, campo1, campo2);

		imprimirRegistroSunat(nombArchSal, sunat, nPersonas);

	}

	/* Detenemos el conteo de tiempo */
	clock_t t_fin_sort = clock();

	 printf("\nORDENACION EXITOSA, tiempo: %.20f ms\n\n",((double)t_fin_sort-t_ini_sort)*1000.0/CLOCKS_PER_SEC);

}

void ordenarmientoRegistro(tipoSunat sunat[], tipoReniec reniec[], tipoInfocorp infocorp[], int nPersonas){

	/* Declaracion de variables */

	char rpta[30];
	char nombArchSal[MAX_CHAR];	
	int numArchivo;
	int campo1, campo2;
	int numAlgoritmo;

	/* Procedemos a pedirle al usuario si desea ordenar algun archivo */

	while (1){

		printf("¿DESEA ORDENAR? (S/N)?: ");
		scanf("%s", rpta);

		if (strcmp(rpta,"N")==0)
			break;
		else if (strcmp(rpta,"S")==0){

			/* Procedemos a pedirle al usuario que archivo ordenar */	

			verificarArchivo(&numArchivo);

			/* Procedemos a pedirle al usuario el nombre del archivo de salida */

			printf("\nINGRESE EL NOMBRE DEL ARCHIVO DE SALIDA: ");
			scanf("%s", nombArchSal);

			/* Procedemos a pedirle al usuario mediante que campos desea ordenar */

			verificarCampos(numArchivo, &campo1, &campo2);	

			/* Procedemos a pedirle al usuario mediante que algoritmo desea algoritmo desea ordenar */

			verificarAlgoritmo(&numAlgoritmo);

			/* Procedemos a ordenar el registro con el algoritmo y campos ingresados 
			   e imprimirlo en el archivo de salida con el nombre escogido*/

			obtenerRegistroOrdenado(numArchivo, numAlgoritmo, nombArchSal, infocorp, reniec, sunat, campo1, campo2, nPersonas);			

			break;			

		}
		else
			printf("\n%80s\n\n","CARACTER INGRESADO INCORRECTO");

	}

}

void imprimirSalidaCredito(FILE *archSalida, tipoPersona persona, double credito){

	fprintf(archSalida, "%.8d", persona.dni);
	imprimirEspacios(archSalida, 8);

	fprintf(archSalida, "%s", persona.nombres);
	imprimirEspacios(archSalida, 25 - strlen(persona.nombres));

	fprintf(archSalida, "%s", persona.apPaterno);
	imprimirEspacios(archSalida, 15 - strlen(persona.apPaterno));
	
	fprintf(archSalida, " %14.4lf\n", credito);

}

double calcularCreditoA(int riesgo, char cargaFamiliar[], int montoFact){

	int f;
	double h, credito;
	
	if (strcmp(cargaFamiliar,"No")==0)
		f = 3;
	else 
		f = 1;
		
	
	if (riesgo >= 1 && riesgo <= 2)
		h = 1.0;
	else if (riesgo >= 3 && riesgo <= 5)
		h = 0.6;
	else if (riesgo >= 6 && riesgo <= 7)
		h = 0.2;
	else if (riesgo >= 8)
		h = 0.0;
		
	credito = (4*montoFact/14.0)*(f/3.0)*h;
	
	return credito;

}

double calcularCreditoB(int riesgo, char cargaFamiliar[], int montoFact){

	int f;
	double h, credito;
	
	if (strcmp(cargaFamiliar, "No")==0)
		f = 4;
	else 
		f = 1;
		
	
	if (riesgo >= 1 && riesgo <= 2)
		h = 1.0;
	else if (riesgo >= 3)
		h = 0;
		
	credito = (4*montoFact/14.0)*(f/3.0)*h;
	
	return credito;

}

double calcularCreditoC(int riesgo, char cargaFamiliar[], int montoFact){

	int f;
	double h, credito;
	
	if (strcmp(cargaFamiliar, "No")==0)
		f = 3;
	else
		f = 2;
	
	if (riesgo == 1)
		h = 1.0;
	else if (riesgo >= 2 && riesgo <= 4)
		h = 0.4;
	else if (riesgo >= 5)
		h = 0.0;
		
	credito = (4*montoFact/14.0)*(f/3.0)*h;
	
	return credito;

}

int busquedaTernaria(tipoSunat sunat[], int ini, int fin, int k){

	if (ini > fin)
		return -1;
 
	int terc = (fin-ini + 1)/3;
 
	if (sunat[ini+terc].dni == k)
		return ini+terc;
	else if (sunat[fin-terc].dni == k)
		return fin-terc;
 
	if (sunat[ini+terc].dni > k)
		return busquedaTernaria(sunat, ini, ini+terc-1, k);
	else if (sunat[fin-terc].dni > k)
		return busquedaTernaria(sunat, ini+terc+1, fin-terc-1, k);
	else
		return busquedaTernaria(sunat, fin-terc+1, fin, k);

}

void obtenerLineaCreditoBancoA(FILE *archSalida, tipoPersona persona[], tipoInfocorp infocorp[], tipoReniec reniec[], tipoSunat sunat[], int nPersonas, int nPersonasBanco){

	fprintf(archSalida, "\n%40s\n\n", "BANCO A");

	int i;
	double creditoA;

	/* Iniciamos el conteo del tiempo */	
	clock_t t_ini_sort = clock();	

	for (i = 0; i < nPersonasBanco; i++){

		int pos = busquedaTernaria(sunat, 0, nPersonas-1, persona[i].dni);
		
		if (pos != -1){
			creditoA = calcularCreditoA(infocorp[pos].riesgo, reniec[pos].cargaFamiliar, sunat[pos].montoFact);			
			imprimirSalidaCredito(archSalida, persona[i], creditoA);					
		}	
		else
			fprintf(archSalida, "                PERSONA CON DNI N° %.8d NO ENCONTRADA\n", persona[i].dni);
	
		
	}	

	/* Detenemos el conteo del tiempo */
	clock_t t_fin_sort = clock();

	printf("\nTIEMPO DE BUSQUEDA DEL BANCO A: %.20f ms\n",((double)t_fin_sort-t_ini_sort)*1000.0/CLOCKS_PER_SEC);

}

void obtenerLineaCreditoBancoB(FILE *archSalida, tipoPersona persona[], tipoInfocorp infocorp[], tipoReniec reniec[], tipoSunat sunat[], int nPersonas, int nPersonasBanco){

	fprintf(archSalida, "\n%40s\n\n", "BANCO B");

	int i;
	double creditoB;

	/* Iniciamos el conteo del tiempo */
	clock_t t_ini_sort = clock();

	for (i = 0; i < nPersonasBanco; i++){

		int pos = busquedaTernaria(sunat, 0, nPersonas-1, persona[i].dni);
		
		if (pos != -1){
			creditoB = calcularCreditoB(infocorp[pos].riesgo, reniec[pos].cargaFamiliar, sunat[pos].montoFact);			
			imprimirSalidaCredito(archSalida, persona[i], creditoB);					
		}
		else
			fprintf(archSalida, "                PERSONA CON DNI N° %.8d NO ENCONTRADA\n", persona[i].dni);
		
	}	

	/* Detenemos el conteo del tiempo */
	clock_t t_fin_sort = clock();

	printf("\nTIEMPO DE BUSQUEDA DEL BANCO B: %.20f ms\n",((double)t_fin_sort-t_ini_sort)*1000.0/CLOCKS_PER_SEC);

}

void obtenerLineaCreditoBancoC(FILE *archSalida, tipoPersona persona[], tipoInfocorp infocorp[], tipoReniec reniec[], tipoSunat sunat[], int nPersonas, int nPersonasBanco){

	fprintf(archSalida, "\n%40s\n\n", "BANCO C");

	/* Iniciamos el conteo del tiempo */
	clock_t t_ini_sort = clock();

	int i;
	double creditoC;
	for (i = 0; i < nPersonasBanco; i++){

		int pos = busquedaTernaria(sunat, 0, nPersonas-1, persona[i].dni);
		
		if (pos != -1){
			creditoC = calcularCreditoC(infocorp[pos].riesgo, reniec[pos].cargaFamiliar, sunat[pos].montoFact);			
			imprimirSalidaCredito(archSalida, persona[i], creditoC);					
		}	
		else
			fprintf(archSalida, "                PERSONA CON DNI N° %.8d NO ENCONTRADA\n", persona[i].dni);
		
	}	

	/* Detenemos el conteo del tiempo */
	clock_t t_fin_sort = clock();

	printf("\nTIEMPO DE BUSQUEDA DEL BANCO C: %.20f ms\n",((double)t_fin_sort-t_ini_sort)*1000.0/CLOCKS_PER_SEC);

}


void obtenerLineaCredito(tipoPersona persona[], tipoInfocorp infocorp[], tipoReniec reniec[], tipoSunat sunat[], int nPersonas, int nPersonasBanco){
	
	FILE *archSalida;
	char nombArchSal[MAX_CHAR];
	double creditoA, creditoB, creditoC;
	int pos;

	/* Pedimos al usuario crear el archivo de linea de credito y prepararlo para la impresion*/
	
	printf("\nINGRESE EL NOMBRE DEL ARCHIVO DE SALIDA DE LA LINEA DE CREDITO: ");
	scanf("%s", nombArchSal);
	
	archSalida = fopen(nombArchSal, "w");
	
	/* Procedemos a calcular la linea de credito por banco*/

	obtenerLineaCreditoBancoA(archSalida, persona, infocorp, reniec, sunat, nPersonas, nPersonasBanco);

	obtenerLineaCreditoBancoB(archSalida, persona, infocorp, reniec, sunat, nPersonas, nPersonasBanco);
 
	obtenerLineaCreditoBancoC(archSalida, persona, infocorp, reniec, sunat, nPersonas, nPersonasBanco);
	
	/* Cerramos archivos */
	
	fclose(archSalida);

}

/* Programa Principal */

int main(){

	/* Registros Sunat, Reniec e Infocorp */

	tipoSunat sunat[1200];
	tipoReniec reniec[1200];
	tipoInfocorp infocorp[1200];
	tipoPersona persona[300];
	int nPersonas = 0, nPersonasBanco = 0;

	/* Obtener Registros */

	leerRegistroSunat(sunat, &nPersonas);
	leerRegistroReniec(reniec, &nPersonas);
	leerRegistroInfocorp(infocorp, &nPersonas);

	imprimirCabecera1();

	/* Ordenar el registro de un archivo mediante diferentes campos */

	ordenarmientoRegistro(sunat, reniec, infocorp, nPersonas);	
	
	/* Proceso de Bancos */

	leerRegistroPersonas(persona, &nPersonasBanco);
	
	/* Ordenamos respecto a los numeros del dni */
	
	shellSort_Infocorp(infocorp, nPersonas, 4, 2); 
	shellSort_Reniec(reniec, nPersonas, 4, 2);
	shellSort_Sunat(sunat, nPersonas, 4, 2);

	imprimirCabecera2();
	
	/* Calculamos la linea de credito */
	
	obtenerLineaCredito(persona, infocorp, reniec, sunat, nPersonas, nPersonasBanco);	

	imprimirGuiones();

	return 0;

}
