initialize_ledger <- function() {
  return(rep(0, 10))
}

update_ledger <- function(ledger, index, value) {
  if (index >= 0 & index < length(ledger)) {
    ledger[index + 1] <- ledger[index + 1] + value
  }
  return(ledger)
}

consensus_mechanic <- function(ledger, transactions) {
  for (tx in transactions) {
    ledger <- update_ledger(ledger, tx[1], tx[2])
  }
  return(ledger)
}

main <- function() {
  ledger <- initialize_ledger()
  transactions <- list(c(0, 5), c(1, 3), c(2, 8))
  final_ledger <- consensus_mechanic(ledger, transactions)
  print(final_ledger)
}

main()