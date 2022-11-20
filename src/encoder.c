
#include "../libs/Encoder.h"


Message newMessageContainer(char* message)
{
  Message newMsg;
  newMsg =NULL;
  newMsg = malloc(sizeof(newMsg));
  newMsg->content=calloc(BUFSIZ,sizeof(char));

  strcpy(newMsg->content,message);
  newMsg->length = strlen(message);

  return newMsg;
}

ERROR setMessage(Message frame, char* string)
{

  if(string == NULL)return FALSE;

  strncpy(frame->content,string,BUFSIZ);
  return TRUE;
}

char* getMessage(Message frame)
{
  return frame->content;
}

ERROR encodeMessage(Message frame, size_t offset)
{

	int numero[512][4];
	int j=0,i=0,k=0;
	char numeros[100][2];
	int sumanumero[100];

  if(!frame) return FALSE;
  if(!frame->content)return FALSE;

  for(int i = 0; i<= frame->length; i++)
    {
      if(frame->content[i] != ',')
			{
				numeros[j][k] = frame->content[i];
		  	k++;
      }
			if(frame->content[i] == ',')
			{			
				frame->content[i-1] += offset;
				numeros[j][k-1] = frame->content[i-1];		
				sscanf(numeros[j], " %d", numero[j]);
				j++;
				k=0;
			}
    }
        printf(" \n \n");

for(i=0;i<j;i++)
{
	for(k=0;k<2;k++)
	{
		printf("%c", numeros[i][k]);
	}
	 		printf(" \t vale '%ls'", numero[i]);
	printf("\n");
}
        printf(" \n \n");

  return TRUE;
}


