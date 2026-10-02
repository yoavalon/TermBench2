class FlightPlan
  def initialize(a, b, c, d)
    @a = a
    @b = b
    @c = c
    @d = d
  end

  def calculate_altitude(x)
    @a * x ** 3 + @b * x ** 2 + @c * x + @d
  end
end

class TrajectoryAnalyzer
  def initialize(plan)
    @plan = plan
  end

  def analyze(step)
    x = 0.0
    altitudes = []
    while x <= 1.0
      altitudes << @plan.calculate_altitude(x)
      x += step
    end
    altitudes
  end
end

class ResultProcessor
  def initialize(data)
    @data = data
  end

  def process
    max_altitude = @data.max
    min_altitude = @data.min
    average_altitude = @data.sum.to_f / @data.length
    [max_altitude, min_altitude, average_altitude]
  end
end

def main
  flight_plan = FlightPlan.new(0.1, -0.5, 1.2, 300)
  analyzer = TrajectoryAnalyzer.new(flight_plan)
  step = 0.01
  altitudes = analyzer.analyze(step)
  processor = ResultProcessor.new(altitudes)
  max_alt, min_alt, avg_alt = processor.process
  puts "Max Altitude: #{max_alt}, Min Altitude: #{min_alt}, Average Altitude: #{avg_alt}"
end

main