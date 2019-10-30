#include<Windows.h>
#include<winsock.h>
#include<stdio.h>
#pragma comment(lib, "ws2_32.lib")

//各控件ID
#define ID_StcTIPConnect	3301//提示"输入服务器IP地址与端口号"
#define ID_BtnConnect		3303//连接服务器按钮
#define ID_EditIP			3304//连接服务器IP地址输入框
#define ID_EditPort			3305//连接服务器端口号输入框

#define ID_BtnSndLUP		3306//发送命令左轮加速按钮
#define ID_BtnSndLDOWN		3307//发送命令左轮减速按钮
#define ID_BtnSndLSTOP		3308//发送命令左轮停止按钮
#define ID_BtnSndRUP		3309//发送命令右轮加速按钮
#define ID_BtnSndRDOWN		3310//发送命令右轮减速按钮
#define ID_BtnSndRSTOP		3311//发送命令右轮停止按钮
#define ID_BtnSndCWA		3312//发送命令原地逆时针旋转按钮
#define ID_BtnSndCWB		3313//发送命令原地顺时针旋转按钮
#define ID_BtnSndRCWA		3314//发送命令逆时针转圈跑按钮
#define ID_BtnSndRCWB		3315//发送命令顺时针转圈跑按钮
#define ID_BtnSndSTOP		3316//发送命令停车按钮
#define ID_BtnSndGET		3317//发送命令获取当前数据按钮
#define ID_EditSHOWS1		3328//显示小车速度传回信息
#define ID_EditSHOWS2		3329//显示小车速度传回信息
#define ID_EditSHOWS3		3330//显示小车速度传回信息
#define ID_EditSHOWS4		3331//显示小车速度传回信息
#define ID_EditSHOWD1		3332//显示小车距离传回信息
#define ID_EditSHOWD2		3333//显示小车距离传回信息
#define ID_EditSHOWD3		3334//显示小车距离传回信息
#define ID_EditSHOWD4		3335//显示小车距离传回信息
#define ID_EditSHOWX		3336//显示小车距离传回信息
#define ID_EditSHOWY		3337//显示小车距离传回信息
#define ID_EditSHOWZ		3338//显示小车距离传回信息

#define ID_BtnAhead			3319//发送命令前进按钮
#define ID_BtnBack			3320//发送命令后退按钮
#define ID_BtnStop			3321//发送命令停车按钮
#define ID_BtnLeft			3322//发送命令<预留>按钮
#define ID_BtnRight			3323//发送命令<预留>按钮
#define ID_BtnLAhead		3324//发送命令前左转弯按钮
#define ID_BtnRAhead		3325//发送命令前右转弯按钮
#define ID_BtnLBACK			3326//发送命令后左转弯按钮
#define ID_BtnRBACK			3327//发送命令后右转弯按钮

#define ID_BtnC1			3339//发送命令收球起停按钮
#define ID_BtnC2			3340//发送命令运球起停按钮
#define ID_BtnC3			3341//发送命令收球起停按钮
#define ID_BtnC4			3342//发送命令运球起停按钮
#define ID_BtnC5			3343//发送命令收球起停按钮
#define ID_BtnC6			3344//发送命令运球起停按钮
#define ID_BtnC7			3345//发送命令收球起停按钮
#define ID_BtnC8			3346//发送命令运球起停按钮

//控件尺寸信息
#define Width_Screen		(GetSystemMetrics(SM_CXSCREEN))//屏幕宽度
#define Height_Screen		(GetSystemMetrics(SM_CYSCREEN))//屏幕高度
#define Width_Window		770//程序窗体宽度
#define Height_Window		680//程序窗体高度

