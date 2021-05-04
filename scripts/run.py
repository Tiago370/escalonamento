import os
#com subtract
#criar arquivo "2x2-hom-ORS.csv"
os.system("rm 2x2-hom-ORS.csv")
os.system("touch 2x2-hom-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/hom-ORS-2x2 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 2x2-hom-ORS.csv')

#criar arquivo "4x4-hom-ORS.csv"
os.system("rm 4x4-hom-ORS.csv")
os.system("touch 4x4-hom-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/hom-ORS-4x4 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 4x4-hom-ORS.csv')

#criar arquivo "8x8-hom-ORS.csv"
os.system("rm 8x8-hom-ORS.csv")
os.system("touch 8x8-hom-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/hom-ORS-8x8 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 8x8-hom-ORS.csv')

#criar arquivo "10x10-hom-ORS.csv"
os.system("rm 10x10-hom-ORS.csv")
os.system("touch 10x10-hom-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/hom-ORS-10x10 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 10x10-hom-ORS.csv')


#criar arquivo "2x2-het-ORS.csv"
os.system("rm 2x2-het-ORS.csv")
os.system("touch 2x2-het-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/het-ORS-2x2 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 2x2-het-ORS.csv')

#criar arquivo "4x4-het-ORS.csv"
os.system("rm 4x4-het-ORS.csv")
os.system("touch 4x4-het-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/het-ORS-4x4 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 4x4-het-ORS.csv')

#criar arquivo "8x8-het-ORS.csv"
os.system("rm 8x8-het-ORS.csv")
os.system("touch 8x8-het-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/het-ORS-8x8 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 8x8-het-ORS.csv')

#criar arquivo "10x10-het-ORS.csv"
os.system("rm 10x10-het-ORS.csv")
os.system("touch 10x10-het-ORS.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -subtract -net redes/het-ORS-10x10 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 10x10-het-ORS.csv')


#sem subtract
#criar arquivo "2x2-hom-OR.csv"
os.system("rm 2x2-hom-OR.csv")
os.system("touch 2x2-hom-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/hom-OR-2x2 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 2x2-hom-OR.csv')

#criar arquivo "4x4-hom-OR.csv"
os.system("rm 4x4-hom-OR.csv")
os.system("touch 4x4-hom-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/hom-OR-4x4 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 4x4-hom-OR.csv')

#criar arquivo "8x8-hom-OR.csv"
os.system("rm 8x8-hom-OR.csv")
os.system("touch 8x8-hom-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/hom-OR-8x8 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 8x8-hom-OR.csv')

#criar arquivo "10x10-hom-OR.csv"
os.system("rm 10x10-hom-OR.csv")
os.system("touch 10x10-hom-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/hom-OR-10x10 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 10x10-hom-OR.csv')


#criar arquivo "2x2-het-OR.csv"
os.system("rm 2x2-het-OR.csv")
os.system("touch 2x2-het-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/het-OR-2x2 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 2x2-het-OR.csv')

#criar arquivo "4x4-het-OR.csv"
os.system("rm 4x4-het-OR.csv")
os.system("touch 4x4-het-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/het-OR-4x4 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 4x4-het-OR.csv')

#criar arquivo "8x8-het-OR.csv"
os.system("rm 8x8-het-OR.csv")
os.system("touch 8x8-het-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/het-OR-8x8 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 8x8-het-OR.csv')

#criar arquivo "10x10-het-OR.csv"
os.system("rm 10x10-het-OR.csv")
os.system("touch 10x10-het-OR.csv")
for i in range(1, 101):
    os.system('./build/escalonamento run -order -relativize -net redes/het-OR-10x10 -instance instancias/teste/hetereogenea/' + str(i) + ' -data 10x10-het-OR.csv')

