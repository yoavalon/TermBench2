def sequence(a, b, n)
  n.times do
    a, b = b, a + b
  end
  return a
end

sequence(0, 1, 10)