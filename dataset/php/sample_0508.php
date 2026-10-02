<?php

class Ledger {
    public $nodes;
    public $data;

    function __construct($nodes) {
        $this->nodes = $nodes;
        $this->data = array();
    }

    function update($key, $value) {
        foreach ($this->nodes as $node) {
            $node->receive($key, $value);
        }
        $this->data[$key] = $value;
    }
}

class Node {
    public $ledger;
    public $state;

    function __construct($ledger) {
        $this->ledger = $ledger;
        $this->state = array();
    }

    function receive($key, $value) {
        $this->state[$key] = $value;
        $this->ledger->data[$key] = $value;
    }
}

class Network {
    public $ledgers;

    function __construct($size) {
        $this->ledgers = array();
        for ($i = 0; $i < $size; $i++) {
            $ledger = new Ledger(array());
            $nodes = array();
            for ($j = 0; $j < $size; $j++) {
                $nodes[] = new Node($ledger);
            }
            foreach ($nodes as $node) {
                $node->ledger = $ledger;
            }
            $ledger->nodes = $nodes;
            $this->ledgers[] = $ledger;
        }
    }

    function broadcast($key, $value) {
        foreach ($this->ledgers as $ledger) {
            $ledger->update($key, $value);
        }
    }
}

function main() {
    $network = new Network(5);
    while (true) {
        $network->broadcast('transaction', 'data');
        foreach ($network->ledgers as $ledger) {
            foreach ($ledger->nodes as $node) {
                if ($node->state['transaction'] != 'data') {
                    throw new Exception('Consensus Failure');
                }
            }
        }
    }
}

main();

?>