/** \file startup_stm32f.c
 * \brief startup for a the STM32F030 device.
 */
#include <core/device.h>

// Exception / Interrupt Handler Function Prototype
typedef void(*pIrq)(void);

void reset_handler(void);

extern void __main(void);

extern void nmi_handler(void);
extern void hard_fault_handler(void);
extern void systick_handler(void);

// Exception / Interrupt Vector table
__attribute__((section("vector_table")))
const pIrq vector_table[41] = {
  /******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  (pIrq) __INITIAL_SP,                      /*     Initial Stack Pointer                                       */
  reset_handler,                            /*     Reset Handler                                               */
  nmi_handler,                              /* -14 NMI Handler                                                 */
  hard_fault_handler,                       /* -13 Hard Fault Handler                                          */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*  -5 SVCall Handler                                              */
  0,                                        /*     Reserved                                                    */
  0,                                        /*     Reserved                                                    */
  0,                                        /*  -2 PendSV Handler                                              */
  systick_handler,                          /*  -1 SysTick Handler                                             */

  /******  STM32F030x8 specific Interrupt Numbers **************************************************************/
  0,                                        /*   0 Window WatchDog Interrupt                                   */
  0,                                        /*   2 RTC Interrupt through EXTI Lines 17, 19 and 20              */
  0,                                        /*   3 FLASH global Interrupt                                      */
  0,                                        /*   4 RCC global Interrupt                                        */
  0,                                        /*   5 EXTI Line 0 and 1 Interrupts                                */
  0,                                        /*   6 EXTI Line 2 and 3 Interrupts                                */
  0,                                        /*   7 EXTI Line 4 to 15 Interrupts                                */
  0,                                        /*   9 DMA1 Channel 1 Interrupt                                    */
  0,                                        /*   10 DMA1 Channel 2 and Channel 3 Interrupts                    */
  0,                                        /*   11 DMA1 Channel 4 and Channel 5 Interrupts                    */
  0,                                        /*   12 ADC1 global Interrupt                                      */
  0,                                        /*   13 TIM1 Break, Update, Trigger and Commutation Interrupts     */
  0,                                        /*   14 TIM1 Capture Compare Interrupt                             */
  0,                                        /*   16 TIM3 global Interrupt                                      */
  0,                                        /*   17 TIM6 global Interrupt                                      */
  0,                                        /*   19 TIM14 global Interrupt                                     */
  0,                                        /*   20 TIM15 global Interrupt                                     */
  0,                                        /*   21 TIM16 global Interrupt                                     */
  0,                                        /*   22 TIM17 global Interrupt                                     */
  0,                                        /*   23 I2C1 Event Interrupt                                       */
  0,                                        /*   24 I2C2 Event Interrupt                                       */
  0,                                        /*   25 SPI1 global Interrupt                                      */
  0,                                        /*   26 SPI2 global Interrupt                                      */
  0,                                        /*   27 USART1 global Interrupt                                    */
  0                                         /*   28 USART2 global Interrupt                                    */
};

/** \fn reset_handler
 * \brief Reset Handler called on controller reset.
 *
 * \return Void.
 */
void reset_handler(void) {
  __main();
}
