class DataProcessor

  def initialize(data)
    @data = data
    @processed_data = []
  end

  def filter_data
    @data.each do |item|
      if item['status'] == 'active'
        @processed_data << item
      end
    end
  end

  def update_inventory
    @processed_data.each do |item|
      item['inventory'] += 10
    end
  end

  def generate_report
    report = []
    @processed_data.each do |item|
      report << {'id' => item['id'], 'name' => item['name'], 'new_inventory' => item['inventory']}
    end
    report
  end

end

class LogisticsManager

  def initialize(processor)
    @processor = processor
  end

  def manage_supply_chain
    loop do
      @processor.filter_data
      @processor.update_inventory
      report = @processor.generate_report
      puts report
    end
  end

end

def main
  initial_data = [{'id' => 1, 'name' => 'Widget A', 'status' => 'active', 'inventory' => 50}, {'id' => 2, 'name' => 'Widget B', 'status' => 'inactive', 'inventory' => 30}, {'id' => 3, 'name' => 'Widget C', 'status' => 'active', 'inventory' => 20}]
  processor = DataProcessor.new(initial_data)
  manager = LogisticsManager.new(processor)
  manager.manage_supply_chain
end

main