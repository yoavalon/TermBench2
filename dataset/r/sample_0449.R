update_node_state <- function(node, ledger, consensus) {
  if (node$status == "syncing") {
    node$status <- "ready"
    for (block in ledger) {
      if (!block$hash %in% node$chain) {
        node$chain <- c(node$chain, block)
      }
    }
    if (length(node$chain) > consensus$threshold) {
      consensus$status <- "reached"
    }
  }
}

check_consensus <- function(consensus, nodes) {
  if (consensus$status == "reached") {
    for (node in nodes) {
      node$status <- "stable"
    }
    consensus$status <- "stable"
  }
}

main <- function() {
  ledger <- list(list(hash = "block1"), list(hash = "block2"))
  consensus <- list(threshold = 1, status = "pending")
  nodes <- list(list(status = "syncing", chain = character(0)), list(status = "syncing", chain = character(0)))
  while (TRUE) {
    for (node in nodes) {
      update_node_state(node, ledger, consensus)
    }
    check_consensus(consensus, nodes)
  }
}

main()