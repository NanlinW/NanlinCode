#pragma once
#pragma once  
#include "winsock2.h"
#include "stdio.h"
#pragma comment(lib,"ws2_32.lib")
//���������ܳ���������ĺ�
#define TRUE			1
#define FALSE			0
#define	MAXLINE		    200	    // max text line length 
#define	DEFAULT_NAMELEN 100 //Ĭ�ϵ����ֳ���

typedef struct tagTCPHDR		//TCP�ײ�����
{
	USHORT  sport;            //Source port 
	USHORT  dport;            //Destination port 
	ULONG   seq;              //Sequence number 
	ULONG   ack;              //Ack number 
	BYTE    hlen;             // TCP header len (num of bytes << 2) 
	BYTE    flags;            // Option flags 
	USHORT  window;           // Flow control credit (num of bytes) 
	USHORT  check;            // Checksum 
	USHORT  urgent;           // Urgent data pointer 
} TCPHDR, * PTCPHDR;
//TCP��־�ֶζ���
#define TFIN        0x01    // Option flags: no more data 
#define TSYN        0x02    // sync sequence nums 
#define TRST        0x04    // reset connection 
#define TPUSH       0x08    // push buffered data 
#define TACK        0x10    // acknowledgement 
#define TURGE       0x20    // urgent 

//������Ҫʵ�ֵĳ�Ա����
class CSocketFrame
{
public:
	CSocketFrame(void); //���캯��
	~CSocketFrame(void); //��������
	int set_address(char* hname, char* sname, struct sockaddr_in* sap, char* protocol);
	//���ݸ���������������ʮ����IP��ַ���socket_in�ṹ�洢�ĵ�ַ
	int start_up(void); //Windows Sockets ��ʼ������
	int clean_up(void); //Windows Sockets ��Դ�ͷź���
	int quit(SOCKET s); //�˳�������
	SOCKET udp_server(char* hname, char* sname);//��ʽ�׽��ַ�������ʼ������
	int recvn(SOCKET s, char* recvbuf, unsigned int fixedlen); //���ն�������
	int recvvl(SOCKET s, char* recvbuf, unsigned int recvbuflen);//���ձ䳤����
	SOCKET udp_client(char* hname, char* sname); //��ʽ�׽��ֿͻ��˳�ʼ������

};
