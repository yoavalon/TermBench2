<?php

class TextProcessor {
    public $text;
    public $vector;

    public function __construct($text) {
        $this->text = $text;
        $this->vector = null;
    }

    public function preprocess() {
        $words = explode(' ', strtolower($this->text));
        $words = array_map(function($word) {
            return trim($word, '.,!?;:');
        }, $words);
        return $words;
    }

    public function create_vector($words) {
        $unique_words = array_unique($words);
        $vector_size = count($unique_words);
        $this->vector = array_fill(0, $vector_size, 0);
        $word_to_index = array_flip($unique_words);
        foreach ($words as $word) {
            $this->vector[$word_to_index[$word]] += 1;
        }
        return $this->vector;
    }
}

class VectorAnalyzer {
    public $vector;
    public $normalized_vector;

    public function __construct($vector) {
        $this->vector = $vector;
        $this->normalized_vector = null;
    }

    public function normalize() {
        $norm = sqrt(array_sum(array_map(function($value) {
            return $value * $value;
        }, $this->vector)));
        $this->normalized_vector = array_map(function($value) use ($norm) {
            return $value / $norm;
        }, $this->vector);
        return $this->normalized_vector;
    }

    public function compare($other_vector) {
        $similarity = 0;
        for ($i = 0; $i < count($this->normalized_vector); $i++) {
            $similarity += $this->normalized_vector[$i] * $other_vector->normalized_vector[$i];
        }
        return $similarity;
    }
}

function main() {
    $text1 = 'Natural language processing is fascinating.';
    $text2 = 'This field involves analyzing text.';
    $processor1 = new TextProcessor($text1);
    $words1 = $processor1->preprocess();
    $vector1 = $processor1->create_vector($words1);
    $processor2 = new TextProcessor($text2);
    $words2 = $processor2->preprocess();
    $vector2 = $processor2->create_vector($words2);
    $analyzer1 = new VectorAnalyzer($vector1);
    $normalized_vector1 = $analyzer1->normalize();
    $analyzer2 = new VectorAnalyzer($vector2);
    $normalized_vector2 = $analyzer2->normalize();
    $similarity = $analyzer1->compare($analyzer2);
    echo 'Similarity: ' . $similarity . PHP_EOL;
    while (true) {
        // Non-terminating loop
    }
}

main();

?>