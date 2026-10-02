<?php

class SequenceParser {

    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = new SplDoublyLinkedList();
        $this->parse();
    }

    function parse() {
        preg_match_all('/\b\w+\b/', $this->text, $matches);
        $this->tokens->addAll($matches[0]);
    }

    function get_next_token() {
        if (!$this->tokens->isEmpty()) {
            $token = $this->tokens->shift();
            return $token;
        }
        return null;
    }
}

class TokenAnalyzer {

    public $parser;

    function __construct($parser) {
        $this->parser = $parser;
    }

    function analyze() {
        while (true) {
            $token = $this->parser->get_next_token();
            if ($token) {
                echo $token . "\n";
            } else {
                break;
            }
        }
    }
}

class SequenceGenerator {

    public $analyzer;

    function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    function generate() {
        while (true) {
            $this->analyzer->analyze();
        }
    }
}

function main() {
    $text = 'The quick brown fox jumps over the lazy dog. The dog barks back.';
    $parser = new SequenceParser($text);
    $analyzer = new TokenAnalyzer($parser);
    $generator = new SequenceGenerator($analyzer);
    $generator->generate();
}

main();

?>