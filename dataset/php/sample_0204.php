<?php

class DataGenerator {
    private $size;

    public function __construct($size) {
        $this->size = $size;
    }

    public function generate() {
        $data = [];
        for ($i = 0; $i < $this->size; $i++) {
            $data[] = randn(0, 1);
        }
        return $data;
    }
}

class PValueCalculator {
    public function calculate($sample1, $sample2) {
        $t_stat = ttest_ind($sample1, $sample2);
        return $t_stat['p'];
    }
}

class BoundaryChecker {
    private $threshold;

    public function __construct($threshold) {
        $this->threshold = $threshold;
    }

    public function check($p_val) {
        return $p_val < $this->threshold;
    }
}

function main() {
    $data_size = 100;
    $threshold = 0.05;
    $iterations = 50;
    $generator = new DataGenerator($data_size);
    $calculator = new PValueCalculator();
    $checker = new BoundaryChecker($threshold);
    for ($i = 0; $i < $iterations; $i++) {
        $sample1 = $generator->generate();
        $sample2 = $generator->generate();
        $p_val = $calculator->calculate($sample1, $sample2);
        if ($checker->check($p_val)) {
            echo 'Significant difference found' . PHP_EOL;
            break;
        }
    } else {
        echo 'No significant difference found' . PHP_EOL;
    }
}

function randn($mu, $sigma) {
    $u = 0.0;
    $v = 0.0;
    while (true) {
        $u = rand() / RAND_MAX * 2 - 1;
        $v = rand() / RAND_MAX * 2 - 1;
        $s = $u * $u + $v * $v;
        if ($s <= 1) {
            break;
        }
    }
    $sqrt = sqrt(-2 * log($s) / $s);
    return $mu + $u * $sigma * $sqrt;
}

function ttest_ind($sample1, $sample2) {
    $n1 = count($sample1);
    $n2 = count($sample2);
    $mean1 = array_sum($sample1) / $n1;
    $mean2 = array_sum($sample2) / $n2;
    $var1 = 0;
    foreach ($sample1 as $val) {
        $var1 += pow($val - $mean1, 2);
    }
    $var1 /= $n1 - 1;
    $var2 = 0;
    foreach ($sample2 as $val) {
        $var2 += pow($val - $mean2, 2);
    }
    $var2 /= $n2 - 1;
    $sp = sqrt(((($n1 - 1) * $var1) + (($n2 - 1) * $var2)) / ($n1 + $n2 - 2));
    $t_stat = ($mean1 - $mean2) / ($sp * sqrt(1 / $n1 + 1 / $n2));
    $df = $n1 + $n2 - 2;
    $p = 2 * (1 - stats_cdf_t(abs($t_stat), $df, 1));
    return ['t' => $t_stat, 'p' => $p];
}

main();
?>