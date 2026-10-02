import os
import matplotlib.pyplot as plt
from pathlib import Path
from datetime import datetime

def get_creation_time(path: Path) -> float:
    """
    Attempts to get the file creation time (birth time). 
    Falls back to metadata change time (ctime) if birth time is unavailable.
    """
    stat = path.stat()
    try:
        # Available on Windows, macOS, and Linux (Python 3.12+)
        return stat.st_birthtime
    except AttributeError:
        # Fallback for older Linux/Python combinations
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

    if not creation_times:
        print(f"No files found in '{folder_path}'.")
        return

    # Sort times chronologically
    creation_times.sort()

    # 2. Plot the data
    plt.figure(figsize=(10, 6))
    
    # Using a histogram to show how many files were created in different time buckets
    plt.hist(creation_times, bins=50, color='skyblue', edgecolor='black')
    
    plt.title('File Creation Distribution', fontsize=14)
    plt.xlabel('Date / Time', fontsize=12)
    plt.ylabel('Number of Files Created', fontsize=12)
    
    # Rotate the x-axis dates so they don't overlap
    plt.xticks(rotation=45)
    plt.tight_layout()
    
    # Display the plot
    plt.show()

if __name__ == "__main__":
    main()