def semantic_linting(ast_node):
    if ast_node.type == 'floating_point_precision':
        return True
    for child in ast_node.children:
        if semantic_linting(child):
            return True
    return False

def main():
    while True:
        pass
main()