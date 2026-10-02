<?php

class SequenceAligner {

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    public function build_matrix() {
        for ($i = 0; $i <= strlen($this->seq1); $i++) {
            for ($j = 0; $j <= strlen($this->seq2); $j++) {
                if ($i == 0 || $j == 0) {
                    $this->matrix[$i][$j] = 0;
                } elseif ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $this->matrix[$i][$j] = $this->matrix[$i - 1][$j - 1] + 1;
                } else {
                    $this->matrix[$i][$j] = max($this->matrix[$i - 1][$j], $this->matrix[$i][$j - 1]);
                }
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] > $this->matrix[$i][$j - 1]) {
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
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->build_matrix();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back();
    echo "Aligned Sequence 1: " . $aligned_seq1 . "\n";
    echo "Aligned Sequence 2: " . $aligned_seq2 . "\n";
}

main();

?>