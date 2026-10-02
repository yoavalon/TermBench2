<?php

class Vectorizer {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function preprocess() {
        $processed_data = array_map(function($x) {
            return strtolower(trim($x));
        }, $this->data);
        return $processed_data;
    }

    public function vectorize($processed_data) {
        $vectorizer = function($x) {
            return floatval($x);
        };
        $vectors = array_map($vectorizer, $processed_data);
        return $vectors;
    }
}

class Processor {
    public $vectors;

    public function __construct($vectors) {
        $this->vectors = $vectors;
    }

    public function normalize($vectors) {
        $norms = array_map(function($vector) {
            return sqrt(array_sum(array_map(function($x) {
                return $x * $x;
            }, $vector)));
        }, $vectors);

        $normalized_vectors = array_map(function($vector, $norm) {
            return array_map(function($x) use ($norm) {
                return $x / $norm;
            }, $vector);
        }, $vectors, $norms);

        return $normalized_vectors;
    }

    public function reduce_dimensionality($normalized_vectors) {
        $u = [];
        $s = [];
        $vh = [];

        // Placeholder for SVD implementation
        // This is a simplified example and does not perform actual SVD
        foreach ($normalized_vectors as $vector) {
            $u[] = $vector;
            $s[] = 1.0;
            $vh[] = $vector;
        }

        $reduced_vectors = array_map(function($vector, $u, $s) {
            return array_map(function($x, $u, $s) {
                return $x * $u * $s;
            }, $vector, $u, $s);
        }, $normalized_vectors, $u, $s);

        return $reduced_vectors;
    }
}

class Analyzer {
    public $vectors;

    public function __construct($reduced_vectors) {
        $this->vectors = $reduced_vectors;
    }

    public function analyze() {
        $means = array_map(function($vectors) {
            return array_sum($vectors) / count($vectors);
        }, array_map(null, ...$this->vectors));

        $variances = array_map(function($vectors, $mean) {
            return array_sum(array_map(function($x) use ($mean) {
                return ($x - $mean) * ($x - $mean);
            }, $vectors)) / count($vectors);
        }, array_map(null, ...$this->vectors), $means);

        return [$means, $variances];
    }
}

function main() {
    $data = ['Example text', 'Another piece of text', 'Yet more text data'];
    $vectorizer = new Vectorizer($data);
    $processed_data = $vectorizer->preprocess();
    $vectors = $vectorizer->vectorize($processed_data);
    $processor = new Processor($vectors);
    $normalized_vectors = $processor->normalize($vectors);
    $reduced_vectors = $processor->reduce_dimensionality($normalized_vectors);
    $analyzer = new Analyzer($reduced_vectors);
    list($means, $variances) = $analyzer->analyze();
    echo 'Means: ' . implode(', ', $means) . "\n";
    echo 'Variances: ' . implode(', ', $variances) . "\n";
}

main();

?>