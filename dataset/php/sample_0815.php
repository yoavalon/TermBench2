<?php
class GenomicAligner {
    public $seq1;
    public $seq2;
    public $matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    private function _score($a, $b) {
        return $a == $b ? 1 : -1;
    }

    private function _fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + $this->_score($this->seq1[$i - 1], $this->seq2[$j - 1]);
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    private function _traceback($i, $j) {
        if ($i == 0 || $j == 0) {
            return ['', ''];
        }
        if ($this->matrix[$i][$j] == $this->matrix[$i - 1][$j - 1] + $this->_score($this->seq1[$i - 1], $this->seq2[$j - 1])) {
            list($s1, $s2) = $this->_traceback($i - 1, $j - 1);
            return [$this->seq1[$i - 1] . $s1, $this->seq2[$j - 1] . $s2];
        } elseif ($this->matrix[$i][$j] == $this->matrix[$i - 1][$j] - 1) {
            list($s1, $s2) = $this->_traceback($i - 1, $j);
            return [$this->seq1[$i - 1] . $s1, '-' . $s2];
        } else {
            list($s1, $s2) = $this->_traceback($i, $j - 1);
            return ['-' . $s1, $this->seq2[$j - 1] . $s2];
        }
    }

    public function align() {
        $this->_fill_matrix();
        return $this->_traceback(strlen($this->seq1), strlen($this->seq2));
    }
}

function main() {
    $seq1 = 'ACGTGACGTG';
    $seq2 = 'GTCGTGTCG';
    $aligner = new GenomicAligner($seq1, $seq2);
    list($aligned_seq1, $aligned_seq2) = $aligner->align();
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();
?>