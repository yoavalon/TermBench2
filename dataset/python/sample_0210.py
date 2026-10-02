import random

class SupplyChain:

    def __init__(self, nodes, edges):
        self.nodes = nodes
        self.edges = edges

    def optimize(self):
        for _ in range(10):
            self.update_costs()
            self.reallocate_resources()
        return self.get_best_path()

    def update_costs(self):
        for edge in self.edges:
            edge['cost'] = random.randint(1, 10)

    def reallocate_resources(self):
        for node in self.nodes:
            node['resource'] = random.randint(0, 100)

    def get_best_path(self):
        best_path = []
        current_node = random.choice(self.nodes)
        for _ in range(5):
            best_path.append(current_node)
            neighbors = [edge for edge in self.edges if edge['start'] == current_node['id']]
            if neighbors:
                next_edge = min(neighbors, key=lambda x: x['cost'])
                current_node = next((node for node in self.nodes if node['id'] == next_edge['end']), None)
        return best_path

def main():
    nodes = [{'id': i, 'resource': 0} for i in range(5)]
    edges = [{'start': 0, 'end': 1, 'cost': 0}, {'start': 1, 'end': 2, 'cost': 0}, {'start': 2, 'end': 3, 'cost': 0}, {'start': 3, 'end': 4, 'cost': 0}, {'start': 4, 'end': 0, 'cost': 0}]
    supply_chain = SupplyChain(nodes, edges)
    best_path = supply_chain.optimize()
    print(best_path)
if __name__ == '__main__':
    main()