/** \file stm32f_irq.c
 * \brief
 */

void nmi_handler            (void) __attribute__ ((weak, alias("default_handler")));
void hard_fault_handler     (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler        (void) __attribute__ ((weak, alias("default_handler")));

void default_handler(void) {
  while(1);
}
