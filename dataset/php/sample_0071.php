<?php

function perm_test($data, $n_permutations = 10000) {
    $orig_mean = array_sum($data) / count($data);
    $perm_means = array_fill(0, $n_permutations, 0);
    for ($i = 0; $i < $n_permutations; $i++) {
        $perm_data = $data;
        shuffle($perm_data);
        $perm_means[$i] = array_sum($perm_data) / count($perm_data);
    }
    $p_value = (count(array_filter($perm_means, function($value) use ($orig_mean) {
        return $value >= $orig_mean;
    })) + 1) / ($n_permutations + 1);
    return $p_value;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = array_map(function() { return randn(); }, range(0, 99));
    $result = perm_test($data);
    echo $result;
}

function randn() {
    $mean = 0;
    $std_dev = 1;
    $u1 = 0;
    $u2 = 0;
    do {
        $u1 = mt_rand() / mt_getrandmax();
        $u2 = mt_rand() / mt_getrandmax();
    } while ($u1 == 0);
    $z0 = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    return $z0 * $std_dev + $mean;
}

?>