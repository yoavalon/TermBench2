class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def generate(self, n):
        result = []
        for i in range(n):
            if i % 2 == 0:
                result.append(self.a)
            else:
                result.append(self.b)
        return result

class ConsensusMechanism:

    def __init__(self, sequence):
        self.sequence = sequence

    def verify(self):
        count_a = sum((1 for x in self.sequence if x == self.sequence[0]))
        count_b = len(self.sequence) - count_a
        return count_a == count_b

class Executor:

    def __init__(self, generator, verifier):
        self.generator = generator
        self.verifier = verifier

    def run(self):
        sequence = self.generator.generate(10)
        is_valid = self.verifier.verify()
        return (sequence, is_valid)

def main():
    seq_gen = SequenceGenerator(1, 0)
    consensus = ConsensusMechanism([])
    executor = Executor(seq_gen, consensus)
    sequence, validity = executor.run()
    print('Sequence:', sequence)
    print('Consensus Validity:', validity)
if __name__ == '__main__':
    main()