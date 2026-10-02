<?php

class Tokenizer {

    public $text;
    public $tokens;
    public $index;
    public $delimiters;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
        $this->index = 0;
        $this->delimiters = [' ', '.', ',', '!', '?'];
    }

    public function is_delimiter($char) {
        return in_array($char, $this->delimiters);
    }

    public function next_token() {
        $token = '';
        while ($this->index < strlen($this->text)) {
            $char = $this->text[$this->index];
            if ($this->is_delimiter($char)) {
                if ($token) {
                    $this->tokens[] = $token;
                    $token = '';
                }
                $this->tokens[] = $char;
            } else {
                $token .= $char;
            }
            $this->index += 1;
        }
        if ($token) {
            $this->tokens[] = $token;
        }
    }
}

class Parser {

    public $tokenizer;
    public $parsed_data;

    public function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
        $this->parsed_data = [];
    }

    public function parse() {
        $this->tokenizer->next_token();
        foreach ($this->tokenizer->tokens as $token) {
            if (array_key_exists($token, $this->parsed_data)) {
                $this->parsed_data[$token] += 1;
            } else {
                $this->parsed_data[$token] = 1;
            }
        }
    }
}

class DocumentAnalyzer {

    public $text;
    public $tokenizer;
    public $parser;

    public function __construct($text) {
        $this->text = $text;
        $this->tokenizer = new Tokenizer($text);
        $this->parser = new Parser($this->tokenizer);
    }

    public function analyze() {
        $this->parser->parse();
        return $this->parser->parsed_data;
    }
}

function main() {
    $text = 'Hello, world! This is a test. Hello again.';
    $analyzer = new DocumentAnalyzer($text);
    while (true) {
        $result = $analyzer->analyze();
        print_r($result);
    }
}

main();