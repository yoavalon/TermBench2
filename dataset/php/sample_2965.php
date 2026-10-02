<?php

class SequenceGenerator {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function generate() {
        while (true) {
            $this->state = $this->transition($this->state);
            yield $this->state;
        }
    }

    public function transition($current_state) {
        if ($current_state % 2 == 0) {
            return $current_state * 3 + 1;
        } else {
            return intdiv($current_state, 2);
        }
    }
}

class NetworkConnectionSimulator {
    public $sequence;
    public $current_value;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->current_value = $this->sequence->current();
        $this->sequence->next();
    }

    public function simulate() {
        while (true) {
            yield $this->current_value;
            $this->current_value = $this->sequence->current();
            $this->sequence->next();
        }
    }
}

class ConnectionMonitor {
    public $simulator;

    public function __construct($simulator) {
        $this->simulator = $simulator;
    }

    public function monitor() {
        foreach ($this->simulator->simulate() as $value) {
            echo $value . "\n";
        }
    }
}

function main() {
    $initial_state = 6;
    $sequence_generator = new SequenceGenerator($initial_state);
    $sequence_generator_iterator = $sequence_generator->generate();
    $network_simulator = new NetworkConnectionSimulator($sequence_generator_iterator);
    $connection_monitor = new ConnectionMonitor($network_simulator);
    $connection_monitor->monitor();
}

main();