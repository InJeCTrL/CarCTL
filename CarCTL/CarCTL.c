#include<Windows.h>
#include<winsock.h>
#include<stdio.h>
#pragma comment(lib, "ws2_32.lib")

//���ؼ�ID
#define ID_StcTIPConnect	3301//��ʾ"���������IP��ַ��˿ں�"
#define ID_BtnConnect		3303//���ӷ�������ť
#define ID_EditIP			3304//���ӷ�����IP��ַ�����
#define ID_EditPort			3305//���ӷ������˿ں������

#define ID_BtnSndLUP		3306//�����������ּ��ٰ�ť
#define ID_BtnSndLDOWN		3307//�����������ּ��ٰ�ť
#define ID_BtnSndLSTOP		3308//������������ֹͣ��ť
#define ID_BtnSndRUP		3309//�����������ּ��ٰ�ť
#define ID_BtnSndRDOWN		3310//�����������ּ��ٰ�ť
#define ID_BtnSndRSTOP		3311//������������ֹͣ��ť
#define ID_BtnSndCWA		3312//��������ԭ����ʱ����ת��ť
#define ID_BtnSndCWB		3313//��������ԭ��˳ʱ����ת��ť
#define ID_BtnSndRCWA		3314//����������ʱ��תȦ�ܰ�ť
#define ID_BtnSndRCWB		3315//��������˳ʱ��תȦ�ܰ�ť
#define ID_BtnSndSTOP		3316//��������ͣ����ť
#define ID_BtnSndGET		3317//���������ȡ��ǰ���ݰ�ť
#define ID_EditSHOWS1		3328//��ʾС���ٶȴ�����Ϣ
#define ID_EditSHOWS2		3329//��ʾС���ٶȴ�����Ϣ
#define ID_EditSHOWS3		3330//��ʾС���ٶȴ�����Ϣ
#define ID_EditSHOWS4		3331//��ʾС���ٶȴ�����Ϣ
#define ID_EditSHOWD1		3332//��ʾС�����봫����Ϣ
#define ID_EditSHOWD2		3333//��ʾС�����봫����Ϣ
#define ID_EditSHOWD3		3334//��ʾС�����봫����Ϣ
#define ID_EditSHOWD4		3335//��ʾС�����봫����Ϣ
#define ID_EditSHOWX		3336//��ʾС�����봫����Ϣ
#define ID_EditSHOWY		3337//��ʾС�����봫����Ϣ
#define ID_EditSHOWZ		3338//��ʾС�����봫����Ϣ

#define ID_BtnAhead			3319//��������ǰ����ť
#define ID_BtnBack			3320//����������˰�ť
#define ID_BtnStop			3321//��������ͣ����ť
#define ID_BtnLeft			3322//��������<Ԥ��>��ť
#define ID_BtnRight			3323//��������<Ԥ��>��ť
#define ID_BtnLAhead		3324//��������ǰ��ת�䰴ť
#define ID_BtnRAhead		3325//��������ǰ��ת�䰴ť
#define ID_BtnLBACK			3326//�����������ת�䰴ť
#define ID_BtnRBACK			3327//�����������ת�䰴ť

#define ID_BtnC1			3339//��������������ͣ��ť
#define ID_BtnC2			3340//��������������ͣ��ť
#define ID_BtnC3			3341//��������������ͣ��ť
#define ID_BtnC4			3342//��������������ͣ��ť
#define ID_BtnC5			3343//��������������ͣ��ť
#define ID_BtnC6			3344//��������������ͣ��ť
#define ID_BtnC7			3345//��������������ͣ��ť
#define ID_BtnC8			3346//��������������ͣ��ť

//�ؼ��ߴ���Ϣ
#define Width_Screen		(GetSystemMetrics(SM_CXSCREEN))//��Ļ���
#define Height_Screen		(GetSystemMetrics(SM_CYSCREEN))//��Ļ�߶�
#define Width_Window		770//��������
#define Height_Window		680//������߶�

