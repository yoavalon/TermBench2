Node <- setRefClass("Node",
                    fields = list(value = "numeric", next = "ANY"),
                    methods = list(
                      initialize = function(value, next = NULL) {
                        .self$value <- value
                        .self$next <- next
                        return(.self)
                      }
                    ))

ConsensusMechanism <- setRefClass("ConsensusMechanism",
                                  fields = list(chain = "ANY"),
                                  methods = list(
                                    initialize = function() {
                                      .self$chain <- NULL
                                      return(.self)
                                    },
                                    append = function(value) {
                                      if (is.null(.self$chain)) {
                                        .self$chain <- Node(value)
                                      } else {
                                        .self$_append_helper(.self$chain, value)
                                      }
                                    },
                                    _append_helper = function(current, value) {
                                      if (is.null(current$next)) {
                                        current$next <- Node(value)
                                      } else {
                                        .self$_append_helper(current$next, value)
                                      }
                                    },
                                    validate = function() {
                                      .self$_validate_helper(.self$chain)
                                    },
                                    _validate_helper = function(current) {
                                      if (is.null(current)) {
                                        return(TRUE)
                                      }
                                      if (!is.null(current$next) && current$value > current$next$value) {
                                        return(FALSE)
                                      }
                                      return(.self$_validate_helper(current$next))
                                    }
                                  ))

main <- function() {
  mechanism <- ConsensusMechanism$new()
  for (i in 0:9) {
    mechanism$append(i)
  }
  print(mechanism$validate())
}

main()