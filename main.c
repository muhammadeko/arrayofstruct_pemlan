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
		{"19081010097","Muhammad Eko Prasetyo5","muhammadeko.if@gmail.com2","089677717101",168,48,20},
		{"19081010098","Muhammad Eko Prasetyo4","muhammadeko.if@gmail.com4","089677717104",169,58,22},
		{"19081010094","Muhammad Eko Prasetyo3","muhammadeko.if@gmail.com3","089677717103",179,38,21},
		{"19081010095","Muhammad Eko Prasetyo2","muhammadeko.if@gmail.com5","089677717102",171,68,24},
		{"19081010099","Muhammad Eko Prasetyo1","muhammadeko.if@gmail.com1","089677717105",166,78,23}
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
void bubble_sort(int pilih,int type){
	int i,j;
	for(i = 0; i < size-1; i++) 
        {
            for(j = 0; j < size-i-1; j++)
            {
            	int tukar;
				switch(pilih){
					case 1:
						tukar=strcmp(data_mhs[j].npm,data_mhs[j+1].npm)>0?1:0;
						break;
					case 2:
						tukar=strcmp(data_mhs[j].nama,data_mhs[j+1].nama)>0?1:0;
						break;
					case 3:
						tukar=strcmp(data_mhs[j].email,data_mhs[j+1].email)>0?1:0;
						break;
					case 4:
						tukar=strcmp(data_mhs[j].nohp,data_mhs[j+1].nohp)>0?1:0;
						break;
					case 5:
						tukar=data_mhs[j].tinggi>data_mhs[j+1].tinggi?1:0;
						break;
					case 6:
						tukar=data_mhs[j].berat>data_mhs[j+1].berat?1:0;
						break;
					case 7:
						tukar=data_mhs[j].umur>data_mhs[j+1].umur?1:0;
						break;
				}
				if(type==1&&tukar==1){
					mhs temp;
					temp=data_mhs[j];
					data_mhs[j]=data_mhs[j+1];
					data_mhs[j+1]=temp;
				}
				if(type==2&&tukar==0){
					mhs temp;
					temp=data_mhs[j];
					data_mhs[j]=data_mhs[j+1];
					data_mhs[j+1]=temp;
				}
            }
        }
}
void selection_sort(int pilih,int type){
	int i,j,min_idx;
	for(i = 0; i < size-1; i++) 
        {
        	min_idx=i;
            for(j = i+1; j < size; j++)
            {
				if(type==1){
					switch(pilih){
						case 1:
							min_idx=strcmp(data_mhs[j].npm,data_mhs[min_idx].npm)>0?j:i;
							break;
						case 2:
							min_idx=strcmp(data_mhs[j].nama,data_mhs[min_idx].nama)>0?j:i;
							break;
						case 3:
							min_idx=strcmp(data_mhs[j].email,data_mhs[min_idx].email)>0?j:i;
							break;
						case 4:
							min_idx=strcmp(data_mhs[j].nohp,data_mhs[min_idx].nohp)>0?j:i;
							break;
						case 5:
							min_idx=data_mhs[j].tinggi<data_mhs[min_idx].tinggi?j:i;
							break;
						case 6:
							min_idx=data_mhs[j].berat<data_mhs[min_idx].berat?j:i;
							break;
						case 7:
							min_idx=data_mhs[j].umur<data_mhs[min_idx].umur?j:i;
							break;
					}
				}else if(type==2){
					switch(pilih){
						case 1:
							min_idx=strcmp(data_mhs[j].npm,data_mhs[min_idx].npm)<0?j:i;
							break;
						case 2:
							min_idx=strcmp(data_mhs[j].nama,data_mhs[min_idx].nama)<0?j:i;
							break;
						case 3:
							min_idx=strcmp(data_mhs[j].email,data_mhs[min_idx].email)<0?j:i;
							break;
						case 4:
							min_idx=strcmp(data_mhs[j].nohp,data_mhs[min_idx].nohp)<0?j:i;
							break;
						case 5:
							min_idx=data_mhs[j].tinggi>data_mhs[min_idx].tinggi?j:i;
							break;
						case 6:
							min_idx=data_mhs[j].berat>data_mhs[min_idx].berat?j:i;
							break;
						case 7:
							min_idx=data_mhs[j].umur>data_mhs[min_idx].umur?j:i;
							break;
					}
				}
            }
            mhs temp;
            temp=data_mhs[min_idx];
			data_mhs[min_idx]=data_mhs[i];
			data_mhs[i]=temp;
        }
}
mhs sequential_search(int pilih,int i_temp, char c_temp[50]){
	int flag=0,i,idx=-1;
	for(i=0;i<size;i++){
		switch(pilih){
			case 1:
				flag=strcmp(data_mhs[i].npm,c_temp)==0?1:0;
				break;
			case 2:
				flag=strcmp(data_mhs[i].nama,c_temp)==0?1:0;
				break;
			case 3:
				flag=strcmp(data_mhs[i].email,c_temp)==0?1:0;
				break;
			case 4:
				flag=strcmp(data_mhs[i].nohp,c_temp)==0?1:0;
				break;
			case 5:
				flag=data_mhs[i].tinggi==i_temp?1:0;
				break;
			case 6:
				flag=data_mhs[i].berat==i_temp?1:0;
				break;
			case 7:
				flag=data_mhs[i].umur==i_temp?1:0;
				break;
		}
		if(flag==1)idx=i;
	}
	return data_mhs[idx];	
}
mhs binary_search(int pilih,int i_temp, char c_temp[50]){
	int ktm=0;
	int l=0,r=size-1,m,idx=-1;
	bubble_sort(pilih,1);
	while(l<=r&&ktm==0){
		m=(l+r)/2;
		switch(pilih){
			case 1:
				if(strcmp(data_mhs[m].npm,c_temp)==0)ktm=1;
				else if(strcmp(c_temp,data_mhs[m].npm)<0)r=m-1;
				else l=m+1;
				break;
			case 2:
				if(strcmp(data_mhs[m].nama,c_temp)==0)ktm=1;
				else if(strcmp(c_temp,data_mhs[m].nama)<0)r=m-1;
				else l=m+1;
				break;
			case 3:
				if(strcmp(data_mhs[m].email,c_temp)==0)ktm=1;
				else if(strcmp(c_temp,data_mhs[m].email)<0)r=m-1;
				else l=m+1;
				break;
			case 4:
				if(strcmp(data_mhs[m].nohp,c_temp)==0)ktm=1;
				else if(strcmp(c_temp,data_mhs[m].nohp)<0)r=m-1;
				else l=m+1;
				break;
			case 5:
				if(data_mhs[m].tinggi==i_temp)ktm=1;
				else if(i_temp<data_mhs[m].tinggi)r=m-1;
				else l=m+1;
				break;
			case 6:
				if(data_mhs[m].berat==i_temp)ktm=1;
				else if(i_temp<data_mhs[m].berat)r=m-1;
				else l=m+1;
				break;
			case 7:
				if(data_mhs[m].umur==i_temp)ktm=1;
				else if(i_temp<data_mhs[m].umur)r=m-1;
				else l=m+1;
				break;
		}
		if(ktm==1)idx=m;
	}
	return data_mhs[idx];
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
	printf("Menu :\n1. Insert Data\n2. Update Data\n3. Delete Data\n4. Urutkan\n5. Sequential Search\n6. Binary Search\n7. Exit\nPilih menu : ");
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
		if(no>size||no<1){
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
		if(no>size||no<1){
			printf("Tidak ada data dengan nomor %d, mohon masukkan kembali : ",no);
			goto input_delete;
		}else{
			delete(no-1);
			system("cls");
			goto awal;
		}
	}else if(pilih==4){
		int type,pilih,metode;
		input_metode:
		printf("Silahkan masukkan metode pengurutan:\n1. Bubble Sort\n2. Selection Sort\nPilihan anda : ");
		scanf("%d",&metode);
		if(metode>2||metode<1){
			printf("Inputan anda salah.\n"); 
			goto input_metode;
		};
		input_pilih:
		printf("Silahkan pilih data mana yang akan anda urutkan:\n1. NPM\n2. Nama\n3. Email\n4. No HP\n5. Tinggi\n6. Berat\n7. Umur\nPilihan anda : ");
		scanf("%d",&pilih);
		if(pilih>7||pilih<1){
			printf("Inputan anda salah.\n"); 
			goto input_pilih;
		};
		input_type:
		printf("Silahkan pilih urutan:\n1. Ascending\n2. Descending\nPilihan anda : ");
		scanf("%d",&type);
		if(type>2||type<1){
			printf("Inputan anda salah.\n"); 
			goto input_type;
		};
		if(metode==1){
			bubble_sort(pilih,type);
		}else{
			selection_sort(pilih,type);
		}
		system("cls");
		goto awal;		
	}else if(pilih==5||pilih==6){
		char cari_c[50];
		int cari_i;
		input_pilih_seq:
		printf("Silahkan pilih data mana yang akan anda urutkan:\n1. NPM\n2. Nama\n3. Email\n4. No HP\n5. Tinggi\n6. Berat\n7. Umur\nPilihan anda : ");
		scanf("%d",&pilih);
		if(pilih>7||pilih<1){
			printf("Inputan anda salah.\n"); 
			goto input_pilih_seq;
		};
		printf("Masukkan data yang akan dicari : ");
		if(pilih>0&&pilih<=4){
			scanf(" %[^\n]s",&cari_c);
		}else if(pilih>4&&pilih<=7){
			scanf("%d",&cari_i);
		}
		mhs hasil=pilih==5?sequential_search(pilih,cari_i,cari_c):binary_search(pilih,cari_i,cari_c);
		if(hasil.tinggi==0){
			printf("Tidak ada data.");
		}else{
			printf("Data ditemukan : \n");
			printf("NPM \t\t\t: %s\n",hasil.npm);	
			printf("Nama \t\t\t: %s\n",hasil.nama);
			printf("Email \t\t\t: %s\n",hasil.email);
			printf("No HP \t\t\t: %s\n",hasil.nohp);
			printf("Tinggi \t\t\t: %d\n",hasil.tinggi);
			printf("Berat \t\t\t: %d\n",hasil.berat);
			printf("Umur \t\t\t: %d\n\n",hasil.umur);
		}
		printf("Tekan tombol apa saja untuk kembali ke awal");
		getch();
		system("cls");
		goto awal;
	}else if(pilih==7){
		printf("Terimakasih telah menggunakan program ini.");
		return 0;
	}else{
		printf("Inputan anda salah. Mohon masukkan kembali : ");
		goto pilih;
	}
}
