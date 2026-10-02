<?php

class SequenceAligner {

    public $seq1;
    public $seq2;
    public $score_matrix;
    public $traceback_matrix;
    public $max_score;
    public $max_position;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->score_matrix = [];
        $this->traceback_matrix = [];
        $this->max_score = 0;
        $this->max_position = [0, 0];
    }

    function initialize_matrices() {
        $len1 = strlen($this->seq1);
        $len2 = strlen($this->seq2);
        for ($i = 0; $i <= $len1; $i++) {
            $this->score_matrix[] = array_fill(0, $len2 + 1, 0);
            $this->traceback_matrix[] = array_fill(0, $len2 + 1, 0);
        }
    }

    function fill_matrices() {
        $len1 = strlen($this->seq1);
        $len2 = strlen($this->seq2);
        for ($i = 1; $i <= $len1; $i++) {
            for ($j = 1; $j <= $len2; $j++) {
                $match = $this->score_matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] == $this->seq2[$j - 1] ? 1 : -1);
                $delete = $this->score_matrix[$i - 1][$j] - 1;
                $insert = $this->score_matrix[$i][$j - 1] - 1;
                $this->score_matrix[$i][$j] = max($match, $delete, $insert);
                if ($this->score_matrix[$i][$j] == $match) {
                    $this->traceback_matrix[$i][$j] = 1;
                } elseif ($this->score_matrix[$i][$j] == $delete) {
                    $this->traceback_matrix[$i][$j] = 2;
                } else {
                    $this->traceback_matrix[$i][$j] = 3;
                }
                if ($this->score_matrix[$i][$j] > $this->max_score) {
                    $this->max_score = $this->score_matrix[$i][$j];
                    $this->max_position = [$i, $j];
                }
            }
        }
    }

    function backtrack() {
        $aligned_seq1 = [];
        $aligned_seq2 = [];
        list($i, $j) = $this->max_position;
        while ($i > 0 && $j > 0) {
            if ($this->traceback_matrix[$i][$j] == 1) {
                array_push($aligned_seq1, $this->seq1[$i - 1]);
                array_push($aligned_seq2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($this->traceback_matrix[$i][$j] == 2) {
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
    $seq1 = 'AGCTG';
    $seq2 = 'CGTAT';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->initialize_matrices();
    $aligner->fill_matrices();
    list($aligned_seq1, $aligned_seq2) = $aligner->backtrack();
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
}

main();

?>