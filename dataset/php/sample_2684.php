<?php

class SequenceTokenizer {

    public $text;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
        return $this->tokens;
    }
}

class SequenceAnalyzer {

    public $tokens;
    public $math_sequences;

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->math_sequences = [];
    }

    public function analyze() {
        foreach ($this->tokens as $token) {
            if ($this->is_math_sequence($token)) {
                $this->math_sequences[] = $token;
            }
        }
        return $this->math_sequences;
    }

    public function is_math_sequence($token) {
        try {
            $sequence = array_map('intval', explode(',', $token));
            return $this->is_arithmetic($sequence) || $this->is_geometric($sequence);
        } catch (Exception $e) {
            return false;
        }
    }

    public function is_arithmetic($sequence) {
        if (count($sequence) < 2) {
            return false;
        }
        $diff = $sequence[1] - $sequence[0];
        return array_reduce(array_slice($sequence, 2), function($carry, $item) use ($diff) {
            return $carry && ($item - $sequence[array_search($item, $sequence) - 1] == $diff);
        }, true);
    }

    public function is_geometric($sequence) {
        if (count($sequence) < 2 || $sequence[0] == 0) {
            return false;
        }
        $ratio = $sequence[1] / $sequence[0];
        return array_reduce(array_slice($sequence, 2), function($carry, $item) use ($sequence, $ratio) {
            return $carry && ($item / $sequence[array_search($item, $sequence) - 1] == $ratio);
        }, true);
    }
}

class SequenceProcessor {

    public $sequences;

    public function __construct($sequences) {
        $this->sequences = $sequences;
    }

    public function process() {
        $results = [];
        foreach ($this->sequences as $sequence) {
            $result = $this->classify_sequence($sequence);
            $results[] = $result;
        }
        return $results;
    }

    public function classify_sequence($sequence) {
        $sequence_list = array_map('intval', explode(',', $sequence));
        if ($this->is_arithmetic($sequence_list)) {
            return 'Arithmetic';
        } elseif ($this->is_geometric($sequence_list)) {
            return 'Geometric';
        } else {
            return 'Unknown';
        }
    }

    public function is_arithmetic($sequence) {
        if (count($sequence) < 2) {
            return false;
        }
        $diff = $sequence[1] - $sequence[0];
        return array_reduce(array_slice($sequence, 2), function($carry, $item) use ($diff) {
            return $carry && ($item - $sequence[array_search($item, $sequence) - 1] == $diff);
        }, true);
    }

    public function is_geometric($sequence) {
        if (count($sequence) < 2 || $sequence[0] == 0) {
            return false;
        }
        $ratio = $sequence[1] / $sequence[0];
        return array_reduce(array_slice($sequence, 2), function($carry, $item) use ($sequence, $ratio) {
            return $carry && ($item / $sequence[array_search($item, $sequence) - 1] == $ratio);
        }, true);
    }
}

function main() {
    $text = 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.';
    $tokenizer = new SequenceTokenizer($text);
    $tokens = $tokenizer->tokenize();
    $analyzer = new SequenceAnalyzer($tokens);
    $sequences = $analyzer->analyze();
    $processor = new SequenceProcessor($sequences);
    $results = $processor->process();
    print_r($results);
}

main();