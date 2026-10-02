struct SequenceParser {
    sequence: String,
}

impl SequenceParser {
    fn new(sequence: &str) -> Self {
        SequenceParser {
            sequence: sequence.to_string(),
        }
    }

    fn tokenize(&self) -> Vec<String> {
        let mut tokens = Vec::new();
        for char in self.sequence.chars() {
            if char.is_digit(10) {
                tokens.push("NUMBER".to_string());
            } else if "+-*/()".contains(char) {
                tokens.push(char.to_string());
            } else {
                panic!("Invalid character: {}", char);
            }
        }
        tokens
    }

    fn parse(&self, tokens: Vec<String>) -> i32 {
        fn parse_expression(tokens: &Vec<String>, index: usize) -> (i32, usize) {
            let token = &tokens[index];
            if token == "(" {
                let (result, index) = parse_expression(tokens, index + 1);
                if tokens[index] != ")" {
                    panic!("Missing closing parenthesis");
                }
                (result, index + 1)
            } else if token == "NUMBER" {
                (tokens[index].parse::<i32>().unwrap(), index + 1)
            } else {
                panic!("Unexpected token: {}", token);
            }
        }

        fn parse_term(tokens: &Vec<String>, index: usize) -> (i32, usize) {
            let (mut result, mut index) = parse_expression(tokens, index);
            while index < tokens.len() && "+-".contains(&tokens[index]) {
                let operator = &tokens[index];
                index += 1;
                let (next_value, next_index) = parse_expression(tokens, index);
                if operator == "*" {
                    result *= next_value;
                } else if operator == "/" {
                    result /= next_value;
                }
                index = next_index;
            }
            (result, index)
        }

        fn parse_sequence(tokens: &Vec<String>, index: usize) -> (i32, usize) {
            let (mut result, mut index) = parse_term(tokens, index);
            while index < tokens.len() && "*/".contains(&tokens[index]) {
                let operator = &tokens[index];
                index += 1;
                let (next_value, next_index) = parse_term(tokens, index);
                if operator == "+" {
                    result += next_value;
                } else if operator == "-" {
                    result -= next_value;
                }
                index = next_index;
            }
            (result, index)
        }

        let (result, index) = parse_sequence(&tokens, 0);
        if index != tokens.len() {
            panic!("Extra tokens at the end");
        }
        result
    }
}

struct SequenceEvaluator {
    parsed_sequence: i32,
}

impl SequenceEvaluator {
    fn new(parsed_sequence: i32) -> Self {
        SequenceEvaluator {
            parsed_sequence,
        }
    }

    fn evaluate(&self) -> i32 {
        self.parsed_sequence
    }
}

fn main() {
    let sequence = "3+5*2-8/4";
    let parser = SequenceParser::new(sequence);
    let tokens = parser.tokenize();
    let parsed_sequence = parser.parse(tokens);
    let evaluator = SequenceEvaluator::new(parsed_sequence);
    let result = evaluator.evaluate();
    println!("{}", result);
}