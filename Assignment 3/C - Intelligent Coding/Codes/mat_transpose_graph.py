import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
csv_file_path = "matrix_transpose_in.csv"  # Adjust as needed to the correct file path
data = pd.read_csv(csv_file_path)  # Read CSV with headers

# Use a rolling window to calculate the moving average
window_size = 10

# Extract the 'n' column for the X-axis
x = data["n"]

# Calculate the rolling average for 'n'
x_avg = x.rolling(window=window_size).mean()

# Extract all other columns for Y values
y_lines = data.loc[:, "ij":"ji"]  # Select all columns from 'ij' to 'ji'

# Plot the rolling averages
for column in y_lines:
    y_avg = (
        y_lines[column].rolling(window=window_size).mean()
    )  # Calculate the moving average for each column
    plt.plot(x_avg, y_avg, label=column)  # Use column name as label

# Adding labels, title, and legend
plt.xlabel("n")
plt.ylabel("Execution Time (ms)")
plt.title("Matrix Transpose Execution Time by Algorithm")
plt.legend()  # Show legend to differentiate lines

# Display the plot
plt.show()
