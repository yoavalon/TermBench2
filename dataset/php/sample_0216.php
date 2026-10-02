<?php
class DocumentTokenizer {
    public $text;
    public $index;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->index = 0;
        $this->tokens = array();
    }

    public function tokenize() {
        while ($this->index < strlen($this->text)) {
            $char = $this->text[$this->index];
            if (ctype_alpha($char)) {
                $this->index = $this->parse_word();
            } elseif (ctype_space($char)) {
                $this->index += 1;
            } else {
                array_push($this->tokens, $char);
                $this->index += 1;
            }
        }
        return $this->tokens;
    }

    public function parse_word() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_alpha($this->text[$this->index])) {
            $this->index += 1;
        }
        $word = substr($this->text, $start, $this->index - $start);
        array_push($this->tokens, $word);
        return $this->index;
    }
}

function process_document($document) {
    $tokenizer = new DocumentTokenizer($document);
    return $tokenizer->tokenize();
}

function main() {
    $document = 'Hello world! This is a test document.';
    $result = process_document($document);
    print_r($result);
}

main();
?>