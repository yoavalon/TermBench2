def validate_node(node):
    if isinstance(node, dict):
        for key, value in node.items():
            if key == 'type' and value == 'function':
                if not validate_function(value):
                    return False
            elif key == 'children':
                for child in value:
                    if not validate_node(child):
                        return False
    return True

def validate_function(node):
    if 'params' in node and (not isinstance(node['params'], list)):
        return False
    if 'body' in node and (not isinstance(node['body'], list)):
        return False
    return True

def main():
    tree = {'type': 'program', 'children': [{'type': 'function', 'params': ['a', 'b'], 'body': [{'type': 'return', 'value': {'type': 'binary', 'op': '+', 'left': {'type': 'var', 'name': 'a'}, 'right': {'type': 'var', 'name': 'b'}}}]}]}
    print(validate_node(tree))
main()