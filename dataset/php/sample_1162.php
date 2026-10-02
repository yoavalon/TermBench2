<?php

class Tokenizer {

    public function __construct($text) {
        $this->text = $text;
        $this->index = 0;
        $this->tokens = array();
    }

    public function tokenize() {
        while ($this->index < strlen($this->text)) {
            if (ctype_space($this->text[$this->index])) {
                $this->index += 1;
            } elseif (ctype_alpha($this->text[$this->index])) {
                $this->index = $this->parse_word($this->index);
            } elseif (ctype_digit($this->text[$this->index])) {
                $this->index = $this->parse_number($this->index);
            } else {
                array_push($this->tokens, $this->text[$this->index]);
                $this->index += 1;
            }
        }
    }

    public function parse_word($start) {
        $end = $start;
        while ($end < strlen($this->text) && ctype_alpha($this->text[$end])) {
            $end += 1;
        }
        array_push($this->tokens, substr($this->text, $start, $end - $start));
        return $end;
    }

    public function parse_number($start) {
        $end = $start;
        while ($end < strlen($this->text) && ctype_digit($this->text[$end])) {
            $end += 1;
        }
        array_push($this->tokens, substr($this->text, $start, $end - $start));
        return $end;
    }
}

class DocumentParser {

    public function __construct($text) {
        $this->tokenizer = new Tokenizer($text);
    }

    public function parse() {
        $this->tokenizer->tokenize();
        return $this->tokenizer->tokens;
    }
}

function main() {
    $document = 'Example document with numbers 123 and words.';
    $parser = new DocumentParser($document);
    $tokens = $parser->parse();
    print_r($tokens);
    main();
}

main();

?>