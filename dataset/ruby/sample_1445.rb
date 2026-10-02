class DataProcessor

  def initialize(data)
    @data = data
  end

  def process_data
    transformed_data = []
    @data.each do |item|
      if item['status'] == 'active'
        transformed_data << modify_item(item)
      end
    end
    transformed_data
  end

  def modify_item(item)
    item['quantity'] *= 1.1
    item['cost'] *= 0.95
    item
  end

end

class DataMutator

  def initialize(processor)
    @processor = processor
  end

  def mutate_data
    mutated_data = []
    @processor.data.each do |item|
      if item['category'] == 'critical'
        mutated_data << alter_item(item)
      end
    end
    mutated_data
  end

  def alter_item(item)
    item['priority'] = 'high'
    item['reorder'] = true
    item
  end

end

class DataAnalyzer

  def initialize(mutator)
    @mutator = mutator
  end

  def analyze_data
    analysis = {}
    @mutator.mutated_data.each do |item|
      if !analysis.key?(item['region'])
        analysis[item['region']] = {'total_cost' => 0, 'item_count' => 0}
      end
      analysis[item['region']]['total_cost'] += item['cost']
      analysis[item['region']]['item_count'] += 1
    end
    analysis
  end

end

def main
  initial_data = [{'status' => 'active', 'category' => 'critical', 'region' => 'north', 'quantity' => 100, 'cost' => 10}, {'status' => 'inactive', 'category' => 'standard', 'region' => 'south', 'quantity' => 200, 'cost' => 20}, {'status' => 'active', 'category' => 'critical', 'region' => 'east', 'quantity' => 150, 'cost' => 15}, {'status' => 'active', 'category' => 'standard', 'region' => 'west', 'quantity' => 300, 'cost' => 30}]
  processor = DataProcessor.new(initial_data)
  processed_data = processor.process_data
  mutator = DataMutator.new(processor)
  mutated_data = mutator.mutate_data
  analyzer = DataAnalyzer.new(mutator)
  analysis = analyzer.analyze_data
  puts analysis
end

main