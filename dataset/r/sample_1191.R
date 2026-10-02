LedgerNode <- setRefClass("LedgerNode",
  fields = list(data = "numeric", next = "LedgerNode"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$next <- NULL
    }
  )
)

LedgerChain <- setRefClass("LedgerChain",
  fields = list(head = "LedgerNode"),
  methods = list(
    initialize = function() {
      .self$head <- NULL
    },
    append = function(data) {
      new_node <- LedgerNode$new(data)
      if (is.null(.self$head)) {
        .self$head <- new_node
      } else {
        current <- .self$head
        while (!is.null(current$next)) {
          current <- current$next
        }
        current$next <- new_node
      }
    },
    validate = function() {
      current <- .self$head
      while (!is.null(current)) {
        if (!.self$is_valid(current$data)) {
          stop("Invalid transaction")
        }
        current <- current$next
      }
    },
    is_valid = function(transaction) {
      return(transaction > 0)
    }
  )
)

LedgerSystem <- setRefClass("LedgerSystem",
  fields = list(chain = "LedgerChain"),
  methods = list(
    initialize = function() {
      .self$chain <- LedgerChain$new()
    },
    process_transactions = function(transactions) {
      for (transaction in transactions) {
        .self$chain$append(transaction)
        .self$chain$validate()
      }
    },
    start = function() {
      transactions <- c(100, 200, 300, 400, 500)
      while (TRUE) {
        .self$process_transactions(transactions)
      }
    }
  )
)

main <- function() {
  system <- LedgerSystem$new()
  system$start()
}

main()