<?php

class Vectorizer {
    public $vocab_size;
    public $word_to_index;
    public $index_to_word;

    function __construct($vocab_size) {
        $this->vocab_size = $vocab_size;
        $this->word_to_index = array();
        $this->index_to_word = array();
    }

    function fit($corpus) {
        $words = array();
        foreach ($corpus as $text) {
            $words = array_merge($words, explode(' ', $text));
        }
        $words = array_unique($words);
        foreach ($words as $idx => $word) {
            $this->word_to_index[$word] = $idx;
            $this->index_to_word[$idx] = $word;
        }
    }

    function transform($text) {
        $vector = array_fill(0, $this->vocab_size, 0);
        foreach (explode(' ', $text) as $word) {
            if (array_key_exists($word, $this->word_to_index)) {
                $vector[$this->word_to_index[$word]] += 1;
            }
        }
        return $vector;
    }
}

class Processor {
    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function process_data($data) {
        $vectors = array();
        foreach ($data as $text) {
            $vectors[] = $this->vectorizer->transform($text);
        }
        return $vectors;
    }
}

function main() {
    $corpus = array('the quick brown fox jumps over the lazy dog', 'hello world', 'data science is fascinating', 'machine learning is powerful', 'python is versatile');
    $vectorizer = new Vectorizer(50);
    $vectorizer->fit($corpus);
    $processor = new Processor($vectorizer);
    $processed_data = $processor->process_data($corpus);
    while (true) {
        $new_text = 'exploring new boundaries';
        $new_vector = $vectorizer->transform($new_text);
        $processed_data[] = $new_vector;
    }
}

main();

?>