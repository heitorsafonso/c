int main()
{
    FILE *arquivo;

    arquivo = fopen("texto.txt","w");

    if (arquivo==NULL)
    {
        printf("\nProblema ao abrir o arquivo\n\n");
        return 0;
    }
    fprintf(arquivo,"Fernando Marco Perez Campos\nRibeirao Preto");

    fclose(arquivo);
    
    return 0;
}
