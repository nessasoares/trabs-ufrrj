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
import operator

def mostrarSolucao(list):
    for l in list:
        print(l)

def diferencaLimiteTotal(S_linha):
    soma = 0
    for i in range(len(S_linha)):
        soma += S_linha[i]["diferencaLimite"]
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
        pontosInstalacao[i]["diferencaLimite"] = round(limite,3)
    return pontosInstalacao

def construcaoInicialDoRadar(radares_list, terreno):
    #solução inicial

    S_2=[]
    C = 0
    it = 0

    #1
    S = []  #localização das p facilidades
    LRC = []
    L = []
    aux = 0
    K = radares_list[-1]["tipo"] #qts tipos de tadar
    p = 0;
    for k in range(0, K+1):
        #2
        pk = radares_list[k]["quantidade"] #qtd de radar por tipo
        aux += pk

        #3
        l_aux = []
        lrc_aux = []

        #calcular a cobertura
        terreno_coberturas = calculoCobertura(terreno, radares_list[k]["alcance"])
        pontos_sorted = sorted(terreno_coberturas, key=lambda x: x["diferencaLimite"]) #ordenação de acordo com a cobertura gerada

        for t in range(0, len(pontos_sorted)):
            pontos_sorted[t]["tipoRadar"] = k+1 #atribuir os tipos de radar

        L.extend(pontos_sorted) 
        l_aux = pontos_sorted

        #4
        escolhidos = []
        while len(lrc_aux)< pk:
            posicao = randint(0, len(pontos_sorted)-1)
            if posicao not in escolhidos: #verificar se essa posição não foi escolhida antes
                lrc_aux.append(l_aux[posicao])
                escolhidos.append(posicao)

        #5
        i = 0
        while len(S) < aux :
            #ordenar lrc_aux pra poder pegar a maior cobertura
            lrc_aux_sorted = sorted(lrc_aux, key=lambda x: x["diferencaLimite"])
            lrc_aux = lrc_aux_sorted

            r_max = lrc_aux[0].copy()

            r_max_old = r_max
            S.append(r_max)

            if r_max_old in lrc_aux:
                lrc_aux.remove(r_max_old)

            if r_max_old in l_aux:
                l_aux.remove(r_max_old)
            status = True
            while status:
                copia = l_aux[i].copy()
                if copia not in lrc_aux:
                    lrc_aux.append(copia)
                    LRC.extend(lrc_aux)
                    status = False
                i+= 1

            #verificação caso tenham mais radares que pontos de instalação ;)
            if len(S) >= len(terreno):
                break

    return S, LRC, L, aux

def buscaTabu(S, LRC, L, tabu, qtd_radares, qtd_terrenos):
      aux = None
      max = 100000 #teve que ser um numero assim por causa dos numeros negativos que aparecem lá na conta
      S = sorted(S, key=lambda x: x["diferencaLimite"]) #ordenar o S
      maior_area = S[0].copy() #descobrir a maior área de S

      tipo = maior_area["tipoRadar"] #pegar o tipo do radar do terreno que tem a maior area coberta
      if len(tabu) == 100: #tamanho para a tabu
          tabu.remove(tabu[0])
      tabu.append(maior_area)

      s_copia = S[0].copy()

      S.remove(s_copia) #remove a maior area de S
      if s_copia in LRC:
        LRC.remove(s_copia)

      #11
      for i in range(len(LRC)):
          #procura o melhor elemento que tenha o mesmo tipo de radar do que foi excluído
          if LRC[i]["tipoRadar"] == tipo and LRC[i]["diferencaLimite"] < max :
              aux = LRC[i].copy()
              max = LRC[i]["diferencaLimite"]


      S.append(aux)

      #12
      L_sorted = sorted(L, key=lambda x: x["diferencaLimite"])
      p = 0
      status = True
      while status:
          nova_posicao = L_sorted[p].copy()
          if nova_posicao not in LRC:
              if nova_posicao not in S:
                  if aspiracaoDefault(S, L_sorted[p]) or nova_posicao not in tabu:
                      LRC.append(nova_posicao)
                      status = False
          p+=1
          if p>=qtd_radares or p>=qtd_terrenos:
              status = False
      return S, tabu

def aspiracaoDefault(S, L_choose):
    S_maior = S[0]["diferencaLimite"]
    if S_maior < L_choose["diferencaLimite"]: 
        return False
    else:
        return True


def atualizaSolucao(S, it, C, S_linha,it_sem_melhora):
    cobertura_S = sum(S_aux["diferencaLimite"] for S_aux in S)
    if len(S_linha) is 0:

        S_linha = S
        C = cobertura_S
        it = 1

    else:
      if cobertura_S < C:
        del S_linha[0]
        S_linha = S
        C = cobertura_S
        it_sem_melhora = 0
      else:
        it_sem_melhora += 1

      it +=1

    return it, S_linha, C,it_sem_melhora


#-----------------------------------------------------------

it = 0
it_max = 100
it_max_igual = 100
it_sem_melhora = 0
C = 1000000
label = True
terreno = leituraArquivo.recuperaPontosInstalacao()
print("Quantidade de pontos de instalação disponíveis: ", len(terreno))
radares = leituraArquivo.recuperaInformacoesRadar()
it_max_sem_melhora = 2 * quantidadeTotalDeRadares(radares) #quantidade total de não melhora para exibir o resultado
tabu = []
S_linha = []
inicio = time.time()
while it < it_max_sem_melhora:
    S, LRC, L, qtd_radares = construcaoInicialDoRadar(radares, terreno)
    S_aux, tabu = buscaTabu(S, LRC, L, tabu, qtd_radares, len(terreno))
    it, S_linha, C,it_sem_melhora = atualizaSolucao(S_aux, it, C, S_linha,it_sem_melhora)
    if it == it_max:
      print ("\n\n it == it_max")
      break
print("\n\n Solução encontrada: ")
mostrarSolucao(sorted(S_linha, key=lambda x: x["linha"]))
fim = time.time()
tempo = fim - inicio
print("Tempo de execução do grasp: ", round(tempo, 5))
diferenca_limite = calculoAreaFinal(S_linha)
print("Total área final: ", diferenca_limite)
