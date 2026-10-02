<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn();
    }
    return $data;
}

function randn() {
    $u = 0.0;
    $v = 0.0;
    while (true) {
        $u = 2 * mt_rand() / mt_getrandmax() - 1;
        $v = 2 * mt_rand() / mt_getrandmax() - 1;
        $s = $u * $u + $v * $v;
        if ($s <= 1) {
            break;
        }
    }
    $x = $u * sqrt(-2 * log($s) / $s);
    return $x;
}

function calculate_p_value($sample1, $sample2) {
    $t_stat = 0.0;
    $df = count($sample1) + count($sample2) - 2;
    $mean1 = array_sum($sample1) / count($sample1);
    $mean2 = array_sum($sample2) / count($sample2);
    $var1 = 0.0;
    $var2 = 0.0;
    foreach ($sample1 as $value) {
        $var1 += pow($value - $mean1, 2);
    }
    foreach ($sample2 as $value) {
        $var2 += pow($value - $mean2, 2);
    }
    $var1 /= count($sample1) - 1;
    $var2 /= count($sample2) - 1;
    $pooled_var = (($df * ($var1 + $var2)) / ($df - 2));
    $t_stat = ($mean1 - $mean2) / sqrt($pooled_var * (1 / count($sample1) + 1 / count($sample2)));
    $p_value = betainc($df / 2, $df / 2, $df / ($df + $t_stat * $t_stat));
    return $p_value;
}

function betainc($a, $b, $x) {
    return incomplete_beta($a, $b, $x) / beta_function($a, $b);
}

function incomplete_beta($a, $b, $x) {
    if ($x == 0) return 0;
    if ($x == 1) return beta_function($a, $b);
    $apb = $a + $b;
    $bet = beta_function($a, $b);
    $front = pow($x, $a) * pow(1 - $x, $b) / $bet;
    $a0 = 1;
    $b0 = 1;
    $c0 = 1;
    $d0 = 0;
    $h = $a0;
    for ($m = 1; $m <= 1000; $m++) {
        $an = $m * ($m + $apb - 1) * ($m + $a - 1) * $x / (($a + 2 * $m - 1) * ($a + 2 * $m - 2));
        $bn = $m * ($m + $apb - 1) * ($m + $b - 1) * (1 - $x) / (($b + 2 * $m - 1) * ($b + 2 * $m - 2));
        $am = $a0 * $an + $b0 * $bn;
        $bm = $b0 * $an + $c0 * $bn;
        $cm = $c0 * $am + $d0 * $bn;
        $dm = $d0 * $am + $c0 * $bn;
        if ($cm != 0) {
            $dn = $dm / $cm;
            $h = $h * $dn;
            $c0 = $am / $cm;
            $d0 = $bm / $cm;
        }
        if (abs($dn - 1) < 1e-10) {
            break;
        }
    }
    return $front * $h;
}

function beta_function($a, $b) {
    return gamma_function($a) * gamma_function($b) / gamma_function($a + $b);
}

function gamma_function($x) {
    if ($x == 1) return 1;
    if ($x == 0.5) return sqrt(pi());
    return ($x - 1) * gamma_function($x - 1);
}

function main() {
    $sample_size = 30;
    $num_permutations = 1000;
    $p_values = [];
    for ($i = 0; $i < $num_permutations; $i++) {
        $data1 = generate_data($sample_size);
        $data2 = generate_data($sample_size);
        $p_values[] = calculate_p_value($data1, $data2);
    }
    $mean_p_value = array_sum($p_values) / count($p_values);
    echo $mean_p_value;
}

main();