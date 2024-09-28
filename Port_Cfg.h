/*
 * Port_Cfg.h
 *
 *  Created on: Aug 21, 2024
 *      Author: Administrator
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/*The number of specified PortPins in this.*/
#define Port_Number_Of_PortPins                   (43U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                    (STD_ON)

/*Pre-processor switch to enable / disable the use of the function Port_SetPinDirection()*/
#define PORT_SET_PIN_DIRECTION_API               (STD_ON)

/*Pre-processor switch to enable / disable the use of the function Port_SetPinMode()*/
#define PORT_SET_PIN_MODE_API                    (STD_ON)

/*Pre-processor switch to enable / disable the API to read out the modules version information*/
#define PORT_VERSION_INFO_API                    (STD_ON)


/*indicate if the direction is changeable on a port pin during runtime[ISN'T ALREADY DONE BY THE SET DIR API?].*/
#define PORT_PIN_DIRECTION_CHANGEABLE            (STD_ON)

/*Parameter to indicate if the mode is changeable on a port pin during runtime.*/
#define PORT_PIN_MODE_CHANGEABLE                 (STD_ON)


/*Port Numbers*/
#define PORT_A                                   (uint8)0
#define PORT_B                                   (uint8)1
#define PORT_C                                   (uint8)2
#define PORT_D                                   (uint8)3
#define PORT_E                                   (uint8)4
#define PORT_F                                   (uint8)5

/*Pin Numbers*/
#define PORT_PIN_0                               (uint8)0
#define PORT_PIN_1                               (uint8)1
#define PORT_PIN_2                               (uint8)2
#define PORT_PIN_3                               (uint8)3
#define PORT_PIN_4                               (uint8)4
#define PORT_PIN_5                               (uint8)5
#define PORT_PIN_6                               (uint8)6
#define PORT_PIN_7                               (uint8)7

/*Port pin mode from mode list for use with Port_Init() function.*/

//#define PORT_PIN_MODE_ADC                 (uint8)0
#define PORT_PIN_MODE_DIO                 (uint8)0
//#define PORT_PIN_MODE_CAN                 (uint8)1
#define PORT_PIN_MODE_UART                (uint8)1
#define PORT_PIN_MODE_ADC                 (uint8)2
#define PORT_PIN_MODE_DIO_GPT             (uint8)3
#define PORT_PIN_MODE_DIO_WDG             (uint8)4
#define PORT_PIN_MODE_FLEXRAY             (uint8)5
#define PORT_PIN_MODE_ICU                 (uint8)6
#define PORT_PIN_MODE_LIN                 (uint8)7
#define PORT_PIN_MODE_MEM                 (uint8)8
#define PORT_PIN_MODE_PWM                 (uint8)9
#define PORT_PIN_MODE_SPI                 (uint8)10
#define PORT_PIN_MODE_CAN                 (uint8)11



/*Port Pin Level value from Port pin list.*/
#define PORT_PIN_LEVEL_HIGH              (STD_HIGH)
#define PORT_PIN_LEVEL_LOW               (STD_LOW)


/*******************************************************************************
 *                             Port Pin ID                             *
 *******************************************************************************/

#define PORT_A_PIN_0                               (Port_PinType)0
#define PORT_A_PIN_1                               (Port_PinType)1
#define PORT_A_PIN_2                               (Port_PinType)2
#define PORT_A_PIN_3                               (Port_PinType)3
#define PORT_A_PIN_4                               (Port_PinType)4
#define PORT_A_PIN_5                               (Port_PinType)5
#define PORT_A_PIN_6                               (Port_PinType)6
#define PORT_A_PIN_7                               (Port_PinType)7


#define PORT_B_PIN_0                               (Port_PinType)0
#define PORT_B_PIN_1                               (Port_PinType)1
#define PORT_B_PIN_2                               (Port_PinType)2
#define PORT_B_PIN_3                               (Port_PinType)3
#define PORT_B_PIN_4                               (Port_PinType)4
#define PORT_B_PIN_5                               (Port_PinType)5
#define PORT_B_PIN_6                               (Port_PinType)6
#define PORT_B_PIN_7                               (Port_PinType)7



#define PORT_C_PIN_4                               (Port_PinType)4
#define PORT_C_PIN_5                               (Port_PinType)5
#define PORT_C_PIN_6                               (Port_PinType)6
#define PORT_C_PIN_7                               (Port_PinType)7

