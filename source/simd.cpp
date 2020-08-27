	// Armazena: recebe 4 valores de 8 bits e os junta em uma �nica vari�vel de 32 bits
unsigned int armazena(unsigned char valor1, unsigned char valor2, unsigned char valor3, unsigned char valor4) {
	unsigned int resultado;
	resultado = (valor1 << 24) + (valor2 << 16) + (valor3 << 8) + valor4;
	return resultado;
}


	// Primeiro: recebe um valor de 32 bits e retorna o 1� bloco de 8 bits
unsigned char primeiro(unsigned int valor) {
	unsigned char resultado; // Vari�vel de apenas 8 bits
	resultado = valor >> 24; // "Empurra" o 1� bloco para a �ltima posi��o, descartando o 2�, 3� e 4�. Logo depois, o atribui � vari�vel 'resultado' de 8 bits, que ignora os 24 bits equivalentes �s 3 primeiras posi��es (agora zerados).
	return resultado;
}


	// Segundo: recebe um valor de 32 bits e retorna o 2� bloco de 8 bits
unsigned char segundo(unsigned int valor) {
	unsigned char resultado; // 8 bits
	resultado = (valor << 8) >> 24; // Transforma o 2� bloco no novo 1�, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos s�o descartados, por seguran�a.
	return resultado;
}


	// Terceiro: recebe um valor de 32 bits e retorna o 3� bloco de 8 bits
unsigned char terceiro(unsigned int valor) {
	unsigned char resultado;
	resultado = (valor << 16) >> 24; // Transforma o 3� bloco no novo 1�, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos s�o descartados, por seguran�a.
	return resultado;
}


	// Quarto: recebe um valor de 32 bits e retorna o 4� bloco de 8 bits
unsigned char quarto(unsigned int valor) {
	unsigned char resultado;
	resultado = (valor << 24) >> 24; // Transforma o 4� bloco no novo 1�, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos s�o descartados, por seguran�a.
	return resultado;
}


	// Soma: separa os blocos, os soma individualmente, e junta seus resultados.
unsigned int soma(unsigned int parcela1, unsigned int parcela2) {
	unsigned char soma1, soma2, soma3, soma4;			// 4 vari�veis de 8 bits cada
	soma1 = primeiro(parcela1) + primeiro(parcela2);	// Cada vari�vel recebe a soma dos n�s blocos de ambas as parcelas
	soma2 = segundo(parcela1) + segundo(parcela2);
	soma3 = terceiro(parcela1) + terceiro(parcela2);
	soma4 = quarto(parcela1) + quarto(parcela2);
	
	unsigned int soma = armazena(soma1, soma2, soma3, soma4);	// As 4 vari�veis s�o armazenadas, na ordem, em uma vari�vel de 32 bits
	return soma;
}


	// Mult: separa os blocos, os multiplica individualmente, e junta seus resultados.
unsigned int mult(unsigned int fator1, unsigned int fator2) {
	unsigned char mult1, mult2, mult3, mult4;			// 4 vari�veis de 8 bits cada
	mult1 = primeiro(fator1) * primeiro(fator2);		// Cada vari�vel recebe a soma dos n�s blocos de ambos os fatores
	mult2 = segundo(fator1) * segundo(fator2);
	mult3 = terceiro(fator1) * terceiro(fator2);
	mult4 = quarto(fator1) * quarto(fator2);

	unsigned int mult = armazena(mult1, mult2, mult3, mult4);	// As 4 vari�veis s�o armazenadas, na ordem, em uma vari�vel de 32 bits
	return mult;
}