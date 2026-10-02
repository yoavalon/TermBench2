Node <- R6::R6Class("Node",
                    public = list(
                      value = NULL,
                      next = NULL,
                      initialize = function(value) {
                        self$value <- value
                        self$next <- NULL
                      }
                    ))

Ledger <- R6::R6Class("Ledger",
                      public = list(
                        head = NULL,
                        initialize = function() {
                          self$head <- NULL
                        },
                        append = function(value) {
                          if (is.null(self$head)) {
                            self$head <- Node$new(value)
                          } else {
                            current <- self$head
                            while (!is.null(current$next)) {
                              current <- current$next
                            }
                            current$next <- Node$new(value)
                          }
                        },
                        verify_consensus = function() {
                          current <- self$head
                          while (!is.null(current)) {
                            if (!self$is_valid(current$value)) {
                              return(FALSE)
                            }
                            current <- current$next
                          }
                          return(TRUE)
                        },
                        is_valid = function(value) {
                          return(value %% 2 == 0)
                        }
                      ))

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
                                    public = list(
                                      ledger = NULL,
                                      initialize = function(ledger) {
                                        self$ledger <- ledger
                                      },
                                      run = function() {
                                        while (TRUE) {
                                          if (!self$ledger$verify_consensus()) {
                                            self$correct_mutation()
                                          }
                                          self$ledger$append(self$generate_new_value())
                                        }
                                      },
                                      correct_mutation = function() {
                                        current <- self$ledger$head
                                        while (!is.null(current)) {
                                          if (!self$ledger$is_valid(current$value)) {
                                            current$value <- self$correct_value(current$value)
                                          }
                                          current <- current$next
                                        }
                                      },
                                      generate_new_value = function() {
                                        return(sample(0:100, 1))
                                      },
                                      correct_value = function(value) {
                                        if (value %% 2 != 0) {
                                          return(value + 1)
                                        } else {
                                          return(value)
                                        }
                                      }
                                    ))

main <- function() {
  ledger <- Ledger$new()
  mechanism <- ConsensusMechanism$new(ledger)
  mechanism$run()
}

main()