import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
csv_file_path = "matrix_trans.csv"  # Adjust as needed to the correct file path
data = pd.read_csv(csv_file_path)  # Read CSV with headers

# Define the rolling window size
window_size = 7

# Extract the 'n' column for the X-axis and compute the rolling average
x = data["n"]
x_avg = x.rolling(
    window=window_size, min_periods=1
).mean()  # Calculate rolling average for 'n'

# Extract all other columns for Y values
y_lines = data.loc[:, "add":"in"]  # Select all columns from 'ijk' to 'jik'

# Plot the rolling averages for all lines
for column in y_lines:
    y_avg = (
        y_lines[column].rolling(window=window_size, min_periods=1).mean()
    )  # Rolling average for each algorithm
    plt.plot(x_avg, y_avg, label=column)  # Use column name as label

# Adding labels, title, and legend
plt.xlabel("n")
plt.ylabel("Execution Time (ms)")
plt.title("Comparison")
plt.legend()  # Show legend to differentiate lines

# Display the plot
plt.show()
