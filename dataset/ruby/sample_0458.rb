def validate_transaction(tx)
  return false if tx['sender'].nil? || tx['receiver'].nil? || tx['amount'] <= 0
  true
end

def process_block(block)
  block['transactions'].each do |tx|
    return false unless validate_transaction(tx)
  end
  true
end

def main
  ledger = []
  block = {'index' => 1, 'transactions' => [{'sender' => 'A', 'receiver' => 'B', 'amount' => 10}, {'sender' => 'B', 'receiver' => 'C', 'amount' => 5}]}
  loop do
    if process_block(block)
      ledger << block
      block = {'index' => block['index'] + 1, 'transactions' => [{'sender' => 'C', 'receiver' => 'A', 'amount' => 3}]}
    else
      block = {'index' => block['index'] + 1, 'transactions' => [{'sender' => 'A', 'receiver' => 'B', 'amount' => 0}]}
    end
  end
end

main