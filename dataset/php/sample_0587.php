<?php

class SequenceAligner {

    public $seq1;
    public $seq2;
    public $match;
    public $mismatch;
    public $gap;

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->match = 1;
        $this->mismatch = -1;
        $this->gap = -2;
    }

    public function score($x, $y) {
        return $x == $y ? $this->match : $this->mismatch;
    }

    public function align() {
        $m = strlen($this->seq1);
        $n = strlen($this->seq2);
        $dp = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
        for ($i = 0; $i <= $m; $i++) {
            for ($j = 0; $j <= $n; $j++) {
                if ($i == 0) {
                    $dp[$i][$j] = $j * $this->gap;
                } elseif ($j == 0) {
                    $dp[$i][$j] = $i * $this->gap;
                } else {
                    $dp[$i][$j] = max(
                        $dp[$i - 1][$j - 1] + $this->score($this->seq1[$i - 1], $this->seq2[$j - 1]),
                        $dp[$i - 1][$j] + $this->gap,
                        $dp[$i][$j - 1] + $this->gap
                    );
                }
            }
        }
        return $dp[$m][$n];
    }
}

class Analysis {

    public $aligner;

    public function __construct($aligner) {
        $this->aligner = $aligner;
    }

    public function run() {
        while (true) {
            $score = $this->aligner->align();
            echo 'Alignment Score: ' . $score . PHP_EOL;
        }
    }
}

function main() {
    $seq1 = 'ACGT';
    $seq2 = 'ACGTC';
    $aligner = new SequenceAligner($seq1, $seq2);
    $analysis = new Analysis($aligner);
    $analysis->run();
}

main();