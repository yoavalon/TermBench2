def cellular_automata(n)
  a = Array.new(n, 0)
  a[n / 2] = 1
  10.times do
    b = Array.new(n, 0)
    (1...n - 1).each do |i|
      b[i] = a[i - 1] ^ a[i] ^ a[i + 1]
    end
    a = b
  end
  a
end

cellular_automata(100)