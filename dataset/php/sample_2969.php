<?php

function generate_sequence($n) {
    $sequence = array();
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function compare_sequences($seq1, $seq2) {
    $score = 0;
    $min_length = min(count($seq1), count($seq2));
    for ($i = 0; $i < $min_length; $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score++;
        }
    }
    return $score;
}

class SequenceAligner {
    public $seq1;
    public $seq2;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
    }

    function align() {
        $best_score = 0;
        $best_shift = 0;
        for ($shift = -$this->seq1; $shift < count($this->seq2); $shift++) {
            $shifted_seq = array_slice($this->seq2, $shift) + array_fill(0, abs($shift), 0);
            $score = compare_sequences($this->seq1, $shifted_seq);
            if ($score > $best_score) {
                $best_score = $score;
                $best_shift = $shift;
            }
        }
        return array($best_score, $best_shift);
    }
}

function main() {
    $seq1 = generate_sequence(100);
    $seq2 = generate_sequence(100);
    $aligner = new SequenceAligner($seq1, $seq2);
    while (true) {
        list($score, $shift) = $aligner->align();
        echo "Best Score: $score, Best Shift: $shift\n";
    }
}

main();

?>