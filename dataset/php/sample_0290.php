<?php

class SequenceAligner {

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
        $this->score_matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    public function initialize_matrices() {
        for ($i = 0; $i <= strlen($this->seq1); $i++) {
            $this->matrix[$i][0] = $i;
            $this->score_matrix[$i][0] = $i * -2;
        }
        for ($j = 0; $j <= strlen($this->seq2); $j++) {
            $this->matrix[0][$j] = $j;
            $this->score_matrix[0][$j] = $j * -2;
        }
    }

    public function calculate_scores() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->score_matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 1 : -1);
                $delete = $this->score_matrix[$i - 1][$j] - 2;
                $insert = $this->score_matrix[$i][$j - 1] - 2;
                $this->score_matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $aligned_seq1 = '';
        $aligned_seq2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && ($this->score_matrix[$i][$j] == $this->score_matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 1 : -1))) {
                $aligned_seq1 = $this->seq1[$i - 1] . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$j - 1] . $aligned_seq2;
                $i--;
                $j--;
            } elseif ($i > 0 && $this->score_matrix[$i][$j] == $this->score_matrix[$i - 1][$j] - 2) {
                $aligned_seq1 = $this->seq1[$i - 1] . $aligned_seq1;
                $aligned_seq2 = '-' . $aligned_seq2;
                $i--;
            } else {
                $aligned_seq1 = '-' . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$j - 1] . $aligned_seq2;
                $j--;
            }
        }
        return array($aligned_seq1, $aligned_seq2);
    }
}

function main() {
    $seq1 = 'GATTACA';
    $seq2 = 'GATTCACA';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->initialize_matrices();
    $aligner->calculate_scores();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back();
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();

?>