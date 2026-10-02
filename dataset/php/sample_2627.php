<?php

class TextProcessor {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', strtolower($this->text), -1, PREG_SPLIT_NO_EMPTY);
    }
}

class SequenceAnalyzer {
    public $tokens;
    public $sequences;

    function __construct($tokens) {
        $this->tokens = $tokens;
        $this->sequences = [];
    }

    function identify_sequences() {
        for ($i = 0; $i < count($this->tokens) - 1; $i++) {
            $pair = $this->tokens[$i] . ' ' . $this->tokens[$i + 1];
            if (array_key_exists($pair, $this->sequences)) {
                $this->sequences[$pair]++;
            } else {
                $this->sequences[$pair] = 1;
            }
        }
    }
}

class ReportGenerator {
    public $sequences;

    function __construct($sequences) {
        $this->sequences = $sequences;
    }

    function generate_report() {
        arsort($this->sequences);
        $report = array_slice($this->sequences, 0, 10);
        return $report;
    }
}

function main() {
    $text = 'This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.';
    $processor = new TextProcessor($text);
    $processor->tokenize();
    $analyzer = new SequenceAnalyzer($processor->tokens);
    $analyzer->identify_sequences();
    $generator = new ReportGenerator($analyzer->sequences);
    $report = $generator->generate_report();
    foreach ($report as $sequence => $count) {
        echo "Sequence: $sequence, Count: $count\n";
    }
}

main();
?>