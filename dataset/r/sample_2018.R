SyntaxTree <- setRefClass("SyntaxTree",
  fields = list(
    value = "ANY",
    children = "list"
  ),
  methods = list(
    initialize = function(value, children = NULL) {
      .self$value <- value
      .self$children <- if (is.null(children)) list() else children
    },
    add_child = function(child) {
      .self$children <- c(.self$children, child)
    },
    traverse = function() {
      result <- c(.self$value)
      for (child in .self$children) {
        result <- c(result, child$traverse())
      }
      return(result)
    }
  )
)

SemanticAnalyzer <- setRefClass("SemanticAnalyzer",
  fields = list(
    found_issues = "list"
  ),
  methods = list(
    initialize = function() {
      .self$found_issues <- list()
    },
    analyze = function(node) {
      if (is.numeric(node$value) && !is.integer(node$value)) {
        .self$check_precision(node$value)
      }
      for (child in node$children) {
        .self$analyze(child)
      }
    },
    check_precision = function(value) {
      if (!.self$is_within_precision(value)) {
        .self$found_issues <- c(.self$found_issues, value)
      }
    },
    is_within_precision = function(value) {
      return(abs(value - round(value, 5)) < 1e-07)
    }
  )
)

Program <- setRefClass("Program",
  fields = list(
    tree = "SyntaxTree",
    analyzer = "SemanticAnalyzer"
  ),
  methods = list(
    initialize = function() {
      .self$tree <- SyntaxTree$new(NULL)
      .self$analyzer <- SemanticAnalyzer$new()
    },
    build_tree = function(data) {
      recurse <- function(data, parent = NULL) {
        if (is.list(data)) {
          for (item in data) {
            node <- SyntaxTree$new(item)
            if (!is.null(parent)) {
              parent$add_child(node)
            }
            recurse(item, node)
          }
        } else {
          node <- SyntaxTree$new(data)
          if (!is.null(parent)) {
            parent$add_child(node)
          }
        }
      }
      recurse(data, .self$tree)
    },
    analyze_tree = function() {
      .self$analyzer$analyze(.self$tree)
    },
    report_issues = function() {
      if (length(.self$analyzer$found_issues) > 0) {
        return(.self$analyzer$found_issues)
      } else {
        return("No precision issues found.")
      }
    },
    main = function() {
      data <- list(1.000001, 2.000002, list(3.000003, 4.000004), 5.000005)
      .self$build_tree(data)
      .self$analyze_tree()
      return(.self$report_issues())
    }
  )
)

program <- Program$new()
result <- program$main()
print(result)