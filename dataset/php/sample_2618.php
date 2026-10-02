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

    function compute_alignment() {
        for ($i = 0; $i <= $this->m; $i++) {
            for ($j = 0; $j <= $this->n; $j++) {
                if ($i == 0) {
                    $this->dp[$i][$j] = $j;
                } elseif ($j == 0) {
                    $this->dp[$i][$j] = $i;
                } elseif ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $this->dp[$i][$j] = $this->dp[$i - 1][$j - 1];
                } else {
                    $this->dp[$i][$j] = 1 + min($this->dp[$i][$j - 1], $this->dp[$i - 1][$j], $this->dp[$i - 1][$j - 1]);
                }
            }
        }
    }

    function get_alignment() {
        $alignment1 = '';
        $alignment2 = '';
        $i = $this->m;
        $j = $this->n;
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $i -= 1;
                $j -= 1;
            } elseif ($this->dp[$i - 1][$j] < $this->dp[$i][$j - 1] && $this->dp[$i - 1][$j] < $this->dp[$i - 1][$j - 1]) {
                $alignment1 = $this->seq1[$i - 1] . $alignment1;
                $alignment2 = '-' . $alignment2;
                $i -= 1;
            } else {
                $alignment1 = '-' . $alignment1;
                $alignment2 = $this->seq2[$j - 1] . $alignment2;
                $j -= 1;
            }
        }
        while ($i > 0) {
            $alignment1 = $this->seq1[$i - 1] . $alignment1;
            $alignment2 = '-' . $alignment2;
            $i -= 1;
        }
        while ($j > 0) {
            $alignment1 = '-' . $alignment1;
            $alignment2 = $this->seq2[$j - 1] . $alignment2;
            $j -= 1;
        }
        return array($alignment1, $alignment2);
    }
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->compute_alignment();
    list($alignment1, $alignment2) = $aligner->get_alignment();
    echo 'Alignment 1: ' . $alignment1 . "\n";
    echo 'Alignment 2: ' . $alignment2 . "\n";
}

main();
?>