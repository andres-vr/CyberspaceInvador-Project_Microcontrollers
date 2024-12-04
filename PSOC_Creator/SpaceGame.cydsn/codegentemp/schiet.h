/*******************************************************************************
* File Name: schiet.h  
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

#if !defined(CY_PINS_schiet_H) /* Pins schiet_H */
#define CY_PINS_schiet_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "schiet_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 schiet__PORT == 15 && ((schiet__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    schiet_Write(uint8 value);
void    schiet_SetDriveMode(uint8 mode);
uint8   schiet_ReadDataReg(void);
uint8   schiet_Read(void);
void    schiet_SetInterruptMode(uint16 position, uint16 mode);
uint8   schiet_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the schiet_SetDriveMode() function.
     *  @{
     */
        #define schiet_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define schiet_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define schiet_DM_RES_UP          PIN_DM_RES_UP
        #define schiet_DM_RES_DWN         PIN_DM_RES_DWN
        #define schiet_DM_OD_LO           PIN_DM_OD_LO
        #define schiet_DM_OD_HI           PIN_DM_OD_HI
        #define schiet_DM_STRONG          PIN_DM_STRONG
        #define schiet_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define schiet_MASK               schiet__MASK
#define schiet_SHIFT              schiet__SHIFT
#define schiet_WIDTH              1u

/* Interrupt constants */
#if defined(schiet__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in schiet_SetInterruptMode() function.
     *  @{
     */
        #define schiet_INTR_NONE      (uint16)(0x0000u)
        #define schiet_INTR_RISING    (uint16)(0x0001u)
        #define schiet_INTR_FALLING   (uint16)(0x0002u)
        #define schiet_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define schiet_INTR_MASK      (0x01u) 
#endif /* (schiet__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define schiet_PS                     (* (reg8 *) schiet__PS)
/* Data Register */
#define schiet_DR                     (* (reg8 *) schiet__DR)
/* Port Number */
#define schiet_PRT_NUM                (* (reg8 *) schiet__PRT) 
/* Connect to Analog Globals */                                                  
#define schiet_AG                     (* (reg8 *) schiet__AG)                       
/* Analog MUX bux enable */
#define schiet_AMUX                   (* (reg8 *) schiet__AMUX) 
/* Bidirectional Enable */                                                        
#define schiet_BIE                    (* (reg8 *) schiet__BIE)
/* Bit-mask for Aliased Register Access */
#define schiet_BIT_MASK               (* (reg8 *) schiet__BIT_MASK)
/* Bypass Enable */
#define schiet_BYP                    (* (reg8 *) schiet__BYP)
/* Port wide control signals */                                                   
#define schiet_CTL                    (* (reg8 *) schiet__CTL)
/* Drive Modes */
#define schiet_DM0                    (* (reg8 *) schiet__DM0) 
#define schiet_DM1                    (* (reg8 *) schiet__DM1)
#define schiet_DM2                    (* (reg8 *) schiet__DM2) 
/* Input Buffer Disable Override */
#define schiet_INP_DIS                (* (reg8 *) schiet__INP_DIS)
/* LCD Common or Segment Drive */
#define schiet_LCD_COM_SEG            (* (reg8 *) schiet__LCD_COM_SEG)
/* Enable Segment LCD */
#define schiet_LCD_EN                 (* (reg8 *) schiet__LCD_EN)
/* Slew Rate Control */
#define schiet_SLW                    (* (reg8 *) schiet__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define schiet_PRTDSI__CAPS_SEL       (* (reg8 *) schiet__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define schiet_PRTDSI__DBL_SYNC_IN    (* (reg8 *) schiet__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define schiet_PRTDSI__OE_SEL0        (* (reg8 *) schiet__PRTDSI__OE_SEL0) 
#define schiet_PRTDSI__OE_SEL1        (* (reg8 *) schiet__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define schiet_PRTDSI__OUT_SEL0       (* (reg8 *) schiet__PRTDSI__OUT_SEL0) 
#define schiet_PRTDSI__OUT_SEL1       (* (reg8 *) schiet__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define schiet_PRTDSI__SYNC_OUT       (* (reg8 *) schiet__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(schiet__SIO_CFG)
    #define schiet_SIO_HYST_EN        (* (reg8 *) schiet__SIO_HYST_EN)
    #define schiet_SIO_REG_HIFREQ     (* (reg8 *) schiet__SIO_REG_HIFREQ)
    #define schiet_SIO_CFG            (* (reg8 *) schiet__SIO_CFG)
    #define schiet_SIO_DIFF           (* (reg8 *) schiet__SIO_DIFF)
#endif /* (schiet__SIO_CFG) */

/* Interrupt Registers */
#if defined(schiet__INTSTAT)
    #define schiet_INTSTAT            (* (reg8 *) schiet__INTSTAT)
    #define schiet_SNAP               (* (reg8 *) schiet__SNAP)
    
	#define schiet_0_INTTYPE_REG 		(* (reg8 *) schiet__0__INTTYPE)
#endif /* (schiet__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_schiet_H */


/* [] END OF FILE */
