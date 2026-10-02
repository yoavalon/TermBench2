<?php

class SequenceAligner {

    public $seq1;
    public $seq2;
    public $m;
    public $n;
    public $dp;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->m = strlen($seq1);
        $this->n = strlen($seq2);
        $this->dp = array_fill(0, $this->m + 1, array_fill(0, $this->n + 1, 0));
    }

    function calculate_score() {
        for ($i = 1; $i <= $this->m; $i++) {
            for ($j = 1; $j <= $this->n; $j++) {
                if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $this->dp[$i][$j] = $this->dp[$i - 1][$j - 1] + 1;
                } else {
                    $this->dp[$i][$j] = max($this->dp[$i - 1][$j], $this->dp[$i][$j - 1]);
                }
            }
        }
    }

    function traceback() {
        $i = $this->m;
        $j = $this->n;
        $align1 = '';
        $align2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && $this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i--;
                $j--;
            } elseif ($i > 0 && $this->dp[$i][$j] == $this->dp[$i - 1][$j]) {
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
    $aligner->calculate_score();
    $result = $aligner->traceback();
    echo 'Aligned Sequence 1: ' . $result[0] . "\n";
    echo 'Aligned Sequence 2: ' . $result[1] . "\n";
}

main();

?>