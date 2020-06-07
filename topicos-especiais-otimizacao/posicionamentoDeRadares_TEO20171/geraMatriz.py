#!-*- coding: utf8 -*-

'''
 UFRRJ - Ciência da Computação
 Disciplina: Tópicos Especiais em Otimização
 Professora: Adria Lyra
 Alunas: Patrícia Castro e Vanessa Soares

 Executar aplicação somente com python3
 python3 geraMatriz.py 'numero de linhas' 'numero de colunas'

'''

import random
import leituraArquivo as leituraArquivo
from decimal import *
import sys


def inicializaMatriz(param):

	l = int(param[0])
	c = int(param[1])

	mat = [[random.randint(0,1) for j in range(c)] for i in range(l)]

	string = param[0] + ' x ' + param[1]
	print ("Criando matriz ", string)

	return mat

def inserirCobertura(param):

	mat = inicializaMatriz(param)
	radares = leituraArquivo.recuperaInformacoesRadar()
	sorted_radares = sorted(radares, key=lambda x: x["alcance"])

	menor_alcance = sorted_radares[0]["alcance"]
	maior_alcance = sorted_radares[-1]["alcance"]
	peq = menor_alcance * 2.0 * 3.14
	grd = maior_alcance * 2.0 * 3.14

	for i in range(0,len(mat)):
		for j in range(0,len(mat)):
			if mat[i][j] == 1:
				mat[i][j] = round(random.uniform(peq,grd), 3) #.uniform(a,b) para flutuante

	return mat

def manipularArquivo(param):

	mat = inserirCobertura(param)
	strMat = "\n".join(str(mat[i]).replace("[","").replace("]","").replace(",","") for i in range(0,len(mat)))
	print(strMat)
	arq = open('matrizBase.txt','w')
	arq.write(strMat)
	arq.close()

param = sys.argv[1:]
manipularArquivo(param)
