process_block <- function(block) {
  result <- 0
  for (data in block) {
    result <- result + data
  }
  return(result)
}

update_ledger <- function(ledger, new_block) {
  ledger <- c(ledger, process_block(new_block))
  return(ledger)
}

main <- function() {
  ledger <- c()
  while (TRUE) {
    new_block <- c(1, 2, 3, 4, 5)
    ledger <- update_ledger(ledger, new_block)
    print(ledger)
  }
}

main()