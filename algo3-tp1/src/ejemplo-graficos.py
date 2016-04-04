import numpy as np
import matplotlib.pyplot as plt

t = np.arange(1., 9., 1.)

plt.plot(t, t, 'r--', t, t*np.log2(t), 'bs', t, t**2, 'g^')
#r-- representa r de red -- porque lo dibuja con lineas punteadas, - es linea sin puntear
#bs representa b de blue s de squares
#g^ representa g de green y ^ de que son triangulos
plt.show()

t2 = [8,20,22,25,32,34,42,55]
plt.plot(t,t*10,'b-',t,t2,'g--')
plt.show()

#en este grafico graficamos los puntos (1,8), (2,20), (3,22)... hasta el (8,55)
#junto con la curva que representa una complejidad lineal que pasa por encima de la curva
