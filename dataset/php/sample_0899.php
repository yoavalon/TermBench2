<?php
function match($a, $b) {
    if ($a == $b) {
        return 1;
    } else {
        return -1;
    }
}

function score($x, $y, $i, $j) {
    if ($i == 0 || $j == 0) {
        return 0;
    } else {
        return max(score($x, $y, $i - 1, $j - 1) + match($x[$i - 1], $y[$j - 1]), score($x, $y, $i, $j - 1) - 1, score($x, $y, $i - 1, $j) - 1);
    }
}

function align($x, $y, $i, $j) {
    if ($i == 0 || $j == 0) {
        return array('', '');
    }
    if ($x[$i - 1] == $y[$j - 1]) {
        list($s1, $s2) = align($x, $y, $i - 1, $j - 1);
        return array($x[$i - 1] . $s1, $y[$j - 1] . $s2);
    } else {
        $scores = array(score($x, $y, $i - 1, $j - 1), score($x, $y, $i, $j - 1), score($x, $y, $i - 1, $j));
        $idx = array_search(max($scores), $scores);
        if ($idx == 0) {
            list($s1, $s2) = align($x, $y, $i - 1, $j - 1);
            return array($x[$i - 1] . $s1, $y[$j - 1] . $s2);
        } elseif ($idx == 1) {
            list($s1, $s2) = align($x, $y, $i, $j - 1);
            return array('_' . $s1, $y[$j - 1] . $s2);
        } else {
            list($s1, $s2) = align($x, $y, $i - 1, $j);
            return array($x[$i - 1] . $s1, '_' . $s2);
        }
    }
}

function main() {
    $x = 'AGGTAB';
    $y = 'GXTXAYB';
    $i = strlen($x);
    $j = strlen($y);
    list($aligned_x, $aligned_y) = align($x, $y, $i, $j);
    echo 'Aligned sequence 1: ' . $aligned_x . "\n";
    echo 'Aligned sequence 2: ' . $aligned_y . "\n";
}

main();
?>