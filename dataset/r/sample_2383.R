Node <- setRefClass("Node", fields = list(value = "numeric", next = "ANY"))

Ledger <- setRefClass("Ledger", fields = list(head = "Node", tail = "Node"),
                      methods = list(
                        initialize = function() {
                          .self$head <- NULL
                          .self$tail <- NULL
                        },
                        append = function(value) {
                          new_node <- Node$new(value = value)
                          if (is.null(.self$head)) {
                            .self$head <- new_node
                            .self$tail <- new_node
                          } else {
                            .self$tail$next <- new_node
                            .self$tail <- new_node
                          }
                        },
                        consensus = function() {
                          current <- .self$head
                          while (!is.null(current)) {
                            if (current$value < 0.5) {
                              current$value <- current$value + 0.01
                            } else {
                              current$value <- current$value - 0.01
                            }
                            current <- current$next
                          }
                        }
                      ))

main <- function() {
  ledger <- Ledger$new()
  for (i in 0:99) {
    ledger$append(i / 100)
  }
  while (TRUE) {
    ledger$consensus()
  }
}

main()