//�����б�
#define CMD_LUP				"left+\r\n"//���ּ���
#define CMD_LDOWN			"left-\r\n"//���ּ���
#define CMD_LSTOP			"left0\r\n"//����ֹͣ
#define CMD_RUP				"right+\r\n"//���ּ���
#define CMD_RDOWN			"right-\r\n"//���ּ���
#define CMD_RSTOP			"right0\r\n"//����ֹͣ
#define CMD_CWA				"cw1\r\n"//˳ʱ����ת
#define CMD_CWB				"ccw1\r\n"//��ʱ����ת
#define CMD_RCWA			"runcw\r\n"//��ʱ��תȦ��
#define CMD_RCWB			"runccw\r\n"//˳ʱ��תȦ��
#define CMD_STOP			"stop\r\n"//ͣ��
#define CMD_GET				"get\r\n"//��ȡС��״̬����
#define CMD_SPEED			"inc\r\n"//С����ǰ����
#define CMD_SLOW			"dec\r\n"//С������
#define CMD_COLLECTON		"collecton\r\n"//����������
#define CMD_COLLECTOFF		"collectoff\r\n"//������ֹͣ
#define CMD_MOVEON			"movon\r\n"//����������
#define CMD_MOVEOFF			"movoff\r\n"//������ֹͣ

//���ؼ����
HWND hMainWND;			//������
HWND hFont;				//ͳһ����
HWND hFont_CTL;			//����������

HWND hBtn_Connect;		//���Ӱ�ť
HWND hBtn_LUP;			//����"���ּ���"��ť
HWND hBtn_LDOWN;		//����"���ּ���"��ť
HWND hBtn_LSTOP;		//����"����ֹͣ"��ť
HWND hBtn_RUP;			//����"���ּ���"��ť
HWND hBtn_RDOWN;		//����"���ּ���"��ť
HWND hBtn_RSTOP;		//����"����ֹͣ"��ť
HWND hBtn_CWA;			//����"ԭ����ʱ����ת"��ť
HWND hBtn_CWB;			//����"ԭ��˳ʱ����ת"��ť
HWND hBtn_RCWA;			//����"��ʱ����ת��"��ť
HWND hBtn_RCWB;			//����"˳ʱ����ת��"��ť
HWND hBtn_STOP;			//����"ͣ��"��ť
HWND hBtn_GET;			//����"��ȡС��״̬����"��ť
HWND hBtn_Ahead;		//����"ǰ��"��ť
HWND hBtn_Back;			//����"����"��ť
HWND hBtn_Stop;			//����"ֹͣ"��ť
HWND hBtn_Left;			//����"<Ԥ��>"��ť
HWND hBtn_Right;		//����"<Ԥ��>"��ť
HWND hBtn_LAhead;		//����"��ǰ��ת��"��ť
HWND hBtn_RAhead;		//����"��ǰ��ת��"��ť
HWND hBtn_LBack;		//����"���ת��"��ť
HWND hBtn_RBack;		//����"�ҷ���ת��"��ť
HWND hBtn_CTRL[8];		//����"����/��������ͣ"��ť

HWND hText_TipConnect;	//"���������IP��ַ��˿ں�"
HWND hText_TipSpeed;	//"�ٶȣ�"
HWND hText_TipSpeed1;	//"�ٶ�1"
HWND hText_TipSpeed2;	//"�ٶ�2"
HWND hText_TipSpeed3;	//"�ٶ�3"
HWND hText_TipSpeed4;	//"�ٶ�4"
HWND hText_TipXYZ;		//"ˮƽ�ǣ�"
HWND hText_TipX;		//"X:"
HWND hText_TipY;		//"Y:"
HWND hText_TipZ;		//"Z:"
HWND hText_TipDist;		//"���룺"
HWND hText_TipDist1;	//"����1"
HWND hText_TipDist2;	//"����2"
HWND hText_TipDist3;	//"����3"
HWND hText_TipDist4;	//"����4"

HWND hEdit_IP;			//IP��ַ����
HWND hEdit_Port;		//�˿ں�����
HWND hEdit_ShowArgu[11];//�����ٶȡ����롢ˮƽ����Ϣ���

SOCKET fd_socket;//socket������
struct sockaddr_in SA;
HANDLE hThread;//������Ϣ�߳̾��
INT flag_conn = 0;//��ǵ�ǰ�Ƿ�����״̬
WSADATA WSAData = { 0 };

