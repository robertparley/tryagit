#include <stdio.h>
#include <string.h>
//写一个文件复制程序，用fwrite/fread实现

int copyy()
{
	FILE* fr = fopen("exer.txt","r");
	FILE* fw = fopen("copy","w");
	char str[1000]={};//要清空数组，防止后续乱码出现
	if(fr==NULL)	//检验FILE*是否生成成功
	{
		puts("fail!");
		return 1;
	}
	fread(str,100,4,fr);
	printf("%s",str);
	fwrite(str,100,4,fw);
	fclose(fw);
	fclose(fr);
	return 0;
}


//加密解密程序


void encrypt(FILE* f)
{
	int a = 0;
while((a = fgetc(f))!=EOF)
	{
		a = ~a;a += 100;
		fseek(f,-1,SEEK_CUR);
		fputc(a,f);
	}
}

void deciph(FILE* f)
{
	int a = 0;
	while((a = fgetc(f))!=EOF){
	a -= 100;a =~a;
	fseek(f,-1,SEEK_CUR);
	fputc(a,f);}
}
int secrett()
{
	FILE* fc=fopen("copy","r+");
	deciph(fc);
	fclose(fc);
	FILE* fd=fopen("copy","r+");
	encrypt(fd);
	fclose(fc);
}



//统计字母、数字、其他字符的个数。
//其间包含了对a与a+的测试，即EOF存在的测试。

int countt()
{
	int num,ch,oth;
	num=ch=oth=0;
	char c;
	FILE* fc = fopen("copy","r");
	if(fc==NULL)  return 1;
	while((c = fgetc(fc)) != EOF)
	{
		if((c >= '0')&&(c <='9'))	num++;
		else if((c >= 'a') && (c <= 'z'))	ch++;
		else oth++;
	}
	int te=ftell(fc);printf("%d\n",te);
	fclose(fc);
	printf("number=%d\nchar=%d\nother=%d\n",num,ch,oth);
	FILE* a = fopen("copy","a+");
	if(a==NULL)	return 1;
	fputc('a',a);
	fputc('a',a);
	fputc('a',a);
	num=ch=oth=0;
	te=ftell(a);printf("%d\n",te);
	while((c = fgetc(fc)) != EOF)
	{
		if((c >= '0')&&(c <='9'))	num++;
		else if((c >= 'a') && (c <= 'z'))	ch++;
		else oth++;
	}
	printf("number=%d\nchar=%d\nother=%d\n",num,ch,oth);
	return 0;
}


//显示文件内容，要求带行号，每20行暂停一次，回车继续。

int printt(int argc,char* argv[])
{
	if(argc < 2)
	{
		puts("参数过少！");
	}
	int a;
	printf("%d\n",argc);
	for(a=1;a < argc;a++)
	{
		printf("第%d篇文档：%s\n",a,argv[a]);
		char s[100]={};
		int i,j;
		char* st=argv[a];
		FILE* fi = fopen(st,"r");
		for(i=1;;i++)
		{
			for(j=0;j<100;j++)	s[j]='\0';
			if((s[0]=fgetc(fi))!=EOF)
			{
				fseek(fi,-1,SEEK_CUR);
				fgets(s,100,fi);
			}
			else
				break;
			printf("第%d行\t%s",i,s);
			if(i%20 == 0){	scanf("%*[^\n]");scanf("%*c");}
		}
		fclose(fi);
		printf("\n\n");
	}
	return 0;
}


int main(int argc,char* argv[])
{
		printt(argc,argv);
		return 0;
}

