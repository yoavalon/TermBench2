<?php

class SequenceGenerator {
    public $a;
    public $b;

    function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
    }

    function generate($n) {
        $result = array();
        for ($i = 0; $i < $n; $i++) {
            if ($i % 2 == 0) {
                array_push($result, $this->a);
            } else {
                array_push($result, $this->b);
            }
        }
        return $result;
    }
}

class ConsensusMechanism {
    public $sequence;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function verify() {
        $count_a = 0;
        foreach ($this->sequence as $x) {
            if ($x == $this->sequence[0]) {
                $count_a++;
            }
        }
        $count_b = count($this->sequence) - $count_a;
        return $count_a == $count_b;
    }
}

class Executor {
    public $generator;
    public $verifier;

    function __construct($generator, $verifier) {
        $this->generator = $generator;
        $this->verifier = $verifier;
    }

    function run() {
        $sequence = $this->generator->generate(10);
        $is_valid = $this->verifier->verify();
        return array($sequence, $is_valid);
    }
}

function main() {
    $seq_gen = new SequenceGenerator(1, 0);
    $consensus = new ConsensusMechanism(array());
    $executor = new Executor($seq_gen, $consensus);
    list($sequence, $validity) = $executor->run();
    echo 'Sequence: ' . implode(', ', $sequence) . "\n";
    echo 'Consensus Validity: ' . ($validity ? 'true' : 'false') . "\n";
}

main();

?>