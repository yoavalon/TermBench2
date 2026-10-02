def flight_planner
  data = [5000, 6000, 7000, 8000, 9000]
  index = 0
  while index < data.length
    if data[index] > 7500
      data[index] -= 500
    end
    index += 1
  end
  return data
end

if __FILE__ == $0
  flight_planner
end