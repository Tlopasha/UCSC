#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

int check_dirent(char *);
char *srchflnm;

#define ISDIR(fn) (lstat(fn,&sbuf)==-1)?0:S_ISDIR(sbuf.st_mode)

int main(int argc, char **argv) {
	if (argc == 3) {
			srchflnm=argv[2];
			check_dirent(argv[1]);
	}
	else fprintf(stderr, "Usage: %s directory_name search_filename\n", 
			argv[0]);
	
	return 0;
}

int check_dirent(char *path) {
	struct dirent *dp;
  struct stat sbuf;
	DIR *dirp;
	int	isdir=0;
	char svpath[1024]; // required on stack
	char buf[1024]; 	 // required on stack

	static char pathbuf[1024]; // not needed on stack.
	
	if ((dirp = opendir(path)) == NULL) {
		fprintf(stderr,"%30.30s: %s\n", path, "Failed to open directory");
		return 1;
	}   

	// key premise of this section 
	//  .. stat() works on valid path entries, 
	//  .. therefore chdir() as needed.
	while ((dp = readdir(dirp)) != NULL) {
			if ((!strcmp(".",dp->d_name)) || (!strcmp("..",dp->d_name))) 
				continue;

			sprintf(buf,"%s/%s",path,dp->d_name);
			isdir=ISDIR(buf);

			if (!(strcmp(dp->d_name,srchflnm))) {
				fprintf(stderr,"Found: %s\n",realpath(buf,pathbuf));
			}

			if (isdir) {
				getcwd(svpath,sizeof(svpath));	// save full path for now
				chdir(path);								 		// used path

				check_dirent(dp->d_name);
				chdir(svpath);								 	// used saved path from earlier
			}
	}
	
	closedir(dirp);
	
	return 0;
}
