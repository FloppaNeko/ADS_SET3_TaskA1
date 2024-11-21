import matplotlib.pyplot as plt
import numpy as np

TRUE_VAL = 0.9445171858994637


data = np.genfromtxt("data.csv", delimiter=',')
x = data[:, 0]
res = data[:, 1]
err = data[:, 2]

fig, axes = plt.subplots(1, 2, figsize=(12, 5))  # 1 row, 2 columns

# First graph
axes[0].plot(x, res, color="blue")
axes[0].axhline(y=TRUE_VAL, linestyle="--", color="black", label="Истинное значение")
axes[0].set_title("Значение площади")
axes[0].set_xlabel("Количество точек")
axes[0].grid()
axes[0].legend()

# Second graph
axes[1].plot(x, err, color="red")
axes[1].set_title("Относительная погрешность")
axes[1].set_xlabel("Количество точек")
axes[1].grid()

# Adjust spacing between plots
plt.tight_layout()

# Show the plots
plt.show()

