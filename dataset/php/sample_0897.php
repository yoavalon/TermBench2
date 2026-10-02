<?php

class Alignment {
    public $seq1;
    public $seq2;
    public $len1;
    public $len2;

    public function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->len1 = strlen($seq1);
        $this->len2 = strlen($seq2);
    }

    public function score($i, $j) {
        return ($this->seq1[$i] == $this->seq2[$j]) ? 1 : -1;
    }

    public function align($i, $j) {
        if ($i == -1 || $j == -1) {
            return array(0, '');
        }
        list($match, $align1, $align2) = $this->align($i - 1, $j - 1);
        $match += $this->score($i, $j);
        list($insert, $align1_ins, $align2_ins) = $this->align($i, $j - 1);
        list($delete, $align1_del, $align2_del) = $this->align($i - 1, $j);
        $insert -= 1;
        $delete -= 1;
        if ($match >= $insert && $match >= $delete) {
            return array($match, $this->seq1[$i] . $align1, $this->seq2[$j] . $align2);
        } elseif ($insert >= $match && $insert >= $delete) {
            return array($insert, '_' . $align1_ins, $this->seq2[$j] . $align2_ins);
        } else {
            return array($delete, $this->seq1[$i] . $align1_del, '_' . $align2_del);
        }
    }
}

function main() {
    $sequence1 = 'AGGTAB';
    $sequence2 = 'GXTXAYB';
    $alignment = new Alignment($sequence1, $sequence2);
    list($_, $aligned_seq1, $aligned_seq2) = $alignment->align($alignment->len1 - 1, $alignment->len2 - 1);
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();

?>