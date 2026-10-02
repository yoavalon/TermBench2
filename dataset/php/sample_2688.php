php
<?php

class SequenceAligner {

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $this->matrix[$i][$j] = $this->matrix[$i - 1][$j - 1] + 1;
                } else {
                    $this->matrix[$i][$j] = max($this->matrix[$i - 1][$j], $this->matrix[$i][$j - 1]);
                }
            }
        }
    }

    function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $alignment = array();
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                array_push($alignment, $this->seq1[$i - 1]);
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] > $this->matrix[$i][$j - 1]) {
                $i--;
            } else {
                $j--;
            }
        }
        $alignment = array_reverse($alignment);
        return implode('', $alignment);
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrix();
    $result = $aligner->trace_back();
    echo 'Aligned sequence: ' . $result;
}

main();