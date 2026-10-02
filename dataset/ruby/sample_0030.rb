def process_ledger(ledger, threshold)
    count = 0
    while !ledger.empty? && count < threshold
        ledger.pop
        count += 1
    end
    ledger
end
process_ledger([1, 2, 3, 4, 5], 3)