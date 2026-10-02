<?php

class Vector {
    public $elements;

    public function __construct($elements) {
        $this->elements = $elements;
    }

    public function magnitude() {
        return sqrt(array_sum(array_map(function($x) { return pow($x, 2); }, $this->elements)));
    }

    public function normalize() {
        $mag = $this->magnitude();
        $this->elements = array_map(function($x) use ($mag) { return $x / $mag; }, $this->elements);
    }
}

function cosine_similarity($vec1, $vec2) {
    if (count($vec1->elements) != count($vec2->elements)) {
        throw new Exception('Vectors must be of the same length');
    }
    $dot_product = array_sum(array_map(function($i) use ($vec1, $vec2) { return $vec1->elements[$i] * $vec2->elements[$i]; }, range(0, count($vec1->elements) - 1)));
    return $dot_product / ($vec1->magnitude() * $vec2->magnitude());
}

function process_vectors($data) {
    $vectors = array_map(function($vec) { return new Vector($vec); }, $data);
    $results = [];
    for ($i = 0; $i < count($vectors); $i++) {
        for ($j = $i + 1; $j < count($vectors); $j++) {
            $vectors[$i]->normalize();
            $vectors[$j]->normalize();
            $similarity = cosine_similarity($vectors[$i], $vectors[$j]);
            $results[] = [$i, $j, $similarity];
        }
    }
    return $results;
}

function main() {
    $data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    $similarities = process_vectors($data);
    foreach ($similarities as $similarity) {
        list($idx1, $idx2, $sim) = $similarity;
        echo "Similarity between vector $idx1 and $idx2: " . number_format($sim, 4) . "\n";
    }
}

main();

?>