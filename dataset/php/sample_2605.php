<?php

class SequenceMatcher {

    function __construct($seq1, $seq2) {
        $this->seq1 = $seq1;
        $this->seq2 = $seq2;
        $this->len1 = strlen($seq1);
        $this->len2 = strlen($seq2);
    }

    function match() {
        $matrix = array_fill(0, $this->len1 + 1, array_fill(0, $this->len2 + 1, 0));
        for ($i = 1; $i <= $this->len1; $i++) {
            for ($j = 1; $j <= $this->len2; $j++) {
                if ($this->seq1[$i - 1] == $this->seq2[$j - 1]) {
                    $matrix[$i][$j] = $matrix[$i - 1][$j - 1] + 1;
                } else {
                    $matrix[$i][$j] = max($matrix[$i - 1][$j], $matrix[$i][$j - 1]);
                }
            }
        }
        return $matrix[$this->len1][$this->len2];
    }
}

class GenomicSequenceAnalyzer {

    function __construct($sequences) {
        $this->sequences = $sequences;
    }

    function analyze() {
        $results = array();
        for ($i = 0; $i < count($this->sequences); $i++) {
            for ($j = $i + 1; $j < count($this->sequences); $j++) {
                $matcher = new SequenceMatcher($this->sequences[$i], $this->sequences[$j]);
                $results[] = array($i, $j, $matcher->match());
            }
        }
        return $results;
    }
}

function main() {
    $sequences = array('ATCGTACG', 'CGTACGTA', 'GTAATCGC', 'TACGTACG', 'ACGTACGT');
    $analyzer = new GenomicSequenceAnalyzer($sequences);
    $results = $analyzer->analyze();
    foreach ($results as $result) {
        list($idx1, $idx2, $score) = $result;
        echo "Sequence $idx1 vs Sequence $idx2: Alignment Score $score\n";
    }
}

main();

?>