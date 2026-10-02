def decay_function(current_value, decay_rate):
    return current_value * (1 - decay_rate)

def termination_analysis(initial_value, threshold, decay_rate):
    value = initial_value
    count = 0
    while value > threshold:
        value = decay_function(value, decay_rate)
        count += 1
    return count

def main():
    initial_value = 1.0
    threshold = 0.01
    decay_rate = 0.1
    result = termination_analysis(initial_value, threshold, decay_rate)
    print(result)
main()