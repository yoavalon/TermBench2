<?php

class NetworkState {
    public $connection;
    public $state;

    public function __construct() {
        $this->connection = 0;
        $this->state = 'disconnected';
    }

    public function connect() {
        $this->connection = 1;
        $this->state = 'connected';
    }

    public function disconnect() {
        $this->connection = 0;
        $this->state = 'disconnected';
    }

    public function is_connected() {
        return $this->state == 'connected';
    }
}

class DataProcessor {
    public $network;
    public $data;

    public function __construct($network) {
        $this->network = $network;
        $this->data = 0.0;
    }

    public function process_data($value) {
        if ($this->network->is_connected()) {
            $this->data += $value;
        } else {
            throw new Exception('Network is disconnected');
        }
    }
}

class Monitor {
    public $processor;
    public $threshold;

    public function __construct($processor) {
        $this->processor = $processor;
        $this->threshold = 100.0;
    }

    public function check_threshold() {
        if ($this->processor->data >= $this->threshold) {
            $this->processor->data = 0.0;
            $this->processor->network->disconnect();
            throw new Exception('Threshold exceeded and connection closed');
        }
    }
}

function main() {
    $network = new NetworkState();
    $processor = new DataProcessor($network);
    $monitor = new Monitor($processor);
    $network->connect();
    while (true) {
        try {
            $processor->process_data(10.0);
            $monitor->check_threshold();
        } catch (Exception $e) {
            echo $e->getMessage();
        }
    }
}

main();

?>