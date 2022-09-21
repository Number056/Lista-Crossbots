#include "muito_simples_p2.h"

//°C = (°F - 32) / 1.8 
// site para a fórmula: https://calculife.com/pt/converter-celsius-para-fahrenheit-c-para-f-conversor-online/
float converte_temperatura(float fahrenheit){
    return (fahrenheit - 32) / 1.8;
}