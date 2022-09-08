//#include "main.h"

//extern I2C_HandleTypeDef hi2c1;

//uint8_t IIC_ReadBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata)
//{
//	uint8_t r_value = 0;
//    r_value = HAL_I2C_Mem_Read(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, pdata, length, 1000);
//	return r_value;
//}
//uint8_t IIC_WriteBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata)
//{
//	uint8_t r_value = 0;
//    r_value = HAL_I2C_Mem_Write(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, pdata, length, 1000);
//	return r_value;
//}
///**************************实现函数********************************************
//*函数原型:		uint8_t IICreadByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data)
//*功　　能:	    读取指定设备 指定寄存器的一个值
//输入	dev_addr  目标设备地址
//		reg_addr	   寄存器地址
//		*data  读出的数据将要存放的地址
//返回   0,1
//*******************************************************************************/ 
//uint8_t IIC_ReadByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data)
//{
//	uint8_t r_value = 0;
//	r_value = HAL_I2C_Mem_Read(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, data, 1, 1000);  
//	return r_value;	
//}
//uint8_t IIC_WriteByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t data)
//{
//	uint8_t r_value = 0;
//    r_value = HAL_I2C_Mem_Write(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, &data, 1, 1000);
//	return r_value;
//}

///**************************实现函数********************************************
//*函数原型:		uint8_t IIC_WriteBits(uint8_t dev_addr,uint8_t reg_addr,uint8_t bitStart,uint8_t length,uint8_t data)
//*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的多个位
//输入	dev_addr  目标设备地址
//		reg_addr	   寄存器地址
//		bitStart  目标字节的起始位
//		length   位长度
//		data    存放改变目标字节位的值
//返回   成功 为1 
// 		失败为0
//*******************************************************************************/ 
//uint8_t IIC_WriteBits(uint8_t dev_addr, uint8_t reg_addr,uint8_t bitStart,uint8_t length,uint8_t data)
//{

//    uint8_t b;
//    if (IIC_ReadByte(dev_addr, reg_addr, &b) != 0) 
//	{
//        uint8_t mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
//        data <<= (8 - length);
//        data >>= (7 - bitStart);
//        b &= mask;
//        b |= data;
//        return IIC_WriteByte(dev_addr, reg_addr, b);
//    } else {
//        return 0;
//    }
//}
///**************************实现函数********************************************
//*函数原型:		uint8_t IICwriteBit(uint8_t dev, uint8_t reg, uint8_t bitNum, uint8_t data)
//*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的1个位
//输入	dev  目标设备地址
//		reg	   寄存器地址
//		bitNum  要修改目标字节的bitNum位
//		data  为0 时，目标位将被清0 否则将被置位
//返回   成功 为1 
// 		失败为0
//*******************************************************************************/ 
//uint8_t IICwriteBit(uint8_t dev, uint8_t reg, uint8_t bitNum, uint8_t data)
//{
//    uint8_t b;
//    IIC_ReadByte(dev, reg, &b);
//    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
//    return IIC_WriteByte(dev, reg, b);
//}
//uint8_t mpu_ReadBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata)
//{
//	uint8_t r_value = 0;
//	dev_addr <<= 1;
//	r_value = IIC_ReadBytes(dev_addr,reg_addr,length,pdata);
//	return r_value;	 
//}
//uint8_t mpu_WriteBytes(uint8_t dev_addr,uint8_t reg_addr, uint8_t length, uint8_t *pdata)
//{
//    uint8_t r_value = 0;
//	dev_addr <<= 1;
//	r_value = IIC_WriteBytes(dev_addr,reg_addr,length,pdata);
//	return r_value;	 
//}