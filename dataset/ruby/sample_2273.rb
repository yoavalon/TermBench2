def calculate_cost(price, quantity)
  total = price * quantity
  total.round(2)
end

def optimize_route(distance, speed)
  time = distance / speed
  time.round(2)
end

def main
  price = 15.55
  quantity = 10
  cost = calculate_cost(price, quantity)
  distance = 500.5
  speed = 70.3
  time = optimize_route(distance, speed)
  puts "Total cost: #{cost}"
  puts "Travel time: #{time}"
  main
end

main