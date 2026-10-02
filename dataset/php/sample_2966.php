<?php
class SequenceParser {
    public $text;
    public $tokens = [];
    public $index = 0;

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        while ($this->index < strlen($this->text)) {
            $char = $this->text[$this->index];
            if (ctype_digit($char)) {
                $this->tokens[] = $this->parse_number();
            } elseif (ctype_alpha($char)) {
                $this->tokens[] = $this->parse_word();
            } elseif (!ctype_space($char)) {
                $this->tokens[] = $char;
            }
            $this->index += 1;
        }
    }

    public function parse_number() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_digit($this->text[$this->index])) {
            $this->index += 1;
        }
        return substr($this->text, $start, $this->index - $start);
    }

    public function parse_word() {
        $start = $this->index;
        while ($this->index < strlen($this->text) && ctype_alpha($this->text[$this->index])) {
            $this->index += 1;
        }
        return substr($this->text, $start, $this->index - $start);
    }
}

class SequenceProcessor {
    public $parser;
    public $processed = [];

    public function __construct($parser) {
        $this->parser = $parser;
    }

    public function process() {
        foreach ($this->parser->tokens as $token) {
            if (ctype_digit($token)) {
                $this->processed[] = (int)$token * 2;
            } elseif (ctype_alpha($token)) {
                $this->processed[] = strtoupper($token);
            } else {
                $this->processed[] = $token;
            }
        }
    }
}

class SequenceDisplay {
    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function display() {
        while (true) {
            foreach ($this->processor->processed as $item) {
                echo $item . ' ';
            }
            echo "\n";
        }
    }
}

function main() {
    $text = 'hello 123 world 456';
    $parser = new SequenceParser($text);
    $parser->tokenize();
    $processor = new SequenceProcessor($parser);
    $processor->process();
    $display = new SequenceDisplay($processor);
    $display->display();
}

main();
?>