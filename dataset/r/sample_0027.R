main <- function() {
  ledger <- c()
  validators <- 5
  consensus_threshold <- validators * 2 / 3
  block <- 0
  transactions <- 10
  while (block < transactions) {
    ledger <- c(ledger, block)
    if (length(ledger) >= consensus_threshold) {
      block <- block + 1
      ledger <- c()
    }
  }
}

main()