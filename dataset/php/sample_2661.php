<?php

class SequenceParser {

    private $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function tokenize() {
        $tokens = [];
        for ($i = 0; $i < strlen($this->sequence); $i++) {
            $char = $this->sequence[$i];
            if (ctype_digit($char)) {
                $tokens[] = 'NUMBER';
            } elseif (strpos('+-*/()', $char) !== false) {
                $tokens[] = $char;
            } else {
                throw new Exception("Invalid character: $char");
            }
        }
        return $tokens;
    }

    public function parse($tokens) {

        $parse_expression = function($index) use ($tokens, &$parse_expression, &$parse_term, &$parse_sequence) {
            $token = $tokens[$index];
            if ($token == '(') {
                list($result, $index) = $parse_expression($index + 1);
                if ($tokens[$index] != ')') {
                    throw new Exception('Missing closing parenthesis');
                }
                return [$result, $index + 1];
            } elseif ($token == 'NUMBER') {
                return [(int)$tokens[$index], $index + 1];
            } else {
                throw new Exception("Unexpected token: $token");
            }
        };

        $parse_term = function($index) use ($tokens, &$parse_expression, &$parse_term, &$parse_sequence) {
            list($result, $index) = $parse_expression($index);
            while ($index < count($tokens) && strpos('*/', $tokens[$index]) !== false) {
                $operator = $tokens[$index];
                $index += 1;
                list($next_value, $index) = $parse_expression($index);
                if ($operator == '*') {
                    $result *= $next_value;
                } elseif ($operator == '/') {
                    $result = intdiv($result, $next_value);
                }
            }
            return [$result, $index];
        };

        $parse_sequence = function($index) use ($tokens, &$parse_expression, &$parse_term, &$parse_sequence) {
            list($result, $index) = $parse_term($index);
            while ($index < count($tokens) && strpos('+-', $tokens[$index]) !== false) {
                $operator = $tokens[$index];
                $index += 1;
                list($next_value, $index) = $parse_term($index);
                if ($operator == '+') {
                    $result += $next_value;
                } elseif ($operator == '-') {
                    $result -= $next_value;
                }
            }
            return [$result, $index];
        };

        list($result, $index) = $parse_sequence(0);
        if ($index != count($tokens)) {
            throw new Exception('Extra tokens at the end');
        }
        return $result;
    }
}

class SequenceEvaluator {

    private $parsed_sequence;

    public function __construct($parsed_sequence) {
        $this->parsed_sequence = $parsed_sequence;
    }

    public function evaluate() {

        $evaluate_expression = function($expr) use (&$evaluate_expression) {
            if (is_int($expr)) {
                return $expr;
            } elseif (is_array($expr)) {
                $operator = $expr[0];
                $left = $evaluate_expression($expr[1]);
                $right = $evaluate_expression($expr[2]);
                if ($operator == '+') {
                    return $left + $right;
                } elseif ($operator == '-') {
                    return $left - $right;
                } elseif ($operator == '*') {
                    return $left * $right;
                } elseif ($operator == '/') {
                    return intdiv($left, $right);
                } else {
                    throw new Exception("Unknown operator: $operator");
                }
            } else {
                throw new Exception("Unexpected expression type: $expr");
            }
        };

        return $evaluate_expression($this->parsed_sequence);
    }
}

function main() {
    $sequence = '3+5*2-8/4';
    $parser = new SequenceParser($sequence);
    $tokens = $parser->tokenize();
    $parsed_sequence = $parser->parse($tokens);
    $evaluator = new SequenceEvaluator($parsed_sequence);
    $result = $evaluator->evaluate();
    echo $result;
}

main();