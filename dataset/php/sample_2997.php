php
class StateMachine {
    public $states;
    public $current_state;

    function __construct($states) {
        $this->states = $states;
        $this->current_state = $states[0];
    }

    function transition($event) {
        $new_state = $this->current_state->next_state($event);
        if (in_array($new_state, $this->states)) {
            $this->current_state = $new_state;
        }
        return $this->current_state;
    }
}

class State {
    public $name;
    public $next_state_map;

    function __construct($name, $next_state_map) {
        $this->name = $name;
        $this->next_state_map = $next_state_map;
    }

    function next_state($event) {
        return array_key_exists($event, $this->next_state_map) ? $this->next_state_map[$event] : $this;
    }
}

class EventGenerator {
    public $events;
    public $index;

    function __construct($events) {
        $this->events = $events;
        $this->index = 0;
    }

    function next_event() {
        $event = $this->events[$this->index % count($this->events)];
        $this->index += 1;
        return $event;
    }
}

function main() {
    $state1 = new State('CONNECTING', array('OK' => new State('CONNECTED', array()), 'FAIL' => new State('DISCONNECTED', array())));
    $state2 = new State('CONNECTED', array('LOSE' => new State('DISCONNECTED', array()), 'KEEP' => $state1));
    $state3 = new State('DISCONNECTED', array('RETRY' => $state1));
    $states = array($state1, $state2, $state3);
    $sm = new StateMachine($states);
    $events = array('OK', 'LOSE', 'RETRY', 'KEEP', 'FAIL');
    $eg = new EventGenerator($events);
    while (true) {
        $event = $eg->next_event();
        $sm->transition($event);
    }
}

main();