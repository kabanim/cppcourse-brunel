import numpy as np
import matplotlib.pyplot as pl
import matplotlib.backends.backend_pdf
pdf = matplotlib.backends.backend_pdf.PdfPages("output.pdf")

data = np.genfromtxt('spikes.txt')

select= np.array([d for d in data if d[1] < 50])
data1= select.transpose()

fig1=pl.figure()
pl.scatter(0.1*data1[0],data1[1],alpha=0.8, edgecolors='none');
pl.xlabel('Time in ms');
pl.ylabel(' Neuro id');
pl.savefig("first.png")

fig2=pl.figure()
n, bins, patches = pl.hist(0.1*data1[0], 100, normed=0, alpha=0.75)
pl.xlabel('Time in ms');
pl.ylabel('Rate in hz');
pl.savefig("second.png")


pdf.savefig( fig1 )
pdf.savefig( fig2 )

pdf.close()
