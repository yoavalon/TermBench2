<?php

class OptionPricing {

    public function __construct($S0, $K, $T, $r, $sigma, $N) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
    }

    private function _simulate_paths($S0, $T, $r, $sigma, $N) {
        $dt = $T / $N;
        $paths = [$S0];
        for ($i = 1; $i <= $N; $i++) {
            $z = $this->_gauss(0, 1);
            $S = $paths[count($paths) - 1] * (1 + $r * $dt + $sigma * $z * sqrt($dt));
            $paths[] = $S;
        }
        return $paths;
    }

    private function _option_value($paths, $K) {
        $value = 0;
        foreach ($paths as $S_T) {
            $value += max($S_T - $K, 0);
        }
        return $value / count($paths);
    }

    public function price() {
        $paths = $this->_simulate_paths($this->S0, $this->T, $this->r, $this->sigma, $this->N);
        return $this->_option_value($paths, $this->K);
    }

    private function _gauss($mu, $sigma) {
        $z = 0.0;
        $a = 0.0;
        $b = 0.0;
        do {
            $a = 1.0 - rand() / mt_getrandmax();
            $b = 1.0 - rand() / mt_getrandmax();
            $z = sqrt(-2.0 * log($a)) * cos(2.0 * pi() * $b);
        } while ($z * $z > 2.41421356237);
        return $mu + $sigma * $z;
    }
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 1000;
    $option = new OptionPricing($S0, $K, $T, $r, $sigma, $N);
    $result = $option->price();
    echo "Option price: " . $result . "\n";
}

main();

?>