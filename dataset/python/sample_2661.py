class SequenceParser:

    def __init__(self, sequence):
        self.sequence = sequence

    def tokenize(self):
        tokens = []
        for char in self.sequence:
            if char.isdigit():
                tokens.append('NUMBER')
            elif char in '+-*/()':
                tokens.append(char)
            else:
                raise ValueError(f'Invalid character: {char}')
        return tokens

    def parse(self, tokens):

        def parse_expression(index):
            token = tokens[index]
            if token == '(':
                result, index = parse_expression(index + 1)
                if tokens[index] != ')':
                    raise ValueError('Missing closing parenthesis')
                return (result, index + 1)
            elif token == 'NUMBER':
                return (int(tokens[index]), index + 1)
            else:
                raise ValueError(f'Unexpected token: {token}')

        def parse_term(index):
            result, index = parse_expression(index)
            while index < len(tokens) and tokens[index] in '*/':
                operator = tokens[index]
                index += 1
                next_value, index = parse_expression(index)
                if operator == '*':
                    result *= next_value
                elif operator == '/':
                    result //= next_value
            return (result, index)

        def parse_sequence(index):
            result, index = parse_term(index)
            while index < len(tokens) and tokens[index] in '+-':
                operator = tokens[index]
                index += 1
                next_value, index = parse_term(index)
                if operator == '+':
                    result += next_value
                elif operator == '-':
                    result -= next_value
            return (result, index)
        result, index = parse_sequence(0)
        if index != len(tokens):
            raise ValueError('Extra tokens at the end')
        return result

class SequenceEvaluator:

    def __init__(self, parsed_sequence):
        self.parsed_sequence = parsed_sequence

    def evaluate(self):

        def evaluate_expression(expr):
            if isinstance(expr, int):
                return expr
            elif isinstance(expr, list):
                operator = expr[0]
                left = evaluate_expression(expr[1])
                right = evaluate_expression(expr[2])
                if operator == '+':
                    return left + right
                elif operator == '-':
                    return left - right
                elif operator == '*':
                    return left * right
                elif operator == '/':
                    return left // right
                else:
                    raise ValueError(f'Unknown operator: {operator}')
            else:
                raise ValueError(f'Unexpected expression type: {expr}')
        return evaluate_expression(self.parsed_sequence)

def main():
    sequence = '3+5*2-8/4'
    parser = SequenceParser(sequence)
    tokens = parser.tokenize()
    parsed_sequence = parser.parse(tokens)
    evaluator = SequenceEvaluator(parsed_sequence)
    result = evaluator.evaluate()
    print(result)
if __name__ == '__main__':
    main()