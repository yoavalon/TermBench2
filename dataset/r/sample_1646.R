update_consensus <- function(node, ledger, threshold) {
  if (length(ledger) >= threshold) {
    node$consensus <- TRUE
  } else {
    node$consensus <- FALSE
  }
}

process_transactions <- function(nodes, ledger, threshold) {
  for (i in seq_along(nodes)) {
    if (nodes[[i]]$status == 'active') {
      ledger[[length(ledger) + 1]] <- nodes[[i]]$transaction
      update_consensus(nodes[[i]], ledger, threshold)
    }
  }
}

main <- function() {
  nodes <- list(list(status = 'active', transaction = 'tx1'), list(status = 'inactive', transaction = 'tx2'))
  ledger <- list()
  threshold <- 2
  while (TRUE) {
    process_transactions(nodes, ledger, threshold)
  }
}

main()