/*******************************************************************************
* File Name: incoming.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_incoming_H)
#define CY_ISR_incoming_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void incoming_Start(void);
void incoming_StartEx(cyisraddress address);
void incoming_Stop(void);

CY_ISR_PROTO(incoming_Interrupt);

void incoming_SetVector(cyisraddress address);
cyisraddress incoming_GetVector(void);

void incoming_SetPriority(uint8 priority);
uint8 incoming_GetPriority(void);

void incoming_Enable(void);
uint8 incoming_GetState(void);
void incoming_Disable(void);

void incoming_SetPending(void);
void incoming_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the incoming ISR. */
#define incoming_INTC_VECTOR            ((reg32 *) incoming__INTC_VECT)

/* Address of the incoming ISR priority. */
#define incoming_INTC_PRIOR             ((reg8 *) incoming__INTC_PRIOR_REG)

/* Priority of the incoming interrupt. */
#define incoming_INTC_PRIOR_NUMBER      incoming__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable incoming interrupt. */
#define incoming_INTC_SET_EN            ((reg32 *) incoming__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the incoming interrupt. */
#define incoming_INTC_CLR_EN            ((reg32 *) incoming__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the incoming interrupt state to pending. */
#define incoming_INTC_SET_PD            ((reg32 *) incoming__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the incoming interrupt. */
#define incoming_INTC_CLR_PD            ((reg32 *) incoming__INTC_CLR_PD_REG)


#endif /* CY_ISR_incoming_H */


/* [] END OF FILE */
