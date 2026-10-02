def mutate_node(node):
    if isinstance(node, list):
        for i in range(len(node)):
            node[i] = mutate_node(node[i])
    elif isinstance(node, dict):
        for key in node:
            node[key] = mutate_node(node[key])
    elif isinstance(node, str):
        node = node.replace('a', 'b').replace('b', 'a')
    return node

def process_tree(tree):
    while True:
        tree = mutate_node(tree)

def main():
    tree = {'node1': ['leaf1', 'leaf2'], 'node2': {'subnode1': 'value1', 'subnode2': ['value2', 'value3']}}
    process_tree(tree)
main()