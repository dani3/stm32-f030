/** \file stm32f_irq.c
 * \brief
 */

void nmi_handler            (void) __attribute__ ((weak, alias("default_handler")));
void hard_fault_handler     (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler        (void) __attribute__ ((weak, alias("default_handler")));

void Interrupt0_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt1_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt2_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt3_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt4_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt5_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt6_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt7_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt8_Handler     (void) __attribute__ ((weak, alias("default_handler")));
void Interrupt9_Handler     (void) __attribute__ ((weak, alias("default_handler")));

void default_handler(void) {
  while(1);
}
