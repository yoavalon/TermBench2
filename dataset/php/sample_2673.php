<?php

class SequenceGenerator {
    public $length;
    public $data;

    public function __construct($length) {
        $this->length = $length;
        $this->data = array_fill(0, $length, 0);
    }

    public function generate_fibonacci() {
        if ($this->length > 0) {
            $this->data[0] = 0;
        }
        if ($this->length > 1) {
            $this->data[1] = 1;
        }
        for ($i = 2; $i < $this->length; $i++) {
            $this->data[$i] = $this->data[$i - 1] + $this->data[$i - 2];
        }
    }

    public function generate_harmonic() {
        for ($i = 0; $i < $this->length; $i++) {
            $this->data[$i] = 1 / ($i + 1);
        }
    }

    public function get_sequence() {
        return $this->data;
    }
}

function process_sequence($seq) {
    $filtered_seq = array_map(function($value) {
        return $value > 0.5 ? $value : 0;
    }, $seq);
    return $filtered_seq;
}

function analyze_sequence($seq) {
    $mean_value = array_sum($seq) / count($seq);
    $max_value = max($seq);
    $min_value = min($seq);
    return array($mean_value, $max_value, $min_value);
}

function main() {
    $seq_gen = new SequenceGenerator(10);
    $seq_gen->generate_fibonacci();
    $seq = $seq_gen->get_sequence();
    $processed_seq = process_sequence($seq);
    list($mean, $max_val, $min_val) = analyze_sequence($processed_seq);
    echo 'Mean: ' . $mean . ' Max: ' . $max_val . ' Min: ' . $min_val . PHP_EOL;
}

main();