#include "my_func.h"

#include "main.h"


char temp[50] = "";
/*wifiģ���ʼ��*/
int wifi_init()
{
	uint8_t ret=0;
	
	//���β���wifiģ�鹦�ܼ�����wifi��������
	ret = Send_AT_commend("AT", "OK", 100);
	if(!ret)
		return -1;
	ret = Send_AT_commend("AT+CIPMUX=1", "OK", 100);
	if(!ret)
		return -2;
	ret = Send_AT_commend("AT+CIPSERVER=1,8080", "OK", 200); 			//AT+CWJAP="pxc002","?????"
	if(!ret)
		return -3;
	return 1;
}



/*����ATָ��
*�������:atָ��ڴ����յ����ݣ���ʱʱ��
*/
uint8_t Send_AT_commend(char *at_commend, char *re_commend, uint16_t time_out)
{
	uint8_t i=0;
	for(i=0;i<3;i++)
	{
		clear_buf();
		HAL_UART_Transmit(&huart1, (uint8_t *)at_commend, strlen(at_commend), 0xFFFF);
		HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", 2, 0xFFFF);				//�Զ����ͻس�����
		HAL_Delay(time_out);
		if(find_str(re_commend))
			return 1;
		i++;
	}
	return 0;
}


/*���wifi���ջ�����*/
void clear_buf()
{
	uint16_t i;
	for(i=0;i<2000;i++)
		my_re_buf1[i]=0x00;
	pt_w1=0;
	HAL_UART_AbortReceive_IT(&huart1);
	HAL_UART_Receive_IT(&huart1,my_re_buf1,1);
}


/*�����ַ���
*�����������Ҫƥ����ַ���
*/
uint8_t find_str(char *a)
{
	int i;
	char *addr = strstr((const char *)my_re_buf1,a);
	if(addr)
		return 1;
	return 0;
	
}

/*wifi����
*�����������Ҫ���͵��ַ������飬���͵��ֽ���
*/
void wifi_send(uint8_t *buf, int len)
{
	char len_str[]="",temp1[256]="";
	itoa(len, len_str);
	strcat(temp1,"AT+CIPSEND=");
	strcat(temp1,len_str);
	HAL_UART_Transmit(&huart2, (uint8_t *)"��������\r\n", 10, 0xFFFF);
	if(Send_AT_commend(temp1, ">", 300))
		if(Send_AT_commend((char *)buf, "SEND OK", 300))
			HAL_UART_Transmit(&huart2, (uint8_t *)"���ͳɹ�������\r\n", 16, 0xFFFF);
}

void itoa(int n,char s[])
{
	int i,j,sign,m=0;
	char temp[]="";
	if((sign=n)<0)
	n=-n;
	i=0;
	do{
				 s[i++]=n%10+'0';
	}
	while ((n/=10)>0);
	if(sign<0)
	s[i++]='-';
	s[i]='\0';
	for(j=i-1;j>=0;j--)    
		temp[m++]=s[j];
	for(i=0;i<strlen(temp);i++)
		s[i]=temp[i];
}


