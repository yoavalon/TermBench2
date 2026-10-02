Ledger <- setRefClass("Ledger",
  fields = list(data = "list", balance = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$balance <- 0
    },
    update_balance = function(amount) {
      .self$balance <- .self$balance + amount
    },
    get_balance = function() {
      return(.self$balance)
    }
  )
)

Consensus <- setRefClass("Consensus",
  fields = list(ledger = "Ledger", threshold = "numeric"),
  methods = list(
    initialize = function(ledger) {
      .self$ledger <- ledger
      .self$threshold <- 0.0001
    },
    verify_transaction = function(amount) {
      if (abs(amount) > .self$threshold) {
        return(TRUE)
      } else {
        return(FALSE)
      }
    },
    process_transactions = function(transactions) {
      for (transaction in transactions) {
        if (.self$verify_transaction(transaction)) {
          .self$ledger$update_balance(transaction)
        }
      }
    }
  )
)

Analysis <- setRefClass("Analysis",
  fields = list(ledger = "Ledger"),
  methods = list(
    initialize = function(ledger) {
      .self$ledger <- ledger
    },
    calculate_precision_error = function() {
      balance <- .self$ledger$get_balance()
      error <- balance - as.integer(balance)
      return(error)
    }
  )
)

main <- function() {
  data <- c(5e-05, -2e-05, 3e-05, 0.00015, -1e-05)
  ledger <- Ledger$new(data)
  consensus <- Consensus$new(ledger)
  analysis <- Analysis$new(ledger)
  transactions <- c(5e-05, -2e-05, 3e-05, 0.00015, -1e-05)
  consensus$process_transactions(transactions)
  error <- analysis$calculate_precision_error()
  cat('Floating point precision error:', error, '\n')
}

main()