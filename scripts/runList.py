import os

#criar arquivo "list-hom.csv"
os.system("rm list-hom.csv")
os.system("touch list-hom.csv")
for i in range(1, 101):
    os.system('./build/main LIST instancias/teste/homogenea/' +str(i) + ' >> list-hom.csv')


#criar arquivo "list-het.csv"
os.system("rm list-het.csv")
os.system("touch list-het.csv")
for i in range(1, 101):
    os.system('./build/main LIST instancias/teste/hetereogenea/' +str(i) + ' >> list-het.csv')

