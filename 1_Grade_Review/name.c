#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[50];
	printf("name: ");
	fgets(name, sizeof(name), stdin);

	FILE *fp;
	fp = fopen("name.txt", "w");

	fprintf(fp, "your name: %s", name);
	printf("succeeded to save your name in name.txt\n");

	fclose(fp);

	return 0;
}
