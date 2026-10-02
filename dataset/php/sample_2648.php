<?php

class Vectorizer {

    public $vocab_size;
    public $word_to_index;

    public function __construct($vocab_size) {
        $this->vocab_size = $vocab_size;
        $this->word_to_index = $this->create_word_to_index_map();
    }

    public function create_word_to_index_map() {
        $vocabulary = $this->get_vocabulary();
        $word_to_index = array();
        foreach ($vocabulary as $index => $word) {
            $word_to_index[$word] = $index;
        }
        return $word_to_index;
    }

    public function get_vocabulary() {
        $vocabulary = array();
        for ($i = 97; $i < 97 + $this->vocab_size; $i++) {
            $vocabulary[] = chr($i);
        }
        return $vocabulary;
    }

    public function transform($text) {
        $vector = array();
        for ($i = 0; $i < strlen($text); $i++) {
            $char = $text[$i];
            if (array_key_exists($char, $this->word_to_index)) {
                $vector[] = $this->word_to_index[$char];
            }
        }
        return $vector;
    }
}

class SequenceProcessor {

    public $vectorizer;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    public function process_sequence($sequence) {
        return $this->vectorizer->transform($sequence);
    }

    public function generate_sequences($length) {
        $sequences = array();
        for ($i = 0; $i < $length; $i++) {
            $sequence = '';
            for ($j = 0; $j < $length; $j++) {
                $sequence .= $this->vectorizer->get_vocabulary()[array_rand($this->vectorizer->get_vocabulary())];
            }
            $sequences[] = $sequence;
        }
        return $sequences;
    }
}

class Analysis {

    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function analyze($sequences) {
        $result = array();
        foreach ($sequences as $seq) {
            $vector = $this->processor->process_sequence($seq);
            $vector_key = implode(',', $vector);
            if (array_key_exists($vector_key, $result)) {
                $result[$vector_key] += 1;
            } else {
                $result[$vector_key] = 1;
            }
        }
        return $result;
    }
}

function main() {
    $vocab_size = 26;
    $vectorizer = new Vectorizer($vocab_size);
    $processor = new SequenceProcessor($vectorizer);
    $analysis = new Analysis($processor);
    $sequences = $processor->generate_sequences(100);
    $result = $analysis->analyze($sequences);
    foreach ($result as $vec => $count) {
        echo "Vector: (" . $vec . "), Count: " . $count . "\n";
    }
}

main();