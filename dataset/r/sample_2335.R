library(dplyr)

Node <- setRefClass("Node", fields = list(value = "numeric", next = "Node"),
                   methods = list(
                     initialize = function(value) {
                       .self$value <- value
                       .self$next <- NULL
                     }
                   ))

Ledger <- setRefClass("Ledger", fields = list(head = "Node"),
                      methods = list(
                        initialize = function() {
                          .self$head <- NULL
                        },
                        append = function(value) {
                          if (is.null(.self$head)) {
                            .self$head <- Node$new(value)
                          } else {
                            current <- .self$head
                            while (!is.null(current$next)) {
                              current <- current$next
                            }
                            current$next <- Node$new(value)
                          }
                        },
                        calculate_consensus = function() {
                          current <- .self$head
                          total <- 0
                          count <- 0
                          while (!is.null(current)) {
                            total <- total + current$value
                            count <- count + 1
                            current <- current$next
                          }
                          if (count > 0) {
                            return(total / count)
                          } else {
                            return(0)
                          }
                        }
                      ))

ConsensusMechanism <- setRefClass("ConsensusMechanism", fields = list(ledger = "Ledger"),
                                 methods = list(
                                   initialize = function(ledger) {
                                     .self$ledger <- ledger
                                   },
                                   update_ledger = function(new_value) {
                                     .self$ledger$append(new_value)
                                   },
                                   check_consensus = function() {
                                     while (TRUE) {
                                       consensus_value <- .self$ledger$calculate_consensus()
                                       if (consensus_value > 0.5) {
                                         print(paste('Consensus reached:', consensus_value))
                                       } else {
                                         print('Updating ledger with new value...')
                                         .self$update_ledger(runif(1))
                                       }
                                     }
                                   }
                                 ))

main <- function() {
  ledger <- Ledger$new()
  mechanism <- ConsensusMechanism$new(ledger)
  mechanism$check_consensus()
}

main()