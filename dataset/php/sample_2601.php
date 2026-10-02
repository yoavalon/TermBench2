<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function calculate_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 1 : -1);
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    function traceback() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 && $j > 0) {
            if ($this->matrix[$i][$j] == $this->matrix[$i - 1][$j] - 1) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i--;
            } elseif ($this->matrix[$i][$j] == $this->matrix[$i][$j - 1] - 1) {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j--;
            } else {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            }
        }
        while ($i > 0) {
            $align1 = $this->seq1[$i - 1] . $align1;
            $align2 = '-' . $align2;
            $i--;
        }
        while ($j > 0) {
            $align1 = '-' . $align1;
            $align2 = $this->seq2[$j - 1] . $align2;
            $j--;
        }
        return array($align1, $align2);
    }
}

function main() {
    $seq1 = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA';
    $seq2 = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->calculate_matrix();
    list($aligned_seq1, $aligned_seq2) = $aligner->traceback();
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();

?>