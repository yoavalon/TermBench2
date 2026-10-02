def main
  states = { 'A' => 'B', 'B' => 'C', 'C' => 'A' }
  state = 'A'
  loop do
    state = states[state]
  end
end

main