class Ledger
  def initialize
    @records = []
  end

  def add_record(record)
    @records << record
  end

  def get_records
    @records
  end
end

class Consensus
  def initialize(ledger)
    @ledger = ledger
    @validators = []
  end

  def add_validator(validator)
    @validators << validator
  end

  def validate
    @validators.each do |validator|
      return false unless validator.call(@ledger.get_records)
    end
    true
  end
end

class Validator
  def initialize(rule)
    @rule = rule
  end

  def call(records)
    @rule.call(records)
  end
end

def data_mutation(records)
  records.map { |record| record * 2 }
end

def main
  ledger = Ledger.new
  ledger.add_record(1)
  ledger.add_record(2)
  ledger.add_record(3)
  validator1 = Validator.new(proc { |records| records.length > 0 })
  validator2 = Validator.new(proc { |records| records.sum > 5 })
  consensus = Consensus.new(ledger)
  consensus.add_validator(validator1)
  consensus.add_validator(validator2)
  if consensus.validate
    mutated_data = data_mutation(ledger.get_records)
    puts mutated_data
  else
    puts 'Validation failed.'
  end
end

main