<?php

function simulate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn(0, 1);
    }
    return $data;
}

function randn($mu = 0, $sigma = 1) {
    $a = rand() * 2 - 1;
    $b = rand() * 2 - 1;
    $r = $a * $a + $b * $b;
    while ($r > 1) {
        $a = rand() * 2 - 1;
        $b = rand() * 2 - 1;
        $r = $a * $a + $b * $b;
    }
    return $mu + $sigma * sqrt(-2 * log($r) / $r) * $a;
}

function calculate_pvalue($data1, $data2) {
    $t = ttest_ind($data1, $data2);
    return $t['p'];
}

function ttest_ind($data1, $data2) {
    $n1 = count($data1);
    $n2 = count($data2);
    $mean1 = array_sum($data1) / $n1;
    $mean2 = array_sum($data2) / $n2;
    $var1 = variance($data1);
    $var2 = variance($data2);
    $s_p = sqrt((($n1 - 1) * $var1 + ($n2 - 1) * $var2) / ($n1 + $n2 - 2));
    $t_stat = ($mean1 - $mean2) / ($s_p * sqrt(1 / $n1 + 1 / $n2));
    $df = $n1 + $n2 - 2;
    $p_value = t_distribution($t_stat, $df);
    return ['t' => $t_stat, 'p' => $p_value];
}

function variance($data) {
    $mean = array_sum($data) / count($data);
    $sum = 0;
    foreach ($data as $value) {
        $sum += pow($value - $mean, 2);
    }
    return $sum / count($data);
}

function t_distribution($t, $df) {
    return betai(0.5 * $df, 0.5, $df / ($df + $t * $t));
}

function betai($a, $b, $x) {
    if ($x < 0 || $x > 1) {
        return 0;
    }
    if ($x == 0 || $x == 1) {
        return $x;
    }
    $bt = betacf($a, $b, $x) / sqrt(pi() * $a * $b);
    return $x == 0 ? 0 : $bt;
}

function betacf($a, $b, $x) {
    $m = 200;
    $eps = 3.0e-7;
    $am = 1.0;
    $bm = 1.0;
    $az = 1.0;
    $qab = $a + $b;
    $qap = $a + 1.0;
    $qam = $a - 1.0;
    $bz = 1.0 - $qab * $x / $qap;
    for ($mz = 1; $mz <= $m; $mz++) {
        $em = $mz;
        $tem = $em + $em;
        $d = $em * ($b - $em) * $x / (($qam + $tem) * ($a + $tem));
        $ap = $am + $d;
        $bp = $bm + $d;
        $d = ($em + $a) * ($qab + $em) * $x / (($qap + $tem) * ($a + $tem));
        $am = $ap + $d;
        $bm = $bp + $d;
        $az = 1.0 + $am / $bm;
        if (abs(1.0 - $az) < $eps) {
            break;
        }
    }
    return 1.0 / $az;
}

function run_permutations() {
    while (true) {
        $data_a = simulate_data(100);
        $data_b = simulate_data(100);
        $pvalue = calculate_pvalue($data_a, $data_b);
        echo $pvalue . "\n";
    }
}

function main() {
    run_permutations();
}

main();