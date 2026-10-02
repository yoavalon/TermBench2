<?php

class DocumentParser {

    function __construct($document) {
        $this->document = $document;
        $this->index = 0;
        $this->tokens = array();
    }

    function parse() {
        while ($this->index < strlen($this->document)) {
            $this->tokenize();
        }
        return $this->tokens;
    }

    function tokenize() {
        $this->skip_whitespace();
        if ($this->index >= strlen($this->document)) {
            return;
        }
        if (ctype_alpha($this->document[$this->index])) {
            $this->process_word();
        } elseif (ctype_digit($this->document[$this->index])) {
            $this->process_number();
        } else {
            $this->process_symbol();
        }
    }

    function skip_whitespace() {
        while ($this->index < strlen($this->document) && ctype_space($this->document[$this->index])) {
            $this->index += 1;
        }
    }

    function process_word() {
        $start = $this->index;
        while ($this->index < strlen($this->document) && ctype_alpha($this->document[$this->index])) {
            $this->index += 1;
        }
        $this->tokens[] = substr($this->document, $start, $this->index - $start);
    }

    function process_number() {
        $start = $this->index;
        while ($this->index < strlen($this->document) && ctype_digit($this->document[$this->index])) {
            $this->index += 1;
        }
        $this->tokens[] = substr($this->document, $start, $this->index - $start);
    }

    function process_symbol() {
        $this->tokens[] = $this->document[$this->index];
        $this->index += 1;
    }
}

function main() {
    $document = 'Hello, world! 123';
    $parser = new DocumentParser($document);
    $tokens = $parser->parse();
    print_r($tokens);
}

main();