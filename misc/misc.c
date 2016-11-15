#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("%d\n", compareVersion("1.1", "1.2"));
#if 0
	char t[4] = "1.1";
  	printf("%s\n", strtok(t, "."));
	   char str[80] = "This is - www.tutorialspoint.com - website";
	      const char s[2] = "-";
	         char *token;
		    
		    /* get the first token */
		    token = strtok(str, s);
		    printf("%s\n", token);
		       
		       /* walk through other tokens */
		       while( token != NULL ) 
			    {
			            printf( " %s\n", token );
				        
				          token = strtok(NULL, s);
					     }
		          
#endif
		       return(0);
}

struct version_info {
      int* num;
          int length;
};

struct version_info get_version_info(char* version_passed) {
      char* version = malloc(strlen(version_passed) + 1);
      strcpy(version, version_passed);
      printf("%d\n", __LINE__);
      struct version_info ver;
          int cnt = 0;
	  int tem;
	  char* x = NULL;
	      int temp_len = strlen(version);
	      printf("%d\n", __LINE__);
	          for (int i = 0; i < temp_len; i++) {
		            if (version[i] == '.')
			                  cnt++;
			        }
		  printf("%d\n", __LINE__);
		      ver.length = cnt + 1;
		  printf("%d\n", __LINE__);
		          ver.num = malloc(ver.length * sizeof(int));
		  printf("%d\n", __LINE__);
		  	     printf("sending version %s\n", version);
		  	     x = strtok(version, ".");
			     printf("string is %s\n", x);
		  printf("%d\n", __LINE__);
			     tem = atoi(x);
		  printf("%d\n", __LINE__);
			     ver.num[0] = tem;
		  printf("%d\n", __LINE__);
			          for (int i = 1; i < ver.length; i++) {
		  printf("%d\n", __LINE__);
				            ver.num[i] = atoi(strtok(NULL, "."));
		  printf("%d\n", __LINE__);
					        }
				  printf("%d\n", __LINE__);
				      return ver;
}

int compareVersion(char* version1, char* version2) {
      printf("%d\n", __LINE__);
      struct version_info ver1 = get_version_info(version1);
          struct version_info ver2 = get_version_info(version2);

	      int i = 0;
	          int j = 0;
		      
		      while(i < ver1.length && j < ver2.length) {
			        printf("%d : %d\n", ver1.num[i], ver2.num[j]);
				        if (ver1.num[i] < ver2.num[j])
					              return -1;
					        else if (ver1.num[i] > ver2.num[j])
						              return 1;
						        else {
							              i++;
								                  j++;
										          }
							    }
		          
		          if (i == ver1.length && j == ver2.length)
			            return 0;
			      else if (i == ver1.length)
				        return -1;
			          else
				            return 1;
}
