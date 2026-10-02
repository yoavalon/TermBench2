class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def calculate_cost(node):
    if node is None:
        return 0
    left_cost = calculate_cost(node.left)
    right_cost = calculate_cost(node.right)
    return node.value + left_cost + right_cost

def optimize_supply_chain(root, budget):
    if root is None or budget <= 0:
        return (0, root)
    left_value, left_node = optimize_supply_chain(root.left, budget - root.value)
    right_value, right_node = optimize_supply_chain(root.right, budget - root.value)
    total_value = root.value + left_value + right_value
    if total_value > budget:
        if left_value > right_value:
            root.left = None
        else:
            root.right = None
    return (total_value, root)

def main():
    root = Node(10)
    root.left = Node(5)
    root.right = Node(15)
    root.left.left = Node(3)
    root.left.right = Node(7)
    root.right.right = Node(20)
    budget = 25
    _, optimized_tree = optimize_supply_chain(root, budget)
    print('Total Cost of Optimized Supply Chain:', calculate_cost(optimized_tree))
main()