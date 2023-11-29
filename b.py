def fb(n):
    a,b = 0,1
    if n==0:
        return 1
    for i in range(n):
        a,b =b,a+b
    return a

def f(x):
    return x*x-6*x+2
s=fb(0)
n=0
while 1/s>=0.08:
    n+=1
    s+=fb(n)
a=0
b=10
x1=a+fb(n)/s*(b-a)
x2=b-x1+a
y1=f(x1)
y2=f(x2)
for i in range(n):
    if y1<=y2:
        b=x2
        x2=x1
        x1=a+b-x2
        y2=y1
        y1=f(x1)
    else:
        a=x1
        x1=x2
        x2=b-x1+a
        y1=y2
        y2=f(x2)
print(a,b,b-a>0.8,n+2)