#define PORT_D_PIN_0                               (Port_PinType)0
#define PORT_D_PIN_1                               (Port_PinType)1
#define PORT_D_PIN_2                               (Port_PinType)2
#define PORT_D_PIN_3                               (Port_PinType)3
#define PORT_D_PIN_4                               (Port_PinType)4
#define PORT_D_PIN_5                               (Port_PinType)5
#define PORT_D_PIN_6                               (Port_PinType)6
#define PORT_D_PIN_7                               (Port_PinType)7


#define PORT_E_PIN_0                               (Port_PinType)0
#define PORT_E_PIN_1                               (Port_PinType)1
#define PORT_E_PIN_2                               (Port_PinType)2
#define PORT_E_PIN_3                               (Port_PinType)3
#define PORT_E_PIN_4                               (Port_PinType)4
#define PORT_E_PIN_5                               (Port_PinType)5
#define PORT_E_PIN_6                               (Port_PinType)6
#define PORT_E_PIN_7                               (Port_PinType)7


#define PORT_F_PIN_0                               (Port_PinType)0
#define PORT_F_PIN_1                               (Port_PinType)1
#define PORT_F_PIN_2                               (Port_PinType)2
#define PORT_F_PIN_3                               (Port_PinType)3
#define PORT_F_PIN_4                               (Port_PinType)4
#define PORT_F_PIN_5                               (Port_PinType)5
#define PORT_F_PIN_6                               (Port_PinType)6
#define PORT_F_PIN_7                               (Port_PinType)7



/*******************************************************************************
 *                             Port Pin Mode Type                             *
 *******************************************************************************/

#define PORT_A_PIN_0_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_1_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_2_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_3_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_A_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO


#define PORT_B_PIN_0_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_1_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_2_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_3_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_B_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO



#define PORT_C_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_C_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_C_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_C_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO


#define PORT_D_PIN_0_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_1_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_2_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_3_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_D_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO



#define PORT_E_PIN_0_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_1_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_2_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_3_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_E_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO



#define PORT_F_PIN_0_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_1_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_2_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_3_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_4_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_5_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_6_INITIAL_MODE                  PORT_PIN_MODE_DIO
#define PORT_F_PIN_7_INITIAL_MODE                  PORT_PIN_MODE_DIO

/*******************************************************************************
 *                             Port Pin Direction                            *
 *******************************************************************************/
#define PORT_A_PIN_0_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_1_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_2_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_3_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_4_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_A_PIN_7_DIRECTION                     PORT_PIN_OUT


#define PORT_B_PIN_0_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_1_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_2_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_3_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_4_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_B_PIN_7_DIRECTION                     PORT_PIN_OUT


#define PORT_C_PIN_4_DIRECTION                     PORT_PIN_OUT
#define PORT_C_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_C_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_C_PIN_7_DIRECTION                     PORT_PIN_OUT


#define PORT_D_PIN_0_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_1_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_2_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_3_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_4_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_D_PIN_7_DIRECTION                     PORT_PIN_OUT



#define PORT_E_PIN_0_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_1_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_2_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_3_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_4_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_E_PIN_7_DIRECTION                     PORT_PIN_OUT



#define PORT_F_PIN_0_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_1_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_2_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_3_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_4_DIRECTION                     PORT_PIN_IN
#define PORT_F_PIN_5_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_6_DIRECTION                     PORT_PIN_OUT
#define PORT_F_PIN_7_DIRECTION                     PORT_PIN_OUT

/*******************************************************************************
 *                             Port Pin Resistor                            *
 *******************************************************************************/
#define PORT_A_PIN_0_RESISTOR                      PULL_UP
#define PORT_A_PIN_1_RESISTOR                      PULL_UP
#define PORT_A_PIN_2_RESISTOR                      PULL_UP
#define PORT_A_PIN_3_RESISTOR                      PULL_UP
#define PORT_A_PIN_4_RESISTOR                      PULL_UP
#define PORT_A_PIN_5_RESISTOR                      PULL_UP
#define PORT_A_PIN_6_RESISTOR                      PULL_UP
#define PORT_A_PIN_7_RESISTOR                      PULL_UP


