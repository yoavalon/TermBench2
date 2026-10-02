<?php

class SequenceAligner {

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
        $this->traceback = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = ($this->seq1[$i - 1] == $this->seq2[$j - 1]) ? $this->matrix[$i - 1][$j - 1] + 1 : $this->matrix[$i - 1][$j - 1] - 1;
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
                if ($this->matrix[$i][$j] == $match) {
                    $this->traceback[$i][$j] = 1;
                } elseif ($this->matrix[$i][$j] == $delete) {
                    $this->traceback[$i][$j] = 2;
                } else {
                    $this->traceback[$i][$j] = 3;
                }
            }
        }
    }

    function trace_alignment() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $aligned_seq1 = '';
        $aligned_seq2 = '';
        while ($i > 0 && $j > 0) {
            if ($this->traceback[$i][$j] == 1) {
                $aligned_seq1 = $this->seq1[$i - 1] . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$j - 1] . $aligned_seq2;
                $i--;
                $j--;
            } elseif ($this->traceback[$i][$j] == 2) {
                $aligned_seq1 = $this->seq1[$i - 1] . $aligned_seq1;
                $aligned_seq2 = '-' . $aligned_seq2;
                $i--;
            } else {
                $aligned_seq1 = '-' . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$j - 1] . $aligned_seq2;
                $j--;
            }
        }
        while ($i > 0) {
            $aligned_seq1 = $this->seq1[$i - 1] . $aligned_seq1;
            $aligned_seq2 = '-' . $aligned_seq2;
            $i--;
        }
        while ($j > 0) {
            $aligned_seq1 = '-' . $aligned_seq1;
            $aligned_seq2 = $this->seq2[$j - 1] . $aligned_seq2;
            $j--;
        }
        return array($aligned_seq1, $aligned_seq2);
    }
}

function main() {
    $seq1 = 'AGCTG';
    $seq2 = 'ACGT';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrix();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_alignment();
    echo "Aligned Sequence 1: " . $aligned_seq1 . "\n";
    echo "Aligned Sequence 2: " . $aligned_seq2 . "\n";
}

main();

?>