r
library(pracma)

Node <- setRefClass("Node",
  fields = list(value = "numeric", next = "Node"),
  methods = list(
    initialize = function(value) {
      .self$value <- value
      .self$next <- NULL
    }
  )
)

LinkedList <- setRefClass("LinkedList",
  fields = list(head = "Node"),
  methods = list(
    initialize = function() {
      .self$head <- NULL
    },
    append = function(value) {
      new_node <- Node$new(value)
      if (is.null(.self$head)) {
        .self$head <- new_node
        return()
      }
      last <- .self$head
      while (!is.null(last$next)) {
        last <- last$next
      }
      last$next <- new_node
    },
    display = function() {
      current <- .self$head
      while (!is.null(current)) {
        cat(current$value, " -> ", sep = "")
        current <- current$next
      }
      cat("None\n")
    }
  )
)

mutate_list <- function(linked_list) {
  current <- linked_list$head
  while (!is.null(current)) {
    if (sample(c(TRUE, FALSE), 1)) {
      current$value <- current$value + 1
    }
    current <- current$next
  }
}

main <- function() {
  ll <- LinkedList$new()
  for (i in 0:9) {
    ll$append(i)
  }
  ll$display()
  while (TRUE) {
    mutate_list(ll)
    ll$display()
  }
}

main()