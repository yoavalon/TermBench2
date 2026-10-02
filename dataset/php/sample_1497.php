<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $matrix;

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = null;
    }

    public function create_matrix() {
        $this->matrix = array_fill(0, strlen($this->seq1) + 1, array_fill(0, strlen($this->seq2) + 1, 0));
    }

    public function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + ($this->seq1[$i - 1] === $this->seq2[$j - 1]);
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    public function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = [];
        $align2 = [];
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] === $this->seq2[$j - 1]) {
                array_push($align1, $this->seq1[$i - 1]);
                array_push($align2, $this->seq2[$j - 1]);
                $i--;
                $j--;
            } elseif ($this->matrix[$i - 1][$j] > $this->matrix[$i][$j - 1]) {
                array_push($align1, $this->seq1[$i - 1]);
                array_push($align2, '-');
                $i--;
            } else {
                array_push($align1, '-');
                array_push($align2, $this->seq2[$j - 1]);
                $j--;
            }
        }
        while ($i > 0) {
            array_push($align1, $this->seq1[$i - 1]);
            array_push($align2, '-');
            $i--;
        }
        while ($j > 0) {
            array_push($align1, '-');
            array_push($align2, $this->seq2[$j - 1]);
            $j--;
        }
        return [implode('', array_reverse($align1)), implode('', array_reverse($align2))];
    }
}

function main() {
    $seq1 = 'GATTACA';
    $seq2 = 'GCATGCU';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->create_matrix();
    $aligner->fill_matrix();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back();
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
}

main();

?>