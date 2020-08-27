	// Armazena: recebe 4 valores de 8 bits e os junta em uma única variável de 32 bits
unsigned int armazena(unsigned char valor1, unsigned char valor2, unsigned char valor3, unsigned char valor4) {
	unsigned int resultado;
	resultado = (valor1 << 24) + (valor2 << 16) + (valor3 << 8) + valor4;
	return resultado;
}


	// Primeiro: recebe um valor de 32 bits e retorna o 1º bloco de 8 bits
unsigned char primeiro(unsigned int valor) {
	unsigned char resultado; // Variável de apenas 8 bits
	resultado = valor >> 24; // "Empurra" o 1º bloco para a última posição, descartando o 2º, 3º e 4º. Logo depois, o atribui à variável 'resultado' de 8 bits, que ignora os 24 bits equivalentes às 3 primeiras posições (agora zerados).
	return resultado;
}


	// Segundo: recebe um valor de 32 bits e retorna o 2º bloco de 8 bits
unsigned char segundo(unsigned int valor) {
	unsigned char resultado; // 8 bits
	resultado = (valor << 8) >> 24; // Transforma o 2º bloco no novo 1º, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos são descartados, por segurança.
	return resultado;
}


	// Terceiro: recebe um valor de 32 bits e retorna o 3º bloco de 8 bits
unsigned char terceiro(unsigned int valor) {
	unsigned char resultado;
	resultado = (valor << 16) >> 24; // Transforma o 3º bloco no novo 1º, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos são descartados, por segurança.
	return resultado;
}


	// Quarto: recebe um valor de 32 bits e retorna o 4º bloco de 8 bits
unsigned char quarto(unsigned int valor) {
	unsigned char resultado;
	resultado = (valor << 24) >> 24; // Transforma o 4º bloco no novo 1º, e faz o mesmo procedimento que em primeiro(). Dessa forma, todos os outros blocos são descartados, por segurança.
	return resultado;
}


	// Soma: separa os blocos, os soma individualmente, e junta seus resultados.
unsigned int soma(unsigned int parcela1, unsigned int parcela2) {
	unsigned char soma1, soma2, soma3, soma4;			// 4 variáveis de 8 bits cada
	soma1 = primeiro(parcela1) + primeiro(parcela2);	// Cada variável recebe a soma dos nºs blocos de ambas as parcelas
	soma2 = segundo(parcela1) + segundo(parcela2);
	soma3 = terceiro(parcela1) + terceiro(parcela2);
	soma4 = quarto(parcela1) + quarto(parcela2);
	
	unsigned int soma = armazena(soma1, soma2, soma3, soma4);	// As 4 variáveis são armazenadas, na ordem, em uma variável de 32 bits
	return soma;
}


	// Mult: separa os blocos, os multiplica individualmente, e junta seus resultados.
unsigned int mult(unsigned int fator1, unsigned int fator2) {
	unsigned char mult1, mult2, mult3, mult4;			// 4 variáveis de 8 bits cada
	mult1 = primeiro(fator1) * primeiro(fator2);		// Cada variável recebe a soma dos nºs blocos de ambos os fatores
	mult2 = segundo(fator1) * segundo(fator2);
	mult3 = terceiro(fator1) * terceiro(fator2);
	mult4 = quarto(fator1) * quarto(fator2);

	unsigned int mult = armazena(mult1, mult2, mult3, mult4);	// As 4 variáveis são armazenadas, na ordem, em uma variável de 32 bits
	return mult;
}