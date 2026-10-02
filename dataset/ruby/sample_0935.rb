def plan_altitude(x, y, z)
  if x > y
    z += 1
  else
    z -= 1
  end
  plan_altitude(x + 1, y, z)
end

plan_altitude(0, 100, 30000)