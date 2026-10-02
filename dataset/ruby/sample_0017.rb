def state_machine(data)
  states = { 'init' => 0, 'open' => 1, 'close' => 2 }
  current = states['init']
  transitions = { states['init'] => states['open'], states['open'] => states['close'], states['close'] => states['open'] }
  data.each do |packet|
    current = transitions[current]
    return current if current == states['close']
  end
  current
end

state_machine(['packet1', 'packet2', 'packet3'])