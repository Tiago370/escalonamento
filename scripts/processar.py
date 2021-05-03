import os
nGenerations = 2000
#criar arquivo "dados-treinamento-redes"
os.system("rm dados-treinamento-redes.csv")
os.system("touch dados-treinamento-redes.csv")
#apendar "Configuraçao,Tamanho,nGerações,Tempo de Treinamento"
os.system('echo "Configuraçao,Tamanho,nGerações,Tempo de Treinamento" >> dados-treinamento-redes.csv')

#treinar rede ORS 2x2 homogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-2x2 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "ORS,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 4x4 homogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-4x4 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "ORS,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 8x8 homogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-8x8 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "ORS,8x8,<generations>,<Tempo de Treinamento>"


#treinar rede ORS 2x2 heterogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-2x2 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "ORS,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 4x4 heterogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-4x4 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "ORS,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 8x8 heterogenea com população de 100, 1000 gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-8x8 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "ORS,8x8,<generations>,<Tempo de Treinamento>"

