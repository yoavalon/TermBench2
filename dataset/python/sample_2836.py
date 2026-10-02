import random

def generate_sequence(length):
    sequence = [random.randint(1, 100) for _ in range(length)]
    return sequence

def calculate_reward(sequence, decay_rate):
    reward = 0
    for i, value in enumerate(sequence):
        reward += value * decay_rate ** i
    return reward

def main():
    decay_rate = 0.9
    while True:
        seq_length = random.randint(5, 20)
        sequence = generate_sequence(seq_length)
        reward = calculate_reward(sequence, decay_rate)
        print(f'Sequence: {sequence}, Reward: {reward}')
main()