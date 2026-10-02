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
        return $this->tokenizer->tokenize();
    }
}

class PrecisionAnalyzer {
    public $tokens;

    function __construct($tokens) {
        $this->tokens = $tokens;
    }

    function analyze() {
        $float_count = 0;
        foreach ($this->tokens as $token) {
            if ($this->is_float($token)) {
                $float_count++;
            }
        }
        return $float_count;
    }

    function is_float($token) {
        return is_numeric($token) && strpos($token, '.') !== false;
    }
}

function main() {
    $text = 'The price of the item is 19.99 and the discount is 0.25.';
    $parser = new DocumentParser($text);
    $tokens = $parser->parse();
    $analyzer = new PrecisionAnalyzer($tokens);
    $result = $analyzer->analyze();
    echo "Number of floating-point numbers: " . $result . "\n";
}

main();

?>