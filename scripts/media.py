sumMake = 0
sumTime = 0
for i in range(1,101):
    linha = input()
    v = linha.split(",")
    makeSpan = int(v[0])
    time = float(v[1])
    sumMake += makeSpan
    sumTime += time

print(sumMake/100)
print(sumTime/100)
