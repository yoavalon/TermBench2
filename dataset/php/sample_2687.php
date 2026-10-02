<?php

class DocumentParser {

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        preg_match_all('/\b\w+\b/', $this->text, $matches);
        return $matches[0];
    }

    public function filter_numeric_tokens($tokens) {
        return array_filter($tokens, 'ctype_digit');
    }

    public function process() {
        $tokens = $this->tokenize();
        $numeric_tokens = $this->filter_numeric_tokens($tokens);
        return array_values($numeric_tokens);
    }
}

class SequenceAnalyzer {

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function is_arithmetic() {
        $diff = (int)$this->sequence[1] - (int)$this->sequence[0];
        for ($i = 2; $i < count($this->sequence); $i++) {
            if ((int)$this->sequence[$i] - (int)$this->sequence[$i - 1] != $diff) {
                return false;
            }
        }
        return true;
    }

    public function is_geometric() {
        if ($this->sequence[0] == '0') {
            return false;
        }
        $ratio = (float)$this->sequence[1] / (float)$this->sequence[0];
        for ($i = 2; $i < count($this->sequence); $i++) {
            if ((float)$this->sequence[$i] / (float)$this->sequence[$i - 1] != $ratio) {
                return false;
            }
        }
        return true;
    }

    public function analyze() {
        if (count($this->sequence) < 2) {
            return 'Too few elements for analysis';
        }
        if ($this->is_arithmetic()) {
            return 'Arithmetic Sequence';
        } elseif ($this->is_geometric()) {
            return 'Geometric Sequence';
        } else {
            return 'Neither Arithmetic nor Geometric Sequence';
        }
    }
}

function main() {
    $text = 'The sequence is 2, 4, 6, 8, 10';
    $parser = new DocumentParser($text);
    $numeric_tokens = $parser->process();
    $analyzer = new SequenceAnalyzer($numeric_tokens);
    $result = $analyzer->analyze();
    echo $result;
}

main();

?>