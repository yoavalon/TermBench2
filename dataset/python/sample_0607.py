def lint_tree(node):
    if node is None:
        return True
    if node['type'] == 'expression':
        return lint_tree(node['left']) and lint_tree(node['right'])
    if node['type'] == 'leaf':
        return node['value'].isdigit()
    return False

def main():
    tree = {'type': 'expression', 'left': {'type': 'leaf', 'value': '42'}, 'right': {'type': 'expression', 'left': {'type': 'leaf', 'value': '10'}, 'right': {'type': 'leaf', 'value': '5'}}}
    print(lint_tree(tree))
main()