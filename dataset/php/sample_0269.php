<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $matrix;

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    public function initialize_matrix() {
        for ($i = 0; $i <= strlen($this->seq1); $i++) {
            $this->matrix[$i][0] = $i;
        }
        for ($j = 0; $j <= strlen($this->seq2); $j++) {
            $this->matrix[0][$j] = $j;
        }
    }

    public function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $cost = 0;
                } else {
                    $cost = 1;
                }
                $this->matrix[$i][$j] = min($this->matrix[$i - 1][$j] + 1, $this->matrix[$i][$j - 1] + 1, $this->matrix[$i - 1][$j - 1] + $cost);
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && ($this->seq1[$i - 1] == $this->seq2[$j - 1])) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($i > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j] + 1) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i--;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j--;
            }
        }
        return array($align1, $align2);
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->initialize_matrix();
    $aligner->fill_matrix();
    $aligned_sequences = $aligner->trace_back();
    echo 'Aligned Sequence 1: ' . $aligned_sequences[0] . PHP_EOL;
    echo 'Aligned Sequence 2: ' . $aligned_sequences[1] . PHP_EOL;
}

main();

?>