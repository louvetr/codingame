#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define MAX_FILENAME 501

int main()
{ // Number of elements which make up the association table.
	int N, Q, i, j, k;
	char **asso;
	char **files;

	scanf("%d", &N); // Number Q of file names to be analyzed.
	scanf("%d", &Q);

	asso = calloc(N, sizeof(char *) * 2);
	files = calloc(Q, sizeof(char *));

	for (i = 0; i < N; i++) {
		char EXT[11]; // MIME type.
		char MT[51];
		char *tmp = NULL;

		scanf("%s%s", EXT, MT);
		fgetc(stdin);
		tmp = strdup(EXT);
		fprintf(stderr, "tmp = '%s'\n", tmp);
		asso[2 * i] = strdup(EXT);
		asso[2 * i + 1] = strdup(MT);
		/*fprintf(stderr, "asso[%d][0]= '%s', asso[%d][1] = '%s'\n",
                i, asso[2*i], i, asso[2*i+1]);*/
	}

	for (i = 0; i < Q; i++) {
		char FNAME[MAX_FILENAME];
		char *tmp = NULL;
		fgets(FNAME, MAX_FILENAME, stdin);
		tmp = strchr(FNAME, '\n');
		if (tmp)
			*tmp = '\0';
		files[i] = strdup(FNAME);
		//fprintf(stderr, "files[%d] = '%s'\n", i, files[i]);
	}

	for (i = 0; i < Q; i++) {
		char *ext = NULL;
		char *tmp = NULL;
		tmp = files[i];

		ext = strrchr(files[i], '.');
		if (!ext) {
			printf("UNKNOWN\n");
			continue;
		}
		ext++;

		for (j = 0; j < N; j++) {
			char *found = NULL;
			/*fprintf(stderr, "#%d --- ext = '%s', asso[%d][0]= '%s'\n",
                i, files[i]+k, j, asso[2*j]);*/
			if (!strcasecmp(ext, asso[2 * j])) {
				printf("%s\n", asso[2 * j + 1]);
				break;
			}
		}
		if (j == N)
			printf("UNKNOWN\n");

		free(files[i]);
	}

	for (j = 0; j < N; j++) {
		free(asso[2 * j]);
		free(asso[2 * j + 1]);
	}

	free(asso);
	free(files);

	return 0;
}
