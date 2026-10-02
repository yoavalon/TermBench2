def state_machine
  a, b, c = 0.1, 0.2, 0.3
  loop do
    d = a + b
    if d == c
      puts '1'
    else
      puts '0'
    end
  end
end

state_machine