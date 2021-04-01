#include <stdint.h>
#include "stmbf407.h"

#define     __IO    volatile

#define PERIPH_BASE 0x40000000UL //Si on regarde dans le référence manual, on trouve que les registres commencent tous à partir de cette adresse. 
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL) //D'où son utilisation avec un "+" ensuite
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x0C00UL) //Où a-t-il trouvé l'adresse de "base" AHB1 
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE) 

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800UL)
#define RCC ((RCC_TypeDef *) RCC_BASE)

typedef struct
{
  __IO uint32_t MODER;    
  __IO uint32_t OTYPER;   
  __IO uint32_t OSPEEDR;  
  __IO uint32_t PUPDR;    
  __IO uint32_t IDR;      
  __IO uint32_t ODR;      
  __IO uint32_t BSRR;     
  __IO uint32_t LCKR;     
  __IO uint32_t AFR[2];   
} GPIO_TypeDef;

typedef struct
{
  __IO uint32_t CR;            
  __IO uint32_t PLLCFGR;       
  __IO uint32_t CFGR;          
  __IO uint32_t CIR;           
  __IO uint32_t AHB1RSTR;      
  __IO uint32_t AHB2RSTR;      
  __IO uint32_t AHB3RSTR;      
  uint32_t      RESERVED0;     
  __IO uint32_t APB1RSTR;      
  __IO uint32_t APB2RSTR;      
  uint32_t      RESERVED1[2];  
  __IO uint32_t AHB1ENR;       
  __IO uint32_t AHB2ENR;       
  __IO uint32_t AHB3ENR;       
  uint32_t      RESERVED2;     
  __IO uint32_t APB1ENR;       
  __IO uint32_t APB2ENR;       
  uint32_t      RESERVED3[2];  
  __IO uint32_t AHB1LPENR;     
  __IO uint32_t AHB2LPENR;     
  __IO uint32_t AHB3LPENR;     
  uint32_t      RESERVED4;     
  __IO uint32_t APB1LPENR;     
  __IO uint32_t APB2LPENR;     
  uint32_t      RESERVED5[2];  
  __IO uint32_t BDCR;          
  __IO uint32_t CSR;           
  uint32_t      RESERVED6[2];  
  __IO uint32_t SSCGR;         
  __IO uint32_t PLLI2SCFGR;    
} RCC_TypeDef;
 

int main()
{
    RCC->AHB1ENR |= 1<<3;
    GPIOD->MODER |= 0x55000000;

    GPIOD->ODR = 0x0000; 
    
    while(1){
        GPIOD->ODR |= 0xA000; 
        stmbf407_wait(5) ; 

        GPIOD->ODR = 0x0000; 
        stmbf407_wait(5) ; 

    }
  return 0;
}


