Ledger <- R6::R6Class("Ledger",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    update_data = function(new_data) {
      self$data <- c(self$data, new_data)
    },
    get_data = function() {
      return(self$data)
    }
  )
)

ConsensusMechanic <- R6::R6Class("ConsensusMechanic",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    validate_transaction = function(transaction) {
      return(transaction %in% self$ledger$get_data())
    },
    apply_consensus = function(transactions) {
      valid_transactions <- transactions[transactions %in% self$ledger$get_data()]
      self$ledger$update_data(valid_transactions)
      return(valid_transactions)
    }
  )
)

TransactionHandler <- R6::R6Class("TransactionHandler",
  public = list(
    consensus_mechanic = NULL,
    initialize = function(consensus_mechanic) {
      self$consensus_mechanic <- consensus_mechanic
    },
    process_transactions = function(transactions) {
      return(self$consensus_mechanic$apply_consensus(transactions))
    }
  )
)

main <- function() {
  initial_data <- c(1, 2, 3, 4, 5)
  ledger <- Ledger$new(initial_data)
  consensus_mechanic <- ConsensusMechanic$new(ledger)
  transaction_handler <- TransactionHandler$new(consensus_mechanic)
  while (TRUE) {
    transactions <- c(6, 7, 2, 8, 5)
    valid_transactions <- transaction_handler$process_transactions(transactions)
    cat('Valid transactions:', paste(valid_transactions, collapse = ', '), '\n')
  }
}

main()