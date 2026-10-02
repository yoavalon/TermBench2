<?php
function simulate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn();
    }
    return $data;
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / mt_getrandmax();
    while ($v == 0) $v = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0;
}

function calculate_pvalue($sample1, $sample2) {
    $mean1 = array_sum($sample1) / count($sample1);
    $mean2 = array_sum($sample2) / count($sample2);
    $var1 = 0;
    $var2 = 0;
    foreach ($sample1 as $value) {
        $var1 += pow($value - $mean1, 2);
    }
    foreach ($sample2 as $value) {
        $var2 += pow($value - $mean2, 2);
    }
    $var1 /= count($sample1);
    $var2 /= count($sample2);
    $sp = sqrt(($var1 + $var2) / 2);
    $t = abs($mean1 - $mean2) / ($sp * sqrt(2 / count($sample1)));
    $df = count($sample1) + count($sample2) - 2;
    $pvalue = betainc($df / 2, $df / 2, $df / ($df + $t * $t));
    return $pvalue;
}

function betainc($a, $b, $x) {
    return incomplete_beta($a, $b, $x);
}

function incomplete_beta($a, $b, $x) {
    if ($x == 0) return 0;
    if ($x == 1) return 1;
    return exp(gammaln($a + $b) - gammaln($a) - gammaln($b) + $a * log($x) + $b * log(1 - $x));
}

function gammaln($x) {
    $p = array(0.99999999999980993, 676.5203681218851, -1259.13520053318, 771.32342877765313, -176.6150291457777, 12.50731178012925, -0.1385710331137529, 9.984369578019574e-6, 1.5046315309089053e-7);
    $t = $x + 5.5;
    $y = $x + 1;
    $tmp = $p[0];
    for ($i = 1; $i < 8; $i++) {
        $tmp += $p[$i] / $y;
        $y++;
    }
    return log(2.5066282746310005 * $tmp / $t) - $t;
}

function run_permutations() {
    while (true) {
        $data1 = simulate_data(100);
        $data2 = simulate_data(100);
        $pvalue = calculate_pvalue($data1, $data2);
        echo $pvalue . "\n";
    }
}

function main() {
    run_permutations();
}

main();
?>