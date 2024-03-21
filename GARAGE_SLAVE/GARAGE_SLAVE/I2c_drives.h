/*
 * I2c_drives.h
 *
 * Created: 20/10/2023 02:05:13 م
 *  Author: handsa
 */ 


#ifndef I2C_DRIVES_H_
#define I2C_DRIVES_H_
void i2c_clock_init(unsigned long scl);
void i2c_start(void);
void i2c_adress(unsigned char address);
void i2c_data(unsigned char data);
void i2c_stop(void);
void i2c_set_address(unsigned char addres);
unsigned char i2c_slave_read(void);



#endif /* I2C_DRIVES_H_ */