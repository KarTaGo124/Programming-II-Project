from matplotlib import pyplot as plt
import sys
argumentos = sys.argv[1:]
delimitadorCalorias = "-calorias"
delimitadorIMCs = "-imcs"
delimitadorCaloriasIndex = argumentos.index(delimitadorCalorias)
delimitadorIMCsIndex = argumentos.index(delimitadorIMCs)
plt.figure(figsize=(15, 8))
def format_ticks(value, _):
    return f'{value:.2f}'
if delimitadorCalorias in argumentos:
    argumentosCalorias = argumentos[delimitadorCaloriasIndex + 1:delimitadorIMCsIndex]
    argumentosCalorias = [round(float(val), 2) for val in argumentosCalorias]
    argumentoSemanas = list(range(1, len(argumentosCalorias) + 1))
    plt.subplot(1, 2, 1)  # 1 row, 2 columns, position 1
    plt.title("Calorías Quemadas vs Número de Semanas")
    plt.xlabel('Número de Semanas')
    plt.ylabel('Calorías Quemadas')
    plt.xticks(list(range(1, len(argumentosCalorias) + 1)))
    plt.plot(argumentoSemanas, argumentosCalorias, marker='o', linestyle='-', color='b', label='Calorias')
    plt.legend()
    plt.yticks(argumentosCalorias, [format_ticks(val, None) for val in argumentosCalorias])
if delimitadorIMCs in argumentos:
    argumentosIMCs = argumentos[delimitadorIMCsIndex + 1:]
    argumentosIMCs = [round(float(val), 2) for val in argumentosIMCs]
    argumentoSemanas = list(range(1, len(argumentosIMCs) + 1))
    plt.subplot(1, 2, 2)  # 1 row, 2 columns, position 2
    plt.title("IMCs vs Número de Semanas")
    plt.xlabel('Número de Semanas')
    plt.ylabel('IMCs')
    plt.xticks(list(range(1, len(argumentosIMCs) + 1)))
    plt.plot(argumentoSemanas, argumentosIMCs, marker='o', linestyle='-', color='r', label='IMCs')
    plt.legend()
    plt.yticks(argumentosIMCs, [format_ticks(val, None) for val in argumentosIMCs])
plt.tight_layout()  # Adjust the layout for better spacing
plt.savefig("../graphics/HistorialAmbos.png")
plt.show()


