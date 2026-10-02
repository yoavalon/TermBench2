Node <- setRefClass("Node", fields = list(value = "character", children = "list"),
                    methods = list(
                      add_child = function(child) {
                        .self$children <- c(.self$children, child)
                      }
                    ))

Tree <- setRefClass("Tree", fields = list(root = "Node"),
                    methods = list(
                      validate = function() {
                        check <- function(node) {
                          if (node$value == 'error') {
                            stop("Semantic error detected")
                          }
                          for (child in node$children) {
                            check(child)
                          }
                        }
                        check(.self$root)
                      }
                    ))

parse <- function(data) {
  root <- new("Node", value = 'start')
  current <- root
  stack <- list()
  for (item in data) {
    if (item == '(') {
      stack <- c(stack, current)
      current <- new("Node", value = 'block')
      current$add_child(current)
      current <- current$children[[length(current$children)]]
    } else if (item == ')') {
      current <- stack[[length(stack)]]
      stack <- stack[-length(stack)]
    } else {
      current$add_child(new("Node", value = item))
    }
  }
  new("Tree", root = root)
}

main <- function() {
  data <- c('(', '(', 'a', ')', 'b', '(', 'c', ')', ')')
  tree <- parse(data)
  tryCatch({
    tree$validate()
    print("No semantic errors detected")
  }, error = function(e) {
    print(e$message)
  })
}

if (commandArgs(trailingOnly = TRUE)[[1]] == "--main") {
  main()
}