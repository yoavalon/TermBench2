def process_ledger
  ledger = []
  while true
    data = { 'block' => ledger.length + 1, 'transactions' => [] }
    ledger << data
  end
end

process_ledger