/*******************************************************************************
* File Name: player.h  
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

#if !defined(CY_PINS_player_H) /* Pins player_H */
#define CY_PINS_player_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "player_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 player__PORT == 15 && ((player__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    player_Write(uint8 value);
void    player_SetDriveMode(uint8 mode);
uint8   player_ReadDataReg(void);
uint8   player_Read(void);
void    player_SetInterruptMode(uint16 position, uint16 mode);
uint8   player_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the player_SetDriveMode() function.
     *  @{
     */
        #define player_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define player_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define player_DM_RES_UP          PIN_DM_RES_UP
        #define player_DM_RES_DWN         PIN_DM_RES_DWN
        #define player_DM_OD_LO           PIN_DM_OD_LO
        #define player_DM_OD_HI           PIN_DM_OD_HI
        #define player_DM_STRONG          PIN_DM_STRONG
        #define player_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define player_MASK               player__MASK
#define player_SHIFT              player__SHIFT
#define player_WIDTH              1u

/* Interrupt constants */
#if defined(player__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in player_SetInterruptMode() function.
     *  @{
     */
        #define player_INTR_NONE      (uint16)(0x0000u)
        #define player_INTR_RISING    (uint16)(0x0001u)
        #define player_INTR_FALLING   (uint16)(0x0002u)
        #define player_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define player_INTR_MASK      (0x01u) 
#endif /* (player__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define player_PS                     (* (reg8 *) player__PS)
/* Data Register */
#define player_DR                     (* (reg8 *) player__DR)
/* Port Number */
#define player_PRT_NUM                (* (reg8 *) player__PRT) 
/* Connect to Analog Globals */                                                  
#define player_AG                     (* (reg8 *) player__AG)                       
/* Analog MUX bux enable */
#define player_AMUX                   (* (reg8 *) player__AMUX) 
/* Bidirectional Enable */                                                        
#define player_BIE                    (* (reg8 *) player__BIE)
/* Bit-mask for Aliased Register Access */
#define player_BIT_MASK               (* (reg8 *) player__BIT_MASK)
/* Bypass Enable */
#define player_BYP                    (* (reg8 *) player__BYP)
/* Port wide control signals */                                                   
#define player_CTL                    (* (reg8 *) player__CTL)
/* Drive Modes */
#define player_DM0                    (* (reg8 *) player__DM0) 
#define player_DM1                    (* (reg8 *) player__DM1)
#define player_DM2                    (* (reg8 *) player__DM2) 
/* Input Buffer Disable Override */
#define player_INP_DIS                (* (reg8 *) player__INP_DIS)
/* LCD Common or Segment Drive */
#define player_LCD_COM_SEG            (* (reg8 *) player__LCD_COM_SEG)
/* Enable Segment LCD */
#define player_LCD_EN                 (* (reg8 *) player__LCD_EN)
/* Slew Rate Control */
#define player_SLW                    (* (reg8 *) player__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define player_PRTDSI__CAPS_SEL       (* (reg8 *) player__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define player_PRTDSI__DBL_SYNC_IN    (* (reg8 *) player__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define player_PRTDSI__OE_SEL0        (* (reg8 *) player__PRTDSI__OE_SEL0) 
#define player_PRTDSI__OE_SEL1        (* (reg8 *) player__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define player_PRTDSI__OUT_SEL0       (* (reg8 *) player__PRTDSI__OUT_SEL0) 
#define player_PRTDSI__OUT_SEL1       (* (reg8 *) player__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define player_PRTDSI__SYNC_OUT       (* (reg8 *) player__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(player__SIO_CFG)
    #define player_SIO_HYST_EN        (* (reg8 *) player__SIO_HYST_EN)
    #define player_SIO_REG_HIFREQ     (* (reg8 *) player__SIO_REG_HIFREQ)
    #define player_SIO_CFG            (* (reg8 *) player__SIO_CFG)
    #define player_SIO_DIFF           (* (reg8 *) player__SIO_DIFF)
#endif /* (player__SIO_CFG) */

/* Interrupt Registers */
#if defined(player__INTSTAT)
    #define player_INTSTAT            (* (reg8 *) player__INTSTAT)
    #define player_SNAP               (* (reg8 *) player__SNAP)
    
	#define player_0_INTTYPE_REG 		(* (reg8 *) player__0__INTTYPE)
#endif /* (player__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_player_H */


/* [] END OF FILE */
