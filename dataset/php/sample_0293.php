<?php

class SequenceAligner {

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = null;
    }

    function initialize_matrix() {
        $len1 = strlen($this->seq1);
        $len2 = strlen($this->seq2);
        $this->matrix = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
        for ($i = 0; $i <= $len1; $i++) {
            $this->matrix[$i][0] = $i;
        }
        for ($j = 0; $j <= $len2; $j++) {
            $this->matrix[0][$j] = $j;
        }
    }

    function compute_alignment() {
        $len1 = strlen($this->seq1);
        $len2 = strlen($this->seq2);
        for ($i = 1; $i <= $len1; $i++) {
            for ($j = 1; $j <= $len2; $j++) {
                $cost = ($this->seq1[$i - 1] === $this->seq2[$j - 1]) ? 0 : 1;
                $this->matrix[$i][$j] = min($this->matrix[$i - 1][$j] + 1, $this->matrix[$i][$j - 1] + 1, $this->matrix[$i - 1][$j - 1] + $cost);
            }
        }
    }

    function backtrack_alignment() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] === $this->seq2[$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] + 1 === $this->matrix[$i][$j]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i--;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
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
    $aligner->initialize_matrix();
    $aligner->compute_alignment();
    $alignment = $aligner->backtrack_alignment();
    echo 'Aligned Sequence 1: ' . $alignment[0] . "\n";
    echo 'Aligned Sequence 2: ' . $alignment[1] . "\n";
}

main();