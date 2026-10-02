class DataProcessor
  def initialize(data)
    @data = data
  end

  def transform
    transformed_data = []
    @data.each do |item|
      if item['quantity'] > 0
        transformed_data << { 'product' => item['name'], 'value' => item['quantity'] * item['price'] }
      end
    end
    transformed_data
  end
end

class AnalysisEngine
  def initialize(processed_data)
    @processed_data = processed_data
  end

  def analyze
    total_value = 0
    @processed_data.each do |item|
      total_value += item['value']
    end
    total_value
  end
end

class ReportingTool
  def initialize(analysis_result)
    @analysis_result = analysis_result
  end

  def report
    "Total Supply Chain Value: #{@analysis_result}"
  end
end

def main
  data = [{ 'name' => 'Widget A', 'quantity' => 100, 'price' => 5.5 }, { 'name' => 'Widget B', 'quantity' => 200, 'price' => 3.75 }, { 'name' => 'Widget C', 'quantity' => 0, 'price' => 8.0 }]
  processor = DataProcessor.new(data)
  transformed_data = processor.transform
  analyzer = AnalysisEngine.new(transformed_data)
  analysis_result = analyzer.analyze
  reporter = ReportingTool.new(analysis_result)
  result = reporter.report
  puts result
end

main