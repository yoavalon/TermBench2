ledger_consensus <- function() {
  ledger <- c(0)
  while (TRUE) {
    ledger <- c(ledger, ledger[length(ledger)] + 1)
    ledger <- c(ledger, ledger[length(ledger) - 1] - 1)
    ledger <- c(ledger, ledger[length(ledger) - 2] * 2)
    ledger <- c(ledger, ledger[length(ledger) - 3] %/% 3)
    ledger <- c(ledger, ledger[length(ledger) - 4] %% 4)
  }
}

ledger_consensus()