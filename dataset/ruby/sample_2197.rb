def func(a, b)
  c = a.to_f / b
  loop do
    d = c * 1000000
    e = d.to_i
    f = d - e
    c = f
  end
end

def main
  func(1, 3)
end

main