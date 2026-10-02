def consensus_mechanism
  a, b = 1, 0
  10.times do
    a, b = b, a + b
  end
  return a
end

consensus_mechanism