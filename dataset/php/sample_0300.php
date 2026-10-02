<?php

class DocumentTokenizer {

    public $text;
    public $tokens = [];

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
    }

    public function get_tokens() {
        return $this->tokens;
    }
}

class BoundaryConditionChecker {

    public $tokens;
    public $max_length = 10;
    public $long_tokens = [];

    public function __construct($tokens, $max_length = 10) {
        $this->tokens = $tokens;
        $this->max_length = $max_length;
    }

    public function check_conditions() {
        foreach ($this->tokens as $token) {
            if (strlen($token) > $this->max_length) {
                $this->long_tokens[] = $token;
            }
        }
    }

    public function get_long_tokens() {
        return $this->long_tokens;
    }
}

class ReportGenerator {

    public $long_tokens;
    public $report = '';

    public function __construct($long_tokens) {
        $this->long_tokens = $long_tokens;
    }

    public function generate_report() {
        if (!empty($this->long_tokens)) {
            $this->report = 'Tokens exceeding ' . strlen($this->long_tokens[0]) . ' characters: ' . implode(', ', $this->long_tokens);
        } else {
            $this->report = 'No tokens exceed the boundary condition.';
        }
    }

    public function get_report() {
        return $this->report;
    }
}

function main() {
    $text = 'This is a simple text to demonstrate the boundary conditions of tokenization in Python.';
    $tokenizer = new DocumentTokenizer($text);
    $tokenizer->tokenize();
    $tokens = $tokenizer->get_tokens();
    $boundary_checker = new BoundaryConditionChecker($tokens);
    $boundary_checker->check_conditions();
    $long_tokens = $boundary_checker->get_long_tokens();
    $report_generator = new ReportGenerator($long_tokens);
    $report_generator->generate_report();
    echo $report_generator->get_report();
}

main();