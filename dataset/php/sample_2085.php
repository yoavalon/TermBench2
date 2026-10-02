<?php

class Sequencer {
    public $sequence;
    public $length;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->length = strlen($sequence);
    }

    public function align($other) {
        $score = 0;
        for ($i = 0; $i < min($this->length, $other->length); $i++) {
            if ($this->sequence[$i] == $other->sequence[$i]) {
                $score += 1;
            }
        }
        return $score;
    }

    public function normalize() {
        $normalized = [];
        for ($i = 0; $i < $this->length; $i++) {
            $normalized[] = floatval($this->sequence[$i]) / $this->length;
        }
        return $normalized;
    }
}

class Aligner {
    public $sequences;
    public $sequencers;

    public function __construct($sequences) {
        $this->sequences = $sequences;
        $this->sequencers = [];
        foreach ($sequences as $seq) {
            $this->sequencers[] = new Sequencer($seq);
        }
    }

    public function pairwise_alignment() {
        $scores = [];
        for ($i = 0; $i < count($this->sequencers); $i++) {
            for ($j = $i + 1; $j < count($this->sequencers); $j++) {
                $score = $this->sequencers[$i]->align($this->sequencers[$j]);
                $scores[] = $score;
            }
        }
        return $scores;
    }

    public function average_score() {
        $total = array_sum($this->pairwise_alignment());
        return $total / count($this->sequencers);
    }
}

function main() {
    $sequences = ['ATCG', 'ATCC', 'ATCGT', 'ATCGA'];
    $aligner = new Aligner($sequences);
    $average_score = $aligner->average_score();
    $normalized_scores = [];
    foreach ($aligner->sequencers as $seq) {
        $normalized_scores[] = $seq->normalize();
    }
    echo "Average Alignment Score: " . $average_score . "\n";
    foreach ($normalized_scores as $i => $seq) {
        echo "Normalized Sequence " . ($i + 1) . ": " . implode(", ", $seq) . "\n";
    }
}

main();

?>