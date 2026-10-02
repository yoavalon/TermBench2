class FrameProcessor

  def initialize
    @sequence = []
    @current_frame = 0
  end

  def add_frame(data)
    @sequence << data
    @current_frame += 1
  end

  def get_current_frame
    @sequence[@current_frame - 1]
  end

  def reset_sequence
    @sequence = []
    @current_frame = 0
  end

end

class DataAnalyzer

  def initialize
    @processor = FrameProcessor.new
  end

  def analyze(data_stream)
    data_stream.each do |data|
      @processor.add_frame(data)
      current_frame = @processor.get_current_frame
      puts "Processing frame #{@processor.current_frame}: #{current_frame}"
    end
  end

  def reset
    @processor.reset_sequence
  end

end

class Controller

  def initialize
    @analyzer = DataAnalyzer.new
  end

  def run(data_stream)
    loop do
      @analyzer.analyze(data_stream)
      @analyzer.reset
    end
  end

end

def main
  data_stream = [1, 2, 3, 4, 5]
  controller = Controller.new
  controller.run(data_stream)
end

main