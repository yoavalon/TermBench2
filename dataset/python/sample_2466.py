def generate_sequence(n):

    def decay_reward(x):
        return x * 0.95 if x > 0 else 0
    sequence = [1]
    for _ in range(1, n):
        sequence.append(decay_reward(sequence[-1]))
    return sequence
if __name__ == '__main__':
    print(generate_sequence(10))