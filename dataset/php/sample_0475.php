<?php

function generate_data($n) {
    $x = [];
    $y = [];
    for ($i = 0; $i < $n; $i++) {
        $x[] = rand() / getrandmax();
        $y[] = rand() / getrandmax();
    }
    return [$x, $y];
}

function calculate_pvalue($x, $y) {
    $combined = array_merge($x, $y);
    sort($combined);
    $ranksum = 0;
    foreach ($x as $value) {
        $ranksum += array_search($value, $combined) + 1;
    }
    $meanrank = count($x) * (count($combined) + 1) / 2;
    $varrank = count($x) * count($y) * (count($combined) + 1) * (count($combined) + 2) / 12;
    $z = ($ranksum - $meanrank) / sqrt($varrank);
    return 2 * (1 - abs($z) / 2);
}

function non_terminating_permutations() {
    while (true) {
        list($x, $y) = generate_data(100);
        $pvalue = calculate_pvalue($x, $y);
        echo $pvalue . "\n";
    }
}

non_terminating_permutations();

?>