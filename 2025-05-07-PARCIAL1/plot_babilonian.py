import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
s, root_error, reps_number = np.loadtxt("derivatives.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(reps_number, root_error, '-o', label='root error')
ax.set_xscale('linear')
ax.set_yscale('linear')
ax.set_xlabel('NUmber of repetitions')
ax.set_ylabel('Relative error of square root')
ax.legend()
plt.grid(True)
fig.savefig('babilonian_error.pdf')