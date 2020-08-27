#include <cstdlib>

	// Ligar Bit
unsigned int ligarBit(unsigned int valor, unsigned int bit) {
	unsigned int resultado, mascara = 1 << bit;	// M�scara para ligar bit ('1' deslocado at� a posi��o desejada)
	resultado = valor | mascara;				// Operador OR bit-a-bit para ligar o bit desejado sem interferir nos outros
	return resultado;
}


	// Desligar Bit
unsigned int desligarBit(unsigned int valor, unsigned int bit) {
	unsigned int resultado, mascara = 1 << bit; // M�scara para desligar bit ('1' deslocado at� a posi��o desejada) Ex.: 00010000
	mascara = ~mascara;							// M�scara invertida Ex.: 11101111
	resultado = valor & mascara;				// Operador AND bit-a-bit para desligar o bit desejado sem interferir nos outros
	return resultado;
}


	// Testar Bit
bool testarBit(unsigned long long int valor, unsigned int bit) {
	bool resultado;
	unsigned long long int medio, mascara = 1ll << bit; // M�scara: '1' deslocado de 0 a 63 bits
	medio = valor & mascara;							// O bit desejado permanece inalterado, enquanto TODOS os outros s�o zerados
	medio = medio >> bit;								// O bit desejado passa a ocupar a posi��o 0
	resultado = medio;									// Convers�o dos �ltimos bits do long long para bool
	return resultado;
}


	// Codificar
unsigned long long int codificar(unsigned int valor) {
	unsigned int codificado = valor;
		// 6 valores aleat�rios entre 0 e 31
	unsigned int v1, v2, v3, v4, v5, v6;
	v1 = rand() % 32;
	v2 = rand() % 32;
	v3 = rand() % 32;
	v4 = rand() % 32;
	v5 = rand() % 32;
	v6 = rand() % 32;

		// Invertendo cada bit sorteado
	if (testarBit(codificado, v1)) {
		codificado = desligarBit(codificado, v1);
	}
	else {
		codificado = ligarBit(codificado, v1);
	}

	if (testarBit(codificado, v2)) {
		codificado = desligarBit(codificado, v2);
	}
	else {
		codificado = ligarBit(codificado, v2);
	}

	if (testarBit(codificado, v3)) {
		codificado = desligarBit(codificado, v3);
	}
	else {
		codificado = ligarBit(codificado, v3);
	}

	if (testarBit(codificado, v4)) {
		codificado = desligarBit(codificado, v4);
	}
	else {
		codificado = ligarBit(codificado, v4);
	}

	if (testarBit(codificado, v5)) {
		codificado = desligarBit(codificado, v5);
	}
	else {
		codificado = ligarBit(codificado, v5);
	}

	if (testarBit(codificado, v6)) {
		codificado = desligarBit(codificado, v6);
	}
	else {
		codificado = ligarBit(codificado, v6);
	}

	unsigned long long int resultado = codificado;	//'resultado' recebe [32 bits '0'][32 bits do valor codificado]
	resultado = (resultado << 5) + v1;				// [27 bits '0'][32 bits - codificado][5 bits de v1]
	resultado = (resultado << 5) + v2;				// [22 bits '0'][32 bits - codificado][5 bits de v1][5 bits de v2]
	resultado = (resultado << 5) + v3;				// [17 bits '0'][32 bits - codificado][5 bits de v1][5 bits de v2][5 bits de v3]
	resultado = (resultado << 5) + v4;				// [12 bits '0'][32 bits - codificado][5 bits de v1][5 bits de v2][5 bits de v3][5 bits de v4]
	resultado = (resultado << 5) + v5;				// [7 bits '0'][32 bits - codificado][5 bits de v1][5 bits de v2][5 bits de v3][5 bits de v4][5 bits de v5]
	resultado = (resultado << 5) + v6;				// [2 bits '0'][32 bits - codificado][5 bits de v1][5 bits de v2][5 bits de v3][5 bits de v4][5 bits de v5][5 bits de v6]
	resultado <<= 2;								// [32 bits - codificado][5 bits de v1][5 bits de v2][5 bits de v3][5 bits de v4][5 bits de v5][5 bits de v6][2 bits '0']
	return resultado;
}


	// Decodificar
unsigned int decodificar(unsigned long long int valor) {
	unsigned int codificado = valor >> 32;				// Manipula [32 bits][32 bits] - Elimina o 2� bloco e guarda o 1�
	unsigned int v1, v2, v3, v4, v5, v6, bits = valor;	// Manipula [32 bits][32 bits] - Elimina o 1� bloco e guarda o 2�
	
		// Manipula [5 bits][5 bits][5 bits][5 bits][5 bits][5 bits][2 bits] - Traz o bloco desejado para a 1� posi��o, eliminando os anteriores, e logo depois o leva para a �ltima posi��o, eliminando os posteriores
	v1 = bits >> 27;
	v2 = (bits << 5) >> 27;
	v3 = (bits << 10) >> 27;
	v4 = (bits << 15) >> 27;
	v5 = (bits << 20) >> 27;
	v6 = (bits << 25) >> 27;

		// 'resultado' recebe o valor original codificado
	unsigned int resultado = codificado;

		// 'resultado' � manipulado, sendo decodificado passo-a-passo
		// Invertendo o bit da posi��o v1
	if (testarBit(resultado, v1)) {
		resultado = desligarBit(resultado, v1);
	}
	else {
		resultado = ligarBit(resultado, v1);
	}
		// Invertendo o bit da posi��o v2
	if (testarBit(resultado, v2)) {
		resultado = desligarBit(resultado, v2);
	}
	else {
		resultado = ligarBit(resultado, v2);
	}
		// Invertendo o bit da posi��o v3
	if (testarBit(resultado, v3)) {
		resultado = desligarBit(resultado, v3);
	}
	else {
		resultado = ligarBit(resultado, v3);
	}
		// Invertendo o bit da posi��o v4
	if (testarBit(resultado, v4)) {
		resultado = desligarBit(resultado, v4);
	}
	else {
		resultado = ligarBit(resultado, v4);
	}
		// Invertendo o bit da posi��o v5
	if (testarBit(resultado, v5)) {
		resultado = desligarBit(resultado, v5);
	}
	else {
		resultado = ligarBit(resultado, v5);
	}
		// Invertendo o bit da posi��o v6
	if (testarBit(resultado, v6)) {
		resultado = desligarBit(resultado, v6);
	}
	else {
		resultado = ligarBit(resultado, v6);
	}

	return resultado;
}


// Fun��es extras - Orientadas a tarefas, visando a clareza do Principal.cpp

	// Valor Codificado:
	// Retorna apenas o resultado codificado, sem a identifica��o de bits alterados
unsigned int valorCodificado(unsigned long long int valor) {
	unsigned int codificado = valor >> 32;	// Manipula [32 bits][32 bits] - Elimina o 2� bloco e guarda o 1�
	return codificado;
}


	// Bit Alterado:
	// Retorna apenas o bit alterado na posi��o informada
unsigned int bitAlterado(unsigned long long int valor, unsigned int posicao) {
	unsigned int bits = valor;				// Manipula [32 bits][32 bits] - Elimina o 1� bloco e guarda o 2�
	bits = (bits << (5 * posicao)) >> 27;
	// Manipula [5 bits][5 bits][5 bits][5 bits][5 bits][5 bits][2 bits] - Traz o bloco desejado para a 1� posi��o, eliminando os anteriores, e logo depois o leva para a �ltima posi��o, eliminando os posteriores
	return bits;
}