#!/usr/bin/python3
import numpy as np
import pylab as pl



def getdata(file) :
    data = np.loadtxt(file)
    n = data.shape[0]
    x = np.zeros((n))
    y = np.zeros((n))
    x[:] = data[:,0]
    y[:] = data[:,1]
    return(x,y)


x1,y1 = getdata('data-cpu.txt')
x2,y2 = getdata('data-gpu.txt')
x3,y3 = getdata('data-omp.txt')

Nt=1501
l=6
flop = Nt*((2*l)*2*2 + 30)
flop=flop/1.0e+09
y1[:] = x1[:]**2*flop/y1[:] 
y2[:] = x2[:]**2*flop/y2[:] 
y3[:] = x3[:]**2*flop/y3[:] 

# Plotting
fig = pl.figure()
#pl.xticks(np.arange(0,3.1,1))
l1=pl.plot(x1,y1,label='Cpu single-core',color='orange',marker='o', linestyle='dashed')
l2=pl.plot(x2,y2,label='Gpu',color='red',marker='o',linestyle='dashed')
l3=pl.plot(x3,y3,label='Cpu six-core',color='green',marker='o',linestyle='dashed')
pl.legend(loc='upper left')
pl.xlabel('Model dimension')
pl.ylabel('Gflops')
pl.title("FD simulation 1500 time steps")
pl.ylim(0.0,120.0)
#pl.xlim(9.0,20.0)

#ax=pl.gca()
#pl.Axes.set_aspect(ax,0.75)

# Showing figure
#pl.rc('font',size=15)
#pl.gcf().tight_layout(h_pad=0,w_pad=0)
pl.savefig('gflops.pdf',bbox_inches='tight')
pl.show()
