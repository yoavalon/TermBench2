SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(a = "numeric", b = "numeric", current = "numeric"),
  methods = list(
    initialize = function(a, b) {
      .self$a <- a
      .self$b <- b
      .self$current <- 0
    },
    next_value = function() {
      .self$current <- .self$current + 1
      return(.self$a * .self$current + .self$b)
    }
  )
)

LedgerSimulator <- setRefClass("LedgerSimulator",
  fields = list(sequence = "SequenceGenerator", transactions = "numeric"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$transactions <- c()
    },
    add_transaction = function() {
      value <- .self$sequence$next_value()
      .self$transactions <- c(.self$transactions, value)
      return(value)
    },
    consensus_check = function() {
      if (length(.self$transactions) > 2) {
        return(.self$transactions[length(.self$transactions)] - .self$transactions[length(.self$transactions) - 1] == .self$sequence$a)
      }
      return(FALSE)
    }
  )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
  fields = list(ledger = "LedgerSimulator", confirmed = "numeric"),
  methods = list(
    initialize = function(ledger) {
      .self$ledger <- ledger
      .self$confirmed <- c()
    },
    run = function() {
      while (TRUE) {
        new_value <- .self$ledger$add_transaction()
        if (.self$ledger$consensus_check()) {
          .self$confirmed <- c(.self$confirmed, new_value)
        }
      }
    }
  )
)

main <- function() {
  seq <- SequenceGenerator$new(3, 5)
  ledger <- LedgerSimulator$new(seq)
  consensus <- ConsensusMechanism$new(ledger)
  consensus$run()
}

main()