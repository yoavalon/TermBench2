class SequenceParser {
    sequence: string;

    constructor(sequence: string) {
        this.sequence = sequence;
    }

    tokenize(): string[] {
        const tokens: string[] = [];
        for (const char of this.sequence) {
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

    parse(tokens: string[]): number {
        const parse_expression = (index: number): [number, number] => {
            const token = tokens[index];
            if (token === '(') {
                const [result, newIndex] = parse_expression(index + 1);
                if (tokens[newIndex] !== ')') {
                    throw new Error('Missing closing parenthesis');
                }
                return [result, newIndex + 1];
            } else if (token === 'NUMBER') {
                return [parseInt(tokens[index], 10), index + 1];
            } else {
                throw new Error(`Unexpected token: ${token}`);
            }
        };

        const parse_term = (index: number): [number, number] => {
            let [result, newIndex] = parse_expression(index);
            while (newIndex < tokens.length && '*/'.includes(tokens[newIndex])) {
                const operator = tokens[newIndex];
                newIndex += 1;
                const [nextValue, nextIndex] = parse_expression(newIndex);
                if (operator === '*') {
                    result *= nextValue;
                } else if (operator === '/') {
                    result = Math.floor(result / nextValue);
                }
                newIndex = nextIndex;
            }
            return [result, newIndex];
        };

        const parse_sequence = (index: number): [number, number] => {
            let [result, newIndex] = parse_term(index);
            while (newIndex < tokens.length && '+-'.includes(tokens[newIndex])) {
                const operator = tokens[newIndex];
                newIndex += 1;
                const [nextValue, nextIndex] = parse_term(newIndex);
                if (operator === '+') {
                    result += nextValue;
                } else if (operator === '-') {
                    result -= nextValue;
                }
                newIndex = nextIndex;
            }
            return [result, newIndex];
        };

        const [result, index] = parse_sequence(0);
        if (index !== tokens.length) {
            throw new Error('Extra tokens at the end');
        }
        return result;
    }
}

class SequenceEvaluator {
    parsed_sequence: number;

    constructor(parsed_sequence: number) {
        this.parsed_sequence = parsed_sequence;
    }

    evaluate(): number {
        const evaluate_expression = (expr: number | [string, number, number]): number => {
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

if (require.main === module) {
    main();
}