#!-*- coding: utf8 -*-

'''
 UFRRJ - Ciência da Computação
 Disciplina: Tópicos Especiais em Otimização
 Professora: Adria Lyra
 Alunas: Patrícia Castro e Vanessa Soares

 Executar aplicação somente com python3
 python3 leituraArquivo.py

'''

import re
import os.path

def leituraBase(path):
	with open(path) as file_object:
		base = file_object.readlines()

		arquivo = []
		for i in range(0,len(base)):
			arquivo.append(base[i].rstrip()) #rstrip remove \n da linha

	return arquivo

def recuperaMatriz():

	arquivo = leituraBase("matrizBase.txt")
	matTerreno = []
	lin = len(arquivo)
	col = 0
	for i in range(0,lin):
	 	col = len(arquivo[i].split()) 
	 	matTerreno.append([])
	 	for j in range(0, col):
	 		areas = arquivo[i].split()[j]
	 		matTerreno[i].append(float(areas))

	return lin,col,matTerreno

def recuperaInformacoesRadar():
	arquivo = leituraBase("informacoesRadar.txt")
	n_tipos = len(arquivo)
	print ("\n\nQuantidade de tipos de radares : ", n_tipos )
	radares_list = []
	for i in range(0, n_tipos):
		radar={
			"tipo": 0,
			"alcance": 0,
			"quantidade": 0
		}
		linha_radar = arquivo[i].split(' ')
		radar["tipo"] = i
		radar["alcance"] = int(linha_radar[0])
		radar["quantidade"] = int(linha_radar[1])

		radares_list.append(radar)
	return radares_list

def guardaAreaDoTerreno():

		lin,col,matTerreno = recuperaMatriz()

		jsonMatriz = []
		for i in range(0,lin):
			for j in range(0,col):
				arquivo = {"linha": i, "coluna": j, "areaTerreno": matTerreno[i][j]}
				jsonMatriz.append(arquivo)


		print(jsonMatriz)

def recuperaPontosInstalacao():
		lin,col,matTerreno = recuperaMatriz()

		jsonMatriz = []
		for i in range(0,lin):
			for j in range(0,col):
				if matTerreno[i][j]>0:
					arquivo = {"linha": i, "coluna": j, "areaTerreno": matTerreno[i][j], "areaNaoCoberta":0, "tipoRadar":0}
					jsonMatriz.append(arquivo)
		return jsonMatriz
