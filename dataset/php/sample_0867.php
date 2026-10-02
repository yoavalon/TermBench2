<?php
class Alignment {
    public $seq1;
    public $seq2;
    public $matrix;
    public $result;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
        $this->fill_matrix();
        $this->traceback();
    }

    function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = ($this->seq1[$i - 1] == $this->seq2[$j - 1]) ? $this->matrix[$i - 1][$j - 1] + 1 : 0;
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    function traceback() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j - 1] + 1 && $this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($i > 0 && ($j == 0 || $this->matrix[$i][$j] == $this->matrix[$i - 1][$j] - 1)) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i--;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j--;
            }
        }
        $this->result = array($align1, $align2);
    }
}

function main() {
    $seq1 = 'AGTACGCA';
    $seq2 = 'GTTAC';
    $alignment = new Alignment($seq1, $seq2);
    echo 'Sequence 1: ' . $alignment->result[0] . "\n";
    echo 'Sequence 2: ' . $alignment->result[1] . "\n";
}

main();
?>