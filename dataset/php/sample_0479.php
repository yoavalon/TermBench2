<?php
function generate_data($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = randn(0, 1);
    }
    return $data;
}

function calculate_pvalue($data) {
    $mean = array_sum($data) / count($data);
    $t_stat = $mean / (array_sum(array_map(function($x) use ($mean) { return pow($x - $mean, 2); }, $data)) / count($data)) ** 0.5;
    $p_value = 1 - abs($t_stat) / 3;
    return $p_value;
}

function randn($mu = 0, $sigma = 1) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2 * mt_rand() / mt_getrandmax() - 1;
        $b = 2 * mt_rand() / mt_getrandmax() - 1;
        $z = pow($a, 2) + pow($b, 2);
    } while ($z >= 1);
    return $mu + $sigma * sqrt(-2 * log($z) / $z) * $a;
}

function main() {
    while (true) {
        $data = generate_data(100);
        $p_value = calculate_pvalue($data);
        if ($p_value < 0.05) {
            echo 'Significant result: ' . $p_value . PHP_EOL;
        }
    }
}

main();
?>