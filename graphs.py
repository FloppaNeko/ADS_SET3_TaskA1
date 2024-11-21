import matplotlib.pyplot as plt
import numpy as np

TRUE_VAL = 0.9445171858994637


data = np.genfromtxt("data.csv", delimiter=',')
x = data[:, 0]
res1 = data[:, 1]
err1 = data[:, 2]
res2 = data[:, 3]
err2 = data[:, 4]

fig, axes = plt.subplots(1, 2, figsize=(12, 5))  # 1 row, 2 columns

# First graph
axes[0].plot(x, res1, color="blue", lw=1, 
             label="Площадь области точек $S_{rec} = 4$")
axes[0].plot(x, res2, color="gold", lw=1,
             label="Площадь области точек $S_{rec} = 9$")
axes[0].axhline(y=TRUE_VAL, linestyle="--", color="black", label="Истинное значение")
axes[0].set_title("Значение площади")
axes[0].set_xlabel("Количество точек")
axes[0].set_ylim(0.85, 1.05)
axes[0].grid()
axes[0].legend()

# Second graph
axes[1].plot(x, err1, color="red", lw=1,
             label="Площадь области точек $S_{rec} = 4$")
axes[1].plot(x, err2, color="turquoise", lw=1,
             label="Площадь области точек $S_{rec} = 9$")
axes[1].set_title("Относительная погрешность")
axes[1].set_xlabel("Количество точек")
axes[1].set_ylim(-0.005, 0.10)
axes[1].grid()
axes[1].legend()

# Adjust spacing between plots
plt.tight_layout()

# Show the plots
plt.show()

