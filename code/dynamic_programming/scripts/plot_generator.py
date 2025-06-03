import matplotlib.pyplot as plt
import os

def generar_grafico():
    tiempo_path = "measurements/brute_force/time.txt"
    output_path = "plots/brute_force/tiempo.png"

    os.makedirs(os.path.dirname(output_path), exist_ok=True)

    with open(tiempo_path) as f:
        line = f.readline()
        tiempo = int(line.strip().split()[-1])  # extrae el número al final

    plt.figure(figsize=(6, 4))
    plt.bar(["Fuerza bruta"], [tiempo], color="tomato")
    plt.ylabel("Tiempo de ejecución (ms)")
    plt.title("Tiempo de ejecución - Fuerza bruta")

    plt.savefig(output_path)
    plt.close()

if __name__ == "__main__":
    generar_grafico()
