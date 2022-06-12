s1=['a','b','c']

s2= ['b','c']
def digSum(cls,input1,input2):
    a=list(set(input1)&set(input2))
    sum=0
    n=0
    for i in a:
        n+=ord(i)



    if (n == 0):
        return 0
    if (n % 9 == 0):
        return 9
    else:
       return (n % 9)
     
     
print(digSum('.',s1,s2))
