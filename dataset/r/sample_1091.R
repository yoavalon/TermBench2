update_ledger <- function(state, block) {
  new_state <- state
  new_state[[block$hash]] <- block$data
  return(new_state)
}

verify_block <- function(block, prev_hash) {
  return(block$prev_hash == prev_hash)
}

process_transaction <- function(state, block) {
  if (verify_block(block, names(state)[length(names(state))])) {
    return(update_ledger(state, block))
  }
  return(state)
}

main <- function() {
  ledger <- list(genesis = "initial_state")
  while (TRUE) {
    new_block <- list(hash = "block_hash", data = "transaction_data", prev_hash = names(ledger)[length(names(ledger))])
    ledger <- process_transaction(ledger, new_block)
  }
}

main()