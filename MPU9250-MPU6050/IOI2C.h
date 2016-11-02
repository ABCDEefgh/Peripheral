#ifndef __IOI2C_H
#define __IOI2C_H
#include "stm32l0xx_hal.h"

//IO�ڲ����궨��
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

#define SCL_H         GPIOB->BSRR = GPIO_PIN_8
#define SCL_L         GPIOB->BRR  = GPIO_PIN_8

#define SDA_H         GPIOB->BSRR = GPIO_PIN_9
#define SDA_L         GPIOB->BRR  = GPIO_PIN_9

#define SCL_read      GPIOB->IDR  & GPIO_PIN_8
#define SDA_read      GPIOB->IDR  & GPIO_PIN_9

//IIC���в�������
extern void IIC_Init(void);                //��ʼ��IIC��IO��
extern uint8_t IIC_Start(void);				//����IIC��ʼ�ź�
extern void IIC_Stop(void);	  			//����IICֹͣ�ź�
extern void IIC_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
extern uint8_t IIC_Read_Byte(void);//IIC��ȡһ���ֽ�
extern uint8_t IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
extern void IIC_Ack(void);					//IIC����ACK�ź�
extern void IIC_NAck(void);				//IIC������ACK�ź�

extern void IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
extern uint8_t IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);
extern unsigned char I2C_Readkey(unsigned char I2C_Addr);

extern unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr);
extern unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data);
extern uint8_t IICwriteBytes(uint8_t dev, uint8_t reg, uint8_t length, uint8_t* data);
extern uint8_t IICwriteBits(uint8_t dev,uint8_t reg,uint8_t bitStart,uint8_t length,uint8_t data);
extern uint8_t IICwriteBit(uint8_t dev,uint8_t reg,uint8_t bitNum,uint8_t data);
extern uint8_t IICreadBytes(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t len,uint8_t *data);

extern void IIC_Analog(void);

#endif

//------------------End of File----------------------------
