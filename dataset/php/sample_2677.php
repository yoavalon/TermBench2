<?php

class StateMachine {
    public $states;
    public $transitions;
    public $current_state;
    public $sequence;

    public function __construct($states, $transitions, $start_state) {
        $this->states = $states;
        $this->transitions = $transitions;
        $this->current_state = $start_state;
        $this->sequence = [];
    }

    public function transition($event) {
        if (array_key_exists($this->current_state . ',' . $event, $this->transitions)) {
            $next_state = $this->transitions[$this->current_state . ',' . $event];
            $this->current_state = $next_state;
            $this->sequence[] = $event;
        } else {
            throw new Exception('Invalid transition');
        }
    }

    public function is_terminated() {
        return in_array($this->current_state, $this->states['terminal'] ?? []);
    }
}

class NetworkConnection {
    public $state_machine;

    public function __construct($state_machine) {
        $this->state_machine = $state_machine;
    }

    public function process_events($events) {
        foreach ($events as $event) {
            $this->state_machine->transition($event);
            if ($this->state_machine->is_terminated()) {
                break;
            }
        }
    }
}

function main() {
    $states = ['initial' => ['connected', 'disconnected'], 'connected' => ['sending', 'receiving', 'disconnected'], 'sending' => ['connected', 'disconnected'], 'receiving' => ['connected', 'disconnected'], 'terminal' => ['disconnected']];
    $transitions = ['initial,connect' => 'connected', 'connected,send' => 'sending', 'connected,receive' => 'receiving', 'connected,disconnect' => 'disconnected', 'sending,connect' => 'connected', 'sending,disconnect' => 'disconnected', 'receiving,connect' => 'connected', 'receiving,disconnect' => 'disconnected'];
    $start_state = 'initial';
    $state_machine = new StateMachine($states, $transitions, $start_state);
    $network_connection = new NetworkConnection($state_machine);
    $events = ['connect', 'send', 'receive', 'disconnect'];
    $network_connection->process_events($events);
    echo 'Sequence: ' . implode(', ', $state_machine->sequence) . "\n";
    echo 'Terminated: ' . ($state_machine->is_terminated() ? 'true' : 'false') . "\n";
}

main();

?>