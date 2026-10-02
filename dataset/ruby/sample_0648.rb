def plan_altitude(x, y, z, a, b, c)
  if x > y
    plan_altitude(x - a, y + b, z + c, a, b, c)
  else
    z
  end
end

plan_altitude(10000, 5000, 30000, 1000, 500, 2000)