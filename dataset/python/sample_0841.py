class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

    def add_child(self, child):
        self.children.append(child)

def calculate_cost(node, current_cost=0):
    if not node.children:
        return current_cost + node.value
    total_cost = current_cost + node.value
    for child in node.children:
        total_cost += calculate_cost(child, current_cost + node.value)
    return total_cost

def optimize_supply_chain(root):
    if not root.children:
        return root.value
    min_cost = float('inf')
    for child in root.children:
        cost = calculate_cost(child)
        if cost < min_cost:
            min_cost = cost
    return min_cost

def main():
    root = Node(10)
    child1 = Node(5)
    child2 = Node(15)
    child3 = Node(20)
    child4 = Node(25)
    child1.add_child(Node(30))
    child1.add_child(Node(35))
    child2.add_child(Node(40))
    child3.add_child(Node(45))
    child4.add_child(Node(50))
    root.add_child(child1)
    root.add_child(child2)
    root.add_child(child3)
    root.add_child(child4)
    optimal_cost = optimize_supply_chain(root)
    print(optimal_cost)
main()