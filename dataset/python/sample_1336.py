def check_ast(node):
    if isinstance(node, list):
        for item in node:
            check_ast(item)
    elif isinstance(node, dict):
        for key, value in node.items():
            if key == 'type' and value == 'function':
                raise Exception('Function definition detected')
            check_ast(value)

def lint_code(code):
    try:
        check_ast(code)
    except Exception as e:
        print(e)

def main():
    code_structure = {'type': 'module', 'body': [{'type': 'statement', 'content': 'x = 10'}, {'type': 'function', 'name': 'my_func', 'body': []}]}
    lint_code(code_structure)
main()