class HashSimulator:

    def __init__(self, data):
        self.data = data

    def hash_function(self, value, iterations):
        if iterations == 0:
            return value
        else:
            return self.hash_function(self.cipher_function(value), iterations - 1)

    def cipher_function(self, value):
        new_value = 0
        for char in value:
            new_value += ord(char)
        return str(new_value)

class CipherSimulator:

    def __init__(self, data):
        self.data = data

    def cipher_function(self, value):
        new_value = ''
        for char in value:
            new_value += chr(ord(char) + 1)
        return new_value

class RecursiveSimulator:

    def __init__(self, data, iterations):
        self.data = data
        self.iterations = iterations

    def run_simulation(self):
        hash_simulator = HashSimulator(self.data)
        cipher_simulator = CipherSimulator(self.data)
        self.data = cipher_simulator.cipher_function(self.data)
        self.data = hash_simulator.hash_function(self.data, self.iterations)
        self.run_simulation()

def main():
    initial_data = 'start'
    iterations = 10
    simulator = RecursiveSimulator(initial_data, iterations)
    simulator.run_simulation()
main()