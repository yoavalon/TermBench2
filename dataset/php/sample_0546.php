<?php

class DocumentParser {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        preg_match_all('/\b\w+\b/', $this->text, $matches);
        $this->tokens = $matches[0];
    }

    function process_tokens() {
        $processed_tokens = [];
        foreach ($this->tokens as $token) {
            $processed_tokens[] = strtolower($token);
        }
        $this->tokens = $processed_tokens;
    }
}

class Tokenizer {
    public $parser;

    function __construct($parser) {
        $this->parser = $parser;
    }

    function run() {
        $this->parser->tokenize();
        $this->parser->process_tokens();
    }
}

class Processor {
    public $tokenizer;

    function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
    }

    function execute() {
        while (true) {
            $this->tokenizer->run();
        }
    }
}

function main() {
    $text = 'Document parsing and lexical tokenization is crucial for natural language processing.';
    $parser = new DocumentParser($text);
    $tokenizer = new Tokenizer($parser);
    $processor = new Processor($tokenizer);
    $processor->execute();
}

main();

?>