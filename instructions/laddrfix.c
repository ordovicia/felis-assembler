#include "commands.h"

void laddrfix2(int[10000],int);

void laddrfix(char label_set[10000][255],int laddr[10000],FILE *fd)
{


    //FILE* fd;
    char buf[256] = {'\0'};
    int p = 1;
    char *rs = NULL,*rt = NULL,*rd = NULL,*imm = NULL,*tok = NULL;

    int debug_line = 0;



    while (fgets(buf, 255, fd) != NULL) {
        if (strlen(buf) > 1) {
            //debug_line += 1;
            tok = strtok(buf, " \t\n");


            /*assembla command*/
            //if (tok[0] == '.') {
            //}
            /*comment*/
            //else
            if (tok[0] == '#') {
            }
            /*label*/
            else if (tok[strlen(tok) - 1] == ':') {
            } else {
               if (strcmp(tok, "addi") == 0) {
                rs = strtok(NULL, " ,\t");
                rd = strtok(NULL, " ,\t");
                rd = rs; rs = rd; //warning消す用
                imm = strtok(NULL, " ,\t\n");
                if (mysearch(imm, label_set, 10000) != -1) {
                    /*constがラベルのとき*/
                    laddrfix2(laddr,p);
                    p+=1;
                } 
             } else if (strcmp(tok, "jal") == 0) {
                imm = strtok(NULL, " \t\n");
                if (mysearch(imm, label_set, 10000) == -1) {
                 /* jal r1 */
                  //laddrfix2(laddr,p);
                  p+=0;
                } else {
                }
            }
                p += 1;
                
            }
//printf("laddrfix = %d\n",debug_line);
        }
    }



}



void laddrfix2(int laddr[10000],int n)
{
  int i;
  for (i=0;i<10000;i++){
    if (laddr[i] > n) laddr[i] += 1;
  }
}



