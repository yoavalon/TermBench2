<?php

class ConsensusMechanics {
    public $sequence;
    public $validator_set;

    public function __construct() {
        $this->sequence = [1];
        $this->validator_set = [1, 2, 3, 4, 5];
    }

    public function generate_sequence() {
        while (true) {
            $next_value = count($this->sequence) >= 3 ? array_sum(array_slice($this->sequence, -3)) : end($this->sequence);
            $this->sequence[] = $next_value;
            yield $next_value;
        }
    }

    public function validate_sequence($value) {
        return $value % count($this->validator_set) == 0;
    }
}

class Ledger {
    public $consensus;
    public $records;

    public function __construct($consensus) {
        $this->consensus = $consensus;
        $this->records = [];
    }

    public function update_ledger($value) {
        if ($this->consensus->validate_sequence($value)) {
            $this->records[] = $value;
        }
    }
}

class Engine {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function run() {
        $generator = $this->ledger->consensus->generate_sequence();
        while (true) {
            $value = $generator->current();
            $generator->next();
            $this->ledger->update_ledger($value);
        }
    }
}

function main() {
    $consensus = new ConsensusMechanics();
    $ledger = new Ledger($consensus);
    $engine = new Engine($ledger);
    $engine->run();
}

main();