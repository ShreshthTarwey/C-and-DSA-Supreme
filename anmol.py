import math
def method1(x,y):
    rem=x%y
    while(rem!=0):
        x,y = y,rem
        rem=x%y
    
    print(y)
def method2(x,y):
    print(math.gcd(x,y))
# def method3(x,y): abhi kaam baki hai
#     if(x>y):
#         i=y
#     else:
#         i=x
#     while(1):
#         if(x%i==0 and y%i==0):
#             hcf=i
#             break;
#         i+=1
#     print(hcf)
x=int(input())
y=int(input())
method1(x,y)
method2(x,y)
# method3(x,y)
