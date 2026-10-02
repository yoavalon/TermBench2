<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $matrix;
    public $traceback_matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = [];
        $this->traceback_matrix = [];
    }

    function initialize_matrices() {
        $m = strlen($this->seq1) + 1;
        $n = strlen($this->seq2) + 1;
        $this->matrix = array_fill(0, $m, array_fill(0, $n, 0));
        $this->traceback_matrix = array_fill(0, $m, array_fill(0, $n, 0));
        for ($i = 1; $i < $m; $i++) {
            $this->matrix[$i][0] = $i;
            $this->traceback_matrix[$i][0] = 1;
        }
        for ($j = 1; $j < $n; $j++) {
            $this->matrix[0][$j] = $j;
            $this->traceback_matrix[0][$j] = 2;
        }
    }

    function fill_matrices() {
        $m = strlen($this->seq1);
        $n = strlen($this->seq2);
        for ($i = 1; $i <= $m; $i++) {
            for ($j = 1; $j <= $n; $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] === $this->seq2[$j - 1] ? 0 : 1);
                $delete = $this->matrix[$i - 1][$j] + 1;
                $insert = $this->matrix[$i][$j - 1] + 1;
                $this->matrix[$i][$j] = min($match, $delete, $insert);
                if ($this->matrix[$i][$j] == $match) {
                    $this->traceback_matrix[$i][$j] = 3;
                } elseif ($this->matrix[$i][$j] == $delete) {
                    $this->traceback_matrix[$i][$j] = 1;
                } else {
                    $this->traceback_matrix[$i][$j] = 2;
                }
            }
        }
    }

    function traceback() {
        $alignment1 = '';
        $alignment2 = '';
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        while ($i > 0 || $j > 0) {
            if ($this->traceback_matrix[$i][$j] == 3) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $i--;
                $j--;
            } elseif ($this->traceback_matrix[$i][$j] == 1) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = '-' . $alignment2;
                $i--;
            } else {
                $alignment1 = '-' . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $j--;
            }
        }
        return array($alignment1, $alignment2);
    }
}

function main() {
    $seq1 = 'GATTACA';
    $seq2 = 'GCATGCU';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->initialize_matrices();
    $aligner->fill_matrices();
    list($alignment1, $alignment2) = $aligner->traceback();
    echo $alignment1 . "\n";
    echo $alignment2 . "\n";
}

main();

?>