class Sequence:

    def __init__(self, n):
        self.n = n

    def generate(self):
        result = []
        for i in range(self.n):
            result.append(self.transform(i))
        return result

    def transform(self, x):
        return (x * x + 3 * x + 1) % 101

class HashSimulator:

    def __init__(self, sequence):
        self.sequence = sequence

    def hash(self):
        total = 0
        for num in self.sequence:
            total = (total + num * 23) % 1001
        return total

class CipherSimulator:

    def __init__(self, hash_value):
        self.hash_value = hash_value

    def encrypt(self):
        encrypted = []
        for i in range(self.hash_value):
            encrypted.append((i * self.hash_value + i) % 1009)
        return encrypted

def main():
    n = 50
    sequence = Sequence(n).generate()
    hash_simulator = HashSimulator(sequence)
    hash_value = hash_simulator.hash()
    cipher_simulator = CipherSimulator(hash_value)
    encrypted = cipher_simulator.encrypt()
    print(encrypted)
if __name__ == '__main__':
    main()