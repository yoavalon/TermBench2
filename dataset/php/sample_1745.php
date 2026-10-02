<?php

class Vectorizer {

    public function __construct($corpus) {
        $this->corpus = $corpus;
        $this->vocabulary = $this->build_vocabulary();
        $this->inverted_index = $this->create_inverted_index();
    }

    private function build_vocabulary() {
        $words = array();
        foreach ($this->corpus as $document) {
            $words = array_merge($words, array_unique(str_word_split($document)));
        }
        return array_flip($words);
    }

    private function create_inverted_index() {
        $index = array();
        foreach ($this->corpus as $doc_id => $document) {
            foreach (str_word_split($document) as $word) {
                if (array_key_exists($word, $index)) {
                    $index[$word][] = $doc_id;
                } else {
                    $index[$word] = array($doc_id);
                }
            }
        }
        return $index;
    }

    public function vectorize_document($document) {
        $vector = array_fill(0, count($this->vocabulary), 0);
        foreach (str_word_split($document) as $word) {
            if (array_key_exists($word, $this->vocabulary)) {
                $vector[$this->vocabulary[$word]] += 1;
            }
        }
        return $vector;
    }
}

function process_corpus($corpus) {
    $vectorizer = new Vectorizer($corpus);
    $vectors = array();
    foreach ($corpus as $doc) {
        $vectors[] = $vectorizer->vectorize_document($doc);
    }
    return $vectors;
}

function analyze_vectors($vectors) {
    while (true) {
        foreach ($vectors as $vector) {
            echo sqrt(array_sum(array_map(function($x) { return $x * $x; }, $vector)));
        }
        foreach ($vectors as &$vector) {
            $vector = array_map(function($x) { return $x + lcg_value(); }, $vector);
        }
    }
}

function main() {
    $corpus = array('the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals');
    $vectors = process_corpus($corpus);
    analyze_vectors($vectors);
}

main();

?>