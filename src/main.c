#include "stm32f4xx.h"


void setupCpu(void) {

	// Reset config and disable external clock sources
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_OFF);
	RCC_LSEConfig(RCC_LSE_OFF);

	// Enable internal clock sources and wait until ready
	RCC_HSICmd(ENABLE);
	RCC_LSICmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_HSIRDY)) { /* wait until ready */ }
	while (!RCC_GetFlagStatus(RCC_FLAG_LSIRDY)) { /* wait until ready */ }

	// Configure RTC Clock to use LSI
	//default RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

	// Configure PLL to use HSI and wait until ready
	RCC_PLLCmd(DISABLE);
	RCC_PLLConfig(RCC_PLLSource_HSI, 16, 336, 2, 4); // SYSCLK = 168MHz
	RCC_PLLCmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_PLLRDY)) { /* wait until ready */ }

	// Configure system clocks to use PLL clock source
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	RCC_HCLKConfig(RCC_SYSCLK_Div1); // HCLK = 168MHz
	RCC_PCLK1Config(RCC_HCLK_Div4); // PCLK1 = 42MHz
	RCC_PCLK2Config(RCC_HCLK_Div2); // PCLK2 = 84MHz
	//default SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK); // Cortex System Timer = 168MHz

}


void setupDisplay(void) {

}

void setupGpio(void) {

	// Configure GPIO PB5
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


}
			

int main(void) {

	// Initialize Hardware
	setupCpu();
	setupDisplay();
	setupGpio();

}
