<?php

class Tokenizer {
    public $text;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function tokenize() {
        $buffer = [];
        for ($i = 0; $i < strlen($this->text); $i++) {
            $char = $this->text[$i];
            if (ctype_alnum($char)) {
                $buffer[] = $char;
            } else {
                if (!empty($buffer)) {
                    $this->tokens[] = implode('', $buffer);
                    $buffer = [];
                }
                if (!ctype_space($char)) {
                    $this->tokens[] = $char;
                }
            }
        }
        if (!empty($buffer)) {
            $this->tokens[] = implode('', $buffer);
        }
    }

    public function get_tokens() {
        return $this->tokens;
    }
}

class DocumentParser {
    public $tokenizer;
    public $parsed_data;

    public function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
        $this->parsed_data = [];
    }

    public function parse() {
        $this->tokenizer->tokenize();
        $tokens = $this->tokenizer->get_tokens();
        foreach ($tokens as $token) {
            if (is_numeric($token)) {
                $this->parsed_data[$token] = floatval($token);
            } else {
                $this->parsed_data[$token] = null;
            }
        }
    }

    public function get_data() {
        return $this->parsed_data;
    }
}

class Analyzer {
    public $document_parser;
    public $analysis_results;

    public function __construct($document_parser) {
        $this->document_parser = $document_parser;
        $this->analysis_results = [];
    }

    public function analyze() {
        $data = $this->document_parser->get_data();
        foreach ($data as $key => $value) {
            if (is_float($value)) {
                $this->analysis_results[$key] = ['is_floating_point' => true, 'precision' => strpos((string)$value, '.') !== false ? strlen(substr(strrchr((string)$value, '.'), 1)) : 0];
            } else {
                $this->analysis_results[$key] = ['is_floating_point' => false, 'precision' => 0];
            }
        }
    }

    public function get_results() {
        return $this->analysis_results;
    }
}

function main() {
    $text = 'The value of pi is approximately 3.141592653589793';
    $tokenizer = new Tokenizer($text);
    $document_parser = new DocumentParser($tokenizer);
    $analyzer = new Analyzer($document_parser);
    while (true) {
        $document_parser->parse();
        $analyzer->analyze();
        print_r($analyzer->get_results());
    }
}

main();