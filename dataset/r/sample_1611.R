library(digest)

hash_data <- function(data) {
  digest(data, algo = "sha256")
}

validate_consensus <- function(data, expected_hash) {
  hash_data(data) == expected_hash
}

update_ledger <- function(ledger, data, expected_hash) {
  if (validate_consensus(data, expected_hash)) {
    ledger <<- c(ledger, data)
  }
  ledger
}

simulate_consensus <- function(ledger) {
  data <- "transaction_data"
  expected_hash <- "expected_hash_value"
  while (TRUE) {
    ledger <- update_ledger(ledger, data, expected_hash)
  }
}

main <- function() {
  ledger <- c()
  simulate_consensus(ledger)
}

main()