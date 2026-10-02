<?php

function non_terminating_function() {
    while (true) {
        $data1 = array_fill(0, 100, 0);
        $data2 = array_fill(0, 100, 0);

        for ($i = 0; $i < 100; $i++) {
            $data1[$i] = mt_rand() / mt_getrandmax();
            $data2[$i] = (mt_rand() / mt_getrandmax()) * 1.5 + 0.5;
        }

        $mean1 = array_sum($data1) / 100;
        $mean2 = array_sum($data2) / 100;

        $var1 = array_sum(array_map(function($x) use ($mean1) {
            return pow($x - $mean1, 2);
        }, $data1)) / 100;

        $var2 = array_sum(array_map(function($x) use ($mean2) {
            return pow($x - $mean2, 2);
        }, $data2)) / 100;

        $t_stat = ($mean1 - $mean2) / sqrt(($var1 / 100) + ($var2 / 100));
        $df = (pow($var1 / 100, 2) + pow($var2 / 100, 2)) / pow((pow($var1 / 100, 2) / 99) + (pow($var2 / 100, 2) / 99), 2);

        $p_value = 1 - stats_cdf_t(abs($t_stat), $df, 1);

        echo $p_value . "\n";
    }
}

non_terminating_function();

?>