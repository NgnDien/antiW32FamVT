// anti W32.FamVT.AP
// create: 2020.06.29
// by: Ngn
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

void showTitle()
{
	system("cls");
	printf("************************************************************\n");
	printf("*                 Anti W32.FamVT - 0620.19                 *\n");
	printf("*                      Created by Ngn                      *\n");
	printf("*.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-*\n");
	printf("*[+]        Phuc hoi USB bi W32.FamVT.AP an du lieu        *\n");
	printf("*[+]              Go bo W32.FamVT.AP khoi USB              *\n");
	printf("*[!]    Khong mo o dia USB truoc khi chay chuong trinh!    *\n");
	printf("************************************************************\n");
	printf("\n");
}

int main()
{
	showTitle();
	
	start:
		printf("Nhap vao thu muc o dia USB (VD: F:\\)> ");
		char drive[3];
		scanf("%s", &drive);
		if(strlen(drive) > 3)
		{
			printf("[Error] Thu muc o dia USB phai co dang <drive letter>:\\ \n");
			printf("        (vi du: F:\\)\n");
			goto start;
		}
		if(drive[2] == '\\')
		{
			
		}
		else
		{
			strcat(drive, "\\");
		}
		
	printf("[+] Thu muc da chon: %s\n", drive);
	
	//1. hien toan bo file an:
	printf("\n[+] Hien file an..> ");
	char cmd[52];
	strcpy(cmd, "attrib -s -h -r ");
	strcat(cmd, drive);
	strcat(cmd, "* /s /d");
	system(cmd);
	//2. xoa Recycler.bin
	printf("\n[+] Xoa Recycler.bin..> ");
	strcpy(cmd, "RD /S /Q ");
	strcat(cmd, drive);
	strcat(cmd, "RECYCLER.BIN\\");
	system(cmd);
	//3. xoa lnk
	printf("\n[+] Xoa shortcut..> ");
	strcpy(cmd, "DEL ");
	strcat(cmd, drive);
	strcat(cmd, "*.lnk /s");
	system(cmd);
	//4. xoa desktop.ini
	printf("\n[+] Xoa desktop.ini..> ");
	strcpy(cmd, "DEL ");
	strcat(cmd, drive);
	strcat(cmd, "*desktop.ini /s");
	system(cmd);
	//5. an thu muc System Volume Information
	printf("\n[+] An thu muc System Volume Information..> ");
	strcpy(cmd, "attrib +s +h +r \"");
	strcat(cmd, drive);
	strcat(cmd, "System Volume Information\" /s /d");
	system(cmd);
	exit:
		printf("\n[+] Xong");
		system("timeout /t 5");
}
