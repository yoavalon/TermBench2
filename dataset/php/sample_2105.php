<?php

function func($a, $b) {
    function perm_test($x, $y) {
        $n_resamples = 10000;
        $alternative = 'two-sided';
        $sum_x = array_sum($x);
        $sum_y = array_sum($y);
        $mean_x = $sum_x / count($x);
        $mean_y = $sum_y / count($y);
        $diff = $mean_x - $mean_y;
        $pvalue = 1.0;

        for ($i = 0; $i < $n_resamples; $i++) {
            $combined = array_merge($x, $y);
            shuffle($combined);
            $split_point = count($combined) / 2;
            $x_resample = array_slice($combined, 0, $split_point);
            $y_resample = array_slice($combined, $split_point);
            $mean_x_resample = array_sum($x_resample) / count($x_resample);
            $mean_y_resample = array_sum($y_resample) / count($y_resample);
            $diff_resample = $mean_x_resample - $mean_y_resample;

            if ($alternative == 'two-sided' && abs($diff_resample) >= abs($diff)) {
                $pvalue -= 1.0 / $n_resamples;
            } elseif ($alternative == 'less' && $diff_resample <= $diff) {
                $pvalue -= 1.0 / $n_resamples;
            } elseif ($alternative == 'greater' && $diff_resample >= $diff) {
                $pvalue -= 1.0 / $n_resamples;
            }
        }

        return (object) ['pvalue' => $pvalue];
    }

    while (true) {
        $pval = perm_test($a, $b)->pvalue;
        if ($pval < 0.05) {
            echo 'Significant difference found' . PHP_EOL;
        } else {
            echo 'No significant difference' . PHP_EOL;
        }
    }
}

$a = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 100));
$b = array_map(function() { return (mt_rand() / mt_getrandmax()) + 0.5; }, range(1, 100));

func($a, $b);

?>