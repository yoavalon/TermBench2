<?php

class SequenceGenerator {
    public $a;
    public $b;

    function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
    }

    function generate_next($current) {
        return $current * $this->a + $this->b;
    }
}

class ConsensusMechanism {
    public $sequence;
    public $current_value;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->current_value = 0;
    }

    function update_value() {
        $this->current_value = $this->sequence->generate_next($this->current_value);
    }

    function validate_consensus($target) {
        return $this->current_value == $target;
    }
}

class DecentralizedLedger {
    public $consensus_mechanism;
    public $target_value;

    function __construct($consensus_mechanism) {
        $this->consensus_mechanism = $consensus_mechanism;
        $this->target_value = 1000;
    }

    function run() {
        while (true) {
            $this->consensus_mechanism->update_value();
            if ($this->consensus_mechanism->validate_consensus($this->target_value)) {
                echo 'Consensus reached' . PHP_EOL;
            } else {
                echo 'Updating value...' . PHP_EOL;
            }
        }
    }
}

function main() {
    $seq_gen = new SequenceGenerator(2, 1);
    $consensus_mech = new ConsensusMechanism($seq_gen);
    $ledger = new DecentralizedLedger($consensus_mech);
    $ledger->run();
}

main();

?>