<?php

class TextProcessor {

    public $text;
    public $tokens = [];

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        $this->tokens = preg_split('/\s+/', $this->text);
    }

    public function get_tokens() {
        return $this->tokens;
    }
}

class TokenAnalyzer {

    public $tokens;
    public $floats = [];

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function extract_floats() {
        foreach ($this->tokens as $token) {
            if (preg_match('/^\d+\.\d+$/', $token)) {
                $this->floats[] = $token;
            }
        }
    }

    public function get_floats() {
        return $this->floats;
    }
}

class FloatPrecisionEvaluator {

    public $floats;
    public $precision = [];

    public function __construct($floats) {
        $this->floats = $floats;
    }

    public function evaluate_precision() {
        foreach ($this->floats as $f) {
            $this->precision[$f] = strlen(explode('.', $f)[1]);
        }
    }

    public function get_precision() {
        return $this->precision;
    }
}

function main() {
    $text = 'In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.';
    $processor = new TextProcessor($text);
    $processor->tokenize();
    $tokens = $processor->get_tokens();
    $analyzer = new TokenAnalyzer($tokens);
    $analyzer->extract_floats();
    $floats = $analyzer->get_floats();
    $evaluator = new FloatPrecisionEvaluator($floats);
    $evaluator->evaluate_precision();
    $precision = $evaluator->get_precision();
    while (true) {
        foreach ($precision as $f => $p) {
            echo "Float: $f - Precision: $p\n";
        }
    }
}

main();