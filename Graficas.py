from matplotlib import pyplot as plt
import sys

arguments = sys.argv[1:] #lee to do el texto
weight_history_delimiter = "--weight_history"
imc_history_delimiter = "--imc_history"
date_delimiter_index = arguments.index("--date")
date_args = arguments[date_delimiter_index + 1:]

if weight_history_delimiter in arguments:
    weight_delimiter_index = arguments.index(weight_history_delimiter)
    weight_args = arguments[weight_delimiter_index + 1:date_delimiter_index]
    print(weight_args)
    print(date_args)
    plt.plot(weight_args, date_args)
    plt.savefig("../assets/weight_history.png")
    plt.show()
else:
    imc_delimiter_index = arguments.index(imc_history_delimiter)
    imc_args = arguments[imc_delimiter_index:date_delimiter_index - 1]
    plt.plot(imc_args, date_args)
    plt.savefig("../assets/imc_history.png")