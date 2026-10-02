<?php

class Vectorizer {
    public $data;
    public $vectorizer;

    public function __construct($data) {
        $this->data = $data;
        $this->vectorizer = new CountVectorizer();
    }

    public function fit_transform() {
        return $this->vectorizer->fit_transform($this->data)->toarray();
    }
}

class Processor {
    public $vectors;

    public function __construct($vectors) {
        $this->vectors = $vectors;
    }

    public function normalize() {
        $norms = array_map('sqrt', array_map(function($v) {
            return array_sum(array_map(function($x) { return $x * $x; }, $v));
        }, $this->vectors));
        $norms = array_map(function($n) { return $n == 0 ? 1 : $n; }, $norms);
        return array_map(function($v, $n) { return array_map(function($x) use ($n) { return $x / $n; }, $v); }, $this->vectors, $norms);
    }

    public function filter($threshold) {
        $mask = array_map(function($v) use ($threshold) {
            return array_sum(array_map(function($x) use ($threshold) { return $x > $threshold ? 1 : 0; }, $v)) > 0;
        }, $this->vectors);
        $filtered = array();
        foreach ($mask as $i => $m) {
            if ($m) {
                $filtered[] = $this->vectors[$i];
            }
        }
        return $filtered;
    }
}

class Analysis {
    public $data;

    public function __construct($processed_data) {
        $this->data = $processed_data;
    }

    public function analyze() {
        $mean_vector = array_fill(0, count($this->data[0]), 0);
        $variance_vector = array_fill(0, count($this->data[0]), 0);
        foreach ($this->data as $vector) {
            $mean_vector = array_map(function($m, $v) { return $m + $v; }, $mean_vector, $vector);
            $variance_vector = array_map(function($v) { return $v * $v; }, $vector);
        }
        $mean_vector = array_map(function($m) use ($this) { return $m / count($this->data); }, $mean_vector);
        $variance_vector = array_map(function($v, $m) use ($this) { return ($v - $m * $m) / count($this->data); }, $variance_vector, $mean_vector);
        return array($mean_vector, $variance_vector);
    }
}

function main() {
    $data = array(
        'Natural language processing is fascinating.',
        'Vectorization is a key technique in NLP.',
        'Machine learning models learn from data.',
        'Data preprocessing is crucial for NLP tasks.',
        'Understanding human language is complex.'
    );
    $vectorizer = new Vectorizer($data);
    $vectors = $vectorizer->fit_transform();
    $processor = new Processor($vectors);
    $normalized_data = $processor->normalize();
    $filtered_data = $processor->filter(0.1);
    $analysis = new Analysis($filtered_data);
    list($mean_vector, $variance_vector) = $analysis->analyze();
    echo 'Mean Vector: ' . implode(', ', $mean_vector) . "\n";
    echo 'Variance Vector: ' . implode(', ', $variance_vector) . "\n";
}

main();

?>