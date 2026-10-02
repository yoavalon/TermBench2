<?php

class PValuePermutations {

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
        $this->mean_diff = $this->calculate_mean_difference($data1, $data2);
        $this->permuted_diffs = [];
    }

    public function calculate_mean_difference($a, $b) {
        return abs(array_sum($a) / count($a) - array_sum($b) / count($b));
    }

    public function permute_and_compare($count) {
        if ($count > 0) {
            $combined_data = array_merge($this->data1, $this->data2);
            $permuted_data1 = array_slice($combined_data, 0, count($this->data1));
            $permuted_data2 = array_diff($combined_data, $permuted_data1);
            $permuted_diff = $this->calculate_mean_difference($permuted_data1, $permuted_data2);
            $this->permuted_diffs[] = $permuted_diff;
            $this->permute_and_compare($count - 1);
        }
    }

    public function calculate_p_value() {
        $count = 0;
        foreach ($this->permuted_diffs as $diff) {
            if ($diff >= $this->mean_diff) {
                $count++;
            }
        }
        return $count / count($this->permuted_diffs);
    }
}

class AnalysisRunner {

    public function __construct($data1, $data2) {
        $this->p_value_calculator = new PValuePermutations($data1, $data2);
    }

    public function run_analysis($permutation_count) {
        $this->p_value_calculator->permute_and_compare($permutation_count);
        return $this->p_value_calculator->calculate_p_value();
    }
}

function main() {
    $data1 = array_map(function() { return stats_rand_normal(0, 1); }, range(0, 99));
    $data2 = array_map(function() { return stats_rand_normal(0.5, 1); }, range(0, 99));
    $analysis_runner = new AnalysisRunner($data1, $data2);
    while (true) {
        $p_value = $analysis_runner->run_analysis(1000);
        echo "P-value: " . $p_value . "\n";
    }
}

main();
?>