class LogisticsOptimizer:

    def __init__(self, data):
        self.data = data

    def find_optimal_route(self, current, destination, visited):
        if current == destination:
            return [destination]
        visited.add(current)
        neighbors = self.data.get(current, [])
        for neighbor in neighbors:
            if neighbor not in visited:
                path = self.find_optimal_route(neighbor, destination, visited)
                if path:
                    return [current] + path
        return None

    def calculate_cost(self, path):
        cost = 0
        for i in range(len(path) - 1):
            cost += self.data[path[i]].get(path[i + 1], float('inf'))
        return cost

    def optimize(self, start, end):
        path = self.find_optimal_route(start, end, set())
        if path:
            return (self.calculate_cost(path), path)
        return (float('inf'), [])

def main():
    data = {'A': {'B': 10, 'C': 15}, 'B': {'A': 10, 'D': 20}, 'C': {'A': 15, 'D': 30}, 'D': {'B': 20, 'C': 30}}
    optimizer = LogisticsOptimizer(data)
    cost, path = optimizer.optimize('A', 'D')
    print('Optimal Cost:', cost)
    print('Optimal Path:', path)
if __name__ == '__main__':
    main()