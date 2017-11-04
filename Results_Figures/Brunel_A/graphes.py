import numpy as np
import matplotlib.pyplot as pl

data = np.genfromtxt('spikes.txt')

select= np.array([d for d in data if d[1] < 50])
data1= select.transpose()

pl.figure()
pl.scatter(0.1*data1[0],data1[1],alpha=0.8, edgecolors='none');
pl.xlabel('Time in ms');
pl.ylabel(' Neuro id');
pl.savefig("first.png")

pl.figure()
n, bins, patches = pl.hist(0.1*data1[0], 100, normed=0, alpha=0.75)
pl.xlabel('Time in ms');
pl.ylabel('Rate in Hz');

f, axarr = pl.subplots(2)
axarr[0].scatter(0.1*data1[0],data1[1],alpha=0.8, edgecolors='none')

n, bins, patches = axarr[1].hist(0.1*data1[0], 100, alpha=0.75)
pl.savefig("A.pdf")

