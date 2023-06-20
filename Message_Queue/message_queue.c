//TO WRITE DATA

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 100

struct msg_buffer
{
	long msg_type;
	char msg_text[100];
}message;

void main()
{
	key_t key;
	int msgid;
	key=ftok("progfile",65);
	msgid=msgget(key,0666|IPC_CREAT);
	message.msg_type=1;
	printf("Write data to be read:");
	fgets(message.msg_text,MAX,stdin);
	msgsnd(msgid,&message,sizeof(message),0);
	printf("Data send is:%s\n",message.msg_text);
}


//TO READ DATA

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer
{
	long msg_type;
	char msg_text[100];
}message;

void main()
{
	key_t key;
	int msgid;
	key=ftok("progfile",65);
	msgid=msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("The data recieved is:%s\n",message.msg_text);
	msgctl(msgid,IPC_RMID,NULL);
}

