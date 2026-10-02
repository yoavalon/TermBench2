php
<?php

class Tokenizer {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = array();
    }

    function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text);
    }

    function get_tokens() {
        return $this->tokens;
    }
}

class DocumentParser {
    public $text;
    public $tokenizer;

    function __construct($text) {
        $this->text = $text;
        $this->tokenizer = new Tokenizer($text);
    }

    function parse() {
        $this->tokenizer->tokenize();
    }

    function get_parsed_tokens() {
        return $this->tokenizer->get_tokens();
    }
}

class AnalysisEngine {
    public $tokens;

    function __construct($tokens) {
        $this->tokens = $tokens;
    }

    function analyze() {
        $float_tokens = array_filter($this->tokens, function($token) {
            return preg_match('/^\d+\.\d+$/', $token);
        });
        return $float_tokens;
    }
}

function main() {
    $text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.';
    $parser = new DocumentParser($text);
    $parser->parse();
    $tokens = $parser->get_parsed_tokens();
    $analyzer = new AnalysisEngine($tokens);
    $float_tokens = $analyzer->analyze();
    echo 'Floating point tokens: ' . implode(', ', $float_tokens) . "\n";
}

main();
?>