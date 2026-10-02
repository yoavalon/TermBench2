<?php

class Vectorizer {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function normalize($vector) {
        $magnitude = 0.0;
        foreach ($vector as $x) {
            $magnitude += pow($x, 2);
        }
        $magnitude = sqrt($magnitude);
        if ($magnitude == 0) {
            return array_fill(0, count($vector), 0.0);
        }
        $normalized_vector = [];
        foreach ($vector as $x) {
            $normalized_vector[] = $x / $magnitude;
        }
        return $normalized_vector;
    }

    public function vectorize() {
        $vectors = [];
        foreach ($this->data as $item) {
            $vector = [];
            for ($i = 0; $i < strlen($item); $i++) {
                $vector[] = ord($item[$i]) / 1000.0;
            }
            $normalized_vector = $this->normalize($vector);
            $vectors[] = $normalized_vector;
        }
        return $vectors;
    }
}

class Processor {

    public $vectors;

    public function __construct($vectors) {
        $this->vectors = $vectors;
    }

    public function cosine_similarity($vec1, $vec2) {
        $dot_product = 0.0;
        for ($i = 0; $i < count($vec1); $i++) {
            $dot_product += $vec1[$i] * $vec2[$i];
        }
        $norm1 = 0.0;
        foreach ($vec1 as $x) {
            $norm1 += pow($x, 2);
        }
        $norm1 = sqrt($norm1);
        $norm2 = 0.0;
        foreach ($vec2 as $x) {
            $norm2 += pow($x, 2);
        }
        $norm2 = sqrt($norm2);
        if ($norm1 == 0 || $norm2 == 0) {
            return 0.0;
        }
        return $dot_product / ($norm1 * $norm2);
    }

    public function compare() {
        $results = [];
        for ($i = 0; $i < count($this->vectors); $i++) {
            for ($j = $i + 1; $j < count($this->vectors); $j++) {
                $similarity = $this->cosine_similarity($this->vectors[$i], $this->vectors[$j]);
                $results[] = [$i, $j, $similarity];
            }
        }
        return $results;
    }
}

function main() {
    $data = ['hello', 'world', 'python', 'programming'];
    $vectorizer = new Vectorizer($data);
    $vectors = $vectorizer->vectorize();
    $processor = new Processor($vectors);
    $results = $processor->compare();
    foreach ($results as $result) {
        list($i, $j, $similarity) = $result;
        echo "Similarity between item $i and $j: " . number_format($similarity, 4) . "\n";
    }
}

main();