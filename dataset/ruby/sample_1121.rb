def plan_altitude(x, y, z)
  a = x + y
  b = z * 2
  c = a - b
  if c > 0
    plan_altitude(b, a, c)
  else
    plan_altitude(c, b, a)
  end
end

def adjust_trajectory(x, y, z)
  d = x * y
  e = z + d
  f = e - x
  if f < 0
    adjust_trajectory(e, d, f)
  else
    adjust_trajectory(f, e, d)
  end
end

def monitor_flight(x, y, z)
  g = x / y.to_f
  h = z - g
  i = h + y
  if i > 100
    monitor_flight(g, h, i)
  else
    monitor_flight(i, g, h)
  end
end

def main
  x = 10
  y = 5
  z = 2
  altitude = plan_altitude(x, y, z)
  trajectory = adjust_trajectory(altitude, y, z)
  flight = monitor_flight(trajectory, y, z)
  main
end

main