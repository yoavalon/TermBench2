<?php

class Vectorizer {
    public $corpus;
    public $vocabulary;

    function __construct($corpus) {
        $this->corpus = $corpus;
        $this->vocabulary = array();
    }

    function build_vocabulary($index = 0) {
        if ($index >= count($this->corpus)) {
            return;
        }
        $words = explode(' ', $this->corpus[$index]);
        foreach ($words as $word) {
            if (!array_key_exists($word, $this->vocabulary)) {
                $this->vocabulary[$word] = 0;
            }
            $this->vocabulary[$word] += 1;
        }
        $this->build_vocabulary($index + 1);
    }

    function vectorize($text) {
        $vector = array();
        $words = explode(' ', $text);
        foreach ($words as $word) {
            if (array_key_exists($word, $this->vocabulary)) {
                $vector[$word] = $this->vocabulary[$word];
            } else {
                $vector[$word] = 0;
            }
        }
        return $vector;
    }
}

class Analysis {
    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function compare_texts($text1, $text2) {
        $vec1 = $this->vectorizer->vectorize($text1);
        $vec2 = $this->vectorizer->vectorize($text2);
        $similarity = 0;
        $allWords = array_unique(array_merge(array_keys($vec1), array_keys($vec2)));
        foreach ($allWords as $word) {
            $similarity += min($vec1[$word] ?? 0, $vec2[$word] ?? 0);
        }
        return $similarity;
    }
}

function main() {
    $corpus = array('Natural language processing is fascinating', 'Vectorization is a core technique in NLP', 'This example demonstrates recursion', 'Recursion is useful in many algorithms');
    $vectorizer = new Vectorizer($corpus);
    $vectorizer->build_vocabulary();
    $analysis = new Analysis($vectorizer);
    $similarity = $analysis->compare_texts('Natural language processing', 'Vectorization in NLP');
    echo 'Similarity: ' . $similarity . "\n";
}

main();

?>