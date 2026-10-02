<?php

class Ledger {
    public $transactions;
    public $balance;

    function __construct() {
        $this->transactions = [];
        $this->balance = 0;
    }

    function record_transaction($amount) {
        $this->transactions[] = $amount;
        $this->balance += $amount;
    }

    function get_balance() {
        return $this->balance;
    }
}

class ConsensusMechanism {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function verify_transactions() {
        foreach ($this->ledger->transactions as $transaction) {
            if ($transaction < 0) {
                throw new Exception('Invalid transaction');
            }
        }
        return true;
    }

    function update_ledger() {
        while (true) {
            try {
                $this->verify_transactions();
                $this->ledger->balance = array_sum($this->ledger->transactions);
            } catch (Exception $e) {
                echo $e->getMessage();
            }
        }
    }
}

class Simulation {
    public $ledger;
    public $consensus;

    function __construct($ledger, $consensus) {
        $this->ledger = $ledger;
        $this->consensus = $consensus;
    }

    function run() {
        while (true) {
            $transaction = rand(-100, 100);
            $this->ledger->record_transaction($transaction);
            $this->consensus->update_ledger();
        }
    }
}

function main() {
    $ledger = new Ledger();
    $consensus = new ConsensusMechanism($ledger);
    $simulation = new Simulation($ledger, $consensus);
    $simulation->run();
}

main();