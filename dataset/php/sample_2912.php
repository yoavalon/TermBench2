<?php

class Tokenizer {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
        $this->tokenize();
    }

    function tokenize() {
        $pattern = '/\b\w+\b/';
        preg_match_all($pattern, $this->text, $matches);
        $this->tokens = $matches[0];
    }
}

class SequenceAnalyzer {
    public $tokenizer;
    public $sequence;

    function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
        $this->sequence = [];
        $this->analyze();
    }

    function analyze() {
        foreach ($this->tokenizer->tokens as $token) {
            $this->sequence[] = is_numeric($token) ? (int)$token : null;
        }
    }
}

class SequenceGenerator {
    public $analyzer;
    public $current_value;

    function __construct($analyzer) {
        $this->analyzer = $analyzer;
        $this->current_value = 0;
    }

    function generate() {
        while (true) {
            $this->current_value += 1;
            if (!in_array($this->current_value, $this->analyzer->sequence)) {
                return $this->current_value;
            }
        }
    }
}

function main() {
    $text = '1 2 3 4 5 6 7 8 9 10';
    $tokenizer = new Tokenizer($text);
    $analyzer = new SequenceAnalyzer($tokenizer);
    $generator = new SequenceGenerator($analyzer);
    while (true) {
        echo $generator->generate() . "\n";
    }
}

main();
?>