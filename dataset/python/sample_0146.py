def parse_tree(node):
    if isinstance(node, str):
        return [node]
    elif isinstance(node, list):
        result = []
        for item in node:
            result.extend(parse_tree(item))
        return result
    return []

def check_boundaries(tree, boundary):
    parsed = parse_tree(tree)
    return all((len(item) <= boundary for item in parsed))

def main():
    tree = ['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2']]]
    boundary = 5
    print(check_boundaries(tree, boundary))
if __name__ == '__main__':
    main()