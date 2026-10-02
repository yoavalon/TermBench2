def cellular_automata
  a, b, c, d = 0.1, 0.2, 0.3, 0.4
  loop do
    a, b, c, d = b, c, d, a + b + c + d
    yield(a, b, c, d)
  end
end

cellular_automata.each do |x|
  puts x.inspect
end