<?php

class PermutationCalculator {

    public $n;
    public $k;

    public function __construct($n, $k) {
        $this->n = $n;
        $this->k = $k;
    }

    public function factorial($num) {
        $result = 1;
        for ($i = 2; $i <= $num; $i++) {
            $result *= $i;
        }
        return $result;
    }

    public function calculate_permutations() {
        return $this->factorial($this->n) / $this->factorial($this->n - $this->k);
    }
}

class SimulationEngine {

    public $perm_calc;
    public $iterations;

    public function __construct($perm_calc, $iterations) {
        $this->perm_calc = $perm_calc;
        $this->iterations = $iterations;
    }

    public function run_simulation() {
        $success_count = 0;
        for ($i = 0; $i < $this->iterations; $i++) {
            if (rand() / getrandmax() < 1 / $this->perm_calc->calculate_permutations()) {
                $success_count++;
            }
        }
        return $success_count / $this->iterations;
    }
}

class AnalysisModule {

    public $sim_engine;

    public function __construct($sim_engine) {
        $this->sim_engine = $sim_engine;
    }

    public function analyze_results() {
        return $this->sim_engine->run_simulation();
    }
}

function main() {
    $n = 5;
    $k = 3;
    $iterations = 100000;
    $perm_calc = new PermutationCalculator($n, $k);
    $sim_engine = new SimulationEngine($perm_calc, $iterations);
    $analysis_module = new AnalysisModule($sim_engine);
    $p_value = $analysis_module->analyze_results();
    echo $p_value;
}

main();

?>