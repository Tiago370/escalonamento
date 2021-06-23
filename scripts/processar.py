import os
nGenerations = 1000000
#criar arquivo "dados-treinamento-redes"
os.system("rm dados-treinamento-redes.csv")
os.system("touch dados-treinamento-redes.csv")
#apendar "Configuraçao,Tamanho,nGerações,Tempo de Treinamento"
os.system('echo "Configuraçao,Tamanho,nGerações,Tempo de Treinamento" >> dados-treinamento-redes.csv')

#treinar rede ORS 2x2 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-2x2 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "ORS,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 4x4 homogenea com população de 100, <nGenerations> ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-4x4 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "ORS,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 8x8 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-8x8 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "ORS,8x8,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 10x10 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/hom-ORS-10x10 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 10 -hidden-neurons 10")
#apendar "ORS,10x10,<generations>,<Tempo de Treinamento>"


#treinar rede ORS 2x2 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-2x2 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "ORS,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 4x4 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-4x4 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "ORS,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 8x8 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-8x8 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "ORS,8x8,<generations>,<Tempo de Treinamento>"

#treinar rede ORS 10x10 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -subtract -net redes/het-ORS-10x10 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 10 -hidden-neurons 10")
#apendar "ORS,10x10,<generations>,<Tempo de Treinamento>"

#sem subtract
#treinar rede OR 2x2 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/hom-OR-2x2 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "OR,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede OR 4x4 homogenea com população de 100, <nGenerations> ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/hom-OR-4x4 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "OR,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede OR 8x8 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/hom-OR-8x8 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "OR,8x8,<generations>,<Tempo de Treinamento>"

#treinar rede OR 10x10 homogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "hom-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/hom-OR-10x10 -instance treinamento-homogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 10 -hidden-neurons 10")
#apendar "OR,10x10,<generations>,<Tempo de Treinamento>"


#treinar rede OR 2x2 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/het-OR-2x2 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 2 -hidden-neurons 2")
#apendar "OR,2x2,<generations>,<Tempo de Treinamento>"

#treinar rede OR 4x4 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/het-OR-4x4 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 4 -hidden-neurons 4")
#apendar "OR,4x4,<generations>,<Tempo de Treinamento>"

#treinar rede OR 8x8 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/het-OR-8x8 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 8 -hidden-neurons 8")
#apendar "OR,8x8,<generations>,<Tempo de Treinamento>"

#treinar rede OR 10x10 heterogenea com população de 100, <nGenerations> gerações ou até ficar 200 gerações sem melhoras
os.system('echo "het-" >> dados-treinamento-redes.csv')
os.system("./build/escalonamento train -order -relativize -net redes/het-OR-10x10 -instance treinamento-heterogeneo -generations " + str(nGenerations) + " -population 100 -hidden-layers 10 -hidden-neurons 10")
#apendar "OR,10x10,<generations>,<Tempo de Treinamento>"

