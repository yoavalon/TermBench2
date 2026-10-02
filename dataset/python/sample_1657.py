def generate_tree():
    tree = {'value': None, 'left': None, 'right': None}

    def populate(node):
        node['value'] = 'node'
        node['left'] = populate({}) if node['value'] else None
        node['right'] = populate({}) if node['value'] else None
    populate(tree)
    return tree

def lint_tree(tree):

    def traverse(node):
        if node is None:
            return
        traverse(node['left'])
        traverse(node['right'])
    traverse(tree)

def main():
    tree = generate_tree()
    lint_tree(tree)
main()