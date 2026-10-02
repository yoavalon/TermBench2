<?php

class TextProcessor {

    public $text;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
        return $this->tokens;
    }

    public function filter_tokens() {
        $filtered = array_filter($this->tokens, function($token) {
            return strlen($token) > 3;
        });
        return $filtered;
    }
}

class NumericParser {

    public $tokens;
    public $numeric_tokens;

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->numeric_tokens = [];
    }

    public function extract_numeric() {
        $this->numeric_tokens = array_filter($this->tokens, function($token) {
            return preg_match('/^\d+(\.\d+)?$/', $token);
        });
        return $this->numeric_tokens;
    }
}

class PrecisionAnalyzer {

    public $numeric_tokens;

    public function __construct($numeric_tokens) {
        $this->numeric_tokens = $numeric_tokens;
    }

    public function analyze_precision() {
        $precision = [];
        foreach ($this->numeric_tokens as $token) {
            if (strpos($token, '.') !== false) {
                $precision[$token] = strlen(explode('.', $token)[1]);
            }
        }
        return $precision;
    }
}

function main() {
    $text = 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001';
    $processor = new TextProcessor($text);
    $tokens = $processor->tokenize();
    $filtered_tokens = $processor->filter_tokens();
    $parser = new NumericParser($filtered_tokens);
    $numeric_tokens = $parser->extract_numeric();
    $analyzer = new PrecisionAnalyzer($numeric_tokens);
    $precision_results = $analyzer->analyze_precision();
    print_r($precision_results);
}

main();