#include "stm32f1xx_hal.h"
#include "string.h"

#define WIFI_NAME "Real"			//Ҫ���ӵ�wifi�ȵ���
#define WIFI_PWD "YZY12345"					//�ȵ�����
#define SERVER_ADDR "192.168.43.1"		//������ip��ַ
#define SERVER_PORT "10500"						//�˿ں�

#define AT_ERROR "atָ����� \r\n"
#define MODE_ERROR "����ģʽ���ô���\r\n"
#define CONECT_WIFI_ERROR "�޷�����wifi\r\n"
#define CONECT_SERVER_ERROR "�޷����ӷ�����\r\n"

#define DEBUG 1			//debugģʽ������Ϊ1

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern uint8_t my_re_buf1[2000];
extern uint8_t my_re_buf2[2000];
extern uint8_t send_buf[512];
extern uint16_t pt_w1;

int wifi_init();
uint8_t Send_AT_commend(char *at_commend, char *re_commend, uint16_t time_out);
void clear_buf();
uint8_t find_str(char *a);
uint8_t server_str();
uint8_t wifi_str();
void wifi_send(uint8_t *buf,int len);
void itoa(int n,char s[]);


