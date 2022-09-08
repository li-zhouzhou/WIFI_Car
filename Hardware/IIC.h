#ifndef __IIC_H
#define __IIC_H

#include "main.h"

extern uint8_t IIC_ReadBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata);
extern uint8_t IIC_WriteBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata);
extern uint8_t IIC_ReadByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data);
extern uint8_t IIC_WriteByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t data);
extern uint8_t IIC_WriteBits(uint8_t dev_addr,uint8_t reg_addr,uint8_t bitStart,uint8_t length,uint8_t data);
extern uint8_t IICwriteBit(uint8_t dev, uint8_t reg, uint8_t bitNum, uint8_t data);
extern uint8_t mpu_ReadBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata);
extern uint8_t mpu_WriteBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata);

#endif