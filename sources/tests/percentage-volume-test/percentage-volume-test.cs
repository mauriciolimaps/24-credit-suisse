// See https://aka.ms/new-console-template for more information

using System.Collections.Generic;



List<Operacao> operacoes = new()
{
	new Operacao { totalNegociado =       900.00m, porcentagem = 0.10M },
	new Operacao { totalNegociado =     1_500.00m, porcentagem = 0.30M },
    new Operacao { totalNegociado =    23_456.78m, porcentagem = 0.30M },
    new Operacao { totalNegociado = 1_200_000.00m, porcentagem = 0.15M }
};

Console.WriteLine("  +-------------------+-------------+----------------+");
Console.WriteLine("  |  Total Negociado  | porcentagem |   quantidade   |");
Console.WriteLine("  +-------------------+-------------+----------------+");

foreach (Operacao operacao in operacoes)
{
	Console.Write("  |  {0,15:N2}", operacao.totalNegociado);
    Console.Write("  |");
	Console.Write("  {0,9:P1}",     operacao.porcentagem);
    Console.Write("  |"); 
    Console.Write("  {0,12}",       operacao.quantidade().ToString("N3"));
    Console.Write("  |");
    Console.WriteLine();
}

Console.WriteLine("  +-------------------+-------------+----------------+");

public class Operacao
{
	private decimal mPorcentagem;
	public  decimal totalNegociado { get; set; }
	public decimal porcentagem {
		get { return mPorcentagem; }  
		set
		{ 
			if ((value < 0) || (value >= 1))
				throw new InvalidDataException("Porcentagem Inválida");

			mPorcentagem = value; 
		}
	}

	public Operacao() { this.mPorcentagem = 0; }

	public decimal quantidade()
	{
		if ((mPorcentagem < 0) || (mPorcentagem >= 1))
			throw new Exception("O parâmetro de porcentagem deve ser positivo e menor que 1");

		decimal quantity = totalNegociado * porcentagem / (1 - porcentagem);
		return quantity;
	}
};

