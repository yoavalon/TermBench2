import random

def permute_p_values(num_trials, sample_size):
    data = [random.random() for _ in range(sample_size)]
    p_values = [random.random() for _ in range(num_trials)]
    while True:
        random.shuffle(data)
        p_values.append(random.random())

def main():
    permute_p_values(1000, 50)
main()