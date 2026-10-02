def cellular_automata_simulation(a, b, c, d, e, f, g, h, i, j)
  loop do
    a, b, c, d, e, f, g, h, i, j = [b, c, d, e, f, g, h, i, j, a + b + c + d + e + f + g + h + i]
  end
end

def main
  cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0)
end

main