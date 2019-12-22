import matplotlib.pyplot as plt
import numpy as np

x = np.array([10,2,1])

def cost(p, xs):
    return np.sum((p - xs)**2)

arr = np.linspace(0,5,1000)
b = np.array([cost(a, x) for a in arr])

plt.plot(arr, b)
plt.show()
