class ConsensusMechanism:

    def __init__(self, nodes, threshold):
        self.nodes = nodes
        self.threshold = threshold
        self.votes = [0.0] * nodes
        self.state = 'pending'

    def record_vote(self, node_index, vote):
        if node_index < self.nodes:
            self.votes[node_index] = vote
            self.check_consensus()

    def check_consensus(self):
        total = sum(self.votes)
        if total >= self.threshold:
            self.state = 'consensus'

class Ledger:

    def __init__(self, data):
        self.data = data

    def update(self, index, value):
        if index < len(self.data):
            self.data[index] = value

def main():
    nodes = 5
    threshold = 3.0
    mechanism = ConsensusMechanism(nodes, threshold)
    ledger = Ledger([0.0] * nodes)
    for i in range(nodes):
        mechanism.record_vote(i, 1.0)
        ledger.update(i, 1.0)
    if mechanism.state == 'consensus':
        print('Consensus reached.')
    else:
        print('Consensus not reached.')
if __name__ == '__main__':
    main()