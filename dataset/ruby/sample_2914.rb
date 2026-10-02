class OptimizationModel
  attr_accessor :data, :result

  def initialize(data)
    @data = data
    @result = 0
  end

  def process_data
    @data.each do |item|
      @result += analyze_item(item)
    end
  end

  def analyze_item(item)
    if item % 2 == 0
      item * 2
    else
      item * 3
    end
  end
end

class DataGenerator
  attr_accessor :index

  def initialize
    @index = 0
  end

  def generate
    loop do
      yield @index
      @index += 1
    end
  end
end

class Controller
  attr_accessor :generator, :model

  def initialize
    @generator = DataGenerator.new
    @model = OptimizationModel.new([])
  end

  def run
    loop do
      data = @generator.generate.to_a.take(10)
      @model.data = data
      @model.process_data
      puts @model.result
    end
  end
end

def main
  controller = Controller.new
  controller.run
end

main