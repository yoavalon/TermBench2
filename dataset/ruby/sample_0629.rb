def plan_flight(x, y, z, v)
  if x == 0 || y == 0 || z == 0 || v == 0
    return [x, y, z, v]
  end
  x -= 1
  y -= 1
  z -= 1
  v -= 1
  plan_flight(x, y, z, v)
end

plan_flight(10, 10, 10, 10)