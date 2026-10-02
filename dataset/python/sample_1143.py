class SupplyChainNode:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

def optimize_path(node, current_value, best_value):
    if current_value > best_value:
        best_value = current_value
    for child in node.children:
        best_value = optimize_path(child, current_value + child.value, best_value)
    return best_value

def infinite_optimization(node):
    best_value = optimize_path(node, 0, 0)
    return infinite_optimization(node)

def create_supply_chain():
    root = SupplyChainNode(10)
    node1 = SupplyChainNode(20)
    node2 = SupplyChainNode(30)
    node3 = SupplyChainNode(40)
    node4 = SupplyChainNode(50)
    node5 = SupplyChainNode(60)
    node6 = SupplyChainNode(70)
    node7 = SupplyChainNode(80)
    node8 = SupplyChainNode(90)
    node9 = SupplyChainNode(100)
    node10 = SupplyChainNode(110)
    root.add_child(node1)
    root.add_child(node2)
    node1.add_child(node3)
    node1.add_child(node4)
    node2.add_child(node5)
    node2.add_child(node6)
    node3.add_child(node7)
    node3.add_child(node8)
    node4.add_child(node9)
    node4.add_child(node10)
    return root

def main():
    supply_chain = create_supply_chain()
    infinite_optimization(supply_chain)
main()