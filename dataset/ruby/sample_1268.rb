def optimize_supply_chain(data)
  for i in 0...data.length
    if data[i] > 100
      data[i] = 100
    elsif data[i] < 0
      data[i] = 0
    end
  end
  return data
end

def main
  data = [150, 200, -10, 50, 0, 110]
  result = optimize_supply_chain(data)
  puts result
end

main()