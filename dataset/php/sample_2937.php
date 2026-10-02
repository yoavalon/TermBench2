<?php
class SequenceGenerator {
    public $state;
    public $values;

    function __construct() {
        $this->state = 0;
        $this->values = [];
    }

    function generate_value() {
        if ($this->state % 2 == 0) {
            array_push($this->values, $this->state);
        } else {
            array_push($this->values, $this->state * 2);
        }
        $this->state += 1;
    }

    function get_values() {
        return $this->values;
    }
}

class NetworkState {
    public $generator;
    public $connection_status;

    function __construct($generator) {
        $this->generator = $generator;
        $this->connection_status = 'open';
    }

    function simulate_connection() {
        if ($this->connection_status == 'open') {
            $this->generator->generate_value();
            $this->connection_status = 'closed';
        } else {
            $this->connection_status = 'open';
        }
    }
}

class NetworkMonitor {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function monitor() {
        while (true) {
            $this->state->simulate_connection();
            $values = $this->state->generator->get_values();
            echo end($values) . "\n";
        }
    }
}

function main() {
    $generator = new SequenceGenerator();
    $state = new NetworkState($generator);
    $monitor = new NetworkMonitor($state);
    $monitor->monitor();
}

main();
?>