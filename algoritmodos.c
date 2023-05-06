#include <stdio.h>
//Daniel Camacho,Carlos Caruci,Ilver Camacho Sección "D"

int main() 
{
	//Se procede a declarar las respectivas variables
    int num_cta, tipo_transac, cant_dep = 0, cant_ret = 0;
	
    float sald_ini, sald_act, monto_transac, monto_dep = 0, menor_sald, mayor_sald;

    // Se procede a pedir la información sobre la cuenta
	
    printf("Ingrese el numero de la cuenta--(Por favor introducir un numero positivo o 0)--:\t ");
	
    scanf("%d", &num_cta);
	
    printf("Por favor ingrese el saldo inicial de la cuenta:\t ");
	
    scanf("%f", &sald_ini);
	
    sald_act = sald_ini; // Indica que el saldo actual comienza siendo igual al saldo inicial
	
    menor_sald = sald_ini; // Indica que el menor saldo comienza siendo igual al saldo inicial
	
    mayor_sald = sald_ini; // Indica que el mayor saldo comienza siendo igual al saldo inicial

    // Se comienza a procesar cada una de las transacciones mediante un ciclo while
	
    while (1) { // Se procede a utilizar un bucle infinito que se interrumpe cuando se ingresa "0"
	
        printf("Ingrese el tipo de transaccion (1 para retiro | 2 para deposito) o presione 0 para salir: ");
		
        scanf("%d", &tipo_transac);
		
        if (tipo_transac == 0) { // Si se ingresa "0", se sale del bucle infinito
		
            break;
        }
        printf("Ingrese el monto de la transaccion:\t ");
		
        scanf("%f", &monto_transac);
		
        if ((tipo_transac == 1) && (sald_act < monto_transac)) { // Si se intenta retirar más dinero del que se tiene, se muestra un mensaje de error y se continúa con el bucle infinito
            printf("No se puede realizar el retiro. Saldo insuficiente.\n");
            continue;
        }
        if (tipo_transac == 1) { // Si se ingresa "1", se procesa un retiro
            cant_ret++; // Se incrementa la cantidad de retiros procesados
            sald_act -= monto_transac; // Se resta el monto del retiro al saldo actual
        } else if (tipo_transac == 2) { // Si se ingresa "2", se procesa un depósito
            cant_dep++; // Se incrementa la cantidad de depósitos realizados
            monto_dep += monto_transac; // Se suma el monto del depósito al monto total de depósitos
            sald_act += monto_transac; // Se suma el monto del depósito al saldo actual
        } else { // Si se ingresa un número diferente de "1" o "2", se muestra un mensaje de error
            printf("Tipo de transacción inválido.\n");
        }
        if (sald_act < menor_sald) { // Si el saldo actual es menor al menor saldo registrado hasta el momento, se actualiza el valor del menor saldo
            menor_sald = sald_act;
        }
        if (sald_act > mayor_sald) { // Si el saldo actual es mayor al mayor saldo registrado hasta el momento, se actualiza el valor del mayor saldo
            mayor_sald = sald_act;
        }
    }

    // ----Se proceden a Imprimir los resultados al usuario-------
	
    printf("\nNumero de cuenta: %d\n", num_cta);
    printf("Saldo actual: %.2f\n", sald_act);
    printf("Cantidad de depósitos realizados: %d\n", cant_dep);
    printf("Monto total de los depositos: %.2f\n", monto_dep);
    printf("Cantidad de retiros procesados: %d\n", cant_ret);
    printf("Menor saldo durante el mes: %.2f\n", menor_sald);
    printf("Mayor saldo durante el mes: %.2f\n", mayor_sald);

    return 0;
}