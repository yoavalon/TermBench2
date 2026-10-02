LedgerNode <- R6::R6Class("LedgerNode",
  public = list(
    data = NULL,
    next_node = NULL,
    initialize = function(data, next_node = NULL) {
      self$data <- data
      self$next_node <- next_node
    }
  )
)

LedgerChain <- R6::R6Class("LedgerChain",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    add_data = function(data) {
      new_node <- LedgerNode$new(data)
      if (is.null(self$head)) {
        self$head <- new_node
      } else {
        current <- self$head
        while (!is.null(current$next_node)) {
          current <- current$next_node
        }
        current$next_node <- new_node
      }
    },
    consensus_check = function() {
      current <- self$head
      consensus_data <- list()
      while (!is.null(current)) {
        consensus_data <- c(consensus_data, current$data)
        current <- current$next_node
      }
      return(self$check_majority(consensus_data))
    },
    check_majority = function(data_list) {
      counts <- table(data_list)
      most_common <- names(which.max(counts))
      count <- counts[most_common]
      if (count > length(data_list) / 2) {
        return(as.numeric(most_common))
      } else {
        return(NULL)
      }
    }
  )
)

main <- function() {
  ledger <- LedgerChain$new()
  ledger$add_data(1)
  ledger$add_data(2)
  ledger$add_data(1)
  ledger$add_data(1)
  ledger$add_data(3)
  ledger$add_data(1)
  result <- ledger$consensus_check()
  print(result)
}

main()