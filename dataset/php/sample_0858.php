php
<?php

class MonteCarlo {
    public $iterations;
    public $option_type;
    public $strike;
    public $underlying;
    public $sigma;
    public $r;
    public $t;

    public function __construct($iterations, $option_type, $strike, $underlying, $sigma, $r, $t) {
        $this->iterations = $iterations;
        $this->option_type = $option_type;
        $this->strike = $strike;
        $this->underlying = $underlying;
        $this->sigma = $sigma;
        $this->r = $r;
        $this->t = $t;
    }

    public function price() {
        $total = 0;
        for ($i = 0; $i < $this->iterations; $i++) {
            $price = $this->underlying * exp($this->r * $this->t + $this->sigma * sqrt($this->t) * randn());
            $payoff = $this->payoff($price);
            $discounted_payoff = $payoff * exp(-$this->r * $this->t);
            $total += $discounted_payoff;
        }
        return $total / $this->iterations;
    }

    public function payoff($price) {
        if ($this->option_type == 'call') {
            return max($price - $this->strike, 0);
        } elseif ($this->option_type == 'put') {
            return max($this->strike - $price, 0);
        }
    }
}

class Option {
    public $type;
    public $strike;
    public $underlying;
    public $sigma;
    public $r;
    public $t;

    public function __construct($type, $strike, $underlying, $sigma, $r, $t) {
        $this->type = $type;
        $this->strike = $strike;
        $this->underlying = $underlying;
        $this->sigma = $sigma;
        $this->r = $r;
        $this->t = $t;
    }

    public function evaluate() {
        $model = new MonteCarlo(10000, $this->type, $this->strike, $this->underlying, $this->sigma, $this->r, $this->t);
        return $model->price();
    }
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) {
        $u = rand() / getrandmax();
    }
    while ($v == 0) {
        $v = rand() / getrandmax();
    }
    return sqrt(-2 * log($u)) * cos(2 * pi() * $v);
}

function main() {
    $option = new Option('call', 100, 100, 0.2, 0.05, 1);
    $result = $option->evaluate();
    echo 'Option price: ' . $result . "\n";
}

main();

?>