<?php

class SequenceAligner {

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->table = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function build_table() {
        for ($i = 0; $i <= strlen($this->seq1); $i++) {
            for ($j = 0; $j <= strlen($this->seq2); $j++) {
                if ($i == 0 || $j == 0) {
                    $this->table[$i][$j] = 0;
                } elseif ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $this->table[$i][$j] = $this->table[$i - 1][$j - 1] + 1;
                } else {
                    $this->table[$i][$j] = max($this->table[$i - 1][$j], $this->table[$i][$j - 1]);
                }
            }
        }
    }

    function traceback() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 && $j > 0) {
            if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i -= 1;
                $j -= 1;
            } elseif ($this->table[$i - 1][$j] > $this->table[$i][$j - 1]) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i -= 1;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j -= 1;
            }
        }
        while ($i > 0) {
            $align1 = $this->seq1[$i - 1] . $align1;
            $align2 = '-' . $align2;
            $i -= 1;
        }
        while ($j > 0) {
            $align1 = '-' . $align1;
            $align2 = $this->seq2[$j - 1] . $align2;
            $j -= 1;
        }
        return array($align1, $align2);
    }

}

function main() {
    $seq1 = 'ACGTGACGGCCG';
    $seq2 = 'ACGTTACGGCCG';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->build_table();
    list($aligned_seq1, $aligned_seq2) = $aligner->traceback();
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
}

main();

?>