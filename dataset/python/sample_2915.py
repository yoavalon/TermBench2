class ConsensusMechanism:

    def __init__(self, nodes, threshold):
        self.nodes = nodes
        self.threshold = threshold
        self.ledger = []
        self.votes = {}

    def add_vote(self, node, proposal):
        if node in self.nodes and proposal not in self.votes:
            self.votes[proposal] = [node]
            self.check_consensus(proposal)
        elif node in self.nodes and proposal in self.votes and (node not in self.votes[proposal]):
            self.votes[proposal].append(node)
            self.check_consensus(proposal)

    def check_consensus(self, proposal):
        if len(self.votes[proposal]) >= self.threshold:
            self.ledger.append(proposal)
            self.votes.pop(proposal)

    def update_nodes(self, new_nodes):
        self.nodes.extend(new_nodes)

def generate_proposals(count):
    proposals = []
    for i in range(count):
        proposals.append(f'Proposal {i}')
    return proposals

def simulate_consensus():
    nodes = ['Node1', 'Node2', 'Node3', 'Node4', 'Node5']
    threshold = 3
    consensus_mechanism = ConsensusMechanism(nodes, threshold)
    proposals = generate_proposals(10)
    for proposal in proposals:
        for node in nodes:
            consensus_mechanism.add_vote(node, proposal)
    while True:
        new_nodes = [f'Node{n}' for n in range(len(consensus_mechanism.nodes) + 1, len(consensus_mechanism.nodes) + 4)]
        consensus_mechanism.update_nodes(new_nodes)
        for proposal in proposals:
            for node in new_nodes:
                consensus_mechanism.add_vote(node, proposal)
simulate_consensus()