import os
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from pathlib import Path
from datetime import datetime

def get_creation_time(path: Path) -> float:
    """
    Attempts to get the file creation time (birth time). 
    Falls back to metadata change time (ctime) if birth time is unavailable.
    """
    stat = path.stat()
    try:
        return stat.st_birthtime
    except AttributeError:
        return stat.st_ctime

def main():
    folder_path = Path('/home/algo/code/TermBench2/dataset/python')
    
    if not folder_path.exists() or not folder_path.is_dir():
        print(f"Error: The directory '{folder_path}' does not exist.")
        return

    # 1. Collect file creation times
    creation_times = []
    for file_path in folder_path.iterdir():
        if file_path.is_file():
            c_timestamp = get_creation_time(file_path)
            creation_times.append(datetime.fromtimestamp(c_timestamp))

    if len(creation_times) < 2:
        print(f"Not enough files to calculate job durations in '{folder_path}'.")
        return

    # Sort times chronologically
    creation_times.sort()

    # 2. Calculate continuous job durations
    completion_times = []
    durations = []
    
    for i in range(1, len(creation_times)):
        duration_seconds = (creation_times[i] - creation_times[i-1]).total_seconds()
        completion_times.append(creation_times[i])
        durations.append(duration_seconds)

    # Calculate a moving average to show the trend smoothly
    # Adjust the window size (e.g., 10) depending on how many total files you have
    window_size = min(10, len(durations))
    moving_averages = []
    
    for i in range(len(durations)):
        start_idx = max(0, i - window_size + 1)
        window = durations[start_idx : i + 1]
        moving_averages.append(sum(window) / len(window))

    # 3. Plot the data continuously
    plt.figure(figsize=(12, 6))
    
    # Plot raw durations as a light scatter plot in the background (optional)
    plt.scatter(completion_times, durations, color='lightgray', alpha=0.7, label='Individual Job Duration', s=15)
    
    # Plot the moving average as a continuous line
    plt.plot(completion_times, moving_averages, color='blue', linewidth=2, label=f'{window_size}-Job Moving Average')
    
    plt.title('Average Time per Job Over Time', fontsize=14)
    plt.xlabel('Date / Time', fontsize=12)
    plt.ylabel('Duration (Seconds)', fontsize=12)
    
    # Format the X-axis to display timestamps cleanly
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d %H:%M'))
    plt.xticks(rotation=45)
    
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.tight_layout()
    
    # Display the plot
    plt.show()

if __name__ == "__main__":
    main()