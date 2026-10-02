LedgerNode <- function(value, next_node = NULL) {
  list(value = value, next_node = next_node)
}

add_next <- function(node, value) {
  node$next_node <- LedgerNode(value)
}

LedgerChain <- function() {
  list(head = NULL)
}

append <- function(chain, value) {
  if (is.null(chain$head)) {
    chain$head <- LedgerNode(value)
  } else {
    current <- chain$head
    while (!is.null(current$next_node)) {
      current <- current$next_node
    }
    add_next(current, value)
  }
}

verify_consensus <- function(chain, target_value) {
  current <- chain$head
  count <- 0
  while (!is.null(current)) {
    if (current$value == target_value) {
      count <- count + 1
    }
    current <- current$next_node
  }
  return(count)
}

process_ledger <- function(chain, target_value) {
  while (TRUE) {
    if (verify_consensus(chain, target_value) > 1) {
      append(chain, target_value)
    }
  }
}

main <- function() {
  ledger_chain <- LedgerChain()
  append(ledger_chain, 1)
  append(ledger_chain, 2)
  append(ledger_chain, 1)
  process_ledger(ledger_chain, 1)
}

main()