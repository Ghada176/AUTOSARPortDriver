 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H


/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (124U)

/* Dio Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Dio.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif


#include "Common_Macros.h"
#include "Std_Types.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
#define PORT_INIT_SID                            (uint8)0x00

#define PORT_SET_PIN_DIRECTION_SID               (uint8)0x01

#define PORT_REFRESH_PORT_DIRECTION_SID          (uint8)0x02

#define PORT_GET_VERSION_INFO_SID                (uint8)0x03

#define PORT_SET_PIN_MODE_SID                    (uint8)0x04



/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/*Invalid Port Pin ID requested*/
#define PORT_E_PARAM_PIN                         (uint8)0x0A

/*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0B

/*API Port_Init service called with wrong parameter.*/
#define PORT_E_PARAM_CONFIG                      (uint8)0x0C


/*API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0E

/*API service called without module initialization*/
#define PORT_E_UNINIT                            (uint8)0x0F

/*APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER                     (uint8)0x10


/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Shall cover all available port pins. 0=>num of port pins*/
typedef uint8 Port_PinType;


/*Different port pin modes*/
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
    //INPUT,OUTPUT
}Port_PinDirectionType;



/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    uint8 port_num; 
    Port_PinType pin_num;
    Port_PinModeType Pin_Mode;
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    uint8 Port_Pin_Direction_Changeable;
    uint8 Port_Pin_Mode_Changeable;


}Port_PinsConfig;

typedef struct Port_ConfigType
{
    Port_PinsConfig Port_Pins_Config[Port_Number_Of_PortPins] ;

}Port_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************

* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Pointer to configuration set
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr );


/************************************************************************************

* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Pin - Port Pin ID number, Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set the port pin direction during runtime.
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif
/* The function Port_SetPinDirection shall only be available
 *  to the user if the pre-compile parameter PortSetPinDirectionApi is set to TRUE.
 *   If set to FALSE, the function Port_SetPinDirection is not available. (see also section 8.3.2. */




/************************************************************************************

* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): VOID
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: refreshES the direction of all configured ports to the configured direction
************************************************************************************/
void Port_RefreshPortDirection( void );

/*The function Port_RefreshPortDirection shall
 *   exclude those port pins from refreshing
 *   that are configured as ‘pin direction changeable during runtime‘.*/



/************************************************************************************

* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): versioninfo - Pointer to where to store the version information of this module
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif
/*PORT103: The function Port_GetVersionInfo shall be pre compile time configurable On/Off by the configuration parameter PortVersionInfoApi.
PORT144: If source code for caller and callee of Port_GetVersionInfo is available, the PORT Driver module should realize Port_GetVersionInfo as a macro, defined in the module’s header file.
PORT225: if Det is enabled, the parameter versioninfo shall be
checked for being NULL. The error PORT_E_PARAM_POINTER shall be reported in case the value is a NULL pointer*/



/************************************************************************************

* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Pin ID, Mode - Pin Mode
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode of the referenced pin during runtime.
************************************************************************************/
#if(PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif
/*PORT223: If Det is enabled, the function Port_SetPinMode shall return
PORT_E_MODE_UNCHANGEABLE and return without any action,
 if the parameter PortPinModeChangeable is set to FALSE*/

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
