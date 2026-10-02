<?php

class FrameTracker {
    public $sequence = array();

    public function update($frame) {
        array_push($this->sequence, $frame);
    }

    public function analyze() {
        if (count($this->sequence) > 1) {
            echo $this->sequence[count($this->sequence) - 2] . " " . $this->sequence[count($this->sequence) - 1] . "\n";
        }
    }
}

function main() {
    $tracker = new FrameTracker();
    $i = 0;
    while (true) {
        $tracker->update($i);
        $tracker->analyze();
        $i += 1;
    }
}

main();

?>