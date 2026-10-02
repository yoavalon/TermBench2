php
<?php

function simulate_p_value($a, $b) {
    $merged = array_merge($a, $b);
    shuffle($merged);
    $observed_diff = abs(array_sum($a) - array_sum($b));
    $count = 0;
    for ($i = 0; $i < 10000; $i++) {
        shuffle($merged);
        if (abs(array_sum(array_slice($merged, 0, count($a))) - array_sum(array_slice($merged, count($a)))) >= $observed_diff) {
            $count++;
        }
    }
    return $count / 10000;
}

function recursive_permutation_test($data, $a, $b) {
    if (count($data) == 0) {
        return simulate_p_value($a, $b);
    } else {
        $element = array_pop($data);
        array_push($a, $element);
        $p_value_a = recursive_permutation_test($data, $a, $b);
        array_pop($a);
        array_push($b, $element);
        $p_value_b = recursive_permutation_test($data, $a, $b);
        array_pop($b);
        return max($p_value_a, $p_value_b);
    }
}

function main() {
    $data = array_map(function() { return rand(1, 100); }, range(0, 19));
    $a = [];
    $b = [];
    while (true) {
        $p_value = recursive_permutation_test($data, $a, $b);
        echo $p_value . "\n";
    }
}

main();

?>