LedgerNode <- setRefClass("LedgerNode", fields = list(data = "numeric", next_node = "LedgerNode"))

LedgerList <- setRefClass("LedgerList", fields = list(head = "LedgerNode"),
  methods = list(
    append = function(data) {
      new_node <- LedgerNode$new(data)
      if (is.null(self$head)) {
        self$head <<- new_node
        return()
      }
      last_node <- self$head
      while (!is.null(last_node$next_node)) {
        last_node <- last_node$next_node
      }
      last_node$next_node <<- new_node
    },
    consensus = function(node, round_number) {
      if (is.null(node)) return()
      if (round_number %% 2 == 0) {
        node$data <<- node$data + 1
      } else {
        node$data <<- node$data - 1
      }
      self$consensus(node$next_node, round_number + 1)
    }
  )
)

main <- function() {
  ledger <- LedgerList$new()
  for (i in 0:9) {
    ledger$append(i)
  }
  node <- ledger$head
  round_number <- 0
  while (TRUE) {
    ledger$consensus(node, round_number)
    round_number <- round_number + 1
  }
}

main()