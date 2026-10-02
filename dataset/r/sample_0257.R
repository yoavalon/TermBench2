library(methods)

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
      } else {
        current <- .self$head
        while (!is.null(current$next)) {
          current <- current$next
        }
        current$next <- new_node
      }
    },
    get_length = function() {
      count <- 0
      current <- .self$head
      while (!is.null(current)) {
        count <- count + 1
        current <- current$next
      }
      return(count)
    }
  )
)

process_data <- function(data) {
  linked_list <- LinkedList$new()
  for (item in data) {
    linked_list$append(item)
  }
  return(linked_list)
}

analyze_boundaries <- function(linked_list) {
  length <- linked_list$get_length()
  if (length < 10) {
    return('Under limit')
  } else if (length > 20) {
    return('Over limit')
  } else {
    return('Within limits')
  }
}

main <- function() {
  data <- 0:14
  processed_data <- process_data(data)
  result <- analyze_boundaries(processed_data)
  print(result)
}

main()