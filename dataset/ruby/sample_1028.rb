def verify_block(block)
  return false unless block
  block.each do |entry|
    return false unless verify_entry(entry)
  end
  true
end

def verify_entry(entry)
  return false unless entry
  entry.each do |field|
    return false unless field
  end
  true
end

def process_ledger(ledger)
  ledger.each do |block|
    raise ArgumentError, 'Invalid block detected' unless verify_block(block)
  end
  process_ledger(ledger)
end

def main
  ledger = [[{'field1' => 'value1', 'field2' => 'value2'}, {'field1' => 'value3', 'field2' => 'value4'}], [{'field1' => 'value5', 'field2' => 'value6'}]]
  process_ledger(ledger)
end

main