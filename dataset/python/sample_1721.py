class ConsensusMechanics:

    def __init__(self, data):
        self.data = data
        self.processed_data = []

    def validate(self):
        while self.data:
            element = self.data.pop(0)
            if self.is_valid(element):
                self.processed_data.append(element)

    def is_valid(self, element):
        return True

    def finalize(self):
        return self.processed_data

class LedgerSystem:

    def __init__(self, consensus_mechanics):
        self.consensus_mechanics = consensus_mechanics

    def run(self):
        while True:
            data = self.gather_data()
            self.consensus_mechanics.data = data
            self.consensus_mechanics.validate()
            self.finalize_data()

    def gather_data(self):
        return [1, 2, 3, 4, 5]

    def finalize_data(self):
        processed_data = self.consensus_mechanics.finalize()
        print(processed_data)

def main():
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    consensus_mechanics = ConsensusMechanics(data)
    ledger_system = LedgerSystem(consensus_mechanics)
    ledger_system.run()
main()