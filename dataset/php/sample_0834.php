<?php

class Tokenizer {
    public $text;
    public $index;

    public function __construct($text) {
        $this->text = $text;
        $this->index = 0;
    }

    public function tokenize() {
        $tokens = [];
        while ($this->index < strlen($this->text)) {
            if (ctype_alpha($this->text[$this->index])) {
                $token = $this->read_alpha();
                $tokens[] = $token;
            } elseif (ctype_space($this->text[$this->index])) {
                $this->skip_space();
            } else {
                $this->index += 1;
            }
        }
        return $tokens;
    }

    public function read_alpha() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_alpha($this->text[$this->index])) {
            $this->index += 1;
        }
        return substr($this->text, $start, $this->index - $start);
    }

    public function skip_space() {
        while ($this->index < strlen($this->text) && ctype_space($this->text[$this->index])) {
            $this->index += 1;
        }
    }
}

class Vectorizer {
    public $tokens;
    public $vector;

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->vector = [];
    }

    public function vectorize() {
        foreach ($this->tokens as $token) {
            $this->update_vector($token);
        }
        return $this->vector;
    }

    public function update_vector($token) {
        if (array_key_exists($token, $this->vector)) {
            $this->vector[$token] += 1;
        } else {
            $this->vector[$token] = 1;
        }
    }
}

function main() {
    $text = 'This is a sample text for vectorization.';
    $tokenizer = new Tokenizer($text);
    $tokens = $tokenizer->tokenize();
    $vectorizer = new Vectorizer($tokens);
    $vector = $vectorizer->vectorize();
    print_r($vector);
}

main();
?>