#include "stm32f1xx_hal.h"
#include "string.h"

#define WIFI_NAME "Real"			//要连接的wifi热点名
#define WIFI_PWD "YZY12345"					//热点密码
#define SERVER_ADDR "192.168.43.1"		//服务器ip地址
#define SERVER_PORT "10500"						//端口号

#define AT_ERROR "at指令错误 \r\n"
#define MODE_ERROR "工作模式设置错误\r\n"
#define CONECT_WIFI_ERROR "无法连接wifi\r\n"
#define CONECT_SERVER_ERROR "无法连接服务器\r\n"

#define DEBUG 1			//debug模式下设置为1

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


