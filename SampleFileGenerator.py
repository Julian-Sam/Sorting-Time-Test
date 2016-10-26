import random
SampleSize = 20000
ListSize = 1000

X = random.sample(range(SampleSize), ListSize)

##X=list(range(length))
##random.shuffle(X)

new = open("new.txt","w")

new.write(str(length))
new.write("\n")

for i in range(len(X)):
    A = str(X[i])
    new.write(A)
    new.write("\n")
    

new.close()

