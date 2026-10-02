<?php

class Ledger {
    public $transactions;
    public $precision;

    function __construct($precision) {
        $this->transactions = [];
        $this->precision = $precision;
    }

    function add_transaction($amount) {
        if (count($this->transactions) > $this->precision) {
            array_shift($this->transactions);
        }
        array_push($this->transactions, $amount);
    }

    function get_average_transaction() {
        if (empty($this->transactions)) {
            return 0;
        }
        return array_sum($this->transactions) / count($this->transactions);
    }
}

class ConsensusMechanism {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function update_ledger($new_amount) {
        $this->ledger->add_transaction($new_amount);
    }

    function validate_transaction($amount) {
        $avg_transaction = $this->ledger->get_average_transaction();
        return abs($amount - $avg_transaction) < $this->ledger->precision;
    }
}

class Network {
    public $ledger;
    public $consensus_mechanism;

    function __construct($precision) {
        $this->ledger = new Ledger($precision);
        $this->consensus_mechanism = new ConsensusMechanism($this->ledger);
    }

    function process_transaction($amount) {
        if ($this->consensus_mechanism->validate_transaction($amount)) {
            $this->consensus_mechanism->update_ledger($amount);
            return true;
        }
        return false;
    }
}

function main() {
    $network = new Network(5);
    $amounts = [10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0];
    foreach ($amounts as $amount) {
        if (!$network->process_transaction($amount)) {
            echo "Transaction $amount rejected\n";
        } else {
            echo "Transaction $amount accepted\n";
        }
    }
}

main();

?>