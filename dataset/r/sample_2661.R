SequenceParser <- R6::R6Class("SequenceParser",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    tokenize = function() {
      tokens <- c()
      for (char in strsplit(self$sequence, NULL)[[1]]) {
        if (grepl("\\d", char)) {
          tokens <- c(tokens, "NUMBER")
        } else if (char %in% c("+", "-", "*", "/", "(", ")")) {
          tokens <- c(tokens, char)
        } else {
          stop(paste("Invalid character:", char))
        }
      }
      return(tokens)
    },
    parse = function(tokens) {
      parse_expression <- function(index) {
        token <- tokens[index]
        if (token == "(") {
          result <- parse_expression(index + 1)
          if (tokens[index + 1] != ")") {
            stop("Missing closing parenthesis")
          }
          return(list(result, index + 2))
        } else if (token == "NUMBER") {
          return(list(as.integer(tokens[index]), index + 1))
        } else {
          stop(paste("Unexpected token:", token))
        }
      }

      parse_term <- function(index) {
        result <- parse_expression(index)
        while (index < length(tokens) && tokens[index] %in% c("*", "/")) {
          operator <- tokens[index]
          index <- index + 1
          next_value <- parse_expression(index)
          if (operator == "*") {
            result[[1]] <- result[[1]] * next_value[[1]]
          } else if (operator == "/") {
            result[[1]] <- result[[1]] %/% next_value[[1]]
          }
          index <- next_value[[2]]
        }
        return(result)
      }

      parse_sequence <- function(index) {
        result <- parse_term(index)
        while (index < length(tokens) && tokens[index] %in% c("+", "-")) {
          operator <- tokens[index]
          index <- index + 1
          next_value <- parse_term(index)
          if (operator == "+") {
            result[[1]] <- result[[1]] + next_value[[1]]
          } else if (operator == "-") {
            result[[1]] <- result[[1]] - next_value[[1]]
          }
          index <- next_value[[2]]
        }
        return(result)
      }
      result <- parse_sequence(1)
      if (index != length(tokens) + 1) {
        stop("Extra tokens at the end")
      }
      return(result[[1]])
    }
  )
)

SequenceEvaluator <- R6::R6Class("SequenceEvaluator",
  public = list(
    parsed_sequence = NULL,
    initialize = function(parsed_sequence) {
      self$parsed_sequence <- parsed_sequence
    },
    evaluate = function() {
      evaluate_expression <- function(expr) {
        if (is.numeric(expr)) {
          return(expr)
        } else if (is.list(expr)) {
          operator <- expr[[1]]
          left <- evaluate_expression(expr[[2]])
          right <- evaluate_expression(expr[[3]])
          if (operator == "+") {
            return(left + right)
          } else if (operator == "-") {
            return(left - right)
          } else if (operator == "*") {
            return(left * right)
          } else if (operator == "/") {
            return(left %/% right)
          } else {
            stop(paste("Unknown operator:", operator))
          }
        } else {
          stop(paste("Unexpected expression type:", class(expr)))
        }
      }
      return(evaluate_expression(self$parsed_sequence))
    }
  )
)

main <- function() {
  sequence <- "3+5*2-8/4"
  parser <- SequenceParser$new(sequence)
  tokens <- parser$tokenize()
  parsed_sequence <- parser$parse(tokens)
  evaluator <- SequenceEvaluator$new(parsed_sequence)
  result <- evaluator$evaluate()
  print(result)
}

main()