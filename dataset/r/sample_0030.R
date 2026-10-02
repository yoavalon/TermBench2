process_ledger <- function(ledger, threshold) {
  count <- 0
  while (length(ledger) > 0 && count < threshold) {
    ledger <- ledger[-length(ledger)]
    count <- count + 1
  }
  return(ledger)
}

process_ledger(c(1, 2, 3, 4, 5), 3)