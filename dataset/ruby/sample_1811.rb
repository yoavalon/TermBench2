def process_connections(states, transitions, start, end)
  current = start
  (states.length * 2).times do
    break if current == end
    current = transitions[current] || current
  end
  current == end
end

process_connections(['A', 'B', 'C'], {'A' => 'B', 'B' => 'C', 'C' => 'A'}, 'A', 'C')