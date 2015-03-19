/* Beginner Level Exec() Example
 *
 *  User will insert the Website name he/she want to enter on firefox
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* opensite(char input[70]){

	char *site = (char*) malloc(70);

	site=input;

	return site;
}

int main(int argc, const char *argv[])
{

			char *site;
			char input[70];
			site=input;
            printf("Insert the Website name you want to enter on firefox\n");
			scanf("%s",site);

			site = opensite(input);

			execlp ("firefox", "firefox",site, NULL);
	    	char *args[] = {"firefox", site, NULL};
	    	execvp ("firefox", args);

	exit(EXIT_SUCCESS);
}
