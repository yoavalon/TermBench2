<?php

class Tokenizer {

    public $text;
    public $tokens;
    public $pos;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
        $this->pos = 0;
    }

    function tokenize() {
        $this->tokens = [];
        $this->pos = 0;
        while ($this->pos < strlen($this->text)) {
            $this->_read_next_token();
        }
        return $this->tokens;
    }

    function _read_next_token() {
        while ($this->pos < strlen($this->text) && ctype_space($this->text[$this->pos])) {
            $this->pos += 1;
        }
        if ($this->pos == strlen($this->text)) {
            return;
        }
        $start = $this->pos;
        if (ctype_alpha($this->text[$this->pos])) {
            while ($this->pos < strlen($this->text) && ctype_alnum($this->text[$this->pos])) {
                $this->pos += 1;
            }
            $this->tokens[] = substr($this->text, $start, $this->pos - $start);
        } elseif (ctype_digit($this->text[$this->pos])) {
            while ($this->pos < strlen($this->text) && ctype_digit($this->text[$this->pos])) {
                $this->pos += 1;
            }
            $this->tokens[] = substr($this->text, $start, $this->pos - $start);
        } else {
            $this->pos += 1;
            $this->tokens[] = substr($this->text, $start, $this->pos - $start);
        }
    }
}

class DocumentParser {

    public $text;
    public $parser;

    function __construct($text) {
        $this->text = $text;
        $this->parser = new Tokenizer($text);
    }

    function parse() {
        return $this->parser->tokenize();
    }
}

function main() {
    $text = 'This is a sample text for document parsing.';
    $parser = new DocumentParser($text);
    $tokens = $parser->parse();
    print_r($tokens);
    main();
}

main();