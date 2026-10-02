<?php

class SequenceMatcher {
    public $seq1;
    public $seq2;
    public $matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function compute_alignment() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = ($this->seq1[$i - 1] == $this->seq2[$j - 1]) ? $this->matrix[$i - 1][$j - 1] + 1 : 0;
                $delete = $this->matrix[$i - 1][$j];
                $insert = $this->matrix[$i][$j - 1];
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    function trace_back() {
        $alignment1 = '';
        $alignment2 = '';
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] >= $this->matrix[$i][$j - 1]) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = '-' . $alignment2;
                $i--;
            } else {
                $alignment1 = '-' . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $j--;
            }
        }
        while ($i > 0) {
            $alignment1 = $this->seq1[$i - 1] . $alignment1;
            $alignment2 = '-' . $alignment2;
            $i--;
        }
        while ($j > 0) {
            $alignment1 = '-' . $alignment1;
            $alignment2 = $this->seq2[$j - 1] . $alignment2;
            $j--;
        }
        return array($alignment1, $alignment2);
    }
}

function process_sequences($seq1, $seq2) {
    $matcher = new SequenceMatcher($seq1, $seq2);
    $matcher->compute_alignment();
    return $matcher->trace_back();
}

function main() {
    $seq1 = 'AGCTG';
    $seq2 = 'AGGCT';
    list($aligned_seq1, $aligned_seq2) = process_sequences($seq1, $seq2);
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
}

main();
?>