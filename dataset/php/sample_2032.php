<?php
class SequenceAligner {
    public $seq1;
    public $seq2;
    public $matrix;

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    }

    function compute_score($a, $b) {
        return ($a == $b) ? 1 : -1;
    }

    function fill_matrix() {
        for ($i = 1; $i <= strlen($this->seq1); $i++) {
            for ($j = 1; $j <= strlen($this->seq2); $j++) {
                $match = $this->matrix[$i - 1][$j - 1] + $this->compute_score($this->seq1[$i - 1], $this->seq2[$j - 1]);
                $delete = $this->matrix[$i - 1][$j] - 1;
                $insert = $this->matrix[$i][$j - 1] - 1;
                $this->matrix[$i][$j] = max($match, $delete, $insert);
            }
        }
    }

    function trace_back() {
        $i = strlen($this->seq1);
        $j = strlen($this->seq2);
        $align1 = '';
        $align2 = '';
        while ($i > 0 || $j > 0) {
            if ($i > 0 && $j > 0 && ($this->matrix[$i][$j] == $this->matrix[$i - 1][$j - 1] + $this->compute_score($this->seq1[$i - 1], $this->seq2[$j - 1]))) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $i -= 1;
                $j -= 1;
            } elseif ($i > 0 && $this->matrix[$i][$j] == $this->matrix[$i - 1][$j] - 1) {
                $align1 = $this->seq1[$i - 1] . $align1;
                $align2 = '-' . $align2;
                $i -= 1;
            } else {
                $align1 = '-' . $align1;
                $align2 = $this->seq2[$j - 1] . $align2;
                $j -= 1;
            }
        }
        return array($align1, $align2);
    }
}

function main() {
    $seq1 = 'ACGT';
    $seq2 = 'ACGTA';
    $aligner = new SequenceAligner($seq1, $seq2);
    $aligner->fill_matrix();
    $aligned_sequences = $aligner->trace_back();
    echo 'Aligned Sequence 1: ' . $aligned_sequences[0] . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_sequences[1] . "\n";
}

main();
?>