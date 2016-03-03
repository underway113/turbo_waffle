#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct mhs{
	int nilai;
	char nama[25];
	char nim[11];
	struct mhs *next; //Untuk menunjuk ke record mhs berikutnya
};

struct mhs *head = NULL;

void insertHead(struct mhs *data){
	if (head == NULL){
		head = data;

	}else{
		data->next = head;
		head=data;
	}
}

void insertMiddle (struct mhs *pos, struct mhs *data){ //Fungsi ini melakukan insert di akhir
	if (head == NULL){
		head = data;

	}else{
		data->next = pos->next;
		pos->next = data;
	}
}

void insertLast (struct mhs *data){ //Fungsi ini melakukan insert di akhir
	if (head == NULL){
		head = data;
	}else{
		struct mhs *ptr = head;
		while (ptr->next !=NULL) ptr = ptr->next;
		ptr->next = data;
	}
}

void deleteHead(){
	if(head==NULL) return;
	struct mhs *ptr = head;
	head = head->next;
	free(ptr);
}

void deleteMiddle(struct mhs *pos){ //MasihError
	if(head!=NULL){
		struct mhs *ptr = head;
		while(ptr->next != pos && ptr->next !=NULL){
			ptr=ptr->next;
		}
		if(ptr->next != NULL){
			ptr->next = pos->next;
			free(pos);
		}
	}
}

void deleteLast(){
	//TUGAS
}



struct mhs *createMhs(char *nim, char *nama, int nilai){
	struct mhs *cur = (struct mhs *) malloc (sizeof(struct mhs));
	strcpy (cur-> nama, nama);
	strcpy(cur->nim,nim);
	cur->nilai = nilai;
	cur->next = NULL;
	return cur;
}

struct mhs *searchByNim(char *nim){
	struct mhs *cur =head;
	while(cur !=NULL){
		if(strcmp(cur->nim,nim) == 0){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void print(){
	struct mhs *cur = head;
	while(cur !=NULL){
	printf("%s %s %d\n",cur->nim,cur->nama,cur->nilai);
	cur=cur->next;
	}
}

int main(){
	struct mhs *p = createMhs("1901466641","Jeremy", 100);
	struct mhs *q  = createMhs("048320845","Adam", 99);
	struct mhs *r  = createMhs("789103615","Testing", 45);
	struct mhs *s  = createMhs("489456106","DeadPoll", 79);
	struct mhs *t  = createMhs("081557892","Polling", 50);
	insertLast(p);
	insertLast(q);
	insertLast(s);
	insertLast(t);
	deleteMiddle(s);
	struct mhs *temp;
	temp = searchByNim("1901466641");
	printf("%s %d\n",temp->nama,temp->nilai);
	print();
	free(p);
	free(q);
	getchar();
	return 0;
}