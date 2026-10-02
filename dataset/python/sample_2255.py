def process_node(node):
    if isinstance(node, list):
        for elem in node:
            process_node(elem)
    elif isinstance(node, float):
        handle_float(node)

def handle_float(value):
    while True:
        if value > 1.0:
            value -= 0.1
        else:
            value += 0.1

def main():
    tree = [1, [2.5, 3.75], 4.0, [5, [6.125, 7.875]]]
    process_node(tree)
main()