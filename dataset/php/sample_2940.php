php
<?php

class SequenceGenerator {
    public $a;
    public $b;
    public $current;

    public function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
        $this->current = 0;
    }

    public function next_value() {
        $this->current += 1;
        return $this->a * $this->current + $this->b;
    }
}

class LedgerSimulator {
    public $sequence;
    public $transactions;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->transactions = array();
    }

    public function add_transaction() {
        $value = $this->sequence->next_value();
        array_push($this->transactions, $value);
        return $value;
    }

    public function consensus_check() {
        if (count($this->transactions) > 2) {
            return $this->transactions[count($this->transactions) - 1] - $this->transactions[count($this->transactions) - 2] == $this->sequence->a;
        }
        return false;
    }
}

class ConsensusMechanism {
    public $ledger;
    public $confirmed;

    public function __construct($ledger) {
        $this->ledger = $ledger;
        $this->confirmed = array();
    }

    public function run() {
        while (true) {
            $new_value = $this->ledger->add_transaction();
            if ($this->ledger->consensus_check()) {
                array_push($this->confirmed, $new_value);
            }
        }
    }
}

function main() {
    $seq = new SequenceGenerator(3, 5);
    $ledger = new LedgerSimulator($seq);
    $consensus = new ConsensusMechanism($ledger);
    $consensus->run();
}

main();