#define PORT_B_PIN_0_RESISTOR                      PULL_UP
#define PORT_B_PIN_1_RESISTOR                      PULL_UP
#define PORT_B_PIN_2_RESISTOR                      PULL_UP
#define PORT_B_PIN_3_RESISTOR                      PULL_UP
#define PORT_B_PIN_4_RESISTOR                      PULL_UP
#define PORT_B_PIN_5_RESISTOR                      PULL_UP
#define PORT_B_PIN_6_RESISTOR                      PULL_UP
#define PORT_B_PIN_7_RESISTOR                      PULL_UP


#define PORT_C_PIN_4_RESISTOR                      PULL_UP
#define PORT_C_PIN_5_RESISTOR                      PULL_UP
#define PORT_C_PIN_6_RESISTOR                      PULL_UP
#define PORT_C_PIN_7_RESISTOR                      PULL_UP


#define PORT_D_PIN_0_RESISTOR                      PULL_UP
#define PORT_D_PIN_1_RESISTOR                      PULL_UP
#define PORT_D_PIN_2_RESISTOR                      PULL_UP
#define PORT_D_PIN_3_RESISTOR                      PULL_UP
#define PORT_D_PIN_4_RESISTOR                      PULL_UP
#define PORT_D_PIN_5_RESISTOR                      PULL_UP
#define PORT_D_PIN_6_RESISTOR                      PULL_UP
#define PORT_D_PIN_7_RESISTOR                      PULL_UP


#define PORT_E_PIN_0_RESISTOR                      PULL_UP
#define PORT_E_PIN_1_RESISTOR                      PULL_UP
#define PORT_E_PIN_2_RESISTOR                      PULL_UP
#define PORT_E_PIN_3_RESISTOR                      PULL_UP
#define PORT_E_PIN_4_RESISTOR                      PULL_UP
#define PORT_E_PIN_5_RESISTOR                      PULL_UP
#define PORT_E_PIN_6_RESISTOR                      PULL_UP
#define PORT_E_PIN_7_RESISTOR                      PULL_UP


#define PORT_F_PIN_0_RESISTOR                      PULL_UP
#define PORT_F_PIN_1_RESISTOR                      OFF      //LED
#define PORT_F_PIN_2_RESISTOR                      PULL_UP
#define PORT_F_PIN_3_RESISTOR                      PULL_UP
#define PORT_F_PIN_4_RESISTOR                      PULL_UP  //Button
#define PORT_F_PIN_5_RESISTOR                      PULL_UP
#define PORT_F_PIN_6_RESISTOR                      PULL_UP
#define PORT_F_PIN_7_RESISTOR                      PULL_UP

/*******************************************************************************
 *                             Port Pin Initial_Value                            *
 *******************************************************************************/
#define PORT_A_PIN_0_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_1_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_2_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_3_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW


#define PORT_B_PIN_0_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_1_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_2_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_3_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW


#define PORT_C_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW


#define PORT_D_PIN_0_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_1_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_2_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_3_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW


#define PORT_E_PIN_0_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_1_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_2_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_3_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_E_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW


#define PORT_F_PIN_0_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_1_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_2_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_3_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_4_LEVEL_VALUE                    PORT_PIN_LEVEL_HIGH  //button
#define PORT_F_PIN_5_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_6_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW
#define PORT_F_PIN_7_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW

/*******************************************************************************
 *                             Port Pin Direction Changeable                          *
 *******************************************************************************/
#define PORT_A_PIN_0_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_1_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_2_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_3_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)


#define PORT_B_PIN_0_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_1_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_2_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_3_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)


#define PORT_C_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)


#define PORT_D_PIN_0_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_1_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_2_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_3_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)


#define PORT_E_PIN_0_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_1_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_2_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_3_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)


#define PORT_F_PIN_0_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_1_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_2_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_3_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_4_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_5_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_6_DIRECTION_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_7_DIRECTION_CHANGEABLE                 (STD_OFF)

/*******************************************************************************
 *                             Port Pin Mode Changeable                          *
 *******************************************************************************/
#define PORT_A_PIN_0_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_1_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_2_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_3_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_A_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#define PORT_B_PIN_0_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_1_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_2_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_3_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_B_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#define PORT_C_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_C_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#define PORT_D_PIN_0_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_1_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_2_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_3_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_D_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#define PORT_E_PIN_0_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_1_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_2_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_3_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_E_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#define PORT_F_PIN_0_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_1_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_2_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_3_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_4_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_5_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_6_MODE_CHANGEABLE                 (STD_OFF)
#define PORT_F_PIN_7_MODE_CHANGEABLE                 (STD_OFF)


#endif /* PORT_CFG_H_ */
