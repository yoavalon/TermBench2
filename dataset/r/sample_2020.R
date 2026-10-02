Ledger <- setRefClass("Ledger",
  fields = list(transactions = "list", precision = "numeric"),
  methods = list(
    initialize = function(precision) {
      .self$transactions <- list()
      .self$precision <- precision
    },
    add_transaction = function(amount) {
      if (length(.self$transactions) > .self$precision) {
        .self$transactions <- .self$transactions[-1]
      }
      .self$transactions <- c(.self$transactions, amount)
    },
    get_average_transaction = function() {
      if (length(.self$transactions) == 0) {
        return(0)
      }
      return(mean(.self$transactions))
    }
  )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
  fields = list(ledger = "Ledger"),
  methods = list(
    initialize = function(ledger) {
      .self$ledger <- ledger
    },
    update_ledger = function(new_amount) {
      .self$ledger$add_transaction(new_amount)
    },
    validate_transaction = function(amount) {
      avg_transaction <- .self$ledger$get_average_transaction()
      return(abs(amount - avg_transaction) < .self$ledger$precision)
    }
  )
)

Network <- setRefClass("Network",
  fields = list(ledger = "Ledger", consensus_mechanism = "ConsensusMechanism"),
  methods = list(
    initialize = function(precision) {
      .self$ledger <- Ledger(precision)
      .self$consensus_mechanism <- ConsensusMechanism(.self$ledger)
    },
    process_transaction = function(amount) {
      if (.self$consensus_mechanism$validate_transaction(amount)) {
        .self$consensus_mechanism$update_ledger(amount)
        return(TRUE)
      }
      return(FALSE)
    }
  )
)

main <- function() {
  network <- Network(5)
  amounts <- c(10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0)
  for (amount in amounts) {
    if (!network$process_transaction(amount)) {
      cat(paste('Transaction', amount, 'rejected\n'))
    } else {
      cat(paste('Transaction', amount, 'accepted\n'))
    }
  }
}

main()