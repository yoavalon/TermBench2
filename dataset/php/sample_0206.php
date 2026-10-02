<?php

class SequenceAligner {

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

    public function compute_similarity() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 0 : 1);
                $delete = $this->matrix[$i - 1][$j] + 1;
                $insert = $this->matrix[$i][$j - 1] + 1;
                $this->matrix[$i][$j] = min($match, $delete, $insert);
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $aligned_seq1 = [];
        $aligned_seq2 = [];
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 0 : 1)) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($i > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j] + 1) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, '-');
                $i--;
            } else {
                array_push($aligned_seq1, '-');
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $j--;
            }
        }
        return [implode('', array_reverse($aligned_seq1)), implode('', array_reverse($aligned_seq2))];
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->initialize_matrix();
    $aligner->compute_similarity();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back();
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();

?>