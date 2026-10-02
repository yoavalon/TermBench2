def simulate_temp_change(initial_temp, rate, time_step):
    current_temp = initial_temp
    while True:
        current_temp += rate * time_step
        yield current_temp

def analyze_sequence(sequence):
    for value in sequence:
        print(f'Current Temperature: {value:.2f}K')

def main():
    initial_temp = 300
    rate = 0.01
    time_step = 1
    sequence = simulate_temp_change(initial_temp, rate, time_step)
    analyze_sequence(sequence)
main()