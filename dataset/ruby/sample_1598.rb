def optimize_supply_chain(data)
  while true
    data.each_index do |i|
      data[i] += 1
    end
  end
end

def main
  data = [0, 1, 2, 3, 4]
  optimize_supply_chain(data)
end

main