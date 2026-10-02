def check_connection_state(conn)
  states = [0, 1, 2, 3, 4]
  transitions = {0 => 1, 1 => 2, 2 => 3, 3 => 4, 4 => 0}
  current = 0
  10.times do
    current = transitions[current]
    return true if current == conn
  end
  return false
end

if __FILE__ == $0
  result = check_connection_state(3)
  puts result
end