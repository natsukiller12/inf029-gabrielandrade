# include  <stdio.h>
# include  " estruturas.h "
# include " pessoas.h "
# include " disciplinas.h "
int  main ()
{
    escola escola;
    int Controle = 0 ;
    comandopessoa int = 0 ;
    comandodisc int = 0 ;
    int qtdPessoas = 0 ;
    int qtdAlunos = 0 ;
    int qtdProfessores = 0 ;
    int qtdDisciplinas = 0 ;
    int resultado = 0 ;
    Faz
    {
        printf ( " \ n Cadastro Escolar ------------------ \ n 1 - Sistema de Pessoas. \ n 2 - Sistema de Disciplinas. \ n 3 - Sair do Sistema. \ n " );
        scanf ( " % i " , & controle);
        interruptor (controle)
        {
        caso  1 :
            Faz
            {
                printf ( " \ n Sistema de Pessoas -------------- \ n 1 - Cadastrar \ n 2 - Removedor \ n 3 - Exibir todos os dados \ n 4 - Exibir dados de uma pessoa \ n 5 - Alterar dados de uma pessoa \ n 6 - Voltar ao menu principal \ n " );
                scanf ( " % i " , & comandopessoa);
                switch (comandopessoa)
                {
                caso  1 :
                    cadastrar (escola. pessoas , & qtdPessoas, & qtdAlunos, & qtdProfessores);
                    pausa ;
                caso  2 :
                    removerpessoa (escola. pessoas , & qtdPessoas, & qtdDisciplinas, & qtdProfessores, & qtdAlunos, escola. disciplinas );
                    pausa ;
                caso  3 :
                    exibirdados (escola. pessoas , & qtdPessoas);
                    pausa ;
                caso  4 :
                    exibe_pessoax (escola. pessoas , & qtdPessoas);
                    pausa ;
                caso  5 :
                    alterarDados (escola. pessoas , & qtdPessoas);
                    pausa ;

                caso  6 :
                    printf ( " \ n Voltando ao menu. \ n " );
                    pausa ;

                padrão :
                    printf ( " \ n Comando Invalido. \ n " );
                    pausa ;

                }
            } enquanto (comandopessoa! = 6 );

            pausa ;

        caso  2 :
            Faz
            {
                printf ( " \ n Sistema de Disciplinas ------------- \ n 1 - Cadastrar disciplina \ n 2 - Alterar professor de uma disciplina \ n 3 - Adicionar um aluno a uma disciplina \ n 4 - Remover aluno de uma disciplina \ n 5 - Exibir dados de uma disciplina \ n 6 - Voltar ao menu principal \ n " );
                scanf ( " % i " , & comandodisc);
                interruptor (comandodisc)
                {
                caso  1 :
                    resultado = cadastraDisciplina (escola. pessoas , escola. disciplinas , qtdDisciplinas, qtdPessoas);
                    if (resultado == 1 )
                    {
                        qtdDisciplinas ++;
                    }
                    pausa ;

                caso  2 :
                    alteraDisciplina (escola. pessoas , escola. disciplinas );
                    pausa ;

                caso  3 :
                    adicionaAluno (escola. disciplinas , escola. pessoas , qtdPessoas, qtdAlunos);
                    pausa ;

                caso  4 :
                    removeAluno (escola. disciplinas , escola. pessoas , qtdAlunos);
                    pausa ;

                caso  5 :
                    exibeDisciplina (escola. disciplinas , qtdDisciplinas);
                    pausa ;

                caso  6 :
                    printf ( " \ n Voltando ao menu. \ n " );
                    pausa ;

                padrão :
                    printf ( " \ n Comando Invalido. \ n " );
                    pausa ;
                }
            } enquanto (comandodisc! = 6 );
            pausa ;

        caso  3 :
            printf ( " \ n Saindo do Sistema. \ n " );
            return  0 ;
            pausa ;

        padrão :
            printf ( " \ n Opcao Invalida. \ n " );
            pausa ;
        }
    } enquanto (controle! = 3 );

    return  0 ;
}
