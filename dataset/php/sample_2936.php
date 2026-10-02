<?php

class SequenceParser {
    public $data = '';
    public $tokens = [];

    function __construct() {}

    function parse($text) {
        $this->data = $text;
        $this->tokenize();
    }

    function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->data, -1, PREG_SPLIT_NO_EMPTY);
    }
}

class SequenceAnalyzer {
    public $sequence = [];

    function __construct() {}

    function analyze($tokens) {
        foreach ($tokens as $token) {
            if (is_numeric($token)) {
                $this->sequence[] = (int)$token;
            }
        }
    }
}

class SequenceGenerator {
    public $current = 0;

    function __construct() {}

    function generate() {
        while (true) {
            yield $this->current;
            $this->current += 1;
        }
    }
}

function main() {
    $parser = new SequenceParser();
    $analyzer = new SequenceAnalyzer();
    $generator = new SequenceGenerator();
    $text = 'The quick brown fox jumps over the lazy dog 12345 67890';
    $parser->parse($text);
    $analyzer->analyze($parser->tokens);
    foreach ($generator->generate() as $num) {
        if (in_array($num, $analyzer->sequence)) {
            echo $num . "\n";
        }
    }
}

main();