//��ǰ����
INT SPEED(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_SPEED);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//����
INT SLOW(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_SLOW);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//���ּ���
INT LUP(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_LUP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//���ּ���
INT RUP(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_RUP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//���ּ���
INT LDOWN(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_LDOWN);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//���ּ���
INT RDOWN(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_RDOWN);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//����ֹͣ
INT LSTOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_LSTOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//����ֹͣ
INT RSTOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_RSTOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//ԭ����ʱ����ת
INT CWA(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_CWA);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//ԭ��˳ʱ����ת
INT CWB(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_CWB);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//��ʱ��תȦ��
INT RCWA(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_RCWA);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//˳ʱ��תȦ��
INT RCWB(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����
	
	strcpy(Buf_Send, CMD_RCWB);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//ͣ��
INT STOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_STOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//��ȡС������
INT GET(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_GET);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//����������
INT COLLECTON(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_COLLECTON);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//ֹͣ������
INT COLLECTOFF(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_COLLECTOFF);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//����������
INT MOVEON(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_MOVEON);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//ֹͣ������
INT MOVEOFF(void)
{
	CHAR Buf_Send[1024] = { 0 };//���������ݻ�����

	strcpy(Buf_Send, CMD_MOVEOFF);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
DWORD WINAPI RecvShow(LPVOID lpParam)
{
	CHAR Buf_Recv_ANSI[1024] = { 0 };//���������ݻ�����(���ַ�)
	CHAR Buf_Set_ANSI[20] = { 0 };//���������ݻ�����(���ַ�)
	TCHAR Buf_Set[20] = { 0 };//���������ݻ�����(���ַ�)
	CHAR *ptr_slow = NULL, *ptr_fast = NULL;
	INT num_Recv;//�յ����ַ���
	INT i;//ָ�����õı༭����

	while (TRUE)
	{
		num_Recv = recv(fd_socket, Buf_Recv_ANSI, 1023, 0);
		//�������˶Ͽ�����
		if (num_Recv <= 0)
		{
			SetWindowText(hBtn_Connect, L"����");
			SetWindowPos(hMainWND, HWND_TOP, 0, 0, Width_Window, 100, SWP_NOMOVE);
			closesocket(fd_socket);//�ر�socket
			flag_conn = 0;
			EnableWindow(hEdit_IP, TRUE);
			EnableWindow(hEdit_Port, TRUE);
			break;
		}
		Buf_Recv_ANSI[num_Recv] = 0;
		for (i = 0; i < 11; i++)
		{
			SetWindowText(hEdit_ShowArgu[i], L"");
		}
		ptr_slow = Buf_Recv_ANSI;
		ptr_fast = ptr_slow + 1;
		i = 0;
		while (*ptr_fast)
		{
			if (*ptr_fast == ' ')
			{
				*ptr_fast = 0;
				strcpy(Buf_Set_ANSI, ptr_slow);
				mbstowcs(Buf_Set, Buf_Set_ANSI, strlen(Buf_Set_ANSI) + 1);
				SetWindowText(hEdit_ShowArgu[i++], Buf_Set);
				if (i == 11)
					break;
				ptr_slow = ptr_fast + 1;
				ptr_fast = ptr_slow + 1;
			}
			else
			{
				ptr_fast++;
			}
		}
	}

	return 0;
}
LRESULT WINAPI CtlProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR IPaddr[1024] = { 0 };//���IP��ַ�ַ���(���ֽ�)
	CHAR IPaddr_ANSI[1024] = { 0 };//���IP��ַ�ַ���(���ֽ�)
	TCHAR Port[512] = { 0 };//��Ŷ˿ں��ַ���(���ֽ�)
	CHAR Port_ANSI[512] = { 0 };//��Ŷ˿ں��ַ���(���ֽ�)
	static INT flag_onoff[8] = { 0 };//�������/��������ͣ״̬(0ֹͣ;1����)
	INT result_Conn;//���ӽ��
	INT i;//���ز���չʾ�ؼ����

	switch (message)
	{
	case WM_CREATE:
		hFont = CreateFont(-14, -7, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, TEXT("΢���ź�"));
		hFont_CTL = CreateFont(50, 30, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, TEXT("����"));
		hText_TipConnect = CreateWindow(L"Static", L"���������IP��ַ��˿ں�", WS_CHILD | WS_VISIBLE, 15, 15, 300, 30, hWnd, NULL, hWnd, 0);
		hEdit_IP = CreateWindow(L"Edit", L"192.168.1.11", WS_BORDER | ES_CENTER | WS_CHILD | WS_VISIBLE, 200, 15, 200, 30, hWnd, (HMENU)ID_EditIP, hWnd, 0);
		hEdit_Port = CreateWindow(L"Edit", L"8080", WS_BORDER | ES_CENTER | WS_CHILD | WS_VISIBLE, 420, 15, 100, 30, hWnd, (HMENU)ID_EditPort, hWnd, 0);
		hBtn_Connect = CreateWindow(L"Button", L"����", WS_CHILD | WS_VISIBLE | WS_BORDER, 530, 15, 200, 30, hWnd, (HMENU)ID_BtnConnect, hWnd, 0);
		hText_TipSpeed = CreateWindow(L"Static", L"�ٶȣ�", WS_CHILD | WS_VISIBLE, 15, 430, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipSpeed1 = CreateWindow(L"Static", L"1��", WS_CHILD | WS_VISIBLE, 15, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[0] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS1, hWnd, 0);
		hText_TipSpeed2 = CreateWindow(L"Static", L"2��", WS_CHILD | WS_VISIBLE, 130, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[1] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS2, hWnd, 0);
		hText_TipSpeed3 = CreateWindow(L"Static", L"3��", WS_CHILD | WS_VISIBLE, 245, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[2] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS3, hWnd, 0);
		hText_TipSpeed4 = CreateWindow(L"Static", L"4��", WS_CHILD | WS_VISIBLE, 360, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[3] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 385, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS4, hWnd, 0);
		hText_TipDist = CreateWindow(L"Static", L"���룺", WS_CHILD | WS_VISIBLE, 15, 500, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipDist1 = CreateWindow(L"Static", L"1��", WS_CHILD | WS_VISIBLE, 15, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[4] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD1, hWnd, 0);
		hText_TipDist2 = CreateWindow(L"Static", L"2��", WS_CHILD | WS_VISIBLE, 130, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[5] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD2, hWnd, 0);
		hText_TipDist3 = CreateWindow(L"Static", L"3��", WS_CHILD | WS_VISIBLE, 245, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[6] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD3, hWnd, 0);
		hText_TipDist4 = CreateWindow(L"Static", L"4��", WS_CHILD | WS_VISIBLE, 360, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[7] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 385, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD4, hWnd, 0);
		hText_TipXYZ = CreateWindow(L"Static", L"ˮƽ�ǣ�", WS_CHILD | WS_VISIBLE, 15, 570, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipX = CreateWindow(L"Static", L"1��", WS_CHILD | WS_VISIBLE, 15, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[8] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWX, hWnd, 0);
		hText_TipY = CreateWindow(L"Static", L"2��", WS_CHILD | WS_VISIBLE, 130, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[9] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWY, hWnd, 0);
		hText_TipZ = CreateWindow(L"Static", L"3��", WS_CHILD | WS_VISIBLE, 245, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[10] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWZ, hWnd, 0);
		hBtn_LUP = CreateWindow(L"Button", L"���ּ���", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 80, 100, 60, hWnd, (HMENU)ID_BtnSndLUP, hWnd, 0);
		hBtn_LDOWN = CreateWindow(L"Button", L"���ּ���", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 150, 100, 60, hWnd, (HMENU)ID_BtnSndLDOWN, hWnd, 0);
		hBtn_LSTOP = CreateWindow(L"Button", L"����ֹͣ", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 220, 100, 60, hWnd, (HMENU)ID_BtnSndLSTOP, hWnd, 0);
		hBtn_RUP = CreateWindow(L"Button", L"���ּ���", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 80, 100, 60, hWnd, (HMENU)ID_BtnSndRUP, hWnd, 0);
		hBtn_RDOWN = CreateWindow(L"Button", L"���ּ���", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 150, 100, 60, hWnd, (HMENU)ID_BtnSndRDOWN, hWnd, 0);
		hBtn_RSTOP = CreateWindow(L"Button", L"����ֹͣ", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 220, 100, 60, hWnd, (HMENU)ID_BtnSndRSTOP, hWnd, 0);
		hBtn_CWA = CreateWindow(L"Button", L"ԭ����ʱ����ת", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 290, 100, 60, hWnd, (HMENU)ID_BtnSndCWA, hWnd, 0);
		hBtn_CWB = CreateWindow(L"Button", L"ԭ��˳ʱ����ת", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 290, 100, 60, hWnd, (HMENU)ID_BtnSndCWB, hWnd, 0);
		hBtn_RCWA = CreateWindow(L"Button", L"��ʱ����ת��", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 360, 100, 60, hWnd, (HMENU)ID_BtnSndRCWA, hWnd, 0);
		hBtn_RCWB = CreateWindow(L"Button", L"˳ʱ����ת��", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 360, 100, 60, hWnd, (HMENU)ID_BtnSndRCWB, hWnd, 0);
		hBtn_STOP = CreateWindow(L"Button", L"ͣ��", WS_CHILD | WS_VISIBLE | WS_BORDER, 265, 80, 100, 160, hWnd, (HMENU)ID_BtnSndSTOP, hWnd, 0);
		hBtn_GET = CreateWindow(L"Button", L"��ȡ״̬����", WS_CHILD | WS_VISIBLE | WS_BORDER, 265, 260, 100, 160, hWnd, (HMENU)ID_BtnSndGET, hWnd, 0);
		hBtn_LAhead = CreateWindow(L"Button", L"�I", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 80, 100, 100, hWnd, (HMENU)ID_BtnLAhead, hWnd, 0);
		hBtn_Ahead = CreateWindow(L"Button", L"��", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 80, 100, 100, hWnd, (HMENU)ID_BtnAhead, hWnd, 0);
		hBtn_RAhead = CreateWindow(L"Button", L"�J", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 80, 100, 100, hWnd, (HMENU)ID_BtnRAhead, hWnd, 0);
		hBtn_Left = CreateWindow(L"Button", L"<>", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 190, 100, 100, hWnd, (HMENU)ID_BtnLeft, hWnd, 0);
		hBtn_Stop = CreateWindow(L"Button", L"ͣ", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 190, 100, 100, hWnd, (HMENU)ID_BtnStop, hWnd, 0);
		hBtn_Right = CreateWindow(L"Button", L"<>", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 190, 100, 100, hWnd, (HMENU)ID_BtnRight, hWnd, 0);
		hBtn_LBack = CreateWindow(L"Button", L"�L", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 300, 100, 100, hWnd, (HMENU)ID_BtnLeft, hWnd, 0);
		hBtn_Back = CreateWindow(L"Button", L"��", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 300, 100, 100, hWnd, (HMENU)ID_BtnStop, hWnd, 0);
		hBtn_RBack = CreateWindow(L"Button", L"�K", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 300, 100, 100, hWnd, (HMENU)ID_BtnRight, hWnd, 0);

		hBtn_CTRL[0] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 420, 100, 50, hWnd, (HMENU)ID_BtnC1, hWnd, 0);
		hBtn_CTRL[1] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 420, 100, 50, hWnd, (HMENU)ID_BtnC2, hWnd, 0);
		hBtn_CTRL[2] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 472, 100, 50, hWnd, (HMENU)ID_BtnC3, hWnd, 0);
		hBtn_CTRL[3] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 472, 100, 50, hWnd, (HMENU)ID_BtnC4, hWnd, 0);
		hBtn_CTRL[4] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 524, 100, 50, hWnd, (HMENU)ID_BtnC5, hWnd, 0);
		hBtn_CTRL[5] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 524, 100, 50, hWnd, (HMENU)ID_BtnC6, hWnd, 0);
		hBtn_CTRL[6] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 576, 100, 50, hWnd, (HMENU)ID_BtnC7, hWnd, 0);
		hBtn_CTRL[7] = CreateWindow(L"Button", L"����������", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 576, 100, 50, hWnd, (HMENU)ID_BtnC8, hWnd, 0);

		//���ø��ؼ�����
		SendMessage(hText_TipConnect, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipSpeed, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipSpeed1, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipSpeed2, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipSpeed3, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipSpeed4, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipDist, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipDist1, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipDist2, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipDist3, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipDist4, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipXYZ, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipX, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipY, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hText_TipZ, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hEdit_IP, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hEdit_Port, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_Connect, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_LUP, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_LDOWN, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_LSTOP, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_RUP, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_RDOWN, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_RSTOP, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_CWA, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_CWB, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_RCWA, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_RCWB, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_STOP, WM_SETFONT, (WPARAM)hFont, NULL);
		for (i = 0; i < 11; i++)
		{
			SendMessage(hEdit_ShowArgu[i], WM_SETFONT, (WPARAM)hFont, NULL);
		}
		for (i = 0; i < 8; i++)
		{
			SendMessage(hBtn_CTRL[i], WM_SETFONT, (WPARAM)hFont, NULL);
		}
		SendMessage(hBtn_GET, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(hBtn_LAhead, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_Ahead, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_RAhead, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_Left, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_Stop, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_Right, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_LBack, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_Back, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		SendMessage(hBtn_RBack, WM_SETFONT, (WPARAM)hFont_CTL, NULL);
		break;
	//������̰���
	case WM_KEYDOWN:
		//����״̬������
		if (flag_conn && LOWORD(wParam) != VK_NUMPAD5 && LOWORD(wParam) <= VK_NUMPAD9 && LOWORD(wParam) >= VK_NUMPAD1)
		{
			SetTimer(hWnd, LOWORD(wParam), 20, NULL);
		}
		break;
	//�������̧��
	case WM_KEYUP:
		//����״̬������
		if (flag_conn && LOWORD(wParam) != VK_NUMPAD5 && LOWORD(wParam) <= VK_NUMPAD9 && LOWORD(wParam) >= VK_NUMPAD1)
		{
			KillTimer(hWnd, LOWORD(wParam));
		}
		if (flag_conn && LOWORD(wParam) == VK_NUMPAD5)
		{
			STOP();
		}
		break;
	case WM_TIMER:
		switch (LOWORD(wParam))
		{
		case VK_NUMPAD7:
			LUP();
//			LUP();
//			RUP();
			//LDOWN();
			break;
		case VK_NUMPAD8:
			SPEED();
			break;
		case VK_NUMPAD9:
			RUP();
//			RUP();
//			LUP();
//			RDOWN();
			break;
		case VK_NUMPAD4:
			break;
		case VK_NUMPAD6:
			break;
		case VK_NUMPAD1:
			LDOWN();
//			LDOWN();
//			RDOWN();
			break;
		case VK_NUMPAD2:
			SLOW();
			break;
		case VK_NUMPAD3:
			RDOWN();
//			RDOWN();
//			LDOWN();
			break;
		default:
			break;
		}
		break;
	//���񰴼�����
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		//�������Ӱ�ť
		case ID_BtnConnect:
			//δ����
			if (!flag_conn)
			{
				SendMessage(hEdit_IP, WM_GETTEXT, sizeof(IPaddr) / sizeof(TCHAR), (LPARAM)(void*)IPaddr);//��ȡ�����IP��ַ
				SendMessage(hEdit_Port, WM_GETTEXT, sizeof(Port) / sizeof(TCHAR), (LPARAM)(void*)Port);//��ȡ����Ķ˿ں�
				wcstombs(IPaddr_ANSI, IPaddr, sizeof(IPaddr) / sizeof(TCHAR));
				SA.sin_addr.s_addr = inet_addr(IPaddr_ANSI);
				wcstombs(Port_ANSI, Port, sizeof(Port) / sizeof(TCHAR));
				SA.sin_port = htons(atoi(Port_ANSI));
				//���Գ�ʼ��socket
				fd_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if (fd_socket == INVALID_SOCKET)
				{
					WSACleanup();
					MessageBox(NULL, L"��ʼ��socketʧ�ܣ�", L"��ʼ��ʧ��", MB_OK);
					return -1;
				}
				//�������ӵ�������
				result_Conn = connect(fd_socket, (struct sockaddr *)&SA, sizeof(SA));
				if (result_Conn == SOCKET_ERROR)
				{
					MessageBox(NULL, L"�޷�����", L"����ʧ��", MB_OK);
				}
				else
				{
					SetWindowText(hBtn_Connect, L"�Ͽ�����");
					for (i = 0; i < 11; i++)
					{
						SetWindowText(hEdit_ShowArgu[i], L"");
					}
					hThread = CreateThread(NULL, 0, RecvShow, NULL, 0, NULL);
					SetWindowPos(hWnd, HWND_TOP, 0, 0, Width_Window, Height_Window, SWP_NOMOVE);
					flag_conn = 1;
					EnableWindow(hEdit_IP, FALSE);
					EnableWindow(hEdit_Port, FALSE);
				}
			}
			//������
			else
			{
				SetWindowText(hBtn_Connect, L"����");
				SetWindowPos(hWnd, HWND_TOP, 0, 0, Width_Window, 100, SWP_NOMOVE);
				TerminateThread(hThread, 0);
				closesocket(fd_socket);//�ر�socket
				flag_conn = 0;
				EnableWindow(hEdit_IP, TRUE);
				EnableWindow(hEdit_Port, TRUE);
			}
			break;
		//���ּ���
		case ID_BtnSndLUP:
			LUP();
			break;
		//���ּ���
		case ID_BtnSndLDOWN:
			LDOWN();
			break;
		//����ֹͣ
		case ID_BtnSndLSTOP:
			LSTOP();
			break;
		//���ּ���
		case ID_BtnSndRUP:
			RUP();
			break;
		//���ּ���
		case ID_BtnSndRDOWN:
			RDOWN();
			break;
		//����ֹͣ
		case ID_BtnSndRSTOP:
			RSTOP();
			break;
		//ԭ����ʱ����ת
		case ID_BtnSndCWA:
			CWA();
			break;
		//ԭ��˳ʱ����ת
		case ID_BtnSndCWB:
			CWB();
			break;
		//��ʱ��תȦ��
		case ID_BtnSndRCWA:
			RCWA();
			break;
		//˳ʱ��תȦ��
		case ID_BtnSndRCWB:
			RCWB();
			break;
		//ͣ��
		case ID_BtnSndSTOP:
			STOP();
			break;
		//��ȡС��״̬����
		case ID_BtnSndGET:
			GET();
			break;
		//����/ֹͣ��ǰ��ת��
		case ID_BtnLAhead:

			break;
		//����/ֹͣ������
		case ID_BtnC1://case ID_BtnC3:case ID_BtnC5:case ID_BtnC7:
			//��ǰΪֹͣ״̬
			if (flag_onoff[0] == 0)
			{
				COLLECTON();
				SetWindowText(hBtn_CTRL[0], L"ֹͣ������");
				flag_onoff[0] = 1;
			}
			//��ǰΪ����״̬
			else
			{
				COLLECTOFF();
				SetWindowText(hBtn_CTRL[0], L"����������");
				flag_onoff[0] = 0;
			}
			break;
		//����/ֹͣ������
		case ID_BtnC2://case ID_BtnC4:case ID_BtnC6:case ID_BtnC8:
			//��ǰΪֹͣ״̬
			if (flag_onoff[1] == 0)
			{
				MOVEON();
				SetWindowText(hBtn_CTRL[1], L"ֹͣ������");
				flag_onoff[1] = 1;
			}
			//��ǰΪ����״̬
			else
			{
				MOVEOFF();
				SetWindowText(hBtn_CTRL[1], L"����������");
				flag_onoff[1] = 0;
			}
			break;
		default:
			break;
		}
		if (LOWORD(wParam) != ID_EditIP && LOWORD(wParam) != ID_EditPort)
			SetFocus(hWnd);
		break;
	case WM_DESTROY:
		DeleteObject(hFont);//��������
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX WC;//������
	INT ProgWidth, ProgHeight;//�����ȡ��߶�

	WC.cbSize = sizeof(WNDCLASSEX);
	WC.style = CS_HREDRAW | CS_VREDRAW;
	WC.lpfnWndProc = CtlProc;
	WC.cbClsExtra = 0;
	WC.cbWndExtra = 0;
	WC.hInstance = hInstance;
	WC.hIcon = 0;
	WC.hCursor = 0;
	WC.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_BTNFACE);
	WC.lpszMenuName = 0;
	WC.lpszClassName = L"WND";
	WC.hIconSm = 0;

	if (WSAStartup(MAKEWORD(2, 2), &WSAData))
	{
		return -1;
	}
	SA.sin_family = AF_INET;
	RegisterClassEx(&WC);
	ProgWidth = Width_Window;
	ProgHeight = Height_Window;
	hMainWND = CreateWindow(L"WND", L"�������", WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, Width_Screen / 2 - ProgWidth / 2, Height_Screen / 2 - ProgHeight / 2, ProgWidth, 100, NULL, 0, 0, 0);
	ShowWindow(hMainWND, 1);
	UpdateWindow(hMainWND);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	WSACleanup();

	return 0;
}