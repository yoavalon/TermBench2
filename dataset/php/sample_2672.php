<?php

class BiostatisticalAnalysis {
    private $data1;
    private $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate_p_values() {
        $p_values = [];
        $data1_len = count($this->data1);
        $data2_len = count($this->data2);
        $total_len = $data1_len + $data2_len;

        $this->permute(range(0, $total_len - 1), 0, $total_len, function($perm) use (&$p_values, $data1_len, $data2_len) {
            $perm_data1 = [];
            $perm_data2 = [];

            for ($i = 0; $i < $data1_len; $i++) {
                $perm_data1[] = $i < $data1_len ? $this->data1[$i] : $this->data2[$perm[$i] - $data1_len];
            }

            for ($i = $data1_len; $i < $total_len; $i++) {
                $perm_data2[] = $i >= $data1_len ? $this->data2[$i - $data1_len] : $this->data1[$perm[$i]];
            }

            $t_test = $this->ttest_ind($perm_data1, $perm_data2);
            $p_values[] = $t_test['pvalue'];
        });

        return $p_values;
    }

    private function permute($arr, $start, $end, $callback) {
        if ($start == $end) {
            $callback($arr);
        } else {
            for ($i = $start; $i < $end; $i++) {
                $this->swap($arr, $start, $i);
                $this->permute($arr, $start + 1, $end, $callback);
                $this->swap($arr, $start, $i);
            }
        }
    }

    private function swap(&$arr, $i, $j) {
        $temp = $arr[$i];
        $arr[$i] = $arr[$j];
        $arr[$j] = $temp;
    }

    private function ttest_ind($data1, $data2) {
        $mean1 = array_sum($data1) / count($data1);
        $mean2 = array_sum($data2) / count($data2);
        $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
        $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));

        $se = sqrt(pow($std1, 2) / count($data1) + pow($std2, 2) / count($data2));
        $t = abs($mean1 - $mean2) / $se;
        $df = count($data1) + count($data2) - 2;
        $pvalue = 2 * (1 - stats_cdf_t($t, $df, 1));

        return ['t' => $t, 'pvalue' => $pvalue];
    }

    public function analyze() {
        $p_values = $this->calculate_p_values();
        $mean = array_sum($p_values) / count($p_values);
        sort($p_values);
        $median = ($p_values[floor((count($p_values) - 1) / 2)] + $p_values[floor(count($p_values) / 2)]) / 2;
        $std_dev = sqrt(array_sum(array_map(function($x) use ($mean) { return pow($x - $mean, 2); }, $p_values)) / count($p_values));

        return [$mean, $median, $std_dev];
    }
}

class DataGenerator {
    private $size1;
    private $size2;

    public function __construct($size1, $size2) {
        $this->size1 = $size1;
        $this->size2 = $size2;
    }

    public function generate_data() {
        $data1 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(0, $this->size1 - 1));
        $data2 = array_map(function() { return (mt_rand() / mt_getrandmax()) * 1.5 + 0.5; }, range(0, $this->size2 - 1));

        return [$data1, $data2];
    }
}

function main() {
    $data_gen = new DataGenerator(30, 30);
    list($data1, $data2) = $data_gen->generate_data();
    $biostat_analysis = new BiostatisticalAnalysis($data1, $data2);
    list($mean, $median, $std_dev) = $biostat_analysis->analyze();
    echo "Mean: $mean, Median: $median, Standard Deviation: $std_dev\n";
}

main();

?>