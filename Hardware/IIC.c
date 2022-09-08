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
///**************************ʵ�ֺ���********************************************
//*����ԭ��:		uint8_t IICreadByte(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data)
//*��������:	    ��ȡָ���豸 ָ���Ĵ�����һ��ֵ
//����	dev_addr  Ŀ���豸��ַ
//		reg_addr	   �Ĵ�����ַ
//		*data  ���������ݽ�Ҫ��ŵĵ�ַ
//����   0,1
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

///**************************ʵ�ֺ���********************************************
//*����ԭ��:		uint8_t IIC_WriteBits(uint8_t dev_addr,uint8_t reg_addr,uint8_t bitStart,uint8_t length,uint8_t data)
//*��������:	    �� �޸� д ָ���豸 ָ���Ĵ���һ���ֽ� �еĶ��λ
//����	dev_addr  Ŀ���豸��ַ
//		reg_addr	   �Ĵ�����ַ
//		bitStart  Ŀ���ֽڵ���ʼλ
//		length   λ����
//		data    ��Ÿı�Ŀ���ֽ�λ��ֵ
//����   �ɹ� Ϊ1 
// 		ʧ��Ϊ0
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
///**************************ʵ�ֺ���********************************************
//*����ԭ��:		uint8_t IICwriteBit(uint8_t dev, uint8_t reg, uint8_t bitNum, uint8_t data)
//*��������:	    �� �޸� д ָ���豸 ָ���Ĵ���һ���ֽ� �е�1��λ
//����	dev  Ŀ���豸��ַ
//		reg	   �Ĵ�����ַ
//		bitNum  Ҫ�޸�Ŀ���ֽڵ�bitNumλ
//		data  Ϊ0 ʱ��Ŀ��λ������0 ���򽫱���λ
//����   �ɹ� Ϊ1 
// 		ʧ��Ϊ0
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