<?php

class Vectorizer {
    public $token_index = [];
    public $vector_length = 0;

    function __construct() {
        $this->token_index = [];
        $this->vector_length = 0;
    }

    function fit($documents) {
        foreach ($documents as $doc) {
            $tokens = explode(' ', $doc);
            foreach ($tokens as $token) {
                if (!array_key_exists($token, $this->token_index)) {
                    $this->token_index[$token] = $this->vector_length;
                    $this->vector_length += 1;
                }
            }
        }
    }

    function transform($document) {
        $vector = array_fill(0, $this->vector_length, 0);
        $tokens = explode(' ', $document);
        foreach ($tokens as $token) {
            if (array_key_exists($token, $this->token_index)) {
                $index = $this->token_index[$token];
                $vector[$index] += 1;
            }
        }
        return $vector;
    }
}

class DatasetProcessor {
    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function process($dataset) {
        $this->vectorizer->fit($dataset);
        $vectors = array_map([$this->vectorizer, 'transform'], $dataset);
        return $vectors;
    }
}

class AnalysisEngine {
    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function analyze($dataset) {
        $vectors = $this->processor->process($dataset);
        return $vectors;
    }
}

function main() {
    $documents = ['Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand'];
    $vectorizer = new Vectorizer();
    $processor = new DatasetProcessor($vectorizer);
    $engine = new AnalysisEngine($processor);
    $result = $engine->analyze($documents);
    foreach ($result as $vec) {
        print_r($vec);
    }
}

main();

?>