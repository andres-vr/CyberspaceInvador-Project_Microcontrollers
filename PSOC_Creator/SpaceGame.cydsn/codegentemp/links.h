/*******************************************************************************
* File Name: links.h  
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

#if !defined(CY_PINS_links_H) /* Pins links_H */
#define CY_PINS_links_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "links_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 links__PORT == 15 && ((links__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    links_Write(uint8 value);
void    links_SetDriveMode(uint8 mode);
uint8   links_ReadDataReg(void);
uint8   links_Read(void);
void    links_SetInterruptMode(uint16 position, uint16 mode);
uint8   links_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the links_SetDriveMode() function.
     *  @{
     */
        #define links_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define links_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define links_DM_RES_UP          PIN_DM_RES_UP
        #define links_DM_RES_DWN         PIN_DM_RES_DWN
        #define links_DM_OD_LO           PIN_DM_OD_LO
        #define links_DM_OD_HI           PIN_DM_OD_HI
        #define links_DM_STRONG          PIN_DM_STRONG
        #define links_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define links_MASK               links__MASK
#define links_SHIFT              links__SHIFT
#define links_WIDTH              1u

/* Interrupt constants */
#if defined(links__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in links_SetInterruptMode() function.
     *  @{
     */
        #define links_INTR_NONE      (uint16)(0x0000u)
        #define links_INTR_RISING    (uint16)(0x0001u)
        #define links_INTR_FALLING   (uint16)(0x0002u)
        #define links_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define links_INTR_MASK      (0x01u) 
#endif /* (links__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define links_PS                     (* (reg8 *) links__PS)
/* Data Register */
#define links_DR                     (* (reg8 *) links__DR)
/* Port Number */
#define links_PRT_NUM                (* (reg8 *) links__PRT) 
/* Connect to Analog Globals */                                                  
#define links_AG                     (* (reg8 *) links__AG)                       
/* Analog MUX bux enable */
#define links_AMUX                   (* (reg8 *) links__AMUX) 
/* Bidirectional Enable */                                                        
#define links_BIE                    (* (reg8 *) links__BIE)
/* Bit-mask for Aliased Register Access */
#define links_BIT_MASK               (* (reg8 *) links__BIT_MASK)
/* Bypass Enable */
#define links_BYP                    (* (reg8 *) links__BYP)
/* Port wide control signals */                                                   
#define links_CTL                    (* (reg8 *) links__CTL)
/* Drive Modes */
#define links_DM0                    (* (reg8 *) links__DM0) 
#define links_DM1                    (* (reg8 *) links__DM1)
#define links_DM2                    (* (reg8 *) links__DM2) 
/* Input Buffer Disable Override */
#define links_INP_DIS                (* (reg8 *) links__INP_DIS)
/* LCD Common or Segment Drive */
#define links_LCD_COM_SEG            (* (reg8 *) links__LCD_COM_SEG)
/* Enable Segment LCD */
#define links_LCD_EN                 (* (reg8 *) links__LCD_EN)
/* Slew Rate Control */
#define links_SLW                    (* (reg8 *) links__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define links_PRTDSI__CAPS_SEL       (* (reg8 *) links__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define links_PRTDSI__DBL_SYNC_IN    (* (reg8 *) links__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define links_PRTDSI__OE_SEL0        (* (reg8 *) links__PRTDSI__OE_SEL0) 
#define links_PRTDSI__OE_SEL1        (* (reg8 *) links__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define links_PRTDSI__OUT_SEL0       (* (reg8 *) links__PRTDSI__OUT_SEL0) 
#define links_PRTDSI__OUT_SEL1       (* (reg8 *) links__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define links_PRTDSI__SYNC_OUT       (* (reg8 *) links__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(links__SIO_CFG)
    #define links_SIO_HYST_EN        (* (reg8 *) links__SIO_HYST_EN)
    #define links_SIO_REG_HIFREQ     (* (reg8 *) links__SIO_REG_HIFREQ)
    #define links_SIO_CFG            (* (reg8 *) links__SIO_CFG)
    #define links_SIO_DIFF           (* (reg8 *) links__SIO_DIFF)
#endif /* (links__SIO_CFG) */

/* Interrupt Registers */
#if defined(links__INTSTAT)
    #define links_INTSTAT            (* (reg8 *) links__INTSTAT)
    #define links_SNAP               (* (reg8 *) links__SNAP)
    
	#define links_0_INTTYPE_REG 		(* (reg8 *) links__0__INTTYPE)
#endif /* (links__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_links_H */


/* [] END OF FILE */
