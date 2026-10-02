<?php

class SequenceAligner {

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    public function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = ($this->seq1[$i - 1] == $this->seq2[$j - 1]) ? $this->matrix[$i - 1][$j - 1] + 1 : 0;
                $this->matrix[$i][$j] = max($this->matrix[$i - 1][$j], $this->matrix[$i][$j - 1], $match);
            }
        }
    }

    public function traceback() {
        $aligned_seq1 = array();
        $aligned_seq2 = array();
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && $this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $i -= 1;
                $j -= 1;
            } elseif ($i > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j]) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, '-');
                $i -= 1;
            } else {
                array_push($aligned_seq1, '-');
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $j -= 1;
            }
        }
        return (implode('', array_reverse($aligned_seq1)), implode('', array_reverse($aligned_seq2)));
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrix();
    list($aligned_seq1, $aligned_seq2) = $aligner->traceback();
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
}

main();