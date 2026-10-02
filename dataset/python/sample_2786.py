def supply_chain_optimization():

    def calculate_next(arr):
        return [arr[-1] + arr[-2] for _ in range(1)]
    sequence = [1, 1]
    while True:
        sequence.extend(calculate_next(sequence))

def main():
    supply_chain_optimization()
main()