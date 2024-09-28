 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_PinsConfig * Port_Pins = NULL_PTR;

STATIC uint8 Port_Init_Status = PORT_NOT_INITIALIZED;

/************************************************************************************

* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Port_Pins - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Pointer to configuration set
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{

#if(PORT_DEV_ERROR_DETECT== STD_ON)
    {
        if(ConfigPtr== NULL_PTR)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_INIT_SID,
                             PORT_E_PARAM_CONFIG);
        }
        else
        {
           //nth
        }


    }
#endif
    Port_Pins = ConfigPtr->Port_Pins_Config;

    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    uint8 i;
    for( i = 0 ; i<Port_Number_Of_PortPins; i++)
    {
        switch(Port_Pins[i].port_num)
            {
                case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                         break;
                case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                         break;
                case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                         break;
                case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                         break;
                case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                         break;
                case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                         break;
            }
        if( ((Port_Pins[i].port_num == 3) && (Port_Pins[i].pin_num == 7)) || ((Port_Pins[i].port_num == 5) && (Port_Pins[i].pin_num == 0)) ) /* PD7 or PF0 */
            {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[i].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            }
            else if( (Port_Pins[i].port_num == 2) && (Port_Pins[i].pin_num <= 3) ) /* PC0 to PC3 */
            {
                /* Do Nothing ...  this is the JTAG pins */
            }
            else
            {
                /* Do Nothing ... No need to unlock the commit register for this pin */
            }
        if(Port_Pins[i].direction == PORT_PIN_OUT)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

                if(Port_Pins[i].initial_value == STD_HIGH)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[i].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[i].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                }
            }
            else if(Port_Pins[i].direction == PORT_PIN_IN)
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

                if(Port_Pins[i].resistor == PULL_UP)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[i].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                }
                else if(Port_Pins[i].resistor == PULL_DOWN)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[i].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[i].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[i].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                }
            }
            else
            {
                /* Do Nothing */
            }
        if(Port_Pins[i].Pin_Mode == PORT_PIN_MODE_DIO)
        {
            /* Setup the pin mode as GPIO */
               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
               *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[i].pin_num * 4));     /* Clear the PMCx bits for this pin */
               SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */

        }
        else if(Port_Pins[i].Pin_Mode == PORT_PIN_MODE_UART)
        {
            /* Setup the pin mode as GPIO */
               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
               SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
               *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[i].pin_num * 4));     /* Clear the PMCx bits for this pin */
               *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000001 << (Port_Pins[i].pin_num * 4));     /* Set the PMCx bits for this pin */
               SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        }
        else
        {
         //Expand Cases
        }




    }
    Port_Init_Status= PORT_INITIALIZED;
}


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
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
#if(PORT_DEV_ERROR_DETECT== STD_ON)
    {
        if(Pin > Port_Number_Of_PortPins)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_SET_PIN_DIRECTION_SID,
                             PORT_E_PARAM_PIN);
        }
        else
        {
           //nth
        }
        if(Port_Pins[Pin].Port_Pin_Direction_Changeable == STD_OFF)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_SET_PIN_DIRECTION_SID,
                             PORT_E_DIRECTION_UNCHANGEABLE);
        }
        else
        {

        }
        if( Port_Init_Status== PORT_NOT_INITIALIZED)
               {
                    Det_ReportError( PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     PORT_SET_PIN_DIRECTION_SID,
                                     PORT_E_UNINIT);
                }
                else
                {
                   //nth
                }


    }
#endif

    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    switch(Port_Pins[Pin].port_num)
               {
                   case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                            break;
                   case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                            break;
                   case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                            break;
                   case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                            break;
                   case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                            break;
                   case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                            break;
               }


    if(Direction == PORT_PIN_OUT)
               {
                   SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */


               }
               else if(Direction == PORT_PIN_IN)
               {
                   CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */


               }
               else
               {
                   /* Do Nothing */
               }


}
#endif



