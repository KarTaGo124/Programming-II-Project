from matplotlib import pyplot as plt
import sys

argumentos = sys.argv[1:] #lee to do el texto
delimitadorDatos = "-datos"
delimitadorDatosIndex = argumentos.index(delimitadorDatos)
argumentoDatos = argumentos[delimitadorDatosIndex + 1:]
argumentoSemanas = list(range(1, len(argumentoDatos)+1))
print(argumentoDatos)
print(argumentoSemanas)
plt.plot(argumentoDatos,argumentoSemanas )
plt.savefig("HistorialCalorias.png")
plt.show()

