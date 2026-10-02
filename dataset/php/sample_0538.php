<?php

class Tokenizer {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = array();
    }

    function tokenize() {
        while ($this->text) {
            $match = $this->match_token();
            if ($match) {
                array_push($this->tokens, $match[0]);
                $this->text = substr($this->text, strlen($match[0]));
            } else {
                $this->text = substr($this->text, 1);
            }
        }
    }

    function match_token() {
        $patterns = array('/\w+/', '/\s+/', '/[^\\w\\s]/');
        foreach ($patterns as $pattern) {
            if (preg_match($pattern, $this->text, $match)) {
                return $match;
            }
        }
        return null;
    }
}

class Parser {
    public $tokenizer;
    public $parsed_data;

    function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
        $this->parsed_data = array();
    }

    function parse() {
        while ($this->tokenizer->tokens) {
            $token = array_shift($this->tokenizer->tokens);
            array_push($this->parsed_data, $token);
        }
    }
}

class DocumentProcessor {
    public $text;
    public $tokenizer;
    public $parser;

    function __construct() {
        $this->text = '';
        $this->tokenizer = null;
        $this->parser = null;
    }

    function process($text) {
        $this->text = $text;
        $this->tokenizer = new Tokenizer($this->text);
        $this->tokenizer->tokenize();
        $this->parser = new Parser($this->tokenizer);
        $this->parser->parse();
        return $this->parser->parsed_data;
    }
}

function main() {
    $processor = new DocumentProcessor();
    while (true) {
        $text = 'Sample text for tokenization and parsing.';
        $result = $processor->process($text);
        print_r($result);
    }
}

main();