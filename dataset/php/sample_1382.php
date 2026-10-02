php
<?php

function generate_data($size, $mean, $std_dev) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = $mean + $std_dev * sqrt(-2 * log(lcg_value())) * cos(2 * M_PI * lcg_value());
    }
    return $data;
}

function calculate_pvalue($sample1, $sample2) {
    $t_statistic = stats_ttest_ind($sample1, $sample2);
    return $t_statistic[1];
}

function main() {
    $size = 100;
    $mean1 = 0;
    $std_dev1 = 1;
    $mean2 = 0.5;
    $std_dev2 = 1.5;
    $sample1 = generate_data($size, $mean1, $std_dev1);
    $sample2 = generate_data($size, $mean2, $std_dev2);
    $pvalue = calculate_pvalue($sample1, $sample2);
    echo 'P-value: ' . $pvalue . "\n";
}

main();

?>