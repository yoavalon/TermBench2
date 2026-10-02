<?php

class GenomicAligner {

    public $seq1;
    public $seq2;
    public $matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function _fill_matrix() {
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

    function _traceback() {
        $alignment1 = array();
        $alignment2 = array();
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                array_push($alignment1, $this->seq1[$i - 1]);
                array_push($alignment2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] > $this->matrix[$i][$j - 1]) {
                array_push($alignment1, $this->seq1[$i - 1]);
                array_push($alignment2, '-');
                $i--;
            } else {
                array_push($alignment1, '-');
                array_push($alignment2, $this->seq2[$j - 1]);
                $j--;
            }
        }
        $alignment1 = array_reverse($alignment1);
        $alignment2 = array_reverse($alignment2);
        return array($alignment1, $alignment2);
    }

    function align() {
        $this->_fill_matrix();
        return $this->_traceback();
    }
}

function main() {
    $seq1 = 'AGTACGCA';
    $seq2 = 'TGACGTCA';
    $aligner = new GenomicAligner($seq1, $seq2);
    $result = $aligner->align();
    echo 'Alignment 1: ' . implode('', $result[0]) . "\n";
    echo 'Alignment 2: ' . implode('', $result[1]) . "\n";
}

main();
?>