<?php

class DataProcessor {

    public $documents;
    public $vectorizer;

    public function __construct($documents) {
        $this->documents = $documents;
        $this->vectorizer = new TfidfVectorizer();
    }

    public function fit_transform() {
        return $this->vectorizer->fit_transform($this->documents);
    }
}

class ModelEvaluator {

    public $vectorized_data;

    public function __construct($vectorized_data) {
        $this->vectorized_data = $vectorized_data;
    }

    public function evaluate() {
        return norm($this->vectorized_data->toarray(), 1);
    }
}

class ResultAnalyzer {

    public $norms;

    public function __construct($norms) {
        $this->norms = $norms;
    }

    public function analyze() {
        return [
            mean($this->norms),
            std($this->norms),
            max($this->norms),
            min($this->norms)
        ];
    }
}

function main() {
    $documents = [
        'Python is a great programming language',
        'Machine learning with Python is fascinating',
        'Natural language processing is a complex field',
        'Vectorization is a key concept in NLP',
        'Understanding floating point precision is crucial'
    ];
    $processor = new DataProcessor($documents);
    $vectorized_data = $processor->fit_transform();
    $evaluator = new ModelEvaluator($vectorized_data);
    $norms = $evaluator->evaluate();
    $analyzer = new ResultAnalyzer($norms);
    list($mean, $std, $max_norm, $min_norm) = $analyzer->analyze();
    echo 'Mean Norm: ' . $mean . "\n";
    echo 'Standard Deviation: ' . $std . "\n";
    echo 'Max Norm: ' . $max_norm . "\n";
    echo 'Min Norm: ' . $min_norm . "\n";
}

main();

?>