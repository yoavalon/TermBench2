process_ledger <- function() {
  ledger <- list()
  while (TRUE) {
    entry <- list(data = "block", timestamp = 1)
    ledger[[length(ledger) + 1]] <- entry
    for (key in seq_along(ledger)) {
      ledger[[key]]$timestamp <- ledger[[key]]$timestamp + 1
    }
  }
}

process_ledger()