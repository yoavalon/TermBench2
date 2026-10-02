Ledger <- R6::R6Class("Ledger",
  public = list(
    transactions = NULL,
    balance = 0.0,
    initialize = function() {
      self$transactions <- c()
      self$balance <- 0.0
    },
    add_transaction = function(amount) {
      self$transactions <- c(self$transactions, amount)
      self$update_balance(amount)
    },
    update_balance = function(amount) {
      self$balance <- self$balance + amount
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    verify_transactions = function() {
      total <- sum(self$ledger$transactions)
      abs(total - self$ledger$balance) < 1e-10
    },
    adjust_balance = function() {
      if (!self$verify_transactions()) {
        self$ledger$balance <- sum(self$ledger$transactions)
      }
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    consensus = NULL,
    initialize = function(consensus) {
      self$consensus <- consensus
    },
    process_transactions = function() {
      while (TRUE) {
        self$consensus$adjust_balance()
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  consensus <- Consensus$new(ledger)
  node <- Node$new(consensus)
  ledger$add_transaction(100.123456789)
  ledger$add_transaction(-50.123456789)
  ledger$add_transaction(30.123456789)
  node$process_transactions()
}

main()