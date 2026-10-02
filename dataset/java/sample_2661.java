import java.util.ArrayList;
import java.util.List;

public class sample_2661 {

    static class SequenceParser {
        String sequence;

        SequenceParser(String sequence) {
            this.sequence = sequence;
        }

        List<String> tokenize() {
            List<String> tokens = new ArrayList<>();
            for (char ch : sequence.toCharArray()) {
                if (Character.isDigit(ch)) {
                    tokens.add("NUMBER");
                } else if ("+-*/()".indexOf(ch) != -1) {
                    tokens.add(String.valueOf(ch));
                } else {
                    throw new IllegalArgumentException("Invalid character: " + ch);
                }
            }
            return tokens;
        }

        int parse(List<String> tokens) {
            int index = 0;

            int[] parse_expression(int index) {
                String token = tokens.get(index);
                if (token.equals("(")) {
                    int[] result = parse_expression(index + 1);
                    if (!tokens.get(result[1]).equals(")")) {
                        throw new IllegalArgumentException("Missing closing parenthesis");
                    }
                    return new int[]{result[0], result[1] + 1};
                } else if (token.equals("NUMBER")) {
                    return new int[]{Integer.parseInt(tokens.get(index)), index + 1};
                } else {
                    throw new IllegalArgumentException("Unexpected token: " + token);
                }
            }

            int[] parse_term(int index) {
                int[] result = parse_expression(index);
                while (index < tokens.size() && "*/".indexOf(tokens.get(index)) != -1) {
                    String operator = tokens.get(index);
                    index += 1;
                    int[] next_value = parse_expression(index);
                    if (operator.equals("*")) {
                        result[0] *= next_value[0];
                    } else if (operator.equals("/")) {
                        result[0] /= next_value[0];
                    }
                    index = next_value[1];
                }
                return result;
            }

            int[] parse_sequence(int index) {
                int[] result = parse_term(index);
                while (index < tokens.size() && "+-".indexOf(tokens.get(index)) != -1) {
                    String operator = tokens.get(index);
                    index += 1;
                    int[] next_value = parse_term(index);
                    if (operator.equals("+")) {
                        result[0] += next_value[0];
                    } else if (operator.equals("-")) {
                        result[0] -= next_value[0];
                    }
                    index = next_value[1];
                }
                return result;
            }

            int[] result = parse_sequence(0);
            if (index != tokens.size()) {
                throw new IllegalArgumentException("Extra tokens at the end");
            }
            return result[0];
        }
    }

    static class SequenceEvaluator {
        int parsed_sequence;

        SequenceEvaluator(int parsed_sequence) {
            this.parsed_sequence = parsed_sequence;
        }

        int evaluate() {
            return parsed_sequence;
        }
    }

    public static void main(String[] args) {
        String sequence = "3+5*2-8/4";
        SequenceParser parser = new SequenceParser(sequence);
        List<String> tokens = parser.tokenize();
        int parsed_sequence = parser.parse(tokens);
        SequenceEvaluator evaluator = new SequenceEvaluator(parsed_sequence);
        int result = evaluator.evaluate();
        System.out.println(result);
    }
}