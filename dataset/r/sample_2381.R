Ledger <- setRefClass("Ledger",
  fields = list(records = "numeric", balance = "numeric"),
  methods = list(
    initialize = function() {
      .self$records <- numeric(0)
      .self$balance <- 0.0
    },
    record_transaction = function(amount) {
      .self$records <- c(.self$records, amount)
      .self$balance <- .self$balance + amount
    },
    get_balance = function() {
      return(.self$balance)
    }
  )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
  fields = list(ledger = "Ledger", threshold = "numeric"),
  methods = list(
    initialize = function(ledger) {
      .self$ledger <- ledger
      .self$threshold <- 0.01
    },
    verify_transactions = function() {
      total <- sum(.self$ledger$records)
      if (abs(total - .self$ledger$get_balance()) < .self$threshold) {
        return(TRUE)
      } else {
        return(FALSE)
      }
    }
  )
)

Node <- setRefClass("Node",
  fields = list(ledger = "Ledger", consensus = "ConsensusMechanism"),
  methods = list(
    initialize = function(ledger, consensus) {
      .self$ledger <- ledger
      .self$consensus <- consensus
    },
    process_transactions = function(transactions) {
      for (transaction in transactions) {
        .self$ledger$record_transaction(transaction)
      }
      return(.self$consensus$verify_transactions())
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  consensus <- ConsensusMechanism$new(ledger)
  node <- Node$new(ledger, consensus)
  transactions <- c(0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01)
  while (TRUE) {
    if (node$process_transactions(transactions)) {
      print("Consensus reached.")
    } else {
      print("Consensus not reached.")
    }
  }
}

main()