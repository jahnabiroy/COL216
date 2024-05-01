import pandas as pd
import matplotlib.pyplot as plt

# Read data from CSV file
file_path = "data.csv"
data = pd.read_csv(file_path)

# Extract data columns
x_values = data["input"]
y1_values = data["A"]
y2_values = data["B"]
y3_values = data["C"]

# Create a single plot with all three lines and resize the figure
fig, ax = plt.subplots(figsize=(10, 6))  # Adjust the width and height as needed

# Plot the data
ax.plot(x_values, y1_values, label="Tail Recursion", color="cyan")
ax.plot(x_values, y2_values, label="Recursion", color="magenta")
ax.plot(x_values, y3_values, label="Iterative", color="orange")

ax.set_xlabel("N")
ax.set_ylabel("Cycles")
ax.set_title("JAHNABI ROY; 2022CS11094; Performance versus input N")
ax.legend()
plt.show()