//命令列表
#define CMD_LUP				"left+\r\n"//左轮加速
#define CMD_LDOWN			"left-\r\n"//左轮减速
#define CMD_LSTOP			"left0\r\n"//左轮停止
#define CMD_RUP				"right+\r\n"//右轮加速
#define CMD_RDOWN			"right-\r\n"//右轮减速
#define CMD_RSTOP			"right0\r\n"//右轮停止
#define CMD_CWA				"cw1\r\n"//顺时针旋转
#define CMD_CWB				"ccw1\r\n"//逆时针旋转
#define CMD_RCWA			"runcw\r\n"//逆时针转圈跑
#define CMD_RCWB			"runccw\r\n"//顺时针转圈跑
#define CMD_STOP			"stop\r\n"//停车
#define CMD_GET				"get\r\n"//获取小车状态数据
#define CMD_SPEED			"inc\r\n"//小车向前加速
#define CMD_SLOW			"dec\r\n"//小车减速
#define CMD_COLLECTON		"collecton\r\n"//收球电机启动
#define CMD_COLLECTOFF		"collectoff\r\n"//收球电机停止
#define CMD_MOVEON			"movon\r\n"//运球电机启动
#define CMD_MOVEOFF			"movoff\r\n"//运球电机停止

//各控件句柄
HWND hMainWND;			//主窗体
HWND hFont;				//统一字体
HWND hFont_CTL;			//控制区字体

HWND hBtn_Connect;		//连接按钮
HWND hBtn_LUP;			//发送"左轮加速"按钮
HWND hBtn_LDOWN;		//发送"左轮减速"按钮
HWND hBtn_LSTOP;		//发送"左轮停止"按钮
HWND hBtn_RUP;			//发送"右轮加速"按钮
HWND hBtn_RDOWN;		//发送"右轮减速"按钮
HWND hBtn_RSTOP;		//发送"右轮停止"按钮
HWND hBtn_CWA;			//发送"原地逆时针旋转"按钮
HWND hBtn_CWB;			//发送"原地顺时针旋转"按钮
HWND hBtn_RCWA;			//发送"逆时针旋转跑"按钮
HWND hBtn_RCWB;			//发送"顺时针旋转跑"按钮
HWND hBtn_STOP;			//发送"停车"按钮
HWND hBtn_GET;			//发送"获取小车状态数据"按钮
HWND hBtn_Ahead;		//发送"前进"按钮
HWND hBtn_Back;			//发送"后退"按钮
HWND hBtn_Stop;			//发送"停止"按钮
HWND hBtn_Left;			//发送"<预留>"按钮
HWND hBtn_Right;		//发送"<预留>"按钮
HWND hBtn_LAhead;		//发送"左前方转弯"按钮
HWND hBtn_RAhead;		//发送"右前方转弯"按钮
HWND hBtn_LBack;		//发送"左后方转弯"按钮
HWND hBtn_RBack;		//发送"右方法转弯"按钮
HWND hBtn_CTRL[8];		//发送"收球/运球电机起停"按钮

HWND hText_TipConnect;	//"输入服务器IP地址与端口号"
HWND hText_TipSpeed;	//"速度："
HWND hText_TipSpeed1;	//"速度1"
HWND hText_TipSpeed2;	//"速度2"
HWND hText_TipSpeed3;	//"速度3"
HWND hText_TipSpeed4;	//"速度4"
HWND hText_TipXYZ;		//"水平仪："
HWND hText_TipX;		//"X:"
HWND hText_TipY;		//"Y:"
HWND hText_TipZ;		//"Z:"
HWND hText_TipDist;		//"距离："
HWND hText_TipDist1;	//"距离1"
HWND hText_TipDist2;	//"距离2"
HWND hText_TipDist3;	//"距离3"
HWND hText_TipDist4;	//"距离4"

HWND hEdit_IP;			//IP地址输入
HWND hEdit_Port;		//端口号输入
HWND hEdit_ShowArgu[11];//传回速度、距离、水平仪信息输出

SOCKET fd_socket;//socket描述符
struct sockaddr_in SA;
HANDLE hThread;//接收消息线程句柄
INT flag_conn = 0;//标记当前是否连接状态
WSADATA WSAData = { 0 };

