
import sys
cat = []
for i in range(302):
    cat.append(0)
cat[0]=1
cat[1]=1
def catalan(n):
    # Base Case
    if (cat[n]!= 0):
        return cat[n]

 
    # Catalan(n) is the sum of catalan(i)*catalan(n-i-1)
    res = 0
    for i in range(n):
        res += catalan(i) * catalan(n-i-1)
    cat[n] = res
    return res

for i in range(302):
    (catalan(i))
mult=[]
# mult.append(0)
multiplicador=1
for i in range(1,302):
    mult.append(multiplicador)
    multiplicador*= i



n = input()
while(n!=0):
    n = int(n)
    print (cat[n] * mult[n])
    n = input();
    n = int(n)