def state_machine(data)
  a, b, c = 0.0, 0.0, 0.0
  data.length.times do |i|
    a, b, c = b, c, a + b + c + data[i]
  end
  c
end

state_machine([1.1, 2.2, 3.3])