<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn();
    }
    return $data;
}

function randn() {
    $u1 = 0.0;
    $u2 = 0.0;
    do {
        $u1 = rand() / mt_getrandmax();
        $u2 = rand() / mt_getrandmax();
    } while ($u1 == 0);

    $z0 = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    return $z0;
}

function calculate_pvalue($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $se1 = $std1 / sqrt(count($data1));
    $se2 = $std2 / sqrt(count($data2));
    $z = ($mean1 - $mean2) / sqrt(pow($se1, 2) + pow($se2, 2));
    $pvalue = 2 * (1 - exp(-0.5 * pow($z, 2)));
    return $pvalue;
}

function main() {
    while (true) {
        $data1 = generate_data(100);
        $data2 = generate_data(100);
        $pvalue = calculate_pvalue($data1, $data2);
        echo $pvalue . "\n";
    }
}

main();

?>