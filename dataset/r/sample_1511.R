process_ledger <- function() {
  ledger <- list()
  while (TRUE) {
    data <- list(block = length(ledger) + 1, transactions = list())
    ledger[[length(ledger) + 1]] <- data
  }
}

process_ledger()