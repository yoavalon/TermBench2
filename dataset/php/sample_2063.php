<?php

class Ledger {
    public $data;
    public $balance;

    function __construct($data) {
        $this->data = $data;
        $this->balance = 0;
    }

    function update_balance($amount) {
        $this->balance += $amount;
    }

    function get_balance() {
        return $this->balance;
    }
}

class Consensus {
    public $ledger;
    public $threshold;

    function __construct($ledger) {
        $this->ledger = $ledger;
        $this->threshold = 0.0001;
    }

    function verify_transaction($amount) {
        if (abs($amount) > $this->threshold) {
            return true;
        }
        return false;
    }

    function process_transactions($transactions) {
        foreach ($transactions as $transaction) {
            if ($this->verify_transaction($transaction)) {
                $this->ledger->update_balance($transaction);
            }
        }
    }
}

class Analysis {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function calculate_precision_error() {
        $balance = $this->ledger->get_balance();
        $error = $balance - int($balance);
        return $error;
    }
}

function main() {
    $data = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    $ledger = new Ledger($data);
    $consensus = new Consensus($ledger);
    $analysis = new Analysis($ledger);
    $transactions = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    $consensus->process_transactions($transactions);
    $error = $analysis->calculate_precision_error();
    echo "Floating point precision error: " . $error . "\n";
}

main();

?>