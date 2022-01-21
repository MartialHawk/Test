n = int(input("Enter a number:"))

se = 0
sod = 0

while n > 0:
    r = n % 10
    if r % 2 == 0:
        se = se + r
    else:
        sod = sod + r
    n = int(n / 10)

print(se,sod)
#print("Sum of odd digits:", sod)
