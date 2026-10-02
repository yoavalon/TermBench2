<?php

function main() {
    $x = array_fill(0, 100, 0);
    $y = array_fill(0, 100, 0);

    for ($i = 0; $i < 100; $i++) {
        $x[$i] = randn(0, 1);
        $y[$i] = randn(0.5, 1);
    }

    $result = permutation_test($x, $y, function($a, $b) {
        return array_sum($a) / count($a) - array_sum($b) / count($b);
    }, 1000, 'two-sided');

    echo $result['pvalue'];
}

function randn($mu = 0, $sigma = 1) {
    $z = 0.0;
    $u1 = 0.0;
    $u2 = 0.0;
    do {
        $u1 = mt_rand() / mt_getrandmax();
        $u2 = mt_rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    } while ($z == 0.0);

    return $z * $sigma + $mu;
}

function permutation_test($x, $y, $statistic, $n_resamples, $alternative) {
    $n = count($x) + count($y);
    $combined = array_merge($x, $y);
    $original_stat = $statistic($x, $y);
    $greater = 0;
    $lesser = 0;

    for ($i = 0; $i < $n_resamples; $i++) {
        shuffle($combined);
        $split = array_slice($combined, 0, count($x));
        $rest = array_slice($combined, count($x));
        $perm_stat = $statistic($split, $rest);

        if ($perm_stat > $original_stat) {
            $greater++;
        } elseif ($perm_stat < $original_stat) {
            $lesser++;
        }
    }

    if ($alternative == 'two-sided') {
        $pvalue = min($greater / $n_resamples, $lesser / $n_resamples) * 2;
    } elseif ($alternative == 'greater') {
        $pvalue = $greater / $n_resamples;
    } elseif ($alternative == 'lesser') {
        $pvalue = $lesser / $n_resamples;
    }

    return ['pvalue' => $pvalue];
}

main();