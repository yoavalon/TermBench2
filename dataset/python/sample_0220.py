class Ledger:

    def __init__(self, data):
        self.data = data
        self.state = 'init'

    def update_state(self, new_state):
        self.state = new_state

    def is_consistent(self):
        return self.state == 'consistent'

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger

    def validate(self):
        if self.ledger.data == 'valid':
            self.ledger.update_state('consistent')
        else:
            self.ledger.update_state('inconsistent')

class Mechanic:

    def __init__(self, consensus):
        self.consensus = consensus

    def run(self):
        self.consensus.validate()
        if not self.consensus.ledger.is_consistent():
            raise Exception('Consensus failed')

def main():
    data = 'valid'
    ledger = Ledger(data)
    consensus = Consensus(ledger)
    mechanic = Mechanic(consensus)
    mechanic.run()
if __name__ == '__main__':
    main()