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
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $aligned_seq1 = array();
        $aligned_seq2 = array();
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] > $this->matrix[$i][$j - 1]) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, '-');
                $i--;
            } else {
                array_push($aligned_seq1, '-');
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $j--;
            }
        }
        $aligned_seq1 = array_reverse($aligned_seq1);
        $aligned_seq2 = array_reverse($aligned_seq2);
        return array(implode('', $aligned_seq1), implode('', $aligned_seq2));
    }
}

function main() {
    $seq1 = 'GATTACA';
    $seq2 = 'CGATACG';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrix();
    list($result1, $result2) = $aligner->trace_back();
    echo $result1 . "\n";
    echo $result2 . "\n";
}

main();