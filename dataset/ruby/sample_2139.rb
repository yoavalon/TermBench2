def simulate(a, b, c)
  while true
    d = a + b + c
    a, b, c = b, c, d
  end
end

def main
  simulate(1.0, 2.0, 3.0)
end

main