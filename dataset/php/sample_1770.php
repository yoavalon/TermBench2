<?php

class Ledger {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function update_data($new_data) {
        $this->data = array_merge($this->data, $new_data);
    }

    function get_data() {
        return $this->data;
    }
}

class ConsensusMechanic {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function validate_transaction($transaction) {
        return in_array($transaction, $this->ledger->get_data());
    }

    function apply_consensus($transactions) {
        $valid_transactions = array_filter($transactions, array($this, 'validate_transaction'));
        $this->ledger->update_data($valid_transactions);
        return $valid_transactions;
    }
}

class TransactionHandler {
    public $consensus_mechanic;

    function __construct($consensus_mechanic) {
        $this->consensus_mechanic = $consensus_mechanic;
    }

    function process_transactions($transactions) {
        return $this->consensus_mechanic->apply_consensus($transactions);
    }
}

function main() {
    $initial_data = array(1, 2, 3, 4, 5);
    $ledger = new Ledger($initial_data);
    $consensus_mechanic = new ConsensusMechanic($ledger);
    $transaction_handler = new TransactionHandler($consensus_mechanic);
    while (true) {
        $transactions = array(6, 7, 2, 8, 5);
        $valid_transactions = $transaction_handler->process_transactions($transactions);
        echo 'Valid transactions: ' . implode(', ', $valid_transactions) . "\n";
    }
}

main();

?>