	// Codificar
unsigned long long int codificar(unsigned int valor);
	
	// Decodificar
unsigned int decodificar(unsigned long long int valor);

	// Ligar Bit
unsigned int ligarBit(unsigned int valor, unsigned int	bit);

	// Desligar Bit
unsigned int desligarBit(unsigned int valor, unsigned int bit);

	// Testar Bit
bool testarBit(unsigned long long int valor, unsigned int bit);


// Funções extras - Orientadas a tarefas, visando a clareza do Principal.cpp

	// Valor Codificado:
	// Retorna apenas o resultado codificado, sem a identificação de bits alterados
unsigned int valorCodificado(unsigned long long int valor);

	// Bit Alterado:
	// Retorna apenas o bit alterado na posição informada
unsigned int bitAlterado(unsigned long long int valor, unsigned int posicao);
