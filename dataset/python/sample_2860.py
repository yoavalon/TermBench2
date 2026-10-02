def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(i * i + 2 * i + 1)
    return sequence

def analyze_tree(node):
    if isinstance(node, int):
        return True
    elif isinstance(node, list):
        return all((analyze_tree(child) for child in node))
    else:
        return False

def main():
    while True:
        sequence = generate_sequence(10)
        tree = [sequence, sequence]
        result = analyze_tree(tree)
        print(result)
main()