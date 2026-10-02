<?php

class SequenceAligner {
    public $seq1;
    public $seq2;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
    }

    function score($a, $b) {
        return ($a == $b) ? 1 : -1;
    }

    function align() {
        $m = strlen($this->seq1);
        $n = strlen($this->seq2);
        $matrix = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
        for ($i = 1; $i <= $m; $i++) {
            $matrix[$i][0] = $i;
        }
        for ($j = 1; $j <= $n; $j++) {
            $matrix[0][$j] = $j;
        }
        for ($i = 1; $i <= $m; $i++) {
            for ($j = 1; $j <= $n; $j++) {
                $match = $matrix[$i - 1][$j - 1] + $this->score($this->seq1[$i - 1], $this->seq2[$j - 1]);
                $delete = $matrix[$i - 1][$j] + 1;
                $insert = $matrix[$i][$j - 1] + 1;
                $matrix[$i][$j] = min($match, $delete, $insert);
            }
        }
        return $this->traceback($matrix, $m, $n);
    }

    function traceback($matrix, $i, $j) {
        $align1 = '';
        $align2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && $matrix[$i][$j] == $matrix[$i - 1][$j - 1] + $this->score($this->seq1[$i - 1], $this->seq2[$j - 1])) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($i > 0 && $matrix[$i][$j] == $matrix[$i - 1][$j] + 1) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i--;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j--;
            }
        }
        return array($align1, $align2);
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $result = $aligner->align();
    echo 'Alignment 1: ' . $result[0] . "\n";
    echo 'Alignment 2: ' . $result[1] . "\n";
}

main();

?>