/************************************************************************************

* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): VOID
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: refreshes the direction of all configured ports to the configured direction
************************************************************************************/
void Port_RefreshPortDirection( void )
{
#if(PORT_DEV_ERROR_DETECT== STD_ON)
    {
        if( Port_Init_Status== PORT_NOT_INITIALIZED)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_REFRESH_PORT_DIRECTION_SID,
                             PORT_E_UNINIT);
        }
        else
        {
           //nth
        }


    }
#endif

    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    uint8 i;
    for( i=0; i<Port_Number_Of_PortPins; i++)
    {
        switch(Port_Pins[i].port_num)
                          {
                              case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                                       break;
                              case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                                       break;
                              case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                                       break;
                              case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                                       break;
                              case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                                       break;
                              case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                                       break;
                          }

        if(Port_Pins[i].Port_Pin_Direction_Changeable == STD_OFF)
        {
        if(Port_Pins[i].direction == PORT_PIN_OUT)
                   {
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */


                   }
                   else if(Port_Pins[i].direction == PORT_PIN_IN)
                   {
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */


                   }
                   else
                   {
                       /* Do Nothing */
                   }
        }
        else if(Port_Pins[i].Port_Pin_Direction_Changeable == STD_ON)
        {
            //report error
        }
        else
        {
            //nth
        }

    }


}

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
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if(PORT_DEV_ERROR_DETECT== STD_ON)
    {
        if(Port_Init_Status == PORT_NOT_INITIALIZED)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_GET_VERSION_INFO_SID,
                             PORT_E_UNINIT);
        }
        else
        {
           //nth
        }

        if(versioninfo == NULL_PTR)
               {
                   Det_ReportError( PORT_MODULE_ID,
                                    PORT_INSTANCE_ID,
                                    PORT_GET_VERSION_INFO_SID,
                                    PORT_E_UNINIT);
               }
               else
               {
                  //nth
               }



    }
#endif



}
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
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

#if(PORT_DEV_ERROR_DETECT== STD_ON)
    {
        if(Pin > Port_Number_Of_PortPins)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_SET_PIN_MODE_SID,
                             PORT_E_PARAM_PIN);
        }
        else
        {
           //nth
        }
        if(Mode > 9 &&  Mode != 14)
                {
                    Det_ReportError( PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     PORT_SET_PIN_MODE_SID,
                                     PORT_E_PARAM_INVALID_MODE);
                }
                else
                {
                   //nth
                }
        if(Port_Pins[Pin].Port_Pin_Mode_Changeable == STD_OFF)
        {
            Det_ReportError( PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_SET_PIN_MODE_SID,
                             PORT_E_PARAM_PIN);
        }
        else
        {
           //nth
        }
        if(Port_Init_Status == PORT_NOT_INITIALIZED)
                {
                    Det_ReportError( PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     PORT_SET_PIN_MODE_SID,
                                     PORT_E_UNINIT);
                }
                else
                {
                   //nth
                }


    }
#endif

    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
           switch(Port_Pins[Pin].port_num)
                      {
                          case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                                   break;
                          case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                                   break;
                          case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                                   break;
                          case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                                   break;
                          case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                                   break;
                          case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                                   break;
                      }

               if( Mode == PORT_PIN_MODE_DIO)
                       {
                           /* Setup the pin mode as GPIO */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pin_num * 4));     /* Clear the PMCx bits for this pin */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */

                       }
                       else if(Mode == PORT_PIN_MODE_UART)
                       {
                           /* Setup the pin mode as GPIO */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pin_num * 4));     /* Clear the PMCx bits for this pin */
                              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000001 << (Port_Pins[Pin].pin_num * 4));     /* Set the PMCx bits for this pin */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                       }
                       else
                       {
                        //Expand Cases
                       }



}
#endif

/*PORT223: If Det is enabled, the function Port_SetPinMode shall return
PORT_E_MODE_UNCHANGEABLE and return without any action,
 if the parameter PortPinModeChangeable is set to FALSE*/
