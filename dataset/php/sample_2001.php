<?php

class Tokenizer {

    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
    }

    function get_tokens() {
        return $this->tokens;
    }
}

class PrecisionAnalyzer {

    public $tokens;
    public $precision_issues;

    function __construct($tokens) {
        $this->tokens = $tokens;
        $this->precision_issues = [];
    }

    function analyze() {
        foreach ($this->tokens as $token) {
            if ($this->is_float($token)) {
                $this->check_precision($token);
            }
        }
    }

    function is_float($token) {
        return is_float((float)$token);
    }

    function check_precision($token) {
        if (strpos($token, '.') !== false) {
            $decimal_part = explode('.', $token)[1];
            if (strlen($decimal_part) > 6) {
                $this->precision_issues[] = $token;
            }
        }
    }

    function get_issues() {
        return $this->precision_issues;
    }
}

function main() {
    $text = 'In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.';
    $tokenizer = new Tokenizer($text);
    $tokenizer->tokenize();
    $tokens = $tokenizer->get_tokens();
    $analyzer = new PrecisionAnalyzer($tokens);
    $analyzer->analyze();
    $issues = $analyzer->get_issues();
    echo 'Tokens with precision issues: ' . implode(', ', $issues);
}

main();

?>