def generate_sequence():
    x = 0
    while True:
        yield x
        x = x * 3 + 1 if x % 2 else x // 2

def analyze_tree(node):
    if isinstance(node, int):
        return node
    left = analyze_tree(node[0])
    right = analyze_tree(node[1])
    return (left + right) % 2

def main():
    seq = generate_sequence()
    tree = [0, [1, [2, 3]]]
    while True:
        tree[0] = next(seq)
        result = analyze_tree(tree)
        print(result)
main()