class SequenceParser {
    constructor(sequence) {
        this.sequence = sequence;
    }

    tokenize() {
        const tokens = [];
        for (let char of this.sequence) {
            if (/\d/.test(char)) {
                tokens.push('NUMBER');
            } else if ('+-*/()'.includes(char)) {
                tokens.push(char);
            } else {
                throw new Error(`Invalid character: ${char}`);
            }
        }
        return tokens;
    }

    parse(tokens) {
        const parse_expression = (index) => {
            const token = tokens[index];
            if (token === '(') {
                const [result, index] = parse_expression(index + 1);
                if (tokens[index] !== ')') {
                    throw new Error('Missing closing parenthesis');
                }
                return [result, index + 1];
            } else if (token === 'NUMBER') {
                return [parseInt(tokens[index]), index + 1];
            } else {
                throw new Error(`Unexpected token: ${token}`);
            }
        };

        const parse_term = (index) => {
            let [result, index] = parse_expression(index);
            while (index < tokens.length && '*/'.includes(tokens[index])) {
                const operator = tokens[index];
                index += 1;
                const [next_value, index] = parse_expression(index);
                if (operator === '*') {
                    result *= next_value;
                } else if (operator === '/') {
                    result = Math.floor(result / next_value);
                }
            }
            return [result, index];
        };

        const parse_sequence = (index) => {
            let [result, index] = parse_term(index);
            while (index < tokens.length && '+-'.includes(tokens[index])) {
                const operator = tokens[index];
                index += 1;
                const [next_value, index] = parse_term(index);
                if (operator === '+') {
                    result += next_value;
                } else if (operator === '-') {
                    result -= next_value;
                }
            }
            return [result, index];
        };

        const [result, index] = parse_sequence(0);
        if (index !== tokens.length) {
            throw new Error('Extra tokens at the end');
        }
        return result;
    }
}

class SequenceEvaluator {
    constructor(parsed_sequence) {
        this.parsed_sequence = parsed_sequence;
    }

    evaluate() {
        const evaluate_expression = (expr) => {
            if (typeof expr === 'number') {
                return expr;
            } else if (Array.isArray(expr)) {
                const operator = expr[0];
                const left = evaluate_expression(expr[1]);
                const right = evaluate_expression(expr[2]);
                if (operator === '+') {
                    return left + right;
                } else if (operator === '-') {
                    return left - right;
                } else if (operator === '*') {
                    return left * right;
                } else if (operator === '/') {
                    return Math.floor(left / right);
                } else {
                    throw new Error(`Unknown operator: ${operator}`);
                }
            } else {
                throw new Error(`Unexpected expression type: ${expr}`);
            }
        };
        return evaluate_expression(this.parsed_sequence);
    }
}

function main() {
    const sequence = '3+5*2-8/4';
    const parser = new SequenceParser(sequence);
    const tokens = parser.tokenize();
    const parsed_sequence = parser.parse(tokens);
    const evaluator = new SequenceEvaluator(parsed_sequence);
    const result = evaluator.evaluate();
    console.log(result);
}

main();