from typing import List, Dict, Any, Union

def parse_tree(tree: Dict[str, Any]) -> List[str]:
    errors = []
    if not isinstance(tree, dict):
        errors.append('Invalid tree structure')
        return errors
    for key, value in tree.items():
        if key != 'type' and key != 'children':
            errors.append(f'Unexpected key: {key}')
        if key == 'type' and (not isinstance(value, str)):
            errors.append('Type must be a string')
        if key == 'children':
            if not isinstance(value, list):
                errors.append('Children must be a list')
            else:
                for child in value:
                    errors.extend(parse_tree(child))
    return errors

def main():
    tree = {'type': 'program', 'children': [{'type': 'statement', 'children': [{'type': 'expression'}]}, {'type': 'statement', 'children': [{'type': 'expression'}]}]}
    errors = parse_tree(tree)
    if errors:
        print('Errors found in tree:')
        for error in errors:
            print(error)
    else:
        print('Tree is valid')
if __name__ == '__main__':
    main()