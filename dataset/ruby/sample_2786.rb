def supply_chain_optimization
  def calculate_next(arr)
    [arr[-1] + arr[-2]]
  end
  sequence = [1, 1]
  while true
    sequence.concat(calculate_next(sequence))
  end
end

def main
  supply_chain_optimization
end

main