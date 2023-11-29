a=0
b=10
x1=a+0.382*(b-a)
x2=a+0.618*(b-a)

def f(x):
    return x*x-6*x+2
y1=f(x1)
y2=f(x2)
c=2
while b-a>0.8:
    if y1<=y2:
        b=x2
        x2=x1
        x1=a+0.382*(b-a)
        y2=y1
        y1=f(x1)
    else:
        a=x1
        x1=x2
        x2=a+0.618*(b-a)
        y1=y2
        y2=f(x2)
    c+=1
print(a,b,b-a>0.8,c)