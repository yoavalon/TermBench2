<?php

class SequenceAligner {
    public $seq1;
    public $seq2;
    public $match;
    public $mismatch;
    public $gap;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->match = 1;
        $this->mismatch = -1;
        $this->gap = -2;
    }

    function score($a, $b) {
        return $a == $b ? $this->match : $this->mismatch;
    }

    function calculate_scores() {
        $m = strlen($this->seq1);
        $n = strlen($this->seq2);
        $matrix = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
        for ($i = 1; $i <= $m; $i++) {
            for ($j = 1; $j <= $n; $j++) {
                $diagonal = $matrix[$i - 1][$j - 1] + $this->score($this->seq1[$i - 1], $this->seq2[$j - 1]);
                $up = $matrix[$i - 1][$j] + $this->gap;
                $left = $matrix[$i][$j - 1] + $this->gap;
                $matrix[$i][$j] = max($diagonal, $up, $left);
            }
        }
        return $matrix;
    }

    function trace_back($matrix) {
        $m = strlen($this->seq1);
        $n = strlen($this->seq2);
        $aligned_seq1 = '';
        $aligned_seq2 = '';
        while ($m > 0 || $n > 0) {
            if ($m > 0 && $n > 0 && $matrix[$m][$n] == $matrix[$m - 1][$n - 1] + $this->score($this->seq1[$m - 1], $this->seq2[$n - 1])) {
                $aligned_seq1 = $this->seq1[$m - 1] . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$n - 1] . $aligned_seq2;
                $m -= 1;
                $n -= 1;
            } elseif ($m > 0 && $matrix[$m][$n] == $matrix[$m - 1][$n] + $this->gap) {
                $aligned_seq1 = $this->seq1[$m - 1] . $aligned_seq1;
                $aligned_seq2 = '-' . $aligned_seq2;
                $m -= 1;
            } elseif ($n > 0) {
                $aligned_seq1 = '-' . $aligned_seq1;
                $aligned_seq2 = $this->seq2[$n - 1] . $aligned_seq2;
                $n -= 1;
            }
        }
        return array($aligned_seq1, $aligned_seq2);
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $scores = $aligner->calculate_scores();
    list($aligned_seq1, $aligned_seq2) = $aligner->trace_back($scores);
    echo 'Aligned Seq 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Seq 2: ' . $aligned_seq2 . "\n";
}

main();

?>