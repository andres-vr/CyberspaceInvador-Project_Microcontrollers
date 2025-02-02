/*******************************************************************************
* File Name: alien.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_alien_H) /* Pins alien_H */
#define CY_PINS_alien_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "alien_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 alien__PORT == 15 && ((alien__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    alien_Write(uint8 value);
void    alien_SetDriveMode(uint8 mode);
uint8   alien_ReadDataReg(void);
uint8   alien_Read(void);
void    alien_SetInterruptMode(uint16 position, uint16 mode);
uint8   alien_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the alien_SetDriveMode() function.
     *  @{
     */
        #define alien_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define alien_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define alien_DM_RES_UP          PIN_DM_RES_UP
        #define alien_DM_RES_DWN         PIN_DM_RES_DWN
        #define alien_DM_OD_LO           PIN_DM_OD_LO
        #define alien_DM_OD_HI           PIN_DM_OD_HI
        #define alien_DM_STRONG          PIN_DM_STRONG
        #define alien_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define alien_MASK               alien__MASK
#define alien_SHIFT              alien__SHIFT
#define alien_WIDTH              1u

/* Interrupt constants */
#if defined(alien__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in alien_SetInterruptMode() function.
     *  @{
     */
        #define alien_INTR_NONE      (uint16)(0x0000u)
        #define alien_INTR_RISING    (uint16)(0x0001u)
        #define alien_INTR_FALLING   (uint16)(0x0002u)
        #define alien_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define alien_INTR_MASK      (0x01u) 
#endif /* (alien__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define alien_PS                     (* (reg8 *) alien__PS)
/* Data Register */
#define alien_DR                     (* (reg8 *) alien__DR)
/* Port Number */
#define alien_PRT_NUM                (* (reg8 *) alien__PRT) 
/* Connect to Analog Globals */                                                  
#define alien_AG                     (* (reg8 *) alien__AG)                       
/* Analog MUX bux enable */
#define alien_AMUX                   (* (reg8 *) alien__AMUX) 
/* Bidirectional Enable */                                                        
#define alien_BIE                    (* (reg8 *) alien__BIE)
/* Bit-mask for Aliased Register Access */
#define alien_BIT_MASK               (* (reg8 *) alien__BIT_MASK)
/* Bypass Enable */
#define alien_BYP                    (* (reg8 *) alien__BYP)
/* Port wide control signals */                                                   
#define alien_CTL                    (* (reg8 *) alien__CTL)
/* Drive Modes */
#define alien_DM0                    (* (reg8 *) alien__DM0) 
#define alien_DM1                    (* (reg8 *) alien__DM1)
#define alien_DM2                    (* (reg8 *) alien__DM2) 
/* Input Buffer Disable Override */
#define alien_INP_DIS                (* (reg8 *) alien__INP_DIS)
/* LCD Common or Segment Drive */
#define alien_LCD_COM_SEG            (* (reg8 *) alien__LCD_COM_SEG)
/* Enable Segment LCD */
#define alien_LCD_EN                 (* (reg8 *) alien__LCD_EN)
/* Slew Rate Control */
#define alien_SLW                    (* (reg8 *) alien__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define alien_PRTDSI__CAPS_SEL       (* (reg8 *) alien__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define alien_PRTDSI__DBL_SYNC_IN    (* (reg8 *) alien__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define alien_PRTDSI__OE_SEL0        (* (reg8 *) alien__PRTDSI__OE_SEL0) 
#define alien_PRTDSI__OE_SEL1        (* (reg8 *) alien__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define alien_PRTDSI__OUT_SEL0       (* (reg8 *) alien__PRTDSI__OUT_SEL0) 
#define alien_PRTDSI__OUT_SEL1       (* (reg8 *) alien__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define alien_PRTDSI__SYNC_OUT       (* (reg8 *) alien__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(alien__SIO_CFG)
    #define alien_SIO_HYST_EN        (* (reg8 *) alien__SIO_HYST_EN)
    #define alien_SIO_REG_HIFREQ     (* (reg8 *) alien__SIO_REG_HIFREQ)
    #define alien_SIO_CFG            (* (reg8 *) alien__SIO_CFG)
    #define alien_SIO_DIFF           (* (reg8 *) alien__SIO_DIFF)
#endif /* (alien__SIO_CFG) */

/* Interrupt Registers */
#if defined(alien__INTSTAT)
    #define alien_INTSTAT            (* (reg8 *) alien__INTSTAT)
    #define alien_SNAP               (* (reg8 *) alien__SNAP)
    
	#define alien_0_INTTYPE_REG 		(* (reg8 *) alien__0__INTTYPE)
#endif /* (alien__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_alien_H */


/* [] END OF FILE */
