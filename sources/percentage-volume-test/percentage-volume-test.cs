// See https://aka.ms/new-console-template for more information

using System.Collections.Generic;



List<Operacao> operacoes = new()
{
	new Operacao { totalNegociado =  900, porcentagem = 0.1M },
	new Operacao { totalNegociado = 1500, porcentagem = 0.3M }
};



foreach (Operacao operacao in operacoes)
{
	decimal quantidade = operacao.quantidade();
	Console.Write("Total Negociado : $ {0:0.##}   porcentagem : {1:N1}%    >  ", operacao.totalNegociado, operacao.porcentagem * 100);
	Console.Write(quantidade);
	Console.WriteLine();
}


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






