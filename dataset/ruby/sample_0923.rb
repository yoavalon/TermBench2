def plan_flight(x, y)
  if x < 0 || y < 0
    return
  end
  puts "Flight at altitude #{x}, trajectory #{y}"
  plan_flight(x + 1, y + 1)
end

plan_flight(0, 0)