/*******************************************************************************
* File Name: knop.h  
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

#if !defined(CY_PINS_knop_H) /* Pins knop_H */
#define CY_PINS_knop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "knop_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 knop__PORT == 15 && ((knop__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    knop_Write(uint8 value);
void    knop_SetDriveMode(uint8 mode);
uint8   knop_ReadDataReg(void);
uint8   knop_Read(void);
void    knop_SetInterruptMode(uint16 position, uint16 mode);
uint8   knop_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the knop_SetDriveMode() function.
     *  @{
     */
        #define knop_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define knop_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define knop_DM_RES_UP          PIN_DM_RES_UP
        #define knop_DM_RES_DWN         PIN_DM_RES_DWN
        #define knop_DM_OD_LO           PIN_DM_OD_LO
        #define knop_DM_OD_HI           PIN_DM_OD_HI
        #define knop_DM_STRONG          PIN_DM_STRONG
        #define knop_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define knop_MASK               knop__MASK
#define knop_SHIFT              knop__SHIFT
#define knop_WIDTH              1u

/* Interrupt constants */
#if defined(knop__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in knop_SetInterruptMode() function.
     *  @{
     */
        #define knop_INTR_NONE      (uint16)(0x0000u)
        #define knop_INTR_RISING    (uint16)(0x0001u)
        #define knop_INTR_FALLING   (uint16)(0x0002u)
        #define knop_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define knop_INTR_MASK      (0x01u) 
#endif /* (knop__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define knop_PS                     (* (reg8 *) knop__PS)
/* Data Register */
#define knop_DR                     (* (reg8 *) knop__DR)
/* Port Number */
#define knop_PRT_NUM                (* (reg8 *) knop__PRT) 
/* Connect to Analog Globals */                                                  
#define knop_AG                     (* (reg8 *) knop__AG)                       
/* Analog MUX bux enable */
#define knop_AMUX                   (* (reg8 *) knop__AMUX) 
/* Bidirectional Enable */                                                        
#define knop_BIE                    (* (reg8 *) knop__BIE)
/* Bit-mask for Aliased Register Access */
#define knop_BIT_MASK               (* (reg8 *) knop__BIT_MASK)
/* Bypass Enable */
#define knop_BYP                    (* (reg8 *) knop__BYP)
/* Port wide control signals */                                                   
#define knop_CTL                    (* (reg8 *) knop__CTL)
/* Drive Modes */
#define knop_DM0                    (* (reg8 *) knop__DM0) 
#define knop_DM1                    (* (reg8 *) knop__DM1)
#define knop_DM2                    (* (reg8 *) knop__DM2) 
/* Input Buffer Disable Override */
#define knop_INP_DIS                (* (reg8 *) knop__INP_DIS)
/* LCD Common or Segment Drive */
#define knop_LCD_COM_SEG            (* (reg8 *) knop__LCD_COM_SEG)
/* Enable Segment LCD */
#define knop_LCD_EN                 (* (reg8 *) knop__LCD_EN)
/* Slew Rate Control */
#define knop_SLW                    (* (reg8 *) knop__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define knop_PRTDSI__CAPS_SEL       (* (reg8 *) knop__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define knop_PRTDSI__DBL_SYNC_IN    (* (reg8 *) knop__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define knop_PRTDSI__OE_SEL0        (* (reg8 *) knop__PRTDSI__OE_SEL0) 
#define knop_PRTDSI__OE_SEL1        (* (reg8 *) knop__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define knop_PRTDSI__OUT_SEL0       (* (reg8 *) knop__PRTDSI__OUT_SEL0) 
#define knop_PRTDSI__OUT_SEL1       (* (reg8 *) knop__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define knop_PRTDSI__SYNC_OUT       (* (reg8 *) knop__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(knop__SIO_CFG)
    #define knop_SIO_HYST_EN        (* (reg8 *) knop__SIO_HYST_EN)
    #define knop_SIO_REG_HIFREQ     (* (reg8 *) knop__SIO_REG_HIFREQ)
    #define knop_SIO_CFG            (* (reg8 *) knop__SIO_CFG)
    #define knop_SIO_DIFF           (* (reg8 *) knop__SIO_DIFF)
#endif /* (knop__SIO_CFG) */

/* Interrupt Registers */
#if defined(knop__INTSTAT)
    #define knop_INTSTAT            (* (reg8 *) knop__INTSTAT)
    #define knop_SNAP               (* (reg8 *) knop__SNAP)
    
	#define knop_0_INTTYPE_REG 		(* (reg8 *) knop__0__INTTYPE)
#endif /* (knop__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_knop_H */


/* [] END OF FILE */
