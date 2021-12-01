#include <stdio.h>
#include <string.h>
int joinCompare(char *a)
{
	int i = 0;
	while (*(a + i) != '\0')
	{
		if (*(a + i) < 'A' || *(a + i) > 'Z')
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int times = 0; times < T; times++)
	{
		char str[201][201] = {0};
		char buff[201] = {0};
		char temp[201] = {0};
		gets(buff);
		int m = 0;
		int n = 0;
		for (int i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == ' ')
			{
				m++;
				n = 0;
				continue;
			}
			str[m][n] = buff[i];
			n++;
		}
		for (int i = 0; i <= m; i++)
		{
			for (int j = i + 1; j <= m; j++)
			{
				if ((!joinCompare(str[i])) || (!joinCompare(str[j])))
					continue;
				if (strcmp(str[j], str[i]) < 0)
				{
					strcpy(temp, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], temp);
				}
			}
		}
		printf("case #%d:\n", times);
		for (int i = 0; i <= m; i++)
			printf("%s ", str[i]);
		printf("\n");
	}
	return 0;
}