//向前加速
INT SPEED(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_SPEED);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//减速
INT SLOW(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_SLOW);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//左轮加速
INT LUP(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_LUP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//右轮加速
INT RUP(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_RUP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//左轮减速
INT LDOWN(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_LDOWN);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//右轮减速
INT RDOWN(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_RDOWN);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//左轮停止
INT LSTOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_LSTOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//右轮停止
INT RSTOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_RSTOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//原地逆时针旋转
INT CWA(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_CWA);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//原地顺时针旋转
INT CWB(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_CWB);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//逆时针转圈跑
INT RCWA(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_RCWA);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//顺时针转圈跑
INT RCWB(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区
	
	strcpy(Buf_Send, CMD_RCWB);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//停车
INT STOP(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_STOP);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//获取小车数据
INT GET(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_GET);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//启动收球电机
INT COLLECTON(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_COLLECTON);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//停止收球电机
INT COLLECTOFF(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_COLLECTOFF);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//启动运球电机
INT MOVEON(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_MOVEON);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
//停止运球电机
INT MOVEOFF(void)
{
	CHAR Buf_Send[1024] = { 0 };//待发送数据缓冲区

	strcpy(Buf_Send, CMD_MOVEOFF);
	send(fd_socket, Buf_Send, strlen(Buf_Send), 0);

	return 0;
}
DWORD WINAPI RecvShow(LPVOID lpParam)
{
	CHAR Buf_Recv_ANSI[1024] = { 0 };//待接收数据缓冲区(多字符)
	CHAR Buf_Set_ANSI[20] = { 0 };//待设置数据缓冲区(多字符)
	TCHAR Buf_Set[20] = { 0 };//待设置数据缓冲区(宽字符)
	CHAR *ptr_slow = NULL, *ptr_fast = NULL;
	INT num_Recv;//收到的字符数
	INT i;//指定设置的编辑框编号

	while (TRUE)
	{
		num_Recv = recv(fd_socket, Buf_Recv_ANSI, 1023, 0);
		//服务器端断开连接
		if (num_Recv <= 0)
		{
			SetWindowText(hBtn_Connect, L"连接");
			SetWindowPos(hMainWND, HWND_TOP, 0, 0, Width_Window, 100, SWP_NOMOVE);
			closesocket(fd_socket);//关闭socket
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
	TCHAR IPaddr[1024] = { 0 };//存放IP地址字符串(宽字节)
	CHAR IPaddr_ANSI[1024] = { 0 };//存放IP地址字符串(多字节)
	TCHAR Port[512] = { 0 };//存放端口号字符串(宽字节)
	CHAR Port_ANSI[512] = { 0 };//存放端口号字符串(多字节)
	static INT flag_onoff[8] = { 0 };//标记收球/运球电机起停状态(0停止;1启动)
	INT result_Conn;//连接结果
	INT i;//传回参数展示控件编号

	switch (message)
	{
	case WM_CREATE:
		hFont = CreateFont(-14, -7, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, TEXT("微软雅黑"));
		hFont_CTL = CreateFont(50, 30, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, TEXT("黑体"));
		hText_TipConnect = CreateWindow(L"Static", L"输入服务器IP地址与端口号", WS_CHILD | WS_VISIBLE, 15, 15, 300, 30, hWnd, NULL, hWnd, 0);
		hEdit_IP = CreateWindow(L"Edit", L"192.168.1.11", WS_BORDER | ES_CENTER | WS_CHILD | WS_VISIBLE, 200, 15, 200, 30, hWnd, (HMENU)ID_EditIP, hWnd, 0);
		hEdit_Port = CreateWindow(L"Edit", L"8080", WS_BORDER | ES_CENTER | WS_CHILD | WS_VISIBLE, 420, 15, 100, 30, hWnd, (HMENU)ID_EditPort, hWnd, 0);
		hBtn_Connect = CreateWindow(L"Button", L"连接", WS_CHILD | WS_VISIBLE | WS_BORDER, 530, 15, 200, 30, hWnd, (HMENU)ID_BtnConnect, hWnd, 0);
		hText_TipSpeed = CreateWindow(L"Static", L"速度：", WS_CHILD | WS_VISIBLE, 15, 430, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipSpeed1 = CreateWindow(L"Static", L"1：", WS_CHILD | WS_VISIBLE, 15, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[0] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS1, hWnd, 0);
		hText_TipSpeed2 = CreateWindow(L"Static", L"2：", WS_CHILD | WS_VISIBLE, 130, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[1] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS2, hWnd, 0);
		hText_TipSpeed3 = CreateWindow(L"Static", L"3：", WS_CHILD | WS_VISIBLE, 245, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[2] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS3, hWnd, 0);
		hText_TipSpeed4 = CreateWindow(L"Static", L"4：", WS_CHILD | WS_VISIBLE, 360, 465, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[3] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 385, 460, 80, 30, hWnd, (HMENU)ID_EditSHOWS4, hWnd, 0);
		hText_TipDist = CreateWindow(L"Static", L"距离：", WS_CHILD | WS_VISIBLE, 15, 500, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipDist1 = CreateWindow(L"Static", L"1：", WS_CHILD | WS_VISIBLE, 15, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[4] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD1, hWnd, 0);
		hText_TipDist2 = CreateWindow(L"Static", L"2：", WS_CHILD | WS_VISIBLE, 130, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[5] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD2, hWnd, 0);
		hText_TipDist3 = CreateWindow(L"Static", L"3：", WS_CHILD | WS_VISIBLE, 245, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[6] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD3, hWnd, 0);
		hText_TipDist4 = CreateWindow(L"Static", L"4：", WS_CHILD | WS_VISIBLE, 360, 535, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[7] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 385, 530, 80, 30, hWnd, (HMENU)ID_EditSHOWD4, hWnd, 0);
		hText_TipXYZ = CreateWindow(L"Static", L"水平仪：", WS_CHILD | WS_VISIBLE, 15, 570, 300, 30, hWnd, NULL, hWnd, 0);
		hText_TipX = CreateWindow(L"Static", L"1：", WS_CHILD | WS_VISIBLE, 15, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[8] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWX, hWnd, 0);
		hText_TipY = CreateWindow(L"Static", L"2：", WS_CHILD | WS_VISIBLE, 130, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[9] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 155, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWY, hWnd, 0);
		hText_TipZ = CreateWindow(L"Static", L"3：", WS_CHILD | WS_VISIBLE, 245, 605, 30, 30, hWnd, NULL, hWnd, 0);
		hEdit_ShowArgu[10] = CreateWindow(L"Edit", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 600, 80, 30, hWnd, (HMENU)ID_EditSHOWZ, hWnd, 0);
		hBtn_LUP = CreateWindow(L"Button", L"左轮加速", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 80, 100, 60, hWnd, (HMENU)ID_BtnSndLUP, hWnd, 0);
		hBtn_LDOWN = CreateWindow(L"Button", L"左轮减速", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 150, 100, 60, hWnd, (HMENU)ID_BtnSndLDOWN, hWnd, 0);
		hBtn_LSTOP = CreateWindow(L"Button", L"左轮停止", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 220, 100, 60, hWnd, (HMENU)ID_BtnSndLSTOP, hWnd, 0);
		hBtn_RUP = CreateWindow(L"Button", L"右轮加速", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 80, 100, 60, hWnd, (HMENU)ID_BtnSndRUP, hWnd, 0);
		hBtn_RDOWN = CreateWindow(L"Button", L"右轮减速", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 150, 100, 60, hWnd, (HMENU)ID_BtnSndRDOWN, hWnd, 0);
		hBtn_RSTOP = CreateWindow(L"Button", L"右轮停止", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 220, 100, 60, hWnd, (HMENU)ID_BtnSndRSTOP, hWnd, 0);
		hBtn_CWA = CreateWindow(L"Button", L"原地逆时针旋转", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 290, 100, 60, hWnd, (HMENU)ID_BtnSndCWA, hWnd, 0);
		hBtn_CWB = CreateWindow(L"Button", L"原地顺时针旋转", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 290, 100, 60, hWnd, (HMENU)ID_BtnSndCWB, hWnd, 0);
		hBtn_RCWA = CreateWindow(L"Button", L"逆时针旋转跑", WS_CHILD | WS_VISIBLE | WS_BORDER, 15, 360, 100, 60, hWnd, (HMENU)ID_BtnSndRCWA, hWnd, 0);
		hBtn_RCWB = CreateWindow(L"Button", L"顺时针旋转跑", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 360, 100, 60, hWnd, (HMENU)ID_BtnSndRCWB, hWnd, 0);
		hBtn_STOP = CreateWindow(L"Button", L"停车", WS_CHILD | WS_VISIBLE | WS_BORDER, 265, 80, 100, 160, hWnd, (HMENU)ID_BtnSndSTOP, hWnd, 0);
		hBtn_GET = CreateWindow(L"Button", L"获取状态数据", WS_CHILD | WS_VISIBLE | WS_BORDER, 265, 260, 100, 160, hWnd, (HMENU)ID_BtnSndGET, hWnd, 0);
		hBtn_LAhead = CreateWindow(L"Button", L"↖", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 80, 100, 100, hWnd, (HMENU)ID_BtnLAhead, hWnd, 0);
		hBtn_Ahead = CreateWindow(L"Button", L"↑", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 80, 100, 100, hWnd, (HMENU)ID_BtnAhead, hWnd, 0);
		hBtn_RAhead = CreateWindow(L"Button", L"↗", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 80, 100, 100, hWnd, (HMENU)ID_BtnRAhead, hWnd, 0);
		hBtn_Left = CreateWindow(L"Button", L"<>", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 190, 100, 100, hWnd, (HMENU)ID_BtnLeft, hWnd, 0);
		hBtn_Stop = CreateWindow(L"Button", L"停", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 190, 100, 100, hWnd, (HMENU)ID_BtnStop, hWnd, 0);
		hBtn_Right = CreateWindow(L"Button", L"<>", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 190, 100, 100, hWnd, (HMENU)ID_BtnRight, hWnd, 0);
		hBtn_LBack = CreateWindow(L"Button", L"↙", WS_CHILD | WS_VISIBLE | WS_BORDER, 380, 300, 100, 100, hWnd, (HMENU)ID_BtnLeft, hWnd, 0);
		hBtn_Back = CreateWindow(L"Button", L"↓", WS_CHILD | WS_VISIBLE | WS_BORDER, 490, 300, 100, 100, hWnd, (HMENU)ID_BtnStop, hWnd, 0);
		hBtn_RBack = CreateWindow(L"Button", L"↘", WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 300, 100, 100, hWnd, (HMENU)ID_BtnRight, hWnd, 0);

		hBtn_CTRL[0] = CreateWindow(L"Button", L"启动收球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 420, 100, 50, hWnd, (HMENU)ID_BtnC1, hWnd, 0);
		hBtn_CTRL[1] = CreateWindow(L"Button", L"启动运球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 420, 100, 50, hWnd, (HMENU)ID_BtnC2, hWnd, 0);
		hBtn_CTRL[2] = CreateWindow(L"Button", L"启动收球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 472, 100, 50, hWnd, (HMENU)ID_BtnC3, hWnd, 0);
		hBtn_CTRL[3] = CreateWindow(L"Button", L"启动运球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 472, 100, 50, hWnd, (HMENU)ID_BtnC4, hWnd, 0);
		hBtn_CTRL[4] = CreateWindow(L"Button", L"启动收球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 524, 100, 50, hWnd, (HMENU)ID_BtnC5, hWnd, 0);
		hBtn_CTRL[5] = CreateWindow(L"Button", L"启动运球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 524, 100, 50, hWnd, (HMENU)ID_BtnC6, hWnd, 0);
		hBtn_CTRL[6] = CreateWindow(L"Button", L"启动收球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 476, 576, 100, 50, hWnd, (HMENU)ID_BtnC7, hWnd, 0);
		hBtn_CTRL[7] = CreateWindow(L"Button", L"启动运球电机", WS_CHILD | WS_VISIBLE | WS_BORDER, 585, 576, 100, 50, hWnd, (HMENU)ID_BtnC8, hWnd, 0);

		//设置各控件字体
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
	//捕获键盘按下
	case WM_KEYDOWN:
		//连接状态允许触发
		if (flag_conn && LOWORD(wParam) != VK_NUMPAD5 && LOWORD(wParam) <= VK_NUMPAD9 && LOWORD(wParam) >= VK_NUMPAD1)
		{
			SetTimer(hWnd, LOWORD(wParam), 20, NULL);
		}
		break;
	//捕获键盘抬起
	case WM_KEYUP:
		//连接状态允许触发
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
	//捕获按键单击
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		//单击连接按钮
		case ID_BtnConnect:
			//未连接
			if (!flag_conn)
			{
				SendMessage(hEdit_IP, WM_GETTEXT, sizeof(IPaddr) / sizeof(TCHAR), (LPARAM)(void*)IPaddr);//获取输入的IP地址
				SendMessage(hEdit_Port, WM_GETTEXT, sizeof(Port) / sizeof(TCHAR), (LPARAM)(void*)Port);//获取输入的端口号
				wcstombs(IPaddr_ANSI, IPaddr, sizeof(IPaddr) / sizeof(TCHAR));
				SA.sin_addr.s_addr = inet_addr(IPaddr_ANSI);
				wcstombs(Port_ANSI, Port, sizeof(Port) / sizeof(TCHAR));
				SA.sin_port = htons(atoi(Port_ANSI));
				//尝试初始化socket
				fd_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if (fd_socket == INVALID_SOCKET)
				{
					WSACleanup();
					MessageBox(NULL, L"初始化socket失败！", L"初始化失败", MB_OK);
					return -1;
				}
				//尝试连接到服务器
				result_Conn = connect(fd_socket, (struct sockaddr *)&SA, sizeof(SA));
				if (result_Conn == SOCKET_ERROR)
				{
					MessageBox(NULL, L"无法连接", L"连接失败", MB_OK);
				}
				else
				{
					SetWindowText(hBtn_Connect, L"断开连接");
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
			//已连接
			else
			{
				SetWindowText(hBtn_Connect, L"连接");
				SetWindowPos(hWnd, HWND_TOP, 0, 0, Width_Window, 100, SWP_NOMOVE);
				TerminateThread(hThread, 0);
				closesocket(fd_socket);//关闭socket
				flag_conn = 0;
				EnableWindow(hEdit_IP, TRUE);
				EnableWindow(hEdit_Port, TRUE);
			}
			break;
		//左轮加速
		case ID_BtnSndLUP:
			LUP();
			break;
		//左轮减速
		case ID_BtnSndLDOWN:
			LDOWN();
			break;
		//左轮停止
		case ID_BtnSndLSTOP:
			LSTOP();
			break;
		//右轮加速
		case ID_BtnSndRUP:
			RUP();
			break;
		//右轮减速
		case ID_BtnSndRDOWN:
			RDOWN();
			break;
		//右轮停止
		case ID_BtnSndRSTOP:
			RSTOP();
			break;
		//原地逆时针旋转
		case ID_BtnSndCWA:
			CWA();
			break;
		//原地顺时针旋转
		case ID_BtnSndCWB:
			CWB();
			break;
		//逆时针转圈跑
		case ID_BtnSndRCWA:
			RCWA();
			break;
		//顺时针转圈跑
		case ID_BtnSndRCWB:
			RCWB();
			break;
		//停车
		case ID_BtnSndSTOP:
			STOP();
			break;
		//获取小车状态数据
		case ID_BtnSndGET:
			GET();
			break;
		//持续/停止左前方转弯
		case ID_BtnLAhead:

			break;
		//启动/停止收球电机
		case ID_BtnC1://case ID_BtnC3:case ID_BtnC5:case ID_BtnC7:
			//当前为停止状态
			if (flag_onoff[0] == 0)
			{
				COLLECTON();
				SetWindowText(hBtn_CTRL[0], L"停止收球电机");
				flag_onoff[0] = 1;
			}
			//当前为启动状态
			else
			{
				COLLECTOFF();
				SetWindowText(hBtn_CTRL[0], L"启动收球电机");
				flag_onoff[0] = 0;
			}
			break;
		//启动/停止运球电机
		case ID_BtnC2://case ID_BtnC4:case ID_BtnC6:case ID_BtnC8:
			//当前为停止状态
			if (flag_onoff[1] == 0)
			{
				MOVEON();
				SetWindowText(hBtn_CTRL[1], L"停止运球电机");
				flag_onoff[1] = 1;
			}
			//当前为启动状态
			else
			{
				MOVEOFF();
				SetWindowText(hBtn_CTRL[1], L"启动运球电机");
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
		DeleteObject(hFont);//销毁字体
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
	WNDCLASSEX WC;//窗体类
	INT ProgWidth, ProgHeight;//窗体宽度、高度

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
	hMainWND = CreateWindow(L"WND", L"控制面板", WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, Width_Screen / 2 - ProgWidth / 2, Height_Screen / 2 - ProgHeight / 2, ProgWidth, 100, NULL, 0, 0, 0);
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