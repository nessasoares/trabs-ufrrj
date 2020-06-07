#!-*- coding: utf8 -*-

'''
 UFRRJ - Ciência da Computação
 Disciplina: Tópicos Especiais em Otimização
 Professora: Adria Lyra
 Alunas: Patrícia Castro e Vanessa Soares

 Executar aplicação somente com python3
 python3 grasp.py

'''

import time
import leituraArquivo as leituraArquivo
from random import randint

def construcaoInicial(terreno, radares):
        #solução inicial
        #1
        S = []  #localização das p facilidades

        K = radares[-1]["tipo"]
        p = 0;
        pop_total = []
        radares_qtd = 0
        terrenos_qtd = len(terreno)

        for k in range(0, K+1):
            pk = radares[k]["quantidade"]
            radares_qtd += pk
            #calcular a cobertura
            terreno_coberturas = calculoCobertura(terreno, radares[k]["alcance"])

            for t in range(0, len(terreno_coberturas)):
                terreno_coberturas[t]["tipoRadar"] = k+1
                pop_total.append(terreno_coberturas[t].copy())

        return escolhaAleatoria(pop_total, radares, terrenos_qtd), pop_total


def escolhaAleatoria(pop_total, radares, terrenos_qtd):
    escolhidos=[]
    pop_inicial = []
    indice = 0
    total_sorted = sorted(pop_total, key=lambda x: x["tipoRadar"]) #ordenar a pop total pelo tipo de radar
    radares_qtd = radares[indice]["quantidade"]
    K = radares[-1]["tipo"]
    contador_radar = 0 #conta quantos radares daquele tipo ja foram inseridos

    for k in range(0, K+1):
        while len(pop_inicial)<radares_qtd:
            posicao = randint(0, len(pop_total)-1) #numero aleatorio
            if posicao not in escolhidos:
                if pop_total[posicao]["tipoRadar"] == k+1:
                    pop_inicial.append(pop_total[posicao])
                    escolhidos.append(posicao)
            if len(pop_inicial) >= terrenos_qtd: #caso existam menos pontos que radares
                break #ele finaliza a execução
        if k+1 <= K:
            radares_qtd += radares[k+1]["quantidade"]

    return pop_inicial

def mostrarSolucao(list):
    for l in list:
        print(l)

def calculoCobertura(pontosInstalacao, alcanceRadar):
    peso = 0
    areaRadar = 2.0*3.14*float(alcanceRadar)
    for i in range(len(pontosInstalacao)):
        areaNaoCoberta = pontosInstalacao[i]["areaTerreno"] - areaRadar
        pontosInstalacao[i]["areaNaoCoberta"] = round(areaNaoCoberta, 3)

        #cálculo da diferença da "borda do radar" até a "borda do terreno"
        if areaNaoCoberta < 0:
            limite = areaNaoCoberta * (-1)
        else:
            limite = areaNaoCoberta
        pontosInstalacao[i]["area"] = areaRadar
        pontosInstalacao[i]["diferencaLimite"] = round(limite,3)
    return pontosInstalacao

def calculoDiferencaTotal(S):
        soma = 0
        for i in range(len(S)):
            soma += S[i]["diferencaLimite"]
        return soma

def calculoAreaFinal(S_linha):
    soma = 0
    for i in range(len(S_linha)):
        if S_linha[i]["areaNaoCoberta"] <= 0:
            soma += S_linha[i]["areaTerreno"]
    return soma

def quantidadeTotalDeRadares(radares):
    auxRadares = 0
    for i in range(0,len(radares)):
        auxRadares += radares[i]["quantidade"]
    print("Quantidade de radares ", auxRadares)
    return auxRadares

def buscaTabu(pop_inicial, pop_total, radares):
    #2
    s = sorted(pop_inicial, key=lambda x: x["diferencaLimite"])
    total_sorted = sorted(pop_total, key=lambda x: x["diferencaLimite"])
    s_estrela = s
    iter = 0
    melhor_iter = 0
    BT_max = 2 * quantidadeTotalDeRadares(radares) #quantidade total de não melhora para exibir o resultado
    tabu = []
    tamanho_tabu = 100
    i=0 #qual elemento vai pegar da população total
    tipoRadar = s[0]["tipoRadar"] #qual o tipo do radar

    while iter - melhor_iter < BT_max:
        iter+=1
        m = total_sorted[i].copy()
        if m["tipoRadar"] == tipoRadar:
            if m not in s:
                s_linha = s.copy()
                tipoRadar = s_linha[0]["tipoRadar"]
                s_linha.remove(s_linha[0])
                s_linha.append(m)
                if calculoDiferencaTotal(s) > calculoDiferencaTotal(s_linha) or m not in tabu:
                    tabu.append(m)
                    if len(tabu) >= tamanho_tabu:
                        tabu.remove(tabu[0])
                    s = s_linha
                if calculoDiferencaTotal(s) < calculoDiferencaTotal(s_estrela):
                    s_estrela = s;
                    melhor_iter = iter
            else:
                i+=1
        else:
            i+=1
    return s_estrela

#-------------------------------------------------------------------------------
terreno = leituraArquivo.recuperaPontosInstalacao()
radares = leituraArquivo.recuperaInformacoesRadar()
inicio = time.time()
pop_inicial, pop_total = construcaoInicial(terreno, radares)
s_estrela_aux = buscaTabu(pop_inicial, pop_total, radares)
print ("\n\n Solução encontrada:")
mostrarSolucao(sorted(s_estrela_aux, key=lambda x: x["tipoRadar"]))
fim = time.time()
tempo = fim - inicio
print("\n\nTempo de execução da busca tabu: ", round(tempo, 5))
print("Somatório final das áreas: ", round(calculoAreaFinal(s_estrela_aux), 3))
