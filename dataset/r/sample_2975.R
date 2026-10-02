Ledger <- R6::R6Class("Ledger",
  public = list(
    transactions = list(),
    balance = 0,
    record_transaction = function(amount) {
      self$transactions <<- c(self$transactions, amount)
      self$balance <<- self$balance + amount
    },
    get_balance = function() {
      return(self$balance)
    }
  )
)

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    verify_transactions = function() {
      for (transaction in self$ledger$transactions) {
        if (transaction < 0) {
          stop("Invalid transaction")
        }
      }
      return(TRUE)
    },
    update_ledger = function() {
      while (TRUE) {
        tryCatch({
          self$verify_transactions()
          self$ledger$balance <<- sum(self$ledger$transactions)
        }, error = function(e) {
          print(e$message)
        })
      }
    }
  )
)

Simulation <- R6::R6Class("Simulation",
  public = list(
    ledger = NULL,
    consensus = NULL,
    initialize = function(ledger, consensus) {
      self$ledger <- ledger
      self$consensus <- consensus
    },
    run = function() {
      while (TRUE) {
        transaction <- sample(-100:100, 1)
        self$ledger$record_transaction(transaction)
        self$consensus$update_ledger()
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  consensus <- ConsensusMechanism$new(ledger)
  simulation <- Simulation$new(ledger, consensus)
  simulation$run()
}

main()