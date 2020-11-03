/** \file startup_stm32f.c
 * \brief startup for a the STM32F030 device.
 */
#include <core/stm32f.h>

// Exception / Interrupt Handler Function Prototype
typedef void(*pIrq)(void);

void reset_handler(void);

extern void __main(void);

extern void nmi_handler(void);
extern void hard_fault_handler(void);
extern void systick_handler(void);

extern void Interrupt0_Handler(void);
extern void Interrupt1_Handler(void);
extern void Interrupt2_Handler(void);
extern void Interrupt3_Handler(void);
extern void Interrupt4_Handler(void);
extern void Interrupt5_Handler(void);
extern void Interrupt6_Handler(void);
extern void Interrupt7_Handler(void);
extern void Interrupt8_Handler(void);
extern void Interrupt9_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/
__attribute__((section("vector_table")))
const pIrq vector_table[240] = {
  (pIrq) __INITIAL_SP,                      /*     Initial Stack Pointer */
  reset_handler,                            /*     Reset Handler */
  nmi_handler,                              /* -14 NMI Handler */
  hard_fault_handler,                        /* -13 Hard Fault Handler */
  0,                                        /* -12 MPU Fault Handler */
  0,                                        /* -11 Bus Fault Handler */
  0,                                        /* -10 Usage Fault Handler */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*  -5 SVCall Handler */
  0,                                        /*  -4 Debug Monitor Handler */
  0,                                        /*     Reserved */
  0,                                        /*  -2 PendSV Handler */
  systick_handler,                          /*  -1 SysTick Handler */

  /* Interrupts */
  Interrupt0_Handler,                       /*   0 Interrupt 0 */
  Interrupt1_Handler,                       /*   1 Interrupt 1 */
  Interrupt2_Handler,                       /*   2 Interrupt 2 */
  Interrupt3_Handler,                       /*   3 Interrupt 3 */
  Interrupt4_Handler,                       /*   4 Interrupt 4 */
  Interrupt5_Handler,                       /*   5 Interrupt 5 */
  Interrupt6_Handler,                       /*   6 Interrupt 6 */
  Interrupt7_Handler,                       /*   7 Interrupt 7 */
  Interrupt8_Handler,                       /*   8 Interrupt 8 */
  Interrupt9_Handler                        /*   9 Interrupt 9 */
};


/** \fn reset_handler
 * \brief Reset Handler called on controller reset.
 *
 * \return Void.
 */
void reset_handler(void) {
  __main();
}
