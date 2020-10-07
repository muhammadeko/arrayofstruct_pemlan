#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mahasiswa{
	char npm[12];
	char nama[50];
	char email[50];
	char nohp[50];
	int tinggi;
	int berat;
	int umur;
}mhs;
mhs data_mhs[]={
		{"19081010097","Muhammad Eko Prasetyo","muhammadeko.if@gmail.com","089677717105",168,48,20}
	};	
int size;
void insert(char npm[12],char nama[50],char email[50], char nohp[14], int tinggi, int berat, int umur){
	strcpy(data_mhs[size].npm,npm);
	strcpy(data_mhs[size].nama,nama);
	strcpy(data_mhs[size].email,email);
	strcpy(data_mhs[size].nohp,nohp);
	data_mhs[size].tinggi=tinggi;
	data_mhs[size].berat=berat;
	data_mhs[size].umur=umur;
	size++;
}
void update(int index,char npm[12],char nama[50],char email[50], char nohp[14], int tinggi, int berat, int umur){
	strcpy(data_mhs[index].npm,npm);
	strcpy(data_mhs[index].nama,nama);
	strcpy(data_mhs[index].email,email);
	strcpy(data_mhs[index].nohp,nohp);
	data_mhs[index].tinggi=tinggi;
	data_mhs[index].berat=berat;
	data_mhs[index].umur=umur;
}
void delete(int index){
	int i=0;
	for(i=0;i<size;i++){
		if(i==index){
			int y=0;
			for(y=i;y<size-1;y++){
				data_mhs[y]=data_mhs[y+1];
			}
			size--;
			break;
		}
	}
}
void view(){
	int i;
	if(size>0){
		for(i=0;i<size;i++){
			printf("Mahasiswa ke \t\t: %d\n",i+1);
			printf("NPM \t\t\t: %s\n",data_mhs[i].npm);	
			printf("Nama \t\t\t: %s\n",data_mhs[i].nama);
			printf("Email \t\t\t: %s\n",data_mhs[i].email);
			printf("No HP \t\t\t: %s\n",data_mhs[i].nohp);
			printf("Tinggi \t\t\t: %d\n",data_mhs[i].tinggi);
			printf("Berat \t\t\t: %d\n",data_mhs[i].berat);
			printf("Umur \t\t\t: %d\n\n",data_mhs[i].umur);
		}
	}else{
		printf("TIDAK ADA DATA\n\n");
	}
}
int main() {
	size = sizeof(data_mhs)/sizeof(data_mhs[0]);
	int i=0;
	int pilih=0;
	int tinggi,berat,umur;
	char npm[12],nama[50],email[50],nohp[14];
	awal:
	printf("====== Aplikasi Sederhana Data Mahasiswa ======\n");
	printf("List Data Mahasiswa: \n\n");
	view();
	printf("Menu :\n1. Insert Data\n2. Update Data\n3. Delete Data\n4. Exit\nPilih menu : ");
	pilih:
	scanf("%d",&pilih);
	if(pilih==1){
		printf("NPM : ");
		scanf("%s",&npm);
		printf("Nama : ");
		scanf(" %[^\n]s",&nama);
		printf("Email : ");
		scanf("%s",&email);
		printf("No HP : ");
		scanf("%s",&nohp);
		printf("Tinggi : ");
		scanf("%d",&tinggi);
		printf("Berat : ");
		scanf("%d",&berat);
		printf("Umur : ");
		scanf("%d",&umur);
		insert(npm,nama,email,nohp,tinggi,berat,umur);
		system("cls");
		goto awal;	
	}else if(pilih==2){
		int no;
		printf("Masukkan nomor data yang akan diedit : ");
		input_edit:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data dengan nomor %d, mohon masukkan kembali : ",no);
			goto input_edit;
		}else{
			printf("NPM : ");
			scanf("%s",&npm);
			printf("Nama : ");
			scanf(" %[^\n]s",&nama);
			printf("Email : ");
			scanf("%s",&email);
			printf("No HP : ");
			scanf("%s",&nohp);
			printf("Tinggi : ");
			scanf("%d",&tinggi);
			printf("Berat : ");
			scanf("%d",&berat);
			printf("Umur : ");
			scanf("%d",&umur);
			update(no-1,npm,nama,email,nohp,tinggi,berat,umur);
			system("cls");
			goto awal;
		}
	}else if(pilih==3){
		int no;
		printf("Masukkan nomor data yang akan dihapus : ");
		input_delete:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data dengan nomor %d, mohon masukkan kembali : ",no);
			goto input_delete;
		}else{
			delete(no-1);
			system("cls");
			goto awal;
		}
	}else if(pilih==4){
		printf("Terimakasih telah menggunakan program ini.");
		return 0;
	}else{
		printf("Inputan anda salah. Mohon masukkan kembali : ");
		goto pilih;
	}
}
