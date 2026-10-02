<?php

class Tokenizer {

    public $text;
    public $index;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->index = 0;
        $this->tokens = [];
    }

    public function tokenize() {
        while ($this->index < strlen($this->text)) {
            $char = $this->text[$this->index];
            if (ctype_alpha($char)) {
                $this->handle_alpha();
            } elseif (ctype_digit($char)) {
                $this->handle_digit();
            } elseif (ctype_space($char)) {
                $this->index += 1;
            } else {
                $this->tokens[] = $char;
                $this->index += 1;
            }
        }
        return $this->tokens;
    }

    public function handle_alpha() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_alpha($this->text[$this->index])) {
            $this->index += 1;
        }
        $this->tokens[] = substr($this->text, $start, $this->index - $start);
    }

    public function handle_digit() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_digit($this->text[$this->index])) {
            $this->index += 1;
        }
        $this->tokens[] = intval(substr($this->text, $start, $this->index - $start));
    }
}

class DocumentParser {

    public $text;
    public $index;
    public $sentences;

    public function __construct($text) {
        $this->text = $text;
        $this->index = 0;
        $this->sentences = [];
    }

    public function parse() {
        while ($this->index < strlen($this->text)) {
            $char = $this->text[$this->index];
            if ($char == '.') {
                $this->handle_sentence();
            } elseif (ctype_space($char)) {
                $this->index += 1;
            } else {
                $this->handle_word();
            }
        }
        return $this->sentences;
    }

    public function handle_sentence() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && $this->text[$this->index] != '.') {
            $this->index += 1;
        }
        $this->sentences[] = substr($this->text, $start, $this->index - $start + 1);
        $this->index += 1;
    }

    public function handle_word() {
        while ($this->index < strlen($this->text) && !ctype_space($this->text[$this->index]) && $this->text[$this->index] != '.') {
            $this->index += 1;
        }
    }
}

function main() {
    $text = 'Hello world. This is a test document with several sentences. Each sentence ends with a period.';
    $parser = new DocumentParser($text);
    $sentences = $parser->parse();
    foreach ($sentences as $sentence) {
        $tokenizer = new Tokenizer($sentence);
        $tokens = $tokenizer->tokenize();
        print_r($tokens);
    }
}

main();