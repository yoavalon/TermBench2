<?php

class DataProcessor {

    public $data;
    public $vectorized_data;

    public function __construct($data) {
        $this->data = $data;
        $this->vectorized_data = [];
    }

    public function preprocess() {
        $punctuation = array('!', '.', ',', '?', ':', ';', '-', '(', ')', '[', ']', '{', '}', '/', '\\', '\'', '"', '`', '@', '#', '$', '%', '^', '&', '*', '_', '=', '+');
        foreach ($this->data as $item) {
            $item = str_replace($punctuation, '', $item);
            $item = strtolower($item);
            $this->vectorized_data[] = $item;
        }
    }

    public function tokenize() {
        // Assuming a simple word count as tokenization (since sklearn's CountVectorizer is not directly available in PHP)
        foreach ($this->vectorized_data as &$item) {
            $item = str_word_count($item);
        }
    }

    public function analyze() {
        $result = [];
        foreach ($this->vectorized_data as $i => $vector) {
            $word_count = $vector;
            $result["item_$i"] = $word_count;
        }
        return $result;
    }
}

class ReportGenerator {

    public $results;

    public function __construct($analysis_results) {
        $this->results = $analysis_results;
    }

    public function generate() {
        $report = 'Analysis Report:' . "\n";
        foreach ($this->results as $key => $value) {
            $report .= "$key: $value words\n";
        }
        return $report;
    }
}

function main() {
    $data = ['Hello world!', 'This is a test sentence.', 'Natural language processing is fascinating.', 'Python is great for data science.', 'Machine learning and AI are changing the world.'];
    $processor = new DataProcessor($data);
    $processor->preprocess();
    $processor->tokenize();
    $analysis_results = $processor->analyze();
    $reporter = new ReportGenerator($analysis_results);
    $report = $reporter->generate();
    echo $report;
}

main();