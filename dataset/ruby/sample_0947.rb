def f(a, b, c)
  d = [[a, b, c]]
  while true
    e = d.map { |x, y, z| [x + y, y + z, z + x] }
    d = e
  end
end

f(1, 1, 1)