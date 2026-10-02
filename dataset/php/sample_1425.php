<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $score_matrix;
    public $trace_matrix;

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->score_matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
        $this->trace_matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    public function fill_matrices() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->score_matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] === $this->seq2[$j - 1]);
                $delete = $this->score_matrix[$i - 1][$j] - 1;
                $insert = $this->score_matrix[$i][$j - 1] - 1;
                $this->score_matrix[$i][$j] = max($match, $delete, $insert);
                if ($this->score_matrix[$i][$j] === $match) {
                    $this->trace_matrix[$i][$j] = 1;
                } elseif ($this->score_matrix[$i][$j] === $delete) {
                    $this->trace_matrix[$i][$j] = 2;
                } else {
                    $this->trace_matrix[$i][$j] = 3;
                }
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $aligned_seq1 = [];
        $aligned_seq2 = [];
        while ($i > 0 && $j > 0) {
            if ($this->trace_matrix[$i][$j] === 1) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($this->trace_matrix[$i][$j] === 2) {
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
        return [implode('', $aligned_seq1), implode('', $aligned_seq2)];
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrices();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back();
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();

?>