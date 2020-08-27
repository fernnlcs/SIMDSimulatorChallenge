#include <iostream>
#include "simd.h"
#include "cripto.h"
using namespace std;

int main() {
		// Definindo os padrões de acentuação
	system("chcp 1252 > nul");

		// Definindo padrão de preenchimento como '0'
	cout.fill('0');

		// Variáveis a1, a2, a3 e a4 se referem ao 1º operando
		// Variáveis b1, b2, b3 e b4 se referem ao 2º operando
	unsigned int a1, a2, a3, a4, b1, b2, b3, b4;
		// Variável 'extra' utilizada para manipular a entrada, ignorando os caracteres não-numéricos
	char extra;

		// Entrada dos dados no formato [001,002,003,004]
	cin >> extra >> a1 >> extra >> a2 >> extra >> a3 >> extra >> a4 >> extra;
	cin >> extra >> b1 >> extra >> b2 >> extra >> b3 >> extra >> b4 >> extra;

		// Concatenando e armazenando os valores dados em variáveis de 32 bits
	unsigned int valor1 = armazena(a1, a2, a3, a4), valor2 = armazena(b1, b2, b3, b4);
	
	cout << endl;

		// Exibindo os operandos (concatenados) na base 10
	cout << "Operandos em 32 bits = " << valor1 << endl;
	cout << "Operandos em 32 bits = " << valor2 << endl;

	cout << endl;

		// Gerando os resultados (soma e multiplicação)
	unsigned int somado = soma(valor1, valor2);
	unsigned int multiplicado = mult(valor1, valor2);

		// Exibindo os resultados (concatenados) na base 10
	cout << "Soma em 32 bits = " << somado << endl;
	cout << "Mult em 32 bits = " << multiplicado << endl;

	cout << endl;

		// Exibindo as Somas no formato "[001,002,003,004] = Somas"
	cout << "[";
	cout.width(3);										// Definindo a largura (em dígitos) do próximo cout como 3
	cout << (unsigned int)primeiro(somado) << ",";		// Convertendo o bloco correspondente (char) para números entre 0 e 255 (usigned int)
	cout.width(3);											// Repete tudo para os 4 blocos
	cout << (unsigned int)segundo(somado) << ",";
	cout.width(3);
	cout << (unsigned int)terceiro(somado) << ",";
	cout.width(3);
	cout<<(unsigned int)quarto(somado) << "]";
	cout << " = Somas" << endl;

		// Exibindo as Multiplicações no formato "[001,002,003,004] = Multiplicações"
	cout << "[";
	cout.width(3);											// Análogo à Soma (preenchimento de zeros)
	cout << (unsigned int)primeiro(multiplicado) << ",";	// Análogo à Soma (conversão e exibição)
	cout.width(3);												// Análogo à Soma (repetição)
	cout << (unsigned int)segundo(multiplicado) << ",";
	cout.width(3);
	cout << (unsigned int)terceiro(multiplicado) << ",";
	cout.width(3);
	cout << (unsigned int)quarto(multiplicado) << "]";
	cout << " = Multiplicações" << endl;

	cout << endl;

		// Codificando resultados
	unsigned long long int somaCodif = codificar(somado), multCodif = codificar(multiplicado);

		// Exibindo os resultados codificados na base 10
	cout << "Soma Cripto 64 bits = " << somaCodif << endl;
	cout << "Mult Cripto 64 bits = " << multCodif << endl;

	cout << endl;

		// Exibindo Soma codificada, Bits alterados, e Soma decodificada
	cout << "Valor Codificado = " << valorCodificado(somaCodif) << " ";
	cout << "(" << bitAlterado(somaCodif, 5) << " " << bitAlterado(somaCodif, 4) << " " << bitAlterado(somaCodif, 3) << " " << bitAlterado(somaCodif, 2) << " " << bitAlterado(somaCodif, 1) << " " << bitAlterado(somaCodif, 0) << ")";
	cout << endl;
	cout << "Soma Decodificada = " << decodificar(somaCodif) << endl;

	cout << endl;

		// Exibindo Multiplicação codificada, Bits alterados, e Multiplicação decodificada
	cout << "Valor Codificado = " << valorCodificado(multCodif) << " ";
	cout << "(" << bitAlterado(multCodif, 5) << " " << bitAlterado(multCodif, 4) << " " << bitAlterado(multCodif, 3) << " " << bitAlterado(multCodif, 2) << " " << bitAlterado(multCodif, 1) << " " << bitAlterado(multCodif, 0) << ")";
	cout << endl;
	cout << "Mult Decodificada = " << decodificar(multCodif) << endl;

		// Retorno da função main()
	return 0;
}