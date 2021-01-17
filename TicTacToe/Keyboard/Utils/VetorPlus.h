#pragma once
#ifdef DEBUG
#include "stdio.h"
#endif // DEBUG

template <class Type> 
class VetorPlus
{
	private:

		// Quantidade de linhas
		int lines = 0;

		// Ponteiro para um vetor type
		Type* _array_               = nullptr;
		//Ainda não funciona
		//Type* last_array = nullptr;

		// Ponteiro para um vetor int quardando a quatidade de colunas que tem em cada linha 
		int* columns_each_rows      = nullptr;
		// Salva os valores de "int *columns_each_rows" para conseguir criar memoria alocada sem perder os valores
		// Substituindo a função realloc(void *ptr, size_t size)
		int* last_columns_each_rows = nullptr;

	public:
		int posArray(int line, int colum)
		{
			int column_media = 0;

			for (int i = 0; i < line; i++)
			{
				column_media += ((i < 0) ? 0 : columns_each_rows[i]);
			}

			//std::cout << "\n (" << line << ", " <<colum << ", " << ", "<<column_media << ", " << ")\n    ";
			return ((column_media) + colum);
		}
		VetorPlus() {};
		virtual ~VetorPlus();

		/* Cria uma linha do vetor, definindo a quantidades de colunas.
		 *
		 * Params.
		 *    int columns --> Quantidade de colunas
		 *
	     * OBS: cada linha pode ter uma quantidade de colunas diferentes.
		 */
		void createLine(int columns);
		
		// --- gets ---

		int getLines()
		{
			return lines;
		}

		int getColumnsEachRows(int line)
		{
			if ((line < lines))
			{
				return columns_each_rows[line];
			}
			else
			{
				return 0;
			}
		}

		Type& getArray() { return _array_; }

		Type& getPosArray(int line, int colum)
		{
			if ((line < lines) && (colum < columns_each_rows[line]))
			{
				return _array_[posArray(line, colum)];
			}
			else
			{
				return _array_[0];
			}
		}
};

template <class Type>
VetorPlus<Type>::~VetorPlus()
{
	#ifdef DEBUG
	printf("VetorPlus delete\n");
	#endif // DEBUG

	

	delete[]last_columns_each_rows;
	delete[]_array_;
}

template <class Type>
void VetorPlus<Type>::createLine(int columns)
{
	lines++;

	columns_each_rows = new int[lines];

	for (int i = 0; i < lines - 1; i++)
	{
		columns_each_rows[i] = last_columns_each_rows[i];
	}

	columns_each_rows[lines - 1] = columns;

	delete[]last_columns_each_rows;

	last_columns_each_rows = columns_each_rows;

	//--- fim criando columns_each_rows ---

	// --- inicio criando _array_ ---

	delete[]_array_;

	_array_ = new Type[posArray(lines - 1, columns)];

	//--- fim criando _array_ ---
}