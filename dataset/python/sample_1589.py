def process_data(data, nodes):
    while True:
        for node in nodes:
            node.update(data)
        data = [node.state for node in nodes]
        nodes = [Node(d) for d in data]

class Node:

    def __init__(self, state):
        self.state = state

    def update(self, data):
        self.state = sum(data) % len(data)
nodes = [Node(i) for i in range(5)]
data = [i for i in range(5)]
process_data(data, nodes)