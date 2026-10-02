<?php

class DocumentParser {

    public $text;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
        $this->process_text();
    }

    public function process_text() {
        $this->tokenize();
    }

    public function tokenize() {
        $this->tokens = preg_split('/\W+/', strtolower($this->text), -1, PREG_SPLIT_NO_EMPTY);
    }
}

class TokenAnalyzer {

    public $tokens;
    public $token_count;

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->token_count = [];
        $this->analyze_tokens();
    }

    public function analyze_tokens() {
        foreach ($this->tokens as $token) {
            if (array_key_exists($token, $this->token_count)) {
                $this->token_count[$token] += 1;
            } else {
                $this->token_count[$token] = 1;
            }
        }
    }
}

class ReportGenerator {

    public $token_count;
    public $report;

    public function __construct($token_count) {
        $this->token_count = $token_count;
        $this->report = $this->generate_report();
    }

    public function generate_report() {
        arsort($this->token_count);
        $this->report = $this->token_count;
        return $this->report;
    }
}

function main() {
    $text = 'This is a test document. This document is used for testing tokenization and analysis.';
    $parser = new DocumentParser($text);
    $analyzer = new TokenAnalyzer($parser->tokens);
    $report_generator = new ReportGenerator($analyzer->token_count);
    print_r($report_generator->report);
}

main();
?>